#include "Timer_Manager.h"
#include <tm4c123gh6pm.h>

static int Ticks_Count=0;


void Timer_Setup(void)
{
	SYSCTL->RCGCTIMER |= (1<<0);	//Enable clock gating for System Timer
	
	//Wait for clock to be enabled
	__ASM volatile("nop");
	__ASM volatile("nop");
	__ASM volatile("nop");
	
	System_Timer->CTL &= ~(1<<0);		//Make sure System Timer is Disabled
	System_Timer->CFG = 0;					//32 Bit Timer
	System_Timer->TAMR |= (1<<1);		//Choose periodic mode, Down counting (Buttons)
	System_Timer->TAILR = 255999;
	System_Timer->IMR |= (1<<0); 		//Enable Debounce Timer Interrupts
	
	NVIC->ISER[0] |= (1<<19);				//Enable NVIC interrupts for System Timer
	
	System_Timer->CTL |= (1<<0);		//Enable Debounce Timer
	
}


Trigger_Type Time_Task(void)
{
	Trigger_Type Next_Trigger;
	
	if(Ticks_Count>=100)
	{
		Ticks_Count=0;
		Next_Trigger=Refresh_Time;
	}
		
	else
	{
		Next_Trigger=Check_Pins;
	}
		
	Ticks_Count++;
	
	return Next_Trigger;
}
