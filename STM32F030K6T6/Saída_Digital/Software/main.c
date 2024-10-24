#include "stm32f030x6.h"
#include "delay.h"
#include "configs.h"

int main(){

	OscInit();

	//Habilita o clock para o GPIOB (Bit 18 do RCC_AHBENR)
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	//Configura o pino PB0 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER0;  					//Limpar bits 0 e 1 para PB0
	GPIOB->MODER |= GPIO_MODER_MODER0_0;   					//Setar bit 0 para modo saída

	while(1){
		//Alterna o estado do PB0 (ON/OFF)
		GPIOB->ODR ^= GPIO_ODR_0;  							//Alterna o bit 0 (PB0)
		Delay_ms(500);
	}
}

