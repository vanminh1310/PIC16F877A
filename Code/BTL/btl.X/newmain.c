/*
 * File:   main.c
 * Author: vanminh
 *
 *
 */


#include <pic.h>
#include "uart.h"
#include "lcd4.h"

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF);

#define delay for(z=0;z<=50000;z++)

unsigned int z;

void interrupt ser();

void main() {
    TRISB = TRISC0 = TRISC1 = 0;
    INTCON |= 0b11000000;
    PIE1 = 0b00100000;
    lcd_init();
    serial_init();
    cmd(0x80);
    show("Serial interrupt");

    while (1) {
        
    }
}

void interrupt ser() {
    unsigned char a = RCREG;
    tx(a);
    cmd(0xc5);
    show("Key : ");
    delay;
    dat(a);
    delay;
    TXIF = RCIF = 0;
}