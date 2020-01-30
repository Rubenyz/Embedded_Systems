/*
 * spi.h
 *
 * Created: 29-01-2020 20:25:55
 *  Author: Ruben
 */ 

#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

#define SPI PORTB
#define SPI_CS PIN0_bm
#define SPI_MISO PIN1_bm
#define SPI_CLK PIN4_bm

void init_spi(void);
void spi_tx(uint16_t data);
uint8_t getCS(void);

#endif /* SPI_H_ */