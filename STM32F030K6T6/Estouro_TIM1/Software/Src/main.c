#include "stm32f030x6.h"

#include "configs.h"

unsigned char counter = 0x00;

//Função de interrupção do TIM1
void TIM1_BRK_UP_TRG_COM_IRQHandler(void){
    if (TIM1->SR & TIM_SR_UIF){    				//Verifica se houve overflow (UIF = Update Interrupt Flag)
        TIM1->SR &= ~TIM_SR_UIF;    			//Limpa a flag de interrupção
        counter++;                  			//Incrementa a variável counter a cada overflow
    }
}

int main(){
	OscInit();
	GPIO();
	TIM1_Init();

	while(1){
		if(counter == 1){
			//Alterna o estado do PB0 (ON/OFF)
			GPIOB->ODR ^= GPIO_ODR_0;  			//Alterna o bit 0 (PB0)
			counter = 0x00;
		}
	}
}
