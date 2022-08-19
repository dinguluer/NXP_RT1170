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


void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_screen_main_main_default
	static lv_style_t style_screen_main_main_default;
	if (style_screen_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_main_main_default);
	else
		lv_style_init(&style_screen_main_main_default);
	lv_style_set_bg_color(&style_screen_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_main_main_default, 0);
	lv_obj_add_style(ui->screen, &style_screen_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_container_Dial
	ui->screen_container_Dial = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_container_Dial, 0, 0);
	lv_obj_set_size(ui->screen_container_Dial, 800, 480);

	//Write style state: LV_STATE_DEFAULT for style_screen_container_dial_main_main_default
	static lv_style_t style_screen_container_dial_main_main_default;
	if (style_screen_container_dial_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_container_dial_main_main_default);
	else
		lv_style_init(&style_screen_container_dial_main_main_default);
	lv_style_set_radius(&style_screen_container_dial_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_container_dial_main_main_default, lv_color_make(0x11, 0x12, 0x12));
	lv_style_set_bg_grad_color(&style_screen_container_dial_main_main_default, lv_color_make(0x0b, 0x0c, 0x0c));
	lv_style_set_bg_grad_dir(&style_screen_container_dial_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_container_dial_main_main_default, 255);
	lv_style_set_border_color(&style_screen_container_dial_main_main_default, lv_color_make(0x11, 0x12, 0x12));
	lv_style_set_border_width(&style_screen_container_dial_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_container_dial_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_container_dial_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_container_dial_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_container_dial_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_container_dial_main_main_default, 0);
	lv_obj_add_style(ui->screen_container_Dial, &style_screen_container_dial_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ODO_roller_image
	ui->screen_ODO_roller_image = lv_img_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_ODO_roller_image, 331, 185);
	lv_obj_set_size(ui->screen_ODO_roller_image, 146, 29);

	//Write style state: LV_STATE_DEFAULT for style_screen_odo_roller_image_main_main_default
	static lv_style_t style_screen_odo_roller_image_main_main_default;
	if (style_screen_odo_roller_image_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_odo_roller_image_main_main_default);
	else
		lv_style_init(&style_screen_odo_roller_image_main_main_default);
	lv_style_set_img_recolor(&style_screen_odo_roller_image_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_odo_roller_image_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_odo_roller_image_main_main_default, 255);
	lv_obj_add_style(ui->screen_ODO_roller_image, &style_screen_odo_roller_image_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_ODO_roller_image, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_ODO_roller_image,&_odoback_146x29);
	lv_img_set_pivot(ui->screen_ODO_roller_image, 0,0);
	lv_img_set_angle(ui->screen_ODO_roller_image, 0);

	//Write codes screen_ODO_roller_0
	ui->screen_ODO_roller_0 = lv_roller_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_ODO_roller_0, 436, 176);

	//Write style state: LV_STATE_DEFAULT for style_screen_odo_roller_0_main_main_default
	static lv_style_t style_screen_odo_roller_0_main_main_default;
	if (style_screen_odo_roller_0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_odo_roller_0_main_main_default);
	else
		lv_style_init(&style_screen_odo_roller_0_main_main_default);
	lv_style_set_radius(&style_screen_odo_roller_0_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_odo_roller_0_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_odo_roller_0_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_odo_roller_0_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_odo_roller_0_main_main_default, 255);
	lv_style_set_border_color(&style_screen_odo_roller_0_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_screen_odo_roller_0_main_main_default, 0);
	lv_style_set_text_color(&style_screen_odo_roller_0_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_add_style(ui->screen_ODO_roller_0, &style_screen_odo_roller_0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_odo_roller_0_main_selected_default
	static lv_style_t style_screen_odo_roller_0_main_selected_default;
	if (style_screen_odo_roller_0_main_selected_default.prop_cnt > 1)
		lv_style_reset(&style_screen_odo_roller_0_main_selected_default);
	else
		lv_style_init(&style_screen_odo_roller_0_main_selected_default);
	lv_style_set_bg_color(&style_screen_odo_roller_0_main_selected_default, lv_color_make(0xfa, 0xfd, 0xff));
	lv_style_set_bg_grad_color(&style_screen_odo_roller_0_main_selected_default, lv_color_make(0x6f, 0x5e, 0xc5));
	lv_style_set_bg_grad_dir(&style_screen_odo_roller_0_main_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_odo_roller_0_main_selected_default, 142);
	lv_style_set_text_color(&style_screen_odo_roller_0_main_selected_default, lv_color_make(0xFF, 0xFF, 0xFF));
	lv_obj_add_style(ui->screen_ODO_roller_0, &style_screen_odo_roller_0_main_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->screen_ODO_roller_0,"0\n1\n2\n3\n4\n5\n6\n7\n8\n9",LV_ROLLER_MODE_INFINITE);
	lv_obj_set_style_text_font(ui->screen_ODO_roller_0, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ODO_roller_0, &lv_font_simsun_16, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->screen_ODO_roller_0, &lv_font_simsun_16, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_visible_row_count(ui->screen_ODO_roller_0,1);

	//Write codes screen_Background_imgage
	ui->screen_Background_imgage = lv_img_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Background_imgage, 0, 0);
	lv_obj_set_size(ui->screen_Background_imgage, 800, 480);

	//Write style state: LV_STATE_DEFAULT for style_screen_background_imgage_main_main_default
	static lv_style_t style_screen_background_imgage_main_main_default;
	if (style_screen_background_imgage_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_background_imgage_main_main_default);
	else
		lv_style_init(&style_screen_background_imgage_main_main_default);
	lv_style_set_img_recolor(&style_screen_background_imgage_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_background_imgage_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_background_imgage_main_main_default, 103);
	lv_obj_add_style(ui->screen_Background_imgage, &style_screen_background_imgage_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_Background_imgage, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_Background_imgage,&_Back_gnd_800x480);
	lv_img_set_pivot(ui->screen_Background_imgage, 0,0);
	lv_img_set_angle(ui->screen_Background_imgage, 0);

	//Write codes screen_Time_Label
	ui->screen_Time_Label = lv_label_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Time_Label, 685, 12);
	lv_obj_set_size(ui->screen_Time_Label, 100, 32);
	lv_label_set_text(ui->screen_Time_Label, "10:28");
	lv_label_set_long_mode(ui->screen_Time_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_Time_Label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_time_label_main_main_default
	static lv_style_t style_screen_time_label_main_main_default;
	if (style_screen_time_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_time_label_main_main_default);
	else
		lv_style_init(&style_screen_time_label_main_main_default);
	lv_style_set_radius(&style_screen_time_label_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_time_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_time_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_time_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_time_label_main_main_default, 0);
	lv_style_set_text_color(&style_screen_time_label_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_time_label_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_screen_time_label_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_time_label_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_time_label_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_time_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_time_label_main_main_default, 0);
	lv_obj_add_style(ui->screen_Time_Label, &style_screen_time_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_Date_Label
	ui->screen_Date_Label = lv_label_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Date_Label, 8, 9);
	lv_obj_set_size(ui->screen_Date_Label, 169, 45);
	lv_label_set_text(ui->screen_Date_Label, "May 24, 2022");
	lv_label_set_long_mode(ui->screen_Date_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_Date_Label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_date_label_main_main_default
	static lv_style_t style_screen_date_label_main_main_default;
	if (style_screen_date_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_date_label_main_main_default);
	else
		lv_style_init(&style_screen_date_label_main_main_default);
	lv_style_set_radius(&style_screen_date_label_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_date_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_date_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_date_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_date_label_main_main_default, 0);
	lv_style_set_text_color(&style_screen_date_label_main_main_default, lv_color_make(0xf8, 0xf7, 0xf7));
	lv_style_set_text_font(&style_screen_date_label_main_main_default, &lv_font_montserratMedium_20);
	lv_style_set_text_letter_space(&style_screen_date_label_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_date_label_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_date_label_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_date_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_date_label_main_main_default, 0);
	lv_obj_add_style(ui->screen_Date_Label, &style_screen_date_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_Dial_image
	ui->screen_Dial_image = lv_img_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Dial_image, 150, null);
	lv_obj_set_size(ui->screen_Dial_image, 500, 388);

	//Write style state: LV_STATE_DEFAULT for style_screen_dial_image_main_main_default
	static lv_style_t style_screen_dial_image_main_main_default;
	if (style_screen_dial_image_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_dial_image_main_main_default);
	else
		lv_style_init(&style_screen_dial_image_main_main_default);
	lv_style_set_img_recolor(&style_screen_dial_image_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_dial_image_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_dial_image_main_main_default, 255);
	lv_obj_add_style(ui->screen_Dial_image, &style_screen_dial_image_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_Dial_image, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_Dial_image,&_Dial_500x388);
	lv_img_set_pivot(ui->screen_Dial_image, 0,0);
	lv_img_set_angle(ui->screen_Dial_image, 0);

	//Write codes screen_Dial_meter
	ui->screen_Dial_meter = lv_meter_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Dial_meter, 199, 46);
	lv_obj_set_size(ui->screen_Dial_meter, 400, 400);

	//add scale screen_Dial_meter_scale_1
	lv_meter_scale_t *screen_Dial_meter_scale_1 = lv_meter_add_scale(ui->screen_Dial_meter);
	lv_meter_set_scale_ticks(ui->screen_Dial_meter, screen_Dial_meter_scale_1, 6, 1, 20, lv_color_make(0xff, 0x00, 0x00));
	lv_meter_set_scale_range(ui->screen_Dial_meter, screen_Dial_meter_scale_1, 0, 60, 240, 150);

	//add needle img for screen_Dial_meter_scale_1
	lv_meter_indicator_t *screen_Dial_meter_scale_1_ndimg_0;
	screen_Dial_meter_scale_1_ndimg_0 = lv_meter_add_needle_img(ui->screen_Dial_meter, screen_Dial_meter_scale_1, &_needle_alpha_188x36, 19, 18);
	lv_meter_set_indicator_value(ui->screen_Dial_meter, screen_Dial_meter_scale_1_ndimg_0, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_dial_meter_main_main_default
	static lv_style_t style_screen_dial_meter_main_main_default;
	if (style_screen_dial_meter_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_dial_meter_main_main_default);
	else
		lv_style_init(&style_screen_dial_meter_main_main_default);
	lv_style_set_bg_color(&style_screen_dial_meter_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_dial_meter_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_dial_meter_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_dial_meter_main_main_default, 0);
	lv_obj_add_style(ui->screen_Dial_meter, &style_screen_dial_meter_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_dial_meter_main_ticks_default
	static lv_style_t style_screen_dial_meter_main_ticks_default;
	if (style_screen_dial_meter_main_ticks_default.prop_cnt > 1)
		lv_style_reset(&style_screen_dial_meter_main_ticks_default);
	else
		lv_style_init(&style_screen_dial_meter_main_ticks_default);
	lv_style_set_text_color(&style_screen_dial_meter_main_ticks_default, lv_color_make(0xff, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_dial_meter_main_ticks_default, &lv_font_simsun_12);
	lv_obj_add_style(ui->screen_Dial_meter, &style_screen_dial_meter_main_ticks_default, LV_PART_TICKS|LV_STATE_DEFAULT);

	//Write codes screen_High_Beam_BG
	ui->screen_High_Beam_BG = lv_img_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_High_Beam_BG, 24, 419);
	lv_obj_set_size(ui->screen_High_Beam_BG, 50, 40);

	//Write style state: LV_STATE_DEFAULT for style_screen_high_beam_bg_main_main_default
	static lv_style_t style_screen_high_beam_bg_main_main_default;
	if (style_screen_high_beam_bg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_high_beam_bg_main_main_default);
	else
		lv_style_init(&style_screen_high_beam_bg_main_main_default);
	lv_style_set_img_recolor(&style_screen_high_beam_bg_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_high_beam_bg_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_high_beam_bg_main_main_default, 23);
	lv_obj_add_style(ui->screen_High_Beam_BG, &style_screen_high_beam_bg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_High_Beam_BG, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_High_Beam_BG,&_High_Beam_2_50x40);
	lv_img_set_pivot(ui->screen_High_Beam_BG, 0,0);
	lv_img_set_angle(ui->screen_High_Beam_BG, 0);

	//Write codes screen_High_Beam
	ui->screen_High_Beam = lv_img_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_High_Beam, 24, 419);
	lv_obj_set_size(ui->screen_High_Beam, 50, 40);

	//Write style state: LV_STATE_DEFAULT for style_screen_high_beam_main_main_default
	static lv_style_t style_screen_high_beam_main_main_default;
	if (style_screen_high_beam_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_high_beam_main_main_default);
	else
		lv_style_init(&style_screen_high_beam_main_main_default);
	lv_style_set_img_recolor(&style_screen_high_beam_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_high_beam_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_high_beam_main_main_default, 255);
	lv_obj_add_style(ui->screen_High_Beam, &style_screen_high_beam_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_High_Beam, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_High_Beam,&_High_Beam_0_50x40);
	lv_img_set_pivot(ui->screen_High_Beam, 0,0);
	lv_img_set_angle(ui->screen_High_Beam, 0);

	//Write codes screen_Engine_BG
	ui->screen_Engine_BG = lv_img_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Engine_BG, 97, 419);
	lv_obj_set_size(ui->screen_Engine_BG, 50, 40);

	//Write style state: LV_STATE_DEFAULT for style_screen_engine_bg_main_main_default
	static lv_style_t style_screen_engine_bg_main_main_default;
	if (style_screen_engine_bg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_engine_bg_main_main_default);
	else
		lv_style_init(&style_screen_engine_bg_main_main_default);
	lv_style_set_img_recolor(&style_screen_engine_bg_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_engine_bg_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_engine_bg_main_main_default, 25);
	lv_obj_add_style(ui->screen_Engine_BG, &style_screen_engine_bg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_Engine_BG, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_Engine_BG,&_Engine_2_50x40);
	lv_img_set_pivot(ui->screen_Engine_BG, 0,0);
	lv_img_set_angle(ui->screen_Engine_BG, 0);

	//Write codes screen_Engine
	ui->screen_Engine = lv_img_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Engine, 97, 419);
	lv_obj_set_size(ui->screen_Engine, 50, 40);

	//Write style state: LV_STATE_DEFAULT for style_screen_engine_main_main_default
	static lv_style_t style_screen_engine_main_main_default;
	if (style_screen_engine_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_engine_main_main_default);
	else
		lv_style_init(&style_screen_engine_main_main_default);
	lv_style_set_img_recolor(&style_screen_engine_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_engine_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_engine_main_main_default, 255);
	lv_obj_add_style(ui->screen_Engine, &style_screen_engine_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_Engine, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_Engine,&_Engine_0_50x40);
	lv_img_set_pivot(ui->screen_Engine, 0,0);
	lv_img_set_angle(ui->screen_Engine, 0);

	//Write codes screen_Fuel_BG
	ui->screen_Fuel_BG = lv_img_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Fuel_BG, 653, 419);
	lv_obj_set_size(ui->screen_Fuel_BG, 50, 40);

	//Write style state: LV_STATE_DEFAULT for style_screen_fuel_bg_main_main_default
	static lv_style_t style_screen_fuel_bg_main_main_default;
	if (style_screen_fuel_bg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_fuel_bg_main_main_default);
	else
		lv_style_init(&style_screen_fuel_bg_main_main_default);
	lv_style_set_img_recolor(&style_screen_fuel_bg_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_fuel_bg_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_fuel_bg_main_main_default, 23);
	lv_obj_add_style(ui->screen_Fuel_BG, &style_screen_fuel_bg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_Fuel_BG, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_Fuel_BG,&_Fuel_2_50x40);
	lv_img_set_pivot(ui->screen_Fuel_BG, 0,0);
	lv_img_set_angle(ui->screen_Fuel_BG, 0);

	//Write codes screen_Fuel
	ui->screen_Fuel = lv_img_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Fuel, 653, 419);
	lv_obj_set_size(ui->screen_Fuel, 50, 40);

	//Write style state: LV_STATE_DEFAULT for style_screen_fuel_main_main_default
	static lv_style_t style_screen_fuel_main_main_default;
	if (style_screen_fuel_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_fuel_main_main_default);
	else
		lv_style_init(&style_screen_fuel_main_main_default);
	lv_style_set_img_recolor(&style_screen_fuel_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_fuel_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_fuel_main_main_default, 255);
	lv_obj_add_style(ui->screen_Fuel, &style_screen_fuel_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_Fuel, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_Fuel,&_Fuel_0_50x40);
	lv_img_set_pivot(ui->screen_Fuel, 0,0);
	lv_img_set_angle(ui->screen_Fuel, 0);

	//Write codes screen_Battery_BG
	ui->screen_Battery_BG = lv_img_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Battery_BG, 726, 419);
	lv_obj_set_size(ui->screen_Battery_BG, 50, 40);

	//Write style state: LV_STATE_DEFAULT for style_screen_battery_bg_main_main_default
	static lv_style_t style_screen_battery_bg_main_main_default;
	if (style_screen_battery_bg_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_battery_bg_main_main_default);
	else
		lv_style_init(&style_screen_battery_bg_main_main_default);
	lv_style_set_img_recolor(&style_screen_battery_bg_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_battery_bg_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_battery_bg_main_main_default, 25);
	lv_obj_add_style(ui->screen_Battery_BG, &style_screen_battery_bg_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_Battery_BG, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_Battery_BG,&_Battery_2_50x40);
	lv_img_set_pivot(ui->screen_Battery_BG, 0,0);
	lv_img_set_angle(ui->screen_Battery_BG, 0);

	//Write codes screen_Battery
	ui->screen_Battery = lv_img_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Battery, 726, 419);
	lv_obj_set_size(ui->screen_Battery, 50, 40);

	//Write style state: LV_STATE_DEFAULT for style_screen_battery_main_main_default
	static lv_style_t style_screen_battery_main_main_default;
	if (style_screen_battery_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_battery_main_main_default);
	else
		lv_style_init(&style_screen_battery_main_main_default);
	lv_style_set_img_recolor(&style_screen_battery_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_battery_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_battery_main_main_default, 255);
	lv_obj_add_style(ui->screen_Battery, &style_screen_battery_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_Battery, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_Battery,&_Battery_0_50x40);
	lv_img_set_pivot(ui->screen_Battery, 0,0);
	lv_img_set_angle(ui->screen_Battery, 0);

	//Write codes screen_Speed
	ui->screen_Speed = lv_img_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Speed, 252, 281);
	lv_obj_set_size(ui->screen_Speed, 290, 185);

	//Write style state: LV_STATE_DEFAULT for style_screen_speed_main_main_default
	static lv_style_t style_screen_speed_main_main_default;
	if (style_screen_speed_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_speed_main_main_default);
	else
		lv_style_init(&style_screen_speed_main_main_default);
	lv_style_set_img_recolor(&style_screen_speed_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_speed_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_speed_main_main_default, 5);
	lv_obj_add_style(ui->screen_Speed, &style_screen_speed_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_Speed, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_Speed,&_Speedo_meter_2_290x185);
	lv_img_set_pivot(ui->screen_Speed, 0,0);
	lv_img_set_angle(ui->screen_Speed, 0);

	//Write codes screen_Speed_Label
	ui->screen_Speed_Label = lv_label_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Speed_Label, 317, 332);
	lv_obj_set_size(ui->screen_Speed_Label, 167, 100);
	lv_label_set_text(ui->screen_Speed_Label, "50");
	lv_label_set_long_mode(ui->screen_Speed_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_Speed_Label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_speed_label_main_main_default
	static lv_style_t style_screen_speed_label_main_main_default;
	if (style_screen_speed_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_speed_label_main_main_default);
	else
		lv_style_init(&style_screen_speed_label_main_main_default);
	lv_style_set_radius(&style_screen_speed_label_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_speed_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_speed_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_speed_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_speed_label_main_main_default, 0);
	lv_style_set_text_color(&style_screen_speed_label_main_main_default, lv_color_make(0xa8, 0xa9, 0xad));
	lv_style_set_text_font(&style_screen_speed_label_main_main_default, &lv_font_simsun_100);
	lv_style_set_text_letter_space(&style_screen_speed_label_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_speed_label_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_speed_label_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_speed_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_speed_label_main_main_default, 0);
	lv_obj_add_style(ui->screen_Speed_Label, &style_screen_speed_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_Speed_Unit
	ui->screen_Speed_Unit = lv_label_create(ui->screen_container_Dial);
	lv_obj_set_pos(ui->screen_Speed_Unit, 353, 423);
	lv_obj_set_size(ui->screen_Speed_Unit, 100, 32);
	lv_label_set_text(ui->screen_Speed_Unit, "Km/h");
	lv_label_set_long_mode(ui->screen_Speed_Unit, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_Speed_Unit, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_speed_unit_main_main_default
	static lv_style_t style_screen_speed_unit_main_main_default;
	if (style_screen_speed_unit_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_speed_unit_main_main_default);
	else
		lv_style_init(&style_screen_speed_unit_main_main_default);
	lv_style_set_radius(&style_screen_speed_unit_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_speed_unit_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_speed_unit_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_speed_unit_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_speed_unit_main_main_default, 0);
	lv_style_set_text_color(&style_screen_speed_unit_main_main_default, lv_color_make(0xa8, 0xa9, 0xad));
	lv_style_set_text_font(&style_screen_speed_unit_main_main_default, &lv_font_simsun_18);
	lv_style_set_text_letter_space(&style_screen_speed_unit_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_speed_unit_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_speed_unit_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_speed_unit_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_speed_unit_main_main_default, 0);
	lv_obj_add_style(ui->screen_Speed_Unit, &style_screen_speed_unit_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}