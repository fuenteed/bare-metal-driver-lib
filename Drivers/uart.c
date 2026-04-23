//in the user manual, PA2 has the function of USART2_TX
//PA3 is for USART2_RX
#include "uart.h"
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

static void _uart_write(int character);
static void _usart_set_baud(uint32_t system_clock, uint32_t input_baud_rate);


void uart_printf(const char *fmt, ...) {
    char buf[128];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    // send the buffer over UART
    char *p = buf;
    while (*p) _uart_write(*p++);
}

static void _uart_write(int character)
{
    //check to see if uart data register is empty
    //We can ONLY write to the TDR if TXE is equal to 1
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


void _usart_init(void)
{
    //first step: setup system clock for GPIO Port A
    RCC->AHB2ENR |= GPIOA_ENABLE;

    RCC->APB1ENR1 |= USART2_ENABLE;

    //configure Port A Pin 2 for USART transmission
    //First we need to set the mode of PA2 to alternate function mode
    //alternate function mode is pin 5 has to be set to 1, and pin 4 to be set to 0
    GPIOA->MODER |= (1U << 5); // set bit 5
    GPIOA->MODER &= ~(1U << 4); //clear bit 4

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

    _usart_set_baud(SystemCoreClock, 115200);

    //set transmission direction (TX)
    USART2->CR1 |= USART2_TRX_ENABLE;

    //enable usart 
    USART2->CR1 |= USART2_PERIPH_ENABLE;

}