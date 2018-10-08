#include <16f1823.h>
#fuses NOMCLR INTRC_IO PLL_SW
#use delay(int = 32Mhz)
#byte trisc = 0x08e
#byte portc = 0x00e
void main() {
  //setup_oscillator(OSC_8MHZ | OSC_PLL_ON);            // Set internal oscillator to 8MHz with PLL enabled (32MHz)
  //setup_adc(ADC_CLOCK_DIV_32);                        // Set ADC conversion time to 32Tosc
  //setup_adc_ports(sAN1);                              // Configure AN1 pin as analog
  //set_adc_channel(1);                                 // Select channel AN1
  setup_dac(DAC_VSS_VDD| DAC_OUTPUT);               // Negative source is VSS and positive source is VDD and output enabled
  int i = 0;
  while(TRUE){
  if(i<31)
  {
    dac_write(i);                                     // Write DAC value according to i
    delay_ms(10);
    i++;
  }
  else
  {
   i=0;
  }
  }
}

   

