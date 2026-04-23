#include "stm32l4xx.h"
#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>


void _usart_init(void);  //function to setup the usart peripheral
void uart_printf(const char *fmt, ...);


#endif /*UART_H_*/