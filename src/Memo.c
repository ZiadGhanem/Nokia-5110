#include "Memo.h"
#include "GLCD.h"
#include <tm4c123gh6pm.h>



void GLCD_PrintChar(char Character,Keypad_KeyState_Type Keypad_KeyState)
{
	int Count;
	static char Current_Row=0,Current_Column=0,Old_Row=0,Old_Column=0;
	
	static Characters_Structure *PtrOldChar;
	Characters_Structure *PtrNewChar;
	PtrNewChar=&ASCII[Character];
	
	if(Keypad_KeyState==Keypad_OldKey)
	{
		for(Count=Old_Column;Count<(Old_Column+(PtrOldChar->Length));Count++)
		{
			Buffer[Old_Row][Count]=0;
		}
		
		Current_Row=Old_Row;
		Current_Column=Old_Column;
	}
	
	else
	{
		Old_Row=Current_Row;
		Old_Column=Current_Column;
		PtrOldChar=PtrNewChar;
	}
		
	if(Current_Column > GLCD_WIDTH-(PtrNewChar->Length))
	{
		Current_Column = 0;
		Current_Row ++;
		if(Current_Row==GLCD_ROWS)
		{
			Current_Row=0;
			Current_Column=0;
		}
	}
	
	for(Count=0;Count<(PtrNewChar->Length);Count++)
	{
		Buffer[Current_Row][Current_Column]=(PtrNewChar->Data)[Count];
		Current_Column++;
	}
}