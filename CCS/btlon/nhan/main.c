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
if(kbhit()) // Hàm kbhit() tr? v? 1 n?u có k? t? ð? nh?n và 0 n?u không có k? t?
{
RDATA=getch(); //nh?n k? t? g?i ð?n
OUTPUT_D(RDATA);
}
}
}
