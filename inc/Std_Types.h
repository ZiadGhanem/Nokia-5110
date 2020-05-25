#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef enum{
	Off,
	Choose,
	Back,
	Selection_Up,
	Selection_Down,
	Selection_Left,
	Selection_Right,
	CharacterPressed,
	Refresh_Time,
	Check_Pins,
	Play_Sound
}Trigger_Type;

typedef enum{Keypad_NewKey,Keypad_OldKey}Keypad_KeyState_Type;

typedef struct{
	Keypad_KeyState_Type Keypad_KeyState;
	char Keypad_Key;
}Keypad_KeyStatus_Type;

typedef struct
{
	Trigger_Type Trigger;
	Keypad_KeyState_Type Keypad_KeyState;
	char Keypad_Key;
}CheckPins_Result_Type;


#endif
