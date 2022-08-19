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

#define TEMP_LINE_OPA 160

#define TEMP_LEFT_LINE_A_LINE_1_X_START 575
#define TEMP_LEFT_LINE_A_LINE_1_X_END   (TEMP_LEFT_LINE_A_LINE_1_X_START+7)
#define TEMP_LEFT_LINE_A_LINE_1_Y_START 445 //369
#define TEMP_LEFT_LINE_A_LINE_1_Y_END   (TEMP_LEFT_LINE_A_LINE_1_Y_START)

#define TEMP_LEFT_LINE_A_LINE_2_X_START (TEMP_LEFT_LINE_A_LINE_1_X_END)
#define TEMP_LEFT_LINE_A_LINE_2_X_END   (TEMP_LEFT_LINE_A_LINE_2_X_START+20-6)
#define TEMP_LEFT_LINE_A_LINE_2_Y_START TEMP_LEFT_LINE_A_LINE_1_Y_END
#define TEMP_LEFT_LINE_A_LINE_2_Y_END   (TEMP_LEFT_LINE_A_LINE_2_Y_START)

#define TEMP_LEFT_LINE_A_LINE_3_X_START (TEMP_LEFT_LINE_A_LINE_2_X_END)
#define TEMP_LEFT_LINE_A_LINE_3_X_END   (TEMP_LEFT_LINE_A_LINE_3_X_START+20)
#define TEMP_LEFT_LINE_A_LINE_3_Y_START TEMP_LEFT_LINE_A_LINE_2_Y_END
#define TEMP_LEFT_LINE_A_LINE_3_Y_END   (TEMP_LEFT_LINE_A_LINE_3_Y_START)

#define TEMP_LEFT_LINE_A_LINE_4_X_START (TEMP_LEFT_LINE_A_LINE_3_X_END)
#define TEMP_LEFT_LINE_A_LINE_4_X_END   (TEMP_LEFT_LINE_A_LINE_4_X_START+20)
#define TEMP_LEFT_LINE_A_LINE_4_Y_START TEMP_LEFT_LINE_A_LINE_3_Y_END
#define TEMP_LEFT_LINE_A_LINE_4_Y_END   (TEMP_LEFT_LINE_A_LINE_4_Y_START)

#define TEMP_LEFT_LINE_A_LINE_5_X_START (TEMP_LEFT_LINE_A_LINE_4_X_END)
#define TEMP_LEFT_LINE_A_LINE_5_X_END   (TEMP_LEFT_LINE_A_LINE_5_X_START+20)
#define TEMP_LEFT_LINE_A_LINE_5_Y_START TEMP_LEFT_LINE_A_LINE_4_Y_END
#define TEMP_LEFT_LINE_A_LINE_5_Y_END   (TEMP_LEFT_LINE_A_LINE_5_Y_START)

#define TEMP_LEFT_LINE_A_LINE_6_X_START (TEMP_LEFT_LINE_A_LINE_5_X_END)
#define TEMP_LEFT_LINE_A_LINE_6_X_END   (TEMP_LEFT_LINE_A_LINE_6_X_START+20)
#define TEMP_LEFT_LINE_A_LINE_6_Y_START TEMP_LEFT_LINE_A_LINE_5_Y_END
#define TEMP_LEFT_LINE_A_LINE_6_Y_END   (TEMP_LEFT_LINE_A_LINE_6_Y_START)

#define TEMP_LEFT_LINE_A_LINE_7_X_START (TEMP_LEFT_LINE_A_LINE_6_X_END)
#define TEMP_LEFT_LINE_A_LINE_7_X_END   (TEMP_LEFT_LINE_A_LINE_7_X_START+20)
#define TEMP_LEFT_LINE_A_LINE_7_Y_START TEMP_LEFT_LINE_A_LINE_6_Y_END
#define TEMP_LEFT_LINE_A_LINE_7_Y_END   (TEMP_LEFT_LINE_A_LINE_7_Y_START)

#define TEMP_LEFT_LINE_A_LINE_8_X_START (TEMP_LEFT_LINE_A_LINE_7_X_END)
#define TEMP_LEFT_LINE_A_LINE_8_X_END   (TEMP_LEFT_LINE_A_LINE_8_X_START+20)
#define TEMP_LEFT_LINE_A_LINE_8_Y_START TEMP_LEFT_LINE_A_LINE_7_Y_END
#define TEMP_LEFT_LINE_A_LINE_8_Y_END   (TEMP_LEFT_LINE_A_LINE_8_Y_START)

#define TEMP_LEFT_LINE_A_LINE_9_X_START (TEMP_LEFT_LINE_A_LINE_8_X_END)
#define TEMP_LEFT_LINE_A_LINE_9_X_END   (TEMP_LEFT_LINE_A_LINE_9_X_START+20)
#define TEMP_LEFT_LINE_A_LINE_9_Y_START TEMP_LEFT_LINE_A_LINE_8_Y_END
#define TEMP_LEFT_LINE_A_LINE_9_Y_END   (TEMP_LEFT_LINE_A_LINE_9_Y_START)

#define TEMP_LEFT_LINE_A_LINE_10_X_START (TEMP_LEFT_LINE_A_LINE_9_X_END)   //124
#define TEMP_LEFT_LINE_A_LINE_10_X_END   (TEMP_LEFT_LINE_A_LINE_10_X_START+20) //360
#define TEMP_LEFT_LINE_A_LINE_10_Y_START TEMP_LEFT_LINE_A_LINE_9_Y_END         // 113
#define TEMP_LEFT_LINE_A_LINE_10_Y_END   (TEMP_LEFT_LINE_A_LINE_10_Y_START)  // 359



uint8_t temp_left_draw_line_1_first_draw_forward = 1;
uint8_t temp_left_draw_line_1_first_draw_forward_switch = 1;
uint8_t temp_left_draw_line_1_draw_backward_switch = 0;
uint8_t temp_left_draw_line_1_draw_backward_switch_case = 0;
uint8_t temp_left_draw_line_1_draw_forward_switch = 0;
uint8_t temp_left_draw_line_1_draw_forward_switch_case = 0;
uint8_t temp_line_1_start_timer;
uint8_t temp_line_1_start_timer_exp;

extern volatile uint32_t temp_drawing_screen;
extern volatile uint32_t temp_drawing_screen_inc_enable;
extern volatile uint8_t  battery_left_start_drawing;
extern volatile uint8_t temp_start_drawing;

volatile uint8_t temp_left_init_entry;

//#define LEFT_DRAW_LINE_1_COLOR_RED 1

void temp_draw(void)
{
//static lv_point_t line_points[] = { {214, 369}, {88, 357}};
//
//    /*Create style*/
//    static lv_style_t style_line;
//    lv_style_init(&style_line);
//    lv_style_set_line_width(&style_line, 12);
//    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_RED));
//    lv_style_set_line_rounded(&style_line, false);
//
//    /*Create a line and apply the new style*/
//    lv_obj_t * line1;
//    line1 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//    lv_line_set_points(line1, line_points, 2);     /*Set the points*/
//    lv_obj_add_style(line1, &style_line, 0);
//    //lv_obj_center(line1);

	if(temp_left_init_entry == 0)
	{
		temp_line_1_start_timer = 1;
		temp_line_1_start_timer_exp = 1;
		temp_left_draw_line_1_first_draw_forward = 1;

		temp_left_init_entry = 1;
	}

#ifndef LEFT_DRAW_LINE_1_COLOR_RED
	//lv_color_t first_line_color = LV_COLOR_MAKE(0,0,255);
	lv_color_t first_line_color = LV_COLOR_MAKE(0x1e, 0xca, 0x1c);
#endif
	//lv_color_t last_line_color = LV_COLOR_MAKE(254,43,43);
	lv_color_t last_line_color = LV_COLOR_MAKE(168,16,31);
	//lv_color_t last_line_color = LV_COLOR_MAKE(255,85,85);
	//lv_color_t last_line_color = LV_COLOR_MAKE(255,0,0);

//	static lv_style_t style_line_L_11;
//	lv_style_init(&style_line_L_11);
//	lv_style_set_line_rounded(&style_line_L_11, false);

//	static lv_style_t style_line_L_fix;
//	lv_style_init(&style_line_L_fix);
//	lv_style_set_line_rounded(&style_line_L_fix, false);
//
//	static lv_style_t style_line_L_fix_temp;
//	lv_style_init(&style_line_L_fix_temp);
//	lv_style_set_line_rounded(&style_line_L_fix_temp, false);

	//temp_left_draw_line_1_first_draw_forward_switch = 13;
	//while(1)
	if(temp_start_drawing)
	{
		if(temp_line_1_start_timer_exp)
		{
			//while(1)
			if(temp_left_draw_line_1_first_draw_forward)
			{
				switch(temp_left_draw_line_1_first_draw_forward_switch)
				{
				case 1 :
					;
					lv_obj_clear_flag(guider_ui.screen_drawing_canvas_triangle_R_1, LV_OBJ_FLAG_HIDDEN);
					temp_left_draw_line_1_first_draw_forward_switch++;
					break;

				case 2 :
					;
					lv_obj_clear_flag(guider_ui.screen_drawing_canvas_triangle_R_2, LV_OBJ_FLAG_HIDDEN);
					temp_left_draw_line_1_first_draw_forward_switch++;
					break;

				case 3 :
					;
					lv_obj_clear_flag(guider_ui.templine1, LV_OBJ_FLAG_HIDDEN);
//					// Line - 1
//					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
//					//12 lines : x = 128/12 = 10.66 = -(10+1)
//					// starting -- x = prev line ending (x +1)
//					//static lv_point_t line_points[] = { {214, 369}, {203, 368}};
//					static lv_point_t line_points[] = { {TEMP_LEFT_LINE_A_LINE_1_X_START, TEMP_LEFT_LINE_A_LINE_1_Y_START}, {TEMP_LEFT_LINE_A_LINE_1_X_END, TEMP_LEFT_LINE_A_LINE_1_Y_END}};
//					//lv_color_t
//					/*Create style*/
//					static lv_style_t style_line;
//					lv_style_init(&style_line);
//					lv_style_set_line_width(&style_line, 12);
//#ifndef LEFT_DRAW_LINE_1_COLOR_RED
//					//lv_style_set_line_opa(&style_line, 56);
//					lv_style_set_line_color(&style_line, first_line_color);
//#else
//					lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_RED));
//#endif
//					lv_style_set_line_rounded(&style_line, false);
//					/*Create a line and apply the new style*/
//					//lv_obj_t * line1;
//					guider_ui.templine1 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//					lv_line_set_points(guider_ui.templine1, line_points, 2);     /*Set the points*/
//					lv_obj_add_style(guider_ui.templine1, &style_line, 0);
//					//lv_obj_center(line1);
//					//lv_task_handler();  // Update the display
					temp_left_draw_line_1_first_draw_forward_switch++;
					break;

				case 4 :
					;
					lv_obj_clear_flag(guider_ui.templine2, LV_OBJ_FLAG_HIDDEN);
//					// Line - 2
//					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
//					//12 lines : x = 128/12 = 10.66 = 10+1
//					// starting -- x = prev line ending (x +1)
//					//static lv_point_t line_points_L_1[] = { {204, 368}, {193, 367}};
//					static lv_point_t line_points_L_1[] = { {TEMP_LEFT_LINE_A_LINE_2_X_START, TEMP_LEFT_LINE_A_LINE_2_Y_START}, {TEMP_LEFT_LINE_A_LINE_2_X_END, TEMP_LEFT_LINE_A_LINE_2_Y_END}};
//					/*Create style*/
//					static lv_style_t style_line_L_1;
//					lv_style_init(&style_line_L_1);
//					lv_style_set_line_width(&style_line_L_1, 12);
//#ifndef LEFT_DRAW_LINE_1_COLOR_RED
//					//lv_style_set_line_opa(&style_line_L_1, 56);
//					lv_style_set_line_color(&style_line_L_1, first_line_color);
//#else
//					lv_style_set_line_color(&style_line_L_1, lv_palette_main(LV_PALETTE_RED));
//#endif
//					lv_style_set_line_rounded(&style_line_L_1, false);
//					/*Create a line and apply the new style*/
//					//lv_obj_t * line2;
//					guider_ui.templine2 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//					lv_line_set_points(guider_ui.templine2, line_points_L_1, 2);     /*Set the points*/
//					lv_obj_add_style(guider_ui.templine2, &style_line_L_1, 0);
//					//lv_obj_center(line1);
//					//lv_task_handler();  // Update the display
					temp_left_draw_line_1_first_draw_forward_switch++;
					break;

				case 5 :
					;
					lv_obj_clear_flag(guider_ui.templine3, LV_OBJ_FLAG_HIDDEN);
//					// Line - 3
//					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
//					//12 lines : x = 128/12 = 10.66 = 10+1
//					// starting -- x = prev line ending (x +1)
//					static lv_point_t line_points_L_2[] = { {TEMP_LEFT_LINE_A_LINE_3_X_START, TEMP_LEFT_LINE_A_LINE_3_Y_START}, {TEMP_LEFT_LINE_A_LINE_3_X_END, TEMP_LEFT_LINE_A_LINE_3_Y_END}};
//					/*Create style*/
//					static lv_style_t style_line_L_2;
//					lv_style_init(&style_line_L_2);
//					lv_style_set_line_width(&style_line_L_2, 12);
//#ifndef LEFT_DRAW_LINE_1_COLOR_RED
//					////lv_style_set_line_opa(&style_line_L_2, 56);
//					lv_style_set_line_color(&style_line_L_2, first_line_color);
//#else
//					lv_style_set_line_color(&style_line_L_2, lv_palette_main(LV_PALETTE_RED));
//#endif
//					lv_style_set_line_rounded(&style_line_L_2, false);
//					/*Create a line and apply the new style*/
//					//lv_obj_t * line3;
//					guider_ui.templine3 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//					lv_line_set_points(guider_ui.templine3, line_points_L_2, 2);     /*Set the points*/
//					lv_obj_add_style(guider_ui.templine3, &style_line_L_2, 0);
//					//lv_obj_center(line1);
//					//lv_task_handler();  // Update the display
					temp_left_draw_line_1_first_draw_forward_switch++;
					break;

				case 6 :
					;
					lv_obj_clear_flag(guider_ui.templine4, LV_OBJ_FLAG_HIDDEN);
//					// Line - 4
//					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
//					//12 lines : x = 128/12 = 10.66 = 10+1
//					// starting -- x = prev line ending (x +1)
//					static lv_point_t line_points_L_3[] = { {TEMP_LEFT_LINE_A_LINE_4_X_START, TEMP_LEFT_LINE_A_LINE_4_Y_START}, {TEMP_LEFT_LINE_A_LINE_4_X_END, TEMP_LEFT_LINE_A_LINE_4_Y_END}};
//					/*Create style*/
//					static lv_style_t style_line_L_3;
//					lv_style_init(&style_line_L_3);
//					lv_style_set_line_width(&style_line_L_3, 12);
//#ifndef LEFT_DRAW_LINE_1_COLOR_RED
//					//lv_style_set_line_opa(&style_line_L_3, 56);
//					lv_style_set_line_color(&style_line_L_3, first_line_color);
//#else
//					lv_style_set_line_color(&style_line_L_3, lv_palette_main(LV_PALETTE_RED));
//#endif
//					lv_style_set_line_rounded(&style_line_L_3, false);
//					/*Create a line and apply the new style*/
//					//lv_obj_t * line4;
//					guider_ui.templine4 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//					lv_line_set_points(guider_ui.templine4, line_points_L_3, 2);     /*Set the points*/
//					lv_obj_add_style(guider_ui.templine4, &style_line_L_3, 0);
//					//lv_obj_center(line1);
//					//lv_task_handler();  // Update the display
					temp_left_draw_line_1_first_draw_forward_switch++;
					break;

				case 7 :
					;
					lv_obj_clear_flag(guider_ui.templine5, LV_OBJ_FLAG_HIDDEN);
//					// Line - 5
//					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
//					//12 lines : x = 128/12 = 10.66 = 10+1
//					// starting -- x = prev line ending (x +1)
//					static lv_point_t line_points_L_4[] = { {TEMP_LEFT_LINE_A_LINE_5_X_START, TEMP_LEFT_LINE_A_LINE_5_Y_START}, {TEMP_LEFT_LINE_A_LINE_5_X_END, TEMP_LEFT_LINE_A_LINE_5_Y_END}};
//					/*Create style*/
//					static lv_style_t style_line_L_4;
//					lv_style_init(&style_line_L_4);
//					lv_style_set_line_width(&style_line_L_4, 12);
//#ifndef LEFT_DRAW_LINE_1_COLOR_RED
//					//lv_style_set_line_opa(&style_line_L_4, 56);
//					lv_style_set_line_color(&style_line_L_4, first_line_color);
//#else
//					lv_style_set_line_color(&style_line_L_4, lv_palette_main(LV_PALETTE_RED));
//#endif
//					lv_style_set_line_rounded(&style_line_L_4, false);
//					/*Create a line and apply the new style*/
//					//lv_obj_t * line5;
//					guider_ui.templine5 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//					lv_line_set_points(guider_ui.templine5, line_points_L_4, 2);     /*Set the points*/
//					lv_obj_add_style(guider_ui.templine5, &style_line_L_4, 0);
//					//lv_obj_center(line1);
//					//lv_task_handler();  // Update the display
					temp_left_draw_line_1_first_draw_forward_switch++;
					break;

				case 8 :
					;
					lv_obj_clear_flag(guider_ui.templine6, LV_OBJ_FLAG_HIDDEN);
//					// Line - 6
//					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
//					//12 lines : x = 128/12 = 10.66 = 10+1
//					// starting -- x = prev line ending (x +1)
//					static lv_point_t line_points_L_5[] = { {TEMP_LEFT_LINE_A_LINE_6_X_START, TEMP_LEFT_LINE_A_LINE_6_Y_START}, {TEMP_LEFT_LINE_A_LINE_6_X_END, TEMP_LEFT_LINE_A_LINE_6_Y_END}};
//					/*Create style*/
//					static lv_style_t style_line_L_5;
//					lv_style_init(&style_line_L_5);
//					lv_style_set_line_width(&style_line_L_5, 12);
//#ifndef LEFT_DRAW_LINE_1_COLOR_RED
//					//lv_style_set_line_opa(&style_line_L_5, 56);
//					lv_style_set_line_color(&style_line_L_5, first_line_color);
//#else
//					lv_style_set_line_color(&style_line_L_5, lv_palette_main(LV_PALETTE_RED));
//#endif
//					lv_style_set_line_rounded(&style_line_L_5, false);
//					/*Create a line and apply the new style*/
//					//lv_obj_t * line6;
//					guider_ui.templine6 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//					lv_line_set_points(guider_ui.templine6, line_points_L_5, 2);     /*Set the points*/
//					lv_obj_add_style(guider_ui.templine6, &style_line_L_5, 0);
//					//lv_obj_center(line1);
//					//lv_task_handler();  // Update the display
					temp_left_draw_line_1_first_draw_forward_switch++;

	    			// start drawing temp screen
					//temp_start_drawing = 1;

					break;

				case 9 :
					;
					lv_obj_clear_flag(guider_ui.templine7, LV_OBJ_FLAG_HIDDEN);
//					// Line - 7
//					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
//					//12 lines : x = 128/12 = 10.66 = 10+1
//					// starting -- x = prev line ending (x +1)
//					static lv_point_t line_points_L_6[] = { {TEMP_LEFT_LINE_A_LINE_7_X_START, TEMP_LEFT_LINE_A_LINE_7_Y_START}, {TEMP_LEFT_LINE_A_LINE_7_X_END, TEMP_LEFT_LINE_A_LINE_7_Y_END}};
//					/*Create style*/
//					static lv_style_t style_line_L_6;
//					lv_style_init(&style_line_L_6);
//					lv_style_set_line_width(&style_line_L_6, 12);
//#ifndef LEFT_DRAW_LINE_1_COLOR_RED
//					//lv_style_set_line_opa(&style_line_L_6, 56);
//					lv_style_set_line_color(&style_line_L_6, first_line_color);
//#else
//					lv_style_set_line_color(&style_line_L_6, lv_palette_main(LV_PALETTE_RED));
//#endif
//					lv_style_set_line_rounded(&style_line_L_6, false);
//					/*Create a line and apply the new style*/
//					//lv_obj_t * line7;
//					guider_ui.templine7 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//					lv_line_set_points(guider_ui.templine7, line_points_L_6, 2);     /*Set the points*/
//					lv_obj_add_style(guider_ui.templine7, &style_line_L_6, 0);
//					//lv_obj_center(line1);
//					//lv_task_handler();  // Update the display
					temp_left_draw_line_1_first_draw_forward_switch++;
					break;

				case 10 :
					;
					lv_obj_clear_flag(guider_ui.templine8, LV_OBJ_FLAG_HIDDEN);
//					// Line - 8
//					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
//					//12 lines : x = 128/12 = 10.66 = 10+1
//					// starting -- x = prev line ending (x +1)
//					static lv_point_t line_points_L_7[] = { {TEMP_LEFT_LINE_A_LINE_8_X_START, TEMP_LEFT_LINE_A_LINE_8_Y_START}, {TEMP_LEFT_LINE_A_LINE_8_X_END, TEMP_LEFT_LINE_A_LINE_8_Y_END}};
//					/*Create style*/
//					static lv_style_t style_line_L_7;
//					lv_style_init(&style_line_L_7);
//					lv_style_set_line_width(&style_line_L_7, 12);
//#ifndef LEFT_DRAW_LINE_1_COLOR_RED
//					//lv_style_set_line_opa(&style_line_L_7, 56);
//					lv_style_set_line_color(&style_line_L_7, first_line_color);
//#else
//					lv_style_set_line_color(&style_line_L_7, lv_palette_main(LV_PALETTE_RED));
//#endif
//					lv_style_set_line_rounded(&style_line_L_7, false);
//					/*Create a line and apply the new style*/
//					//lv_obj_t * line8;
//					guider_ui.templine8 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//					lv_line_set_points(guider_ui.templine8, line_points_L_7, 2);     /*Set the points*/
//					lv_obj_add_style(guider_ui.templine8, &style_line_L_7, 0);
//					//lv_obj_center(line1);
//					//lv_task_handler();  // Update the display
					temp_left_draw_line_1_first_draw_forward_switch++;
					break;

				case 11 :
					;
					lv_obj_clear_flag(guider_ui.templine9, LV_OBJ_FLAG_HIDDEN);
//					// Line - 9
//					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
//					//12 lines : x = 128/12 = 10.66 = 10+1
//					// starting -- x = prev line ending (x +1)
//					static lv_point_t line_points_L_8[] = { {TEMP_LEFT_LINE_A_LINE_9_X_START, TEMP_LEFT_LINE_A_LINE_9_Y_START}, {TEMP_LEFT_LINE_A_LINE_9_X_END, TEMP_LEFT_LINE_A_LINE_9_Y_END}};
//					/*Create style*/
//					static lv_style_t style_line_L_8;
//					lv_style_init(&style_line_L_8);
//					lv_style_set_line_width(&style_line_L_8, 12);
//#ifndef LEFT_DRAW_LINE_1_COLOR_RED
//					//lv_style_set_line_opa(&style_line_L_8, 56);
//					lv_style_set_line_color(&style_line_L_8, first_line_color);
//#else
//					lv_style_set_line_color(&style_line_L_8, lv_palette_main(LV_PALETTE_RED));
//#endif
//					lv_style_set_line_rounded(&style_line_L_8, false);
//					/*Create a line and apply the new style*/
//					//lv_obj_t * line9;
//					guider_ui.templine9 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//					lv_line_set_points(guider_ui.templine9, line_points_L_8, 2);     /*Set the points*/
//					lv_obj_add_style(guider_ui.templine9, &style_line_L_8, 0);
//					//lv_obj_center(line1);
//					//lv_task_handler();  // Update the display
					temp_left_draw_line_1_first_draw_forward_switch++;
					break;

				case 12 :
					;
					lv_obj_clear_flag(guider_ui.templine10, LV_OBJ_FLAG_HIDDEN);
//					// Line - 10
//					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
//					//12 lines : x = 128/12 = 10.66 = 10+1
//					// starting -- x = prev line ending (x +1)
//					static lv_point_t line_points_L_9[] = { {TEMP_LEFT_LINE_A_LINE_10_X_START, TEMP_LEFT_LINE_A_LINE_10_Y_START}, {TEMP_LEFT_LINE_A_LINE_10_X_END, TEMP_LEFT_LINE_A_LINE_10_Y_END}};
//					/*Create style*/
//					static lv_style_t style_line_L_9;
//					lv_style_init(&style_line_L_9);
//					lv_style_set_line_width(&style_line_L_9, 12);
//#ifndef LEFT_DRAW_LINE_1_COLOR_RED
//					//lv_style_set_line_opa(&style_line_L_9, 56);
//					lv_style_set_line_color(&style_line_L_9, first_line_color);
//#else
//					lv_style_set_line_color(&style_line_L_9, lv_palette_main(LV_PALETTE_RED));
//#endif
//					lv_style_set_line_rounded(&style_line_L_9, false);
//					/*Create a line and apply the new style*/
//					//lv_obj_t * line10;
//					guider_ui.templine10 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//					lv_line_set_points(guider_ui.templine10, line_points_L_9, 2);     /*Set the points*/
//					lv_obj_add_style(guider_ui.templine10, &style_line_L_9, 0);
//					//lv_obj_center(line1);
//					//lv_task_handler();  // Update the display

	    			//final
	    			// first time draw completed
	    			temp_left_draw_line_1_first_draw_forward_switch=0;
	    			temp_left_draw_line_1_first_draw_forward = 0;
	    			temp_left_draw_line_1_draw_backward_switch = 1;
					break;

				default :
					break;
				}

				//lv_task_handler();  // Update the display
			}
			else
			{
				if(temp_left_draw_line_1_draw_backward_switch)
				{
					switch (temp_left_draw_line_1_draw_backward_switch_case)
					{
					case 0 :
						lv_obj_add_flag(guider_ui.templine10, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_backward_switch_case++;
						break;
					case 1 :
						lv_obj_add_flag(guider_ui.templine9, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_backward_switch_case++;
						break;
					case 2 :
						lv_obj_add_flag(guider_ui.templine8, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_backward_switch_case++;
						break;
					case 3 :
						lv_obj_add_flag(guider_ui.templine7, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_backward_switch_case++;
						break;
					case 4 :
						lv_obj_add_flag(guider_ui.templine6, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_backward_switch_case++;
						break;
					case 5 :
						lv_obj_add_flag(guider_ui.templine5, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_backward_switch_case++;
						break;
					case 6 :
						lv_obj_add_flag(guider_ui.templine4, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_backward_switch_case++;
						break;
					case 7 :
						lv_obj_add_flag(guider_ui.templine3, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_backward_switch_case++;
						break;
					case 8 :
						lv_obj_add_flag(guider_ui.templine2, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_backward_switch_case++;
						break;
					case 9 :
						lv_obj_add_flag(guider_ui.templine1, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_backward_switch_case++;
						break;
					case 10 :
						lv_obj_add_flag(guider_ui.screen_drawing_canvas_triangle_R_2, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_backward_switch_case++;
						break;
					case 11 :
						lv_obj_add_flag(guider_ui.screen_drawing_canvas_triangle_R_1, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_backward_switch_case++;
						temp_left_draw_line_1_draw_backward_switch_case=0;
						temp_left_draw_line_1_draw_backward_switch = 0;
						temp_left_draw_line_1_draw_forward_switch = 1;
						temp_left_draw_line_1_draw_forward_switch_case = 0;
						break;
					default:
						break;
					}

				}
				else if (temp_left_draw_line_1_draw_forward_switch)
				{
					switch (temp_left_draw_line_1_draw_forward_switch_case)
					{
					case 0 :
						lv_obj_clear_flag(guider_ui.screen_drawing_canvas_triangle_R_1, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_forward_switch_case++;
						break;
					case 1 :
						lv_obj_clear_flag(guider_ui.screen_drawing_canvas_triangle_R_2, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_forward_switch_case++;
						break;
					case 2 :
						lv_obj_clear_flag(guider_ui.templine1, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_forward_switch_case++;
						break;
					case 3 :
						lv_obj_clear_flag(guider_ui.templine2, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_forward_switch_case++;
						break;
					case 4 :
						lv_obj_clear_flag(guider_ui.templine3, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_forward_switch_case++;
						break;
					case 5 :
						lv_obj_clear_flag(guider_ui.templine4, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_forward_switch_case++;
						break;
					case 6 :
						lv_obj_clear_flag(guider_ui.templine5, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_forward_switch_case++;
						break;
					case 7 :
						lv_obj_clear_flag(guider_ui.templine6, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_forward_switch_case++;
						break;
					case 8 :
						lv_obj_clear_flag(guider_ui.templine7, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_forward_switch_case++;
						break;
					case 9 :
						lv_obj_clear_flag(guider_ui.templine8, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_forward_switch_case++;
						break;
					case 10 :
						lv_obj_clear_flag(guider_ui.templine9, LV_OBJ_FLAG_HIDDEN);
						temp_left_draw_line_1_draw_forward_switch_case++;
						break;
					case 11 :
						lv_obj_clear_flag(guider_ui.templine10, LV_OBJ_FLAG_HIDDEN);

						temp_left_draw_line_1_draw_forward_switch_case = 0;
						temp_left_draw_line_1_draw_forward_switch = 0;
						temp_left_draw_line_1_draw_backward_switch = 1;
						temp_left_draw_line_1_draw_backward_switch_case = 0;
						break;
					default:
						break;
					}

				}
				else
				{
					// do nothing
				}

			}

		}

		if(temp_line_1_start_timer)
		{
			temp_drawing_screen = 0;
			temp_drawing_screen_inc_enable = 1;

			temp_line_1_start_timer_exp = 0;
			temp_line_1_start_timer = 0;
		}
		// 35 msec : keep calling : lv_task_handler()
		if (temp_drawing_screen >= 5)  // Minimum : delay for 10 msec --> i.e animation time --> till that time call --> lv_task_handler()
		{
			temp_line_1_start_timer_exp = 1;
			temp_drawing_screen_inc_enable = 0;
			temp_line_1_start_timer = 1;

		}


		//lv_task_handler();  // Update the display

	}

}


void temp_create_lines(void)
{

#ifndef LEFT_DRAW_LINE_1_COLOR_RED
	//lv_color_t first_line_color = LV_COLOR_MAKE(0,0,255);
	lv_color_t first_line_color = LV_COLOR_MAKE(0x1e, 0xca, 0x1c);
#endif
	//lv_color_t last_line_color = LV_COLOR_MAKE(254,43,43);
	lv_color_t last_line_color = LV_COLOR_MAKE(168,16,31);


							// Line - 1
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = -(10+1)
							// starting -- x = prev line ending (x +1)
							//static lv_point_t line_points[] = { {214, 369}, {203, 368}};
							static lv_point_t line_points[] = { {TEMP_LEFT_LINE_A_LINE_1_X_START, TEMP_LEFT_LINE_A_LINE_1_Y_START}, {TEMP_LEFT_LINE_A_LINE_1_X_END, TEMP_LEFT_LINE_A_LINE_1_Y_END}};
							//lv_color_t
							/*Create style*/
							static lv_style_t style_line;
							lv_style_init(&style_line);
							lv_style_set_line_width(&style_line, 12);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							//lv_style_set_line_opa(&style_line, TEMP_LINE_OPA);
							lv_style_set_line_color(&style_line, last_line_color);
		#else
							lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line1;
							guider_ui.templine1 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.templine1, line_points, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.templine1, &style_line, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 2
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							//static lv_point_t line_points_L_1[] = { {204, 368}, {193, 367}};
							static lv_point_t line_points_L_1[] = { {TEMP_LEFT_LINE_A_LINE_2_X_START, TEMP_LEFT_LINE_A_LINE_2_Y_START}, {TEMP_LEFT_LINE_A_LINE_2_X_END, TEMP_LEFT_LINE_A_LINE_2_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_1;
							lv_style_init(&style_line_L_1);
							lv_style_set_line_width(&style_line_L_1, 12);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_1, TEMP_LINE_OPA);
							lv_style_set_line_color(&style_line_L_1, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_1, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_1, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line2;
							guider_ui.templine2 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.templine2, line_points_L_1, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.templine2, &style_line_L_1, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 3
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_2[] = { {TEMP_LEFT_LINE_A_LINE_3_X_START, TEMP_LEFT_LINE_A_LINE_3_Y_START}, {TEMP_LEFT_LINE_A_LINE_3_X_END, TEMP_LEFT_LINE_A_LINE_3_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_2;
							lv_style_init(&style_line_L_2);
							lv_style_set_line_width(&style_line_L_2, 12);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_2, TEMP_LINE_OPA);
							lv_style_set_line_color(&style_line_L_2, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_2, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_2, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line3;
							guider_ui.templine3 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.templine3, line_points_L_2, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.templine3, &style_line_L_2, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display


							// Line - 4
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_3[] = { {TEMP_LEFT_LINE_A_LINE_4_X_START, TEMP_LEFT_LINE_A_LINE_4_Y_START}, {TEMP_LEFT_LINE_A_LINE_4_X_END, TEMP_LEFT_LINE_A_LINE_4_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_3;
							lv_style_init(&style_line_L_3);
							lv_style_set_line_width(&style_line_L_3, 12);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_3, TEMP_LINE_OPA);
							lv_style_set_line_color(&style_line_L_3, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_3, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_3, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line4;
							guider_ui.templine4 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.templine4, line_points_L_3, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.templine4, &style_line_L_3, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 5
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_4[] = { {TEMP_LEFT_LINE_A_LINE_5_X_START, TEMP_LEFT_LINE_A_LINE_5_Y_START}, {TEMP_LEFT_LINE_A_LINE_5_X_END, TEMP_LEFT_LINE_A_LINE_5_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_4;
							lv_style_init(&style_line_L_4);
							lv_style_set_line_width(&style_line_L_4, 12);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_4, TEMP_LINE_OPA);
							lv_style_set_line_color(&style_line_L_4, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_4, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_4, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line5;
							guider_ui.templine5 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.templine5, line_points_L_4, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.templine5, &style_line_L_4, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 6
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_5[] = { {TEMP_LEFT_LINE_A_LINE_6_X_START, TEMP_LEFT_LINE_A_LINE_6_Y_START}, {TEMP_LEFT_LINE_A_LINE_6_X_END, TEMP_LEFT_LINE_A_LINE_6_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_5;
							lv_style_init(&style_line_L_5);
							lv_style_set_line_width(&style_line_L_5, 12);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_5, TEMP_LINE_OPA);
							lv_style_set_line_color(&style_line_L_5, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_5, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_5, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line6;
							guider_ui.templine6 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.templine6, line_points_L_5, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.templine6, &style_line_L_5, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 7
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_6[] = { {TEMP_LEFT_LINE_A_LINE_7_X_START, TEMP_LEFT_LINE_A_LINE_7_Y_START}, {TEMP_LEFT_LINE_A_LINE_7_X_END, TEMP_LEFT_LINE_A_LINE_7_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_6;
							lv_style_init(&style_line_L_6);
							lv_style_set_line_width(&style_line_L_6, 12);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_6, TEMP_LINE_OPA);
							lv_style_set_line_color(&style_line_L_6, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_6, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_6, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line7;
							guider_ui.templine7 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.templine7, line_points_L_6, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.templine7, &style_line_L_6, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 8
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_7[] = { {TEMP_LEFT_LINE_A_LINE_8_X_START, TEMP_LEFT_LINE_A_LINE_8_Y_START}, {TEMP_LEFT_LINE_A_LINE_8_X_END, TEMP_LEFT_LINE_A_LINE_8_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_7;
							lv_style_init(&style_line_L_7);
							lv_style_set_line_width(&style_line_L_7, 12);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_7, TEMP_LINE_OPA);
							lv_style_set_line_color(&style_line_L_7, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_7, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_7, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line8;
							guider_ui.templine8 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.templine8, line_points_L_7, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.templine8, &style_line_L_7, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 9
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_8[] = { {TEMP_LEFT_LINE_A_LINE_9_X_START, TEMP_LEFT_LINE_A_LINE_9_Y_START}, {TEMP_LEFT_LINE_A_LINE_9_X_END, TEMP_LEFT_LINE_A_LINE_9_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_8;
							lv_style_init(&style_line_L_8);
							lv_style_set_line_width(&style_line_L_8, 12);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_8, TEMP_LINE_OPA);
							lv_style_set_line_color(&style_line_L_8, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_8, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_8, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line9;
							guider_ui.templine9 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.templine9, line_points_L_8, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.templine9, &style_line_L_8, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 10
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_9[] = { {TEMP_LEFT_LINE_A_LINE_10_X_START, TEMP_LEFT_LINE_A_LINE_10_Y_START}, {TEMP_LEFT_LINE_A_LINE_10_X_END, TEMP_LEFT_LINE_A_LINE_10_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_9;
							lv_style_init(&style_line_L_9);
							lv_style_set_line_width(&style_line_L_9, 12);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_9, TEMP_LINE_OPA);
							lv_style_set_line_color(&style_line_L_9, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_9, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_9, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line10;
							guider_ui.templine10 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.templine10, line_points_L_9, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.templine10, &style_line_L_9, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

}
