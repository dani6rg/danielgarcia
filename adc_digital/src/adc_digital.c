#include "adc_digital.h"
#include "led.h"
#include "teclas.h"
#include "rti_daniel.h"
#include "adc.h"
#define max_value (0x3FF * 0xFF)


int direccion;
int main(void)
{
	Puerto_inicia();
	Led_inicia();
	InicializarTeclas();
	//timer_interrupcion(1);

   int value;
   while(1) {
	   value = ADC_Value();
	   if(value>1020) Led_alto(LED_2);
	   else           Led_bajo(LED_2);
	   if(value<50)   Led_alto(LED_3);
	   else 		  Led_bajo(LED_3);
   }
   return 0;
}

void Timer_IRQ(void) {
/*	int value;

	int step = high_value / periodo;
	DAC_Value(value>>8);
	tecla = EscanearTeclado();
	if(tecla!=old_tecla) {
		switch(tecla) {
			case 1: periodo+=10; 			break;
			case 2: periodo-=10; 			break;
			case 3: high_value+=10*0xff; 	break;
			case 4: high_value-=10*0xff; 	break;
		}
		old_tecla=tecla;
	}
	value +=step;
	if(value>high_value) {
		value=0;
		Led_invierte(LED_1);
	}

	Borra_interrupcion_timer();;*/
}


