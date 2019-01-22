/* week2rpi.h
 *
 * Definitions and statements for week2rpi.c
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include "../bcm/src/bcm2835.h"

#define BUT0 RPI_GPIO_P1_15	//Stop button
#define DATA0 RPI_GPIO_P1_19	//DATA0 line
#define DATA1 RPI_GPIO_P1_21	//DATA1 line
#define DATA2 RPI_GPIO_P1_23	//DATA2 line
#define SYS0 RPI_GPIO_P1_26	//SYS0 input/output line

int gpio_init(void);
int sendinputpulse(uint8_t pin, uint8_t pud);