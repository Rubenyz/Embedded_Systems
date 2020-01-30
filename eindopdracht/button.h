/* button.h
 *
 * Button declarations
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h>
#include "../bcm/src/bcm2835.h"
#include <pthread.h>
#include "snake.h"

#define BUTTON0 RPI_GPIO_P1_16
#define BUTTON1 RPI_GPIO_P1_18

bool sysReset;
bool pauseWait;

void *button(void *arg);
void init_button(void);
void read_button(void);
