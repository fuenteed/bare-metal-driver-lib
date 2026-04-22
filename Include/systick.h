#ifndef SYSTICK_H_
#define  SYSTICK_H_

#include "stm32l4xx.h"
#include <stdint.h>

void systick_msc_delay(uint32_t delay);

#endif /*SYSTICK_H_*/