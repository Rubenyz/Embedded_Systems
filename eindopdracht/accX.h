/* accX.h
 *
 * Accelerometer declarations
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h>
#include "../bcm/src/bcm2835.h"
#include <pthread.h>
#include <stdbool.h>

extern pthread_mutex_t adcDataMutex;
extern pthread_mutex_t boolMutex;
extern uint16_t adcdata[2];
extern bool sysReset;
extern bool pauseWait;
