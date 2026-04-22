#include "stm32l476xx.h"
#include "stm32l4xx.h"
#include "gpio.h"
#include "systick.h"

int main(void) {

    // Bare metal version without a driver
    // Enable GPIOA clock
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    // Set PA5 as output (Nucleo L476 onboard LED)
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));

    while (1) {
        GPIOA->ODR ^= (1U << 5); // toggle LED

        /*The following line of code would be used WITHOUT our delay function using SysTick*/
        //for (volatile int i = 0; i < 100000; i++);

        /*The following is the SysTick Improvement*/
        systick_msc_delay(1000);

    }


    //with a driver

    /* 
    led_init();
    button_init();

    while(1)
    {
        if(get_btn_state() == 0)
        {
            led_on();
        }else
        {
            led_off();
        }
    }
        */

}