/* 
 * File:   lcd4.h
 * Author: tamin
 *
 * Created on November 17, 2020, 8:28 PM
 */

#ifndef LCD4_H
#define	LCD4_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCD4_H */
#define rs RC0

#define en RC1

void lcd_init();

void cmd(unsigned char a);

void dat(unsigned char b);

void show(unsigned char *s);

void lcd_delay();

void lcd_init()
 {
//  TRISB = TRISD1 = TRISD2 = 0;
    cmd(0x02);

    cmd(0x28);

    cmd(0x0e);

    cmd(0x06);

    cmd(0x80);

}

void cmd(unsigned char a)
 {

    rs = 0;

    PORTB &= 0x0F;

    PORTB |= (a & 0xf0);

    en = 1;

    lcd_delay();

    en = 0;
    lcd_delay();

    PORTB &= 0x0f;

    PORTB |= (a << 4 & 0xf0);

    en = 1;

    lcd_delay();

    en = 0;

    lcd_delay();

}

void dat(unsigned char b)
 {

    rs = 1;

    PORTB &= 0x0F;

    PORTB |= (b & 0xf0);

    en = 1;

    lcd_delay();

    en = 0;

    lcd_delay();

    PORTB &= 0x0f;

    PORTB |= (b << 4 & 0xf0);

    en = 1;

    lcd_delay();

    en = 0;

    lcd_delay();

}

void show(char *s)
 {

    while (*s) {

        dat(*s++);

    }

}

void lcd_delay()
 {

    unsigned int lcd_delay;

    for (lcd_delay = 0; lcd_delay <= 1000; lcd_delay++);

}



