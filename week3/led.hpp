/* led.hpp
 *
 * Definitions, statements for led.cpp
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#define LED0 RPI_GPIO_P1_16 //purple LED
#define LED1 RPI_GPIO_P1_18 //amber LED

class Led {
	public:
		void blink(int ledno);
		void setdir(int ledno, int dir);
};