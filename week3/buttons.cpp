/* buttons.cpp
 *
 * Classes for the pushbuttons
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include "buttons.hpp"
#include <bcm2835.h>


bool Button::read(int butno) {
	return bcm2835_gpio_lev(butno);
}

void Button::setdir(int butno, int dir) {
	bcm2835_gpio_fsel(butno, dir);
}

void Button::setpud(int butno, int pud) {
	bcm2835_gpio_set_pud(butno, pud);
}