/* button.c
 *
 * Stop and pause buttons
 * 22 Jan. 2018
 * Ruben Stauttener
 */
 
#include "button.h"

bool sysReset = 0;
bool pauseWait = 0;

void *button(void *arg) {
	init_button();
	read_button();
}


void init_button(void) {
	bcm2835_gpio_fsel(BUTTON0, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(BUTTON1, BCM2835_GPIO_FSEL_INPT);
	
	bcm2835_gpio_set_pud(BUTTON0, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(BUTTON1, BCM2835_GPIO_PUD_UP);
}


void read_button(void) {
	bool quit = 0;
	
	while(!quit) {
		pthread_mutex_lock(&boolMutex);
		
		if(!bcm2835_gpio_lev(BUTTON0)) {
			sysReset = 1;
			quit = 1;
		}
		
		if(!bcm2835_gpio_lev(BUTTON1)) {
			pauseWait = 1;
		} else {
			pauseWait = 0;
		}
		
		pthread_mutex_unlock(&boolMutex);
	}
}
