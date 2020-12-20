/* 
 * File:   newmain.c
 * Author: taminh
 *
 * Created on December 5, 2020, 2:05 PM
 */


#include<pic.h>
#include "lcd4.h"
int a=0;
void delay(unsigned int a){
    unsigned int i;
    for (i=0; i<a ;i++){
        while(!TMR0IF);
        TMR0IF=0;
    }
    }

//void delay_us(unsigned int delay_us) {
//    unsigned int i;
//    for (i = 0; i <= delay_us; i++);
//}
unsigned int i;

void len() {
    for (i = 50; i < 71; i++) {

        cmd(0xc8);
        dat((i / 10) + 48);
        dat((i % 10) + 48);
        delay(21);
    }
}

void xuong() {
    for (i = 70; i > 50; i--) {
        cmd(0xc8);
        
        dat((i / 10) + 48);
        dat((i % 10) + 48);
        delay(42);

    }

}

void main() {
    unsigned int i;
    TRISB = TRISC0 = TRISC1 = 0;
    OPTION_REG=0X07;
    INTCON = 0X0E;
    lcd_init();
    //     cmd(0x90);
    show("Dem 50-70");
    while (1) {
        len();
        xuong();


    }

}