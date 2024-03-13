/*
 * 	main.c
 *  Created on: Mar 1, 2024
 *  Author: AbdElRahman Khalifa
 */

#include"lcd.h"
#include"ultrasonic.h"
#include<avr/interrupt.h>

int main() {
	uint16 value;
	/* LCD initialization  */
	LCD_init();

	/* Ultra Sonic initialization  */
	Ultrasonic_init();

	/* enable global interrupt */
	sei();

	LCD_displayString("Distance= ");

	while (1) {
		/* get the value in cm */
		value = Ultrasonic_readDistance();

		LCD_moveCursor(0, 10);
		LCD_intgerToString(value);
		LCD_displayString(" cm ");
	}
}
