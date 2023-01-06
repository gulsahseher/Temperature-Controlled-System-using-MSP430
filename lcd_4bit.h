#include "msp430.h"
#include "in430.h"
#define LCD_RS P2OUT_bit.P6
#define LCD_EN P2OUT_bit.P7
#define LCD_DATA P1OUT
#define LCD_STROBE() ((P2OUT|=BIT7),(P2OUT&=~BIT7))
#define nop() asm("nop")
#define LCD_STROBE() asm("nop")

extern void lcd_write(unsigned char); //Used to send commands to the LCD
extern void lcd_clear(void); // Cleans the LCD screen
extern void lcd_puts(const char *); //Writes string expression to LCD
extern void lcd_goto(unsigned char,unsigned char);// LCD goes to the desired place as rows and columns
extern void lcd_init(void); // LCD initial settings are made.
extern void lcd_putch(char); // It is used to write a single write to the LCD
extern void delay_ms(unsigned int); // Delay