#include <tm4c123gh6pm.h>
#include "main.h"
#include "GLCD.h"
#include "Pin_Manager.h"
#include "Timer_Manager.h"
#include "Sound.h"
#include "Std_Types.h"
#include "Snake.h"

/*
const unsigned char Superman[6][84] = {
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x60, 0x20, 0x30, 0x18, 0x8C, 0x84, 0xC6,
0xE2, 0xE2, 0xF3, 0xF2, 0x72, 0x32, 0x32, 0x12, 0x13, 0x02, 0x02, 0x82, 0x82, 0xC2, 0xC2, 0xE2,
0xE2, 0xE3, 0xE2, 0xE2, 0xE2, 0xF2, 0xE2, 0xF3, 0xF2, 0xE2, 0xF3, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2,
0xE3, 0xC2, 0xC2, 0x82, 0x02, 0x02, 0x03, 0x12, 0x32, 0x72, 0xF2, 0xF2, 0x73, 0x02, 0x02, 0x02,
0x02, 0x02, 0x02, 0xE2, 0xC6, 0x86, 0x0C, 0x18, 0x30, 0x20, 0x60, 0xC0, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x18, 0x3C, 0x26, 0xE3, 0x81, 0x81, 0x08, 0x18, 0x3C, 0x7E, 0x7F, 0xFF, 0xFF, 0x1F, 
0x07, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F,
0x3F, 0x7F, 0x3F, 0x7F, 0x7F, 0x7F, 0x3F, 0x7F, 0x7F, 0x7F, 0x3F, 0x7F, 0x7F, 0x7F, 0x3F, 0x7F,
0x3F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7C, 0x70, 0x70, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
0xF0, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x08, 0x01, 0xC3, 0xC2, 0x66,
0x3C, 0x18, 0x00, 0x00}, 
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0C, 0x18, 0x30, 0x21, 0x61, 0xC0,
0x80, 0x00, 0x00, 0x00, 0x60, 0x40, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
0xC0, 0xC0, 0xC0, 0x80, 0xC0, 0x80, 0x80, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03,
0x07, 0x0F, 0x0F, 0x87, 0xC3, 0x63, 0x21, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x03, 0x06, 0x0C, 0x0C, 0x10, 0x30, 0x61, 0xC3, 0x87, 0x0F, 0x07, 0x03, 0x03, 0x03, 0x03,
0x01, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x0F, 0x0F, 0x07, 0x06, 0x80, 0xC0, 0x60, 0x30, 0x30, 0x08,
0x0C, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x04, 0x0C, 0x18, 0x30,
0x61, 0xC1, 0x87, 0x07, 0x0F, 0x1E, 0x3F, 0x7E, 0xFF, 0xFE, 0xFF, 0xFE, 0x7F, 0x3E, 0x1F, 0x0F,
0x07, 0x87, 0xC3, 0x61, 0x30, 0x18, 0x08, 0x0C, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x01, 0x02, 0x06, 0x0C, 0x18, 0x30, 0x61, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x02,
0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00}
};
*/

CheckPins_Result_Type CheckPins_Result_Next;

void TIMER0A_Handler(void)
{
	if(System_Timer->RIS & (1<<0))
	{
		CheckPins_Result_Next.Trigger=Time_Task();
		System_Timer->ICR	|= (1<<0);
	}
}

void WTIMER5A_Handler(void)
{
	if(Sound_Timer->RIS & (1<<2))
	{
		CheckPins_Result_Next.Trigger=Play_Sound;
		Sound_Timer->ICR |= (1<<2);
	}
}


int main(void)

{
	BackLight_Settings Previous_BackLight_State;

	int HoursTens=0,
		HoursDigits=0,
		MinutesTens=0,
		MinutesDigits=0,
		Seconds=0,
		HoursTens_New=0,
		HoursDigits_New=0,
		MinutesTens_New=0,
		MinutesDigits_New=0,
		AlarmHoursTens=0,
		AlarmHoursDigits=0,
		AlarmMinutesTens=0,
		AlarmMinutesDigits=0,
		AlarmHoursTens_New=0,
		AlarmHoursDigits_New=0,
		AlarmMinutesTens_New=0,
		AlarmMinutesDigits_New=0,
		HalfSeconds_Count=0,
		Enable_Activate_Alarm=0;

	enum{Clock,Main_Menu,Settings_Menu,Clock_Menu,Set_Clock,Alarm_Menu,Set_Alarm,Alarm_Tone,Alarm,Games_Menu,Snake_Game,Snake_GameOver,Memo}Current_Position=Clock;
	enum{Hours=1,Minutes=44}SetClock_Position=Hours;
	enum{Alarm_Deactivated,Alarm_Activated}Alarm_State;
	
	Main_Menu_Selection_Type Main_Menu_Selection=Settings_Menu_Selected;
	Settings_Menu_Selection_Type Settings_Menu_Selection=BackLight_Selected;
	Clock_Menu_Selection_Type Clock_Menu_Selection=Alarm_Menu_Selected;
	Alarm_Menu_Selection_Type Alarm_Menu_Selection=Set_Alarm_Menu_Selected;
	Games_Menu_Selection_Type Games_Menu_Selection=Snake_Selected;

	CheckPins_Result_Type CheckPins_Result_Current;
	CheckPins_Result_Current.Trigger=Off;
	
	ButtonSound_Settings_Type ButtonSound_Settings=ButtonSound_Enable;
	
	Melody Alarm_Melody=SuperMario_Theme;
	Melody Alarm_Melody_New=SuperMario_Theme;
	
	Snake_Direction_Type Snake_Direction=Snake_Right;
	Snake_GameState_Type Snake_GameState;

	char Main_Menu_Items[]="Settings\nClock\nGames\nMemo\n";
	char Settings_Menu_Items[]="BackLight\nSet Clock\nButton Sound\n";
	char Clock_Menu_Items[]="Alarm\n";
	char Alarm_Menu_Items[]="Set Alarm\nRemove Alarm\nAlarm Tone\n";
	char Alarm_Tone_Menu_Items[]="Mario Theme\nMario Underworld\nStarWars Theme\nTwinkle\n";
	char Games_Menu_Items[]="Snake\n";

	GLCD_Init();
	Pin_Setup();
	Timer_Setup();
	Sound_Init();
	
	__ASM volatile("CPSIE i");			//Enable global interrupts
	
	GLCD_BackLight(BackLight_Off);
	
	GLCD_DisplayClock(HoursTens,HoursDigits,MinutesTens,MinutesDigits,Seconds);
	GLCD_Update();
	
	while(1)
	{
		switch(CheckPins_Result_Current.Trigger)
		{	
			case Selection_Up:
			{
				CheckPins_Result_Next.Trigger=Off;
				
				switch(Current_Position)
				{
					case Main_Menu:
					{
							if(Main_Menu_Selection > 0)
							{
								Main_Menu_Selection--;
							}
							else
							{
								Main_Menu_Selection=Main_Menu_Max_Selection;
							}
							
							GLCD_ClearBuffer();
							GLCD_SetMenu(Main_Menu_Items,Main_Menu_Selection);
							GLCD_Update();
						
						break;
					}
					
					case Settings_Menu:
					{
						if(Settings_Menu_Selection > 0)
						{
							Settings_Menu_Selection--;
						}
						else
						{
							Settings_Menu_Selection=Settings_Menu_Max_Selection;
						}
						
						GLCD_ClearBuffer();
						GLCD_SetMenu(Settings_Menu_Items,Settings_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Clock_Menu:
					{
						
						if(Clock_Menu_Selection > 0)
						{
							Clock_Menu_Selection--;
						}
						else
						{
							Clock_Menu_Selection=Clock_Menu_Max_Selection;
						}
						
						GLCD_ClearBuffer();
						GLCD_SetMenu(Clock_Menu_Items,Clock_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Set_Clock:
					{
						switch(SetClock_Position)
						{
							case Hours:
							{
								HoursDigits_New++;
								if(HoursDigits_New==10)
								{
									HoursDigits_New=0;
									HoursTens_New++;
								}
								if(HoursTens_New==2 && HoursDigits_New==4)
								{
									HoursDigits_New=0;
									HoursTens_New=0;
								}
								
								break;
							}
							
							case Minutes:
							{
								MinutesDigits_New++;
								if(MinutesDigits_New==10)
								{
									MinutesDigits_New=0;
									MinutesTens_New++;
									if(MinutesTens_New==6)
									{
										MinutesTens_New=0;
									}
								}
								
								break;
							}
							
							default:
							{
								break;
							}
							
						}
						
						GLCD_ClearBuffer();
						GLCD_DisplayClock(HoursTens_New,HoursDigits_New,MinutesTens_New,MinutesDigits_New,1);
						GLCD_PrintString(0,17,"Set Clock");
						GLCD_PrintString(5,0,"Apply");
						GLCD_PrintString(5,60,"Back");
						GLCD_DrawRect(SetClock_Position,10,38,26,BLACK);
						GLCD_Update();
						break;
					}
					
					
					case Alarm_Menu:
					{
						if(Alarm_Menu_Selection > 0)
						{
							Alarm_Menu_Selection--;
						}
						else
						{
							Alarm_Menu_Selection=Alarm_Menu_Max_Selection;
						}
						
						GLCD_ClearBuffer();
						GLCD_SetMenu(Alarm_Menu_Items,Alarm_Menu_Selection);
						GLCD_Update();
						break;
					}
								
					case Set_Alarm:
					{
						switch(SetClock_Position)
						{
							case Hours:
							{
								AlarmHoursDigits_New++;
								if(AlarmHoursDigits_New==10)
								{
									AlarmHoursDigits_New=0;
									AlarmHoursTens_New++;
								}
								if(AlarmHoursTens_New==2 && AlarmHoursDigits_New==4)
								{
									AlarmHoursDigits_New=0;
									AlarmHoursTens_New=0;
								}
								
								break;
							}
							
							case Minutes:
							{
								AlarmMinutesDigits_New++;
								if(AlarmMinutesDigits_New==10)
								{
									AlarmMinutesDigits_New=0;
									AlarmMinutesTens_New++;
									if(AlarmMinutesTens_New==6)
									{
										AlarmMinutesTens_New=0;
									}
								}
								
								break;
							}
							
							default:
							{
								break;
							}
							
						}
						
						GLCD_ClearBuffer();
						GLCD_DisplayClock(AlarmHoursTens_New,AlarmHoursDigits_New,AlarmMinutesTens_New,AlarmMinutesDigits_New,1);
						GLCD_PrintString(0,17,"Set Alarm");
						GLCD_PrintString(5,0,"Apply");
						GLCD_PrintString(5,60,"Back");
						GLCD_DrawRect(SetClock_Position,10,38,26,BLACK);
						GLCD_Update();
						break;
					}
					
					case Alarm_Tone:
					{
						if(Alarm_Melody_New>0)
						{
							Alarm_Melody_New--;
						}
						else
						{
							Alarm_Melody_New=AlarmTones_Max_Number;
						}
						
						Play_Melody(Alarm_Melody_New,Repeat);
						GLCD_ClearBuffer();
						GLCD_SetMenu(Alarm_Tone_Menu_Items,Alarm_Melody_New);
						GLCD_Update();
						break;
					}			
					case Games_Menu:
					{
						if(Games_Menu_Selection > 0)
						{
							Games_Menu_Selection--;
						}
						else
						{
							Games_Menu_Selection=Games_Menu_Max_Selection;
						}
						
						GLCD_ClearBuffer();
						GLCD_SetMenu(Games_Menu_Items,Games_Menu_Selection);
						GLCD_Update();
						break;
					}
					case Snake_Game:
					{
						if((Snake_Direction!=Snake_Up) && (Snake_Direction!=Snake_Down))
						{
							Snake_Direction=Snake_Up;
							Snake_GameState=Snake_MainTask(Snake_Direction);
							if(Snake_GameState==Snake_GameOver_State)
							{
								Current_Position=Snake_GameOver;
								GLCD_ClearBuffer();
								Snake_GameOver_Task();
							}
							GLCD_Update();
						}
						break;
					}
					default:
					{
						break;
					}
				}
				break;
			}
			
			case Selection_Down:
			{
				CheckPins_Result_Next.Trigger=Off;
				switch(Current_Position)
				{
					case Main_Menu:
					{
							Main_Menu_Selection++;
							if(Main_Menu_Selection > Main_Menu_Max_Selection)
							{
								Main_Menu_Selection=(Main_Menu_Selection_Type)0;
							}
							GLCD_ClearBuffer();
							GLCD_SetMenu(Main_Menu_Items,Main_Menu_Selection);
							GLCD_Update();
						break;
					}
					
					case Settings_Menu:
					{
						Settings_Menu_Selection++;
						if(Settings_Menu_Selection > Settings_Menu_Max_Selection)
						{
							Settings_Menu_Selection=(Settings_Menu_Selection_Type)0;
						}
						GLCD_ClearBuffer();
						GLCD_SetMenu(Settings_Menu_Items,Settings_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Clock_Menu:
					{
						Clock_Menu_Selection++;
						if(Clock_Menu_Selection > Clock_Menu_Max_Selection)
						{
							Clock_Menu_Selection=(Clock_Menu_Selection_Type)0;
						}
						GLCD_ClearBuffer();
						GLCD_SetMenu(Clock_Menu_Items,Clock_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Set_Clock:
						{
						switch(SetClock_Position)
						{
							case Hours:
							{
								HoursDigits_New--;
								if(HoursDigits_New<0)
								{
									if(HoursTens_New==0)
									{
										HoursTens_New=2;
										HoursDigits_New=3;
									}
									else
									{
										HoursTens_New--;
										HoursDigits_New=9;
									}
								}
								break;
							}
							case Minutes:
							{
								MinutesDigits_New--;
								if(MinutesDigits_New<0)
								{
									MinutesDigits_New=9;
									
									if(MinutesTens_New==0)
									{
										MinutesTens_New=5;
									}
									else
									{
										MinutesTens_New--;
									}
								}
								break;
							}
							
							default:
							{
								break;
							}
							
						}
						
						GLCD_ClearBuffer();
						GLCD_DisplayClock(HoursTens_New,HoursDigits_New,MinutesTens_New,MinutesDigits_New,1);
						GLCD_PrintString(0,17,"Set Clock");
						GLCD_PrintString(5,0,"Apply");
						GLCD_PrintString(5,60,"Back");
						GLCD_DrawRect(SetClock_Position,10,38,26,BLACK);
						GLCD_Update();
						break;
					}	
					
					case Alarm_Menu:
					{
						Alarm_Menu_Selection++;
						if(Alarm_Menu_Selection > Alarm_Menu_Max_Selection)
						{
							Alarm_Menu_Selection=(Alarm_Menu_Selection_Type)0;
						}
						GLCD_ClearBuffer();
						GLCD_SetMenu(Alarm_Menu_Items,Alarm_Menu_Selection);
						GLCD_Update();
						break;
					}						
					case Set_Alarm:
					{
						switch(SetClock_Position)
						{
							case Hours:
							{
								AlarmHoursDigits_New--;
								if(AlarmHoursDigits_New<0)
								{
									if(AlarmHoursTens_New==0)
									{
										AlarmHoursTens_New=2;
										AlarmHoursDigits_New=3;
									}
									else
									{
										AlarmHoursTens_New--;
										AlarmHoursDigits_New=9;
									}
								}
								break;
							}
							case Minutes:
							{
								AlarmMinutesDigits_New--;
								if(AlarmMinutesDigits_New<0)
								{
									AlarmMinutesDigits_New=9;
									
									if(AlarmMinutesTens_New==0)
									{
										AlarmMinutesTens_New=5;
									}
									else
									{
										AlarmMinutesTens_New--;
									}
								}
								break;
							}
							
							default:
							{
								break;
							}
							
						}
						
						GLCD_ClearBuffer();
						GLCD_DisplayClock(AlarmHoursTens_New,AlarmHoursDigits_New,AlarmMinutesTens_New,AlarmMinutesDigits_New,1);
						GLCD_PrintString(0,17,"Set Alarm");
						GLCD_PrintString(5,0,"Apply");
						GLCD_PrintString(5,60,"Back");
						GLCD_DrawRect(SetClock_Position,10,38,26,BLACK);
						GLCD_Update();
						break;
					}
					
					case Alarm_Tone:
					{
						if(Alarm_Melody_New<AlarmTones_Max_Number)
						{
							Alarm_Melody_New++;
						}
						else
						{
							Alarm_Melody_New=(Melody)0;
						}
						
						Play_Melody(Alarm_Melody_New,Repeat);
						GLCD_ClearBuffer();
						GLCD_SetMenu(Alarm_Tone_Menu_Items,Alarm_Melody_New);
						GLCD_Update();
						break;
					}	
					case Games_Menu:
					{
						Games_Menu_Selection++;
						if(Games_Menu_Selection > Games_Menu_Max_Selection)
						{
							Games_Menu_Selection=(Games_Menu_Selection_Type)0;
						}
						GLCD_ClearBuffer();
						GLCD_SetMenu(Games_Menu_Items,Games_Menu_Selection);
						GLCD_Update();
						break;
					}
					case Snake_Game:
					{
						if((Snake_Direction!=Snake_Up) && (Snake_Direction!=Snake_Down))
						{
							Snake_Direction=Snake_Down;
							Snake_GameState=Snake_MainTask(Snake_Direction);
							if(Snake_GameState==Snake_GameOver_State)
							{
								Current_Position=Snake_GameOver;
								if(Snake_GameState==Snake_GameOver_State)
								{
									Current_Position=Snake_GameOver;
									GLCD_ClearBuffer();
									Snake_GameOver_Task();
								}
							}
							GLCD_Update();
						}
					}
					default:
					{
						break;
					}
				}
				break;
			}
			
			case Selection_Left:
			{
				CheckPins_Result_Next.Trigger=Off;
				switch(Current_Position)
				{
					case Set_Clock:
					{
						switch(SetClock_Position)
						{
							case Hours:
							{
								SetClock_Position=Minutes;
								break;
							}
							case Minutes:
							{
								SetClock_Position=Hours;
								break;
							}
							
							default:
							{
								break;
							}
						}
						
						GLCD_ClearBuffer();
						GLCD_DisplayClock(HoursTens_New,HoursDigits_New,MinutesTens_New,MinutesDigits_New,1);
						GLCD_PrintString(0,17,"Set Clock");
						GLCD_PrintString(5,0,"Apply");
						GLCD_PrintString(5,60,"Back");
						GLCD_DrawRect(SetClock_Position,10,38,26,BLACK);
						GLCD_Update();
						break;
					}
						
					case Set_Alarm:
					{
						switch(SetClock_Position)
						{
							case Hours:
							{
								SetClock_Position=Minutes;
								break;
							}
							case Minutes:
							{
								SetClock_Position=Hours;
								break;
							}
							
							default:
							{
								break;
							}
						}
						
						GLCD_ClearBuffer();
						GLCD_DisplayClock(AlarmHoursTens_New,AlarmHoursDigits_New,AlarmMinutesTens_New,AlarmMinutesDigits_New,1);
						GLCD_PrintString(0,17,"Set Alarm");
						GLCD_PrintString(5,0,"Apply");
						GLCD_PrintString(5,60,"Back");
						GLCD_DrawRect(SetClock_Position,10,38,26,BLACK);
						GLCD_Update();
						break;
					}
					
					case Snake_Game:
					{
						if((Snake_Direction!=Snake_Left) && (Snake_Direction!=Snake_Right))
						{
							Snake_Direction=Snake_Left;
							Snake_GameState=Snake_MainTask(Snake_Direction);
							if(Snake_GameState==Snake_GameOver_State)
							{
								Current_Position=Snake_GameOver;
								if(Snake_GameState==Snake_GameOver_State)
								{
									Current_Position=Snake_GameOver;
									GLCD_ClearBuffer();
									Snake_GameOver_Task();
								}
							}
							GLCD_Update();
						}
						break;
					}
					default:
					{
						break;
					}
				}
				break;
			}
			
			case Selection_Right:
			{
				CheckPins_Result_Next.Trigger=Off;
				switch(Current_Position)
				{
					case Set_Clock:
					{
						switch(SetClock_Position)
						{
							case Hours:
							{
								SetClock_Position=Minutes;
								break;
							}
							
							case Minutes:
							{
								SetClock_Position=Hours;
								break;
							}
							
							default:
							{
								break;
							}
						}
						
						GLCD_ClearBuffer();
						GLCD_DisplayClock(HoursTens_New,HoursDigits_New,MinutesTens_New,MinutesDigits_New,1);
						GLCD_PrintString(0,17,"Set Clock");
						GLCD_PrintString(5,0,"Apply");
						GLCD_PrintString(5,60,"Back");
						GLCD_DrawRect(SetClock_Position,10,38,26,BLACK);
						GLCD_Update();
						break;
					}
					
					case Set_Alarm:
					{
						switch(SetClock_Position)
						{
							case Hours:
							{
								SetClock_Position=Minutes;
								break;
							}
							
							case Minutes:
							{
								SetClock_Position=Hours;
								break;
							}
							
							default:
							{
								break;
							}
						}
						
						GLCD_ClearBuffer();
						GLCD_DisplayClock(AlarmHoursTens_New,AlarmHoursDigits_New,AlarmMinutesTens_New,AlarmMinutesDigits_New,1);
						GLCD_PrintString(0,17,"Set Alarm");
						GLCD_PrintString(5,0,"Apply");
						GLCD_PrintString(5,60,"Back");
						GLCD_DrawRect(SetClock_Position,10,38,26,BLACK);
						GLCD_Update();
						break;
					}
						
					case Snake_Game:
					{
						if((Snake_Direction!=Snake_Left) && (Snake_Direction!=Snake_Right))
						{
							Snake_Direction=Snake_Right;
							Snake_GameState=Snake_MainTask(Snake_Direction);
							if(Snake_GameState==Snake_GameOver_State)
							{
								Current_Position=Snake_GameOver;
								if(Snake_GameState==Snake_GameOver_State)
								{
									Current_Position=Snake_GameOver;
									GLCD_ClearBuffer();
									Snake_GameOver_Task();
								}
							}
							GLCD_Update();
						}
						break;
					}
					default:
					{
						break;
					}
				}
				break;
			}
			
			case Choose:
			{
				CheckPins_Result_Next.Trigger=Off;
				
				switch(Current_Position)
				{
					case Clock:
					{
						Main_Menu_Selection=(Main_Menu_Selection_Type)0;
						Current_Position=Main_Menu;
						GLCD_ClearBuffer();
						GLCD_SetMenu(Main_Menu_Items,Main_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Main_Menu:
					{
						switch(Main_Menu_Selection)
						{
							case Settings_Menu_Selected:
							{
								Current_Position=Settings_Menu;
								Settings_Menu_Selection=(Settings_Menu_Selection_Type)0;
								GLCD_ClearBuffer();
								GLCD_SetMenu(Settings_Menu_Items,Settings_Menu_Selection);
								GLCD_Update();
								break;
							}
							case Clock_Menu_Selected:
							{
								Current_Position=Clock_Menu;
								Clock_Menu_Selection=(Clock_Menu_Selection_Type)0;
								GLCD_ClearBuffer();
								GLCD_SetMenu(Clock_Menu_Items,Clock_Menu_Selection);
								GLCD_Update();
								break;
							}
							case Games_Selected:
							{
								Current_Position=Games_Menu;
								Games_Menu_Selection=(Games_Menu_Selection_Type)0;
								GLCD_ClearBuffer();
								GLCD_SetMenu(Games_Menu_Items,Games_Menu_Selection);
								GLCD_Update();
								break;
							}
							
							case Memo_Selected:
							{
								Current_Position=Memo;
								Memo_Update();
								GLCD_Update();
								break;
							}
							
							default:
							{
								break;
							}
						}
						break;
					}
					
					case Settings_Menu:
					{
						switch(Settings_Menu_Selection)
						{
							case BackLight_Selected:
							{
								GLCD_BackLight(BackLight_Toggle);
								break;
							}
							case Set_Clock_Menu_Selected:
							{
								Current_Position=Set_Clock;
								SetClock_Position=Hours;
								HoursTens_New=HoursTens;
								HoursDigits_New=HoursDigits;
								MinutesTens_New=MinutesTens;
								MinutesDigits_New=MinutesDigits;
								GLCD_ClearBuffer();
								GLCD_PrintString(0,17,"Set Clock");
								GLCD_PrintString(5,0,"Apply");
								GLCD_PrintString(5,60,"Back");
								GLCD_DisplayClock(HoursTens,HoursDigits,MinutesTens,MinutesDigits,1);
								GLCD_DrawRect(SetClock_Position,10,38,26,BLACK);
								GLCD_Update();
								break;
							}
							
							case ButtonSound_Selected:
							{
								ButtonSound_Settings^=(1<<0);
								break;
							}
							
							default:
							{
								break;
							}
						}
						break;
					}
					case Clock_Menu:
					{
						switch(Clock_Menu_Selection)
						{
							case Alarm_Menu_Selected:
							{
								Current_Position=Alarm_Menu;
								Alarm_Menu_Selection=(Alarm_Menu_Selection_Type)0;
								GLCD_ClearBuffer();
								GLCD_SetMenu(Alarm_Menu_Items,Alarm_Menu_Selection);
								GLCD_Update();
								break;
							}
							
							default:
							{
								break;
							}
						}
						break;
					}
					case Set_Clock:
					{
						HalfSeconds_Count=0;
						HoursTens=HoursTens_New;
						HoursDigits=HoursDigits_New;
						MinutesTens=MinutesTens_New;
						MinutesDigits=MinutesDigits_New;
						Current_Position=Settings_Menu;
						GLCD_ClearBuffer();
						GLCD_SetMenu(Settings_Menu_Items,Settings_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Alarm_Menu:
					{
						switch(Alarm_Menu_Selection)
						{
							case Set_Alarm_Menu_Selected:
							{
								Current_Position=Set_Alarm;
								SetClock_Position=Hours;
								AlarmHoursTens_New=AlarmHoursTens;
								AlarmHoursDigits_New=AlarmHoursDigits;
								AlarmMinutesTens_New=AlarmMinutesTens;
								AlarmMinutesDigits_New=AlarmMinutesDigits;
								GLCD_ClearBuffer();
								GLCD_PrintString(0,17,"Set Alarm");
								GLCD_PrintString(5,0,"Apply");
								GLCD_PrintString(5,60,"Back");
								GLCD_DisplayClock(AlarmHoursTens_New,AlarmHoursDigits_New,AlarmMinutesTens_New,AlarmMinutesDigits_New,1);
								GLCD_DrawRect(SetClock_Position,10,38,26,BLACK);
								GLCD_Update();
								break;
							}
							
							case Remove_Alarm_Menu_Selected:
							{
								Alarm_State=Alarm_Deactivated;
								break;
							}
							
							case Alarm_Tone_Selected:
							{
								Current_Position=Alarm_Tone;
								Alarm_Melody_New=Alarm_Melody;
								Play_Melody(Alarm_Melody_New,Repeat);
								GLCD_ClearBuffer();
								GLCD_SetMenu(Alarm_Tone_Menu_Items,Alarm_Melody_New);
								GLCD_Update();
								break;
							}
						}
						break;
					}
					case Set_Alarm:
					{
						AlarmHoursTens=AlarmHoursTens_New;
						AlarmHoursDigits=AlarmHoursDigits_New;
						AlarmMinutesTens=AlarmMinutesTens_New;
						AlarmMinutesDigits=AlarmMinutesDigits_New;
						Alarm_State=Alarm_Activated;
						Enable_Activate_Alarm=1;
						Current_Position=Alarm_Menu;
						GLCD_ClearBuffer();
						GLCD_SetMenu(Alarm_Menu_Items,Alarm_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Alarm_Tone:
					{
						Current_Position=Alarm_Menu;
						Alarm_Melody=Alarm_Melody_New;
						Stop_Melody();
						GLCD_ClearBuffer();
						GLCD_SetMenu(Alarm_Menu_Items,Alarm_Menu_Selection);
						GLCD_Update();
						break;
					}
					case Games_Menu:
					{
						switch(Games_Menu_Selection)
						{
							case Snake_Selected:
							{
								Current_Position=Snake_Game;
								Snake_Direction=Snake_Right;
								GLCD_ClearBuffer();
								Snake_Init();
								GLCD_Update();
								break;
							}
						}
						break;
					}
					
					case Snake_GameOver:
					{
						Current_Position=Snake_Game;
						Snake_Direction=Snake_Right;
						GLCD_ClearBuffer();
						Snake_Init();
						GLCD_Update();
						break;
					}
				
					case Memo:
					{
							Current_Position=Main_Menu;
							Memo_Save();
							GLCD_ClearBuffer();
							GLCD_SetMenu(Main_Menu_Items,Main_Menu_Selection);
							GLCD_Update();
							break;
					}
					
					case Alarm:
					{
						Enable_Activate_Alarm=1;
						AlarmHoursTens=HoursTens;
						AlarmHoursDigits=HoursDigits;
						AlarmMinutesTens=MinutesTens;
						AlarmMinutesDigits=MinutesDigits;
							
						for(int i=0;i<5;i++)
						{
							AlarmMinutesDigits++;
							if(AlarmMinutesDigits==10)
							{
								AlarmMinutesDigits=0;
								AlarmMinutesTens++;
								if(AlarmMinutesTens==6)
								{
									AlarmMinutesTens=0;
									AlarmHoursDigits++;
									if(AlarmHoursDigits==9)
									{
										AlarmHoursDigits=0;
										AlarmHoursTens++;
									}
								}
							}
							if(AlarmHoursDigits==4 && AlarmHoursTens==2)
							{
								AlarmMinutesDigits=0;
								AlarmMinutesTens=0;
								AlarmHoursDigits=0;
								AlarmHoursTens=0;
							}
						}
						GLCD_BackLight(Previous_BackLight_State);
						Current_Position=Clock;
						Stop_Melody();
						GLCD_ClearBuffer();
						GLCD_DisplayClock(HoursTens,HoursDigits,MinutesTens,MinutesDigits,HalfSeconds_Count);
						GLCD_Update();
						break;
					}

					default:
					{
						break;
					}
				}
				break;
			}
			
			case Back:
			{
				CheckPins_Result_Next.Trigger=Off;
				
				switch(Current_Position)
				{					
					case Main_Menu:
					{
						Current_Position=Clock;
						GLCD_ClearBuffer();
						GLCD_DisplayClock(HoursTens,HoursDigits,MinutesTens,MinutesDigits,Seconds);
						GLCD_Update();
						break;
					}
					case Settings_Menu:
					case Clock_Menu:
					case Games_Menu:
					{
						Current_Position=Main_Menu;
						GLCD_ClearBuffer();
						GLCD_SetMenu(Main_Menu_Items,Main_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Memo:
					{
						Memo_Back();
						Current_Position=Main_Menu;
						GLCD_ClearBuffer();
						GLCD_SetMenu(Main_Menu_Items,Main_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Set_Clock:
					{
						Current_Position=Settings_Menu;
						GLCD_ClearBuffer();
						GLCD_SetMenu(Settings_Menu_Items,Main_Menu_Selection);
						GLCD_Update();
						break;
					}
					case Alarm_Menu:
					{
						Current_Position=Clock_Menu;
						GLCD_ClearBuffer();
						GLCD_SetMenu(Clock_Menu_Items,Clock_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Set_Alarm:
					{
						Current_Position=Alarm_Menu;
						GLCD_ClearBuffer();
						GLCD_SetMenu(Alarm_Menu_Items,Alarm_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Alarm_Tone:
					{
						Stop_Melody();
						Current_Position=Alarm_Menu;
						GLCD_ClearBuffer();
						GLCD_SetMenu(Alarm_Menu_Items,Alarm_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Snake_Game:
					case Snake_GameOver:
					{
						Current_Position=Games_Menu;
						GLCD_ClearBuffer();
						GLCD_SetMenu(Games_Menu_Items,Games_Menu_Selection);
						GLCD_Update();
						break;
					}
					
					case Alarm:
					{
						Current_Position=Clock;
						GLCD_BackLight(Previous_BackLight_State);
						Stop_Melody();
						GLCD_ClearBuffer();
						GLCD_DisplayClock(HoursTens,HoursDigits,MinutesTens,MinutesDigits,Seconds);
						GLCD_Update();
						Alarm_State=Alarm_Deactivated;
						break;
					}
	
					default:
					{
						break;
					}
				}
			}
			case CharacterPressed:
			{
				CheckPins_Result_Next.Trigger=Off;
				
				switch(Current_Position)
				{
					case Memo:
					{
						switch(CheckPins_Result_Current.Keypad_Key)
						{
							case 0:
							{
								break;
							}
							
							case 8:
							{
								Memo_DeleteChar();
								GLCD_Update();
								break;
							}
							
							case 13:
							{
								Memo_NextLine();
								break;
							}
							
							default:
							{
								Memo_PrintChar(CheckPins_Result_Current.Keypad_Key,CheckPins_Result_Current.Keypad_KeyState);
								GLCD_Update();
								break;
							}
						}
						
						break;
					}
					default:
					{
						break;
					}
				}
				break;
			}
			case Refresh_Time:
			{
				CheckPins_Result_Next.Trigger=Off;
				
				Seconds ^= 1;
				HalfSeconds_Count++;
				if(HalfSeconds_Count==120)
				{
					HalfSeconds_Count=0;
					MinutesDigits++;
					if(MinutesDigits==10)
					{
						MinutesDigits=0;
						MinutesTens++;
						if(MinutesTens==6)
						{
							MinutesTens=0;
							HoursDigits++;
							if(HoursDigits==9)
							{
								HoursDigits=0;
								HoursTens++;
							}
						}
					}
				}
				
				if(HoursDigits==4 && HoursTens==2)
				{
						MinutesDigits=0;
						MinutesTens=0;
						HoursDigits=0;
						HoursTens=0;
				}
				
				if(Alarm_State==Alarm_Activated && Enable_Activate_Alarm)
				{		
					if((HoursTens==AlarmHoursTens) && (HoursDigits==AlarmHoursDigits) && (MinutesTens==AlarmMinutesTens) && (MinutesDigits==AlarmMinutesDigits))
					{
						Enable_Activate_Alarm=0;
						Current_Position=Alarm;
						Previous_BackLight_State=GLCD_GetCurrentBackLightState();
						Play_Melody(Alarm_Melody,Repeat);
						GLCD_ClearBuffer();
						GLCD_PrintString(2,24,"ALARM!!!");
						GLCD_PrintString(5,0,"Snooze");
						GLCD_PrintString(5,42,"Dismiss");
						GLCD_Update();
					}
				}
				
				switch(Current_Position)
				{
					case Clock:
					{
						GLCD_ClearBuffer();
						GLCD_DisplayClock(HoursTens,HoursDigits,MinutesTens,MinutesDigits,Seconds);
						GLCD_Update();
						break;
					}
					case Alarm:
					{
						GLCD_BackLight(BackLight_Toggle);
						break;
					}
					
					case Snake_Game:
					{
						Snake_GameState=Snake_MainTask(Snake_Direction);
							if(Snake_GameState==Snake_GameOver_State)
							{
								Current_Position=Snake_GameOver;
								if(Snake_GameState==Snake_GameOver_State)
								{
									Current_Position=Snake_GameOver;
									GLCD_ClearBuffer();
									Snake_GameOver_Task();
								}
							}
						GLCD_Update();
						break;
					}
					
					default:
					{
						break;
					}
				}
				break;
			}
			
			case Check_Pins:
			{
				CheckPins_Result_Next=Check_Pins_Task(ButtonSound_Settings);
				break;
			}
				
			
			case Play_Sound:
			{
				CheckPins_Result_Next.Trigger=Off;
				Sound_Task();
				break;
			}
			default:
			{
				break;
			}
			
		}	
		
		CheckPins_Result_Current=CheckPins_Result_Next;
		
	}
	
	//return 0;
}
