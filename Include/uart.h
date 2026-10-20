#include "stm32l476xx.h"
#include "stm32l4xx.h"
#include <sys/types.h>
#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ring_buffer.h>

#define MAX_COMMAND_LENGTH 20

void _usart_init_polling(void);  //function to setup the usart peripheral
void  uart_printf(const uint8_t *string);
void uart_read_byte(const uint8_t *byte);
void uart_putchar(const char ch);
void uart_process_string(uint8_t *str);
int uart_str_len(const uint8_t *str);

// interrupt specific versions
void _usart_init_interrupt(void);
uint8_t uart_itr_read_byte(void);
void uart_itr_process_string(void);

void _usart_init_interrupt(void);
#endif /*UART_H_*/