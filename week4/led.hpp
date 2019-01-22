/* led.hpp
 *
 * Definitions, statements for led.cpp
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#define LED0 RPI_GPIO_P1_16 //purple LED (bit position 0)
#define LED1 RPI_GPIO_P1_18 //amber LED  (bit position 1)

class Led {
	public:
		void setdir(int ledno, int dir);
		void light(int ledno, bool bOn);
};