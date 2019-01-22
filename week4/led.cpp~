/* led.cpp
 *
 * Classes for the LEDs
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include "led.hpp"
#include <bcm2835.h>

void Led::light(int ledno, bool bOn) {
	bcm2835_gpio_write(ledno, bOn);
}

void Led::setdir(int ledno, int dir) {
	bcm2835_gpio_fsel(ledno, dir);
}