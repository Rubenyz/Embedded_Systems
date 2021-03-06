/* week3.cpp
 *
 * Double LED blink with choice and stop button, now in C++
 * 22 Jan. 2018
 * Ruben Stauttener
 */
 
#include <iostream>
using namespace std;

#include "../bcm/src/bcm2835.h"
 
#include "led.hpp"
#include "buttons.hpp"

 
int main(int argc, char **argv) {
	bcm2835_init();
	
	if(argc > 1) {
		cout << "Too many arguments\r\n";
		return 0;
	}
	
	cout << "week3 started\r\n";
	
	Led purple = Led(LED0);
	Led yellow = Led(LED1);

	Button butchoice = Button(BUT0, BCM2835_GPIO_PUD_UP);
	Button butstop = Button(BUT1, BCM2835_GPIO_PUD_UP);
	
	Led* tmp = nullptr;
	
	//as long as BUT1 is not pressed
	while(butstop.read()) {
		
		if(butchoice.read()) {
			tmp = &purple;
			purple.blink(100);
		}
		else {
			tmp = &yellow;
			yellow.blink(100);
		}
		tmp->blink(100);
	}
	
	cout << "week3 stopped.\r\n";
	return 1;
}