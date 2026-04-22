#include "gpio.h"

#define GPIOAEN (1U << 0)
/*The pin 5 of port A for the BSRR register. 
0-15 is for setting the pins to a high state. 
Writing 1 to the appropriate pin
*/
#define LED_BS5 (1U << 5) 
/*

And on the other end we can reset the pin by
setting its reset field to 1, also through the
BSRR register. Bits 16-31 reset the pints 0-15.
*/
#define LED_BR5 (1U << 21)



/*User button is connected to PC13 - Port C Pin 13
So we need to enable the clock to Port C
*/
#define GPIOCEN (1U << 2)
#define BTN_PIN (1U << 13)

void led_init(void)
{
    /*Enable the clock for GPIOA*/
    RCC->AHB2ENR |= GPIOAEN;

    /*Set pin 5 to output mode - set bit 10 to 1 with the OR operation and clear bit 11 to turn it to 0*/
    GPIOA->MODER |= (1U << 10);
    GPIOA->MODER &=~(1U << 11);
}

/*Set the pin to a high state - use the BSRR register to set 1 to the set field*/
void led_on(void)
{
    GPIOA->BSRR |= LED_BS5;
}

/*Reset the pin to a low state - use the BSRR register to reset 1 to the reset field */
void led_off(void)
{
    GPIOA->BSRR |= LED_BR5;
}


void button_init(void)
{
    //enable clock for port C
    RCC->AHB2ENR |= GPIOCEN;

    //set pin 13 to input mode. clear both pins to 0.
    GPIOC->MODER &=~(1U << 26);
    GPIOC->MODER &=~(1U << 27);
}

int get_btn_state(void)
{
    /*remember that IDR is the Input Data Register since we want
    to read the signal of the pin
    */
    //the AND operation checks status of the corresponding pin to see if its high or low. 
    //take full 32-bit IDR -> AND BTN_PIN -> every bit except 13 is cleared.
    if(GPIOC->IDR & BTN_PIN)
    {
        return 1;
    }else
    {
        return 0;
    }
}