//in the user manual, PA2 has the function of USART2_TX
//PA3 is for USART2_RX
#include <stdarg.h>
#include <stdint.h>
#include "uart.h"
#include "stm32l476xx.h"
#include "system_stm32l4xx.h"

//bit 1 to enable clock for Port A
#define GPIOA_ENABLE (1U << 0)

//bit 17 to enable clock for USART2 peripheral instance
#define USART2_ENABLE (1U << 17)

//desired baud rate (bps)
#define BAUD_RATE 115200

//bit 3 corresponds to enable the transmitter
#define USART2_TRX_ENABLE (1U << 3)

//bit 0 corresponds to USART2 enable
#define USART2_PERIPH_ENABLE (1U << 0)

// bit 29 corresponds to enabling FIFO mode
#define USART2_FIFO_ENABLE (1U << 29)

#define USART2_RECEIVER_ENABLE (1 << 2)

static void _uart_write(uint8_t character);
static void _usart_set_baud(uint32_t system_clock, uint32_t input_baud_rate);


void uart_printf(const uint8_t *string)
{
    while (*string) {
        // each string is a string of byte-sized chars
        // pointer to byte is just an array, so starts at first byte
        // write each character by dereferencing, then accessing, then add 1
        _uart_write(*string++);
    }    
}

void uart_putchar(const char ch)
{
    _uart_write(ch);
}

static void _uart_write(uint8_t character)
{
    //check to see if uart data register is empty
    //We can ONLY write to the TDR if TXE is equal to 1
    // USART2_ISR = usart interrupt and status register
    // while transmit buffer not empty inside of isr register, wait.
    while((!(USART2->ISR & USART_ISR_TXE))){}

    //strip everything except lowest 8 bits, place into transmit data register.
    USART2->TDR = (character & 0xFF);
}

static uint16_t _usart_compute_baud(uint32_t system_clock, uint32_t baud_rate)
{
    return (system_clock + (baud_rate / 2 )) / baud_rate;
}

//UART hardware does not work directly with baud rate, it needs a divisor number to place into 
//a register to tell the hardware to divide by a number to get the right timing
//divisor = clock_freq / baudrate
static void _usart_set_baud(uint32_t system_clock, uint32_t input_baud_rate)
{
    //register gets not the baud rate, rather the divisor which then does -> baudrate = clock freq / divisor (BRR value)
    USART2->BRR = _usart_compute_baud(SystemCoreClock, input_baud_rate);
}


void _usart_init_polling(void)
{
    //first step: setup system clock for GPIO Port A
    RCC->AHB2ENR |= GPIOA_ENABLE;
    RCC->APB1ENR1 |= USART2_ENABLE;

    //configure Port A Pin 2 for USART transmission
    //First we need to set the mode of PA2 to alternate function mode
    //alternate function mode is pin 5 has to be set to 1, and pin 4 to be set to 0
    GPIOA->MODER |= (1U << 5); // set bit 5
    GPIOA->MODER &= ~(1U << 4); //clear bit 4

    //now we need to configure Port A pin 3 to be usart
    // usart receiver
    GPIOA->MODER |= (1U << 7);
    GPIOA->MODER &= ~(1U << 6);

    //each pin gets a 4 bit field. 
    //pin 0 gets 0-3, pin 2 gets 4-7, pin 3 gets 8 - 11, pin 4 gets 12-15
    //Since each register is 32 bits, and each pin gets 4 bits for alternate function types
    //we have two registers:
    // AFR[0] - uint32_t  controls alt. function register LOW -> pins 0 - 7
    // AFR[1] - uint32_t  controls alt function register HIGH -> pins 8 - 15
    
    //to insert 7, we should write 0111 into this 4-bit field for PA2 bits 8-11
    GPIOA->AFR[0] |= (1U << 8);
    GPIOA->AFR[0] |= (1U << 9);
    GPIOA->AFR[0] |= (1U << 10);
    GPIOA->AFR[0] &= ~(1U << 11);

    // pins 7 and 6 correspond to pin 3

    /// 0111: AF7 
    GPIOA->AFR[0] |= (1U << 12);
    GPIOA->AFR[0] |= (1U << 13);
    GPIOA->AFR[0] |= (1U << 14);
    GPIOA->AFR[0] &= ~(1U << 15);

    _usart_set_baud(SystemCoreClock, 115200);

    //set transmission direction (TX)
    USART2->CR1 |= USART2_TRX_ENABLE;

    // enable this to receive
    USART2->CR1 |= USART2_RECEIVER_ENABLE;

    //enable usart 
    USART2->CR1 |= USART2_PERIPH_ENABLE;
}


//function to initialize interrupt-based uart
void _usart_init_interrupt(void) 
{
    // first step: setup system clock for GPIO Port A
    RCC->AHB2ENR |= GPIOA_ENABLE;

    RCC->APB1ENR1 |= USART2_ENABLE;

    GPIOA->MODER |= (1U << 5); // set bit 5
    GPIOA->MODER &= ~(1U << 4); //clear bit 4

    //to insert 7, we should write 0111 into this 4-bit field for PA2 bits 8-11
    GPIOA->AFR[0] |= (1U << 8);
    GPIOA->AFR[0] |= (1U << 9);
    GPIOA->AFR[0] |= (1U << 10);
    GPIOA->AFR[0] &= ~(1U << 11);

    _usart_set_baud(SystemCoreClock, 115200);

    // enable reciever to start looking for a start bit
    USART2->CR1 |= USART2_RECEIVER_ENABLE;

    //enable usart 
    USART2->CR1 |= USART2_PERIPH_ENABLE;
}