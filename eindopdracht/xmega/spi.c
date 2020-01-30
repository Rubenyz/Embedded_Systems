/*
 * spi.c
 *
 * Created: 29-01-2020 20:22:52
 *  Author: Ruben
 */ 

#include "spi.h"
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint8_t clkedge = 0;
volatile uint8_t update = 0;

ISR(PORTB_INT0_vect) {
	if(SPI.IN & SPI_CLK) {
		clkedge = 1;
		//PORTF.OUTSET = PIN1_bm;
	} else {
		clkedge = 0;
		//PORTF.OUTCLR = PIN1_bm;
	}
	update = 1;
}


void init_spi(void) {
	SPI.OUTCLR = SPI_MISO;
	SPI.DIRCLR = SPI_CS | SPI_CLK;
	SPI.DIRSET = SPI_MISO;
	
	/*
	SPI.PIN0CTRL |= PORT_OPC_PULLUP_gc;
	SPI.PIN1CTRL |= PORT_OPC_PULLDOWN_gc;
	*/
	
	cli();
	
	SPI.INT0MASK = PIN4_bm;
	SPI.PIN4CTRL = PORT_ISC_BOTHEDGES_gc | PORT_OPC_PULLDOWN_gc;
	SPI.INTCTRL = PORT_INT0LVL_LO_gc;
	
	PMIC.CTRL |= PMIC_LOLVLEN_bm;
	sei();
}


void spi_tx(uint16_t data) {
	//send data
	for(uint16_t i=0x8000; i!=0; i>>=1) {
		while(!update) {
			if(getCS()) {
				break;
			}
		}
		update = 0;
		
		if(clkedge) {
			if(data & i) {
				SPI.OUTSET = SPI_MISO;
			} else {
				SPI.OUTCLR = SPI_MISO;
			}
		}
		
		while(!update) {
			if(getCS()) {
				break;
			}
		}
		update = 0;
	}
}


uint8_t getCS(void) {
	return (SPI.IN & SPI_CS);
}