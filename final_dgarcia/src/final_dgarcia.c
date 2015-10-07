#include "final_dgarcia.h"
#include "rti_daniel.h"
#include "led.h"
#include "adc.h"
#include "dac.h"
#include "teclas.h"

int input_adc=0;
int salida_dac=0;
float G=1,b=1;

void Timer_IRQ(void)
{

	b= (float)(  (1+G)*ADC_Value()  );
	input_adc=(int)b;
	//if (input_adc >=1023) {input_adc=1023; salida_dac=1023;}
	DAC_Value(input_adc);

	Led_invierte(LED_G);
	Borra_interrupcion_timer();
}


int main(void)
{
	Puerto_inicia();
	Led_inicia();
    ADC_Init();
    DAC_Init();
    InicializarTeclas();
    timer_interrupcion(100);

    int tecla_numero=0;

while(1){

	tecla_numero=EscanearTeclado();

	switch(tecla_numero){

	case 1:	G+=0.1;Led_alto(LED_3);
		break;
	case 2:	G-=0.1;Led_bajo(LED_3);
		break;
	case 3: G=0;
		break;
	case 4: G=1;
			break;
	default:
		break;

	}

}
return 0;
}

