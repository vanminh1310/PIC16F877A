/* 
 * File:   newmain.c
 * Author: BinhNGO
 *
 * Created on September 14, 2020, 10:06 AM
 */

#include<pic.h>

void t0delay();

void main() {
    TRISB = 0; // out
    OPTION_REG = 0x07; //Prescale is assigned to Timer 0, Prescaler value = 256, Fclk = 11.0592MHz

    while (1) {
     
        PORTB = 0xff;
        t0delay();
        PORTB = 0x00;
        t0delay();
    }
}

void t0delay() // 1 second
{
    int i;
    for (i = 0; i < 84; i++) {
        while (!T0IF);
        T0IF = 0;
    }
}
