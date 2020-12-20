#include<pic.h>
#include "lcd8.h"
#include "uart.h"


__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF);

#define delay for(z=0;z<=50000;z++)

unsigned int z;

void interrupt ser();

void main()
{
TRISB=0;
TRISC0=TRISC1=TRISC2 = 0;
 INTCON|=0b11000000;
 PIE1=0b00100000;
 lcd_init();
 serial_init();
 tx_string("Bai tap lon its 59");
 while(1) {
  cmd(0x01);
 }
}

void interrupt ser()
{
 unsigned char a = RCREG;
 tx(a);
 cmd(0x80);
 show("Serial interrupt");
 cmd(0xc0);
 show("  Key : ");
 cmd(0xc8);
 dat(a);
 delay;delay;
 TXIF=RCIF=0;
}