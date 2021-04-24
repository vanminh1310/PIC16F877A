#include <16f877a.h>
#fuses XT,NOLVP,NOWDT,NOPROTECT
#use delay(clock=4000000)

#define  Wire1 PIN_B6
#define  Wire2 PIN_B7
#define  Up    PIN_A0
#define  Down  PIN_A1
#define  Dir   PIN_A2
#define start PIN_A3
#define stop   PIN_A5

int16 duty_cycle=512;

void main()
{
   setup_adc(ADC_OFF);           // Tat adc 
   setup_adc_ports(NO_ANALOGS);  
 // output_high(Wire1);           
  //output_low (Wire2);            /
   
   /* PWM Configurations */
   setup_timer_2(T2_DIV_BY_1,255,1);   // Set PWM 
   setup_ccp1(CCP_PWM);          /
   set_pwm1_duty(512L);          // 50% (Half Speed)

   while(1)
   {
      while(input(Up) && input(Down) && input(Dir)&& input(start)&&input(stop)); // kiem tra khi nao co nut dc nhan 
      
      if(!input(start)){
        output_high(Wire1);           
  output_low (Wire2);   
      
      }
      
      if(!input(Up))    
      {
         duty_cycle+=64;   //  (+6.25%)
         set_pwm1_duty(duty_cycle); 
      }
      if(!input(Down)) 
      {
         duty_cycle-=64;   
         set_pwm1_duty(duty_cycle); 
      }
      if(!input(Dir))   
      {
         output_toggle(Wire1);  
         output_toggle(Wire2);   
      }      
      delay_ms(500); 
   }
}
