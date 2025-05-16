/*
 * defines.h
 *
 *  Created on: Oct 26, 2024
 *      Author: danta
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#define	HAB_PB0	    GPIOB->ODR |= GPIO_ODR_0;  			//Seta PB0 em 1
#define	HAB_PB1    	GPIOB->ODR |= GPIO_ODR_1;  			//Seta PB1 em 1
#define	HAB_PB3    	GPIOB->ODR |= GPIO_ODR_3;  			//Seta PB3 em 1
#define	HAB_PB4    	GPIOB->ODR |= GPIO_ODR_4;  			//Seta PB4 em 1

#define	DESHAB_PB0	GPIOB->ODR &= ~GPIO_ODR_0;  	  //Seta PB0 em 0
#define	DESHAB_PB1	GPIOB->ODR &= ~GPIO_ODR_1;  	  //Seta PB1 em 0
#define	DESHAB_PB3	GPIOB->ODR &= ~GPIO_ODR_3;  	  //Seta PB3 em 0
#define	DESHAB_PB4	GPIOB->ODR &= ~GPIO_ODR_4;  	  //Seta PB4 em 0

#endif /* DEFINES_H_ */
