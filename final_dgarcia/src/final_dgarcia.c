#include "final_dgarcia.h"       /* <= own header */
#include "rti_daniel.h"
#include "leds_daniel.h"
//#include "tecla_daniel.h"

#include "adc.h"
#include "dac.h"
#include "teclas.h"
/*==================[macros and definitions]=================================*/
int input_adc=0,c=0;
float b=1;
int salida_dac=0;
float G=1;
/*==================[internal data declaration]==============================*/
void ISR_RIT(void)
{
	led_verde_invierte();
	Chip_RIT_ClearInt(LPC_RITIMER);
c=ADC_Value();
	b= (float)G*c;
	input_adc=(int)b;
	//if (input_adc >=1023) {input_adc=1023; salida_dac=1023;}
	DAC_Value(input_adc);
}

int main(void)
{
int tecla_numero=0;
//char i=0;
ADC_Init();
DAC_Init();
InicializarTeclas();

inicia_led();
timer_interrupcion(100);

while(1){

//tecla_numero= kbhit();
	tecla_numero=EscanearTeclado();

//if(tecla_numero>=1)

	switch(tecla_numero ){

	case 1:	G+=0.1;led_on();
		break;
	case 2:	G-=0.1;led_off();
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


/*==================[end of file]============================================*/
