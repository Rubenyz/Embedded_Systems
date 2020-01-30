/* spi.c
 *
 * Spi control
 * 22 Jan. 2018
 * Ruben Stauttener
 */
 
#include "spi.h"

#define SPIDELAY 150
#define SPIDELAYCS 1000

uint16_t adcdata[2] = {0,0};

void *accelerometer(void *arg) {
	init_spi();
	read_spi();
}


void init_spi(void) {
	bcm2835_gpio_fsel(SPI_CS, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(SPI_CLK, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(SPI_MISO, BCM2835_GPIO_FSEL_INPT);
	
	bcm2835_gpio_set_pud(SPI_MISO, BCM2835_GPIO_PUD_DOWN);
	
	bcm2835_gpio_write(SPI_CS, 0);
	bcm2835_delay(1);
	bcm2835_gpio_write(SPI_CS, 1);
	bcm2835_gpio_write(SPI_CLK, 0);
	bcm2835_delay(1);
}


void read_spi(void) {
	while(!sysReset) {
		uint16_t data = 0x0000;
		
		bcm2835_delayMicroseconds(SPIDELAY);
		bcm2835_gpio_write(SPI_CS, 0);
		bcm2835_delayMicroseconds(SPIDELAYCS);
		
		for(uint16_t i=0x8000; i!=0; i>>=1) {
			bcm2835_gpio_write(SPI_CLK, 1);
			bcm2835_delayMicroseconds(SPIDELAY);
			
			bcm2835_gpio_write(SPI_CLK, 0);
			bcm2835_delayMicroseconds(SPIDELAY);
			
			if(bcm2835_gpio_lev(SPI_MISO)) {
				data = data | i;
			}
			
		}
		
		bcm2835_gpio_write(SPI_CS, 1);
		bcm2835_delayMicroseconds(SPIDELAY);
		
		pthread_mutex_lock(&adcDataMutex);
		adcdata[(data >> 12) & 0x000F] = data & 0x0FFF;
		pthread_mutex_unlock(&adcDataMutex);
	}
}
