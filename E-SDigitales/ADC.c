#INCLUDE <16F1823.H>

#FUSES NOWDT, PUT, NOMCLR
#DEVICE ADC = 10
// El ADC funciona por default a 8 bits, con la l�nea superior se define a 10 bits
// Hiperterminal hercules para leer comunicaciones seriales
// P4. Termometro usando LM35 desde -30v a 
// app bluetooth terminal

#USE DELAY (int = 32MHz)
#USE RS232(BAUD = 9600, XMIT = PIN_C4, RCV = PIN_C5)
// I^2 C

int main(void){
   float s = 0;
   float f = 0;
   
   SETUP_ADC(0x60);  // PINx SER� ANALOGICO
   SETUP_ADC_PORTS(0x000100);   // ADC_CLOCK_DIV_64
   SET_ADC_CHANNEL(0x000100); // CAMBIAR DE CANAL

   for(;;) {
      s = READ_ADC();
      delay_us(2);
      f = s*5/1023;
      printf("POT = %03.2f \r", f);
   }
   return (0);
}