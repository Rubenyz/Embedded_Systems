/* spi.h
 *
 * Spi control declarations
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h>
#include "../bcm/src/bcm2835.h"
#include <pthread.h>
#include "snake.h"

#define SPI_CS RPI_GPIO_P1_19
#define SPI_MISO RPI_GPIO_P1_21
#define SPI_CLK RPI_GPIO_P1_23

uint16_t adcdata[2];

void *accelerometer(void *arg);
void init_spi(void);
void read_spi(void);
