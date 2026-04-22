#include "stm32l476xx.h"
#include "stm32l4xx.h"
#include "gpio.h"
#include "systick.h"
#include "tim.h"

int main(void) 
{

    //initialize LED
    led_init();

    //init tim2
    tim2_1hz_init();
    
    while(1)
    {
        led_on();

        //we will check the status register to see if this flag has been set.
        //if it has then we know overflow has occured.
        //based on reference manual, this is set whenver 
        while(!(TIM2->SR & SR_UIF)){}
        TIM2->SR &= ~SR_UIF;

        led_off();

        while(!(TIM2->SR & SR_UIF)){}
        TIM2->SR &= ~SR_UIF;


    }

}