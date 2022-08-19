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

#include "Screen_Task.h"

extern lv_ui guider_ui;
unsigned char Toggle_Image_Var;

volatile uint8_t toggle_colon_screen_time;
// Program ROM constants
static uint8_t MonthDayTable[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char date[] = "May 24, 2022";
char time[] = "10:10";
char speed[4];

uint8_t speed_update;
uint8_t speed_val = 60;
uint8_t speed_dir;

uint8_t cluster_Odo_0;
uint8_t cluster_Odo_1;
uint8_t cluster_Odo_2;
uint8_t cluster_Odo_3;
uint8_t cluster_Odo_4;
uint8_t cluster_Odo_5;
uint8_t cluster_Odo_6;

uint8_t cluster_Odo_0_update_flag;
uint8_t cluster_Odo_1_update_flag;
uint8_t cluster_Odo_2_update_flag;
uint8_t cluster_Odo_3_update_flag;
uint8_t cluster_Odo_4_update_flag;
uint8_t cluster_Odo_5_update_flag;
uint8_t cluster_Odo_6_update_flag;

// Global variables
// time registers
RtcTimeType RtcTime;

// Animate the Teltail LED
void Screen_teltail_Animate(void)
{

	if(Toggle_Image_Var == 0u)
	{
		//Toggle_Image_Var = 1;
		/*Hide on object*/
		lv_obj_clear_flag(guider_ui.screen_High_Beam, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Engine, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Fuel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Battery, LV_OBJ_FLAG_HIDDEN);
	}
	else if(Toggle_Image_Var == 1u)
	{
		//Toggle_Image_Var = 1;
		lv_obj_add_flag(guider_ui.screen_High_Beam, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_Engine, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Fuel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Battery, LV_OBJ_FLAG_HIDDEN);
	}
	else if(Toggle_Image_Var == 2u)
	{
		//Toggle_Image_Var = 1;
		lv_obj_add_flag(guider_ui.screen_High_Beam, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Engine, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_Fuel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Battery, LV_OBJ_FLAG_HIDDEN);
	}
	else if(Toggle_Image_Var == 3u)
	{
		//Toggle_Image_Var = 1;
		lv_obj_add_flag(guider_ui.screen_High_Beam, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Engine, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Fuel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_Battery, LV_OBJ_FLAG_HIDDEN);
	}
	else if(Toggle_Image_Var == 4u)
	{
		//Toggle_Image_Var = 1;
		lv_obj_clear_flag(guider_ui.screen_High_Beam, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_Engine, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_Fuel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_Battery, LV_OBJ_FLAG_HIDDEN);
	}
	else if(Toggle_Image_Var == 5u)
	{
		//Toggle_Image_Var = 1;
		lv_obj_add_flag(guider_ui.screen_High_Beam, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Engine, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Fuel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Battery, LV_OBJ_FLAG_HIDDEN);
	}
	else if(Toggle_Image_Var == 6u)
	{
		//Toggle_Image_Var = 1;
		lv_obj_clear_flag(guider_ui.screen_High_Beam, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_Engine, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_Fuel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_Battery, LV_OBJ_FLAG_HIDDEN);
	}
	else if(Toggle_Image_Var == 7u)
	{
		//Toggle_Image_Var = 1;
		lv_obj_add_flag(guider_ui.screen_High_Beam, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Engine, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Fuel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_Battery, LV_OBJ_FLAG_HIDDEN);
	}
	else
	{
		// NOP
	}

	Toggle_Image_Var++;
	if(Toggle_Image_Var > 7)
	{
		Toggle_Image_Var = 0;
	}

}

void RTC_Init(void)
{
	// set up timer for RTC operation
	RtcTime.seconds = 0;
	RtcTime.minutes = 10;
	RtcTime.hours = 10;

	RtcTime.day = 3;
	RtcTime.month = 6;
	RtcTime.year = 2022;
}

// Animate the Clock & Date
void RTC_Animate(void)
{
	RtcTime.seconds++;                                                      // increment seconds
	if(RtcTime.seconds > 59)                                        // check seconds overflow
	{
		RtcTime.seconds -= 60;
		RtcTime.minutes++;                                              // increment minutes
		if(RtcTime.minutes > 59)                                // check minutes overflow
		{
			RtcTime.minutes -= 60;
			RtcTime.hours++;                                                // increment hours
			if(RtcTime.hours > 23)                          // check hours overflow
			{
				RtcTime.hours -= 24;
				RtcTime.day++;                                          // increment days
				if(RtcTime.day == MonthDayTable[RtcTime.month-1])// check days overflow
				{
					RtcTime.day = 1;
					RtcTime.month++;                                // increment months
					if(RtcTime.month == 13)         // check months overflow
					{
						RtcTime.month = 1;
						RtcTime.year++;                 // increment years
					}
				}
			}
		}
	}

}


// Convert Month to text name
void convert_Month_to_Text (void)
{
	if(RtcTime.month == 1)
	{
		date[0] = 'J';
		date[1] = 'a';
		date[2] = 'n';
	}
	else if(RtcTime.month == 2)
	{
		date[0] = 'F';
		date[1] = 'e';
		date[2] = 'b';
	}
	else if(RtcTime.month == 3)
	{
		date[0] = 'M';
		date[1] = 'a';
		date[2] = 'r';
	}
	else if(RtcTime.month == 4)
	{
		date[0] = 'A';
		date[1] = 'p';
		date[2] = 'r';
	}
	else if(RtcTime.month == 5)
	{
		date[0] = 'M';
		date[1] = 'a';
		date[2] = 'y';
	}
	else if(RtcTime.month == 6)
	{
		date[0] = 'J';
		date[1] = 'u';
		date[2] = 'n';
	}
	else if(RtcTime.month == 7)
	{
		date[0] = 'J';
		date[1] = 'u';
		date[2] = 'l';
	}
	else if(RtcTime.month == 8)
	{
		date[0] = 'A';
		date[1] = 'u';
		date[2] = 'g';
	}
	else if(RtcTime.month == 9)
	{
		date[0] = 'S';
		date[1] = 'e';
		date[2] = 'p';
	}
	else if(RtcTime.month == 10)
	{
		date[0] = 'O';
		date[1] = 'c';
		date[2] = 't';
	}
	else if(RtcTime.month == 11)
	{
		date[0] = 'N';
		date[1] = 'o';
		date[2] = 'v';
	}
	else if(RtcTime.month == 12)
	{
		date[0] = 'D';
		date[1] = 'e';
		date[2] = 'c';
	}
	else
	{
		// Nop
	}

}

// Convert Day-Decimal to day-char
void convert_day_to_Text(void)
{

	date[4] = (RtcTime.day / 10) + 0x30;
	date[5] = (RtcTime.day % 10) + 0x30;

}

// Convert year-Decimal to year-char
void convert_year_to_Text(void)
{
    // 8,9,10,11
	date[11] = (RtcTime.year % 10) + 0x30;
	date[10] = ((RtcTime.year/10) % 10) + 0x30;
	date[9]  = ((RtcTime.year/100) % 10) + 0x30;
	date[8]  = ((RtcTime.year/1000) % 10) + 0x30;

}

// Convert time-Decimal to time-char
void convert_Time_to_Text(void)
{
	// hour
	time[0] = (RtcTime.hours / 10) + 0x30;
	time[1] = (RtcTime.hours % 10) + 0x30;
	// min
	time[3] = (RtcTime.minutes / 10) + 0x30;
	time[4] = (RtcTime.minutes % 10) + 0x30;

	if(toggle_colon_screen_time)
	{
//		lv_obj_clear_flag(guider_ui.screen_drawing_canvas_triangle_L_1, LV_OBJ_FLAG_HIDDEN);
//		lv_label_set_text(guider_ui.screen_drawing_Time_level_drawing_0, ":");
		//time[2] = ':';
		toggle_colon_screen_time = 0;
	}
	else
	{
//		lv_obj_add_flag(guider_ui.screen_drawing_canvas_triangle_L_1, LV_OBJ_FLAG_HIDDEN);
//		lv_label_set_text(guider_ui.screen_drawing_Time_level_drawing_0, " ");
		//time[2] = ' ';
		toggle_colon_screen_time = 1;
	}
}

//update time on screen
void Screen_date_Time_update(void)
{
	//set date
	convert_Month_to_Text();
	convert_day_to_Text();
	convert_year_to_Text();
	lv_label_set_text(guider_ui.screen_Date_Label, date);

	//set time
	convert_Time_to_Text();
	lv_label_set_text(guider_ui.screen_Time_Label, time);


}

void convert_speed_to_Text(void)
{

	speed[0] = speed[1] = speed[2] = speed[3] = 'a';

	if(speed_val > 99)
	{
	    // set speed
		speed[3] = '\0';
		speed[2] = (speed_val % 10) + 0x30;
		speed[1] = ((speed_val/10) % 10) + 0x30;
		speed[0]  = ((speed_val/100) % 10) + 0x30;
	}
	else
	{
		// set speed
		speed[2] = '\0';
		speed[0] = (speed_val / 10) + 0x30;
		speed[1] = (speed_val % 10) + 0x30;
	}
}

//update speed on screen
void Screen_speed_update(void)
{
	speed_update++;

	if(speed_update == 2)
	{
		if(speed_dir == 0)
		{
			// inc speed
			speed_val++;

		}
		else
		{
			// dec speed
			speed_val--;
		}

		if(speed_val == 180)
		{
			speed_dir = 1;  // dec speed
		}
		else if (speed_val == 10)
		{
			speed_dir = 0;  // inc speed
		}
		else
		{
			// NOP
		}

		//set date
		convert_speed_to_Text();
		lv_label_set_text(guider_ui.screen_Speed_Label, speed);

		speed_update = 0;
	}

}


void ODO_Animate(void)
{
    cluster_Odo_0++;
    cluster_Odo_0_update_flag = 1;

    // increment 10 position
    if(cluster_Odo_0 == 10)
    {
        //cluster_Odo_0.goBack();
        cluster_Odo_0 = 0;
        cluster_Odo_1++;
        cluster_Odo_1_update_flag = 1;
        if(cluster_Odo_1 == 10)
        {
            // increment 100 position
            cluster_Odo_2++;
            cluster_Odo_2_update_flag = 1;
            cluster_Odo_1 = 0;
            if(cluster_Odo_2 == 10)
            {

                // increment 1000 position
                cluster_Odo_3++;
                cluster_Odo_3_update_flag = 1;
                cluster_Odo_2 = 0;
                if(cluster_Odo_3 == 10)
                {
                    // increment 10000 position
                    cluster_Odo_3 = 0;
                    cluster_Odo_4++;
                    cluster_Odo_4_update_flag = 1;
                    if(cluster_Odo_4 == 10)
                    {
                        // increment 100000 position
                        cluster_Odo_5++;
                        cluster_Odo_5_update_flag = 1;
                        cluster_Odo_4 = 0;
                        if(cluster_Odo_5 == 10)
                        {
                            // increment 1000000 position

                            cluster_Odo_6++;
                            cluster_Odo_6_update_flag = 1;
                            cluster_Odo_5 = 0;
                            if(cluster_Odo_6 == 10)
                            {
                                //cluster_Odo_0.goBack();
                                cluster_Odo_6 = 0;
                            }
                        }
                    }
                }
            }

        }
    }
}

//update ODO on screen
void Screen_ODO_update(void)
{
	if(cluster_Odo_0_update_flag == 1)
	{
		lv_roller_set_selected(guider_ui.screen_ODO_roller_0,cluster_Odo_0,LV_ANIM_ON);
		cluster_Odo_0_update_flag = 0;
	}
	if(cluster_Odo_1_update_flag == 1)
	{
		lv_roller_set_selected(guider_ui.screen_ODO_roller_1,cluster_Odo_1,LV_ANIM_ON);
		cluster_Odo_1_update_flag = 0;
	}
	if(cluster_Odo_2_update_flag == 1)
	{
		lv_roller_set_selected(guider_ui.screen_ODO_roller_2,cluster_Odo_2,LV_ANIM_ON);
		cluster_Odo_2_update_flag = 0;
	}
	if(cluster_Odo_3_update_flag == 1)
	{
		lv_roller_set_selected(guider_ui.screen_ODO_roller_3,cluster_Odo_3,LV_ANIM_ON);
		cluster_Odo_3_update_flag = 0;
	}
	if(cluster_Odo_4_update_flag == 1)
	{
		lv_roller_set_selected(guider_ui.screen_ODO_roller_4,cluster_Odo_4,LV_ANIM_ON);
		cluster_Odo_4_update_flag = 0;
	}
	if(cluster_Odo_5_update_flag == 1)
	{
		lv_roller_set_selected(guider_ui.screen_ODO_roller_5,cluster_Odo_5,LV_ANIM_ON);
		cluster_Odo_5_update_flag = 0;
	}
	if(cluster_Odo_6_update_flag == 1)
	{
		lv_roller_set_selected(guider_ui.screen_ODO_roller_6,cluster_Odo_6,LV_ANIM_ON);
		cluster_Odo_6_update_flag = 0;
	}

}

//update ODO on screen
void Screen_ODO_hide(void)
{
	lv_obj_add_flag(guider_ui.screen_ODO_roller_image, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_ODO_roller_0, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_ODO_roller_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_ODO_roller_2, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_ODO_roller_3, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_ODO_roller_4, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_ODO_roller_5, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_ODO_roller_6, LV_OBJ_FLAG_HIDDEN);
}



