/*!
 *  \file    wrapper_test_f0.c
 *  \author  Wim Dolman (<a href="mailto:w.e.dolman@hva.nl">w.e.dolman@hva.nl</a>)
 *  \date    03-10-2016
 *  \version 1.4
 *
 *  \brief   Example for wrapper (uart.c and uart.h).
 *
 *  \details This example using the wrapper (uart.c and uart.h)
 *           for the UART-driver from Atmel's application note AVR1307
 *           (usart_driver.c and usart_driver.h)
 *           which uses avr_compiler.h.
 *
 *           This example uses the wrapper to receive a byte
 *           and to send this byte back in a formatted text string.
 *
 *           \note With the internal RC-oscillators 2 MHz or 32 MHz, it can be
 *           necessary to calibrate this internal clock.
 */
#define F_CPU     2000000UL       //!< system clock frequency

#include <avr/io.h>
#include <avr/interrupt.h>

/*!
 * \brief Macro ENABLE_UART_F0 non zero, in order to ensure
 *        that UART F0 is used.
 */
#define ENABLE_UART_F0   1
#define BAUD             115200    //!< baud rate
#define CLK2X            0         //!< no double clock speed
#include "uart.h"

/*! \brief main routine example with USART0 port F
 *
 *  It initializes the USARTF0 and receive characters from the
 *  UART and sends the characters back in a formatted text string.
 *
 *  \return int
 */
int main(void)
{
  uint16_t c;

  init_uart(&uartF0, &USARTF0, F_CPU, BAUD, CLK2X);

  PMIC.CTRL = PMIC_LOLVLEN_bm;
  sei();

  while(1) {
    if ( (c = uart_getc(&uartF0)) == UART_NO_DATA) {
      continue;
    }

    uart_puts(&uartF0, "Character: '");
    uart_putc(&uartF0, c);
    uart_puts(&uartF0, "'\n");
  }
}
