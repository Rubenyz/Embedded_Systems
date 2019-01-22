/* week1.c
 *
 * Double LED blink with choice and stop button
 * 18 Dec. 2018
 * Ruben Stauttener
 */

#include <stdlib.h>
#include <stdio.h>
#include "../bcm/src/bcm2835.h"
#include "./week1.h"

int gpio_init(void) {
	//both buttons as input
	bcm2835_gpio_fsel(BUT0, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(BUT1, BCM2835_GPIO_FSEL_INPT);

	//both buttons with pullup
	bcm2835_gpio_set_pud(BUT0, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(BUT1, BCM2835_GPIO_PUD_UP);

	//both LEDs as output
	bcm2835_gpio_fsel(LED0, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(LED1, BCM2835_GPIO_FSEL_OUTP);
	
	return 1;
}

int gpio_clear(void) {
	bcm2835_gpio_write(LED0, 0);
	bcm2835_gpio_write(LED1, 0);
	
	return 1;
}

int main(void) {
	int leds[] = {LED0, LED1};	//lookup array for LED colour
	int choice = 1;	//LED choice

	printf("week1 started\r\n");

	if (!bcm2835_init()) {
		return 0;
	}
	
	if(!gpio_init()) {
		return 0;
	}
	
	if(!gpio_clear()) {
		return 0;
	}
	
	//as long as BUT1 is not pressed
	while(bcm2835_gpio_lev(BUT1)) {
		
		if(bcm2835_gpio_lev(BUT0)) {	//if pressed
			choice = 0;	//purple LED
		}
		else if(!bcm2835_gpio_lev(BUT0)) {	//if not pressed
			choice = 1;	//yellow LED
		}
		else {
			return 0;
		}
		
		//blink at 10Hz
		bcm2835_gpio_write(leds[choice], 1);
		delay(50);
		bcm2835_gpio_write(leds[choice], 0);
		delay(50);
	}

	gpio_clear();
	bcm2835_close();
	
	printf("week1 stopped.\r\n");
	
	return 1;
}
