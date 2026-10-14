#include "stm32l476xx.h"
#include "uart.h"
#include <stdio.h>

int main(void)
{
    _usart_init();

    while(1)
    {
        uart_printf("This works!\r\n");
    }
}