# HD44780
C library for HD44780 LCD driver

### Usage
- Copy `lcd` folder into your project.
- Include `./lcd/hd4470.h` file in `main.c`.
- Connect your microcontroller to LCD driver as shown in <a href="https://github.com/filipkorus/HD44780//tree/master/img/scheme.png" target="_blank">scheme</a>.
- Initialize LCD with `LCD_init()`.
- Your LCD library is ready to use!

### LCD_init()
```c
void LCD_init()
```
Initialize LCD, wait for VCC rises to 4.5V, enable `8-bit` mode, clear the screen and set cursor position to the first character.

### LCD_clear_screen()
```c
void LCD_clear_screen()
```
Clear screen and set cursor to default position (0, 0).

### LCD_cursor_position(x, row)
```c
void LCD_cursor_position(int x, int row)
```
Set the cursor to the specified position.<br>
For instance:
* 1st character, 1st row: LCD_cursor_position(0, 0);
* 5th character, 2nd row: LCD_cursor_position(4, 1);
* 16th character (last one), 2nd row: LCD_cursor_position(15, 1);

### LCD_print_str()
```c
void LCD_print_str()
```
Print string to LCD.

### LCD_print_str()
```c
void LCD_print_str()
```
Print string to LCD.

### All commands available
```c
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
void LCD_cursor_position(int x, int row);
void LCD_shift_cursor_left();
void LCD_shift_cursor_right();
void LCD_shift_display_left();
void LCD_shift_display_right();
```

## Scheme
![scheme](https://github.com/filipkorus/HD44780/blob/master/img/scheme.png)

## Demostration
![demostration](https://github.com/filipkorus/HD44780/blob/master/img/demo.jpg)

## Sources
* <a href="http://www.dinceraydin.com/lcd/commands.htm" target="_blank">http://www.dinceraydin.com/lcd/commands.htm</a>
* <a href="https://www.sparkfun.com/datasheets/LCD/HD44780.pdf" target="_blank">https://www.sparkfun.com/datasheets/LCD/HD44780.pdf</a>
