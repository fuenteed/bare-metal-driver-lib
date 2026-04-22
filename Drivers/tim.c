#include "tim.h"

#define TIM2EN  (1U << 0) //based on ref manual, first bit enables tim2 timer
#define CR1_CEN (1U << 0) //based on ref manual, first bit of tim2_cr (control register) enables the counter for this timer


void tim2_1hz_init(void)
{
    //enable clock acccess to tim2

    //based on the reference manual, setting bit 0 to 1 enables the clock for tim2
    //use a bitwise OR to set bit 0 to 1
    RCC->APB1ENR1 |= TIM2EN;

    //set prescalar via TIM2_PSC register
    TIM2->PSC = 400 - 1;

    //set auto reload register
    TIM2->ARR = 10000 - 1;

    //clear counter
    //remember that counter is 16 bit, so it only uses bits 0 to 15
    TIM2->CNT = 0;

    //enable counter
    TIM2->CR1 |= CR1_CEN;

}