/* 
 * File:   lcd4.h
 * Author: tamin
 *
 * Created on November 24, 2020, 2:48 PM
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

#define rs RD2
#define en RD3




void lcd_init();
void cmd(unsigned char a);
void dat(unsigned char b);
void show(unsigned char *s);
void lcd_delay();
void lcd_init() {
    cmd(0x02);
    cmd(0x28);
    cmd(0x0e);
    cmd(0x06);
    cmd(0x80);
}

void cmd(unsigned char a) {
    rs = 0;
    PORTD &= 0x0F;
    PORTD |= (a & 0xf0);
    en = 1;
    lcd_delay();
    en = 0;
    lcd_delay();
    PORTD &= 0x0f;
    PORTD |= (a << 4 & 0xf0);
    en = 1;
    lcd_delay();
    en = 0;
    lcd_delay();
}

void dat(unsigned char b) {
    rs = 1;
    PORTD &= 0x0F;
    PORTD |= (b & 0xf0);
    en = 1;
    lcd_delay();
    en = 0;
    lcd_delay();
    PORTD &= 0x0f;
    PORTD |= (b << 4 & 0xf0);
    en = 1;
    lcd_delay();
    en = 0;
    lcd_delay();
}

void show(unsigned char *s) {
    while (*s) {
        dat(*s++);
    }
}

void lcd_delay() {
    unsigned int lcd_delay;
    for (lcd_delay = 0; lcd_delay <= 1000; lcd_delay++);
}

