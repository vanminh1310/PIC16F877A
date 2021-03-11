/*
 * File:   INT_RB0.c
 * Author: Dell
 * My blog http://xcvn.blogspot.com
 * Created on November 24, 2015, 8:31 PM
 */

#define _XTAL_FREQ 8000000
#include <xc.h>
const unsigned char Code7Seg[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned int count=0;
void interrupt ISR(void);
void main (void)
{
    TRISD = 0x00;
    PORTD = 0X00;
    
    TRISB0 = 1;
    PORTB = 0X00;
    INTCONbits.GIE = 1;
    INTCONbits.INTE = 1;
    OPTION_REGbits.INTEDG = 1;
    while(1)
    {
        PORTD = Code7Seg[count];
        if(count==10)
        {
            count=0;
        }
    } 
}
void interrupt ISR(void)
{
        if(INTF==1)
        {
            {
                count++;
                INTF=0;
            }
        } 
}