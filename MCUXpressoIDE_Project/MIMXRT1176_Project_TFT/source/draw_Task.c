#include "fsl_debug_console.h"
#include "lvgl_support.h"
#include "pin_mux.h"
#include "board.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

#include "fsl_soc_src.h"

// dinesh added
#include "fsl_pit.h"
//dinesh added
#include "Dinesh_TFT_PinConfig.h"

#include "draw_Task.h"

extern lv_ui guider_ui;

// Program ROM constants
static uint8_t draw_MonthDayTable[] = {31,28,31,30,31,30,31,31,30,31,30,31};
//char date[] = "May 24, 2022";
char date_month[]= "Jan";
char date_day[] ="01";
char date_year[] = "2022";
char draw_time_hour[] = "10";
char draw_time_min[] = "09";

uint8_t toggle_colon = 0;

// Global variables
// time registers
draw_RtcTimeType draw_RtcTime;

void draw_RTC_Init(void)
{
	// set up timer for RTC operation
	draw_RtcTime.seconds = 0;
	draw_RtcTime.minutes = 10;
	draw_RtcTime.hours = 10;

	draw_RtcTime.day = 23;
	draw_RtcTime.month = 8;
	draw_RtcTime.year = 2022;
}

// Animate the Clock & Date
void draw_RTC_Animate(void)
{
	draw_RtcTime.seconds++;                                                      // increment seconds
	if(draw_RtcTime.seconds > 59)                                        // check seconds overflow
	{
		draw_RtcTime.seconds -= 60;
		draw_RtcTime.minutes++;                                              // increment minutes
		if(draw_RtcTime.minutes > 59)                                // check minutes overflow
		{
			draw_RtcTime.minutes -= 60;
			draw_RtcTime.hours++;                                                // increment hours
			if(draw_RtcTime.hours > 23)                          // check hours overflow
			{
				draw_RtcTime.hours -= 24;
				draw_RtcTime.day++;                                          // increment days
				if(draw_RtcTime.day == draw_MonthDayTable[draw_RtcTime.month-1])// check days overflow
				{
					draw_RtcTime.day = 1;
					draw_RtcTime.month++;                                // increment months
					if(draw_RtcTime.month == 13)         // check months overflow
					{
						draw_RtcTime.month = 1;
						draw_RtcTime.year++;                 // increment years
					}
				}
			}
		}
	}

}


// Convert Month to text name
void draw_convert_Month_to_Text (void)
{
	if(draw_RtcTime.month == 1)
	{
		date_month[0] = 'J';
		date_month[1] = 'a';
		date_month[2] = 'n';
	}
	else if(draw_RtcTime.month == 2)
	{
		date_month[0] = 'F';
		date_month[1] = 'e';
		date_month[2] = 'b';
	}
	else if(draw_RtcTime.month == 3)
	{
		date_month[0] = 'M';
		date_month[1] = 'a';
		date_month[2] = 'r';
	}
	else if(draw_RtcTime.month == 4)
	{
		date_month[0] = 'A';
		date_month[1] = 'p';
		date_month[2] = 'r';
	}
	else if(draw_RtcTime.month == 5)
	{
		date_month[0] = 'M';
		date_month[1] = 'a';
		date_month[2] = 'y';
	}
	else if(draw_RtcTime.month == 6)
	{
		date_month[0] = 'J';
		date_month[1] = 'u';
		date_month[2] = 'n';
	}
	else if(draw_RtcTime.month == 7)
	{
		date_month[0] = 'J';
		date_month[1] = 'u';
		date_month[2] = 'l';
	}
	else if(draw_RtcTime.month == 8)
	{
		date_month[0] = 'A';
		date_month[1] = 'u';
		date_month[2] = 'g';
	}
	else if(draw_RtcTime.month == 9)
	{
		date_month[0] = 'S';
		date_month[1] = 'e';
		date_month[2] = 'p';
	}
	else if(draw_RtcTime.month == 10)
	{
		date_month[0] = 'O';
		date_month[1] = 'c';
		date_month[2] = 't';
	}
	else if(draw_RtcTime.month == 11)
	{
		date_month[0] = 'N';
		date_month[1] = 'o';
		date_month[2] = 'v';
	}
	else if(draw_RtcTime.month == 12)
	{
		date_month[0] = 'D';
		date_month[1] = 'e';
		date_month[2] = 'c';
	}
	else
	{
		// Nop
	}

}

// Convert Day-Decimal to day-char
void draw_convert_day_to_Text(void)
{

	date_day[0] = (draw_RtcTime.day / 10) + 0x30;
	date_day[1] = (draw_RtcTime.day % 10) + 0x30;

}

// Convert year-Decimal to year-char
void draw_convert_year_to_Text(void)
{
    // 8,9,10,11
	date_year[3] = (draw_RtcTime.year % 10) + 0x30;
	date_year[2] = ((draw_RtcTime.year/10) % 10) + 0x30;
	date_year[1]  = ((draw_RtcTime.year/100) % 10) + 0x30;
	date_year[0]  = ((draw_RtcTime.year/1000) % 10) + 0x30;

}

// Convert time-Decimal to time-char
void draw_convert_Time_to_Text(void)
{
	// hour
	draw_time_hour[0] = (draw_RtcTime.hours / 10) + 0x30;
	draw_time_hour[1] = (draw_RtcTime.hours % 10) + 0x30;
	// min
	draw_time_min[0] = (draw_RtcTime.minutes / 10) + 0x30;
	draw_time_min[1] = (draw_RtcTime.minutes % 10) + 0x30;
}

//update time on screen
void draw_date_Time_update(void)
{
	//set date
	draw_convert_Month_to_Text();
	draw_convert_day_to_Text();
	draw_convert_year_to_Text();
	lv_label_set_text(guider_ui.screen_drawing_Date_Label_drawing, date_month);
	lv_label_set_text(guider_ui.screen_drawing_Date_Label_drawing_0, date_day);
	lv_label_set_text(guider_ui.screen_drawing_Date_Label_drawing_2, date_year);

	if(toggle_colon)
	{
//		lv_obj_clear_flag(guider_ui.screen_drawing_canvas_triangle_L_1, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.screen_drawing_Time_level_drawing_0, ":");
		toggle_colon = 0;
	}
	else
	{
//		lv_obj_add_flag(guider_ui.screen_drawing_canvas_triangle_L_1, LV_OBJ_FLAG_HIDDEN);
		lv_label_set_text(guider_ui.screen_drawing_Time_level_drawing_0, " ");
		toggle_colon = 1;
	}
	//set time
	draw_convert_Time_to_Text();
	lv_label_set_text(guider_ui.screen_drawing_Time_level_drawing, draw_time_hour);
	lv_label_set_text(guider_ui.screen_drawing_Time_level_drawing_1, draw_time_min);

}



