#include "stm32f030x6.h"

#include "SPI.h"

void SPI1_Init(void){
	// 1. Habilita clock para GPIOA e SPI1
	RCC->AHBENR  |= RCC_AHBENR_GPIOAEN;
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

	// 2. Configura PA5 (SCK) e PA7 (MOSI) como Alternate Function
	GPIOA->MODER &= ~(GPIO_MODER_MODER5_Msk | GPIO_MODER_MODER7_Msk);
	GPIOA->MODER |=  (GPIO_MODER_MODER5_1 | GPIO_MODER_MODER7_1); 			// AF mode

	// AF0 para SPI1 (AFRL5 e AFRL7 como 0b0000)
	GPIOA->AFR[0] &= ~((0xF << (5 * 4)) | (0xF << (7 * 4)));

	// 3. Configura SPI1 como mestre, software NSS, prescaler baixo
	SPI1->CR1 = 0;
	SPI1->CR1 |= SPI_CR1_MSTR;      										// Modo mestre
	SPI1->CR1 |= SPI_CR1_SSM;       										// Software slave management
	SPI1->CR1 |= SPI_CR1_SSI;       										// NSS em high
	SPI1->CR1 |= SPI_CR1_BR_0 | SPI_CR1_BR_1 | SPI_CR1_BR_2;
	SPI1->CR1 &= ~(SPI_CR1_CPOL | SPI_CR1_CPHA); 							// CPOL=0, CPHA=0
	//SPI1->CR1 &= ~SPI_CR1_LSBFIRST;

	SPI1->CR1 &= ~SPI_CR1_SPE;       										// Desabilita SPI antes de configurar
	SPI1->CR2 &= ~SPI_CR2_DS;       										// Zera os bits DS
	SPI1->CR2 |= (7 << SPI_CR2_DS_Pos); 									// DS = 0b0111 = 8-bit frame
	SPI1->CR2 &= ~SPI_CR2_FRXTH;     										// FIFO Threshold = 8 bits (opcional)

	SPI1->CR1 |= SPI_CR1_SPE;       										// Habilita SPI
}

void SPI1_Write(uint8_t data){
	while (!(SPI1->SR & SPI_SR_TXE));
	*((__IO uint8_t*)&SPI1->DR) = data;  									//acesso forçado de 8 bits, sem isso o compilador força um sinal de 16 bits
	while (!(SPI1->SR & SPI_SR_TXE));
	while (SPI1->SR & SPI_SR_BSY);
}
