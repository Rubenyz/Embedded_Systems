/* led.cpp
 *
 * Classes for the LED
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include "led.hpp"
#include <bcm2835.h>

void Led::blink(int ledno) {
	bcm2835_gpio_write(ledno, 1);
	delay(50);
	bcm2835_gpio_write(ledno, 0);
	delay(50);
}

void Led::setdir(int ledno, int dir) {
	bcm2835_gpio_fsel(ledno, dir);
}