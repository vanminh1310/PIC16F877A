#include<16f877a.h>
//#include<def_877A.h>
#fuses NOWDT,HS,PUT,NOPROTECT
#use delay(clock=20000000)
#BIT IF0=0x0B.2  // bit so 2 cua thanh ghi INTCON=0Bh la co tran timer0
void tre1s();
void main()
{setup_timer_0(RTCC_INTERNAL|RTCC_DIV_4);// hoat dong su dung xung noi v�  
                                       //  dung bo chia truoc 1:2
output_d(0xff);
while (1)
{
  output_d(0x00);
   tre1s();
  output_d(0xff);
   tre1s();
}
}
void tre1s()
{ int16 i;
   for(i=0;i<10000;i++) // =100*10^-6*100000
   {set_timer0(6);   //  T_dinhthi =delay= 2*(256 - 6)*0.2us = 100us
//INitTIMER0=6;prescaler=2(do RTCC_div_2)

  while(IF0==0);
    IF0=0;
   }
}
