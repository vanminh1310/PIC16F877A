
#include <16F877a.h>
#device *= 16 ADC = 10
#use delay(clock = 20000000) // khai bao thach anh(20Mhz)
#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use i2c(Master, sda = PIN_C4, scl = PIN_C3) // khai bao i2c 
#use rs232(baud = 9600, parity = N, xmit = PIN_C6, rcv = PIN_C7, bits = 8) // khai bao uart(rs232)
const char mang[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90}; // khai bao mang Anot chung 

#include "ds1307.c" // module ds1307
#include "74hc595.c" // ic74hc595

#define Slave_add 0x68
#define Read 1
#define Write 0

// khai bao chan cho 7seg
#define digit1 PIN_b1
#define digit2 PIN_b2
#define digit3 PIN_b3
#define digit4 PIN_b4
#define digit5 PIN_b5
#define digit6 PIN_b6

void send(int8 a);
// khai bao bien
int8 sec, min, hrs, day, month, yr, dow;
unsigned char dsec = 0; //bien phuc vu update time

unsigned int a, b, c, d, e, f, a1, b1, c1, d1, e1, f1;
//Timer1  Truyen len cong RS232 va lay cap nhat thoi gian 
#int_TIMER1
void EXT_isr(void) //moi 1s truyen len may tinh 1 lan
{
    Set_timer1(0xBDB);
    ds1307_get_date(day, month, yr, dow);
    ds1307_get_time(hrs, min, sec);
    send(hrs);
    putc(45);
    send(min);
    putc(45);
    send(sec);
    putc(10);
    // gan gia tri thoi gian
    a = hrs / 10;
    b = hrs % 10;
    c = min / 10;
    d = min % 10;
    e = sec / 10;
    f = sec % 10;
    // gan gia tri ngay thang nam 
    a1 = day / 10;
    b1 = day % 10;
    c1 = month / 10;
    d1 = month % 10;
    e1 = yr / 10;
    f1 = yr % 10;
    // ghi du lieu 74hc595 voi du lieu ngay than nam 
    ghi_byte(mang[f1]);
    ghi_byte(mang[e1]);
    ghi_byte(mang[d1]);
    ghi_byte(mang[c1]);
    ghi_byte(mang[b1]);
    ghi_byte(mang[a1]);

    return;
}

void main()
{
    //khai bao goi ham 
    set_tris_c(0x00);
    SET_TRIS_d(0X00);
    SET_TRIS_b(0b00000001);
    OUTPUT_C(0X00);
    khoitao();
    enable_interrupts(INT_EXT);               //cho phep ngat RB0
    ext_int_edge(0, H_TO_L);                  //dat suon ngat
    enable_interrupts(GLOBAL);                //cho phep ngat toan cuc
    ds1307_init();                            // khoi tao DS1307, tao xung 1Hz o chan 7 DS1307.
    setup_timer_1(T1_INTERNAL | T1_DIV_BY_8); //104 ms overflow flow
    enable_interrupts(INT_TIMER1);

    while (true)
    {
        //quet led hien thi thoi gian 
        OUTPUT_D(mang[a]);
        output_high(digit1);
        Delay_us(100);
        output_low(digit1);

        OUTPUT_D(mang[b]);
        output_high(digit2);
        Delay_us(100);
        output_low(digit2);

        OUTPUT_D(mang[c]);
        output_high(digit3);
        Delay_us(100);
        output_low(digit3);

        OUTPUT_D(mang[d]);
        output_high(digit4);
        Delay_us(100);
        output_low(digit4);

        OUTPUT_D(mang[e]);
        output_high(digit5);
        Delay_us(100);
        output_low(digit5);

        OUTPUT_D(mang[f]);
        output_high(digit6);
        Delay_us(100);
        output_low(digit6);
    }
}

// ham send 
void send(int8 a)
{
    if (a < 10)
    {
        putc(a + 48);
    }
    if (a > 9 && a < 100)
    {
        unsigned char c = a / 10;
        unsigned char d = a % 10;
        putc(c + 48);
        putc(d + 48);
    }
    if (a > 99)
    {
        unsigned char t = a / 100;
        unsigned char c = a / 10 - 10 * t;
        unsigned char d = a % 10;
        putc(t + 48);
        putc(c + 48);
        putc(d + 48);
    }
}
