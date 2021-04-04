/*
 *      Author: Filip Korus
 *	   Website: https://filipkorus.com
 * 	   Created: 3 April 2021
 * Description: simple library for LCD usage
 * 				with microcontrollers
 */

#ifndef LCD_HD44780_H_
#define LCD_HD44780_H_

/* ________________________________ */

/*
 *	 BITS: D0 - D7 PINS
 *	   RS: C0, C1 PINS
 * 	DELAY: text rendering delay
 * 		   must be GREATER than 0
 */
#define BITS PORTD
#define RS PORTC
#define DELAY 30

/* ________________________________ */

void LCD_cmd(unsigned char cmd);
void LCD_data(unsigned char data);
void LCD_init();
void LCD_print_str(char *str);
void LCD_clear_screen();
void LCD_cursor_top_left_corner();
void LCD_move_cursor_right();
void LCD_2nd_line();
void LCD_display_off();
void LCD_display_on();
void LCD_cursor_off();
void LCD_cursor_on();
void LCD_cursor_blink_on();
void LCD_cursor_blink_off();
void LCD_cursor_position(int x, int row); // x: 0 - 15, row: 0 or 1
void LCD_shift_cursor_left();
void LCD_shift_cursor_right();
void LCD_shift_display_left();
void LCD_shift_display_right();
/* ________________________________ */

#endif /* LCD_HD44780_H_ */
