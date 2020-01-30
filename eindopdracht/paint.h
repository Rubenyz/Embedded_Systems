/* paint.h
 *
 * Paint declarations
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
#include <string.h>
#include "snake.h"
#include "button.h"


void *paint(void *arg);
void paintlines(void);
void paintxy(uint8_t x, uint8_t y);
