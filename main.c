#include <avr/io.h>
#include <util/delay.h>

#include "lcd/hd44780.h"

int main(void) {

	DDRC = 0xFF;
	DDRD = 0xFF;
	LCD_init();
//	LCD_cursor_off();
//	LCD_cursor_blink_on();

	while (1) {
		LCD_cursor_top_left_corner();
		LCD_cursor_position(3, 0);
		LCD_print_str("Hello World");
		LCD_cursor_position(3, 1);
		LCD_print_str("Hello AVR");
	}
}
