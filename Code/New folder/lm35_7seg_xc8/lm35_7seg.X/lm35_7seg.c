#include <stdio.h>
#include <stdlib.h>
#define _XTAL_FREQ 8000000 // if 4Mhz is XT
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
#define seg_data PORTC
const unsigned char maled7[] = {0XBF,0X86,0XDB,0XCF,0XE6,0XED,0XFD,0X87,0XFF,0XEF};
void ADCinit (void);
unsigned int ReadADC (void);
unsigned int ADCvalue = 0;
void msdelay(unsigned int itime);
void delay();
void display_digit(int);
int f;
unsigned int voltage;
void main()
{
TRISA = 0xff;
TRISC = 0X00;
TRISD = 0X00;
ADCinit();
unsigned int ones,tens=0;
while(1)
{
ADCvalue = ReadADC();
voltage = 5000.0f / 1023 * ADCvalue;
f = voltage / 10;
ones=f%10;
tens=(f/10)%10;
display_digit(tens);
RD0=1;
delay();
RD0=0;
display_digit(ones);
RD1=1;
delay();
RD1=0;
}
}


void msdelay(unsigned int itime)
{
unsigned int i,j;
for(i=0;i<itime;i++)
for(j=0;j<1275;j++);
}


void display_digit(int c)
{
switch(c)
{
case 0:
seg_data=0xC0;
break;
case 1:
seg_data=0xF9;
break;
case 2:
seg_data=0xA4;
break;
case 3:
seg_data=0xB0;
break;
case 4:
seg_data=0x99;
break;
case 5:
seg_data=0x92;
break;
case 6:
seg_data=0x82;
break;
case 7:
seg_data=0xF8;
break;
case 8:
seg_data=0x80;
break;
case 9:
seg_data=0x90;
break;
}
}
void delay()
{
long int k;
for(k=0;k<100;k++);
}
void ADCinit (void)// adc
{
    // chon tan so clock cho bo adc
    ADCON1bits.ADCS2 = 0, ADCON0bits.ADCS1 = 0,ADCON0bits.ADCS0 = 1;
    // chon kenh adc la kenh an0
    ADCON0bits.CHS2 = 0, ADCON0bits.CHS1 = 0, ADCON0bits.CHS0 = 0;
    // chon cach luu data
    ADCON1bits.ADFM = 1;
    // cau hinh cong vao
    ADCON1bits.PCFG3 = 1,  ADCON1bits.PCFG2 = 1,  ADCON1bits.PCFG1 = 1,  ADCON1bits.PCFG0 = 0;
    // cap nguon cho khoi adc
    ADCON0bits.ADON = 1;
}
unsigned int ReadADC (void)// doc len 7 doan
{
    unsigned int TempValue = 0;
    ADCON0bits.GO_nDONE = 1;
    while(ADCON0bits.GO_nDONE);
    TempValue = ADRESH*256 + ADRESL;
    return (TempValue);
}