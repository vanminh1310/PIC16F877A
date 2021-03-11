

#include <stdio.h>
#include <stdlib.h>
#define _XTAL_FREQ 4000000
#include <xc.h>
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
void GPIO_init (void);
void SANGHET (void);
void TATHET (void);
void XENKE (void);
void SANGNUA (void);
void main (void)
{
    GPIO_init();
    while(1)
    {
        SANGHET();
        __delay_ms(500);       
        TATHET();
        __delay_ms(500);        
        XENKE();
        __delay_ms(500);        
        SANGNUA();
        __delay_ms(500);
    }
}
void GPIO_init(void)
{
    TRISB = 0X00;
    PORTB = 0X00;
}
void SANGHET (void)
{
    PORTB = 0X66;
}
void TATHET (void)
{
    PORTB = 0X00;
}
void XENKE (void)
{
    PORTB = 0XAA;
    __delay_ms(500);
    PORTB = 0X55;
}
void SANGNUA (void)
{
    PORTB = 0X0F;
    __delay_ms(500);
    PORTB = 0XF0;
}