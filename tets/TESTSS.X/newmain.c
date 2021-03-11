/* 
 * File:   newmain.c
 * Author: tamin
 *
 * Created on January 21, 2021, 1:55 PM
 */

#include<pic.h>
#define _XTAL_FREQ 12000000

void GPIO_init(void)
{
    TRISB = 0X00;
    TRISC = 0X00;
    PORTC = 0X00;
    
}
void sanghet(){
    PORTB = 0xFF;
    PORTC=0XFF;
   __delay_ms(2000);

}
void chayled(){

 PORTC = 0Xff;
 PORTC = 0Xff;
 int i,j ;
//        PORTB = 0X01;
        
        for(i=0;i<8;i++)
        {
           __delay_ms(1000);
            PORTB = PORTB<<1;
        }
//         PORTC = 0X01;
        for(i=0;i<8;i++)
        {
           __delay_ms(1000);
            PORTC = PORTC<<1;
        }
        

		
}  

void test2(){
     int i,j ;
  __delay_ms(500);
        PORTB = 0X00;
           PORTC = 0X00;
        for(i=0;i<9;i++)
        {
            __delay_ms(500);
            PORTB = (PORTB<<1) | 0X01;
            PORTC = PORTC>>1;
           PORTC = PORTC | 0X80;
        }
        __delay_ms(500);

}



void lusang(){
     int i,j ;
PORTC = 0X00;
PORTB = 0X00;
    __delay_ms(300);
        for(i=0;i<9;i++)
        {
           __delay_ms(300);
           PORTB = PORTB<<1;
           PORTB = PORTB | 1;
           __delay_ms(300);
           PORTC = PORTC>>1;
           PORTC = PORTC | 0X80;
         PORTB = PORTB<<1;
          PORTC = PORTC>>1; 
        }
    
      

}

void lusang2(){
    int i,j ;
    __delay_ms(300);
   PORTC = 0X00;
      for(i=0;i<9;i++)
       {
          
       }

}

             
            
        



void main(){
    GPIO_init();
    //sanghet();
    //chayled();
    test2();
    chayled();
    
    // sangdon();

}