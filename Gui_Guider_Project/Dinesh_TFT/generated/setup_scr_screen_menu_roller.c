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


void setup_scr_screen_menu_roller(lv_ui *ui){

	//Write codes screen_menu_roller
	ui->screen_menu_roller = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_roller_main_main_default
	static lv_style_t style_screen_menu_roller_main_main_default;
	if (style_screen_menu_roller_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_roller_main_main_default);
	else
		lv_style_init(&style_screen_menu_roller_main_main_default);
	lv_style_set_bg_color(&style_screen_menu_roller_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_menu_roller_main_main_default, 0);
	lv_obj_add_style(ui->screen_menu_roller, &style_screen_menu_roller_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_menu_roller_container_menu_roller
	ui->screen_menu_roller_container_menu_roller = lv_obj_create(ui->screen_menu_roller);
	lv_obj_set_pos(ui->screen_menu_roller_container_menu_roller, 0, 0);
	lv_obj_set_size(ui->screen_menu_roller_container_menu_roller, 800, 480);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_roller_container_menu_roller_main_main_default
	static lv_style_t style_screen_menu_roller_container_menu_roller_main_main_default;
	if (style_screen_menu_roller_container_menu_roller_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_roller_container_menu_roller_main_main_default);
	else
		lv_style_init(&style_screen_menu_roller_container_menu_roller_main_main_default);
	lv_style_set_radius(&style_screen_menu_roller_container_menu_roller_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_menu_roller_container_menu_roller_main_main_default, lv_color_make(0x11, 0x12, 0x12));
	lv_style_set_bg_grad_color(&style_screen_menu_roller_container_menu_roller_main_main_default, lv_color_make(0x0b, 0x0c, 0x0c));
	lv_style_set_bg_grad_dir(&style_screen_menu_roller_container_menu_roller_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_roller_container_menu_roller_main_main_default, 255);
	lv_style_set_border_color(&style_screen_menu_roller_container_menu_roller_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_menu_roller_container_menu_roller_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_menu_roller_container_menu_roller_main_main_default, 255);
	lv_style_set_pad_left(&style_screen_menu_roller_container_menu_roller_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_menu_roller_container_menu_roller_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_menu_roller_container_menu_roller_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_menu_roller_container_menu_roller_main_main_default, 0);
	lv_obj_add_style(ui->screen_menu_roller_container_menu_roller, &style_screen_menu_roller_container_menu_roller_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_menu_roller_roller_1
	ui->screen_menu_roller_roller_1 = lv_roller_create(ui->screen_menu_roller);
	lv_obj_set_pos(ui->screen_menu_roller_roller_1, 28, 41);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_roller_roller_1_main_main_default
	static lv_style_t style_screen_menu_roller_roller_1_main_main_default;
	if (style_screen_menu_roller_roller_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_roller_roller_1_main_main_default);
	else
		lv_style_init(&style_screen_menu_roller_roller_1_main_main_default);
	lv_style_set_radius(&style_screen_menu_roller_roller_1_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_menu_roller_roller_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_roller_roller_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_roller_roller_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_roller_roller_1_main_main_default, 255);
	lv_style_set_border_color(&style_screen_menu_roller_roller_1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_screen_menu_roller_roller_1_main_main_default, 2);
	lv_style_set_text_color(&style_screen_menu_roller_roller_1_main_main_default, lv_color_make(0x33, 0x33, 0x33));
	lv_obj_add_style(ui->screen_menu_roller_roller_1, &style_screen_menu_roller_roller_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_roller_roller_1_main_selected_default
	static lv_style_t style_screen_menu_roller_roller_1_main_selected_default;
	if (style_screen_menu_roller_roller_1_main_selected_default.prop_cnt > 1)
		lv_style_reset(&style_screen_menu_roller_roller_1_main_selected_default);
	else
		lv_style_init(&style_screen_menu_roller_roller_1_main_selected_default);
	lv_style_set_bg_color(&style_screen_menu_roller_roller_1_main_selected_default, lv_color_make(0x1d, 0xe0, 0x10));
	lv_style_set_bg_grad_color(&style_screen_menu_roller_roller_1_main_selected_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_menu_roller_roller_1_main_selected_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_screen_menu_roller_roller_1_main_selected_default, 255);
	lv_style_set_text_color(&style_screen_menu_roller_roller_1_main_selected_default, lv_color_make(0xFF, 0xFF, 0xFF));
	lv_obj_add_style(ui->screen_menu_roller_roller_1, &style_screen_menu_roller_roller_1_main_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->screen_menu_roller_roller_1,"1 HELLO\n2\n3\n4\n5",LV_ROLLER_MODE_INFINITE);
	lv_obj_set_style_text_font(ui->screen_menu_roller_roller_1, &lv_font_simsun_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_menu_roller_roller_1, &lv_font_simsun_100, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->screen_menu_roller_roller_1, &lv_font_simsun_100, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_visible_row_count(ui->screen_menu_roller_roller_1,5);
}