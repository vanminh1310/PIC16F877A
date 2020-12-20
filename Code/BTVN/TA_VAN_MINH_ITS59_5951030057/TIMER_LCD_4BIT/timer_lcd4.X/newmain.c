/* 
 * File:   newmain.c
 * Author: taminh
 *
 * Created on November 18, 2020, 2:54 PM
 */
#include<pic.h>
#include"lcd4.h"
#include "timers.h"
#define delay for(z=0;z<=50000;z++)

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF); // 
unsigned int z;

int a=0,b=0,c=0;

void interrupt tmr0()
{
	if(TMR0IF) {
		a++;
		if(a==42)					//1sec
		{
			cmd(0x80);
			show("Timer 0 interupt");
            RD0= 1;//
            RD1= 0;
            RD2= 0;
			a=0;
			delay;
		}
		TMR0IF=0;	
	} else if(TMR1IF) {
		b++;
		if(b==84)					//2secs
		{
			cmd(0xc0);
			show("Timer 1 interupt");
            RD0 = 0;
            RD1 = 1;
			b=0;
			delay;
		}
		TMR1IF=0;	
	} else if(TMR2IF) {
		c++;
		if(c==2025)					//3secs
		{
			cmd(0x80);
			show("Timer 2 interupt");
			RD0 = 0;
            RD1 = 0;
            RD2 = 1;
            c=0;
			delay;
		}
		TMR2IF=0;	
	}
			
}

void intr_init()
{
	INTCON=0xe0;
	PIE1=0x03;
}

void timer_init()
{
	OPTION_REG=0b00000111;		//internal clk,rising edge,prescaler with tim0,256
	T1CON=0b00000001;			//prescale=1,oscilator is off,internal clk,timer on
	T2CON=0b01111100;			//postscale=16,prescale=1,timer on
}








void main()
{
 //TRISD0 = TRISD1 = TRISD2 = 
TRISD0=TRISD1=TRISD2= TRISB4= TRISB5 = TRISB6 = TRISB7 = TRISC0 = TRISC1 = 0; 
    
	lcd_init();
  
	timer_init();
	intr_init();
    

    
	while(1) {
      
        delay;
        cmd(0x01);
        delay;
		
    
	}
}