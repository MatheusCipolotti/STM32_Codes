#include "stm32f030x6.h"

#include "configs.h"
#include "delay.h"

int main(){
	OscInit();
	GPIO();

	while(1){
		if(GPIOB->IDR & GPIO_IDR_1){
		    // PB1 está em nível lógico 1, aciona PB0
			GPIOB->ODR |= GPIO_ODR_0;  			//Seta PB0 em 1
		}
		else{
		// PB1 está em nível lógico 0, desativa PB0
		    GPIOB->ODR &= ~GPIO_ODR_0;  		//Seta PB0 em 0
		}
	}
}
