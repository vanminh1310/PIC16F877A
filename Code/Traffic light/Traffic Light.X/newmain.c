/* 
 * File:   Traffic Light
 * Author: taminh
 *
 * Created on November 3, 2020, 4:43 PM
 */

#include <xc.h>
#include "main.h"
unsigned short i, j, num, dk; // Khai bao bien
// khai bao thu ham led 7 doan

unsigned short mask(unsigned short num) {
    switch (num) {
        case 0: return 0xc0;
        case 1: return 0xf9;
        case 2: return 0xa4;
        case 3: return 0xb0;
        case 4: return 0x99;
        case 5: return 0x92;
        case 6: return 0x82;
        case 7: return 0xf8;
        case 8: return 0x80;
        case 9: return 0x90;
    }
}

void setup() {
    TRISB1 = 0;
    TRISB2 = 0;
    TRISB3 = 0;
    TRISD = 0; // chan D output h?t 
}

void red() {
    RB1 = 1;
    RB2 = 0;
    RB3 = 0;

}

void green() {
    RB1 = 0;
    RB2 = 1;
    RB3 = 0;
}

void yello() {
    RB1 = 0;
    RB2 = 0;
    RB3 = 1;
}

int main() {
    setup();
    while (1) {


        red();
        for (int a = 5; a >= 0; a--) {
            PORTD = mask(a % 10);
            __delay_ms(1000);

        }
        green();
        for (int b = 3; b >= 0; b--) {
            PORTD = mask(b % 10);
            __delay_ms(1000);
        }
        yello();
        for (int c = 2; c >= 0; c--) {
            PORTD = mask(c % 10);
            __delay_ms(1000);
        }



    }


}

