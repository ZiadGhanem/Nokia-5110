#ifndef GLCD_H_
#define GLCD_H_

#include "SPI.h"
#include "Std_Types.h"

#define GLCD_PORT	GPIOA

typedef enum{
	BackLight_Off,
	BackLight_On,
	BackLight_Toggle
}BackLight_Settings;

#define GLCD_BL		(1<<4)
#define GLCD_DC		(1<<6)
#define GLCD_RST	(1<<7)

#define GLCD_DATA 	1
#define GLCD_CMD  	0
#define GLCD_HEIGHT 48
#define GLCD_WIDTH	84
#define GLCD_ROWS		6
#define GLCD_SIZE		504
#define BLACK		1
#define WHITE		0

extern void GLCD_Init(void);
extern void GLCD_BackLight(BackLight_Settings BackLight_Config);
extern BackLight_Settings GLCD_GetCurrentBackLightState(void);
extern void GLCD_Send(unsigned char Data_CMD,unsigned char Byte);
extern void GLCD_SetContrast(unsigned char Contrast);
extern void GLCD_SetPosition(unsigned char Row,unsigned char Column);
extern void GLCD_Clear(void);
extern void GLCD_ClearBuffer(void);
extern void GLCD_Update(void);
extern void GLCD_SetPixel(unsigned char X,unsigned char Y,unsigned char BW);
extern void GLCD_PrintNumber(unsigned char Row,unsigned char Column,int Number);
extern void GLCD_PrintString(unsigned char Row,unsigned char Column,char *String);
extern void GLCD_DrawLine(unsigned char X1,unsigned char Y1,unsigned char X2,unsigned char Y2,unsigned char BW);
extern void GLCD_DrawRect(unsigned char X,unsigned char Y,unsigned char Width,unsigned char Height,unsigned char BW);
extern void GLCD_FillRect(unsigned char X,unsigned char Y,unsigned char Width,unsigned char Height,unsigned char BW);
extern void GLCD_DrawCircle(unsigned char X_Center,unsigned char Y_Center,unsigned char Radius,unsigned char BW);
extern void GLCD_DrawImage(const unsigned char Image[][84]);
extern void GLCD_SetMenu(char *String,int Selection);
extern void GLCD_DisplayClock(int Hours_H,int Hours_L,int Minutes_H,int Minutes_L,int Seconds);


extern void Memo_PrintChar(char Character,Keypad_KeyState_Type Keypad_KeyState);
extern void Memo_DeleteChar(void);
extern void Memo_NextLine(void);
extern void Memo_Save(void);
extern void Memo_Update(void);
extern void Memo_Back(void);


#endif
