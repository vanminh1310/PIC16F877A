/* 
 * File:   newmain.c
 * Author: BinhNGO
 *
 * Created on September 14, 2020, 10:47 AM
 */

#include<pic.h>
#include<htc.h>

void t2delay();

void main()
{
 TRISB=0;
 T2CON=0b01111000; //postscale=16,prescale=1,timer off
 while(1)
 {
 PORTB=255;
 t2delay();
 PORTB=0;
 t2delay();
 }
}

void t2delay()
{
 unsigned int i;
 T2CON|=(1<<2); //timer2 on
 for(i=0;i<675;i++)
 {
 while(!TMR2IF); 
 TMR2IF=0;
 }
}
