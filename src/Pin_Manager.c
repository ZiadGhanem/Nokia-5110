#include "Pin_Manager.h"
#include "Sound.h"
#include <tm4c123gh6pm.h>

static Keypad_KeyStatus_Type Keypad_GetKey(int Number);

static int Keypad_Rows[]={Keypad_Row0_Pin,Keypad_Row1_Pin,Keypad_Row2_Pin,Keypad_Row3_Pin};
static int Keypad_Columns[]={Keypad_Column0_Pin,Keypad_Column1_Pin,Keypad_Column2_Pin,Keypad_Column3_Pin};
static int Keypad_Timeout_Flag=Keypad_Timeout_Flag_MaxValue;

static int Choose_Debounce_Count=Debounce_Count_OnePress,
						Back_Debounce_Count=Debounce_Count_OnePress,
						Up_Debounce_Count=Debounce_Count_OnePress,
						Down_Debounce_Count=Debounce_Count_OnePress,
						Left_Debounce_Count=Debounce_Count_OnePress,
						Right_Debounce_Count=Debounce_Count_OnePress,
						Choose_FirstTime=1,
						Back_FirstTime=1,
						Up_FirstTime=1,
						Down_FirstTime=1,
						Left_FirstTime=1,
						Right_FirstTime=1;
	
static int Key_Debounce_Count[16]={Debounce_Count_OnePress,Debounce_Count_OnePress,Debounce_Count_OnePress,Debounce_Count_OnePress,
		Debounce_Count_OnePress,Debounce_Count_OnePress,Debounce_Count_OnePress,Debounce_Count_OnePress,
		Debounce_Count_OnePress,Debounce_Count_OnePress,Debounce_Count_OnePress,Debounce_Count_OnePress,
		Debounce_Count_OnePress,Debounce_Count_OnePress,Debounce_Count_OnePress,Debounce_Count_OnePress};
	
static int Keypad_FirstTime[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

void Pin_Setup(void)
{
	SYSCTL->RCGCGPIO |= (1<<1 | 1<<2 | 1<<3);	//Enable clock gating for Pins Port & Sound Port & Keypad Port
	
	//Wait for clock to be enabled
	__ASM volatile("nop");
	__ASM volatile("nop");
	__ASM volatile("nop");
	
	Pins_Port->DEN |= (Up_Pin | Down_Pin | Left_Pin | Right_Pin | Choose_Pin	| Back_Pin);	//Enable digital function for pins
	Pins_Port->PUR |= (Up_Pin | Down_Pin | Left_Pin | Right_Pin | Choose_Pin	| Back_Pin);	//Enable internal pullup resistors for pins

	Sound_Port->AFSEL |= Sound_Pin;
	Sound_Port->PCTL  |= (0x7<<24);
	
	Keypad_ColumnsPort->DIR |= (Keypad_Column0_Pin | Keypad_Column1_Pin | Keypad_Column2_Pin | Keypad_Column3_Pin);
	Keypad_RowsPort->DIR &= ~(Keypad_Row0_Pin | Keypad_Row1_Pin | Keypad_Row2_Pin | Keypad_Row3_Pin);
	
	Keypad_ColumnsPort->DEN |= (Keypad_Column0_Pin | Keypad_Column1_Pin | Keypad_Column2_Pin | Keypad_Column3_Pin);
	Keypad_RowsPort->DEN |= (Keypad_Row0_Pin | Keypad_Row1_Pin | Keypad_Row2_Pin | Keypad_Row3_Pin);
	
	Keypad_RowsPort->PUR |= (Keypad_Row0_Pin | Keypad_Row1_Pin | Keypad_Row2_Pin | Keypad_Row3_Pin);
}


CheckPins_Result_Type Check_Pins_Task(ButtonSound_Settings_Type ButtonSound_Settings)
{
	
	Keypad_KeyStatus_Type Keypad_KeyStatus;
	
	CheckPins_Result_Type CheckPins_Result;
	CheckPins_Result.Trigger=Off;
	
	if(Keypad_Timeout_Flag>0)
	{
		Keypad_Timeout_Flag--;
	}
	
	if(!(Pins_Port->DATA & Choose_Pin))		//If Choose pin was low
		{
			Choose_Debounce_Count--;	//Decrement Choose Count
			
			if(!Choose_Debounce_Count)	//If Count reached zero
			{
				Choose_Debounce_Count=Debounce_Count_ContinuosPress;
				CheckPins_Result.Trigger=Choose;
				
				if(Choose_FirstTime && (ButtonSound_Settings==ButtonSound_Enable))
				{
					Play_Melody(ButtonTick_Sound,No_Repeat);
					Choose_FirstTime=0;
				}
			}
		}
		else
		{
			Choose_Debounce_Count=Debounce_Count_OnePress;
			Choose_FirstTime=1;
		}
		
		
		
		if(!(Pins_Port->DATA & Back_Pin))
		{
			Back_Debounce_Count--;
			
			if(!Back_Debounce_Count)
			{
				Back_Debounce_Count=Debounce_Count_ContinuosPress;
				CheckPins_Result.Trigger=Back;
				if(Back_FirstTime && (ButtonSound_Settings==ButtonSound_Enable))
				{
					Play_Melody(ButtonTick_Sound,No_Repeat);
					Back_FirstTime=0;
				}
			}
		}
		else
		{
			Back_Debounce_Count=Debounce_Count_OnePress;
			Back_FirstTime=1;
		}
		
		
		
		if(!(Pins_Port->DATA & Up_Pin))
		{
			Up_Debounce_Count--;
			
			if(!Up_Debounce_Count)
			{
				Up_Debounce_Count=Debounce_Count_ContinuosPress;
				CheckPins_Result.Trigger=Selection_Up;
				if(Up_FirstTime && (ButtonSound_Settings==ButtonSound_Enable))
				{
					Play_Melody(ButtonTick_Sound,No_Repeat);
					Up_FirstTime=0;
				}
			}
		}
		else
		{
			Up_Debounce_Count=Debounce_Count_OnePress;
			Up_FirstTime=1;
		}
		
		
		
		if(!(Pins_Port->DATA & Down_Pin))
		{
			Down_Debounce_Count--;
			
			if(!Down_Debounce_Count)
			{
				Down_Debounce_Count=Debounce_Count_ContinuosPress;
				CheckPins_Result.Trigger=Selection_Down;
				if(Down_FirstTime && (ButtonSound_Settings==ButtonSound_Enable))
				{
					Play_Melody(ButtonTick_Sound,No_Repeat);
					Down_FirstTime=0;
				}
			}
		}
		else
		{
			Down_Debounce_Count=Debounce_Count_OnePress;
			Down_FirstTime=1;
		}
		
		
		
		if(!(Pins_Port->DATA & Left_Pin))
		{
			Left_Debounce_Count--;
			
			if(!Left_Debounce_Count)
			{
				Left_Debounce_Count=Debounce_Count_ContinuosPress;
				CheckPins_Result.Trigger=Selection_Left;
				if(Left_FirstTime && (ButtonSound_Settings==ButtonSound_Enable))
				{
					Play_Melody(ButtonTick_Sound,No_Repeat);
					Left_FirstTime=0;
				}
			}
		}
		else
		{
			Left_Debounce_Count=Debounce_Count_OnePress;
			Left_FirstTime=1;
		}
		
		
		
		if(!(Pins_Port->DATA & Right_Pin))
		{
			Right_Debounce_Count--;
			
			if(!Right_Debounce_Count)
			{
				Right_Debounce_Count=Debounce_Count_ContinuosPress;
				CheckPins_Result.Trigger=Selection_Right;
				if(Right_FirstTime && (ButtonSound_Settings==ButtonSound_Enable))
				{
					Play_Melody(ButtonTick_Sound,No_Repeat);
					Right_FirstTime=0;
				}
			}
		}
		else
		{
			Right_Debounce_Count=Debounce_Count_OnePress;
			Right_FirstTime=1;
		}
		
		for(int Column=0;Column<4;Column++)
		{
			Keypad_ColumnsPort->DATA |= ( Keypad_Columns[0] | Keypad_Columns[1] | Keypad_Columns[2] | Keypad_Columns[3]);
			Keypad_ColumnsPort->DATA &= ~(Keypad_Columns[Column]);
			
			for(int Row=0;Row<4;Row++)
			{
				int Keypad_NumberofButton=(Row*4)+Column;

				if(!(Keypad_RowsPort->DATA & Keypad_Rows[Row]))
				{
					Key_Debounce_Count[Keypad_NumberofButton]--;

					if(!Key_Debounce_Count[Keypad_NumberofButton])
					{
						if(Keypad_FirstTime[Keypad_NumberofButton] && (ButtonSound_Settings==ButtonSound_Enable))
						{
							Play_Melody(ButtonTick_Sound,No_Repeat);
							Keypad_FirstTime[Keypad_NumberofButton]=0;
						}
						
						Keypad_KeyStatus=Keypad_GetKey(Keypad_NumberofButton+1);
						CheckPins_Result.Trigger=CharacterPressed;
					}
				}

				else
				{
					Key_Debounce_Count[Keypad_NumberofButton]=Debounce_Count_OnePress;
					Keypad_FirstTime[Keypad_NumberofButton]=1;
				}
			}
		}

		CheckPins_Result.Keypad_Key=Keypad_KeyStatus.Keypad_Key;
		CheckPins_Result.Keypad_KeyState=Keypad_KeyStatus.Keypad_KeyState;
	
		return CheckPins_Result;
}



Keypad_KeyStatus_Type Keypad_GetKey(int Number)
{
	Keypad_KeyStatus_Type Keypad_KeyStatus;
	
	static int PreviousNumber=0,Count_Value=0,Enable_Capitalization=0;

	if((PreviousNumber!=Number) || (Keypad_Timeout_Flag==0))
	{
		Keypad_KeyStatus.Keypad_KeyState=Keypad_NewKey;
		Keypad_Timeout_Flag=Keypad_Timeout_Flag_MaxValue;
		Count_Value=0;
	}
	
	else
	{
		Keypad_KeyStatus.Keypad_KeyState=Keypad_OldKey;
	}
	
	PreviousNumber=Number;

	switch(Number)
	{
		case 1:
		{
			Keypad_KeyStatus.Keypad_Key='1';
			break;
		}


		case 2:
		{
			switch(Enable_Capitalization)
			{
				case 0:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='a';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='b';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='c';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='2';
							break;
						}
					}

					break;
				}
				
				default:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='A';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='B';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='C';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='2';
							break;
						}
					}
					
					break;
					}
			}
			
			break;
		}

		case 3:
		{
			switch(Enable_Capitalization)
			{
				case 0:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='d';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='e';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='f';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='3';
							break;
						}
					}

					break;
				}
				
				default:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='D';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='E';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='F';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='3';
							break;
						}
					}
					
					break;
					}
			}
			
			break;
		}

		case 5:
		{
			switch(Enable_Capitalization)
			{
				case 0:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='g';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='h';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='i';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='4';
							break;
						}
					}

					break;
				}
				
				default:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='G';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='H';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='I';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='4';
							break;
						}
					}
					
					break;
					}
			}
			
			break;
		}

		case 6:
		{
			switch(Enable_Capitalization)
			{
				case 0:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='j';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='k';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='l';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='5';
							break;
						}
					}

					break;
				}
				
				default:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='J';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='K';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='L';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='5';
							break;
						}
					}
					
					break;
					}
			}
			
			break;
		}

		
		case 7:
		{
			switch(Enable_Capitalization)
			{
				case 0:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='m';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='n';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='o';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='6';
							break;
						}
					}

					break;
				}
				
				default:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='M';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='N';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='O';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='6';
							break;
						}
					}
					
					break;
					}
			}
			
			break;
		}

		case 9:
		{
			switch(Enable_Capitalization)
			{
				case 0:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='p';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='q';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='r';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='s';
							break;
						}
						
						case 4:
						{
							Keypad_KeyStatus.Keypad_Key='7';
							break;
						}
					}

					break;
				}
				
				default:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='P';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='Q';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='R';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='S';
							break;
						}
						
						case 4:
						{
							Keypad_KeyStatus.Keypad_Key='7';
							break;
						}
					}
					
					break;
					}
			}
			
			break;
		}

		case 10:
		{
			switch(Enable_Capitalization)
			{
				case 0:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='t';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='u';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='v';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='8';
							break;
						}
					}

					break;
				}
				
				default:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='T';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='U';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='V';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='8';
							break;
						}
					}
					
					break;
					}
			}
			
			break;
		}

		case 11:
		{
			switch(Enable_Capitalization)
			{
				case 0:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='w';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='x';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='y';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='z';
							break;
						}
						
						case 4:
						{
							Keypad_KeyStatus.Keypad_Key='9';
							break;
						}
					}

					break;
				}
				
				default:
				{
					switch(Count_Value)
					{
						case 0:
						{
							Keypad_KeyStatus.Keypad_Key='W';
							break;
						}

						case 1:
						{
							Keypad_KeyStatus.Keypad_Key='X';
							break;
						}

						case 2:
						{
							Keypad_KeyStatus.Keypad_Key='Y';
							break;
						}

						case 3:
						{
							Keypad_KeyStatus.Keypad_Key='Z';
							break;
						}
						
						case 4:
						{
							Keypad_KeyStatus.Keypad_Key='9';
							break;
						}
					}
					
					break;
					}
			}
			
			break;
		}

		case 13:
		{
			Keypad_KeyStatus.Keypad_Key='*';
			Keypad_KeyStatus.Keypad_KeyState=Keypad_NewKey;
			break;
		}

		case 14:
		{
			Keypad_KeyStatus.Keypad_Key='0';
			Keypad_KeyStatus.Keypad_KeyState=Keypad_NewKey;
			break;
		}
		
		case 15:
		{
			Keypad_KeyStatus.Keypad_Key='#';
			Keypad_KeyStatus.Keypad_KeyState=Keypad_NewKey;
			break;
		}
		
		case 4:
		{
			Enable_Capitalization=~Enable_Capitalization;
			Keypad_KeyStatus.Keypad_KeyState=Keypad_NewKey;
			Keypad_KeyStatus.Keypad_Key=0;
			break;
		}
		
		case 8:
		{
			Keypad_KeyStatus.Keypad_Key=' ';
			Keypad_KeyStatus.Keypad_KeyState=Keypad_NewKey;
			break;
		}
		
		case 16:
		{
			Keypad_KeyStatus.Keypad_Key=13; //New Line
			Keypad_KeyStatus.Keypad_KeyState=Keypad_NewKey;
			break;
		}
		
		case 12:
		{
			Keypad_KeyStatus.Keypad_Key=8;	//BackSpace
			Key_Debounce_Count[11]=Debounce_Count_ContinuosPress;
			break;
		}
	
	}
	
	if(((Count_Value<4) && ((Number==9) || (Number==11))) || ((Count_Value<3) && ((Number!=9) || (Number!=11))))
	{
		Count_Value++;
	}
	else
	{
		Count_Value=0;
	}

	return Keypad_KeyStatus;

}
