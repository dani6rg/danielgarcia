#include "dac_Analogico.h"
#include "led.h"
#include "teclas.h"
#include "rti_daniel.h"
#include "dac.h"
#define max_value (0x3FF * 0xFF)


int direccion;
int main(void)
{
   	Puerto_inicia();
	Led_inicia();
	InicializarTeclas();
    DAC_Init();
    timer_interrupcion(1);

   while(1) {
   }
   return 0;
}

void Timer_IRQ(void) {
	int tecla_numero;
	static int old_tecla = -1;
	static int periodo = 100;
	static int high_value = max_value * 300 / 330;
	static int value;
	int step = high_value / periodo;
	DAC_Value(value>>8);
	tecla_numero = EscanearTeclado();


	if(tecla_numero!=old_tecla) {
		switch(tecla_numero) {
			case 1: periodo+=10;         break;
			case 2: periodo-=10;         break;
			case 3: high_value+=10*0xff; break;
			case 4: high_value-=10*0xff; break;
		}
		old_tecla=tecla_numero;
	}


	value +=step;
	if(value>high_value) {
		value=0;
		Led_invierte(LED_B);
	}

	Borra_interrupcion_timer();
}

