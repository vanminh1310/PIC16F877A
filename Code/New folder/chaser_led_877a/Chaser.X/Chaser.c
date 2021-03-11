/* File Chaser.c
 * 8:30 2/11/1025
 * My blog http://xcvn.blogspot.com
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _XTAL_FREQ 8000000
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
void GPIO_init(void);// goi ham xuat nhap
void main (void)
{
    GPIO_init(); //
    unsigned char i,I,J,CD,D,Y,X;
    while(1)
    {
         //left d?ch trái
        PORTB = 0X01;
        for(i=0;i<8;i++)
        {
           __delay_ms(300);
            PORTB = PORTB<<1;
        }
        // right d?ch ph?i 
        __delay_ms(300);
        PORTB = 0X80;
        for(i=0;i<8;i++)
        {
            __delay_ms(300);
            PORTB = PORTB>>1;
        }
        // left 2 d?ch trái 2 led
        PORTB = 0X03;
        for(i=0;i<4;i++)
        {
            __delay_ms(300);
            PORTB = PORTB<<2;
        }
        // right 2 d?ch ph?i hai led 
        PORTB = 0XC0;
        for(i=0;i<4;i++)
        {
            __delay_ms(300);
            PORTB = PORTB>>2;
        }
        // chase left sáng d?n 
//        __delay_ms(300);
//        PORTB = 0X00;
//        for(i=0;i<9;i++)
//        {
//           __delay_ms(300);
//           PORTB = PORTB>>1;
//           PORTB = PORTB | 0X80;
//        }
        // chase right sáng d?n ph?i 
//       __delay_ms(300);
//        PORTB = 0X00;
//        for(i=0;i<9;i++)
//        {
//           __delay_ms(300);
//           PORTB = PORTB<<1;
//           PORTB = PORTB | 1;
//        }
      //   chase on left  sáng d?n t?t d?n trái 
        __delay_ms(300);
        PORTB = 0X00;
        for(i=0;i<9;i++)
        {
            __delay_ms(300);
            PORTB = (PORTB<<1) | 0X01;
        }
      //   chase off left sáng d?n t?t d?n trái
        __delay_ms(300);
        for(i=0;i<9;i++)
        {
            __delay_ms(300);
            PORTB = PORTB<<1;
        }
        // chase right on and off sáng d?n t?t d?n ph?i 
//        __delay_ms(300);
//        X=0X00000000;
//        for(I=0;I<8;I++)
//        {
//           X=(X<<1)+0X01;
//           PORTB = X;
//           __delay_ms(300);
//        }
//        for(I=0;I<8;I++)
//        {
//           X=(X>>1);
//           PORTB = X;
//           __delay_ms(300);
//        }
        // don 1 sáng d?n 1
          __delay_ms(300);
        CD=0X00000000;
        for ( J=8;J>0;J--)
        {
        D=0X00000001;
        for(I=0;I<J;I++)
        {
        Y=CD+D;
        PORTB = (Y);
        __delay_ms(300);
        D=(D<<1);
        }
        CD=Y;
        }
        // don 2 sáng d?n 2 led 
        __delay_ms(300);
        CD=0X00;
        for ( J=4;J>0;J--)
        {
        __delay_ms(300);
        D=0X03;//0x03
        for(I=0;I<J;I++)
        {
        __delay_ms(100);
        Y=CD+D;
        PORTB = (Y);
        __delay_ms(300);
        D=(D<<2);
        }
        CD=Y;
        }
        }
    }
void GPIO_init(void)
{
    TRISB = 0X00; // cho porta la  output
    PORTB = 0X00; //
}
