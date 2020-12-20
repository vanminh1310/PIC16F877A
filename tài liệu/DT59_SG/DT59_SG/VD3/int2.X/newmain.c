/* 
 * File:   newmain.c
 * Author: BinhNGO
 *
 * Created on September 7, 2020, 10:57 AM
 */

//Multiple Externel Interrupt
 
#include<pic.h>

#define delay  for(i=0; i<= 50000; i++)
#define LED PORTD
 
#define PORTB_4    (1<<4)
#define PORTB_5    (1<<5)
#define PORTB_6    (1<<6)
#define PORTB_7    (1<<7)
 
unsigned char old_PORTB = 0;
unsigned int i;
 
void interrupt  ISR(void)
{
    unsigned char key_pressed;
    unsigned char new_PORTB = PORTB;
    key_pressed =  old_PORTB ^ new_PORTB;
    if(key_pressed & PORTB_4) {
        LED = PORTB_4;
    } else if(key_pressed & PORTB_5) {
        LED = PORTB_5;
    } else if(key_pressed & PORTB_6) {
        LED = PORTB_6;
    } else if(key_pressed & PORTB_7) {
        LED = PORTB_7;
    } else {
        //junk interrupt
    }   
    delay;
    RBIF=0;
}

void main(void)
{
    /*Port B as a Input */
    TRISB0=0xFF;
    
    /*Port D as a Output */
    TRISD=0;
    LED=0;
    
    /*Storing Original PORTB value*/
    old_PORTB = PORTB;
 
    /* Register PORTB interrupt */
    OPTION_REG |= 0b00000000;
    INTCON |= 0b10011000;
    while(1) {
        LED=0x00;
    }
}
