/* countled.hpp
 *
 * Definitions, statements for countled.cpp
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#define BUT0 RPI_GPIO_P1_22 //choice button
#define BUT1 RPI_GPIO_P1_15 //stop button

class ButtonLed:public Led {			//inherited from Led class
	public:
		void setButtonDir(int butno, int dir);
		void setButtonPud(int butno, int pud);
		bool readButton(int butno);
		void setLed(int ledno, int state);
};