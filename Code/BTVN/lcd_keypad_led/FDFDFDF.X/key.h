/* 
 * File:   key.h
 * Author: taminh
 *
 * Created on November 24, 2020, 2:48 PM
 */

#ifndef KEY_H
#define	KEY_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* KEY_H */
#define R1 RB0
#define R2 RB1
#define R3 RB2
#define R4 RB3
#define C1 RB4
#define C2 RB5
#define C3 RB6
#define C4 RB7
#define delay for(int i; i<10000; i++)
unsigned char key();
void keyinit();
unsigned char keypad[4][4] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'C', '0', '=', '+'}
};
unsigned char rowloc, colloc;
void keyinit() {
    TRISB = 0XF0;
    OPTION_REG &= 0X7F; //ENABLE PULL UP
}

unsigned char key() {
    RC5 = 0;
    PORTB = 0X00;
    while (C1 && C2 && C3 && C4);
    while (!C1 || !C2 || !C3 || !C4) {
        R1 = 0;
        R2 = R3 = R4 = 1;
        if (!C1 || !C2 || !C3 || !C4) {
            rowloc = 0;
            break;
        }
        R2 = 0;
        R1 = 1;
        if (!C1 || !C2 || !C3 || !C4) {
            rowloc = 1;
            break;
        }
        R3 = 0;
        R2 = 1;
        if (!C1 || !C2 || !C3 || !C4) {
            rowloc = 2;
            break;
        }
        R4 = 0;
        R3 = 1;
        if (!C1 || !C2 || !C3 || !C4) {
            rowloc = 3;
            break;
        }
    }
    if (C1 == 0 && C2 != 0 && C3 != 0 && C4 != 0) {
        colloc = 0;
        RC5 = 0x00;
        delay;
        RC5 = 0xff;
    } else if (C1 != 0 && C2 == 0 && C3 != 0 && C4 != 0) {
        colloc = 1;
        RC5 = 0x00;
        delay;
        RC5 = 0xff;
    } else if (C1 != 0 && C2 != 0 && C3 == 0 && C4 != 0) {
        colloc = 2;
        RC5 = 0x00;
        delay;
        RC5 = 0xff;
    } else if (C1 != 0 && C2 != 0 && C3 != 0 && C4 == 0) {
        colloc = 3;
        RC5 = 0x00;
        delay;
        RC5 = 0xff;
    }
    while (C1 == 0 || C2 == 0 || C3 == 0 || C4 == 0);
    return (keypad[rowloc][colloc]);
}

