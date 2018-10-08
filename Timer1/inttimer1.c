#include <16f1823.h>
#fuses NOWDT, PUT, NOMCLR
#use delay(int=32000000)
#INT_TIMER1
void timer()
{
  
   output_toggle(pin_c0);
   SET_TIMER1(65534);
}

void main()
{
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   SETUP_TIMER_1(T1_INTERNAL|0x30);
   SET_TIMER0(65534);
   while(1)
   {
   }
}
