#include <tm4c123gh6pm.h>
#include <stdlib.h>
#include "GLCD.h"
#include "Snake.h"

static uint16_t Get_Next_Node(uint16_t This_Node);
static uint16_t Get_Previous_Node(uint16_t This_Node);
static uint8_t Snake_Detect_Collision(Point Target);
static void Change_Snake_Direction(Snake_Direction_Type Snake_Direction);
static uint8_t Absolute_Difference(uint8_t A, uint8_t B);
static uint8_t Are_Neighbours(Point Node_1,Point Node_2);
static void Make_Fruit(void);
static uint8_t Snake_Ate_Fruit(uint8_t X, uint8_t Y);
static Snake_GameState_Type Snake_Move_Head(Snake_Direction_Type Snake_Direction);
static void Snake_Follow_Tail(void);
static void Snake_Draw(uint8_t X1,uint8_t Y1,uint8_t X2,uint8_t Y2,uint8_t BW);

static Point Snake_Corners[Max_Nodes];

static Point Fruit;

static uint16_t Snake_Head,
							Snake_Tail,
							Snake_Current_Length,
							Snake_Limit_Length,
							Snake_GameScore,
							Snake_GameTopScore=0;

static int8_t Direction_X,
							Direction_Y;

void Snake_Draw(uint8_t X1,uint8_t Y1,uint8_t X2,uint8_t Y2,uint8_t BW)
{
	for(int i=X1;i<=X2;i++)
	{
		for(int j=Y1;j<=Y2;j++)
		{
			GLCD_SetPixel(i,j,BW);
		}
	}
}


uint16_t Get_Next_Node(uint16_t This_Node)
{
  uint16_t Next_Node = This_Node + 1;
	
  if (Next_Node>=Max_Nodes)
	{
		Next_Node = 0;
	}
	
  return Next_Node;  
}

uint16_t Get_Previous_Node(uint16_t This_Node)
{
  if (This_Node)
	{
		return This_Node-1;  // thisNode is not zero so just decrement
	}
	else
	{
		return Max_Nodes-1; //thisNode is zero so go around the bend
	}
}

uint8_t Absolute_Difference(uint8_t A, uint8_t B)
{
  int16_t Unknown = (int16_t)A - B;
  return (uint8_t)((Unknown<0)? -Unknown:Unknown); 
}

uint8_t Are_Neighbours(Point Node_1,Point Node_2)
{
  if ((Absolute_Difference(Node_1.X,Node_2.X) == 1) || (Absolute_Difference(Node_1.Y,Node_2.Y) == 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Change_Snake_Direction(Snake_Direction_Type Snake_Direction)
{
	switch(Snake_Direction)
	{
		case Snake_Up:
		{
			Direction_X=0;
			Direction_Y=-1;
			break;
		}
		case Snake_Down:
		{
			Direction_X=0;
			Direction_Y=1;
			break;
		}
		case Snake_Left:
		{
			Direction_X=-1;
			Direction_Y=0;
			break;
		}
		case Snake_Right:
		{
			Direction_X=1;
			Direction_Y=0;
			break;
		}
	}
}

void Make_Fruit(void)
{
  while (1)
	{
    Fruit.X = (uint16_t)(rand()%(Snake_GameBoard_X-1));
    Fruit.Y = (uint16_t)(rand()%(Snake_GameBoard_Y-1));
    if ((!(Snake_Detect_Collision(Fruit))) && (Fruit.X) && (Fruit.Y))
		{
			break;
		}
  }
	
	Snake_Draw(Fruit.X*Snake_Girth,
						Fruit.Y*Snake_Girth,
						(Fruit.X*Snake_Girth)+Snake_Girth-1,
						(Fruit.Y*Snake_Girth)+Snake_Girth-1,
						BLACK);
}

uint8_t Snake_Ate_Fruit(uint8_t X, uint8_t Y)
{
  if((Fruit.X == X) && (Fruit.Y == Y))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


Snake_GameState_Type Snake_Move_Head(Snake_Direction_Type Snake_Direction)
{
	Snake_GameState_Type GameState=Snake_GameRunning_State;
	
	//Copy snake head to new position
	Snake_Head = Get_Next_Node(Snake_Head); //increment head
	Snake_Corners[Snake_Head]= Snake_Corners[Get_Previous_Node(Snake_Head)];
	Change_Snake_Direction(Snake_Direction);  //change direction
  
  //Have we left the game board?
  if (
			((Snake_Corners[Snake_Head].X == 1) && (Direction_X == -1)) ||
			((Snake_Corners[Snake_Head].Y == 1) && (Direction_Y == -1))	||
			((Snake_Corners[Snake_Head].X == Snake_GameBoard_X) && (Direction_X == 1)) ||
			((Snake_Corners[Snake_Head].Y == Snake_GameBoard_Y) && (Direction_Y == 1))
		)
	{
		GameState=Snake_GameOver_State;
	}
	
	else
	{
		Snake_Corners[Snake_Head].X += Direction_X;
		Snake_Corners[Snake_Head].Y += Direction_Y;
		Snake_Current_Length++;
	}
	
	return GameState;
}

void Snake_Follow_Tail(void)
{
  Snake_Current_Length--;
	
  //Is tail a neighbor of next?
  if (Are_Neighbours(Snake_Corners[Snake_Tail],Snake_Corners[Get_Next_Node(Snake_Tail)]))
  {
    Snake_Tail = Get_Next_Node(Snake_Tail);
  }
  
  //Find which axis tail and next have in common
  else
  {
    if (Snake_Corners[Snake_Tail].X == Snake_Corners[Get_Next_Node(Snake_Tail)].X)
    {
      //These points have the same X, so make adjustment to the Y
      if ((Snake_Corners[Snake_Tail].Y - Snake_Corners[Get_Next_Node(Snake_Tail)].Y) < 0)
			{
				(Snake_Corners[Snake_Tail].Y) ++;
			}
      else
			{
				(Snake_Corners[Snake_Tail].Y)--; 
			}
    }
		
    else
    {
      //These points have the same Y, so make adjustment to the X
      if ((Snake_Corners[Snake_Tail].X - Snake_Corners[Get_Next_Node(Snake_Tail)].X) < 0)
			{
				(Snake_Corners[Snake_Tail].X)++;
			}
      else
			{
				(Snake_Corners[Snake_Tail].X)--;
			}
    }
  }
}


uint8_t  Snake_Detect_Collision(Point Target)
{
  uint16_t Lower = 0;
  uint16_t Upper = 0;
  uint16_t Test_Point = 1;
  uint16_t i=Snake_Tail;
  uint16_t Next_Node = Get_Next_Node(i);

  //Check to see if we hit part of the snake
  //traverse all nodes from tail forward
  while(Next_Node<(Snake_Head-3))
  { 
    //check to see if head's x or y are shared with the current point
    if ((Target.X == Snake_Corners[i].X) && (Snake_Corners[i].X == Snake_Corners[Next_Node].X))
    {
      //which point is the higher  number?
      if(Snake_Corners[i].Y < Snake_Corners[Next_Node].Y)
			{
				Lower = Snake_Corners[i].Y;
				Upper = Snake_Corners[Next_Node].Y;
			}
      else
			{
				Lower = Snake_Corners[Next_Node].Y;
				Upper = Snake_Corners[i].Y;
			}
			
			Test_Point = Target.Y;
		}
    else if ((Target.Y == Snake_Corners[i].Y) && (Snake_Corners[i].Y == Snake_Corners[Next_Node].Y))
    {
      //which point is the higher  number?
      if(Snake_Corners[i].X < Snake_Corners[Next_Node].X)
			{
				Lower = Snake_Corners[i].X;
				Upper = Snake_Corners[Next_Node].X;
			}
      else
			{
				Lower = Snake_Corners[Next_Node].X;
				Upper = Snake_Corners[i].X;
			}
			
      Test_Point = Target.X;
    }
    
    //Now check to see if head is a point between this node and the next
    if ((Test_Point>=Lower) && (Test_Point<=Upper))
		{
			return 1;
    }
		
    i = Next_Node;
    Next_Node = Get_Next_Node(i);
  }
	
  return 0;
}


void Snake_Init(void)
{
	Snake_GameScore=0;
  Snake_Tail = 0;
  Snake_Head = 1;
  Direction_Y = 0;
  Direction_X = 1;
	Snake_Limit_Length = 6;
  Snake_Current_Length = Snake_Limit_Length;
  Snake_Corners[Snake_Head].X = 4+Snake_Current_Length;
  Snake_Corners[Snake_Head].Y = 4;
	Snake_Corners[Snake_Tail].X = 4;
  Snake_Corners[Snake_Tail].Y = 4;
	
	GLCD_DrawRect(0,0,GLCD_WIDTH-2,GLCD_HEIGHT-2,BLACK);
	
	Snake_Draw(Snake_Corners[Snake_Tail].X*Snake_Girth,
									Snake_Corners[Snake_Tail].Y*Snake_Girth,
									(Snake_Corners[Snake_Head].X*Snake_Girth)+Snake_Girth-1,
									(Snake_Corners[Snake_Head].Y*Snake_Girth)+Snake_Girth-1,
										BLACK);
	
  srand((uint16_t)(TIMER0->TAV));
	
  Make_Fruit();
}


Snake_GameState_Type Snake_MainTask(Snake_Direction_Type Snake_Direction)
{ 
	Snake_GameState_Type GameState=Snake_GameRunning_State;
	
	GameState=Snake_Move_Head(Snake_Direction);
	
	if ((Snake_Ate_Fruit(Snake_Corners[Snake_Head].X,Snake_Corners[Snake_Head].Y)))
	{
		Snake_GameScore++;
		Snake_Limit_Length += 2;
		Make_Fruit();
	}
	
	if (Snake_Detect_Collision(Snake_Corners[Snake_Head]))
	{
		GameState=Snake_GameOver_State;
	}
	
	else
	{
		Snake_Draw(Snake_Corners[Snake_Head].X*Snake_Girth,
									Snake_Corners[Snake_Head].Y*Snake_Girth,
									(Snake_Corners[Snake_Head].X*Snake_Girth)+Snake_Girth-1,
									(Snake_Corners[Snake_Head].Y*Snake_Girth)+Snake_Girth-1,
										BLACK);
		
		if (Snake_Current_Length > Snake_Limit_Length)
		{
			Snake_Draw(Snake_Corners[Snake_Tail].X*Snake_Girth,
									Snake_Corners[Snake_Tail].Y*Snake_Girth,
									(Snake_Corners[Snake_Tail].X*Snake_Girth)+Snake_Girth-1,
									(Snake_Corners[Snake_Tail].Y*Snake_Girth)+Snake_Girth-1,
									WHITE); //Erase
			Snake_Follow_Tail();
		}
	}  
	
	return GameState;
}



void Snake_GameOver_Task(void)
{
	if(Snake_GameScore>Snake_GameTopScore)
	{
		Snake_GameTopScore=Snake_GameScore;
	}
	GLCD_PrintString(0,14,"Game Over!!!");
	GLCD_PrintString(2,20,"Score:");
	GLCD_PrintNumber(2,53,Snake_GameScore);
	GLCD_PrintString(3,10,"Top Score:");
	GLCD_PrintNumber(3,63,Snake_GameTopScore);
	GLCD_PrintString(5,0,"Retry");
	GLCD_PrintString(5,60,"Back");
}













