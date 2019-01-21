/* week1.h
 *
 * Definitions and statements for op1.c
 * 18 Dec. 2018
 * Ruben Stauttener
 */

#include "../bcm/src/bcm2835.h"

#define BUT0 RPI_GPIO_P1_22 //choice button
#define BUT1 RPI_GPIO_P1_15 //stop button
#define LED0 RPI_GPIO_P1_16 //purple LED
#define LED1 RPI_GPIO_P1_18 //amber LED

int gpio_init(void);
int gpio_clear(void);
