#include <16f1823.h>
#fuses PUT, NOWDT

#use delay(int = 32 MHz)
#BYTE TrisA = 0x08c
#BYTE TrisC = 0x08e
#BYTE PortA = 0x00c
#BYTE PortC = 0x00e
int k = 0;

int main(void) {
// Se definen los puertos como salidas
   TrisA = 0b000000;
   TrisC = 0b000000;
   
   PortA = 0b000000;
   PortC = 0b000000;
   
   // >>= 1
   
   for(;;) {
      for(k=32; k>0; k/=2) {
         if(k!=8) {
            PortA = k;
            delay_ms(500);
         }
      }
      PortA = 0;
      
      for(k=32; k>0; k/=2) {
      PortC = k;
      delay_ms(500);
      }
      PortC = 0;
      
      for(k=2; k<34; k*=2) {
      PortC = k;
      delay_ms(500);
      }
      PortC = 0;
      
      for(k=1; k<32; k*=2) {
         if(k!=8) {
            PortA = k;
            delay_ms(500);
         }
      }
      PortA = 0;
   }
   
   return (0);
}
