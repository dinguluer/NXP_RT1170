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


void setup_scr_rider_selected_screen(lv_ui *ui){

	//Write codes rider_selected_screen
	ui->rider_selected_screen = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_rider_selected_screen_main_main_default
	static lv_style_t style_rider_selected_screen_main_main_default;
	if (style_rider_selected_screen_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_main_main_default);
	else
		lv_style_init(&style_rider_selected_screen_main_main_default);
	lv_style_set_bg_color(&style_rider_selected_screen_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_rider_selected_screen_main_main_default, 0);
	lv_obj_add_style(ui->rider_selected_screen, &style_rider_selected_screen_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes rider_selected_screen_container_rider_selected
	ui->rider_selected_screen_container_rider_selected = lv_obj_create(ui->rider_selected_screen);
	lv_obj_set_pos(ui->rider_selected_screen_container_rider_selected, 0, 0);
	lv_obj_set_size(ui->rider_selected_screen_container_rider_selected, 800, 480);

	//Write style state: LV_STATE_DEFAULT for style_rider_selected_screen_container_rider_selected_main_main_default
	static lv_style_t style_rider_selected_screen_container_rider_selected_main_main_default;
	if (style_rider_selected_screen_container_rider_selected_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_container_rider_selected_main_main_default);
	else
		lv_style_init(&style_rider_selected_screen_container_rider_selected_main_main_default);
	lv_style_set_radius(&style_rider_selected_screen_container_rider_selected_main_main_default, 0);
	lv_style_set_bg_color(&style_rider_selected_screen_container_rider_selected_main_main_default, lv_color_make(0x11, 0x12, 0x12));
	lv_style_set_bg_grad_color(&style_rider_selected_screen_container_rider_selected_main_main_default, lv_color_make(0x0b, 0x0c, 0x0c));
	lv_style_set_bg_grad_dir(&style_rider_selected_screen_container_rider_selected_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_rider_selected_screen_container_rider_selected_main_main_default, 255);
	lv_style_set_border_color(&style_rider_selected_screen_container_rider_selected_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_rider_selected_screen_container_rider_selected_main_main_default, 0);
	lv_style_set_border_opa(&style_rider_selected_screen_container_rider_selected_main_main_default, 0);
	lv_style_set_pad_left(&style_rider_selected_screen_container_rider_selected_main_main_default, 0);
	lv_style_set_pad_right(&style_rider_selected_screen_container_rider_selected_main_main_default, 0);
	lv_style_set_pad_top(&style_rider_selected_screen_container_rider_selected_main_main_default, 0);
	lv_style_set_pad_bottom(&style_rider_selected_screen_container_rider_selected_main_main_default, 0);
	lv_obj_add_style(ui->rider_selected_screen_container_rider_selected, &style_rider_selected_screen_container_rider_selected_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes rider_selected_screen_Rider_selec_icon
	ui->rider_selected_screen_Rider_selec_icon = lv_imgbtn_create(ui->rider_selected_screen_container_rider_selected);
	lv_obj_set_pos(ui->rider_selected_screen_Rider_selec_icon, 40, 170);
	lv_obj_set_size(ui->rider_selected_screen_Rider_selec_icon, 150, 150);

	//Write style state: LV_STATE_DEFAULT for style_rider_selected_screen_rider_selec_icon_main_main_default
	static lv_style_t style_rider_selected_screen_rider_selec_icon_main_main_default;
	if (style_rider_selected_screen_rider_selec_icon_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_rider_selec_icon_main_main_default);
	else
		lv_style_init(&style_rider_selected_screen_rider_selec_icon_main_main_default);
	lv_style_set_text_color(&style_rider_selected_screen_rider_selec_icon_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor(&style_rider_selected_screen_rider_selec_icon_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_rider_selec_icon_main_main_default, 0);
	lv_style_set_img_opa(&style_rider_selected_screen_rider_selec_icon_main_main_default, 255);
	lv_obj_add_style(ui->rider_selected_screen_Rider_selec_icon, &style_rider_selected_screen_rider_selec_icon_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_rider_selected_screen_rider_selec_icon_main_main_pressed
	static lv_style_t style_rider_selected_screen_rider_selec_icon_main_main_pressed;
	if (style_rider_selected_screen_rider_selec_icon_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_rider_selec_icon_main_main_pressed);
	else
		lv_style_init(&style_rider_selected_screen_rider_selec_icon_main_main_pressed);
	lv_style_set_text_color(&style_rider_selected_screen_rider_selec_icon_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_rider_selected_screen_rider_selec_icon_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_rider_selec_icon_main_main_pressed, 0);
	lv_obj_add_style(ui->rider_selected_screen_Rider_selec_icon, &style_rider_selected_screen_rider_selec_icon_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_rider_selected_screen_rider_selec_icon_main_main_checked
	static lv_style_t style_rider_selected_screen_rider_selec_icon_main_main_checked;
	if (style_rider_selected_screen_rider_selec_icon_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_rider_selec_icon_main_main_checked);
	else
		lv_style_init(&style_rider_selected_screen_rider_selec_icon_main_main_checked);
	lv_style_set_text_color(&style_rider_selected_screen_rider_selec_icon_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_rider_selected_screen_rider_selec_icon_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_rider_selec_icon_main_main_checked, 0);
	lv_obj_add_style(ui->rider_selected_screen_Rider_selec_icon, &style_rider_selected_screen_rider_selec_icon_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->rider_selected_screen_Rider_selec_icon, LV_IMGBTN_STATE_RELEASED, NULL, &_Women_selected_alpha_150x150, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Rider_selec_icon, LV_IMGBTN_STATE_PRESSED, NULL, &_Women_selected_alpha_150x150, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Rider_selec_icon, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_Women_selected_alpha_150x150, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Rider_selec_icon, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_Women_selected_alpha_150x150, NULL);

	//Write codes rider_selected_screen_Area_limit
	ui->rider_selected_screen_Area_limit = lv_imgbtn_create(ui->rider_selected_screen_container_rider_selected);
	lv_obj_set_pos(ui->rider_selected_screen_Area_limit, 343, 66);
	lv_obj_set_size(ui->rider_selected_screen_Area_limit, 100, 100);

	//Write style state: LV_STATE_DEFAULT for style_rider_selected_screen_area_limit_main_main_default
	static lv_style_t style_rider_selected_screen_area_limit_main_main_default;
	if (style_rider_selected_screen_area_limit_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_area_limit_main_main_default);
	else
		lv_style_init(&style_rider_selected_screen_area_limit_main_main_default);
	lv_style_set_text_color(&style_rider_selected_screen_area_limit_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor(&style_rider_selected_screen_area_limit_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_area_limit_main_main_default, 0);
	lv_style_set_img_opa(&style_rider_selected_screen_area_limit_main_main_default, 255);
	lv_obj_add_style(ui->rider_selected_screen_Area_limit, &style_rider_selected_screen_area_limit_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_rider_selected_screen_area_limit_main_main_pressed
	static lv_style_t style_rider_selected_screen_area_limit_main_main_pressed;
	if (style_rider_selected_screen_area_limit_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_area_limit_main_main_pressed);
	else
		lv_style_init(&style_rider_selected_screen_area_limit_main_main_pressed);
	lv_style_set_text_color(&style_rider_selected_screen_area_limit_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_rider_selected_screen_area_limit_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_area_limit_main_main_pressed, 0);
	lv_obj_add_style(ui->rider_selected_screen_Area_limit, &style_rider_selected_screen_area_limit_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_rider_selected_screen_area_limit_main_main_checked
	static lv_style_t style_rider_selected_screen_area_limit_main_main_checked;
	if (style_rider_selected_screen_area_limit_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_area_limit_main_main_checked);
	else
		lv_style_init(&style_rider_selected_screen_area_limit_main_main_checked);
	lv_style_set_text_color(&style_rider_selected_screen_area_limit_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_rider_selected_screen_area_limit_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_area_limit_main_main_checked, 0);
	lv_obj_add_style(ui->rider_selected_screen_Area_limit, &style_rider_selected_screen_area_limit_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->rider_selected_screen_Area_limit, LV_IMGBTN_STATE_RELEASED, NULL, &_Area_limit_alpha_100x100, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Area_limit, LV_IMGBTN_STATE_PRESSED, NULL, &_Area_limit_alpha_100x100, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Area_limit, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_Area_limit_alpha_100x100, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Area_limit, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_Area_limit_alpha_100x100, NULL);

	//Write codes rider_selected_screen_Time_fence
	ui->rider_selected_screen_Time_fence = lv_imgbtn_create(ui->rider_selected_screen_container_rider_selected);
	lv_obj_set_pos(ui->rider_selected_screen_Time_fence, 597, 67);
	lv_obj_set_size(ui->rider_selected_screen_Time_fence, 100, 100);

	//Write style state: LV_STATE_DEFAULT for style_rider_selected_screen_time_fence_main_main_default
	static lv_style_t style_rider_selected_screen_time_fence_main_main_default;
	if (style_rider_selected_screen_time_fence_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_time_fence_main_main_default);
	else
		lv_style_init(&style_rider_selected_screen_time_fence_main_main_default);
	lv_style_set_text_color(&style_rider_selected_screen_time_fence_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor(&style_rider_selected_screen_time_fence_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_time_fence_main_main_default, 0);
	lv_style_set_img_opa(&style_rider_selected_screen_time_fence_main_main_default, 255);
	lv_obj_add_style(ui->rider_selected_screen_Time_fence, &style_rider_selected_screen_time_fence_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_rider_selected_screen_time_fence_main_main_pressed
	static lv_style_t style_rider_selected_screen_time_fence_main_main_pressed;
	if (style_rider_selected_screen_time_fence_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_time_fence_main_main_pressed);
	else
		lv_style_init(&style_rider_selected_screen_time_fence_main_main_pressed);
	lv_style_set_text_color(&style_rider_selected_screen_time_fence_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_rider_selected_screen_time_fence_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_time_fence_main_main_pressed, 0);
	lv_obj_add_style(ui->rider_selected_screen_Time_fence, &style_rider_selected_screen_time_fence_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_rider_selected_screen_time_fence_main_main_checked
	static lv_style_t style_rider_selected_screen_time_fence_main_main_checked;
	if (style_rider_selected_screen_time_fence_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_time_fence_main_main_checked);
	else
		lv_style_init(&style_rider_selected_screen_time_fence_main_main_checked);
	lv_style_set_text_color(&style_rider_selected_screen_time_fence_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_rider_selected_screen_time_fence_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_time_fence_main_main_checked, 0);
	lv_obj_add_style(ui->rider_selected_screen_Time_fence, &style_rider_selected_screen_time_fence_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->rider_selected_screen_Time_fence, LV_IMGBTN_STATE_RELEASED, NULL, &_Time_fence_alpha_100x100, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Time_fence, LV_IMGBTN_STATE_PRESSED, NULL, &_Time_fence_alpha_100x100, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Time_fence, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_Time_fence_alpha_100x100, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Time_fence, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_Time_fence_alpha_100x100, NULL);

	//Write codes rider_selected_screen_Speed_limit
	ui->rider_selected_screen_Speed_limit = lv_imgbtn_create(ui->rider_selected_screen_container_rider_selected);
	lv_obj_set_pos(ui->rider_selected_screen_Speed_limit, 343, 262);
	lv_obj_set_size(ui->rider_selected_screen_Speed_limit, 100, 100);

	//Write style state: LV_STATE_DEFAULT for style_rider_selected_screen_speed_limit_main_main_default
	static lv_style_t style_rider_selected_screen_speed_limit_main_main_default;
	if (style_rider_selected_screen_speed_limit_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_speed_limit_main_main_default);
	else
		lv_style_init(&style_rider_selected_screen_speed_limit_main_main_default);
	lv_style_set_text_color(&style_rider_selected_screen_speed_limit_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor(&style_rider_selected_screen_speed_limit_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_speed_limit_main_main_default, 0);
	lv_style_set_img_opa(&style_rider_selected_screen_speed_limit_main_main_default, 255);
	lv_obj_add_style(ui->rider_selected_screen_Speed_limit, &style_rider_selected_screen_speed_limit_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_rider_selected_screen_speed_limit_main_main_pressed
	static lv_style_t style_rider_selected_screen_speed_limit_main_main_pressed;
	if (style_rider_selected_screen_speed_limit_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_speed_limit_main_main_pressed);
	else
		lv_style_init(&style_rider_selected_screen_speed_limit_main_main_pressed);
	lv_style_set_text_color(&style_rider_selected_screen_speed_limit_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_rider_selected_screen_speed_limit_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_speed_limit_main_main_pressed, 0);
	lv_obj_add_style(ui->rider_selected_screen_Speed_limit, &style_rider_selected_screen_speed_limit_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_rider_selected_screen_speed_limit_main_main_checked
	static lv_style_t style_rider_selected_screen_speed_limit_main_main_checked;
	if (style_rider_selected_screen_speed_limit_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_speed_limit_main_main_checked);
	else
		lv_style_init(&style_rider_selected_screen_speed_limit_main_main_checked);
	lv_style_set_text_color(&style_rider_selected_screen_speed_limit_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_rider_selected_screen_speed_limit_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_speed_limit_main_main_checked, 0);
	lv_obj_add_style(ui->rider_selected_screen_Speed_limit, &style_rider_selected_screen_speed_limit_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->rider_selected_screen_Speed_limit, LV_IMGBTN_STATE_RELEASED, NULL, &_speed_limit_alpha_100x100, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Speed_limit, LV_IMGBTN_STATE_PRESSED, NULL, &_speed_limit_alpha_100x100, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Speed_limit, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_speed_limit_alpha_100x100, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Speed_limit, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_speed_limit_alpha_100x100, NULL);
	lv_obj_add_flag(ui->rider_selected_screen_Speed_limit, LV_OBJ_FLAG_CHECKABLE);

	//Write codes rider_selected_screen_Mode_restriction
	ui->rider_selected_screen_Mode_restriction = lv_imgbtn_create(ui->rider_selected_screen_container_rider_selected);
	lv_obj_set_pos(ui->rider_selected_screen_Mode_restriction, 597, 268);
	lv_obj_set_size(ui->rider_selected_screen_Mode_restriction, 100, 100);

	//Write style state: LV_STATE_DEFAULT for style_rider_selected_screen_mode_restriction_main_main_default
	static lv_style_t style_rider_selected_screen_mode_restriction_main_main_default;
	if (style_rider_selected_screen_mode_restriction_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_mode_restriction_main_main_default);
	else
		lv_style_init(&style_rider_selected_screen_mode_restriction_main_main_default);
	lv_style_set_text_color(&style_rider_selected_screen_mode_restriction_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor(&style_rider_selected_screen_mode_restriction_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_mode_restriction_main_main_default, 0);
	lv_style_set_img_opa(&style_rider_selected_screen_mode_restriction_main_main_default, 255);
	lv_obj_add_style(ui->rider_selected_screen_Mode_restriction, &style_rider_selected_screen_mode_restriction_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_rider_selected_screen_mode_restriction_main_main_pressed
	static lv_style_t style_rider_selected_screen_mode_restriction_main_main_pressed;
	if (style_rider_selected_screen_mode_restriction_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_mode_restriction_main_main_pressed);
	else
		lv_style_init(&style_rider_selected_screen_mode_restriction_main_main_pressed);
	lv_style_set_text_color(&style_rider_selected_screen_mode_restriction_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_rider_selected_screen_mode_restriction_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_mode_restriction_main_main_pressed, 0);
	lv_obj_add_style(ui->rider_selected_screen_Mode_restriction, &style_rider_selected_screen_mode_restriction_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_rider_selected_screen_mode_restriction_main_main_checked
	static lv_style_t style_rider_selected_screen_mode_restriction_main_main_checked;
	if (style_rider_selected_screen_mode_restriction_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_mode_restriction_main_main_checked);
	else
		lv_style_init(&style_rider_selected_screen_mode_restriction_main_main_checked);
	lv_style_set_text_color(&style_rider_selected_screen_mode_restriction_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_rider_selected_screen_mode_restriction_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_mode_restriction_main_main_checked, 0);
	lv_obj_add_style(ui->rider_selected_screen_Mode_restriction, &style_rider_selected_screen_mode_restriction_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->rider_selected_screen_Mode_restriction, LV_IMGBTN_STATE_RELEASED, NULL, &_mode_restriction_alpha_100x100, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Mode_restriction, LV_IMGBTN_STATE_PRESSED, NULL, &_mode_restriction_alpha_100x100, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Mode_restriction, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_mode_restriction_alpha_100x100, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_Mode_restriction, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_mode_restriction_alpha_100x100, NULL);
	lv_obj_add_flag(ui->rider_selected_screen_Mode_restriction, LV_OBJ_FLAG_CHECKABLE);

	//Write codes rider_selected_screen_shield_select_icon
	ui->rider_selected_screen_shield_select_icon = lv_imgbtn_create(ui->rider_selected_screen_container_rider_selected);
	lv_obj_set_pos(ui->rider_selected_screen_shield_select_icon, 95, 250);
	lv_obj_set_size(ui->rider_selected_screen_shield_select_icon, 40, 40);

	//Write style state: LV_STATE_DEFAULT for style_rider_selected_screen_shield_select_icon_main_main_default
	static lv_style_t style_rider_selected_screen_shield_select_icon_main_main_default;
	if (style_rider_selected_screen_shield_select_icon_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_shield_select_icon_main_main_default);
	else
		lv_style_init(&style_rider_selected_screen_shield_select_icon_main_main_default);
	lv_style_set_text_color(&style_rider_selected_screen_shield_select_icon_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor(&style_rider_selected_screen_shield_select_icon_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_shield_select_icon_main_main_default, 0);
	lv_style_set_img_opa(&style_rider_selected_screen_shield_select_icon_main_main_default, 255);
	lv_obj_add_style(ui->rider_selected_screen_shield_select_icon, &style_rider_selected_screen_shield_select_icon_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_rider_selected_screen_shield_select_icon_main_main_pressed
	static lv_style_t style_rider_selected_screen_shield_select_icon_main_main_pressed;
	if (style_rider_selected_screen_shield_select_icon_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_shield_select_icon_main_main_pressed);
	else
		lv_style_init(&style_rider_selected_screen_shield_select_icon_main_main_pressed);
	lv_style_set_text_color(&style_rider_selected_screen_shield_select_icon_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_rider_selected_screen_shield_select_icon_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_shield_select_icon_main_main_pressed, 0);
	lv_obj_add_style(ui->rider_selected_screen_shield_select_icon, &style_rider_selected_screen_shield_select_icon_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_rider_selected_screen_shield_select_icon_main_main_checked
	static lv_style_t style_rider_selected_screen_shield_select_icon_main_main_checked;
	if (style_rider_selected_screen_shield_select_icon_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_shield_select_icon_main_main_checked);
	else
		lv_style_init(&style_rider_selected_screen_shield_select_icon_main_main_checked);
	lv_style_set_text_color(&style_rider_selected_screen_shield_select_icon_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_rider_selected_screen_shield_select_icon_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_rider_selected_screen_shield_select_icon_main_main_checked, 0);
	lv_obj_add_style(ui->rider_selected_screen_shield_select_icon, &style_rider_selected_screen_shield_select_icon_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->rider_selected_screen_shield_select_icon, LV_IMGBTN_STATE_RELEASED, NULL, &_Scheild_select_alpha_40x40, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_shield_select_icon, LV_IMGBTN_STATE_PRESSED, NULL, &_Scheild_select_alpha_40x40, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_shield_select_icon, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_Scheild_select_alpha_40x40, NULL);
	lv_imgbtn_set_src(ui->rider_selected_screen_shield_select_icon, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_Scheild_select_alpha_40x40, NULL);
	lv_obj_add_flag(ui->rider_selected_screen_shield_select_icon, LV_OBJ_FLAG_CHECKABLE);

	//Write codes rider_selected_screen_label_area
	ui->rider_selected_screen_label_area = lv_label_create(ui->rider_selected_screen_container_rider_selected);
	lv_obj_set_pos(ui->rider_selected_screen_label_area, 300, 188);
	lv_obj_set_size(ui->rider_selected_screen_label_area, 200, 32);
	lv_label_set_text(ui->rider_selected_screen_label_area, "AREA LIMIT");
	lv_label_set_long_mode(ui->rider_selected_screen_label_area, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->rider_selected_screen_label_area, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_rider_selected_screen_label_area_main_main_default
	static lv_style_t style_rider_selected_screen_label_area_main_main_default;
	if (style_rider_selected_screen_label_area_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_label_area_main_main_default);
	else
		lv_style_init(&style_rider_selected_screen_label_area_main_main_default);
	lv_style_set_radius(&style_rider_selected_screen_label_area_main_main_default, 0);
	lv_style_set_bg_color(&style_rider_selected_screen_label_area_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_rider_selected_screen_label_area_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_rider_selected_screen_label_area_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_rider_selected_screen_label_area_main_main_default, 0);
	lv_style_set_text_color(&style_rider_selected_screen_label_area_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_rider_selected_screen_label_area_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_rider_selected_screen_label_area_main_main_default, 2);
	lv_style_set_pad_left(&style_rider_selected_screen_label_area_main_main_default, 0);
	lv_style_set_pad_right(&style_rider_selected_screen_label_area_main_main_default, 0);
	lv_style_set_pad_top(&style_rider_selected_screen_label_area_main_main_default, 0);
	lv_style_set_pad_bottom(&style_rider_selected_screen_label_area_main_main_default, 0);
	lv_obj_add_style(ui->rider_selected_screen_label_area, &style_rider_selected_screen_label_area_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes rider_selected_screen_label_time
	ui->rider_selected_screen_label_time = lv_label_create(ui->rider_selected_screen_container_rider_selected);
	lv_obj_set_pos(ui->rider_selected_screen_label_time, 550, 188);
	lv_obj_set_size(ui->rider_selected_screen_label_time, 200, 32);
	lv_label_set_text(ui->rider_selected_screen_label_time, "TIME FENCE");
	lv_label_set_long_mode(ui->rider_selected_screen_label_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->rider_selected_screen_label_time, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_rider_selected_screen_label_time_main_main_default
	static lv_style_t style_rider_selected_screen_label_time_main_main_default;
	if (style_rider_selected_screen_label_time_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_label_time_main_main_default);
	else
		lv_style_init(&style_rider_selected_screen_label_time_main_main_default);
	lv_style_set_radius(&style_rider_selected_screen_label_time_main_main_default, 0);
	lv_style_set_bg_color(&style_rider_selected_screen_label_time_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_rider_selected_screen_label_time_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_rider_selected_screen_label_time_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_rider_selected_screen_label_time_main_main_default, 0);
	lv_style_set_text_color(&style_rider_selected_screen_label_time_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_rider_selected_screen_label_time_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_rider_selected_screen_label_time_main_main_default, 2);
	lv_style_set_pad_left(&style_rider_selected_screen_label_time_main_main_default, 0);
	lv_style_set_pad_right(&style_rider_selected_screen_label_time_main_main_default, 0);
	lv_style_set_pad_top(&style_rider_selected_screen_label_time_main_main_default, 0);
	lv_style_set_pad_bottom(&style_rider_selected_screen_label_time_main_main_default, 0);
	lv_obj_add_style(ui->rider_selected_screen_label_time, &style_rider_selected_screen_label_time_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes rider_selected_screen_label_speed
	ui->rider_selected_screen_label_speed = lv_label_create(ui->rider_selected_screen_container_rider_selected);
	lv_obj_set_pos(ui->rider_selected_screen_label_speed, 306, 384);
	lv_obj_set_size(ui->rider_selected_screen_label_speed, 200, 32);
	lv_label_set_text(ui->rider_selected_screen_label_speed, "SPEED LIMIT");
	lv_label_set_long_mode(ui->rider_selected_screen_label_speed, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->rider_selected_screen_label_speed, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_rider_selected_screen_label_speed_main_main_default
	static lv_style_t style_rider_selected_screen_label_speed_main_main_default;
	if (style_rider_selected_screen_label_speed_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_label_speed_main_main_default);
	else
		lv_style_init(&style_rider_selected_screen_label_speed_main_main_default);
	lv_style_set_radius(&style_rider_selected_screen_label_speed_main_main_default, 0);
	lv_style_set_bg_color(&style_rider_selected_screen_label_speed_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_rider_selected_screen_label_speed_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_rider_selected_screen_label_speed_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_rider_selected_screen_label_speed_main_main_default, 0);
	lv_style_set_text_color(&style_rider_selected_screen_label_speed_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_rider_selected_screen_label_speed_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_rider_selected_screen_label_speed_main_main_default, 2);
	lv_style_set_pad_left(&style_rider_selected_screen_label_speed_main_main_default, 0);
	lv_style_set_pad_right(&style_rider_selected_screen_label_speed_main_main_default, 0);
	lv_style_set_pad_top(&style_rider_selected_screen_label_speed_main_main_default, 0);
	lv_style_set_pad_bottom(&style_rider_selected_screen_label_speed_main_main_default, 0);
	lv_obj_add_style(ui->rider_selected_screen_label_speed, &style_rider_selected_screen_label_speed_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes rider_selected_screen_label_mode
	ui->rider_selected_screen_label_mode = lv_label_create(ui->rider_selected_screen_container_rider_selected);
	lv_obj_set_pos(ui->rider_selected_screen_label_mode, 550, 384);
	lv_obj_set_size(ui->rider_selected_screen_label_mode, 200, 32);
	lv_label_set_text(ui->rider_selected_screen_label_mode, "MODE RESTRICTION");
	lv_label_set_long_mode(ui->rider_selected_screen_label_mode, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->rider_selected_screen_label_mode, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_rider_selected_screen_label_mode_main_main_default
	static lv_style_t style_rider_selected_screen_label_mode_main_main_default;
	if (style_rider_selected_screen_label_mode_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_selected_screen_label_mode_main_main_default);
	else
		lv_style_init(&style_rider_selected_screen_label_mode_main_main_default);
	lv_style_set_radius(&style_rider_selected_screen_label_mode_main_main_default, 0);
	lv_style_set_bg_color(&style_rider_selected_screen_label_mode_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_rider_selected_screen_label_mode_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_rider_selected_screen_label_mode_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_rider_selected_screen_label_mode_main_main_default, 0);
	lv_style_set_text_color(&style_rider_selected_screen_label_mode_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_rider_selected_screen_label_mode_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_rider_selected_screen_label_mode_main_main_default, 2);
	lv_style_set_pad_left(&style_rider_selected_screen_label_mode_main_main_default, 0);
	lv_style_set_pad_right(&style_rider_selected_screen_label_mode_main_main_default, 0);
	lv_style_set_pad_top(&style_rider_selected_screen_label_mode_main_main_default, 0);
	lv_style_set_pad_bottom(&style_rider_selected_screen_label_mode_main_main_default, 0);
	lv_obj_add_style(ui->rider_selected_screen_label_mode, &style_rider_selected_screen_label_mode_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}