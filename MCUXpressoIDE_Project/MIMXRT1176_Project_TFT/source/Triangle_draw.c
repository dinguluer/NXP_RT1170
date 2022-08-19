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
#include "Triangle_draw.h"



void triangle_create_lines(void)
{

//#ifndef LEFT_DRAW_LINE_1_COLOR_RED
//	lv_color_t first_line_color = LV_COLOR_MAKE(0,0,255);
//#endif
//	//lv_color_t last_line_color = LV_COLOR_MAKE(254,43,43);
//	lv_color_t last_line_color = LV_COLOR_MAKE(168,16,31);
	//static lv_color_t triag_bg_color = LV_COLOR_MAKE(0,0,255);
	static lv_color_t triag_bg_color = LV_COLOR_MAKE(168,16,31);

//================================================================ LEFT triangle ==============================================

	//Write codes screen_drawing_canvas_triangle_L_1
	guider_ui.screen_drawing_canvas_triangle_L_1 = lv_canvas_create(guider_ui.screen_drawing_container_drawing);
	lv_obj_set_pos(guider_ui.screen_drawing_canvas_triangle_L_1, 222, 439);
	lv_obj_set_size(guider_ui.screen_drawing_canvas_triangle_L_1, 18, 12);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_canvas_triangle_L_1_main_main_default
	static lv_style_t style_screen_drawing_canvas_triangle_L_1_main_main_default;
	if (style_screen_drawing_canvas_triangle_L_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_canvas_triangle_L_1_main_main_default);
	else
		lv_style_init(&style_screen_drawing_canvas_triangle_L_1_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_canvas_triangle_L_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_screen_drawing_canvas_triangle_L_1_main_main_default, 0);
	lv_obj_add_style(guider_ui.screen_drawing_canvas_triangle_L_1, &style_screen_drawing_canvas_triangle_L_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_color_t *buf_screen_drawing_triangle_canvas_L_1 = (lv_color_t*)lv_mem_alloc(18*12*4);
	lv_canvas_set_buffer(guider_ui.screen_drawing_canvas_triangle_L_1, buf_screen_drawing_triangle_canvas_L_1, 18, 12, LV_IMG_CF_TRUE_COLOR_ALPHA);
	lv_canvas_fill_bg(guider_ui.screen_drawing_canvas_triangle_L_1, lv_color_make(0x00, 0x00, 0x00), 0);
	//DInesh
	static lv_point_t line_points_triangle_L_1[] = { {8,7},{8, 12}, {17, 12}};
	static lv_draw_rect_dsc_t triangle_L_1_property;
	triangle_L_1_property.bg_color = triag_bg_color;// = LV_COLOR_MAKE(255,0,0);
	triangle_L_1_property.bg_opa = 255;
	triangle_L_1_property.border_opa = 0;
	triangle_L_1_property.outline_opa = 0;
	lv_canvas_draw_polygon(guider_ui.screen_drawing_canvas_triangle_L_1,line_points_triangle_L_1,3,&triangle_L_1_property);



	//Write codes screen_drawing_canvas_triangle_L_2
	guider_ui.screen_drawing_canvas_triangle_L_2 = lv_canvas_create(guider_ui.screen_drawing_container_drawing);
	lv_obj_set_pos(guider_ui.screen_drawing_canvas_triangle_L_2, 222, 439);
	lv_obj_set_size(guider_ui.screen_drawing_canvas_triangle_L_2, 18, 12);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_canvas_triangle_L_2_main_main_default
	static lv_style_t style_screen_drawing_canvas_triangle_L_2_main_main_default;
	if (style_screen_drawing_canvas_triangle_L_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_canvas_triangle_L_2_main_main_default);
	else
		lv_style_init(&style_screen_drawing_canvas_triangle_L_2_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_canvas_triangle_L_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_screen_drawing_canvas_triangle_L_2_main_main_default, 0);
	lv_obj_add_style(guider_ui.screen_drawing_canvas_triangle_L_2, &style_screen_drawing_canvas_triangle_L_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_color_t *buf_screen_drawing_triangle_canvas_L_2 = (lv_color_t*)lv_mem_alloc(18*12*4);
	lv_canvas_set_buffer(guider_ui.screen_drawing_canvas_triangle_L_2, buf_screen_drawing_triangle_canvas_L_2, 18, 12, LV_IMG_CF_TRUE_COLOR_ALPHA);
	lv_canvas_fill_bg(guider_ui.screen_drawing_canvas_triangle_L_2, lv_color_make(0x00, 0x00, 0x00), 0);
	//DInesh
	static lv_point_t line_points_triangle_L_2[] = { {4,0},{4, 12}, {18, 12}};
	static lv_draw_rect_dsc_t triangle_L_2_property;
	triangle_L_2_property.bg_color = triag_bg_color;// = LV_COLOR_MAKE(255,0,0);
	triangle_L_2_property.bg_opa = 255;
	triangle_L_2_property.border_opa = 0;
	triangle_L_2_property.outline_opa = 0;
	lv_canvas_draw_polygon(guider_ui.screen_drawing_canvas_triangle_L_2,line_points_triangle_L_2,3,&triangle_L_2_property);

//================================================================ Right triangle ==============================================

	//Write codes screen_drawing_canvas_triangle_R_1
	guider_ui.screen_drawing_canvas_triangle_R_1 = lv_canvas_create(guider_ui.screen_drawing_container_drawing);
	lv_obj_set_pos(guider_ui.screen_drawing_canvas_triangle_R_1, 558, 439);
	lv_obj_set_size(guider_ui.screen_drawing_canvas_triangle_R_1, 17, 12);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_canvas_triangle_R_1_main_main_default
	static lv_style_t style_screen_drawing_canvas_triangle_R_1_main_main_default;
	if (style_screen_drawing_canvas_triangle_R_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_canvas_triangle_R_1_main_main_default);
	else
		lv_style_init(&style_screen_drawing_canvas_triangle_R_1_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_canvas_triangle_R_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_screen_drawing_canvas_triangle_R_1_main_main_default, 0);
	lv_obj_add_style(guider_ui.screen_drawing_canvas_triangle_R_1, &style_screen_drawing_canvas_triangle_R_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_color_t *buf_screen_drawing_triangle_canvas_R_1 = (lv_color_t*)lv_mem_alloc(17*12*4);
	lv_canvas_set_buffer(guider_ui.screen_drawing_canvas_triangle_R_1, buf_screen_drawing_triangle_canvas_R_1, 18, 12, LV_IMG_CF_TRUE_COLOR_ALPHA);
	lv_canvas_fill_bg(guider_ui.screen_drawing_canvas_triangle_R_1, lv_color_make(0x00, 0x00, 0x00), 0);
	//DInesh
	static lv_point_t line_points_triangle_R_1[] = { {0,12},{7, 6}, {7, 12}};
	static lv_draw_rect_dsc_t triangle_R_1_property;
	triangle_R_1_property.bg_color = triag_bg_color;// = LV_COLOR_MAKE(255,0,0);
	triangle_R_1_property.bg_opa = 255;
	triangle_R_1_property.border_opa = 0;
	triangle_R_1_property.outline_opa = 0;
	lv_canvas_draw_polygon(guider_ui.screen_drawing_canvas_triangle_R_1,line_points_triangle_R_1,3,&triangle_R_1_property);


	//Write codes screen_drawing_canvas_triangle_R_2
	guider_ui.screen_drawing_canvas_triangle_R_2 = lv_canvas_create(guider_ui.screen_drawing_container_drawing);
	lv_obj_set_pos(guider_ui.screen_drawing_canvas_triangle_R_2, 558, 439);
	lv_obj_set_size(guider_ui.screen_drawing_canvas_triangle_R_2, 17, 12);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_canvas_triangle_R_2_main_main_default
	static lv_style_t style_screen_drawing_canvas_triangle_R_2_main_main_default;
	if (style_screen_drawing_canvas_triangle_R_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_canvas_triangle_R_2_main_main_default);
	else
		lv_style_init(&style_screen_drawing_canvas_triangle_R_2_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_canvas_triangle_R_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_screen_drawing_canvas_triangle_R_2_main_main_default, 0);
	lv_obj_add_style(guider_ui.screen_drawing_canvas_triangle_R_2, &style_screen_drawing_canvas_triangle_R_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_color_t *buf_screen_drawing_triangle_canvas_R_2 = (lv_color_t*)lv_mem_alloc(17*12*4);
	lv_canvas_set_buffer(guider_ui.screen_drawing_canvas_triangle_R_2, buf_screen_drawing_triangle_canvas_R_2, 18, 12, LV_IMG_CF_TRUE_COLOR_ALPHA);
	lv_canvas_fill_bg(guider_ui.screen_drawing_canvas_triangle_R_2, lv_color_make(0x00, 0x00, 0x00), 0);
	//DInesh
	static lv_point_t line_points_triangle_R_2[] = { {0,12},{16, 0}, {16, 12}};
	static lv_draw_rect_dsc_t triangle_R_2_property;
	triangle_R_2_property.bg_color = triag_bg_color;// = LV_COLOR_MAKE(255,0,0);
	triangle_R_2_property.bg_opa = 255;
	triangle_R_2_property.border_opa = 0;
	triangle_R_2_property.outline_opa = 0;
	lv_canvas_draw_polygon(guider_ui.screen_drawing_canvas_triangle_R_2,line_points_triangle_R_2,3,&triangle_R_2_property);

}
