#include <16f877A.h>
#include <def_877A.h>
#fuses NOWDT,HS,PUT,NOPROTECT
#device  *=16 ADC=10          //using 10 bit A/D converter 
#use delay(clock=20000000)              
int16 value; 

void AD_Init()                           //initialize A/D converter 
{ setup_adc_ports(ALL_ANALOG);   //set analog input ports:  A0,A1,A3
  setup_adc(ADC_CLOCK_INTERNAL);         //using internal clock 
  set_adc_channel(0);                    //input Analog at pin A0 
 
  delay_ms(10);                          //sample hold time 
} 

void main() 
{ 
  AD_Init(); //initialize A/D converter
  while(1) 
  { if(adc_done())
    {                   
    value=read_adc(); //value = (0,1023) vi 10bit
    //value=value*124/1023;
    SETUP_CCP2(CCP_PWM);              //set CCP1(RC2) to PWM mode 
    set_PWM2_duty(value);           //duty_cycle = value / ( period+1 )
    SETUP_TIMER_2(T2_DIV_BY_4,124,1); //set the PWM frequency to [(20MHz/4)/1]/125=16.9KHz 
    }
  }
} 

