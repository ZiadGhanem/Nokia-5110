#ifndef PIN_MANAGER_H_
#define PIN_MANAGER_H_

#include "Std_Types.h"

#define Pins_Port							GPIOB
#define Sound_Port						GPIOD
#define Keypad_ColumnsPort		GPIOD
#define Keypad_RowsPort				GPIOC

#define Down_Pin					(1<<0)
#define Up_Pin 						(1<<1)
#define Right_Pin					(1<<2)
#define Left_Pin					(1<<3)
#define Choose_Pin				(1<<4)
#define Back_Pin					(1<<5)

#define Sound_Pin					(1<<6)

#define Keypad_Column0_Pin		(1<<3)
#define Keypad_Column1_Pin		(1<<2)
#define Keypad_Column2_Pin		(1<<1)
#define Keypad_Column3_Pin		(1<<0)

#define Keypad_Row0_Pin		(1<<7)
#define Keypad_Row1_Pin		(1<<6)
#define Keypad_Row2_Pin		(1<<5)
#define Keypad_Row3_Pin		(1<<4)

#define Debounce_Count_OnePress				10
#define Debounce_Count_ContinuosPress	75

#define Keypad_Timeout_Flag_MaxValue	500

typedef enum{ButtonSound_Disable,ButtonSound_Enable}ButtonSound_Settings_Type;


extern CheckPins_Result_Type Check_Pins_Task(ButtonSound_Settings_Type ButtonSound_Settings);
extern void Pin_Setup(void);

#endif
