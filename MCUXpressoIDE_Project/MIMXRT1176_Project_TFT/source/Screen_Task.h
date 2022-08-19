#ifndef SCREEN_TASK_H
#define SCREEN_TASK_H

//#include "_stdint.h"

typedef struct struct_RtcTime
{
	// time of day
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;

	// date
	uint8_t day;
	uint8_t month;
	uint16_t year;

	//May 24, 2022

} RtcTimeType;

// Animate the Teltail LED
void Screen_teltail_Animate(void);

// Animate the Clock & Date
void RTC_Init(void);
void RTC_Animate(void);
void Screen_date_Time_update(void);

//update speed on screen
void Screen_speed_update(void);

//update ODO on screen
void ODO_Animate(void);
void Screen_ODO_update(void);
void Screen_ODO_hide(void);

extern uint8_t cluster_Odo_0;
extern uint8_t cluster_Odo_1;
extern uint8_t cluster_Odo_2;
extern uint8_t cluster_Odo_3;
extern uint8_t cluster_Odo_4;
extern uint8_t cluster_Odo_5;
extern uint8_t cluster_Odo_6;

extern uint8_t cluster_Odo_0_update_flag;
extern uint8_t cluster_Odo_1_update_flag;
extern uint8_t cluster_Odo_2_update_flag;
extern uint8_t cluster_Odo_3_update_flag;
extern uint8_t cluster_Odo_4_update_flag;
extern uint8_t cluster_Odo_5_update_flag;
extern uint8_t cluster_Odo_6_update_flag;

#endif
