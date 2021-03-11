/*
 * File:   Keypad.c
 * Author: BinhNGO
 *
 * Created on August 13, 2020, 1:30 PM
 */

#include <pic.h>
#include "key.h"
#include"lcd4.h"

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF);






void main() {
    unsigned int i;
    TRISD = 0;
    TRISC0=TRISC1 = 0;
    TRISC5 = 0;
    lcd_init();
    keyinit();
    unsigned char b;
    cmd(0x80);
    show("  Enter the Key ");
    while (1) {
        cmd(0xc7);
        b = key();






        dat(b);


    }
}



