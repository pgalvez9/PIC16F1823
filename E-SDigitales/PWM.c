#include <16F1823.h>
#fuses NOWDT, PUT, NOMCLR
#use delay (int = 32 MHz)

int main(void) {

   SETUP_CCP1(CCP_PWM);
   
   SETUP_TIMER_2(6, 255, 1);     // (modo, periodo, postscaler)
   SET_TIMER2(0);                // Valor de TMR2
   SET_PWM1_DUTY(750);           // Ciclo de trabajo
   
   for(;;) {}
   
   return 0;
}
