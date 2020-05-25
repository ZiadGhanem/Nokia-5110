#include <tm4c123gh6pm.h>
#include "Pin_Manager.h"
#include "Sound.h"

static Repeat_Config Melody_Repeat;

const Melody_Data ButtonTick_Tone={{NOTE_G6},{8},1,Melody_Fast};

const Melody_Data SuperMario_Melody_Theme=
{
	{NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0, NOTE_G6, 0, 0, 0, NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0,
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7,
	0, NOTE_C7, NOTE_D7, NOTE_B6, 0, 0, NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0,
	0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0, NOTE_C7, NOTE_D7, NOTE_B6, 0, 0},
	
	{12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
	12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
	12, 12, 9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
	12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
	12, 12, 9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
	12, 12},
	
	79,

	Melody_Slow};


	const Melody_Data SuperMario_Melody_UnderWorld={
		{NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0, NOTE_C4, NOTE_C5,
	NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0, NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0, 0, NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_DS4, NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4, NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3, NOTE_AS3, NOTE_A3, NOTE_GS3, 0, 0, 0},
		
	{12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6,
	3, 12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6,
	6, 18, 18, 18, 6, 6, 6, 6, 6, 6, 18, 18, 18, 18, 18, 18, 10,
	10, 10, 10, 10, 10, 3, 3, 3},
			
	55,
	
	Melody_Slow};

		
const Melody_Data StarWars_Melody_Theme={
	{NOTE_A4,NOTE_A4,NOTE_A4,NOTE_F4,NOTE_C5,NOTE_A4,NOTE_F4,NOTE_C5,
		NOTE_A4,0,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_F5,NOTE_C5,NOTE_GS4,
		NOTE_F4,NOTE_C5,NOTE_A4,0,NOTE_A5,NOTE_A4,NOTE_A4,NOTE_A5,
		NOTE_GS5,NOTE_G5,NOTE_FS5,NOTE_F5,NOTE_FS5,0,NOTE_A4,NOTE_DS5,
		NOTE_D5,NOTE_CS5,NOTE_C5,NOTE_B4,NOTE_C5,0,NOTE_F4,NOTE_GS4,
		NOTE_F4,NOTE_A4,NOTE_C5,NOTE_A4,NOTE_C5,NOTE_E5,0,NOTE_A5,
		NOTE_A4,NOTE_A4,NOTE_A5,NOTE_GS5,NOTE_G5,NOTE_FS5,NOTE_F5,
		NOTE_FS5,0,NOTE_A4,NOTE_DS5,NOTE_D5,NOTE_CS5,NOTE_C5,NOTE_B4,
		NOTE_C5,0,NOTE_F4,NOTE_GS4,NOTE_F4,NOTE_C5,NOTE_A4,NOTE_F4,
		NOTE_C5,NOTE_A4,0},
	
	{2,2,2,3,7,2,3,7,2,2,2,2,2,3,7,2,3,7,2,2,2,3,7,2,3,6,8,
		8,4,3,4,2,3,6,8,8,4,3,4,2,3,8,2,3,8,2,2,2,3,7,2,3,6,8,
		8,4,3,4,2,3,6,8,8,4,3,4,2,3,8,2,3,8,2,2},
	
	74,
		
	Melody_Fast	
};


const Melody_Data Twinkle_Melody={

{NOTE_C6,NOTE_C6,NOTE_G6,NOTE_G6,NOTE_A6,NOTE_A6,NOTE_G6,NOTE_F6,NOTE_F6,NOTE_E6,NOTE_E6,
NOTE_D6,NOTE_D6,NOTE_C6,NOTE_G6,NOTE_G6,NOTE_F6,NOTE_F6,NOTE_E6,NOTE_E6,NOTE_D6,NOTE_G6,
NOTE_G6,NOTE_F6,NOTE_F6,NOTE_E6,NOTE_E6,NOTE_D6,NOTE_C6,NOTE_C6,NOTE_G6,NOTE_G6,NOTE_A6,
NOTE_A6,NOTE_G6,NOTE_F6,NOTE_F6,NOTE_E6,NOTE_E6,NOTE_D6,NOTE_D6,NOTE_C6},

{5,5,5,5,5,5,2,5,5,5,5,5,5,2,5,5,5,5,5,5,2,5,5,5,5,5,5,2,5,5,5,5,5,5,2,5,5,5,5,5,5,1},

42,

Melody_Slow
};


static int Tone_Periodic_Time
					,Tone_Cycles
					,Current_Tone_Cycles=0
					,Current_Melody_Length;

static Melody_Data Current_Melody;

enum{
	Playing_Tone,
	Tone_Delay,
	Next_Tone,
	Melody_Off
}Next_Melody_State;



void Sound_Init(void)
{
	SYSCTL->RCGCWTIMER |= (1<<5);	//Enable clock gating for Sound Timer
	
	//Wait for clock to be enabled
	__ASM volatile("nop");
	__ASM volatile("nop");
	__ASM volatile("nop");
	
	Sound_Timer->CTL &= ~(1<<0);		//Make sure Sound Timer is Disabled
	Sound_Timer->CTL |= (1<<6);
	Sound_Timer->CFG = 0x4;					//64 Bit Mode
	Sound_Timer->IMR |= (1<<2);
	
	NVIC->ISER[3] |= (1<<8);				//Enable NVIC interrupts for Sound Timer
}

void Play_Melody(Melody Song,Repeat_Config Set_Melody_Repeat)
{
	Sound_Timer->CTL &= ~(1<<0);		//Make sure Sound Timer is Disabled
	Sound_Timer->TAMR |= 0x20A;	//PWM0 & Periodic Mode
	
	switch(Song)
	{
		case ButtonTick_Sound:
		{
			Current_Melody=ButtonTick_Tone;
			break;
		}
		case SuperMario_Theme:
		{
			Current_Melody=SuperMario_Melody_Theme;
			break;
		}
		case SuperMario_UnderWorld:
		{
			Current_Melody=SuperMario_Melody_UnderWorld;
			break;
		}
		
		case StarWars_Theme:
		{
			Current_Melody=StarWars_Melody_Theme;
			break;
		}
		
		case Twinkle:
		{
			Current_Melody=Twinkle_Melody;
			break;
		}
		
		default:
		{
			break;
		}
	}

	Melody_Repeat=Set_Melody_Repeat;
	
	Current_Tone_Cycles=0;
	Current_Melody_Length=0;
		
	Tone_Periodic_Time= 50000000/(Current_Melody.Melody_Frequency[0]);
	Tone_Cycles = ((Current_Melody.Melody_Frequency[0]))/(Current_Melody.Melody_Tempo[0]);
	
	Sound_Timer->TAILR = Tone_Periodic_Time;
	Sound_Timer->TAMATCHR = (Tone_Periodic_Time/2);

	Next_Melody_State=Playing_Tone;
	
	Sound_Port->DEN 	|= Sound_Pin;
	
	Sound_Timer->CTL |= (1<<0);		//Enable Sound Timer
}

void Sound_Task(void)
{
	switch(Next_Melody_State)
	{
		case Playing_Tone:
		{
			if(Current_Tone_Cycles<Tone_Cycles)
			{
				Current_Tone_Cycles++;
			}
			else
			{
				Current_Tone_Cycles=0;
				
				switch(Current_Melody.Melody_Speed)
				{
					case Melody_Slow:
					{
						Sound_Timer->TAMATCHR=0;
						Next_Melody_State=Tone_Delay;
						break;
					}
					
					case Melody_Fast:
					{
						Current_Melody_Length++;
						Next_Melody_State=Next_Tone;
						if(Current_Melody_Length==Current_Melody.Melody_Length)
						{
							Current_Melody_Length=0;
							if(Melody_Repeat==No_Repeat)
							{
								Next_Melody_State=Melody_Off;
							}
						}
						break;
					}
				}
			}

			break;
		}

		case Tone_Delay:
		{
			if(Current_Tone_Cycles<Tone_Cycles)
			{
				Current_Tone_Cycles++;
			}
			else
			{
				Current_Tone_Cycles=0;
				Current_Melody_Length++;
				Next_Melody_State=Next_Tone;
				if(Current_Melody_Length==Current_Melody.Melody_Length)
				{
					Current_Melody_Length=0;
					if(Melody_Repeat==No_Repeat)
					{
						Next_Melody_State=Melody_Off;
					}
				}
			}
			break;
		}
		
		case Next_Tone:
		{
			if(Current_Melody.Melody_Frequency[Current_Melody_Length] != 0)
			{
				Tone_Periodic_Time= 50000000/(Current_Melody.Melody_Frequency[Current_Melody_Length]);
				Tone_Cycles = ((Current_Melody.Melody_Frequency[Current_Melody_Length]))/(Current_Melody.Melody_Tempo[Current_Melody_Length]);
				Sound_Timer->TAILR = Tone_Periodic_Time;
				Sound_Timer->TAMATCHR = (Tone_Periodic_Time/2);
			}
			else
			{
				Sound_Timer->TAMATCHR=0;
			}
			
			Next_Melody_State=Playing_Tone;
			break;
		}

		case Melody_Off:
		{
			Stop_Melody();
		}

		default:
		{
			break;
		}
	}

}


void Stop_Melody(void)
{
	Sound_Timer->CTL &= ~(1<<0);
	Sound_Timer->TAMR = 0x1;
}
