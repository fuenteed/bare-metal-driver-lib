#ifndef GPIO_H_ // prevent multiple inclusion
#define GPIO_H_ 

#include "stm32l4xx.h"
void led_init(void);
void led_on(void);
void led_off(void);
void button_init(void);
int get_btn_state(void);

#endif /*GPIO_H_*/