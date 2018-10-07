#include <16F1823.H>
#fuses PUT, NOWDT, NOMCLR

#use delay(int = 32 MHz)
#BYTE TrisA = 0x08c
#BYTE TrisC = 0x08e
#BYTE PortC = 0x00e

int main(void) {
// Se definen los puertos como entradas o salidas
   set_tris_C(0);
   
   for(;;) {
      
   }
   
   return (0);
}
