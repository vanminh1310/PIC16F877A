/*
 * File:   0_99_button.c
 * Author: Dell
 * my blog http://xcvn.blogspot.com
 * Created on November 21, 2015, 10:10 AM
 */


#define _XTAL_FREQ 12000000
#include<pic.h>
// CONFIG
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF);
unsigned int Count = 0;
unsigned int dem = 0, chuc, donvi;
const unsigned char maled[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
void display(void);
int a =0;
void delay(int a) {
    int i;
    for (i = 0; i < a; i++) {
        while (!TMR0IF);
        TMR0IF = 0;
    }

}

void main(void) {

    
    OPTION_REG = 0X07;
    INTCON |= 0X0E;
    TRISB = 0X00;
    PORTB = 0X00;
    TRISC = 0X00;
    while (1) {


        for (dem = 0; dem < 100; dem++) {
           
            display();
            delay(42);
        }
        for (dem = 99; dem > 0; dem--) {
           
            display();
            delay(21);

        }


    }
}

void display() {
    //   nghin = dem/1000;
    //    tram = (dem - nghin*1000)/100;
    chuc = (dem) / 10;
    donvi = dem % 10;

    PORTB = maled[chuc];
    RC0 = 0;
    __delay_ms(300);
    RC0 = 1;

    PORTB = maled[donvi];
    RC1 = 0;
    __delay_ms(300);
    RC1 = 1;


}
