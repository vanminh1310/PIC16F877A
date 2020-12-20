/*
 * File:   main.c
 * Author: Computer
 *
 * Created on 4 de marzo de 2018, 02:47 PM
 */

#define _XTAL_FREQ 20000000
#include <xc.h>
#include "UART.h"



void main(void) {
   
    char dato_rx;
    TRISBbits.TRISB0 = 0;
    PORTBbits.RB0 = 0;
    
    UART_init();
    UART_printf("Encender led con 1 y apagar led con 0");
    
    while(1)
    {
        dato_rx = UART_read();
        
        if(dato_rx == '1'){
            UART_printf("led encendido ");
            PORTBbits.RB0 = 1;
        }
        
        if(dato_rx == '0'){
            UART_printf("led apagado ");
            PORTBbits.RB0 = 0;
        }
        
    }
    return;
}
