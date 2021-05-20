#include <16f877a.h>
#device ADC=8 // ADC 8bit

#fuses XT,NOLVP,NOWDT,NOPROTECT
#use delay(clock=20000000) // chinh lai thach abg 


#define  Wire1 PIN_B6
#define  Wire2 PIN_B7
#define  Up    PIN_A0
#define  Down  PIN_A1
#define  Dir   PIN_A2
#define start PIN_A3
#define stop   PIN_A5
#define led_st PIN_D0
#define led_sp PIN_D1
#define led_up PIN_D2
#define led_dow PIN_D3
#define led_dao PIN_D4

int16 duty_cycle;//
void ngatadc(){
 while(input(Up) && input(Down) && input(Dir)&& input(start)&&input(stop)); // kiem tra khi nao co nut dc nhan 
      
      if(input(start)==0){
         output_high(Wire1);   // chon chieu quay cua dong co         
         output_low (Wire2);  
         output_high(led_st); 
          output_low (led_sp);
      
      }
       if(!input(stop)){
         output_low(Wire1);   // chon chieu quay cua dong co         
         output_low (Wire2); 
          output_high(led_sp); 
           output_low (led_st); 
             output_low (led_up); 
               output_low (led_dow); 
                 output_low (led_dao); 
      
      }
      
      if(!input(Up))    
      {
         duty_cycle=500;  
         set_pwm1_duty(duty_cycle);
          output_high(led_up); 
           output_low (led_dow); 
      }
      if(!input(Down)) 
      {
         duty_cycle=100;   
         set_pwm1_duty(duty_cycle); 
          output_high(led_dow); 
           output_low (led_up); 
      }
      if(!input(Dir))   
      {
         output_toggle(Wire1);  
         output_toggle(Wire2);   
          output_high(led_dao); 
      }      

}
#INT_AD
void intad()
{  //L�m chuong tr�nh n�o d�
ngatadc();

}


void main()
{
   setup_adc(ADC_CLOCK_DIV_2);
  set_adc_channel(0);   //analog input to pin A0
   enable_interrupts(GLOBAL);
     enable_interrupts(INT_AD);
  // setup_adc(ADC_OFF);           // Tat adc 
   
   
  // setup_adc_ports(NO_ANALOGS);
   setup_timer_2(T2_DIV_BY_4, 124,1);  // f=fosc/[4*mode*(period+1)]?
/*
10000 =20000000/[ 4*mode*(period+1)]�
mode(period+1) = 500?
mode bo chia(1,4,16)
period: co gia tri tu 0-255
chon bo chia 4 gia trij 124
 125*4=500 v?ct  duty_cycle = value / [4*( 124+1 )?]
value = 100 ?duty_cycle = 100/ [4*( 124+1 )]=20 %?
value = 400?duty_cycle = 400 /[4*( 124+1 )]= 80%?
value = 500?duty_cycle = 500/ [4*( 124+1 )]= 100%?

 
*/
   setup_ccp1(CCP_PWM);// chon che do pwm 


   set_pwm1_duty(300);          // 20% (Half Speed)
   set_tris_d(0x00);
    output_d(0x00);
    set_tris_a(0xff);

   while(1)
   {
  
     ngatadc();
    
   }
}