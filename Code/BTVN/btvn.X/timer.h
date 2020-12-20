/* 
 * File:   timerPic.h
 * Author: taminh
 *
 * Created on November 13, 2020, 9:02 PM
 */

#ifndef TIMERPIC_H
#define	TIMERPIC_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TIMERPIC_H */

void timer0(int a) {
    OPTION_REG|=0x07; 
    for (int i = 0; i < a; i++) {
        while (!T0IF);
        T0IF = 0;
    }
}

void timer1(int b) {
    T1CON|=0x01;
    for (int i = 0; i < b; i++) {
        TMR1H = TMR1L = 0;

        while (!TMR1IF);

        TMR1IF = 0;

    }

}

void timer2(int c)
 {
    T2CON|=0b01111000; 
    unsigned int i;

    T2CON |= (1 << 2); //timer2 on

    for (i = 0; i < c; i++)
 {

        while (!TMR2IF); // khi ch?a s?y ra ng?t ch?y bt, có ng?t thì t?t 

        TMR2IF = 0;

    }

}


