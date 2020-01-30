/*
 * xmega.c
 *
 * Created: 09-01-2020 17:29:17
 * Author : Ruben
 */ 

#define F_CPU 2000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

#include "clock.h"
#include "stream.h"
#include "spi.h"


uint8_t init_accelerometer(void) {
	PORTA.DIR &= ~(PIN0_bm | PIN1_bm);
	
	ADCA.CH0.MUXCTRL = ADC_CH_MUXPOS_PIN0_gc | ADC_CH_MUXNEG_GND_MODE3_gc;
	ADCA.CH1.MUXCTRL = ADC_CH_MUXPOS_PIN1_gc | ADC_CH_MUXNEG_GND_MODE3_gc;
	
	ADCA.CH0.CTRL = ADC_CH_INPUTMODE_DIFF_gc;
	ADCA.CH1.CTRL = ADC_CH_INPUTMODE_DIFF_gc;
	
	ADCA.REFCTRL = ADC_REFSEL_INTVCC_gc;
	ADCA.CTRLB = ADC_RESOLUTION_12BIT_gc | ADC_CONMODE_bm;// | ADC_FREERUN_bm;
	ADCA.PRESCALER = ADC_PRESCALER_DIV32_gc;
	
	ADCA.CTRLA = ADC_ENABLE_bm;
	
	return 0;
}


uint16_t read_adc(uint8_t channel) {
	int16_t res = 0;
	
	switch (channel) {
		case 0:
		ADCA.CH0.CTRL |= ADC_CH_START_bm;
		while(!(ADCA.CH0.INTFLAGS & ADC_CH_CHIF_bm));
		res = ADCA.CH0.RES;
		ADCA.CH0.INTFLAGS |= ADC_CH_CHIF_bm;
		break;
		
		case 1:
		ADCA.CH1.CTRL |= ADC_CH_START_bm;
		while(!(ADCA.CH1.INTFLAGS & ADC_CH_CHIF_bm));
		res = ADCA.CH1.RES;
		ADCA.CH1.INTFLAGS |= ADC_CH_CHIF_bm;
		break;
	}
	
	if(res < 0) {
		res *= -1;	
	}
	
	return (uint16_t)res;
}


int main(void)
{
	//Config32MHzClock_Ext16M();
	
	PORTF.DIR |= PIN0_bm;
	
	cli();
	init_accelerometer();
	init_spi();

	init_stream(F_CPU);
	sei();
	
	clear_screen();
	
	printf("hi\r\n");
	_delay_ms(1000);
	
	PORTF.DIR = 0xFF;
	
    while (1) 
    {
		uint16_t accres = 0x0000;
		
		for(uint16_t id=0; id<2; id++) {
			//wait for chip select to go low
			while(getCS()) {
				accres = read_adc(id);
			}
			
			//transmit data + id
			spi_tx(accres | (id << 12));
			
			//wait for chip select to go high
			while(!getCS());
		}
    }
	
	/*
	while(1) {
		if(getCS()) {
			PORTF.OUTSET = PIN0_bm;
		} else {
			PORTF.OUTCLR = PIN0_bm;
		}
		
		if(SPI.IN & SPI_CLK) {
			PORTF.OUTSET = PIN1_bm;
		} else {
			PORTF.OUTCLR = PIN1_bm;
		}
	}*/
}