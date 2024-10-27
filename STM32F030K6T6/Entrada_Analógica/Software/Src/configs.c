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
	//Configura o pino PB0 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER0;  						//Limpa bits 0 e 1 para PB0
	GPIOB->MODER |= GPIO_MODER_MODER0_0;   						//Seta bit 0 para modo saída

	//Configura a saida como Push-Pull
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_0;

	//Define o valor de PB0 para alta velocidade
	GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEEDR0_0;
	GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEEDR0_1 | GPIO_OSPEEDR_OSPEEDR0_0);


//===================================PB1========================================
	//Configura o pino PB0 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER1;  						//Limpa bits 0 e 1 para PB0
	GPIOB->MODER |= GPIO_MODER_MODER1_0;   						//Seta bit 0 para modo saída

	//Configura a saida como Push-Pull
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_1;

	//Define o valor de PB0 para alta velocidade
	GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEEDR1_0;
	GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEEDR1_1 | GPIO_OSPEEDR_OSPEEDR1_0);

//===================================PB3========================================
	//Configura o pino PB0 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER3;  						//Limpa bits 0 e 1 para PB0
	GPIOB->MODER |= GPIO_MODER_MODER3_0;   						//Seta bit 0 para modo saída

	//Configura a saida como Push-Pull
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_3;

	//Define o valor de PB0 para alta velocidade
	GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEEDR3_0;
	GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEEDR3_1 | GPIO_OSPEEDR_OSPEEDR3_0);

//===================================PB4========================================
	//Configura o pino PB0 como saida (MODER: 01)
	GPIOB->MODER &= ~GPIO_MODER_MODER4;  						//Limpa bits 0 e 1 para PB0
	GPIOB->MODER |= GPIO_MODER_MODER4_0;   						//Seta bit 0 para modo saída

	//Configura a saida como Push-Pull
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_4;

	//Define o valor de PB0 para alta velocidade
	GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEEDR4_0;
	GPIOB->OSPEEDR |= (GPIO_OSPEEDR_OSPEEDR4_1 | GPIO_OSPEEDR_OSPEEDR4_0);

}
