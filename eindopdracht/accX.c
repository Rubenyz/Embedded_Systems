/* accX.cpp
 *
 * Accelerometer visualized in terminal
 * 22 Jan. 2018
 * Ruben Stauttener
 */


#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h>
#include <time.h>

#include "../bcm/src/bcm2835.h"
#include "spi.h"
#include "button.h"
#include "paint.h"
#include "snake.h"

pthread_mutex_t adcDataMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t boolMutex = PTHREAD_MUTEX_INITIALIZER;

/*
void *console(void *arg) {
	while(!sysReset) {
		//printf("%d\t%d\r\n", adcdata[0], adcdata[1]);
	}
}
*/

int main(void) {
	bcm2835_init();
	
	pthread_t accelerometerThread;
	pthread_t buttonThread;
	pthread_t consoleThread;
	
	
	pthread_create(&accelerometerThread, NULL, accelerometer, NULL);
	pthread_create(&buttonThread, NULL, button, NULL);
	pthread_create(&consoleThread, NULL, paint, NULL);
	
	
	pthread_join(accelerometerThread, NULL);
	pthread_join(buttonThread, NULL);
	pthread_join(consoleThread, NULL);
	
	bcm2835_close();
	exit(EXIT_SUCCESS);
}
