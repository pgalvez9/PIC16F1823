#INCLUDE <16F1823.H>

#FUSES NOWDT, PUT, NOMCLR
#USE DELAY (int = 32MHz)

#INT_TIMER1
void timer1() {
   output_toggle(pin_c0);
   SET_TIMER1(32768); //0 - 65536
}
// Esta función escrita justo debajo de #FUSES se usará para la interrupción

/*
   Hastag INTERRUPCION
   type funcionAEjecutarCuandoInterrupcion() {
   }
*/

int main(void){
   enable_interrupts(0x309101);  // Habilita un Timer específico
   enable_interrupts(global);    // Habilita el vector de interrupciones
   
   SETUP_TIMER_1(0x05);    // INT (0x05) TEMPORIZADOR - EXT CONTADOR
   SETUP_TIMER_1(0x05|0x30);  // Cambia valores de la fórmula de tiempo
   SET_TIMER1(32768);                   // Cambia TMR1 dentro de la fórmula de tiempo
   
   for(;;){}

   return (0);
}
