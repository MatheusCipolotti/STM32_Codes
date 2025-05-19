#include "stm32f030x6.h"

#include "configs.h"
#include "defines.h"

void OscInit(void){
	//Ativa o HSE (Cristal Externo de 8 MHz)
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY)); 						//Espera até o HSE ficar pronto

	//Seleciona o HSE como o clock do sistema
	RCC->CFGR |= RCC_CFGR_SW_HSE;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE); 	//Espera até o HSE ser selecionado
}

void GPIO_Init(void){
	//Habilita o clock para o GPIOB (Bit 18 do RCC_AHBENR)
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	//===================================PB0========================================
	//Configura o pino PB0 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER0;  						//Limpa bits 0 e 1 para PB0
	GPIOB->MODER |= GPIO_MODER_MODER0_0;   						//Seta bit 0 para modo saída

	//Configura a saida como Push-Pull
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_0;

	//Define o valor de PB0 para alta velocidade
	GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEEDR0_0;
	GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEEDR0_1 | GPIO_OSPEEDR_OSPEEDR0_0);

	//===================================PB3========================================
	//Configura o pino PB3 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER3;  						//Limpa bits 0 e 1 para PB3
	GPIOB->MODER |= GPIO_MODER_MODER3_0;   						//Seta bit 0 para modo saída

	//Configura a saida como Push-Pull
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_3;

	//Define o valor de PB3 para alta velocidade
	GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEEDR3_0;
	GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEEDR3_1 | GPIO_OSPEEDR_OSPEEDR3_0);

	//===================================PB4========================================
	//Configura o pino PB4 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER4;  						//Limpa bits 0 e 1 para PB4
	GPIOB->MODER |= GPIO_MODER_MODER4_0;   						//Seta bit 0 para modo saída

	//Configura a saida como Push-Pull
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_4;

	//Define o valor de PB4 para alta velocidade
	GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEEDR4_0;
	GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEEDR4_1 | GPIO_OSPEEDR_OSPEEDR4_0);
}

void TIM3_Init(void){
	// Habilita o clock do Timer 3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	// Configuração do Timer 3
	TIM3->PSC = 7;  												// Prescaler: 8MHz/8 = 1MHz
	TIM3->ARR = 999;   												// Auto-reload: overflow a cada 1000 contagens (1kHz = 1ms)

	// Configuração do modo de interrupção por estouro
	TIM3->DIER |= TIM_DIER_UIE;  									// Habilita a interrupção de estouro do timer

	//Habilita o Timer 3
	TIM3->CR1 |= TIM_CR1_CEN;

	NVIC_EnableIRQ(TIM3_IRQn);      								// Habilita a interrupção do TIM3 no NVIC
	NVIC_SetPriority(TIM3_IRQn, 1); 								// Define a prioridade (um valor entre 0 e 3, onde 0 é a mais alta)
}
