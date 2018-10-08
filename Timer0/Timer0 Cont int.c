#include <16f1823.h>
#fuses NOWDT, PUT, NOMCLR
#use delay(int=32000000)
int16 i = 0;
#INT_TIMER0
void timer()
{

   output_toggle(pin_c2);
   SET_TIMER0(255);

}

void main()
{
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   SETUP_TIMER_0(T0_EXT_L_TO_H|T0_DIV_1);
   SET_TIMER0(255);
   while(1)
   {
      output_toggle(pin_c0);
      delay_ms(1);
   }
}
