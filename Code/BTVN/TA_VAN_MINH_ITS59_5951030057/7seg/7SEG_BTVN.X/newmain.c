#include<pic.h>
unsigned short mask(unsigned short num) {
    switch (num) {
        case 0: return 0xc0;
        case 1: return 0xf9;
        case 2: return 0xa4;
        case 3: return 0xb0;
        case 4: return 0x99;
        case 5: return 0x92;
        case 6: return 0x82;
        case 7: return 0xf8;
        case 8: return 0x80;
        case 9: return 0x90;
    }
}
unsigned short mask(unsigned short num);
unsigned short digit_no, digit10, digit1, digit, i;

void interrupt() {
    if (digit_no == 0) {
        PORTC = 0; // Turn off both displays
        PORTB = digit1; // Set mask for displaying ones on PORTD
        PORTC = 1; // Turn on display for ones (LSD)
        digit_no = 1;
    } else {
        PORTC = 0; // Turn off both displays
        PORTB = digit10; // Set mask for displaying tens on PORTD
        PORTC = 2; // Turn on display for tens (MSD)
        digit_no = 0;
    }
    TMR0 = 0; // Reset counter TMRO
    INTCON = 0x20; // Bit T0IF=0, T0IE=1
}

void main() {
    OPTION_REG = 0x80; // Set timer TMR0
    TMR0 = 0;
    INTCON = 0xA0; // Disable interrupt PEIE,INTE,RBIE,T0IE
    PORTC = 0; // Turn off both displays
    TRISC = 0; // All port A pins are configured as outputs
    PORTB = 0; // Turn off all display segments
    TRISB = 0; // All port D pins are configured as outputs

    do {
        for (i = 0; i <= 99; i++) { // Count from 0 to 99
            digit = i % 10u;
            digit1 = mask(digit); // Prepare mask for displaying ones
            digit = (char) (i / 10u) % 10u;
            digit10 = mask(digit); // Prepare mask for displaying tens
            Delay_ms(200);
        }
    } while (1); // Endless loop
}