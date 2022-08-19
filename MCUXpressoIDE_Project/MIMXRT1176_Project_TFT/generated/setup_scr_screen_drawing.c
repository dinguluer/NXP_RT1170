/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

#include "Battery_draw.h"
#include "Temp_draw.h"
#include "Triangle_draw.h"
#include "Meter_line_draw.h"

//#define SCREEN_DRAWING_RPM_LABEL_FONT lv_font_simsun_16
//#define SCREEN_DRAWING_DATE_TIME_LABEL_FONT lv_font_simsun_20
//#define SCREEN_DRAWING_SPEED_RPM_UNIT_LABEL_FONT lv_font_simsun_15
//#define SCREEN_DRAWING_FUEL_EMPTY_FULL_GEAR_LABEL_FONT lv_font_simsun_14
//#define SCREEN_DRAWING_GEAR_VALUE_FONT lv_font_simsun_80
//#define SCREEN_DRAWING_RPM_SPEED_VALUE_FONT lv_font_DSEG7Classic_Regular_80

#define SCREEN_DRAWING_RPM_LABEL_FONT lv_font_Alatsi_Regular_16
#define SCREEN_DRAWING_DATE_TIME_LABEL_FONT lv_font_Alatsi_Regular_20
#define SCREEN_DRAWING_SPEED_RPM_UNIT_LABEL_FONT lv_font_Alatsi_Regular_15
#define SCREEN_DRAWING_FUEL_EMPTY_FULL_GEAR_LABEL_FONT lv_font_Alatsi_Regular_14
#define SCREEN_DRAWING_GEAR_VALUE_FONT lv_font_Alatsi_Regular_80
#define SCREEN_DRAWING_RPM_SPEED_VALUE_FONT lv_font_RussoOne_Regular_100
//#define SCREEN_DRAWING_RPM_SPEED_VALUE_FONT lv_font_RussoOne_Regular_80

/*
 lv_font_simsun_12
lv_font_simsun_14
lv_font_simsun_15
lv_font_simsun_16
lv_font_simsun_18
lv_font_simsun_20
lv_font_simsun_22
lv_font_simsun_60
lv_font_simsun_80
lv_font_simsun_100
lv_font_DSEG7Classic_Regular_80
lv_font_montserratMedium_22
lv_font_montserratMedium_20


 *
 */

void setup_scr_screen_drawing(lv_ui *ui){

	//Write codes screen_drawing
	ui->screen_drawing = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_main_main_default
	static lv_style_t style_screen_drawing_main_main_default;
	if (style_screen_drawing_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_main_main_default);
	else
		lv_style_init(&style_screen_drawing_main_main_default);
	lv_style_set_bg_color(&style_screen_drawing_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_drawing_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing, &style_screen_drawing_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_container_drawing
	ui->screen_drawing_container_drawing = lv_obj_create(ui->screen_drawing);
	lv_obj_set_pos(ui->screen_drawing_container_drawing, 0, 0);
	lv_obj_set_size(ui->screen_drawing_container_drawing, 800, 480);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_container_drawing_main_main_default
	static lv_style_t style_screen_drawing_container_drawing_main_main_default;
	if (style_screen_drawing_container_drawing_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_container_drawing_main_main_default);
	else
		lv_style_init(&style_screen_drawing_container_drawing_main_main_default);
	lv_style_set_radius(&style_screen_drawing_container_drawing_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_container_drawing_main_main_default, lv_color_make(0x11, 0x12, 0x12));
	lv_style_set_bg_grad_color(&style_screen_drawing_container_drawing_main_main_default, lv_color_make(0x0b, 0x0c, 0x0c));
	lv_style_set_bg_grad_dir(&style_screen_drawing_container_drawing_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_container_drawing_main_main_default, 255);
	lv_style_set_border_color(&style_screen_drawing_container_drawing_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_drawing_container_drawing_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_drawing_container_drawing_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_container_drawing_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_container_drawing_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_container_drawing_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_container_drawing_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_container_drawing, &style_screen_drawing_container_drawing_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Draw Triangle
	triangle_create_lines();

	//Write codes screen_drawing_RPM_18
	ui->screen_drawing_RPM_18 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_18, 490, 305);
	lv_obj_set_size(ui->screen_drawing_RPM_18, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_18, "18");
	lv_label_set_long_mode(ui->screen_drawing_RPM_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_18, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_18_main_main_default
	static lv_style_t style_screen_drawing_rpm_18_main_main_default;
	if (style_screen_drawing_rpm_18_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_18_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_18_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_18_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_18_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_18_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_18_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_18_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_18_main_main_default, lv_color_make(0xa8, 0x10, 0x1f));
	lv_style_set_text_font(&style_screen_drawing_rpm_18_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_18_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_rpm_18_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_18_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_18_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_18_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_18, &style_screen_drawing_rpm_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_17
	ui->screen_drawing_RPM_17 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_17, 505, 282);
	lv_obj_set_size(ui->screen_drawing_RPM_17, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_17, "17");
	lv_label_set_long_mode(ui->screen_drawing_RPM_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_17, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_17_main_main_default
	static lv_style_t style_screen_drawing_rpm_17_main_main_default;
	if (style_screen_drawing_rpm_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_17_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_17_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_17_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_17_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_17_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_17_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_17_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_17_main_main_default, lv_color_make(0xa8, 0x10, 0x1f));
	lv_style_set_text_font(&style_screen_drawing_rpm_17_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_17_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_rpm_17_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_17_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_17_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_17_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_17, &style_screen_drawing_rpm_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_16
	ui->screen_drawing_RPM_16 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_16, 518, 249);
	lv_obj_set_size(ui->screen_drawing_RPM_16, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_16, "16");
	lv_label_set_long_mode(ui->screen_drawing_RPM_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_16, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_16_main_main_default
	static lv_style_t style_screen_drawing_rpm_16_main_main_default;
	if (style_screen_drawing_rpm_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_16_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_16_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_16_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_16_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_16_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_16_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_16_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_16_main_main_default, lv_color_make(0xa8, 0x10, 0x1f));
	lv_style_set_text_font(&style_screen_drawing_rpm_16_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_16_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_rpm_16_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_16_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_16_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_16_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_16, &style_screen_drawing_rpm_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_15
	ui->screen_drawing_RPM_15 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_15, 521, 216);
	lv_obj_set_size(ui->screen_drawing_RPM_15, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_15, "15");
	lv_label_set_long_mode(ui->screen_drawing_RPM_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_15, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_15_main_main_default
	static lv_style_t style_screen_drawing_rpm_15_main_main_default;
	if (style_screen_drawing_rpm_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_15_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_15_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_15_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_15_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_15_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_15_main_main_default, lv_color_make(0xa8, 0x10, 0x1f));
	lv_style_set_text_font(&style_screen_drawing_rpm_15_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_15_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_rpm_15_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_15_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_15_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_15_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_15, &style_screen_drawing_rpm_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_14
	ui->screen_drawing_RPM_14 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_14, 517, 180);
	lv_obj_set_size(ui->screen_drawing_RPM_14, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_14, "14");
	lv_label_set_long_mode(ui->screen_drawing_RPM_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_14, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_14_main_main_default
	static lv_style_t style_screen_drawing_rpm_14_main_main_default;
	if (style_screen_drawing_rpm_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_14_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_14_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_14_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_14_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_14_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_14_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_14_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_14_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_14_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_14_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_rpm_14_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_14_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_14_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_14_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_14, &style_screen_drawing_rpm_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_13
	ui->screen_drawing_RPM_13 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_13, 505, 151);
	lv_obj_set_size(ui->screen_drawing_RPM_13, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_13, "13");
	lv_label_set_long_mode(ui->screen_drawing_RPM_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_13, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_13_main_main_default
	static lv_style_t style_screen_drawing_rpm_13_main_main_default;
	if (style_screen_drawing_rpm_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_13_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_13_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_13_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_13_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_13_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_13_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_13_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_13_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_rpm_13_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_13_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_13_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_13_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_13, &style_screen_drawing_rpm_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_12
	ui->screen_drawing_RPM_12 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_12, 484, 124);
	lv_obj_set_size(ui->screen_drawing_RPM_12, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_12, "12");
	lv_label_set_long_mode(ui->screen_drawing_RPM_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_12, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_12_main_main_default
	static lv_style_t style_screen_drawing_rpm_12_main_main_default;
	if (style_screen_drawing_rpm_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_12_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_12_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_12_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_12_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_12_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_12_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_12_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_12_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_rpm_12_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_12_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_12_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_12_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_12, &style_screen_drawing_rpm_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_11
	ui->screen_drawing_RPM_11 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_11, 456, 103);
	lv_obj_set_size(ui->screen_drawing_RPM_11, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_11, "11");
	lv_label_set_long_mode(ui->screen_drawing_RPM_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_11, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_11_main_main_default
	static lv_style_t style_screen_drawing_rpm_11_main_main_default;
	if (style_screen_drawing_rpm_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_11_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_11_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_11_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_11_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_11_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_11_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_11_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_rpm_11_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_11_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_11_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_11, &style_screen_drawing_rpm_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_10
	ui->screen_drawing_RPM_10 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_10, 425, 91);
	lv_obj_set_size(ui->screen_drawing_RPM_10, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_10, "10");
	lv_label_set_long_mode(ui->screen_drawing_RPM_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_10, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_10_main_main_default
	static lv_style_t style_screen_drawing_rpm_10_main_main_default;
	if (style_screen_drawing_rpm_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_10_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_10_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_10_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_10_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_10_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_10_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_10_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_rpm_10_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_10_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_10_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_10, &style_screen_drawing_rpm_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_9
	ui->screen_drawing_RPM_9 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_9, 390, 88);
	lv_obj_set_size(ui->screen_drawing_RPM_9, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_9, "9");
	lv_label_set_long_mode(ui->screen_drawing_RPM_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_9, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_9_main_main_default
	static lv_style_t style_screen_drawing_rpm_9_main_main_default;
	if (style_screen_drawing_rpm_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_9_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_9_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_9_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_9_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_9_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_9_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_9_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_drawing_rpm_9_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_9_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_9_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_9, &style_screen_drawing_rpm_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_8
	ui->screen_drawing_RPM_8 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_8, 357, 92);
	lv_obj_set_size(ui->screen_drawing_RPM_8, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_8, "8");
	lv_label_set_long_mode(ui->screen_drawing_RPM_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_8, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_8_main_main_default
	static lv_style_t style_screen_drawing_rpm_8_main_main_default;
	if (style_screen_drawing_rpm_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_8_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_8_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_8_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_8_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_8_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_8_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_8_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_drawing_rpm_8_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_8_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_8_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_8, &style_screen_drawing_rpm_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_7
	ui->screen_drawing_RPM_7 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_7, 325, 106);
	lv_obj_set_size(ui->screen_drawing_RPM_7, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_7, "7");
	lv_label_set_long_mode(ui->screen_drawing_RPM_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_7, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_7_main_main_default
	static lv_style_t style_screen_drawing_rpm_7_main_main_default;
	if (style_screen_drawing_rpm_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_7_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_7_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_7_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_7_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_7_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_7_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_7_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_drawing_rpm_7_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_7_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_7_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_7, &style_screen_drawing_rpm_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_6
	ui->screen_drawing_RPM_6 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_6, 296, 129);
	lv_obj_set_size(ui->screen_drawing_RPM_6, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_6, "6");
	lv_label_set_long_mode(ui->screen_drawing_RPM_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_6, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_6_main_main_default
	static lv_style_t style_screen_drawing_rpm_6_main_main_default;
	if (style_screen_drawing_rpm_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_6_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_6_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_6_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_6_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_6_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_6_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_6_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_drawing_rpm_6_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_6_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_6_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_6, &style_screen_drawing_rpm_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_5
	ui->screen_drawing_RPM_5 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_5, 278, 153.8235294117647);
	lv_obj_set_size(ui->screen_drawing_RPM_5, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_5, "5");
	lv_label_set_long_mode(ui->screen_drawing_RPM_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_5, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_5_main_main_default
	static lv_style_t style_screen_drawing_rpm_5_main_main_default;
	if (style_screen_drawing_rpm_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_5_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_5_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_5_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_5_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_5_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_5_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_5_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_drawing_rpm_5_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_5_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_5_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_5, &style_screen_drawing_rpm_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_4
	ui->screen_drawing_RPM_4 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_4, 266, 186.76470588235296);
	lv_obj_set_size(ui->screen_drawing_RPM_4, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_4, "4");
	lv_label_set_long_mode(ui->screen_drawing_RPM_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_4, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_4_main_main_default
	static lv_style_t style_screen_drawing_rpm_4_main_main_default;
	if (style_screen_drawing_rpm_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_4_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_4_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_4_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_4_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_4_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_4_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_4_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_drawing_rpm_4_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_4_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_4_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_4, &style_screen_drawing_rpm_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_3
	ui->screen_drawing_RPM_3 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_3, 262, 220);
	lv_obj_set_size(ui->screen_drawing_RPM_3, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_3, "3");
	lv_label_set_long_mode(ui->screen_drawing_RPM_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_3_main_main_default
	static lv_style_t style_screen_drawing_rpm_3_main_main_default;
	if (style_screen_drawing_rpm_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_3_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_3_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_3_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_3_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_3_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_3_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_3_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_drawing_rpm_3_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_3_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_3_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_3, &style_screen_drawing_rpm_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_2
	ui->screen_drawing_RPM_2 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_2, 269, 258);
	lv_obj_set_size(ui->screen_drawing_RPM_2, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_2, "2");
	lv_label_set_long_mode(ui->screen_drawing_RPM_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_2_main_main_default
	static lv_style_t style_screen_drawing_rpm_2_main_main_default;
	if (style_screen_drawing_rpm_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_2_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_2_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_2_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_2_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_2_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_2_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_2_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_drawing_rpm_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_2_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_2, &style_screen_drawing_rpm_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_1
	ui->screen_drawing_RPM_1 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_1, 283, 286);
	lv_obj_set_size(ui->screen_drawing_RPM_1, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_1, "1");
	lv_label_set_long_mode(ui->screen_drawing_RPM_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_1_main_main_default
	static lv_style_t style_screen_drawing_rpm_1_main_main_default;
	if (style_screen_drawing_rpm_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_1_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_1_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_1_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_1_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_1_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_1_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_drawing_rpm_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_1, &style_screen_drawing_rpm_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_0
	ui->screen_drawing_RPM_0 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_0, 294, 308);
	lv_obj_set_size(ui->screen_drawing_RPM_0, 20, 20);
	lv_label_set_text(ui->screen_drawing_RPM_0, "0");
	lv_label_set_long_mode(ui->screen_drawing_RPM_0, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_0, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_0_main_main_default
	static lv_style_t style_screen_drawing_rpm_0_main_main_default;
	if (style_screen_drawing_rpm_0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_0_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_0_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_0_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_0_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_0_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_rpm_0_main_main_default, &SCREEN_DRAWING_RPM_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_0_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_rpm_0_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_0_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_0_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_0_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_0, &style_screen_drawing_rpm_0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_Gear_label
	ui->screen_drawing_Gear_label = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Gear_label, 350, 238);
	lv_obj_set_size(ui->screen_drawing_Gear_label, 100, 32);
	lv_label_set_text(ui->screen_drawing_Gear_label, "Gear");
	lv_label_set_long_mode(ui->screen_drawing_Gear_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_Gear_label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_gear_label_main_main_default
	static lv_style_t style_screen_drawing_gear_label_main_main_default;
	if (style_screen_drawing_gear_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_gear_label_main_main_default);
	else
		lv_style_init(&style_screen_drawing_gear_label_main_main_default);
	lv_style_set_radius(&style_screen_drawing_gear_label_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_gear_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_gear_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_gear_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_gear_label_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_gear_label_main_main_default, lv_color_make(0x90, 0x89, 0x89));
	lv_style_set_text_font(&style_screen_drawing_gear_label_main_main_default, &SCREEN_DRAWING_FUEL_EMPTY_FULL_GEAR_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_gear_label_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_gear_label_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_gear_label_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_gear_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_gear_label_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_Gear_label, &style_screen_drawing_gear_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_GEAR_CIRCLE
	ui->screen_drawing_GEAR_CIRCLE = lv_img_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_GEAR_CIRCLE, 333, 191);
	lv_obj_set_size(ui->screen_drawing_GEAR_CIRCLE, 134, 74);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_gear_circle_main_main_default
	static lv_style_t style_screen_drawing_gear_circle_main_main_default;
	if (style_screen_drawing_gear_circle_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_gear_circle_main_main_default);
	else
		lv_style_init(&style_screen_drawing_gear_circle_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_gear_circle_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_drawing_gear_circle_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_drawing_gear_circle_main_main_default, 42);
	lv_obj_add_style(ui->screen_drawing_GEAR_CIRCLE, &style_screen_drawing_gear_circle_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_drawing_GEAR_CIRCLE, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_drawing_GEAR_CIRCLE,&_Gear_circle_134x74);
	lv_img_set_pivot(ui->screen_drawing_GEAR_CIRCLE, 0,0);
	lv_img_set_angle(ui->screen_drawing_GEAR_CIRCLE, 0);

	//Write codes screen_drawing_Gear_value_label
	ui->screen_drawing_Gear_value_label = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Gear_value_label, 349, 157);
	lv_obj_set_size(ui->screen_drawing_Gear_value_label, 100, 100);
	lv_label_set_text(ui->screen_drawing_Gear_value_label, "1");
	lv_label_set_long_mode(ui->screen_drawing_Gear_value_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_Gear_value_label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_gear_value_label_main_main_default
	static lv_style_t style_screen_drawing_gear_value_label_main_main_default;
	if (style_screen_drawing_gear_value_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_gear_value_label_main_main_default);
	else
		lv_style_init(&style_screen_drawing_gear_value_label_main_main_default);
	lv_style_set_radius(&style_screen_drawing_gear_value_label_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_gear_value_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_gear_value_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_gear_value_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_gear_value_label_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_gear_value_label_main_main_default, lv_color_make(0xb2, 0xae, 0xae));
	lv_style_set_text_font(&style_screen_drawing_gear_value_label_main_main_default, &SCREEN_DRAWING_GEAR_VALUE_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_gear_value_label_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_gear_value_label_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_gear_value_label_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_gear_value_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_gear_value_label_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_Gear_value_label, &style_screen_drawing_gear_value_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_speed_value_label
	ui->screen_drawing_speed_value_label = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_speed_value_label, 518, 180);
	lv_obj_set_size(ui->screen_drawing_speed_value_label, 262, 90);
	lv_label_set_text(ui->screen_drawing_speed_value_label, "65");
	lv_label_set_long_mode(ui->screen_drawing_speed_value_label, LV_LABEL_LONG_WRAP);
	//lv_obj_set_style_text_align(ui->screen_drawing_speed_value_label, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_set_style_text_align(ui->screen_drawing_speed_value_label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_speed_value_label_main_main_default
	static lv_style_t style_screen_drawing_speed_value_label_main_main_default;
	if (style_screen_drawing_speed_value_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_speed_value_label_main_main_default);
	else
		lv_style_init(&style_screen_drawing_speed_value_label_main_main_default);
	lv_style_set_radius(&style_screen_drawing_speed_value_label_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_speed_value_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_speed_value_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_speed_value_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_speed_value_label_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_speed_value_label_main_main_default, lv_color_make(0x00, 0x00, 0xff));
	lv_style_set_text_font(&style_screen_drawing_speed_value_label_main_main_default, &SCREEN_DRAWING_RPM_SPEED_VALUE_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_speed_value_label_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_speed_value_label_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_speed_value_label_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_speed_value_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_speed_value_label_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_speed_value_label, &style_screen_drawing_speed_value_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_speed_unit_label
	ui->screen_drawing_speed_unit_label = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_speed_unit_label, 596.6666666666667, 279);
	lv_obj_set_size(ui->screen_drawing_speed_unit_label, 100, 32);
	lv_label_set_text(ui->screen_drawing_speed_unit_label, "km/h");
	lv_label_set_long_mode(ui->screen_drawing_speed_unit_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_speed_unit_label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_speed_unit_label_main_main_default
	static lv_style_t style_screen_drawing_speed_unit_label_main_main_default;
	if (style_screen_drawing_speed_unit_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_speed_unit_label_main_main_default);
	else
		lv_style_init(&style_screen_drawing_speed_unit_label_main_main_default);
	lv_style_set_radius(&style_screen_drawing_speed_unit_label_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_speed_unit_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_speed_unit_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_speed_unit_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_speed_unit_label_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_speed_unit_label_main_main_default, lv_color_make(0x90, 0x89, 0x89));
	lv_style_set_text_font(&style_screen_drawing_speed_unit_label_main_main_default, &SCREEN_DRAWING_SPEED_RPM_UNIT_LABEL_FONT );
	lv_style_set_text_letter_space(&style_screen_drawing_speed_unit_label_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_speed_unit_label_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_speed_unit_label_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_speed_unit_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_speed_unit_label_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_speed_unit_label, &style_screen_drawing_speed_unit_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_value_label
	ui->screen_drawing_RPM_value_label = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_value_label, 15, 180);
	lv_obj_set_size(ui->screen_drawing_RPM_value_label, 262, 90);
	lv_label_set_text(ui->screen_drawing_RPM_value_label, "50");
	lv_label_set_long_mode(ui->screen_drawing_RPM_value_label, LV_LABEL_LONG_WRAP);
	//lv_obj_set_style_text_align(ui->screen_drawing_RPM_value_label, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_value_label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_value_label_main_main_default
	static lv_style_t style_screen_drawing_rpm_value_label_main_main_default;
	if (style_screen_drawing_rpm_value_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_value_label_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_value_label_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_value_label_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_value_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_value_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_value_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_value_label_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_value_label_main_main_default, lv_color_make(0x00, 0x00, 0xff));
	lv_style_set_text_font(&style_screen_drawing_rpm_value_label_main_main_default, &SCREEN_DRAWING_RPM_SPEED_VALUE_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_value_label_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_rpm_value_label_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_value_label_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_value_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_value_label_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_value_label, &style_screen_drawing_rpm_value_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_RPM_UNIT_label
	ui->screen_drawing_RPM_UNIT_label = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_RPM_UNIT_label, 95, 279);
	lv_obj_set_size(ui->screen_drawing_RPM_UNIT_label, 100, 32);
	lv_label_set_text(ui->screen_drawing_RPM_UNIT_label, "x100 rpm");
	lv_label_set_long_mode(ui->screen_drawing_RPM_UNIT_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_RPM_UNIT_label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_rpm_unit_label_main_main_default
	static lv_style_t style_screen_drawing_rpm_unit_label_main_main_default;
	if (style_screen_drawing_rpm_unit_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_rpm_unit_label_main_main_default);
	else
		lv_style_init(&style_screen_drawing_rpm_unit_label_main_main_default);
	lv_style_set_radius(&style_screen_drawing_rpm_unit_label_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_rpm_unit_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_rpm_unit_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_rpm_unit_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_rpm_unit_label_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_rpm_unit_label_main_main_default, lv_color_make(0x90, 0x89, 0x89));
	lv_style_set_text_font(&style_screen_drawing_rpm_unit_label_main_main_default, &SCREEN_DRAWING_SPEED_RPM_UNIT_LABEL_FONT );
	lv_style_set_text_letter_space(&style_screen_drawing_rpm_unit_label_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_drawing_rpm_unit_label_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_rpm_unit_label_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_rpm_unit_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_rpm_unit_label_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_RPM_UNIT_label, &style_screen_drawing_rpm_unit_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_Logo_drawing
	ui->screen_drawing_Logo_drawing = lv_img_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Logo_drawing, 340, 4);
	lv_obj_set_size(ui->screen_drawing_Logo_drawing, 113, 63);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_logo_drawing_main_main_default
	static lv_style_t style_screen_drawing_logo_drawing_main_main_default;
	if (style_screen_drawing_logo_drawing_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_logo_drawing_main_main_default);
	else
		lv_style_init(&style_screen_drawing_logo_drawing_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_logo_drawing_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_drawing_logo_drawing_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_drawing_logo_drawing_main_main_default, 67);
	lv_obj_add_style(ui->screen_drawing_Logo_drawing, &style_screen_drawing_logo_drawing_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_drawing_Logo_drawing, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_drawing_Logo_drawing,&_NXP_LOGO_113x63);
	lv_img_set_pivot(ui->screen_drawing_Logo_drawing, 0,0);
	lv_img_set_angle(ui->screen_drawing_Logo_drawing, 0);

	//Write codes screen_drawing_Time_level_drawing_1
	ui->screen_drawing_Time_level_drawing_1 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Time_level_drawing_1, 765, 9);
	lv_obj_set_size(ui->screen_drawing_Time_level_drawing_1, 25, 26);
	lv_label_set_text(ui->screen_drawing_Time_level_drawing_1, "28");
	lv_label_set_long_mode(ui->screen_drawing_Time_level_drawing_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_Time_level_drawing_1, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_time_level_drawing_1_main_main_default
	static lv_style_t style_screen_drawing_time_level_drawing_1_main_main_default;
	if (style_screen_drawing_time_level_drawing_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_time_level_drawing_1_main_main_default);
	else
		lv_style_init(&style_screen_drawing_time_level_drawing_1_main_main_default);
	lv_style_set_radius(&style_screen_drawing_time_level_drawing_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_time_level_drawing_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_time_level_drawing_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_time_level_drawing_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_time_level_drawing_1_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_time_level_drawing_1_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_time_level_drawing_1_main_main_default, &SCREEN_DRAWING_DATE_TIME_LABEL_FONT );
	lv_style_set_text_letter_space(&style_screen_drawing_time_level_drawing_1_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_drawing_time_level_drawing_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_time_level_drawing_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_time_level_drawing_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_time_level_drawing_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_Time_level_drawing_1, &style_screen_drawing_time_level_drawing_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_Time_level_drawing_0
	ui->screen_drawing_Time_level_drawing_0 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Time_level_drawing_0, 756, 9);
	lv_obj_set_size(ui->screen_drawing_Time_level_drawing_0, 11, 24);
	lv_label_set_text(ui->screen_drawing_Time_level_drawing_0, ":");
	lv_label_set_long_mode(ui->screen_drawing_Time_level_drawing_0, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_Time_level_drawing_0, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_time_level_drawing_0_main_main_default
	static lv_style_t style_screen_drawing_time_level_drawing_0_main_main_default;
	if (style_screen_drawing_time_level_drawing_0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_time_level_drawing_0_main_main_default);
	else
		lv_style_init(&style_screen_drawing_time_level_drawing_0_main_main_default);
	lv_style_set_radius(&style_screen_drawing_time_level_drawing_0_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_time_level_drawing_0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_time_level_drawing_0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_time_level_drawing_0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_time_level_drawing_0_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_time_level_drawing_0_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_time_level_drawing_0_main_main_default, &SCREEN_DRAWING_DATE_TIME_LABEL_FONT );
	lv_style_set_text_letter_space(&style_screen_drawing_time_level_drawing_0_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_drawing_time_level_drawing_0_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_time_level_drawing_0_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_time_level_drawing_0_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_time_level_drawing_0_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_Time_level_drawing_0, &style_screen_drawing_time_level_drawing_0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_Time_level_drawing
	ui->screen_drawing_Time_level_drawing = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Time_level_drawing, 716, 9);
	lv_obj_set_size(ui->screen_drawing_Time_level_drawing, 61, 31);
	lv_label_set_text(ui->screen_drawing_Time_level_drawing, "10");
	lv_label_set_long_mode(ui->screen_drawing_Time_level_drawing, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_Time_level_drawing, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_time_level_drawing_main_main_default
	static lv_style_t style_screen_drawing_time_level_drawing_main_main_default;
	if (style_screen_drawing_time_level_drawing_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_time_level_drawing_main_main_default);
	else
		lv_style_init(&style_screen_drawing_time_level_drawing_main_main_default);
	lv_style_set_radius(&style_screen_drawing_time_level_drawing_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_time_level_drawing_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_time_level_drawing_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_time_level_drawing_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_time_level_drawing_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_time_level_drawing_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_time_level_drawing_main_main_default, &SCREEN_DRAWING_DATE_TIME_LABEL_FONT );
	lv_style_set_text_letter_space(&style_screen_drawing_time_level_drawing_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_drawing_time_level_drawing_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_time_level_drawing_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_time_level_drawing_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_time_level_drawing_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_Time_level_drawing, &style_screen_drawing_time_level_drawing_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_Date_Label_drawing_2
	ui->screen_drawing_Date_Label_drawing_2 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Date_Label_drawing_2, 92, 9);
	lv_obj_set_size(ui->screen_drawing_Date_Label_drawing_2, 53, 24);
	lv_label_set_text(ui->screen_drawing_Date_Label_drawing_2, "2022");
	lv_label_set_long_mode(ui->screen_drawing_Date_Label_drawing_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_Date_Label_drawing_2, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_date_label_drawing_2_main_main_default
	static lv_style_t style_screen_drawing_date_label_drawing_2_main_main_default;
	if (style_screen_drawing_date_label_drawing_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_date_label_drawing_2_main_main_default);
	else
		lv_style_init(&style_screen_drawing_date_label_drawing_2_main_main_default);
	lv_style_set_radius(&style_screen_drawing_date_label_drawing_2_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_date_label_drawing_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_date_label_drawing_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_date_label_drawing_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_date_label_drawing_2_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_date_label_drawing_2_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_date_label_drawing_2_main_main_default, &SCREEN_DRAWING_DATE_TIME_LABEL_FONT );
	lv_style_set_text_letter_space(&style_screen_drawing_date_label_drawing_2_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_drawing_date_label_drawing_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_date_label_drawing_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_date_label_drawing_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_date_label_drawing_2_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_Date_Label_drawing_2, &style_screen_drawing_date_label_drawing_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_Date_Label_drawing_1
	ui->screen_drawing_Date_Label_drawing_1 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Date_Label_drawing_1, 82, 9);
	lv_obj_set_size(ui->screen_drawing_Date_Label_drawing_1, 7, 19);
	lv_label_set_text(ui->screen_drawing_Date_Label_drawing_1, ",");
	lv_label_set_long_mode(ui->screen_drawing_Date_Label_drawing_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_Date_Label_drawing_1, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_date_label_drawing_1_main_main_default
	static lv_style_t style_screen_drawing_date_label_drawing_1_main_main_default;
	if (style_screen_drawing_date_label_drawing_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_date_label_drawing_1_main_main_default);
	else
		lv_style_init(&style_screen_drawing_date_label_drawing_1_main_main_default);
	lv_style_set_radius(&style_screen_drawing_date_label_drawing_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_date_label_drawing_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_date_label_drawing_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_date_label_drawing_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_date_label_drawing_1_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_date_label_drawing_1_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_date_label_drawing_1_main_main_default, &SCREEN_DRAWING_DATE_TIME_LABEL_FONT );
	lv_style_set_text_letter_space(&style_screen_drawing_date_label_drawing_1_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_drawing_date_label_drawing_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_date_label_drawing_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_date_label_drawing_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_date_label_drawing_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_Date_Label_drawing_1, &style_screen_drawing_date_label_drawing_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_Date_Label_drawing_0
	ui->screen_drawing_Date_Label_drawing_0 = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Date_Label_drawing_0, 58, 9);
	lv_obj_set_size(ui->screen_drawing_Date_Label_drawing_0, 28, 22);
	lv_label_set_text(ui->screen_drawing_Date_Label_drawing_0, "24");
	lv_label_set_long_mode(ui->screen_drawing_Date_Label_drawing_0, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_Date_Label_drawing_0, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_date_label_drawing_0_main_main_default
	static lv_style_t style_screen_drawing_date_label_drawing_0_main_main_default;
	if (style_screen_drawing_date_label_drawing_0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_date_label_drawing_0_main_main_default);
	else
		lv_style_init(&style_screen_drawing_date_label_drawing_0_main_main_default);
	lv_style_set_radius(&style_screen_drawing_date_label_drawing_0_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_date_label_drawing_0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_date_label_drawing_0_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_date_label_drawing_0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_date_label_drawing_0_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_date_label_drawing_0_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_date_label_drawing_0_main_main_default, &SCREEN_DRAWING_DATE_TIME_LABEL_FONT );
	lv_style_set_text_letter_space(&style_screen_drawing_date_label_drawing_0_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_drawing_date_label_drawing_0_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_date_label_drawing_0_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_date_label_drawing_0_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_date_label_drawing_0_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_Date_Label_drawing_0, &style_screen_drawing_date_label_drawing_0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_Date_Label_drawing
	ui->screen_drawing_Date_Label_drawing = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Date_Label_drawing, 18, 9);
	lv_obj_set_size(ui->screen_drawing_Date_Label_drawing, 40, 23);
	lv_label_set_text(ui->screen_drawing_Date_Label_drawing, "May");
	lv_label_set_long_mode(ui->screen_drawing_Date_Label_drawing, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_Date_Label_drawing, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_date_label_drawing_main_main_default
	static lv_style_t style_screen_drawing_date_label_drawing_main_main_default;
	if (style_screen_drawing_date_label_drawing_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_date_label_drawing_main_main_default);
	else
		lv_style_init(&style_screen_drawing_date_label_drawing_main_main_default);
	lv_style_set_radius(&style_screen_drawing_date_label_drawing_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_date_label_drawing_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_date_label_drawing_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_date_label_drawing_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_date_label_drawing_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_date_label_drawing_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_date_label_drawing_main_main_default, &SCREEN_DRAWING_DATE_TIME_LABEL_FONT );
	lv_style_set_text_letter_space(&style_screen_drawing_date_label_drawing_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_drawing_date_label_drawing_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_date_label_drawing_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_date_label_drawing_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_date_label_drawing_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_Date_Label_drawing, &style_screen_drawing_date_label_drawing_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_drawing_Guage_1
	ui->screen_drawing_drawing_Guage_1 = lv_img_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_drawing_Guage_1, 250, 76);
	lv_obj_set_size(ui->screen_drawing_drawing_Guage_1, 300, 300);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_drawing_guage_1_main_main_default
	static lv_style_t style_screen_drawing_drawing_guage_1_main_main_default;
	if (style_screen_drawing_drawing_guage_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_drawing_guage_1_main_main_default);
	else
		lv_style_init(&style_screen_drawing_drawing_guage_1_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_drawing_guage_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_drawing_drawing_guage_1_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_drawing_drawing_guage_1_main_main_default, 255);
	lv_obj_add_style(ui->screen_drawing_drawing_Guage_1, &style_screen_drawing_drawing_guage_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_drawing_drawing_Guage_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_drawing_drawing_Guage_1,&_drawing_Guage_1_300x300);
	lv_img_set_pivot(ui->screen_drawing_drawing_Guage_1, 0,0);
	lv_img_set_angle(ui->screen_drawing_drawing_Guage_1, 0);

	//Write codes screen_drawing_cluster_image
	ui->screen_drawing_cluster_image = lv_img_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_cluster_image, 4, 60);
	lv_obj_set_size(ui->screen_drawing_cluster_image, 793, 327);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_cluster_image_main_main_default
	static lv_style_t style_screen_drawing_cluster_image_main_main_default;
	if (style_screen_drawing_cluster_image_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_cluster_image_main_main_default);
	else
		lv_style_init(&style_screen_drawing_cluster_image_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_cluster_image_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_drawing_cluster_image_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_drawing_cluster_image_main_main_default, 255);
	lv_obj_add_style(ui->screen_drawing_cluster_image, &style_screen_drawing_cluster_image_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_drawing_cluster_image, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_drawing_cluster_image,&_CLuster__drawing__background_793x327);
	lv_img_set_pivot(ui->screen_drawing_cluster_image, 0,0);
	lv_img_set_angle(ui->screen_drawing_cluster_image, 0);

	//Write codes screen_drawing_arc_indicator
	ui->screen_drawing_arc_indicator = lv_arc_create(ui->screen_drawing_container_drawing);
//	lv_obj_set_pos(ui->screen_drawing_arc_indicator, 263, 86);
//	lv_obj_set_size(ui->screen_drawing_arc_indicator, 275, 275);
	lv_obj_set_pos(ui->screen_drawing_arc_indicator, 263-4, 86);
	lv_obj_set_size(ui->screen_drawing_arc_indicator, 275+4, 275+4);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_arc_indicator_main_main_default
	static lv_style_t style_screen_drawing_arc_indicator_main_main_default;
	if (style_screen_drawing_arc_indicator_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_arc_indicator_main_main_default);
	else
		lv_style_init(&style_screen_drawing_arc_indicator_main_main_default);
	lv_style_set_bg_color(&style_screen_drawing_arc_indicator_main_main_default, lv_color_make(0xf6, 0xf6, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_arc_indicator_main_main_default, lv_color_make(0xf6, 0xf6, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_arc_indicator_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_arc_indicator_main_main_default, 0);
	lv_style_set_border_width(&style_screen_drawing_arc_indicator_main_main_default, 0);
	lv_style_set_arc_color(&style_screen_drawing_arc_indicator_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
//	lv_style_set_arc_width(&style_screen_drawing_arc_indicator_main_main_default, 16); // 12 --> dinesh
	lv_style_set_arc_width(&style_screen_drawing_arc_indicator_main_main_default, 18); // 12 --> dinesh
	lv_obj_add_style(ui->screen_drawing_arc_indicator, &style_screen_drawing_arc_indicator_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_drawing_arc_indicator, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  // Dinesh

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_arc_indicator_main_indicator_default
	static lv_style_t style_screen_drawing_arc_indicator_main_indicator_default;
	if (style_screen_drawing_arc_indicator_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_arc_indicator_main_indicator_default);
	else
		lv_style_init(&style_screen_drawing_arc_indicator_main_indicator_default);
	lv_style_set_arc_color(&style_screen_drawing_arc_indicator_main_indicator_default, lv_color_make(0xa8, 0x10, 0x1f));
//	lv_style_set_arc_width(&style_screen_drawing_arc_indicator_main_indicator_default, 16); // 12 --> dinesh
	lv_style_set_arc_width(&style_screen_drawing_arc_indicator_main_indicator_default, 18); // 12 --> dinesh
	lv_obj_add_style(ui->screen_drawing_arc_indicator, &style_screen_drawing_arc_indicator_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_arc_indicator_main_knob_default
	static lv_style_t style_screen_drawing_arc_indicator_main_knob_default;
	if (style_screen_drawing_arc_indicator_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_arc_indicator_main_knob_default);
	else
		lv_style_init(&style_screen_drawing_arc_indicator_main_knob_default);
	lv_style_set_bg_color(&style_screen_drawing_arc_indicator_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_arc_indicator_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_arc_indicator_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_arc_indicator_main_knob_default, 0);
	lv_style_set_pad_all(&style_screen_drawing_arc_indicator_main_knob_default, 5);
	lv_obj_add_style(ui->screen_drawing_arc_indicator, &style_screen_drawing_arc_indicator_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_arc_set_bg_angles(ui->screen_drawing_arc_indicator, 135, 45);
	lv_arc_set_angles(ui->screen_drawing_arc_indicator, 135, 45);
	lv_arc_set_rotation(ui->screen_drawing_arc_indicator, 0);
	lv_obj_set_style_pad_top(ui->screen_drawing_arc_indicator, 20, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_drawing_arc_indicator, 20, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_drawing_arc_indicator, 20, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_drawing_arc_indicator, 20, LV_STATE_DEFAULT);
	lv_obj_set_style_arc_rounded(ui->screen_drawing_arc_indicator, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_rounded(ui->screen_drawing_arc_indicator, 0, LV_STATE_DEFAULT);

	//Write codes screen_drawing_drawing_Guage_2
	ui->screen_drawing_drawing_Guage_2 = lv_img_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_drawing_Guage_2, 284, 106);
	//lv_obj_set_pos(ui->screen_drawing_drawing_Guage_2, 0, 20);
	lv_obj_set_size(ui->screen_drawing_drawing_Guage_2, 233, 223);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_drawing_guage_2_main_main_default
	static lv_style_t style_screen_drawing_drawing_guage_2_main_main_default;
	if (style_screen_drawing_drawing_guage_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_drawing_guage_2_main_main_default);
	else
		lv_style_init(&style_screen_drawing_drawing_guage_2_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_drawing_guage_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_drawing_drawing_guage_2_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_drawing_drawing_guage_2_main_main_default, 255);
	lv_obj_add_style(ui->screen_drawing_drawing_Guage_2, &style_screen_drawing_drawing_guage_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_drawing_drawing_Guage_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_drawing_drawing_Guage_2,&_drawing_Guage_2_233x223);
	lv_img_set_pivot(ui->screen_drawing_drawing_Guage_2, 0,0);
	lv_img_set_angle(ui->screen_drawing_drawing_Guage_2, 0);

	//Write codes screen_drawing_FUEL_image
	ui->screen_drawing_FUEL_image = lv_img_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_FUEL_image, 390, 325);
	lv_obj_set_size(ui->screen_drawing_FUEL_image, 30, 30);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_fuel_image_main_main_default
	static lv_style_t style_screen_drawing_fuel_image_main_main_default;
	if (style_screen_drawing_fuel_image_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_fuel_image_main_main_default);
	else
		lv_style_init(&style_screen_drawing_fuel_image_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_fuel_image_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_drawing_fuel_image_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_drawing_fuel_image_main_main_default, 255);
	lv_obj_add_style(ui->screen_drawing_FUEL_image, &style_screen_drawing_fuel_image_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_drawing_FUEL_image, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_drawing_FUEL_image,&_Fuel_0_30x30);
	lv_img_set_pivot(ui->screen_drawing_FUEL_image, 0,0);
	lv_img_set_angle(ui->screen_drawing_FUEL_image, 0);

	//Write codes screen_drawing_FUEL_Empty_label
	ui->screen_drawing_FUEL_Empty_label = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_FUEL_Empty_label, 311, 315);
	lv_obj_set_size(ui->screen_drawing_FUEL_Empty_label, 20, 20);
	lv_label_set_text(ui->screen_drawing_FUEL_Empty_label, "E");
	lv_label_set_long_mode(ui->screen_drawing_FUEL_Empty_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_FUEL_Empty_label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_fuel_empty_label_main_main_default
	static lv_style_t style_screen_drawing_fuel_empty_label_main_main_default;
	if (style_screen_drawing_fuel_empty_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_fuel_empty_label_main_main_default);
	else
		lv_style_init(&style_screen_drawing_fuel_empty_label_main_main_default);
	lv_style_set_radius(&style_screen_drawing_fuel_empty_label_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_fuel_empty_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_fuel_empty_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_fuel_empty_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_fuel_empty_label_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_fuel_empty_label_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_fuel_empty_label_main_main_default, &SCREEN_DRAWING_FUEL_EMPTY_FULL_GEAR_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_fuel_empty_label_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_drawing_fuel_empty_label_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_fuel_empty_label_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_fuel_empty_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_fuel_empty_label_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_FUEL_Empty_label, &style_screen_drawing_fuel_empty_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_FUEL_Full_label
	ui->screen_drawing_FUEL_Full_label = lv_label_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_FUEL_Full_label, 474.28571428571433, 314.2857142857143);
	lv_obj_set_size(ui->screen_drawing_FUEL_Full_label, 20, 20);
	lv_label_set_text(ui->screen_drawing_FUEL_Full_label, "F");
	lv_label_set_long_mode(ui->screen_drawing_FUEL_Full_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_drawing_FUEL_Full_label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_fuel_full_label_main_main_default
	static lv_style_t style_screen_drawing_fuel_full_label_main_main_default;
	if (style_screen_drawing_fuel_full_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_fuel_full_label_main_main_default);
	else
		lv_style_init(&style_screen_drawing_fuel_full_label_main_main_default);
	lv_style_set_radius(&style_screen_drawing_fuel_full_label_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_drawing_fuel_full_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_fuel_full_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_fuel_full_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_fuel_full_label_main_main_default, 0);
	lv_style_set_text_color(&style_screen_drawing_fuel_full_label_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_drawing_fuel_full_label_main_main_default, &SCREEN_DRAWING_FUEL_EMPTY_FULL_GEAR_LABEL_FONT);
	lv_style_set_text_letter_space(&style_screen_drawing_fuel_full_label_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_drawing_fuel_full_label_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_drawing_fuel_full_label_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_drawing_fuel_full_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_drawing_fuel_full_label_main_main_default, 0);
	lv_obj_add_style(ui->screen_drawing_FUEL_Full_label, &style_screen_drawing_fuel_full_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_drawing_Red_fuel_arc
	ui->screen_drawing_Red_fuel_arc = lv_arc_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Red_fuel_arc, 260, 92);
	lv_obj_set_size(ui->screen_drawing_Red_fuel_arc, 280, 280);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_red_fuel_arc_main_main_default
	static lv_style_t style_screen_drawing_red_fuel_arc_main_main_default;
	if (style_screen_drawing_red_fuel_arc_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_red_fuel_arc_main_main_default);
	else
		lv_style_init(&style_screen_drawing_red_fuel_arc_main_main_default);
	lv_style_set_bg_color(&style_screen_drawing_red_fuel_arc_main_main_default, lv_color_make(0xf6, 0xf6, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_red_fuel_arc_main_main_default, lv_color_make(0xf6, 0xf6, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_red_fuel_arc_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_red_fuel_arc_main_main_default, 0);
	lv_style_set_border_width(&style_screen_drawing_red_fuel_arc_main_main_default, 0);
	lv_style_set_arc_color(&style_screen_drawing_red_fuel_arc_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_arc_width(&style_screen_drawing_red_fuel_arc_main_main_default, 10);
	lv_obj_add_style(ui->screen_drawing_Red_fuel_arc, &style_screen_drawing_red_fuel_arc_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_drawing_Red_fuel_arc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  // Dinesh

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_red_fuel_arc_main_indicator_default
	static lv_style_t style_screen_drawing_red_fuel_arc_main_indicator_default;
	if (style_screen_drawing_red_fuel_arc_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_red_fuel_arc_main_indicator_default);
	else
		lv_style_init(&style_screen_drawing_red_fuel_arc_main_indicator_default);
	lv_style_set_arc_color(&style_screen_drawing_red_fuel_arc_main_indicator_default, lv_color_make(0xa8, 0x10, 0x1f));
	lv_style_set_arc_width(&style_screen_drawing_red_fuel_arc_main_indicator_default, 10);
	lv_obj_add_style(ui->screen_drawing_Red_fuel_arc, &style_screen_drawing_red_fuel_arc_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_red_fuel_arc_main_knob_default
	static lv_style_t style_screen_drawing_red_fuel_arc_main_knob_default;
	if (style_screen_drawing_red_fuel_arc_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_red_fuel_arc_main_knob_default);
	else
		lv_style_init(&style_screen_drawing_red_fuel_arc_main_knob_default);
	lv_style_set_bg_color(&style_screen_drawing_red_fuel_arc_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_red_fuel_arc_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_red_fuel_arc_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_red_fuel_arc_main_knob_default, 0);
	lv_style_set_pad_all(&style_screen_drawing_red_fuel_arc_main_knob_default, 5);
	lv_obj_add_style(ui->screen_drawing_Red_fuel_arc, &style_screen_drawing_red_fuel_arc_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_arc_set_bg_angles(ui->screen_drawing_Red_fuel_arc, 111, 132);
	lv_arc_set_angles(ui->screen_drawing_Red_fuel_arc, 111, 132);
	lv_arc_set_rotation(ui->screen_drawing_Red_fuel_arc, 0);
	lv_obj_set_style_pad_top(ui->screen_drawing_Red_fuel_arc, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_drawing_Red_fuel_arc, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_drawing_Red_fuel_arc, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_drawing_Red_fuel_arc, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_arc_rounded(ui->screen_drawing_Red_fuel_arc, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_rounded(ui->screen_drawing_Red_fuel_arc, 0, LV_STATE_DEFAULT);

	//Write codes screen_drawing_Green_fuel_arc
	ui->screen_drawing_Green_fuel_arc = lv_arc_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Green_fuel_arc, 260, 92);
	lv_obj_set_size(ui->screen_drawing_Green_fuel_arc, 280, 280);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_green_fuel_arc_main_main_default
	static lv_style_t style_screen_drawing_green_fuel_arc_main_main_default;
	if (style_screen_drawing_green_fuel_arc_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_green_fuel_arc_main_main_default);
	else
		lv_style_init(&style_screen_drawing_green_fuel_arc_main_main_default);
	lv_style_set_bg_color(&style_screen_drawing_green_fuel_arc_main_main_default, lv_color_make(0x11, 0x12, 0x12));
	lv_style_set_bg_grad_color(&style_screen_drawing_green_fuel_arc_main_main_default, lv_color_make(0xf6, 0xf6, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_green_fuel_arc_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_green_fuel_arc_main_main_default, 0);
	lv_style_set_border_width(&style_screen_drawing_green_fuel_arc_main_main_default, 0);
	lv_style_set_arc_color(&style_screen_drawing_green_fuel_arc_main_main_default, lv_color_make(0x11, 0x12, 0x12));
	lv_style_set_arc_width(&style_screen_drawing_green_fuel_arc_main_main_default, 12);
	lv_obj_add_style(ui->screen_drawing_Green_fuel_arc, &style_screen_drawing_green_fuel_arc_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_drawing_Green_fuel_arc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  // Dinesh

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_green_fuel_arc_main_indicator_default
	static lv_style_t style_screen_drawing_green_fuel_arc_main_indicator_default;
	if (style_screen_drawing_green_fuel_arc_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_green_fuel_arc_main_indicator_default);
	else
		lv_style_init(&style_screen_drawing_green_fuel_arc_main_indicator_default);
	lv_style_set_arc_color(&style_screen_drawing_green_fuel_arc_main_indicator_default, lv_color_make(0x1e, 0xca, 0x1c));
	lv_style_set_arc_width(&style_screen_drawing_green_fuel_arc_main_indicator_default, 10);
	lv_obj_add_style(ui->screen_drawing_Green_fuel_arc, &style_screen_drawing_green_fuel_arc_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_green_fuel_arc_main_knob_default
	static lv_style_t style_screen_drawing_green_fuel_arc_main_knob_default;
	if (style_screen_drawing_green_fuel_arc_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_green_fuel_arc_main_knob_default);
	else
		lv_style_init(&style_screen_drawing_green_fuel_arc_main_knob_default);
	lv_style_set_bg_color(&style_screen_drawing_green_fuel_arc_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_drawing_green_fuel_arc_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_drawing_green_fuel_arc_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_drawing_green_fuel_arc_main_knob_default, 0);
	lv_style_set_pad_all(&style_screen_drawing_green_fuel_arc_main_knob_default, 5);
	lv_obj_add_style(ui->screen_drawing_Green_fuel_arc, &style_screen_drawing_green_fuel_arc_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_arc_set_bg_angles(ui->screen_drawing_Green_fuel_arc, 46, 111);
	lv_arc_set_angles(ui->screen_drawing_Green_fuel_arc, 46, 111);
	lv_arc_set_rotation(ui->screen_drawing_Green_fuel_arc, 0);
	lv_obj_set_style_pad_top(ui->screen_drawing_Green_fuel_arc, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_drawing_Green_fuel_arc, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_drawing_Green_fuel_arc, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_drawing_Green_fuel_arc, 0, LV_STATE_DEFAULT);
	lv_obj_set_style_arc_rounded(ui->screen_drawing_Green_fuel_arc, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_rounded(ui->screen_drawing_Green_fuel_arc, 0, LV_STATE_DEFAULT);

	//Write codes screen_drawing_FUEL_level
	ui->screen_drawing_FUEL_level = lv_img_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_FUEL_level, 303, 326);
	lv_obj_set_size(ui->screen_drawing_FUEL_level, 197, 49);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_fuel_level_main_main_default
	static lv_style_t style_screen_drawing_fuel_level_main_main_default;
	if (style_screen_drawing_fuel_level_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_fuel_level_main_main_default);
	else
		lv_style_init(&style_screen_drawing_fuel_level_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_fuel_level_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_drawing_fuel_level_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_drawing_fuel_level_main_main_default, 255);
	lv_obj_add_style(ui->screen_drawing_FUEL_level, &style_screen_drawing_fuel_level_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_drawing_FUEL_level, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_drawing_FUEL_level,&_FUEL_level_197x49);
	lv_img_set_pivot(ui->screen_drawing_FUEL_level, 0,0);
	lv_img_set_angle(ui->screen_drawing_FUEL_level, 0);

	//Write codes screen_drawing_engine_temperature
	ui->screen_drawing_engine_temperature = lv_img_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_engine_temperature, 518, 426);
	lv_obj_set_size(ui->screen_drawing_engine_temperature, 30, 30);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_engine_temperature_main_main_default
	static lv_style_t style_screen_drawing_engine_temperature_main_main_default;
	if (style_screen_drawing_engine_temperature_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_engine_temperature_main_main_default);
	else
		lv_style_init(&style_screen_drawing_engine_temperature_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_engine_temperature_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_drawing_engine_temperature_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_drawing_engine_temperature_main_main_default, 255);
	lv_obj_add_style(ui->screen_drawing_engine_temperature, &style_screen_drawing_engine_temperature_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_drawing_engine_temperature, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_drawing_engine_temperature,&_engine_temperature_30x30);
	lv_img_set_pivot(ui->screen_drawing_engine_temperature, 0,0);
	lv_img_set_angle(ui->screen_drawing_engine_temperature, 0);

	temp_create_lines();  // dinesh

	//Write codes screen_drawing_engine_temp_drawing
	ui->screen_drawing_engine_temp_drawing = lv_img_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_engine_temp_drawing, 552, 435);
	lv_obj_set_size(ui->screen_drawing_engine_temp_drawing, 211, 20);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_engine_temp_drawing_main_main_default
	static lv_style_t style_screen_drawing_engine_temp_drawing_main_main_default;
	if (style_screen_drawing_engine_temp_drawing_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_engine_temp_drawing_main_main_default);
	else
		lv_style_init(&style_screen_drawing_engine_temp_drawing_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_engine_temp_drawing_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_drawing_engine_temp_drawing_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_drawing_engine_temp_drawing_main_main_default, 255);
	lv_obj_add_style(ui->screen_drawing_engine_temp_drawing, &style_screen_drawing_engine_temp_drawing_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_drawing_engine_temp_drawing, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_drawing_engine_temp_drawing,&_engine_temp_211x20);
	lv_img_set_pivot(ui->screen_drawing_engine_temp_drawing, 0,0);
	lv_img_set_angle(ui->screen_drawing_engine_temp_drawing, 0);

	//Write codes screen_drawing_Battery_0_drawing
	ui->screen_drawing_Battery_0_drawing = lv_img_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Battery_0_drawing, 252, 426);
	lv_obj_set_size(ui->screen_drawing_Battery_0_drawing, 30, 30);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_battery_0_drawing_main_main_default
	static lv_style_t style_screen_drawing_battery_0_drawing_main_main_default;
	if (style_screen_drawing_battery_0_drawing_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_battery_0_drawing_main_main_default);
	else
		lv_style_init(&style_screen_drawing_battery_0_drawing_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_battery_0_drawing_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_drawing_battery_0_drawing_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_drawing_battery_0_drawing_main_main_default, 255);
	lv_obj_add_style(ui->screen_drawing_Battery_0_drawing, &style_screen_drawing_battery_0_drawing_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_drawing_Battery_0_drawing, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_drawing_Battery_0_drawing,&_Battery_0_30x30);
	lv_img_set_pivot(ui->screen_drawing_Battery_0_drawing, 0,0);
	lv_img_set_angle(ui->screen_drawing_Battery_0_drawing, 0);

	battery_create_lines();  // Dinesh

	//Write codes screen_drawing_Battery_0_drawing_level
	ui->screen_drawing_Battery_0_drawing_level = lv_img_create(ui->screen_drawing_container_drawing);
	lv_obj_set_pos(ui->screen_drawing_Battery_0_drawing_level, 37, 435);
	lv_obj_set_size(ui->screen_drawing_Battery_0_drawing_level, 211, 20);

	//Write style state: LV_STATE_DEFAULT for style_screen_drawing_battery_0_drawing_level_main_main_default
	static lv_style_t style_screen_drawing_battery_0_drawing_level_main_main_default;
	if (style_screen_drawing_battery_0_drawing_level_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_drawing_battery_0_drawing_level_main_main_default);
	else
		lv_style_init(&style_screen_drawing_battery_0_drawing_level_main_main_default);
	lv_style_set_img_recolor(&style_screen_drawing_battery_0_drawing_level_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_drawing_battery_0_drawing_level_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_drawing_battery_0_drawing_level_main_main_default, 255);
	lv_obj_add_style(ui->screen_drawing_Battery_0_drawing_level, &style_screen_drawing_battery_0_drawing_level_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_drawing_Battery_0_drawing_level, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_drawing_Battery_0_drawing_level,&_Battery_level_211x20);
	lv_img_set_pivot(ui->screen_drawing_Battery_0_drawing_level, 0,0);
	lv_img_set_angle(ui->screen_drawing_Battery_0_drawing_level, 0);

	// Draw Meter line
	meter_create_lines();

	//DInesh
	lv_arc_set_range(ui->screen_drawing_arc_indicator, 0, 270);
	lv_arc_set_value(ui->screen_drawing_arc_indicator, 0);

	lv_arc_set_mode(ui->screen_drawing_Red_fuel_arc,LV_ARC_MODE_REVERSE);
	lv_arc_set_mode(ui->screen_drawing_Green_fuel_arc,LV_ARC_MODE_REVERSE);

	// screen_drawing_Red_fuel_arc  -->  111 -- 132  ---> red  ---->   i.e -->  0 to 20
	lv_arc_set_range(ui->screen_drawing_Red_fuel_arc, 0, 20);
	// screen_drawing_Green_fuel_arc  -->	46 -- 111  --> green  ---> 	i.e -->  0 to 64
	lv_arc_set_range(ui->screen_drawing_Green_fuel_arc, 0, 64);
	// set value
	lv_arc_set_value(ui->screen_drawing_Red_fuel_arc, 19);    // working value -- 19 to 0
	lv_arc_set_value(ui->screen_drawing_Green_fuel_arc, 64);  // working value -- 63 to 0
	//lv_obj_add_flag(ui->screen_drawing_Green_fuel_arc, LV_OBJ_FLAG_HIDDEN);

	lv_obj_add_flag(ui->screen_drawing_RPM_0, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_2, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_3, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_4, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_5, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_6, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_7, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_8, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_9, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_10, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_11, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_12, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_13, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_14, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_15, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_16, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_17, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_RPM_18, LV_OBJ_FLAG_HIDDEN);

	lv_obj_add_flag(ui->batteryline1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->batteryline2, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->batteryline3, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->batteryline4, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->batteryline5, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->batteryline6, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->batteryline7, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->batteryline8, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->batteryline9, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->batteryline10, LV_OBJ_FLAG_HIDDEN);

	lv_obj_add_flag(ui->templine1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->templine2, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->templine3, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->templine4, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->templine5, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->templine6, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->templine7, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->templine8, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->templine9, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->templine10, LV_OBJ_FLAG_HIDDEN);

	lv_obj_add_flag(ui->screen_drawing_canvas_triangle_L_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_canvas_triangle_L_2, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_canvas_triangle_R_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_drawing_canvas_triangle_R_2, LV_OBJ_FLAG_HIDDEN);

	lv_obj_clear_flag(ui->meterline1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline2, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline3, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline4, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline5, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline6, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline7, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline8, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline9, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline10, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline11, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline12, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline13, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline14, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline15, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline16, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui->meterline17, LV_OBJ_FLAG_HIDDEN);

	//hide guage_2
	lv_obj_add_flag(ui->screen_drawing_drawing_Guage_2, LV_OBJ_FLAG_HIDDEN);

	//lv_obj_add_flag(ui->screen_drawing_arc_indicator, LV_OBJ_FLAG_HIDDEN);

//	lv_arc_set_range(ui->screen_drawing_arc_indicator, 0, 100);
//	lv_arc_set_bg_angles(ui->screen_drawing_arc_indicator, 0, 0);
//	lv_arc_set_angles(ui->screen_drawing_arc_indicator, 135, 45);
//	lv_arc_set_value(ui->screen_drawing_arc_indicator, 0);
}
