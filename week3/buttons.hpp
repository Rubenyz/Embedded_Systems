/* buttons.hpp
 *
 * Definitions, statements for buttons.cpp
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#define BUT0 RPI_GPIO_P1_22 //choice button
#define BUT1 RPI_GPIO_P1_15 //stop button

class Button {
	public:
		bool read(int butno);
		void setdir(int butno, int dir);
		void setpud(int butno, int pud);
};