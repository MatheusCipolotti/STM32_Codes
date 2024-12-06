#include "stm32f030x6.h"

#include "configs.h"
#include "defines.h"
#include "delay.h"
#include "LCD.h"

int main(){
	Osc_Init();
	GPIO();
	LCD_Init();
	LCD_Clear();
	LCD_String_xy(1,4,"INICIANDO...");
	Delay_ms(1000);
	LCD_Clear();

	while(1){
		LCD_String_xy(0,0,"TESTE");
		LCD_String_xy(1,0,"STM32F030K6T6");
	}
}
