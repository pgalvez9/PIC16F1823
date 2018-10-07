/*
   Código fuente para Esclavo de I2C
*/
#include <16F1823.h>

#fuses NOWDT, NOMCLR, PUT
#use delay (int = 32 MHz)
#use RS232(baud = 9600, XMIT = pin_c4, RCV = pin_c5)
#use I2C(slave, SDA = pin_c1, SCL = pin_c0, ADDRESS = 0x50, FORCE_HW, STREAM = Slave1) // Maestro-esclavo
#INT_SSP
void I2C() {
   int state = I2C_ISR_STATE(Slave1);
   
   if(state >= 0x80) {
      I2C_WRITE(Slave1,'A');
   }
}


int main(void) {
   ENABLE_INTERRUPTS(INT_SSP);
   ENABLE_INTERRUPTS(GLOBAL);
   
   while(true) {}

   return 0;
}
