/* 
 * File:   newmain.c
 * Author: taminh
 *
 * Created on November 14, 2020, 2:31 PM
 */

#include <pic.h>
#include "../LCD.X/lcd4.h"

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF);



void main()
 {

    unsigned int i;

    TRISB = TRISC2 = TRISC3 = 0;

    lcd_init();

    cmd(0x90);

    //show("www.utc.edu.vn");

    show("CHAO MUNG KTDT&THCN-GTVT");
    show("Binh NGO, WELCOME :)");
    while (1)
 {

        for (i = 0; i < 15000; i++);

        cmd(0x18);

        for (i = 0; i < 15000; i++);

    }

}


