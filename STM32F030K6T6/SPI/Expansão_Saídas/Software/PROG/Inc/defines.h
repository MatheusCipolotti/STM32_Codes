#ifndef DEFINES_H_
#define DEFINES_H_

//=========================GENERAL========================
#define SYSTEM_CLOCK			8000000

//=========================EUSART=========================
#define BAUDRATE				9600

//==========================GPIO==========================
#define TOGGLE_LED_ON_BOARD()	GPIOB->ODR ^= GPIO_ODR_0;

#define HIGH_MEMORIA()			GPIOB->BSRR |= GPIO_BSRR_BS_3;  			//Seta PB3 em 1
#define HIGH_MOSTRA()			GPIOB->BSRR |= GPIO_BSRR_BR_4;  			//Seta PB4 em 1

#define LOW_MEMORIA()			GPIOB->BSRR = GPIO_BSRR_BR_3;  	  			//Seta PB3 em 0
#define	LOW_MOSTRA()			GPIOB->BSRR = GPIO_BSRR_BS_4;  	  			//Seta PB4 em 0

#endif /* DEFINES_H_ */
