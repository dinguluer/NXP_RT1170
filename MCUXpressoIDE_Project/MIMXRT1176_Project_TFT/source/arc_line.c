/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

//#include "FreeRTOS.h"
//#include "task.h"

#include <core/lv_obj_scroll.h>
#include "fsl_debug_console.h"
#include "lvgl_support.h"
#include "pin_mux.h"
#include "board.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


// Screen task
#include "Screen_Task.h"


//13
//13*2 + 2
//13*3 + 5
//13*4 + 7
//13*5 + 10
//13*6 + 13 --
//(13*7)+16);
//(13*8)+18);
//(13*9)+20);
//(13*10)+21); --
//(13*11)+23);
//(13*12)+25); --
//(13*13)+27);
//(13*14)+29);
//(13*15)+31);
//(13*16)+33);
//(13*17)+35);


#define METER_1_LIMIT 13
#define METER_2_LIMIT 28
#define METER_3_LIMIT 44
#define METER_4_LIMIT 59
#define METER_5_LIMIT 75
#define METER_6_LIMIT 91
#define METER_7_LIMIT 107
#define METER_8_LIMIT 122
#define METER_9_LIMIT 137
#define METER_10_LIMIT 151
#define METER_11_LIMIT 166
#define METER_12_LIMIT 181
#define METER_13_LIMIT 196
#define METER_14_LIMIT 211
#define METER_15_LIMIT 226
#define METER_16_LIMIT 241
#define METER_17_LIMIT 256
//#define METER_18_LIMIT 0


extern volatile uint32_t drawing_screen_arc;
extern volatile uint32_t drawing_screen_arc_inc_enable;
extern volatile int16_t arc_value;
extern volatile	uint8_t arc_clock_wise;


extern volatile uint32_t fuel_drawing_screen_arc;
extern volatile uint32_t fuel_drawing_screen_arc_inc_enable;
extern volatile int16_t  fuel_arc_value_red;
extern volatile int16_t  fuel_arc_value_green;
extern volatile	uint8_t  fuel_arc_clock_wise;

extern volatile uint8_t start_red_arc;
extern volatile uint8_t start_green_arc;

void arc_line(void)
{
	//lv_arc_set_value(guider_ui.screen_drawing_arc_indicator, (13*17)+35);
	if(drawing_screen_arc >= 10)
	{
		lv_arc_set_value(guider_ui.screen_drawing_arc_indicator, arc_value);

		if(arc_clock_wise)
		{
			arc_value++;
			if(arc_value > 270)
			//if(arc_value > 100)
			{
				arc_clock_wise = 0;
			}
		}
		else
		{
			arc_value--;
			if(arc_value <= 0)
			{
				arc_value = 0;
				arc_clock_wise = 1;
			}
		}

		drawing_screen_arc = 0;
	}

	if(arc_value<METER_1_LIMIT)
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_1_LIMIT) && (arc_value < METER_2_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_2_LIMIT)&& (arc_value < METER_3_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_3_LIMIT)&& (arc_value < METER_4_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_4_LIMIT)&& (arc_value < METER_5_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_5_LIMIT)&& (arc_value < METER_6_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_6_LIMIT)&& (arc_value < METER_7_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_7_LIMIT)&& (arc_value < METER_8_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_8_LIMIT)&& (arc_value < METER_9_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_9_LIMIT)&& (arc_value < METER_10_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_10_LIMIT)&& (arc_value < METER_11_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_11_LIMIT)&& (arc_value < METER_12_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_12_LIMIT)&& (arc_value < METER_13_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_13_LIMIT)&& (arc_value < METER_14_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_14_LIMIT)&& (arc_value < METER_15_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_15_LIMIT)&& (arc_value < METER_16_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if ((arc_value > METER_16_LIMIT)&& (arc_value < METER_17_LIMIT))
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}
	if (arc_value > METER_17_LIMIT)
	{
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);
	}


}


void fuel_arc_line(void)
{
	//if(0)
	if(fuel_drawing_screen_arc >= 10)
	{
		lv_arc_set_value(guider_ui.screen_drawing_Red_fuel_arc, fuel_arc_value_red);
		lv_arc_set_value(guider_ui.screen_drawing_Green_fuel_arc, fuel_arc_value_green);
		if(fuel_arc_clock_wise)
		{
			if(start_red_arc)
			{
				fuel_arc_value_red++;
				if(fuel_arc_value_red > 19)
				{
					fuel_arc_value_red = 19;
					//fuel_arc_clock_wise = 0;
					start_green_arc = 1;
					start_red_arc = 0;

					fuel_arc_clock_wise = 0;
				}
			}
			if(start_green_arc)
			{
				fuel_arc_value_green++;
				if(fuel_arc_value_green > 64)
				{
					fuel_arc_value_green = 64;
					start_green_arc = 0;
					start_red_arc = 1;

//					fuel_arc_clock_wise = 0;
				}

			}
		}
		else
		{

			if(start_red_arc)
			{
				fuel_arc_value_red--;
				if(fuel_arc_value_red <= 0)
				{
					fuel_arc_value_red = 0;
					//fuel_arc_clock_wise = 0;
					start_green_arc = 1;
					start_red_arc = 0;
				}
			}
			if(start_green_arc)
			{
				fuel_arc_value_green--;
				if(fuel_arc_value_green <= 0)
				{
					fuel_arc_value_green = 0;
					start_green_arc = 1;
					start_red_arc = 0;

					fuel_arc_clock_wise = 1;
				}

			}


		}

		fuel_drawing_screen_arc = 0;
	}
}
