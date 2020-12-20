#include <pic.h>
#include "7seg_CA.h"

__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF);
void t0delay() // 1 second

{

int i;

for(i=0;i<42;i++) {

while(!T0IF);

T0IF=0;
}}



//void intr_init()
//{
//	INTCON=0xe0;
//	PIE1=0x03;
//}
//
//void timer_init()
//{
//	OPTION_REG=0b00000111;		//internal clk,rising edge,prescaler with tim0,256
//	T1CON=0b00000001;			//prescale=1,oscilator is off,internal clk,timer on
//	T2CON=0b01111100;			//postscale=16,prescale=1,timer on
//}
//
//int a;
//void interrupt tmr0(void)
//
//{
//    if(RB0==1)
//
//    {
//        if(TMR0IF){
//            a++;
//            if(a==42){
//                RB5=1;
//                delay_ms(1000);
//            }
//            TMR0IF=0;
//        }
//        
//    }
//    else{
//        RB5=0;
//    
//    }
//
//
//
//}
void interrupt ISR(void)

{   
    
        while(!RB0){
             t0delay(42);
             RB5=!RB5;
             INTF=0;
        }
         
    

}



void main()
{
    TRISD=0;
    TRISB0=1;
    TRISB5=0;
    TRISC0=TRISC1=0;
    OPTION_REG=0X00;	//falling edge int @ enable pullup portb
 OPTION_REG=0X07;
INTCON|=0Xd0; 

    
    unsigned char i;
    while(1)
    {
        RB5=0;
      for(i=50;i<71;i++)
      {
            SEG7_OUT(i);
            delay_us(500);
            if(i==70)
            {
                for(i=70;i>49;i--)
                {
                    SEG7_OUT2(i);
                    delay_us(1000);
                }
            }
      }
    }
}

