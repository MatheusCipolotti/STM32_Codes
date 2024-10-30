#include "stm32f030x6.h"
#include "configs.h"

void OscInit(void){
	//Ativa o HSE (Cristal Externo de 8 MHz)
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY)); 						//Espera até o HSE ficar pronto

	//Seleciona o HSE como o clock do sistema
	RCC->CFGR |= RCC_CFGR_SW_HSE;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE); 	//Espera até o HSE ser selecionado
}

void GPIO(void){
	//Habilita o clock para o GPIOB
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

//===================================PB0========================================
	//Configura PB0 como saída alternativa para TIM1_CH1 (AF2)
	GPIOB->MODER &= ~(GPIO_MODER_MODER0);
	GPIOB->MODER |= (GPIO_MODER_MODER0_1); 						//PB0 em modo função alternativa
	GPIOB->AFR[0] |= (0x02 << GPIO_AFRL_AFRL0_Pos); 			//AF2 para PB0

}
