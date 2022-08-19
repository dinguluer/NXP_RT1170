#ifndef DRAW_TASK_H
#define DRAW_TASK_H

//#include "_stdint.h"

typedef struct struct_RtcTime_draw
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

} draw_RtcTimeType;


// Animate the Clock & Date
void draw_RTC_Init(void);
void draw_RTC_Animate(void);
void draw_date_Time_update(void);

#endif
