#ifndef DEFINES_H_
#define DEFINES_H_

#define RS_HIGH()	GPIOB->ODR |= GPIO_ODR_4
#define RS_LOW()  	GPIOB->ODR &= ~GPIO_ODR_4
#define E_HIGH()  	GPIOB->ODR |= GPIO_ODR_5
#define E_LOW()   	GPIOB->ODR &= ~GPIO_ODR_5

#endif /* DEFINES_H_ */
