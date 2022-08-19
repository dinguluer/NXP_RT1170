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


void setup_scr_Logo_Screen(lv_ui *ui){

	//Write codes Logo_Screen
	ui->Logo_Screen = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_logo_screen_main_main_default
	static lv_style_t style_logo_screen_main_main_default;
	if (style_logo_screen_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_logo_screen_main_main_default);
	else
		lv_style_init(&style_logo_screen_main_main_default);
	lv_style_set_bg_color(&style_logo_screen_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_logo_screen_main_main_default, 0);
	lv_obj_add_style(ui->Logo_Screen, &style_logo_screen_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Logo_Screen_container_Logo
	ui->Logo_Screen_container_Logo = lv_obj_create(ui->Logo_Screen);
	lv_obj_set_pos(ui->Logo_Screen_container_Logo, 0, 0);
	lv_obj_set_size(ui->Logo_Screen_container_Logo, 800, 480);

	//Write style state: LV_STATE_DEFAULT for style_logo_screen_container_logo_main_main_default
	static lv_style_t style_logo_screen_container_logo_main_main_default;
	if (style_logo_screen_container_logo_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_logo_screen_container_logo_main_main_default);
	else
		lv_style_init(&style_logo_screen_container_logo_main_main_default);
	lv_style_set_radius(&style_logo_screen_container_logo_main_main_default, 0);
	lv_style_set_bg_color(&style_logo_screen_container_logo_main_main_default, lv_color_make(0x11, 0x12, 0x12));
	lv_style_set_bg_grad_color(&style_logo_screen_container_logo_main_main_default, lv_color_make(0x0b, 0x0c, 0x0c));
	lv_style_set_bg_grad_dir(&style_logo_screen_container_logo_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_logo_screen_container_logo_main_main_default, 255);
	lv_style_set_border_color(&style_logo_screen_container_logo_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_logo_screen_container_logo_main_main_default, 0);
	lv_style_set_border_opa(&style_logo_screen_container_logo_main_main_default, 0);
	lv_style_set_pad_left(&style_logo_screen_container_logo_main_main_default, 0);
	lv_style_set_pad_right(&style_logo_screen_container_logo_main_main_default, 0);
	lv_style_set_pad_top(&style_logo_screen_container_logo_main_main_default, 0);
	lv_style_set_pad_bottom(&style_logo_screen_container_logo_main_main_default, 0);
	lv_obj_add_style(ui->Logo_Screen_container_Logo, &style_logo_screen_container_logo_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Logo_Screen_img_1
	ui->Logo_Screen_img_1 = lv_img_create(ui->Logo_Screen_container_Logo);
	lv_obj_set_pos(ui->Logo_Screen_img_1, 203, 140);
	lv_obj_set_size(ui->Logo_Screen_img_1, 400, 200);
//	lv_obj_set_pos(ui->Logo_Screen_img_1, 284, 106);
//	lv_obj_set_size(ui->Logo_Screen_img_1, 233, 223);

	//Write style state: LV_STATE_DEFAULT for style_logo_screen_img_1_main_main_default
	static lv_style_t style_logo_screen_img_1_main_main_default;
	if (style_logo_screen_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_logo_screen_img_1_main_main_default);
	else
		lv_style_init(&style_logo_screen_img_1_main_main_default);
	lv_style_set_img_recolor(&style_logo_screen_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_logo_screen_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_logo_screen_img_1_main_main_default, 255);
	lv_obj_add_style(ui->Logo_Screen_img_1, &style_logo_screen_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->Logo_Screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->Logo_Screen_img_1,&_NXP_LOGO_400x200);
	//lv_img_set_src(ui->Logo_Screen_img_1,&_drawing_Guage_2_233x223);
	lv_img_set_pivot(ui->Logo_Screen_img_1, 0,0);
	lv_img_set_angle(ui->Logo_Screen_img_1, 0);
}
