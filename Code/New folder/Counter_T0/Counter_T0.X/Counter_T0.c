/*
 * File:   0_99_button.c
 * Author: Dell
 * my blog http://xcvn.blogspot.com
 * Created on November 21, 2015, 10:10 AM
 */

#include <stdio.h>
#include <stdlib.h>
#define _XTAL_FREQ 8000000
#include <xc.h>
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
unsigned int dem = 0,nghin,tram,chuc,donvi;
const unsigned char maled[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
void display(void);
void main(void)
{
    OPTION_REGbits.T0CS = 1;          // Dem xung ngoai
    OPTION_REGbits.PSA = 1;           // Su dung bo chia truoc WDT
    TRISB = 0;
    PORTB = 0;
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    PORTD = 0;
    while (1)
    {
        display();
        dem=TMR0;
        if(dem>=100)
        {
            TMR0=0;
            dem=0;
        }
    }
}
void display (void)
{
    chuc = dem/10;
    donvi = dem%10;
    
    PORTB = maled[chuc];
    RD0=0;
    __delay_ms(10);
    RD0=1;
    
    PORTB = maled[donvi];
    RD1=0;
    __delay_ms(10);
    RD1=1;
}
