/* week4.cpp
 *
 * Inheritance in C++
 * 22 Jan. 2018
 * Ruben Stauttener
 */
 
#include <iostream>
using namespace std;

#include <bcm2835.h>
 
#include "led.hpp"
#include "countled.hpp"

//#include "buttons.hpp"

 
int main(int argc, char **argv) {
	int count = 0;
	
	bcm2835_init();
	
	if(argc > 1) {
		cout << "Too many arguments\r\n";
		return 0;
	}
	
	cout << "week4 started\r\n";
	

	Led myLeds;
	CountLed myCountLeds;
	
	myCountLeds.setdir(LED0, BCM2835_GPIO_FSEL_OUTP);
	myCountLeds.setdir(LED1, BCM2835_GPIO_FSEL_OUTP);
	
	count = myCountLeds.countfur();
	myCountLeds.light(LED0, count & (0x01 << 0));
	myCountLeds.light(LED1, count & (0x01 << 1));
	
	while(1) {
		cout << "Hoi\r\n\r\n";
		delay(1000);
	}
	
	
	
	cout << "week4 stopped.\r\n";
	return 1;
}