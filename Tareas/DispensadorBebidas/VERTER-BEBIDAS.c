#INCLUDE <16F1823.h>
#FUSES NOWDT, PUT, NOMCLR

#USE FAST_IO(A)
#USE FAST_IO(C)

#USE DELAY(CLOCK = 32000000)
#BYTE TrisA = 0x08c
#BYTE TrisC = 0x08e
#BYTE PortA = 0x00c
#BYTE PortC = 0x00e

#INT_EXT
void interrupcion() {
   /*
      la funci�n que est� inmediatamente abajo de
      INT_EXT ser� lo que se ejecute en una interrupcion
   */
   
}

void llenaVaso();
void seleccionaVaso();

void main (void) {

/* Se utilizar� para habilitar las interrupciones
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
   ***********************************************
   Lo normal es un L2H (Low to High)
*/
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
   set_tris_a(1);
   set_tris_c(0);
   PortA = 1;
   PortC = 0;

   for(;;) {
      output_bit(Pin_C0, bit_test(PortA,0));
   }
}
