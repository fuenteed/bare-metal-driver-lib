#include "stm32l4xx.h"
#ifndef TIM_H_
#define TIM_H_

//the UIF (update interrupt flag - I think). This is located in the TIM2_SR (status register). 
//this can be used to generate interrupts on overflow or underflow. when ARR reached, this flag is set
#define SR_UIF (1U << 0)

void tim2_1hz_init(void);

#endif /*TIM_H_*/