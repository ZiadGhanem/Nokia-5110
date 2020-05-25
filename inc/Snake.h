#ifndef SNAKE_H_
#define SNAKE_H_

#include "Std_Types.h"

#define Max_Nodes 300
#define Snake_Girth		2
#define Snake_GameBoard_X	((GLCD_WIDTH-3)/Snake_Girth)
#define Snake_GameBoard_Y	((GLCD_HEIGHT-3)/Snake_Girth)

typedef struct{
	uint8_t X;
	uint8_t Y;
}Point;

typedef enum{
Snake_Up,
Snake_Down,
Snake_Left,
Snake_Right,
}Snake_Direction_Type;

typedef enum{Snake_GameRunning_State,Snake_GameOver_State}Snake_GameState_Type;

extern void Snake_Init(void);
extern Snake_GameState_Type Snake_MainTask(Snake_Direction_Type Snake_Direction);
extern void Snake_GameOver_Task(void);


#endif
