/* 
 * File:   newmain.c
 * Author: BinhNGO
 *
 * Created on September 14, 2020, 10:20 AM
 */

#include<pic.h>

void t1delay();

void main()
{
 TRISB=0;
 T1CON=0x01;   //Prescale value = 1:1, It using Internal clock, Timer 1 ON
 while(1) {
 PORTB=0xff;
 t1delay();
 PORTB=0;
 t1delay();
 }
}

void t1delay()
{
 int i;
 for(i=0;i<42;i++) {
 TMR1H=TMR1L=0;
 while(!TMR1IF);
 TMR1IF=0;
 }
}
