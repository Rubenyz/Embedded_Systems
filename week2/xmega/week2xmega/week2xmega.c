/*
 * week2xmega.c
 *
 * Created: 19-12-2018 13:31:23
 * Author : Ruben
 */ 

#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SYS0 0x01 << 3
#define DATA0 0x01 << 0
#define DATA1 0x01 << 1
#define DATA2 0x01 << 2
#define BUT0 0x01 << 0
#define BUT1 0x01 << 1
#define BUT2 0x01 << 2

int data = 0;

int main(void)
{
	PORTD.DIR |= DATA0 | DATA1 | DATA2;
	PORTD.DIR &= ~(SYS0);				//SYS0 as input

	PORTE.DIR &= ~(BUT0) & ~(BUT1) & ~(BUT2);

	PORTF.DIR |= 0x01;
	
	PORTE.PIN0CTRL = PORT_OPC_PULLUP_gc;
	PORTE.PIN1CTRL = PORT_OPC_PULLUP_gc;
	PORTE.PIN2CTRL = PORT_OPC_PULLUP_gc;

	while(1) {
		while(!(PORTD.IN & SYS0));		//wait until system line is high

		PORTD.OUT |= (~PORTE.IN & 0b00000111) % 8;		//write buttons to data lines
		PORTF.OUT |= 0x01;
		
		PORTD.DIR |= SYS0;			//make system line output
		PORTD.OUT &= ~(SYS0);			//make system line low

		_delay_ms(10);
		PORTD.OUT = 0x00;			//make system and data lines low
		PORTD.DIR &= ~(SYS0);		//make system line input
		PORTF.OUT = 0;

		while(PORTD.IN & SYS0);		//wait until system line is low again
	}
	
}

	