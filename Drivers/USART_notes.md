### Interrrupt Enabling specifics for stm32l4
When char received
1. RXNE (Rec. Register Not Empty) gets set to tell us that we have received data
2. Since we have the RXNEIE bit is set, an interrupt is generated
3. Check for flags (Overrun, frame errorss)
4. Clearing the RXNE bit is done by software read to USART_RDR (Read Data Register). 
5. RXNE bit must be cleared before end of reception of next char to avoid overrun error

Overrun error
- Occurs when char received when RXNE has not be reset.
- When the Read Data Register Not Empty flag has not been reset
- When RXNE = 0: data is not received, 1 = received data ready to be read.
- RXNE is set by hardware when content of RDR shift register has been sent to RDR register.

ICR - Interrupt Flag Clear Register (USART_ICR)
- register dedicated to clearing flags for interrupts

STM32 has one IRQ per USART. A single IRQ handles reading and writing. 
- the USART_ISR accounts for interrupts relating to transmitting and reading. 
- the ISR function will maybe need to figure out how it should handle itself for a given input. is it a transmit interrupt or receive interrupt?

TXE - Transmit Data Register Empty
- Set by hardware when TDR has been placed into shift register. Cleared by write to TDR
- An interrupt is generated if the TXEIE bit =1 in the USART_CR1 register
TC - Transmission Complete
- Set by hardware if transmission of frame containing data is complete AND if TXE is set.
- interrupt generated whenever TCIE=1 in CR1 enabled