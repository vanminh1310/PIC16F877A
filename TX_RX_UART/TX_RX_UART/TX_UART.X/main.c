/*
 * File:   main.c
 * Author: Computer
 *
 * Created on 4 de marzo de 2018, 02:47 PM
 */

#define _XTAL_FREQ 20000000
#include <xc.h>
#include "UART.h"

#include "lcd4.h"

void main(void) {
   
    char dato_rx;
    TRISBbits.TRISB0 = 0;
    TRISB0=0;
     TRISB = TRISC0 = TRISC1 = 0; // chan c0 c1 output
    UART_init();
     lcd_init();
    cmd(0x80);
    show("Key : ");
    UART_printf("BTL");
    
    while(1)
    {
        dato_rx = UART_read();
        
         cmd(0xc8);
        show(dato_rx);
        if(dato_rx == 'A'){
            UART_printf("led encendido ");
             show(dato_rx);
            PORTBbits.RB0 = 1;
        }
        
        if(dato_rx == '0'){
            UART_printf("led apagado ");
            PORTBbits.RB0 = 0;
        }
        
    }
    return;
}
