/* 
 * File:   newmain.c
 * Author: taminh
 *
 * Created on November 13, 2020, 9:39 PM
 */
#include"pic.h"

void setup(){
    TRISB = 0x00;
    
}
void main(){
    setup();
    while(1){
        RB0 = 0;
        timer0(42);
        RB0 = 1;
        RB2 = 0;
        timer1(84);
        RB2 = 1;
        
    }
}
