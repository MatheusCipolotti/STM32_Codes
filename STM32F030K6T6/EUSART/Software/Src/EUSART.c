#include "stm32f030x6.h"

#include "EUSART.h"

void EUSART1_Init(unsigned long baudrate){
	//Habilita o clock para GPIOA e USART1
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;    							//Clock para GPIOA
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN; 							//Clock para USART1

	//Configura PA2 (TX) e PA3 (RX) como Alternate Function
	GPIOA->MODER &= ~(GPIO_MODER_MODER2 | GPIO_MODER_MODER3); 				//Limpa os bits
	GPIOA->MODER |= (GPIO_MODER_MODER2_1 | GPIO_MODER_MODER3_1); 				//Modo AF para PA2 e PA3
	GPIOA->AFR[0] &= ~((0xF << (2 * 4)) | (0xF << (3 * 4)));   				//Limpa AF para PA2 e PA3
	GPIOA->AFR[0] |= ((1 << (2 * 4)) | (1 << (3 * 4)));        				//AF1 para USART1_TX e USART1_RX

	//Configura baud rate (assume clock de 8 MHz e 9600 bps)
	USART1->BRR = 8000000 / baudrate;

	//Habilita USART1 e configurar para transmissao e recepção
	USART1->CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
}

void EUSART1_Write(const char data){
	//Espera ate o registrador de dados estar pronto para transmissão
	while (!(USART1->ISR & USART_ISR_TXE));

	//Escreve o caractere no registrador de dados
	USART1->TDR = data;

}

void EUSART1_Write_ln(const char data){
	EUSART1_Write(data);
	EUSART1_Write('\r');
	EUSART1_Write('\n');
}

void EUSART1_Write_Text(const char text[]){
    int i;
    for(i=0;text[i]!='\0';i++){
        EUSART1_Write(text[i]);
    }
}

void EUSART1_Write_Text_ln(const char text[]){
	EUSART1_Write_Text(text);
	EUSART1_Write('\r');
	EUSART1_Write('\n');
}

char EUSART1_Read(void){
	//Espera ate haver um dado disponivel para leitura
	while (!(USART1->ISR & USART_ISR_RXNE));

	//Le o dado recebido
	return (char)USART1->RDR;
}
