/*
 * File:   main.c
 * Author: vanminh
 *
 *
 */


#include <pic.h>
#include "uart.h"
#include "lcd4.h"



void main(void) {
   
    char rx;
    TRISB = TRISC0 = TRISC1 = 0; // chan c0 c1 output
    TRISB0 = 0;
   
       lcd_init();
    cmd(0x80);
    show("Key : ");
    UART_init();
    
    UART_printf("Bai Tap Lon ITS59\n\r");
    
    while(1)
    {
        rx = UART_read();
         UART_printf(rx);
        cmd(0xc8);
        show(rx);
       
        
    }
    return;
}
