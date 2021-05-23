#include <16f877a.h>
#device ADC=8 // ADC 8bit
#fuses XT,NOLVP,NOWDT,NOPROTECT
#use delay(clock=20000000) // chinh lai thach abg 
#define  Wire1 PIN_B6
#define  Wire2 PIN_B7
#define  thuan    PIN_A0
#define  nghich  PIN_A1
#define  stop   PIN_A2
#define led_nghich PIN_D0
#define led_thuan PIN_D1
#define led_stop PIN_D2
void ngatadc(){
 while(input(thuan)&&input(nghich)&&input(stop)); // kiem tra khi nao co nut dc nhan 
 
       if(!input(stop)){
         output_low(Wire1);   // chon chieu quay cua dong co         
         output_low (Wire2); 
         output_high(led_stop);
         output_low(led_nghich);
         output_low(led_thuan);
      }
      if(!input(thuan))    
      {
          output_high(Wire1);
          output_low(Wire2);
          output_high(led_thuan);
         output_low(led_nghich);
         output_low(led_stop);
      
      }
      if(!input(nghich)) 
      {
         output_high(Wire2);
          output_low(Wire1);
          output_high(led_nghich);
         output_low(led_stop);
         output_low(led_thuan);
      
      }
      

}
#INT_AD
void intad()
{  //L�m chuong tr?nh n�o d�
ngatadc();

}


void main()
{
   setup_adc(ADC_CLOCK_DIV_2);
  set_adc_channel(0);   //analog input to pin A0
   enable_interrupts(GLOBAL);
     enable_interrupts(INT_AD);
   set_tris_d(0x00);
    output_d(0x00);
    set_tris_a(0xff);
    output_high(Wire1);
    output_low(Wire2);

   while(1)
   {
  
     ngatadc();
    
   }
}
