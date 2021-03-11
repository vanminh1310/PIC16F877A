/* 
 * File:   newmain.c
 * Author: taminh
 *
 * Created on September 14, 2020, 10:06 AM
 */
#include<htc.h>
#include<pic.h>
#include "timerPic.h"

__CONFIG(0x377A);

void main() {
    TRISD = 0; // out
   

    while (1) {
     
        PORTD = 0xff;
        timer0(42);
        PORTD = 0x00;
        timer0(42);
    }
}

