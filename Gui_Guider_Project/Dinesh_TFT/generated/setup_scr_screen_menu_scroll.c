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


void setup_scr_screen_menu_scroll(lv_ui *ui){

	//Write codes screen_menu_scroll
	ui->screen_menu_scroll = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_main_main_default
	static lv_style_t style_screen_menu_scroll_main_main_default;
	if (style_screen_menu_scroll_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_main_main_default);
	lv_style_set_bg_color(&style_screen_menu_scroll_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_menu_scroll_main_main_default, 0);
	lv_obj_add_style(ui->screen_menu_scroll, &style_screen_menu_scroll_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_menu_scroll_Container_menu_scroll
	ui->screen_menu_scroll_Container_menu_scroll = lv_obj_create(ui->screen_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_Container_menu_scroll, 0, 0);
	lv_obj_set_size(ui->screen_menu_scroll_Container_menu_scroll, 800, 480);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_container_menu_scroll_main_main_default
	static lv_style_t style_screen_menu_scroll_container_menu_scroll_main_main_default;
	if (style_screen_menu_scroll_container_menu_scroll_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_container_menu_scroll_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_container_menu_scroll_main_main_default);
	lv_style_set_radius(&style_screen_menu_scroll_container_menu_scroll_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_menu_scroll_container_menu_scroll_main_main_default, lv_color_make(0x11, 0x12, 0x12));
	lv_style_set_bg_grad_color(&style_screen_menu_scroll_container_menu_scroll_main_main_default, lv_color_make(0x0b, 0x0c, 0x0c));
	lv_style_set_bg_grad_dir(&style_screen_menu_scroll_container_menu_scroll_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_scroll_container_menu_scroll_main_main_default, 255);
	lv_style_set_border_color(&style_screen_menu_scroll_container_menu_scroll_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_menu_scroll_container_menu_scroll_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_menu_scroll_container_menu_scroll_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_menu_scroll_container_menu_scroll_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_menu_scroll_container_menu_scroll_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_menu_scroll_container_menu_scroll_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_menu_scroll_container_menu_scroll_main_main_default, 0);
	lv_obj_add_style(ui->screen_menu_scroll_Container_menu_scroll, &style_screen_menu_scroll_container_menu_scroll_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_menu_scroll_Menu_select_label_1
	ui->screen_menu_scroll_Menu_select_label_1 = lv_label_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_Menu_select_label_1, 436, 110);
	lv_obj_set_size(ui->screen_menu_scroll_Menu_select_label_1, 330, 28);
	lv_label_set_text(ui->screen_menu_scroll_Menu_select_label_1, "Distance 72.5 Km");
	lv_label_set_long_mode(ui->screen_menu_scroll_Menu_select_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_menu_scroll_Menu_select_label_1, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_select_label_1_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_select_label_1_main_main_default;
	if (style_screen_menu_scroll_menu_select_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_select_label_1_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_select_label_1_main_main_default);
	lv_style_set_radius(&style_screen_menu_scroll_menu_select_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_menu_scroll_menu_select_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_menu_scroll_menu_select_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_menu_scroll_menu_select_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_scroll_menu_select_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_screen_menu_scroll_menu_select_label_1_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_menu_scroll_menu_select_label_1_main_main_default, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_screen_menu_scroll_menu_select_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_menu_scroll_menu_select_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_menu_scroll_menu_select_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_menu_scroll_menu_select_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_menu_scroll_menu_select_label_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_menu_scroll_Menu_select_label_1, &style_screen_menu_scroll_menu_select_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_menu_scroll_Menu_select_label_2
	ui->screen_menu_scroll_Menu_select_label_2 = lv_label_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_Menu_select_label_2, 437, 171);
	lv_obj_set_size(ui->screen_menu_scroll_Menu_select_label_2, 330, 28);
	lv_label_set_text(ui->screen_menu_scroll_Menu_select_label_2, "Time 1.36 M");
	lv_label_set_long_mode(ui->screen_menu_scroll_Menu_select_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_menu_scroll_Menu_select_label_2, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_select_label_2_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_select_label_2_main_main_default;
	if (style_screen_menu_scroll_menu_select_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_select_label_2_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_select_label_2_main_main_default);
	lv_style_set_radius(&style_screen_menu_scroll_menu_select_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_menu_scroll_menu_select_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_menu_scroll_menu_select_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_menu_scroll_menu_select_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_scroll_menu_select_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_screen_menu_scroll_menu_select_label_2_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_menu_scroll_menu_select_label_2_main_main_default, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_screen_menu_scroll_menu_select_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_menu_scroll_menu_select_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_menu_scroll_menu_select_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_menu_scroll_menu_select_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_menu_scroll_menu_select_label_2_main_main_default, 0);
	lv_obj_add_style(ui->screen_menu_scroll_Menu_select_label_2, &style_screen_menu_scroll_menu_select_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_menu_scroll_Menu_select_label_3
	ui->screen_menu_scroll_Menu_select_label_3 = lv_label_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_Menu_select_label_3, 437, 229);
	lv_obj_set_size(ui->screen_menu_scroll_Menu_select_label_3, 330, 28);
	lv_label_set_text(ui->screen_menu_scroll_Menu_select_label_3, "Avg. Speed 60 Km/h");
	lv_label_set_long_mode(ui->screen_menu_scroll_Menu_select_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_menu_scroll_Menu_select_label_3, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_select_label_3_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_select_label_3_main_main_default;
	if (style_screen_menu_scroll_menu_select_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_select_label_3_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_select_label_3_main_main_default);
	lv_style_set_radius(&style_screen_menu_scroll_menu_select_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_menu_scroll_menu_select_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_menu_scroll_menu_select_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_menu_scroll_menu_select_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_scroll_menu_select_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_screen_menu_scroll_menu_select_label_3_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_menu_scroll_menu_select_label_3_main_main_default, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_screen_menu_scroll_menu_select_label_3_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_menu_scroll_menu_select_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_menu_scroll_menu_select_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_menu_scroll_menu_select_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_menu_scroll_menu_select_label_3_main_main_default, 0);
	lv_obj_add_style(ui->screen_menu_scroll_Menu_select_label_3, &style_screen_menu_scroll_menu_select_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_menu_scroll_Menu_select_label_4
	ui->screen_menu_scroll_Menu_select_label_4 = lv_label_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_Menu_select_label_4, 437, 290);
	lv_obj_set_size(ui->screen_menu_scroll_Menu_select_label_4, 330, 28);
	lv_label_set_text(ui->screen_menu_scroll_Menu_select_label_4, "Max. Speed 70 Km/h");
	lv_label_set_long_mode(ui->screen_menu_scroll_Menu_select_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_menu_scroll_Menu_select_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_select_label_4_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_select_label_4_main_main_default;
	if (style_screen_menu_scroll_menu_select_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_select_label_4_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_select_label_4_main_main_default);
	lv_style_set_radius(&style_screen_menu_scroll_menu_select_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_menu_scroll_menu_select_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_menu_scroll_menu_select_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_menu_scroll_menu_select_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_scroll_menu_select_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_screen_menu_scroll_menu_select_label_4_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_menu_scroll_menu_select_label_4_main_main_default, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_screen_menu_scroll_menu_select_label_4_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_menu_scroll_menu_select_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_menu_scroll_menu_select_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_menu_scroll_menu_select_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_menu_scroll_menu_select_label_4_main_main_default, 0);
	lv_obj_add_style(ui->screen_menu_scroll_Menu_select_label_4, &style_screen_menu_scroll_menu_select_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_menu_scroll_Menu_select_label_5
	ui->screen_menu_scroll_Menu_select_label_5 = lv_label_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_Menu_select_label_5, 437, 350);
	lv_obj_set_size(ui->screen_menu_scroll_Menu_select_label_5, 330, 28);
	lv_label_set_text(ui->screen_menu_scroll_Menu_select_label_5, "RESET");
	lv_label_set_long_mode(ui->screen_menu_scroll_Menu_select_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_menu_scroll_Menu_select_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_select_label_5_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_select_label_5_main_main_default;
	if (style_screen_menu_scroll_menu_select_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_select_label_5_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_select_label_5_main_main_default);
	lv_style_set_radius(&style_screen_menu_scroll_menu_select_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_menu_scroll_menu_select_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_menu_scroll_menu_select_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_menu_scroll_menu_select_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_scroll_menu_select_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_screen_menu_scroll_menu_select_label_5_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_menu_scroll_menu_select_label_5_main_main_default, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_screen_menu_scroll_menu_select_label_5_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_menu_scroll_menu_select_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_menu_scroll_menu_select_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_menu_scroll_menu_select_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_menu_scroll_menu_select_label_5_main_main_default, 0);
	lv_obj_add_style(ui->screen_menu_scroll_Menu_select_label_5, &style_screen_menu_scroll_menu_select_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_menu_scroll_Menu_select_1
	ui->screen_menu_scroll_Menu_select_1 = lv_img_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_Menu_select_1, 140, 32);
	lv_obj_set_size(ui->screen_menu_scroll_Menu_select_1, 180, 130);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_select_1_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_select_1_main_main_default;
	if (style_screen_menu_scroll_menu_select_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_select_1_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_select_1_main_main_default);
	lv_style_set_img_recolor(&style_screen_menu_scroll_menu_select_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_menu_scroll_menu_select_1_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_menu_scroll_menu_select_1_main_main_default, 255);
	lv_obj_add_style(ui->screen_menu_scroll_Menu_select_1, &style_screen_menu_scroll_menu_select_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_menu_scroll_Menu_select_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_menu_scroll_Menu_select_1,&_Selection_box_180x130);
	lv_img_set_pivot(ui->screen_menu_scroll_Menu_select_1, 0,0);
	lv_img_set_angle(ui->screen_menu_scroll_Menu_select_1, 0);

	//Write codes screen_menu_scroll_Menu_select_2
	ui->screen_menu_scroll_Menu_select_2 = lv_img_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_Menu_select_2, 140, 161);
	lv_obj_set_size(ui->screen_menu_scroll_Menu_select_2, 180, 130);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_select_2_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_select_2_main_main_default;
	if (style_screen_menu_scroll_menu_select_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_select_2_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_select_2_main_main_default);
	lv_style_set_img_recolor(&style_screen_menu_scroll_menu_select_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_menu_scroll_menu_select_2_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_menu_scroll_menu_select_2_main_main_default, 255);
	lv_obj_add_style(ui->screen_menu_scroll_Menu_select_2, &style_screen_menu_scroll_menu_select_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_menu_scroll_Menu_select_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_menu_scroll_Menu_select_2,&_Selection_box_180x130);
	lv_img_set_pivot(ui->screen_menu_scroll_Menu_select_2, 0,0);
	lv_img_set_angle(ui->screen_menu_scroll_Menu_select_2, 0);

	//Write codes screen_menu_scroll_Menu_select_3
	ui->screen_menu_scroll_Menu_select_3 = lv_img_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_Menu_select_3, 140, 291);
	lv_obj_set_size(ui->screen_menu_scroll_Menu_select_3, 180, 130);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_select_3_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_select_3_main_main_default;
	if (style_screen_menu_scroll_menu_select_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_select_3_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_select_3_main_main_default);
	lv_style_set_img_recolor(&style_screen_menu_scroll_menu_select_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_menu_scroll_menu_select_3_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_menu_scroll_menu_select_3_main_main_default, 255);
	lv_obj_add_style(ui->screen_menu_scroll_Menu_select_3, &style_screen_menu_scroll_menu_select_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_menu_scroll_Menu_select_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_menu_scroll_Menu_select_3,&_Selection_box_180x130);
	lv_img_set_pivot(ui->screen_menu_scroll_Menu_select_3, 0,0);
	lv_img_set_angle(ui->screen_menu_scroll_Menu_select_3, 0);

	//Write codes screen_menu_scroll_menu_top_line
	ui->screen_menu_scroll_menu_top_line = lv_img_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_menu_top_line, 61, 11);
	lv_obj_set_size(ui->screen_menu_scroll_menu_top_line, 700, 5);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_top_line_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_top_line_main_main_default;
	if (style_screen_menu_scroll_menu_top_line_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_top_line_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_top_line_main_main_default);
	lv_style_set_img_recolor(&style_screen_menu_scroll_menu_top_line_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_menu_scroll_menu_top_line_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_menu_scroll_menu_top_line_main_main_default, 255);
	lv_obj_add_style(ui->screen_menu_scroll_menu_top_line, &style_screen_menu_scroll_menu_top_line_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_menu_scroll_menu_top_line, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_menu_scroll_menu_top_line,&_Menu_TOP_line_700x5);
	lv_img_set_pivot(ui->screen_menu_scroll_menu_top_line, 0,0);
	lv_img_set_angle(ui->screen_menu_scroll_menu_top_line, 0);

	//Write codes screen_menu_scroll_menu_bottom_line
	ui->screen_menu_scroll_menu_bottom_line = lv_img_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_menu_bottom_line, 61, 452);
	lv_obj_set_size(ui->screen_menu_scroll_menu_bottom_line, 700, 12);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_bottom_line_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_bottom_line_main_main_default;
	if (style_screen_menu_scroll_menu_bottom_line_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_bottom_line_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_bottom_line_main_main_default);
	lv_style_set_img_recolor(&style_screen_menu_scroll_menu_bottom_line_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_menu_scroll_menu_bottom_line_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_menu_scroll_menu_bottom_line_main_main_default, 255);
	lv_obj_add_style(ui->screen_menu_scroll_menu_bottom_line, &style_screen_menu_scroll_menu_bottom_line_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_menu_scroll_menu_bottom_line, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_menu_scroll_menu_bottom_line,&_Menu_Bottom_line_700x12);
	lv_img_set_pivot(ui->screen_menu_scroll_menu_bottom_line, 0,0);
	lv_img_set_angle(ui->screen_menu_scroll_menu_bottom_line, 0);

	//Write codes screen_menu_scroll_menu_vertical_line
	ui->screen_menu_scroll_menu_vertical_line = lv_img_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_menu_vertical_line, 360, 80);
	lv_obj_set_size(ui->screen_menu_scroll_menu_vertical_line, 24, 340);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_vertical_line_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_vertical_line_main_main_default;
	if (style_screen_menu_scroll_menu_vertical_line_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_vertical_line_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_vertical_line_main_main_default);
	lv_style_set_img_recolor(&style_screen_menu_scroll_menu_vertical_line_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_menu_scroll_menu_vertical_line_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_menu_scroll_menu_vertical_line_main_main_default, 75);
	lv_obj_add_style(ui->screen_menu_scroll_menu_vertical_line, &style_screen_menu_scroll_menu_vertical_line_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_menu_scroll_menu_vertical_line, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_menu_scroll_menu_vertical_line,&_Menu_vertical_line_24x340);
	lv_img_set_pivot(ui->screen_menu_scroll_menu_vertical_line, 0,0);
	lv_img_set_angle(ui->screen_menu_scroll_menu_vertical_line, 0);

	//Write codes screen_menu_scroll_menu_label
	ui->screen_menu_scroll_menu_label = lv_label_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_menu_label, 18, 110);
	lv_obj_set_size(ui->screen_menu_scroll_menu_label, 35, 250);
	lv_label_set_text(ui->screen_menu_scroll_menu_label, "MENU");
	lv_label_set_long_mode(ui->screen_menu_scroll_menu_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_menu_scroll_menu_label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_label_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_label_main_main_default;
	if (style_screen_menu_scroll_menu_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_label_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_label_main_main_default);
	lv_style_set_radius(&style_screen_menu_scroll_menu_label_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_menu_scroll_menu_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_menu_scroll_menu_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_menu_scroll_menu_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_scroll_menu_label_main_main_default, 0);
	lv_style_set_text_color(&style_screen_menu_scroll_menu_label_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_menu_scroll_menu_label_main_main_default, &lv_font_simsun_60);
	lv_style_set_text_letter_space(&style_screen_menu_scroll_menu_label_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_menu_scroll_menu_label_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_menu_scroll_menu_label_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_menu_scroll_menu_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_menu_scroll_menu_label_main_main_default, 0);
	lv_obj_add_style(ui->screen_menu_scroll_menu_label, &style_screen_menu_scroll_menu_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_menu_scroll_menu_item_1
	ui->screen_menu_scroll_menu_item_1 = lv_img_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_menu_item_1, 410, 98);
	lv_obj_set_size(ui->screen_menu_scroll_menu_item_1, 370, 50);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_item_1_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_item_1_main_main_default;
	if (style_screen_menu_scroll_menu_item_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_item_1_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_item_1_main_main_default);
	lv_style_set_img_recolor(&style_screen_menu_scroll_menu_item_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_menu_scroll_menu_item_1_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_menu_scroll_menu_item_1_main_main_default, 255);
	lv_obj_add_style(ui->screen_menu_scroll_menu_item_1, &style_screen_menu_scroll_menu_item_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_menu_scroll_menu_item_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_menu_scroll_menu_item_1,&_Menu_item_select_370x50);
	lv_img_set_pivot(ui->screen_menu_scroll_menu_item_1, 0,0);
	lv_img_set_angle(ui->screen_menu_scroll_menu_item_1, 0);

	//Write codes screen_menu_scroll_menu_item_2
	ui->screen_menu_scroll_menu_item_2 = lv_img_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_menu_item_2, 410, 159);
	lv_obj_set_size(ui->screen_menu_scroll_menu_item_2, 370, 50);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_item_2_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_item_2_main_main_default;
	if (style_screen_menu_scroll_menu_item_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_item_2_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_item_2_main_main_default);
	lv_style_set_img_recolor(&style_screen_menu_scroll_menu_item_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_menu_scroll_menu_item_2_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_menu_scroll_menu_item_2_main_main_default, 255);
	lv_obj_add_style(ui->screen_menu_scroll_menu_item_2, &style_screen_menu_scroll_menu_item_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_menu_scroll_menu_item_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_menu_scroll_menu_item_2,&_Menu_item_select_370x50);
	lv_img_set_pivot(ui->screen_menu_scroll_menu_item_2, 0,0);
	lv_img_set_angle(ui->screen_menu_scroll_menu_item_2, 0);

	//Write codes screen_menu_scroll_menu_item_3
	ui->screen_menu_scroll_menu_item_3 = lv_img_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_menu_item_3, 410, 216);
	lv_obj_set_size(ui->screen_menu_scroll_menu_item_3, 370, 50);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_item_3_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_item_3_main_main_default;
	if (style_screen_menu_scroll_menu_item_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_item_3_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_item_3_main_main_default);
	lv_style_set_img_recolor(&style_screen_menu_scroll_menu_item_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_menu_scroll_menu_item_3_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_menu_scroll_menu_item_3_main_main_default, 255);
	lv_obj_add_style(ui->screen_menu_scroll_menu_item_3, &style_screen_menu_scroll_menu_item_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_menu_scroll_menu_item_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_menu_scroll_menu_item_3,&_Menu_item_select_370x50);
	lv_img_set_pivot(ui->screen_menu_scroll_menu_item_3, 0,0);
	lv_img_set_angle(ui->screen_menu_scroll_menu_item_3, 0);

	//Write codes screen_menu_scroll_menu_item_4
	ui->screen_menu_scroll_menu_item_4 = lv_img_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_menu_item_4, 410, 277);
	lv_obj_set_size(ui->screen_menu_scroll_menu_item_4, 370, 50);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_item_4_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_item_4_main_main_default;
	if (style_screen_menu_scroll_menu_item_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_item_4_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_item_4_main_main_default);
	lv_style_set_img_recolor(&style_screen_menu_scroll_menu_item_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_menu_scroll_menu_item_4_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_menu_scroll_menu_item_4_main_main_default, 255);
	lv_obj_add_style(ui->screen_menu_scroll_menu_item_4, &style_screen_menu_scroll_menu_item_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_menu_scroll_menu_item_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_menu_scroll_menu_item_4,&_Menu_item_select_370x50);
	lv_img_set_pivot(ui->screen_menu_scroll_menu_item_4, 0,0);
	lv_img_set_angle(ui->screen_menu_scroll_menu_item_4, 0);

	//Write codes screen_menu_scroll_menu_item_5
	ui->screen_menu_scroll_menu_item_5 = lv_img_create(ui->screen_menu_scroll_Container_menu_scroll);
	lv_obj_set_pos(ui->screen_menu_scroll_menu_item_5, 410, 338);
	lv_obj_set_size(ui->screen_menu_scroll_menu_item_5, 370, 50);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_scroll_menu_item_5_main_main_default
	static lv_style_t style_screen_menu_scroll_menu_item_5_main_main_default;
	if (style_screen_menu_scroll_menu_item_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_scroll_menu_item_5_main_main_default);
	else
		lv_style_init(&style_screen_menu_scroll_menu_item_5_main_main_default);
	lv_style_set_img_recolor(&style_screen_menu_scroll_menu_item_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_menu_scroll_menu_item_5_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_menu_scroll_menu_item_5_main_main_default, 255);
	lv_obj_add_style(ui->screen_menu_scroll_menu_item_5, &style_screen_menu_scroll_menu_item_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_menu_scroll_menu_item_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_menu_scroll_menu_item_5,&_Menu_item_select_370x50);
	lv_img_set_pivot(ui->screen_menu_scroll_menu_item_5, 0,0);
	lv_img_set_angle(ui->screen_menu_scroll_menu_item_5, 0);
}