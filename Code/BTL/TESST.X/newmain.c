#include<htc.h>

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF);

void ser_int();

void tx(unsigned char);

unsigned char rx();

void txstr(unsigned char *);

void main()
 {

    TRISC6 = 0; //Output (TX)
    TRISC7 = 1; //Input (RX)

    ser_int();

    tx("(EmbeTronicX): Enter the letters in keyboard\n\r\r");
    tx("(Binh NGO test USART): Nhap ky tu tu ban phim may tinh:\n\r\r");
    while (1) {
        tx(rx());

    }

}

void ser_int()
 {

    TXSTA = 0x20; //BRGH=0, TXEN = 1, Asynchronous Mode, 8-bit mode RCSTA=0b10010000; //Serial Port enabled,8-bit reception

    SPBRG = 17; //9600 baudrate for 11.0592Mhz

    TXIF = RCIF = 0;

}

void tx(unsigned char a)
 {

    TXREG = a;

    while (!TXIF);

    TXIF = 0;

}

unsigned char rx()
 {

    while (!RCIF);

    RCIF = 0;

    return RCREG;

}

void txstr(unsigned char *s)
 {

    while (*s) {

        tx(*s++);

    }

}
