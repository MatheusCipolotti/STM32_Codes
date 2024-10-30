#include "stm32f030x6.h"

#include "delay.h"
#include "configs.h"
#include "PWM.h"

int main(){
	OscInit();
	GPIO();
	PWM_TIM1_Config();

	while(1){

	}
}
