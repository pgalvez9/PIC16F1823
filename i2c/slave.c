#include <16f1823.h>
#fuses NOWDT, PUT, NOMCLR //No watch dog timer, power up timer, no master clear
#use delay(int=32MHZ)   
#use RS232(baud=9600,XMIT=pin_c4,RCV=pin_c5)
#use I2C(slave,SDA=pin_c1,SCL=pin_c0,ADDRESS=0x60, FORCE_HW, STREAM=S1,fast)//maestro o esclavo,cuál pin es SDA, , forzar a que sea hw
char a = 'a';
#INT_SSP
void I2Cs()
{
   
   int8 state;
   state = i2c_isr_state(S1);
   printf("entre a int %u",state);
   if (state>=0x80)
   {
   
      printf("entre a state 80 %u",state);
      I2C_WRITE(a);
      delay_ms(100);
      
   }
}

void main()
{
   ENABLE_INTERRUPTS(INT_SSP);
   ENABLE_INTERRUPTS(GLOBAL);
   while(true)
   {
      
   delay_ms(100);
   }
}
