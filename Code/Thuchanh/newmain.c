#include<pic.h>
// CONFIG
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & CP_OFF & BOREN_ON & LVP_OFF & CPD_OFF & WRT_OFF & DEBUG_OFF); // 

#define _XTAL_FREQ 20000000


//******Initialize SART********//
void USART_Init()
{
   //Set the pins of RX and TX//
    TRISC6=1;
    TRISC7=1;
    
  //Set the baud rate using//
    BRGH=1;      //high speed baud rate with Bluetooth
    SPBRG  =129;
    
    //Turn on Serial Port//
    SYNC=0;
    SPEN=1;
    
    //Set 8-bit reception and transmission
    RX9=0;
    TX9=0;

   //Enable transmission and reception//
    TXEN=1; 
    CREN=1; 
    
    //Enable global and ph. interrupts//
    GIE = 1;
    PEIE= 1;
  
    //Enable interrupts for Tx. and Rx.//
    RCIE=1;
    TXIE=1;
}
//___________BT initialized_____________//

//Function to load the buffer with one char.//
void USART_char(char byte)  
{
    TXREG = byte;
    while(!TXIF);  
    while(!TRMT);
}
//End of function//

//Function to Load buffer with string//
void USART_string(char* string)
{
    while(*string)
    USART_char(*string++);
}
//End of function//

//Function to send data from RX. buffer//
void send_data()
{
  TXREG = 13;  
  __delay_ms(500);
}
//End of function//

//Function to get a char from buffer of Bluetooth//
char USART_get_char(void)   
{
    if(OERR) // check for over run error 
    {
        CREN = 0;
        CREN = 1; //Reset CREN
    }
    
    if(RCIF==1) //if the user has sent a char return the char (ASCII value)
    {
    while(!RCIF);  
    return RCREG;
    }
    else //if user has sent no message return 0
        return 0;
}
//End of function/

void main(void)
{
    //Scope variable declarations//
    int get_value;
    //End of variable declaration//
   
    //I/O Declarations//
    TRISD4=0;
    //End of I/O declaration//
   
   USART_Init(); //lets get our bluetooth ready for action
    
   //Show some introductory message once on power up//
   USART_string("Bluetooth iS Ready");
   send_data();
   USART_string("Press 1 to turn ON LED");
   send_data();
   USART_string("Press 0 to turn OFF LED");
   send_data();
   //End of message//
    
    while(1) //The infinite lop
    {   
        
    get_value = USART_get_char(); //Read the char. received via BT
    
    //If we receive a '0'//
        if (get_value=='0')
          {
             RD4=0; 
             USART_string("LED turned OFF");
             send_data();
          }
       
    //If we receive a '1'//   
        if (get_value=='1')
          {
             RD4=1;
             USART_string("LED turned ON");
             send_data();
          }      
    }
}