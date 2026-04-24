#include "stm32l476xx.h"
#include "stm32l4xx.h"
#include "globals.h"
#include <sys/types.h>
#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

typedef struct {
    uint32_t baud_rate;
    uint8_t word_len;
    uint8_t stop_bits;
    uint8_t parity;
} USART_Config_t;

typedef struct {
    USART_TypeDef *instance;
    USART_Config_t configuration;
    uint8_t *ptx_buff;
    uint16_t tx_count;
    volatile bool tx_busy;
} USART_Handle_t;


Driver_status_t _usart_init(USART_Handle_t *usart_handle);  //function to setup the usart peripheral
Driver_status_t uart_printf(const char *fmt, ...);


#endif /*UART_H_*/