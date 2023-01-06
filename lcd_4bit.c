#include "io430.h"
#include "in430.h"
#include "lcd_4bit.h"
 
void lcd_write(unsigned char data)
{
   __delay_cycles(40);
   LCD_DATA = ( ( data >> 4 ) & 0x0F );
   LCD_STROBE();
   LCD_DATA = ( data & 0x0F );
   LCD_STROBE();
}
 
void lcd_clear(void)
{
   LCD_RS = 0;
   lcd_write(0x01);
   __delay_cycles(2000);
}
 
void lcd_puts(const char * s)
{
   LCD_RS = 1;
   while(*s)
   lcd_write(*s++);
}
 
void lcd_putch(char c)
{
   LCD_RS = 1;
   lcd_write(c);
}
 
void lcd_goto (unsigned char row, unsigned char column)
{
   LCD_RS = 0;
   if(row==1)
      lcd_write(0x80+((column-1)%16));
   else if (row==2)
      lcd_write(0xC0+((column-1)%16));
}
 
void lcd_init()
{
   LCD_RS = 0;
   LCD_EN = 0;
 
   __delay_cycles(15000);
   LCD_DATA = 0x03;
   LCD_STROBE();
   __delay_cycles(5000);
   LCD_STROBE();
   __delay_cycles(200);
   LCD_STROBE();
   __delay_cycles(200);
   LCD_DATA = 2;
   LCD_STROBE();
 
   lcd_write(0x28);
   lcd_write(0x0C);
   lcd_clear();
   lcd_write(0x06);
}
