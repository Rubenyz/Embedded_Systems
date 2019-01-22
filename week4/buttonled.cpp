/* buttonled.cpp
 *
 * Classes for the button-LED
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include "led.hpp"
#include "buttonled.hpp"

#include <bcm2835.h>

void ButtonLed::setButtonDir(int butno, int dir) {
	bcm2835_gpio_fsel(butno, dir);
}

void ButtonLed::setButtonPud(int butno, int pud) {
	bcm2835_gpio_set_pud(butno, pud);
}

bool ButtonLed::readButton(int butno) {
	return bcm2835_gpio_lev(butno);
}

void ButtonLed::setLed(int ledno, int state) {
	bcm2835_gpio_write(ledno, state);
}