#include <16f1823.h>
#fuses NOWDT, PUT, NOMCLR
#use delay(int=32000000)
int16 i = 0;
#INT_TIMER0
void timer()
{
   i++;
   if(i==1000)
   {
   
   output_toggle(pin_c1);
   i = 0;
   }
   SET_TIMER0(225);
}

void main()
{
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   SETUP_TIMER_0(T0_INTERNAL|T0_DIV_256);
   SET_TIMER0(225);
   while(1)
   {
      output_toggle(pin_c0);
      delay_ms(1);
   }
}
