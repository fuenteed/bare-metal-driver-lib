#include "stm32l476xx.h"
#include "uart.h"

#define RX_HAS_DATA (1 << 5)
int main(void)
{
    _usart_init_polling();


    while(1)
    {
       //uart_printf("This works");
        // if this condition is met, then we have data to be read
        if(USART2->ISR & RX_HAS_DATA){
            // this means we have data in the data register (RDR - Receive Data Register)
            // read it, returns 32 bits but we want the first byte
            char ch = (char)(USART2->RDR & 0xFFU);
            //once we read RDR, that clears the RXNE (Receiver not empty) bit

            // now we need to transmit the byte using the TDR transmit data register
            // write received_data to the TDR
            // writing to this register will clear the TXE (Transmit not empty register)
            // first we need to check if TXE is empty
            if(USART2->ISR & USART_ISR_TXE){
                 uart_putchar(ch);
            }
        }
    }
}
