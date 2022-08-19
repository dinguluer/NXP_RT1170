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


void setup_scr_screen_FONT(lv_ui *ui){

	//Write codes screen_FONT
	ui->screen_FONT = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_main_main_default
	static lv_style_t style_screen_font_main_main_default;
	if (style_screen_font_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_main_main_default);
	else
		lv_style_init(&style_screen_font_main_main_default);
	lv_style_set_bg_color(&style_screen_font_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_font_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT, &style_screen_font_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_FONT_cont_1
	ui->screen_FONT_cont_1 = lv_obj_create(ui->screen_FONT);
	lv_obj_set_pos(ui->screen_FONT_cont_1, 0, 0);
	lv_obj_set_size(ui->screen_FONT_cont_1, 800, 480);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_cont_1_main_main_default
	static lv_style_t style_screen_font_cont_1_main_main_default;
	if (style_screen_font_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_cont_1_main_main_default);
	else
		lv_style_init(&style_screen_font_cont_1_main_main_default);
	lv_style_set_radius(&style_screen_font_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_font_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_font_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_font_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_font_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_screen_font_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_font_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_font_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_screen_font_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_font_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_font_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_font_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT_cont_1, &style_screen_font_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_FONT_label_12
	ui->screen_FONT_label_12 = lv_label_create(ui->screen_FONT_cont_1);
	lv_obj_set_pos(ui->screen_FONT_label_12, 163, 342);
	lv_obj_set_size(ui->screen_FONT_label_12, 525, 100);
	lv_label_set_text(ui->screen_FONT_label_12, "roso_100 , ");
	lv_label_set_long_mode(ui->screen_FONT_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_FONT_label_12, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_label_12_main_main_default
	static lv_style_t style_screen_font_label_12_main_main_default;
	if (style_screen_font_label_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_label_12_main_main_default);
	else
		lv_style_init(&style_screen_font_label_12_main_main_default);
	lv_style_set_radius(&style_screen_font_label_12_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_font_label_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_font_label_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_font_label_12_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_font_label_12_main_main_default, 0);
	lv_style_set_text_color(&style_screen_font_label_12_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_font_label_12_main_main_default, &lv_font_RussoOne_Regular_100);
	lv_style_set_text_letter_space(&style_screen_font_label_12_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_font_label_12_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_font_label_12_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_font_label_12_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_font_label_12_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT_label_12, &style_screen_font_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_FONT_label_3
	ui->screen_FONT_label_3 = lv_label_create(ui->screen_FONT_cont_1);
	lv_obj_set_pos(ui->screen_FONT_label_3, 51, 137);
	lv_obj_set_size(ui->screen_FONT_label_3, 100, 32);
	lv_label_set_text(ui->screen_FONT_label_3, "default_15 , ");
	lv_label_set_long_mode(ui->screen_FONT_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_FONT_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_label_3_main_main_default
	static lv_style_t style_screen_font_label_3_main_main_default;
	if (style_screen_font_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_label_3_main_main_default);
	else
		lv_style_init(&style_screen_font_label_3_main_main_default);
	lv_style_set_radius(&style_screen_font_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_font_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_font_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_font_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_font_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_screen_font_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_font_label_3_main_main_default, &lv_font_Alatsi_Regular_15);
	lv_style_set_text_letter_space(&style_screen_font_label_3_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_font_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_font_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_font_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_font_label_3_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT_label_3, &style_screen_font_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_FONT_label_2
	ui->screen_FONT_label_2 = lv_label_create(ui->screen_FONT_cont_1);
	lv_obj_set_pos(ui->screen_FONT_label_2, 41, 108);
	lv_obj_set_size(ui->screen_FONT_label_2, 100, 32);
	lv_label_set_text(ui->screen_FONT_label_2, "default_14 , ");
	lv_label_set_long_mode(ui->screen_FONT_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_FONT_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_label_2_main_main_default
	static lv_style_t style_screen_font_label_2_main_main_default;
	if (style_screen_font_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_label_2_main_main_default);
	else
		lv_style_init(&style_screen_font_label_2_main_main_default);
	lv_style_set_radius(&style_screen_font_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_font_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_font_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_font_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_font_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_screen_font_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_font_label_2_main_main_default, &lv_font_Alatsi_Regular_14);
	lv_style_set_text_letter_space(&style_screen_font_label_2_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_font_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_font_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_font_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_font_label_2_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT_label_2, &style_screen_font_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_FONT_label_1
	ui->screen_FONT_label_1 = lv_label_create(ui->screen_FONT_cont_1);
	lv_obj_set_pos(ui->screen_FONT_label_1, 0, 70);
	lv_obj_set_size(ui->screen_FONT_label_1, 200, 32);
	lv_label_set_text(ui->screen_FONT_label_1, "default_12 , ");
	lv_label_set_long_mode(ui->screen_FONT_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_FONT_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_label_1_main_main_default
	static lv_style_t style_screen_font_label_1_main_main_default;
	if (style_screen_font_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_label_1_main_main_default);
	else
		lv_style_init(&style_screen_font_label_1_main_main_default);
	lv_style_set_radius(&style_screen_font_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_font_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_font_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_font_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_font_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_screen_font_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_font_label_1_main_main_default, &lv_font_Alatsi_Regular_12);
	lv_style_set_text_letter_space(&style_screen_font_label_1_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_font_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_font_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_font_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_font_label_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT_label_1, &style_screen_font_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_FONT_label_4
	ui->screen_FONT_label_4 = lv_label_create(ui->screen_FONT);
	lv_obj_set_pos(ui->screen_FONT_label_4, 42, 183);
	lv_obj_set_size(ui->screen_FONT_label_4, 100, 32);
	lv_label_set_text(ui->screen_FONT_label_4, "default_16 , ");
	lv_label_set_long_mode(ui->screen_FONT_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_FONT_label_4, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_label_4_main_main_default
	static lv_style_t style_screen_font_label_4_main_main_default;
	if (style_screen_font_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_label_4_main_main_default);
	else
		lv_style_init(&style_screen_font_label_4_main_main_default);
	lv_style_set_radius(&style_screen_font_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_font_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_font_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_font_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_font_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_screen_font_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_font_label_4_main_main_default, &lv_font_Alatsi_Regular_16);
	lv_style_set_text_letter_space(&style_screen_font_label_4_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_font_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_font_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_font_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_font_label_4_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT_label_4, &style_screen_font_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_FONT_label_5
	ui->screen_FONT_label_5 = lv_label_create(ui->screen_FONT);
	lv_obj_set_pos(ui->screen_FONT_label_5, 0, 232);
	lv_obj_set_size(ui->screen_FONT_label_5, 165, 32);
	lv_label_set_text(ui->screen_FONT_label_5, "default_18 , ");
	lv_label_set_long_mode(ui->screen_FONT_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_FONT_label_5, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_label_5_main_main_default
	static lv_style_t style_screen_font_label_5_main_main_default;
	if (style_screen_font_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_label_5_main_main_default);
	else
		lv_style_init(&style_screen_font_label_5_main_main_default);
	lv_style_set_radius(&style_screen_font_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_font_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_font_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_font_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_font_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_screen_font_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_font_label_5_main_main_default, &lv_font_Alatsi_Regular_18);
	lv_style_set_text_letter_space(&style_screen_font_label_5_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_font_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_font_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_font_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_font_label_5_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT_label_5, &style_screen_font_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_FONT_label_6
	ui->screen_FONT_label_6 = lv_label_create(ui->screen_FONT);
	lv_obj_set_pos(ui->screen_FONT_label_6, 0, 289);
	lv_obj_set_size(ui->screen_FONT_label_6, 180, 32);
	lv_label_set_text(ui->screen_FONT_label_6, "default_20 , ");
	lv_label_set_long_mode(ui->screen_FONT_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_FONT_label_6, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_label_6_main_main_default
	static lv_style_t style_screen_font_label_6_main_main_default;
	if (style_screen_font_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_label_6_main_main_default);
	else
		lv_style_init(&style_screen_font_label_6_main_main_default);
	lv_style_set_radius(&style_screen_font_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_font_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_font_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_font_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_font_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_screen_font_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_font_label_6_main_main_default, &lv_font_Alatsi_Regular_20);
	lv_style_set_text_letter_space(&style_screen_font_label_6_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_font_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_font_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_font_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_font_label_6_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT_label_6, &style_screen_font_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_FONT_label_7
	ui->screen_FONT_label_7 = lv_label_create(ui->screen_FONT);
	lv_obj_set_pos(ui->screen_FONT_label_7, 0, 328);
	lv_obj_set_size(ui->screen_FONT_label_7, 162, 32);
	lv_label_set_text(ui->screen_FONT_label_7, "default_22 , ");
	lv_label_set_long_mode(ui->screen_FONT_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_FONT_label_7, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_label_7_main_main_default
	static lv_style_t style_screen_font_label_7_main_main_default;
	if (style_screen_font_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_label_7_main_main_default);
	else
		lv_style_init(&style_screen_font_label_7_main_main_default);
	lv_style_set_radius(&style_screen_font_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_font_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_font_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_font_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_font_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_screen_font_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_font_label_7_main_main_default, &lv_font_Alatsi_Regular_22);
	lv_style_set_text_letter_space(&style_screen_font_label_7_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_font_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_font_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_font_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_font_label_7_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT_label_7, &style_screen_font_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_FONT_label_8
	ui->screen_FONT_label_8 = lv_label_create(ui->screen_FONT);
	lv_obj_set_pos(ui->screen_FONT_label_8, 257, 52);
	lv_obj_set_size(ui->screen_FONT_label_8, 333, 59);
	lv_label_set_text(ui->screen_FONT_label_8, "default_60 , ");
	lv_label_set_long_mode(ui->screen_FONT_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_FONT_label_8, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_label_8_main_main_default
	static lv_style_t style_screen_font_label_8_main_main_default;
	if (style_screen_font_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_label_8_main_main_default);
	else
		lv_style_init(&style_screen_font_label_8_main_main_default);
	lv_style_set_radius(&style_screen_font_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_font_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_font_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_font_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_font_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_screen_font_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_font_label_8_main_main_default, &lv_font_Alatsi_Regular_60);
	lv_style_set_text_letter_space(&style_screen_font_label_8_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_font_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_font_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_font_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_font_label_8_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT_label_8, &style_screen_font_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_FONT_label_10
	ui->screen_FONT_label_10 = lv_label_create(ui->screen_FONT);
	lv_obj_set_pos(ui->screen_FONT_label_10, 250, 125);
	lv_obj_set_size(ui->screen_FONT_label_10, 472, 80);
	lv_label_set_text(ui->screen_FONT_label_10, "default_80 , ");
	lv_label_set_long_mode(ui->screen_FONT_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_FONT_label_10, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_label_10_main_main_default
	static lv_style_t style_screen_font_label_10_main_main_default;
	if (style_screen_font_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_label_10_main_main_default);
	else
		lv_style_init(&style_screen_font_label_10_main_main_default);
	lv_style_set_radius(&style_screen_font_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_font_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_font_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_font_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_font_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_screen_font_label_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_font_label_10_main_main_default, &lv_font_Alatsi_Regular_80);
	lv_style_set_text_letter_space(&style_screen_font_label_10_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_font_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_font_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_font_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_font_label_10_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT_label_10, &style_screen_font_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_FONT_label_11
	ui->screen_FONT_label_11 = lv_label_create(ui->screen_FONT);
	lv_obj_set_pos(ui->screen_FONT_label_11, 129, 235);
	lv_obj_set_size(ui->screen_FONT_label_11, 671, 140);
	lv_label_set_text(ui->screen_FONT_label_11, "default_100 , ");
	lv_label_set_long_mode(ui->screen_FONT_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_FONT_label_11, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_font_label_11_main_main_default
	static lv_style_t style_screen_font_label_11_main_main_default;
	if (style_screen_font_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_font_label_11_main_main_default);
	else
		lv_style_init(&style_screen_font_label_11_main_main_default);
	lv_style_set_radius(&style_screen_font_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_font_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_font_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_font_label_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_font_label_11_main_main_default, 0);
	lv_style_set_text_color(&style_screen_font_label_11_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_font_label_11_main_main_default, &lv_font_Alatsi_Regular_100);
	lv_style_set_text_letter_space(&style_screen_font_label_11_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_font_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_font_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_font_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_font_label_11_main_main_default, 0);
	lv_obj_add_style(ui->screen_FONT_label_11, &style_screen_font_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}