#include <spi.h>

/* 
on the stm32l476rg
Pins for SPI1
PA4 = SPI1_NSS
PA5 = SPI1_SCK
PA6 = SPI1_MISO
PA7 = SPI1_MOSI
AF5 = alternate function 5
*/

SPI_DRIVER_STATUS spi_init()
{
	// setup GPIOA to support SPI
	// GPIO port A is connected to the AHB2
	// enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOA_ENABLE;

	// pins 4 - 7 set to alternate function mode
	GPIOA->MODER = 0;
	GPIOA->MODER |= (1U << 9) | (1U << 11) | (1U << 13) | (1U << 15);

	// set the actual alternate function (AF5)
	// since we are dealing with pins 0-7, we can use the GPIOA_AFRL (low)
	GPIOA->AFR[0] = 0;
	GPIOA->AFR[0] |= (1U << 30) | (1U << 28) //PA7
					| (1U << 26) | (1U << 24) //PA6
					| (1U << 22) | (1U << 20) //PA5
					| (1U << 18) | (1U << 16); //PA4

	


}

SPI_DRIVER_STATUS spi_config()
{

}

SPI_DRIVER_STATUS spi_read()
{

}

SPI_DRIVER_STATUS spi_write()
{

}