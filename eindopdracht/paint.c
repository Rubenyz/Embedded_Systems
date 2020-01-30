/* paint.c
 *
 * Paint functions
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#include "paint.h"
#include "spi.h"
#include <math.h>

uint8_t xmax = 31;
uint8_t ymax = 16;

char stringbuf[1000];


void *paint(void *arg) {
	while(!sysReset) {
		int8_t xdeg = (adcdata[0]-1100)*0.1;
		int8_t ydeg = -(adcdata[1]-1100)*0.1;
		
		if(!pauseWait) {
			paintxy(round((adcdata[0]-650)/30), round((adcdata[1]-650)/60));
			printf("   x: %d°\r\n   y: %d°\r\n", xdeg, ydeg);
		}
		//printf("%d %d\r\n", adcdata[0], adcdata[1]);
		bcm2835_delay(150);
	}
}


void paintxy(uint8_t x, uint8_t y) {
	if(x<0 || y<0 || x>=xmax || y>=ymax) {
		x=round(xmax/2);
		y=round(ymax/2);
	}
	
	//clear screen
	strcpy(stringbuf, "\e[H\e[2J\e[3J");
	
	strcat(stringbuf, "\r\n");
	
	//upper row
	strcat(stringbuf, "   ╔");
	for(uint8_t i=0; i<xmax; i++) {
		strcat(stringbuf, "═");
	}
	strcat(stringbuf, "╗\r\n");
	
	//vertical filling
	for(uint8_t i=0; i<y; i++) {
		strcat(stringbuf, "   ║");
		for(uint8_t j=0; j<xmax; j++) {
			strcat(stringbuf, " ");
		}
		strcat(stringbuf, "║\r\n");
	}
	
	//horizontal filling plus 'O'
	strcat(stringbuf, "   ║");
	for(uint8_t i=0; i<x; i++) {
		strcat(stringbuf, " ");
	}
	strcat(stringbuf, "O");
	for(uint8_t i=0; i<(xmax-x-1); i++) {
		strcat(stringbuf, " ");
	}
	strcat(stringbuf, "║\r\n");
	
	//vertical filling
	for(uint8_t i=0; i<ymax-y-1; i++) {
		strcat(stringbuf, "   ║");
		for(uint8_t j=0; j<xmax; j++) {
			strcat(stringbuf, " ");
		}
		strcat(stringbuf, "║\r\n");
	}
	
	//bottom row
	strcat(stringbuf, "   ╚");
	for(uint8_t i=0; i<xmax; i++) {
		strcat(stringbuf, "═");
	}
	strcat(stringbuf, "╝\r\n");
	
	printf("%s", stringbuf);
}
// ╝ ╗ ╚ ╔ ═ ║
