#include <16F877a.h>
#FUSES NOWDT, HS, PUT, NOPROTECT,
#use DELAY(clock=16000000)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7)
int8 RDATA;
void main()
{
SET_TRIS_D(0x00);
output_d(0);
while(1)
{
if(kbhit()) // H�m kbhit() tr? v? 1 n?u c� k? t? �? nh?n v� 0 n?u kh�ng c� k? t?
{
RDATA=getch(); //nh?n k? t? g?i �?n
OUTPUT_D(RDATA);
}
}
}
