/* week3.cpp
 *
 * Double LED blink with choice and stop button, now in C++
 * 22 Jan. 2018
 * Ruben Stauttener
 */
 
#include <iostream>
using namespace std;

#include <bcm2835.h>
 
#include "led.hpp"
#include "buttons.hpp"

 
int main(int argc, char **argv) {
	int leds[] = {LED0, LED1};	//lookup array for LED colour
	int choice = 1;	//LED choice
	
	bcm2835_init();
	
	if(argc > 1) {
		cout << "Too many arguments\r\n";
		return 0;
	}
	
	cout << "week3 started\r\n";
	
	Led myLeds;
	Button myButtons;
	
	
	myLeds.setdir(LED0, BCM2835_GPIO_FSEL_OUTP);
	myLeds.setdir(LED1, BCM2835_GPIO_FSEL_OUTP);
	
	myButtons.setdir(BUT0, BCM2835_GPIO_FSEL_INPT);
	myButtons.setpud(BUT0, BCM2835_GPIO_PUD_UP);
	myButtons.setdir(BUT1, BCM2835_GPIO_FSEL_INPT);
	myButtons.setpud(BUT1, BCM2835_GPIO_PUD_UP);
		
	//as long as BUT1 is not pressed
	while(myButtons.read(BUT1)) {
		
		if(myButtons.read(BUT0)) {	//if pressed
			choice = 0;	//purple LED
		}
		else if(!myButtons.read(BUT0)) {	//if not pressed
			choice = 1;	//yellow LED
		}
		else {
			return 0;
		}
		
		myLeds.blink(leds[choice]);
	}
	
	cout << "week3 stopped.\r\n";
	return 1;
}