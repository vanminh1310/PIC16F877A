
/*
 * File:   UART.h
 * Author: Carlos Quispe
 * Contacto carlos.quispe.359@gmail.com
 */

void UART_init()
{
    TRISC7 = 1;   //RX input
    TRISC6 = 0;   //TX output 
    
    SYNC = 0;     //UART
    TX9 = 0;      //8 BITS
    BRGH = 1;     //ALTA VELOCIDAD
    SPBRG = 1;            //9600 a 20MHZ
    SPEN = 1;     //UART on    
    TXEN = 1;    //TX on
    CREN = 1;     //RX on
}

char UART_read(void)
{
    if (RCIF == 1)
        return RCREG;
    else
        return 0;
}

void UART_write(char data)
{
    TXREG = data;
     while(TRMT == 0);
}

void UART_printf(unsigned char *s)
{
    while(*s !=0x00){
        UART_write(*s);
        s++;
    }
}

