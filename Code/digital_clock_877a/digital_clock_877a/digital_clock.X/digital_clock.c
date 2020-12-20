/*
 * File:   LCD.c
 * Author: Dell
 * My blog http://xcvn.blogspot.com
 * Created on November 21, 2015, 1:42 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define _XTAL_FREQ 8000000
#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7
#include <xc.h>
#include "lcd.h"
// BEGIN CONFIG
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG
unsigned int minute,second,hour;
void main(void)
{
    char s[10];	
    TRISD = 0X00;	
	Lcd_Init();
    Lcd_Clear();
    while(1)
	{ 
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("  DIGITAL CLOCK");
        __delay_ms(1000);
        sprintf(s,"%u",(hour/10));
        Lcd_Set_Cursor(2,5);
        Lcd_Write_String(s);
        sprintf(s,"%u",(hour%10));
        Lcd_Set_Cursor(2,6);
        Lcd_Write_String(s);
        Lcd_Write_String(":");
        sprintf(s,"%u",(minute/10));
        Lcd_Set_Cursor(2,8);
        Lcd_Write_String(s);
        sprintf(s,"%u",(minute%10));
        Lcd_Set_Cursor(2,9);
        Lcd_Write_String(s);
        Lcd_Write_String(":");
        sprintf(s,"%u",(second/10));
        Lcd_Set_Cursor(2,11);
        Lcd_Write_String(s);
        sprintf(s,"%u",(second%10));
        Lcd_Set_Cursor(2,12);
        Lcd_Write_String(s);
        
        for(int i=0;i<21;i++)
        {
        __delay_ms(50);
        }
        
            second++;
            if(second==61)
            { 
            minute++;
            second=00;
            }
            if(minute==61)
            {
                hour++;
                minute=0;
            }
            if(hour==13)
            {
                hour=0;
            }
    }
}