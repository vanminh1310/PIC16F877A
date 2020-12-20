/* 
 * File:   newmain.c
 * Author: taminh
 *
 * Created on September 14, 2020, 10:06 AM
 */

#include<pic.h>
#include "timerPic.h"



void main() {
    TRISB = 0; // out
   

    while (1) {
     
        PORTB = 0xff;
        timer1(84);
        PORTB = 0x00;
        timer1(84);
    }
}

