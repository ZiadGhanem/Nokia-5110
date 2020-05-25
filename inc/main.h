#ifndef MAIN_H_
#define MAIN_H_

typedef enum{Settings_Menu_Selected,Clock_Menu_Selected,Games_Selected,Memo_Selected}Main_Menu_Selection_Type;
typedef enum{BackLight_Selected,Set_Clock_Menu_Selected,ButtonSound_Selected}Settings_Menu_Selection_Type;
typedef enum{Alarm_Menu_Selected}Clock_Menu_Selection_Type;
typedef enum{Set_Alarm_Menu_Selected,Remove_Alarm_Menu_Selected,Alarm_Tone_Selected}Alarm_Menu_Selection_Type;
typedef enum{Snake_Selected}Games_Menu_Selection_Type;

#define Main_Menu_Max_Selection			(Main_Menu_Selection_Type)3
#define Settings_Menu_Max_Selection (Settings_Menu_Selection_Type)2
#define Clock_Menu_Max_Selection		(Clock_Menu_Selection_Type)0
#define Alarm_Menu_Max_Selection 		(Alarm_Menu_Selection_Type)2
#define Games_Menu_Max_Selection		(Games_Menu_Selection_Type)0

#endif
