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
#include "drawing_speed_RPM.h"

char drawing_speed[4];
char drawing_rpm[4];

//uint8_t drawing_speed_update;
uint8_t drawing_speed_val ;// = 0;
uint8_t drawing_speed_dir;

//uint8_t drawing_rpm_update;
uint8_t drawing_rpm_val; // = 0;
uint8_t drawing_rpm_dir;

uint8_t gear_value;
char gear_value_text[3];

extern volatile uint32_t drawing_screen_speed_rpm ;
extern volatile uint32_t drawing_screen_speed_rpm_inc_enable ;
volatile uint8_t drawing_speed_rpm_update_value;

extern volatile bool pitIsrFlag_drawing;

void convert_number_to_Text(uint16_t speed_val_local, char *text_ptr)
{

	text_ptr[0] = text_ptr[1] = text_ptr[2] = text_ptr[3] = 'a';

	if(speed_val_local > 99)
	{
	    // set text_ptr
		text_ptr[3] = '\0';
		text_ptr[2] = (speed_val_local % 10) + 0x30;
		text_ptr[1] = ((speed_val_local/10) % 10) + 0x30;
		text_ptr[0]  = ((speed_val_local/100) % 10) + 0x30;
	}
	else
	{
		// set text_ptr
		text_ptr[2] = '\0';
		text_ptr[0] = (speed_val_local / 10) + 0x30;
		text_ptr[1] = (speed_val_local % 10) + 0x30;
	}
}

void drawing_speed_update(void)
{
	if(drawing_speed_dir == 0)
	{
		// inc speed
		drawing_speed_val++;

	}
	else
	{
		// dec speed
		drawing_speed_val--;
	}

	if(drawing_speed_val == 180)
	{
		drawing_speed_dir = 1;  // dec speed
	}
	else if (drawing_speed_val == 10)
	{
		drawing_speed_dir = 0;  // inc speed
	}
	else
	{
		// NOP
	}

	//set date
	convert_number_to_Text(drawing_speed_val,drawing_speed);
	lv_label_set_text(guider_ui.screen_drawing_speed_value_label, drawing_speed);
}

void drawing_rpm_update(void)
{
	if(drawing_rpm_dir == 0)
	{
		// inc rpm
		drawing_rpm_val++;

	}
	else
	{
		// dec rpm
		drawing_rpm_val--;
	}

	if(drawing_rpm_val == 180)
	{
		drawing_rpm_dir = 1;  // dec rpm
	}
	else if (drawing_rpm_val == 10)
	{
		drawing_rpm_dir = 0;  // inc rpm
	}
	else
	{
		// NOP
	}

	//set date
	convert_number_to_Text(drawing_rpm_val,drawing_rpm);
	lv_label_set_text(guider_ui.screen_drawing_RPM_value_label, drawing_rpm);
}


//update speed on screen
void drawing_speed_rpm_update(void)
{
	//if(pitIsrFlag_drawing)
	if(drawing_screen_speed_rpm  >= 10)
	{

		drawing_speed_rpm_update_value++;

		if(drawing_speed_rpm_update_value == 2)
		{
			drawing_speed_update();
			drawing_rpm_update();
			drawing_speed_rpm_update_value = 0;
		}

		//pitIsrFlag_drawing = 0;
		drawing_screen_speed_rpm = 0;
	}

	// update gear
	if(pitIsrFlag_drawing)
	{
		gear_value_text[1] = '\0';
		if(gear_value == 0)
		{
			gear_value_text[0] = '1';
		}
		else if (gear_value == 1)
		{
			gear_value_text[0] = '2';
		}
		else if (gear_value == 2)
		{
			gear_value_text[0] = '3';
		}
		else if (gear_value == 3)
		{
			gear_value_text[0] = '4';
		}
		else if (gear_value == 4)
		{
			gear_value_text[0] = '5';
		}
		else if (gear_value == 5)
		{
			gear_value_text[0] = 'R';
		}


//		lv_label_set_text(guider_ui.screen_drawing_Date_Label_drawing, "june 24 2022");
		lv_label_set_text(guider_ui.screen_drawing_Gear_value_label, gear_value_text);

		gear_value++;
		if(gear_value == 6)
		{
			gear_value = 0;
		}

		pitIsrFlag_drawing = 0;
	}


}
