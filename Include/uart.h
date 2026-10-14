#include "stm32l476xx.h"
#include "stm32l4xx.h"
#include <sys/types.h>
#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

void _usart_init_polling(void);  //function to setup the usart peripheral
void  uart_printf(const uint8_t *string);
void uart_read_byte(const uint8_t *byte);
void uart_putchar(const char ch);

void _usart_init_interrupt(void);
#endif /*UART_H_*/