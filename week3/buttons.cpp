/* buttons.cpp
 *
 * Classes for the pushbuttons
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include "buttons.hpp"
#include "../bcm/src/bcm2835.h"


bool Button::read(void) {
	return bcm2835_gpio_lev(butno);
}

Button::Button(int butn, int pud) {
	butno = butn;
	bcm2835_gpio_fsel(butn, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_set_pud(butn, pud);
}