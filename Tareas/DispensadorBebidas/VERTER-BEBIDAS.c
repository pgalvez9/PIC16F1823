#INCLUDE <16G1823.H>

#USE FAST_IO

#USE DELAY(32 000 000)

#INT_EXT
void interrupcion() {
   /*
      la funci�n que est� inmediatamente abajo de
      INT_EXT ser� lo que se ejecute en una interrupcion
   */
}

int llenaVaso() {

   return(0);
}

int hayVaso() {

   return(0);
}

int main (void) {

/* Se utilizar� para habilitar las interrupciones
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
   ***********************************************
   Lo normal es un L2H (Low to High)
*/
   set_tris_a(1);
   set_tris_c(0);

   for(;;) {
      bit_test(a0);
   }

   return(0);
}
