#include <pic.h>
#include "uart.h"
#include "lcd4.h"
#define Thachanh 11059200
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF);

void setup() {
    TRISB = TRISC0 = TRISC1 = 0; // chan c0 c1 output
    
}
unsigned char rx()

{

while(!RCIF);

RCIF=0;

return RCREG;

}
char UART_read(void)
{
    if (PIR1bits.RCIF == 1)
        return RCREG;
    else
        return 0;
}

void main(){
    setup();
    uart_init(9600);
    uart_write("Bai Tap Lon Nhom 2 ITS59 \n\r");
    uart_write("Nhap ki tu tu ban phim \n\r");
    lcd_init();
    
    show("Key: ");
    
    while(1){
    
       char test = UART_read();
        uart_write(test);
        
       
        
    
    }
}