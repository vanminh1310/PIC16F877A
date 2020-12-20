/* 
 * File:   7seg_CA.h
 * Author: tamin
 *
 * Created on November 29, 2020, 8:37 AM
 */


#include<pic.h>

unsigned char LED_MAP[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void delay_us(unsigned int delay_us)
{
    unsigned int i;
    for(i=0;i<=delay_us;i++);
}
void delay_ms(unsigned int delay_ms)
{
    unsigned int i;
    for(i=0;i<delay_ms;i++) delay_us(120);
}

void SEG7_OUT(unsigned char Dem)
{
   
    unsigned char hc,hd;
    hc=Dem/10;
    hd=Dem%10;
    hc=LED_MAP[hc];
    hd=LED_MAP[hd];
    PORTD=hc;
    RC0=1;
    delay_ms(100);
    RC0=0;
    PORTD=hd;
    RC1=1;
    delay_ms(100);
    RC1=0;
}
void SEG7_OUT2(unsigned char Dem)
{
   
    unsigned char hc,hd;
    hc=Dem/10;
    hd=Dem%10;
    hc=LED_MAP[hc];
    hd=LED_MAP[hd];
    PORTD=hc;
    RC0=1;
    delay_ms(100);
    RC0=0;
    PORTD=hd;
    RC1=1;
    delay_ms(100);
    RC1=0;
}

