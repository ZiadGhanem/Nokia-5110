#include "delay.h"
#include <tm4c123gh6pm.h>

void SysTick_Delay_Init(void)
{
	SysTick->CTRL = (1<<2 | 1<<0);
}

void SysTick_Delay_ms(volatile unsigned long Value)
{
	SysTick->LOAD = (Value*16000)-1;
	SysTick->VAL = 0;
	
	while(!((SysTick->CTRL) & (1<<16)));
}

void SysTick_Delay_us(volatile unsigned long Value)
{
	SysTick->LOAD = (Value*16)-1;
	SysTick->VAL = 0;
	
	while(!((SysTick->CTRL) & (1<<16)));
}
