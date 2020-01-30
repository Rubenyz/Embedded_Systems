// /*!
//  *  \file    stream_test.c
//  *  \author  Wim Dolman (<a href="mailto:w.e.dolman@hva.nl">w.e.dolman@hva.nl</a>)
//  *  \date    03-10-2016
//  *  \version 1.4
//  *
//  *  \brief   Example for stream (stream.c and stream.h).
//  *
//  *  \details This example for HvA-Xmegaboard with streams
//  *           using stream.c and stream.h
//  *           with the wrapper (uart.c and uart.h)
//  *           for the UART-driver from Atmel's application note AVR1307
//  *           (usart_driver.c and usart_driver.h)
//  *           which uses avr_compiler.h.
//  *
//  *           This example uses scanf to receive a byte
//  *           and to send this byte back in a formatted text string.
//  *
//  *           This example is code 19.19 from 'De taal C en de Xmega' second edition,
//  *           see <a href="http://www.dolman-wim.nl/xmega/book/index.php">Voorbeelden uit 'De taal C en de Xmega'</a>
//  *
//  *           The baud rate is 115200
//  */
// #define F_CPU     2000000UL       //!< system clock frequency
// 
// #include <avr/io.h>
// #include <avr/interrupt.h>
// #include <stdio.h>
// #include <util/delay.h>
// 
// #include "stream.h"
// 
// /*! \brief main routine example for HvA-Xmegaboard
//  *
//  *  It initializes the standard streams for USARTF0. It wait until it receives a
//  *  character from the UART and sends the character back in a formatted text string.
//  *
//  *  \return int
//  */
// int main(void)
// {
//   uint8_t c;
// 
//   init_stream(F_CPU);
//   sei();
// 
//   while(1) {
//     //scanf("%c", &c);
//     printf("Character: '%c' Hex: %#x\n", c, c);
// 	_delay_ms(100);
//   }
// }
