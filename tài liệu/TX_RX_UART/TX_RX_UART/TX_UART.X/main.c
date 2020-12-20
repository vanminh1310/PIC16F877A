/*
 * File:   main.c
 * Author: Computer
 *
 *
 */


#include <pic.h>
#include "UART.h"



void main(void) {
   
    char dato_rx;
    TRISB = TRISC0 = TRISC1 = 0; // chan c0 c1 output
    TRISB0 = 0;
   
    
    UART_init();
    UART_printf("Bai Tap Lon ITS59");
    
    while(1)
    {
        dato_rx = UART_read();
        
       
        
    }
    return;
}
