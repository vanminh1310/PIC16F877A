/* 
 * File:   newmain.c
 * Author: taminh
 *
 * Created on November 17, 2020, 9:03 PM
 */
#include <pic.h>
#include "lcd4.h"
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF); // 

void setup() {
    TRISB = TRISC0 = TRISC1 = 0; // chan D2 D3 output
    TRISA0 = 1; // KHAI BAO CHAN A0 LA INPUT
}

void adc() {

    unsigned int adcval;

    ADCON1 = 0xc0; //right justified

    ADCON0 = 0x85; //adc on, fosc/64

    while (GO_nDONE); //wait until conversion is finished

    adcval = ((ADRESH << 8) | (ADRESL)); //store the result

    adcval = (adcval / 3) - 1;

    dat((adcval / 1000) + 48);

    dat(((adcval / 100) % 10) + 48);

    dat(((adcval / 10) % 10) + 48);

    dat((adcval % 10) + 48);

}

void main() {
    setup();
    lcd_init();
    //cmd(0x90);
    show("ADC : ");

    while (1) {

        //cmd(0x18);
        cmd(0x8c);
        adc();

    }

}

