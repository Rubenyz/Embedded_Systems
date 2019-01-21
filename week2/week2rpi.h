/* week1.h
 *
 * Definitions and statements for op1.c
 * 18 Dec. 2018
 * Ruben Stauttener
 */

#include "../bcm/src/bcm2835.h"

#define BUT0 RPI_GPIO_P1_22	//Stop button
#define DATA0 RPI_GPIO_P1_15	//DATA0 line
#define DATA1 RPI_GPIO_P1_16	//DATA1 line
#define DATA2 RPI_GPIO_P1_18	//DATA2 line
#define SYS0 RPI_GPIO_P1_18	//SYS0 input/output line

int gpio_init(void);
int sendinputpulse(uint8_t pin, uint8_t pud);
