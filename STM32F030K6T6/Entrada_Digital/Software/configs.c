#include "stm32f030x6.h"
#include "configs.h"

void OscInit(void){
	//Ativa o HSE (Cristal Externo de 8 MHz)
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY)); 						//Espera até o HSE ficar pronto

	//Seleciona o HSE como o clock do sistema
	RCC->CFGR |= RCC_CFGR_SW_HSE;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE); 			//Espera até o HSE ser selecionado
}

void GPIO(void){
//===================================PB0========================================
	//Habilita o clock para o GPIOB (Bit 18 do RCC_AHBENR)
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	//Configura o pino PB0 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER0;  						//Limpa bits 0 e 1 para PB0
	GPIOB->MODER |= GPIO_MODER_MODER0_0;   						//Seta bit 0 para modo saída

	//Configura a saida como Push-Pull
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_0;

	//Define o valor de PB0 para alta velocidade
	GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEEDR0_0;
	GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEEDR0_1 | GPIO_OSPEEDR_OSPEEDR0_0);

//===================================PB1========================================
	GPIOB->MODER &= ~(GPIO_MODER_MODER1);    					//Limpa para garantir que está como entrada
	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR1);    					//Desabilita pull-up/pull-down
}
