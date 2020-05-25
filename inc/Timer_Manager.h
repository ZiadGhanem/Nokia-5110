#ifndef TIMER_MANAGER_H_
#define TIMER_MANAGER_H_

#include "Std_Types.h"


#define System_Timer			TIMER0


extern void Timer_Setup(void);
extern Trigger_Type Time_Task(void);

#endif
