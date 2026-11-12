#include "stm32l476xx.h"
#include "stm32l4xx.h"
#ifndef SPI_H_ // prevent multiple inclusion
#define SPI_H_

#define GPIOA_ENABLE			(1U << 0)
#define GPIOA_PIN_CONFIG_MASK 	(1U << 9) | (1U << 11) | (1U << 13) | (1U << 15)

typedef enum {
	SPI_OK = 0,
	SPI_ERR = 1
} SPI_DRIVER_STATUS;

SPI_DRIVER_STATUS spi_init();
SPI_DRIVER_STATUS spi_config();
SPI_DRIVER_STATUS spi_read();
SPI_DRIVER_STATUS spi_write();

#endif // SPI_H_

/* 
on the stm32l476rg
Pins for SPI1
PA4 = SPI1_NSS
PA5 = SPI1_SCK
PA6 = SPI1_MISO
PA7 = SPI1_MOSI
*/