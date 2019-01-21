/* week1.c
 *
 * Double LED blink with choice and stop button
 * 18 Dec. 2018
 * Ruben Stauttener
 */

#include <stdlib.h>
#include <stdio.h>
#include "../bcm/src/bcm2835.h"
#include "./week2rpi.h"

#define SENDDELAY 10

int gpio_init(void) {
	//4 lines as input
	bcm2835_gpio_fsel(DATA0, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(DATA1, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(DATA2, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(SYS0, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(BUT0, BCM2835_GPIO_FSEL_INPT);

	//SYS0 with pulldown
	bcm2835_gpio_set_pud(SYS0, BCM2835_GPIO_PUD_DOWN);

	return 1;
}

int sendinputpulse(uint8_t pin, uint8_t pud) {
	bcm2835_gpio_set_pud(pin, BCM2835_GPIO_PUD_OFF);	//disable pullup/pulldown
	bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);		//pin as output
	bcm2835_gpio_write(pin, 1);				//make pin high
	delay(SENDDELAY);
	bcm2835_gpio_write(pin, 0);				//make pin low
	bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_INPT);		//pin as input
	bcm2835_gpio_set_pud(pin, pud);				//enable pullup/pulldown as before
}

int main(void) {
	int datalines[] = {DATA0, DATA1, DATA2};	//lookup array for data lines

	printf("week2 started\r\n");

	if (!bcm2835_init()) {
		return 0;
	}
	
	if(!gpio_init()) {
		return 0;
	}
	
	//as long as BUT0 is not pressed
	while(bcm2835_gpio_lev(BUT0)) {
		int data = 0;

		delay(1000);

		while(bcm2835_gpio_lev(SYS0));	//wait for SYS0 to become low

		sendinputpulse(SYS0, BCM2835_GPIO_PUD_DOWN);

		while(!bcm2835_gpio_lev(SYS0));	//wait for SYS0 to become high
-
		delay(5);
		
		//sendinputpulse(SYS0, BCM2835_GPIO_PUD_DOWN);

		for(int i=0; i<3; i++) {
			data |= (bcm2835_gpio_lev(datalines[i] << i));		//parse parallel data
		}

		printf("Data received is: '%d'.\r\n", data);

	}

	bcm2835_close();
	
	printf("week2 stopped.\r\n");
	
	return 1;
}
