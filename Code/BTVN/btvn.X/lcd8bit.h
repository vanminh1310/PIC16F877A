/* 
 * File:   lcd8bit.h
 * Author: taminh
 *
 * Created on November 17, 2020, 8:17 PM
 */

#ifndef LCD8BIT_H
#define	LCD8BIT_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCD8BIT_H */

#define rs RC0

#define rw RC1

#define en RC2
#define delay for(i=0;i<100;i++)


void lcd_init()
 {

    cmd(0x38);

    cmd(0x0c);

    cmd(0x06);

    cmd(0x80);

}

void cmd(unsigned char a)
 {

    PORTB = a;

    rs = 0;

    rw = 0;

    en = 1;

    delay;

    en = 0;

}

void dat(unsigned char b)
 {

    PORTB = b;

    rs = 1;

    rw = 0;

    en = 1;

    delay;

    en = 0;

}

void show(unsigned char *s)
 {

    while (*s) {

        dat(*s++);

    }

}


