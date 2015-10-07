#include "teclado_led.h"
#include "led.h"
#include "teclas.h"



int main(void)
{
	int led;
	Puerto_inicia();
	Led_inicia();
	InicializarTeclas();

   while(1) {
	  static int flag=0;
	  int tecla_numero;
	  tecla_numero = EscanearTeclado();
	  switch(tecla_numero) {
	      case 1:
	    	  led = LED_B;
	    	  break;
	  	  case 2:
	  		  led = LED_1;
	  		  break;
	  	  case 3:
	  		  led = LED_2;
	  		  break;
	  	  case 4:
	  		  led = LED_3;
	  		  break;
	  }
	  //asi siempre apago los LEDss luego de pulsar
	  if(led!=flag) {
		  flag = led;
		  Led_bajo(LED_B);
		  Led_bajo(LED_1);
		  Led_bajo(LED_2);
		  Led_bajo(LED_3);
	  }
	  int i=0;
	  for(i=0;i<1000000;i++) {
	     asm("nop");
	  }
	  if(led==LED_B  || led==LED_1 || led==LED_2 || led==LED_3  )
		  Led_invierte(led);
   }

   return 0;


}

