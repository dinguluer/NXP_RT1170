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
#include "Meter_line_draw.h"


#define METER_LINE_A_LINE_1_X_START 300
#define METER_LINE_A_LINE_1_X_END   312
#define METER_LINE_A_LINE_1_Y_START 288
#define METER_LINE_A_LINE_1_Y_END   281

#define METER_LINE_A_LINE_2_X_START 288
#define METER_LINE_A_LINE_2_X_END   301
#define METER_LINE_A_LINE_2_Y_START 259
#define METER_LINE_A_LINE_2_Y_END   255

#define METER_LINE_A_LINE_3_X_START 284
#define METER_LINE_A_LINE_3_X_END   297
#define METER_LINE_A_LINE_3_Y_START 228
#define METER_LINE_A_LINE_3_Y_END   227

#define METER_LINE_A_LINE_4_X_START 288
#define METER_LINE_A_LINE_4_X_END   301
#define METER_LINE_A_LINE_4_Y_START 196
#define METER_LINE_A_LINE_4_Y_END   200

#define METER_LINE_A_LINE_5_X_START 300
#define METER_LINE_A_LINE_5_X_END   311
#define METER_LINE_A_LINE_5_Y_START 167
#define METER_LINE_A_LINE_5_Y_END   174

#define METER_LINE_A_LINE_6_X_START 318
#define METER_LINE_A_LINE_6_X_END   328
#define METER_LINE_A_LINE_6_Y_START 142
#define METER_LINE_A_LINE_6_Y_END   152

#define METER_LINE_A_LINE_7_X_START 342
#define METER_LINE_A_LINE_7_X_END   349
#define METER_LINE_A_LINE_7_Y_START 123
#define METER_LINE_A_LINE_7_Y_END   135

#define METER_LINE_A_LINE_8_X_START 370
#define METER_LINE_A_LINE_8_X_END   373
#define METER_LINE_A_LINE_8_Y_START 110
#define METER_LINE_A_LINE_8_Y_END   124

#define METER_LINE_A_LINE_9_X_START 400
#define METER_LINE_A_LINE_9_X_END   400
#define METER_LINE_A_LINE_9_Y_START 106
#define METER_LINE_A_LINE_9_Y_END   120

#define METER_LINE_A_LINE_10_X_START 431
#define METER_LINE_A_LINE_10_X_END   428
#define METER_LINE_A_LINE_10_Y_START 110
#define METER_LINE_A_LINE_10_Y_END   124

#define METER_LINE_A_LINE_11_X_START 459
#define METER_LINE_A_LINE_11_X_END   453
#define METER_LINE_A_LINE_11_Y_START 122
#define METER_LINE_A_LINE_11_Y_END   135

#define METER_LINE_A_LINE_12_X_START 483
#define METER_LINE_A_LINE_12_X_END   474
#define METER_LINE_A_LINE_12_Y_START 141
#define METER_LINE_A_LINE_12_Y_END   151

#define METER_LINE_A_LINE_13_X_START 502
#define METER_LINE_A_LINE_13_X_END   490
#define METER_LINE_A_LINE_13_Y_START 166
#define METER_LINE_A_LINE_13_Y_END   173

#define METER_LINE_A_LINE_14_X_START 514
#define METER_LINE_A_LINE_14_X_END   501
#define METER_LINE_A_LINE_14_Y_START 195
#define METER_LINE_A_LINE_14_Y_END   199

#define METER_LINE_A_LINE_15_X_START 518
#define METER_LINE_A_LINE_15_X_END   504
#define METER_LINE_A_LINE_15_Y_START 227
#define METER_LINE_A_LINE_15_Y_END   227

#define METER_LINE_A_LINE_16_X_START 514
#define METER_LINE_A_LINE_16_X_END   502
#define METER_LINE_A_LINE_16_Y_START 257
#define METER_LINE_A_LINE_16_Y_END   254

#define METER_LINE_A_LINE_17_X_START 502
#define METER_LINE_A_LINE_17_X_END   490
#define METER_LINE_A_LINE_17_Y_START 287
#define METER_LINE_A_LINE_17_Y_END   280

#define METER_LINE_A_LINE_S_1_X_START 332
#define METER_LINE_A_LINE_S_1_X_END   295
#define METER_LINE_A_LINE_S_1_Y_START 295
#define METER_LINE_A_LINE_S_1_Y_END   333

#define METER_LINE_A_LINE_E_1_X_START 506
#define METER_LINE_A_LINE_E_1_X_END   469
#define METER_LINE_A_LINE_E_1_Y_START 331
#define METER_LINE_A_LINE_E_1_Y_END   294

#define METER_LINE_WIDTH 4
#define METER_LINE_WIDTH_END 7
#define METER_LINE_OPA_VALUE 255

void meter_create_lines(void)
{

#ifndef LEFT_DRAW_LINE_1_COLOR_RED
	static lv_color_t first_line_color = LV_COLOR_MAKE(51,51,51);
//	static lv_color_t first_line_color = LV_COLOR_MAKE(0,0,0);
//	static lv_color_t first_line_color = LV_COLOR_MAKE(128,128,128);
//	static lv_color_t first_line_color = LV_COLOR_MAKE(255,0,0);
#endif
	//lv_color_t last_line_color = LV_COLOR_MAKE(254,43,43);
	static lv_color_t last_line_color = LV_COLOR_MAKE(168,16,31);


	// Line - S_1
	//S_1 lines : y = 17/17 = 1 --> each Y dec by 1 each time
	//S_1 lines : x = S_18/17 = 10.66 = 10+1
	// starting -- x = prev line ending (x +1)
	static lv_point_t line_points_L_S_1[] = { {METER_LINE_A_LINE_S_1_X_START, METER_LINE_A_LINE_S_1_Y_START}, {METER_LINE_A_LINE_S_1_X_END, METER_LINE_A_LINE_S_1_Y_END}};
	/*Create style*/
	static lv_style_t style_line_L_S_1;
	lv_style_init(&style_line_L_S_1);
	lv_style_set_line_width(&style_line_L_S_1, METER_LINE_WIDTH_END);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
	//lv_style_set_line_opa(&style_line_L_S_1, 56);
	lv_style_set_line_color(&style_line_L_S_1, last_line_color);
#else
	lv_style_set_line_color(&style_line_L_S_1, lv_palette_main(LV_PALETTE_RED));
#endif
	lv_style_set_line_rounded(&style_line_L_S_1, false);
	/*Create a line and apply the new style*/
	//lv_obj_t * lineS_1;
	guider_ui.meterlineS_1 = lv_line_create(guider_ui.screen_drawing_container_drawing);
	lv_line_set_points(guider_ui.meterlineS_1, line_points_L_S_1, 2);     /*Set the points*/
	lv_obj_add_style(guider_ui.meterlineS_1, &style_line_L_S_1, 0);
	//lv_obj_center(line1);
	//lv_task_handler();  // Update the display



							// Line - 1
							//2 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = -(10+1)
							// starting -- x = prev line ending (x +1)
							//static lv_point_t line_points[] = { {214, 369}, {203, 368}};
							static lv_point_t line_points[] = { {METER_LINE_A_LINE_1_X_START, METER_LINE_A_LINE_1_Y_START}, {METER_LINE_A_LINE_1_X_END, METER_LINE_A_LINE_1_Y_END}};
							//lv_color_t
							/*Create style*/
							static lv_style_t style_line;
							lv_style_init(&style_line);
							lv_style_set_line_width(&style_line, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line, first_line_color);
		#else
							lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line1;
							guider_ui.meterline1 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline1, line_points, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline1, &style_line, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 2
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							//static lv_point_t line_points_L_1[] = { {204, 368}, {193, 367}};
							static lv_point_t line_points_L_1[] = { {METER_LINE_A_LINE_2_X_START, METER_LINE_A_LINE_2_Y_START}, {METER_LINE_A_LINE_2_X_END, METER_LINE_A_LINE_2_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_1;
							lv_style_init(&style_line_L_1);
							lv_style_set_line_width(&style_line_L_1, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_1, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_1, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_1, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_1, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line2;
							guider_ui.meterline2 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline2, line_points_L_1, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline2, &style_line_L_1, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 3
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_2[] = { {METER_LINE_A_LINE_3_X_START, METER_LINE_A_LINE_3_Y_START}, {METER_LINE_A_LINE_3_X_END, METER_LINE_A_LINE_3_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_2;
							lv_style_init(&style_line_L_2);
							lv_style_set_line_width(&style_line_L_2, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_2, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_2, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_2, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_2, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line3;
							guider_ui.meterline3 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline3, line_points_L_2, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline3, &style_line_L_2, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display


							// Line - 4
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_3[] = { {METER_LINE_A_LINE_4_X_START, METER_LINE_A_LINE_4_Y_START}, {METER_LINE_A_LINE_4_X_END, METER_LINE_A_LINE_4_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_3;
							lv_style_init(&style_line_L_3);
							lv_style_set_line_width(&style_line_L_3, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_3, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_3, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_3, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_3, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line4;
							guider_ui.meterline4 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline4, line_points_L_3, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline4, &style_line_L_3, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 5
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_4[] = { {METER_LINE_A_LINE_5_X_START, METER_LINE_A_LINE_5_Y_START}, {METER_LINE_A_LINE_5_X_END, METER_LINE_A_LINE_5_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_4;
							lv_style_init(&style_line_L_4);
							lv_style_set_line_width(&style_line_L_4, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_4, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_4, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_4, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_4, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line5;
							guider_ui.meterline5 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline5, line_points_L_4, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline5, &style_line_L_4, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 6
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_5[] = { {METER_LINE_A_LINE_6_X_START, METER_LINE_A_LINE_6_Y_START}, {METER_LINE_A_LINE_6_X_END, METER_LINE_A_LINE_6_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_5;
							lv_style_init(&style_line_L_5);
							lv_style_set_line_width(&style_line_L_5, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_5, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_5, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_5, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_5, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line6;
							guider_ui.meterline6 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline6, line_points_L_5, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline6, &style_line_L_5, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 7
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_6[] = { {METER_LINE_A_LINE_7_X_START, METER_LINE_A_LINE_7_Y_START}, {METER_LINE_A_LINE_7_X_END, METER_LINE_A_LINE_7_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_6;
							lv_style_init(&style_line_L_6);
							lv_style_set_line_width(&style_line_L_6, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_6, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_6, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_6, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_6, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line7;
							guider_ui.meterline7 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline7, line_points_L_6, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline7, &style_line_L_6, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 8
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_7[] = { {METER_LINE_A_LINE_8_X_START, METER_LINE_A_LINE_8_Y_START}, {METER_LINE_A_LINE_8_X_END, METER_LINE_A_LINE_8_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_7;
							lv_style_init(&style_line_L_7);
							lv_style_set_line_width(&style_line_L_7, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_7, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_7, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_7, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_7, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line8;
							guider_ui.meterline8 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline8, line_points_L_7, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline8, &style_line_L_7, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 9
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_8[] = { {METER_LINE_A_LINE_9_X_START, METER_LINE_A_LINE_9_Y_START}, {METER_LINE_A_LINE_9_X_END, METER_LINE_A_LINE_9_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_8;
							lv_style_init(&style_line_L_8);
							lv_style_set_line_width(&style_line_L_8, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_8, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_8, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_8, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_8, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line9;
							guider_ui.meterline9 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline9, line_points_L_8, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline9, &style_line_L_8, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 10
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_9[] = { {METER_LINE_A_LINE_10_X_START, METER_LINE_A_LINE_10_Y_START}, {METER_LINE_A_LINE_10_X_END, METER_LINE_A_LINE_10_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_9;
							lv_style_init(&style_line_L_9);
							lv_style_set_line_width(&style_line_L_9, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_9, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_9, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_9, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_9, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line10;
							guider_ui.meterline10 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline10, line_points_L_9, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline10, &style_line_L_9, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 11
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_11[] = { {METER_LINE_A_LINE_11_X_START, METER_LINE_A_LINE_11_Y_START}, {METER_LINE_A_LINE_11_X_END, METER_LINE_A_LINE_11_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_11;
							lv_style_init(&style_line_L_11);
							lv_style_set_line_width(&style_line_L_11, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_11, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_11, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_11, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_11, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line11;
							guider_ui.meterline11 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline11, line_points_L_11, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline11, &style_line_L_11, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 12
							//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
							//12 lines : x = 128/12 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_12[] = { {METER_LINE_A_LINE_12_X_START, METER_LINE_A_LINE_12_Y_START}, {METER_LINE_A_LINE_12_X_END, METER_LINE_A_LINE_12_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_12;
							lv_style_init(&style_line_L_12);
							lv_style_set_line_width(&style_line_L_12, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_12, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_12, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_12, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_12, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line12;
							guider_ui.meterline12 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline12, line_points_L_12, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline12, &style_line_L_12, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display


							// Line - 13
							//13 lines : y = 13/13 = 1 --> each Y dec by 1 each time
							//13 lines : x = 138/13 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_13[] = { {METER_LINE_A_LINE_13_X_START, METER_LINE_A_LINE_13_Y_START}, {METER_LINE_A_LINE_13_X_END, METER_LINE_A_LINE_13_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_13;
							lv_style_init(&style_line_L_13);
							lv_style_set_line_width(&style_line_L_13, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_13, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_13, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_13, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_13, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line13;
							guider_ui.meterline13 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline13, line_points_L_13, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline13, &style_line_L_13, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 14
							//14 lines : y = 14/14 = 1 --> each Y dec by 1 each time
							//14 lines : x = 148/14 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_14[] = { {METER_LINE_A_LINE_14_X_START, METER_LINE_A_LINE_14_Y_START}, {METER_LINE_A_LINE_14_X_END, METER_LINE_A_LINE_14_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_14;
							lv_style_init(&style_line_L_14);
							lv_style_set_line_width(&style_line_L_14, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_14, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_14, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_14, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_14, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line14;
							guider_ui.meterline14 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline14, line_points_L_14, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline14, &style_line_L_14, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display

							// Line - 15
							//15 lines : y = 15/15 = 1 --> each Y dec by 1 each time
							//15 lines : x = 158/15 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_15[] = { {METER_LINE_A_LINE_15_X_START, METER_LINE_A_LINE_15_Y_START}, {METER_LINE_A_LINE_15_X_END, METER_LINE_A_LINE_15_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_15;
							lv_style_init(&style_line_L_15);
							lv_style_set_line_width(&style_line_L_15, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_15, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_15, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_15, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_15, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line15;
							guider_ui.meterline15 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline15, line_points_L_15, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline15, &style_line_L_15, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display


							// Line - 16
							//16 lines : y = 16/16 = 1 --> each Y dec by 1 each time
							//16 lines : x = 168/16 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_16[] = { {METER_LINE_A_LINE_16_X_START, METER_LINE_A_LINE_16_Y_START}, {METER_LINE_A_LINE_16_X_END, METER_LINE_A_LINE_16_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_16;
							lv_style_init(&style_line_L_16);
							lv_style_set_line_width(&style_line_L_16, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_16, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_16, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_16, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_16, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line16;
							guider_ui.meterline16 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline16, line_points_L_16, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline16, &style_line_L_16, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display


							// Line - 17
							//17 lines : y = 17/17 = 1 --> each Y dec by 1 each time
							//17 lines : x = 178/17 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_17[] = { {METER_LINE_A_LINE_17_X_START, METER_LINE_A_LINE_17_Y_START}, {METER_LINE_A_LINE_17_X_END, METER_LINE_A_LINE_17_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_17;
							lv_style_init(&style_line_L_17);
							lv_style_set_line_width(&style_line_L_17, METER_LINE_WIDTH);
		#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							lv_style_set_line_opa(&style_line_L_17, METER_LINE_OPA_VALUE);
							lv_style_set_line_color(&style_line_L_17, first_line_color);
		#else
							lv_style_set_line_color(&style_line_L_17, lv_palette_main(LV_PALETTE_RED));
		#endif
							lv_style_set_line_rounded(&style_line_L_17, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * line17;
							guider_ui.meterline17 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterline17, line_points_L_17, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterline17, &style_line_L_17, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display


							// Line - E_1
							//E_1 lines : y = 17/17 = 1 --> each Y dec by 1 each time
							//E_1 lines : x = E_18/17 = 10.66 = 10+1
							// starting -- x = prev line ending (x +1)
							static lv_point_t line_points_L_E_1[] = { {METER_LINE_A_LINE_E_1_X_START, METER_LINE_A_LINE_E_1_Y_START}, {METER_LINE_A_LINE_E_1_X_END, METER_LINE_A_LINE_E_1_Y_END}};
							/*Create style*/
							static lv_style_t style_line_L_E_1;
							lv_style_init(&style_line_L_E_1);
							lv_style_set_line_width(&style_line_L_E_1, METER_LINE_WIDTH_END);
						#ifndef LEFT_DRAW_LINE_1_COLOR_RED
							//lv_style_set_line_opa(&style_line_L_E_1, 56);
							lv_style_set_line_color(&style_line_L_E_1, last_line_color);
						#else
							lv_style_set_line_color(&style_line_L_E_1, lv_palette_main(LV_PALETTE_RED));
						#endif
							lv_style_set_line_rounded(&style_line_L_E_1, false);
							/*Create a line and apply the new style*/
							//lv_obj_t * lineE_1;
							guider_ui.meterlineE_1 = lv_line_create(guider_ui.screen_drawing_container_drawing);
							lv_line_set_points(guider_ui.meterlineE_1, line_points_L_E_1, 2);     /*Set the points*/
							lv_obj_add_style(guider_ui.meterlineE_1, &style_line_L_E_1, 0);
							//lv_obj_center(line1);
							//lv_task_handler();  // Update the display


}
