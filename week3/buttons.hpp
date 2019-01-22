/* buttons.hpp
 *
 * Definitions, statements for buttons.cpp
 * 22 Jan. 2018
 * Ruben Stauttener
 */

#define BUT0 RPI_GPIO_P1_22 //choice button
#define BUT1 RPI_GPIO_P1_15 //stop button

class Button {
	private:
		int butno;
	public:
		bool read(void);
		Button(int butn, int pud);
};