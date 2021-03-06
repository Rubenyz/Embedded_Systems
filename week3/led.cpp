/* led.cpp
 *
 * Classes for the LED
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include "led.hpp"
#include "../bcm/src/bcm2835.h"

void Led::blink(int period) {
	bcm2835_gpio_write(ledno, 1);
	delay(period/2);
	bcm2835_gpio_write(ledno, 0);
	delay(period/2);
}


Led::Led(int ledn) {	
	this->ledno = ledn;
	bcm2835_gpio_fsel(ledno, BCM2835_GPIO_FSEL_OUTP);
}