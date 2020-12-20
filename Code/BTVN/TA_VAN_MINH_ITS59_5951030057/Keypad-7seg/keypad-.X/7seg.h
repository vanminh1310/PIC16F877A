/* 
 * File:   7seg.h
 * Author: tamin
 *
 * Created on November 28, 2020, 9:25 AM
 */


unsigned short i, j, num, dk; // Khai bao bien
// khai bao thu ham led 7 doan

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