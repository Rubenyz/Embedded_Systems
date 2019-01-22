/* countled.hpp
 *
 * Definitions, statements for countled.cpp
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#define LED0 RPI_GPIO_P1_16 //purple LED (bit position 0)
#define LED1 RPI_GPIO_P1_18 //amber LED  (bit position 1)

class CountLed:public Led {			//inherited from Led class
	public:
		int countfur(void);
		void setLeds(int ledno0, int ledno1);
};