#include <xc.h>
#include "lcd.h"

#define _XTAL_FREQ   4E6

#define LCD_EN       PORTBbits.RB3
#define LCD_RS       PORTBbits.RB2
#define LCD_DATA     PORTB
#define LCD_STROBE() (LCD_EN=1), (LCD_EN=0)


// write a byte to the LCD in 4 bit mode
void lcd_write(unsigned char c)
 { __delay_us(40);
   LCD_DATA &= 0x0f;
   LCD_DATA |= (c & 0xf0);
   LCD_STROBE();
   LCD_DATA &= 0x0f; 
   LCD_DATA |= ((c<<4) & 0xf0);
   LCD_STROBE();
 }

// Clear and home the LCD
void lcd_clear(void)
 { LCD_RS = 0;
   lcd_write(0x1);
   __delay_ms(2);
 }

// write a string of chars to the LCD
void lcd_puts(const char * s)
 { LCD_RS = 1;     // write characters
   while(*s)
      lcd_write(*s++);
 }

// write one character to the LCD
void lcd_putch(char c)
 { LCD_RS = 1;     // write characters
   lcd_write( c );
 }

// Go to the specified position
void lcd_goto(unsigned char pos)
 { LCD_RS = 0;
   lcd_write(0x80+pos);
 }
        
// initialise the LCD - put into 4 bit mode
void lcd_init(void)
 { char init_value;
   
   init_value = 0x3;
   LCD_RS = 0;
   LCD_EN = 0;
        
   __delay_ms(15);     // wait 15mSec after power applied,
   LCD_DATA &= 0x0f;
   LCD_DATA |= (init_value<<4) & 0xf0 ;
   LCD_STROBE();
   __delay_ms(5);
   LCD_STROBE();
   __delay_us(200);
   LCD_STROBE();
   __delay_us(200);
   LCD_DATA &= 0x0f; 
   LCD_DATA |= (2<<4) & 0xf0;   // Four bit mode
   LCD_STROBE();

   lcd_write(0x28);  // Set interface length
   lcd_write(0xc);   // Display On, Cursor Off, Cursor Blink off
   lcd_clear();      // Clear screen
   lcd_write(0x6);   // Set entry Mode
 }



