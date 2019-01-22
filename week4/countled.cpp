/* countled.cpp
 *
 * Classes for the counting LEDs
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include "led.hpp"
#include "countled.hpp"

#include <bcm2835.h>

int data = 0;

int CountLed::countfur(void) {
	return (data++ % 4);
}

void CountLed::setLeds(int ledno0, int ledno1) {
	int count = countfur();
	
	light(ledno0, count & (0x01 << 0));
	light(ledno1, count & (0x01 << 1));
}