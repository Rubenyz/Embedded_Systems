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
#include "buttonled.hpp"

 
int main(int argc, char **argv) {
	
	bcm2835_init();
	
	if(argc > 1) {
		cout << "Too many arguments\r\n";
		return 0;
	}
	
	cout << "week4 started\r\n";
	

	Led myLeds;
	CountLed myCountLeds;
	ButtonLed myButtonLeds;
	
	myCountLeds.setdir(LED0, BCM2835_GPIO_FSEL_OUTP);
	myCountLeds.setdir(LED1, BCM2835_GPIO_FSEL_OUTP);
	
	myButtonLeds.setdir(LED2, BCM2835_GPIO_FSEL_OUTP);
	
	myButtonLeds.setButtonDir(BUT0, BCM2835_GPIO_FSEL_INPT);			//buttonled
	myButtonLeds.setButtonPud(BUT0, BCM2835_GPIO_PUD_UP);
	
	myButtonLeds.setButtonDir(BUT1, BCM2835_GPIO_FSEL_INPT);			//stopled
	myButtonLeds.setButtonPud(BUT1, BCM2835_GPIO_PUD_UP);
	

	while(myButtonLeds.readButton(BUT1)) {
		myCountLeds.setLeds(LED0, LED1);
		
		for(int i=0; i<100 && myButtonLeds.readButton(BUT1); i++) {
			delay(10);
			myButtonLeds.setLed(LED2, myButtonLeds.readButton(BUT0));			
		}		
	}
	
	
	myCountLeds.light(LED0, 0);
	myCountLeds.light(LED1, 0);
	myCountLeds.light(LED2, 0);
	
	cout << "week4 stopped.\r\n";
	return 1;
}