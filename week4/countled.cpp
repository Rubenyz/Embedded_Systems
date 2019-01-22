/* countled.cpp
 *
 * Classes for the counting LEDs
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include <iostream>
using namespace std;

#include "led.hpp"
#include "countled.hpp"

#include <bcm2835.h>

int data = 0;

int CountLed::countfur(void) {
	return (data++ % 4);
}