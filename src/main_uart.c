#include "stm32l476xx.h"
#include "uart.h"
#include <stdint.h>


int main(void)
{
    _usart_init_polling();


    while(1)
    {
            char string[MAX_COMMAND_LENGTH] = "";
            uart_process_string(string);
            //once we read RDR, that clears the RXNE (Receiver not empty) bit
            // now we need to transmit the byte using the TDR transmit data register
            // write received_data to the TDR
            // writing to this register will clear the TXE (Transmit not empty register)
            // first we need to check if TXE is empty

            uart_printf(string);


    }
}
