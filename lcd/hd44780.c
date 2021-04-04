/*
 *		Author: Filip Korus
 *	   Website: https://filipkorus.com
 * 	   Created: 3 April 2021
 * Description: simple library for LCD usage
 * 				with microcontrollers
 */
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>

#include "hd44780.h"

void LCD_cmd(unsigned char cmd) {
	RS = 0x02;
	BITS = cmd;
	RS = 0x00;
	_delay_ms(DELAY);
}

void LCD_data(unsigned char data) {
	RS = 0x03;
	BITS = data;
	RS = 0x01;
	_delay_ms(DELAY);
}

void LCD_init() {
	_delay_ms(15); // wait for more than 15 ms
				// after VCC rises to 4.5 V
	LCD_cmd(0x38); // enable 8-bit mode
	LCD_cursor_blink_on();
	LCD_cursor_dir_right();
	LCD_clear_screen();
	LCD_cursor_position(0, 0);
}

void LCD_print_str(char *str) {
	while(*str) LCD_data(*str++);
}

void LCD_print_int(int n) {
	char buf[64];
	snprintf(buf, sizeof(buf), "%d", n);
	LCD_print_str(buf);
}

void LCD_print_float(float n) {
	n = ((int)(n * 100 + .5) / 100.0);
	char buf[64];
	snprintf(buf, sizeof(buf), "%d", (int)(n));
	LCD_print_str(buf);
	LCD_print_str(".");
	if(n < 0) n = -n;
	snprintf(buf, sizeof(buf), "%d", (int)(n*100)% 100);
	LCD_print_str(buf);
}

void LCD_clear_screen() {
	LCD_cmd(0x01);
	LCD_cursor_position(0, 0);
}

void LCD_cursor_top_left_corner() {
	LCD_cmd(0x02);
}

void LCD_cursor_dir_right() {
	LCD_cmd(0x06);
}

void LCD_cursor_dir_left() {
	LCD_cmd(0x07);
}

void LCD_2nd_line() {
	LCD_cursor_position(0, 1);
}

void LCD_display_off() {
	LCD_cmd(0x0A);
}

void LCD_display_on() {
	LCD_cmd(0x0E);
}

void LCD_cursor_off() {
	LCD_cmd(0x0C);
}

void LCD_cursor_on() {
	LCD_cmd(0x0E);
}

void LCD_cursor_blink_on() {
	LCD_cmd(0x0F);
}

void LCD_cursor_blink_off() {
	LCD_cmd(0x0E);
}

void LCD_cursor_position(int x, int row) {
	x %= 16;
	row %= 2;
	if(row == 1) x += 64;
	LCD_cmd(0x80 + x);
}

void LCD_shift_cursor_left(){
	LCD_cmd(0x10);
}

void LCD_shift_cursor_right(){
	LCD_cmd(0x14);
}

void LCD_shift_display_left(){
	LCD_cmd(0x18);
}

void LCD_shift_display_right(){
	LCD_cmd(0x1C);
}

void LCD_cursor_left() {
	LCD_cmd(0x10);
}

void LCD_cursor_right() {
	LCD_cmd(0x14);
}
