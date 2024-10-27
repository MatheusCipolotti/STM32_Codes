#include "stm32f030x6.h"
#include "ADC.h"

void ADC_Init(void){
	//Configura o CKMODE para PCLK dividido por 2 (CKMODE = 01)
	ADC1->CFGR2 &= ~ADC_CFGR2_CKMODE;      						//Limpa CKMODE
	ADC1->CFGR2 |= (1 << ADC_CFGR2_CKMODE_Pos); 				//Define CKMODE = 01 (PCLK/2)

	//Habilita o clock para GPIOA
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

	//Configura  o PA0 como entrada analógica
	GPIOA->MODER |= (3 << GPIO_MODER_MODER0_Pos);

	//Habilita o clock para o ADC
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

	//Configura o tempo de amostragem para 28,5 ciclos de clock
	ADC1->SMPR &= ~ADC_SMPR_SMP;   							//Limpa o campo SMP1
	ADC1->SMPR |= (3 << ADC_SMPR_SMP_Pos); 					//Define SMP1 = 011 (28,5 ciclos)

	//Verifica se o ADC está desativado antes da calibração
	if (!(ADC1->CR & ADC_CR_ADEN)){
		//Inicia a calibração do ADC
		ADC1->CR |= ADC_CR_ADCAL;
	    //Aguarda a calibração ser concluída
	    while (ADC1->CR & ADC_CR_ADCAL);
	}

	//Habilita o ADC
	ADC1->CR |= ADC_CR_ADEN;
	while (!(ADC1->ISR & ADC_ISR_ADRDY));
}

unsigned int ADC_Read(void){
	//Seleciona o canal 0 (PA0)
	ADC1->CHSELR = ADC_CHSELR_CHSEL0;

	//Limpa qualquer flag de fim de conversão pendente
	ADC1->ISR |= ADC_ISR_EOC;

	//Inicia a conversão
	ADC1->CR |= ADC_CR_ADSTART;

	//Aguarda o término da conversão
	while (!(ADC1->ISR & ADC_ISR_EOC));

	//Retorna o valor convertido
	return ADC1->DR;
}
