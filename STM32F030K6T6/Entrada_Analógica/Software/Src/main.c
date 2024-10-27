#include "stm32f030x6.h"

#include "defines.h"
#include "delay.h"
#include "configs.h"
#include "ADC.h"

unsigned int adc_var = 0x0000;

int main(){
	OscInit();
	GPIO();
	ADC_Init();

	while(1){
		adc_var = ADC_Read();

		if(adc_var <= 100){
			DESHAB_PB0;
			DESHAB_PB1;
			DESHAB_PB3;
			DESHAB_PB4;
		}
		else if(adc_var <= 1000){
			HAB_PB0;
			DESHAB_PB1;
			DESHAB_PB3;
			DESHAB_PB4;
		}
		else if(adc_var <= 2000){
			HAB_PB0;
			HAB_PB1;
			DESHAB_PB3;
			DESHAB_PB4;
		}
		else if(adc_var <= 3000){
			HAB_PB0;
			HAB_PB1;
			HAB_PB3;
			DESHAB_PB4;
		}
		else if(adc_var <= 4000){
			HAB_PB0;
			HAB_PB1;
			HAB_PB3;
			HAB_PB4;
		}
		else{
			DESHAB_PB0;
			DESHAB_PB1;
			DESHAB_PB3;
			DESHAB_PB4;
		}
	}
}
