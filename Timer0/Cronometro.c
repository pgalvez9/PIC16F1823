#include <16f1823.h>
#fuses NOWDT, PUT, NOMCLR
#use delay(int=32000000)
int16 ms = 0;
int1 pms = 0;
int16 s = 0;
int1 ps = 0;
int16 s30 = 0;
int1 ps30= 0;
#INT_TIMER0
void timer()
{

   ms++;
   pms = 1;
   if(ms==1000)
   {
      s++;
      ms = 0;
      ps = 1;
   }
   if(s==30)
   {
      ps30=1;
      s = 0;
   }
   SET_TIMER0(225);
}

void main()
{
   output_c(0);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   SETUP_TIMER_0(T0_INTERNAL|T0_DIV_256);
   SET_TIMER0(225);
   while(1)
   {
      if(pms==1)
      {
         output_high(pin_c0);
         delay_us(100);
         output_low(pin_c0);
         pms=0;
      }
      if(ps==1)
      {
         output_high(pin_c1);
         delay_ms(10);
         output_low(pin_c1);
         ps=0;
      }
      if(ps30==1)
      {
         output_high(pin_c2);
         delay_ms(1000);
         output_low(pin_c2);
         ps30=0;
      }
   }
}
