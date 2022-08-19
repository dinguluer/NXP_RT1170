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


void setup_scr_Rider_screen(lv_ui *ui){

	//Write codes Rider_screen
	ui->Rider_screen = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_rider_screen_main_main_default
	static lv_style_t style_rider_screen_main_main_default;
	if (style_rider_screen_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_screen_main_main_default);
	else
		lv_style_init(&style_rider_screen_main_main_default);
	lv_style_set_bg_color(&style_rider_screen_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_rider_screen_main_main_default, 0);
	lv_obj_add_style(ui->Rider_screen, &style_rider_screen_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Rider_screen_container_rider
	ui->Rider_screen_container_rider = lv_obj_create(ui->Rider_screen);
	lv_obj_set_pos(ui->Rider_screen_container_rider, 0, 0);
	lv_obj_set_size(ui->Rider_screen_container_rider, 800, 480);

	//Write style state: LV_STATE_DEFAULT for style_rider_screen_container_rider_main_main_default
	static lv_style_t style_rider_screen_container_rider_main_main_default;
	if (style_rider_screen_container_rider_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_screen_container_rider_main_main_default);
	else
		lv_style_init(&style_rider_screen_container_rider_main_main_default);
	lv_style_set_radius(&style_rider_screen_container_rider_main_main_default, 0);
	lv_style_set_bg_color(&style_rider_screen_container_rider_main_main_default, lv_color_make(0x11, 0x12, 0x12));
	lv_style_set_bg_grad_color(&style_rider_screen_container_rider_main_main_default, lv_color_make(0x0b, 0x0c, 0x0c));
	lv_style_set_bg_grad_dir(&style_rider_screen_container_rider_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_rider_screen_container_rider_main_main_default, 255);
	lv_style_set_border_color(&style_rider_screen_container_rider_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_rider_screen_container_rider_main_main_default, 0);
	lv_style_set_border_opa(&style_rider_screen_container_rider_main_main_default, 0);
	lv_style_set_pad_left(&style_rider_screen_container_rider_main_main_default, 0);
	lv_style_set_pad_right(&style_rider_screen_container_rider_main_main_default, 0);
	lv_style_set_pad_top(&style_rider_screen_container_rider_main_main_default, 0);
	lv_style_set_pad_bottom(&style_rider_screen_container_rider_main_main_default, 0);
	lv_obj_add_style(ui->Rider_screen_container_rider, &style_rider_screen_container_rider_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Rider_screen_rider_bg_image
	ui->Rider_screen_rider_bg_image = lv_img_create(ui->Rider_screen_container_rider);
	lv_obj_set_pos(ui->Rider_screen_rider_bg_image, 53, 9);
	lv_obj_set_size(ui->Rider_screen_rider_bg_image, 700, 126);

	//Write style state: LV_STATE_DEFAULT for style_rider_screen_rider_bg_image_main_main_default
	static lv_style_t style_rider_screen_rider_bg_image_main_main_default;
	if (style_rider_screen_rider_bg_image_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_screen_rider_bg_image_main_main_default);
	else
		lv_style_init(&style_rider_screen_rider_bg_image_main_main_default);
	lv_style_set_img_recolor(&style_rider_screen_rider_bg_image_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_rider_screen_rider_bg_image_main_main_default, 0);
	lv_style_set_img_opa(&style_rider_screen_rider_bg_image_main_main_default, 30);
	lv_obj_add_style(ui->Rider_screen_rider_bg_image, &style_rider_screen_rider_bg_image_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->Rider_screen_rider_bg_image, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->Rider_screen_rider_bg_image,&_rider_header_700x126);
	lv_img_set_pivot(ui->Rider_screen_rider_bg_image, 0,0);
	lv_img_set_angle(ui->Rider_screen_rider_bg_image, 0);

	//Write codes Rider_screen_Rider_label
	ui->Rider_screen_Rider_label = lv_label_create(ui->Rider_screen_container_rider);
	lv_obj_set_pos(ui->Rider_screen_Rider_label, 262, 33);
	lv_obj_set_size(ui->Rider_screen_Rider_label, 280, 32);
	lv_label_set_text(ui->Rider_screen_Rider_label, "Who is riding today ?");
	lv_label_set_long_mode(ui->Rider_screen_Rider_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->Rider_screen_Rider_label, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_rider_screen_rider_label_main_main_default
	static lv_style_t style_rider_screen_rider_label_main_main_default;
	if (style_rider_screen_rider_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_screen_rider_label_main_main_default);
	else
		lv_style_init(&style_rider_screen_rider_label_main_main_default);
	lv_style_set_radius(&style_rider_screen_rider_label_main_main_default, 0);
	lv_style_set_bg_color(&style_rider_screen_rider_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_rider_screen_rider_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_rider_screen_rider_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_rider_screen_rider_label_main_main_default, 0);
	lv_style_set_text_color(&style_rider_screen_rider_label_main_main_default, lv_color_make(0x8c, 0x78, 0x78));
	lv_style_set_text_font(&style_rider_screen_rider_label_main_main_default, &lv_font_montserratMedium_22);
	lv_style_set_text_letter_space(&style_rider_screen_rider_label_main_main_default, 2);
	lv_style_set_pad_left(&style_rider_screen_rider_label_main_main_default, 0);
	lv_style_set_pad_right(&style_rider_screen_rider_label_main_main_default, 0);
	lv_style_set_pad_top(&style_rider_screen_rider_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_rider_screen_rider_label_main_main_default, 0);
	lv_obj_add_style(ui->Rider_screen_Rider_label, &style_rider_screen_rider_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Rider_screen_Rider_selection_1
	ui->Rider_screen_Rider_selection_1 = lv_img_create(ui->Rider_screen_container_rider);
	lv_obj_set_pos(ui->Rider_screen_Rider_selection_1, 52, 150);
	lv_obj_set_size(ui->Rider_screen_Rider_selection_1, 226, 224);

	//Write style state: LV_STATE_DEFAULT for style_rider_screen_rider_selection_1_main_main_default
	static lv_style_t style_rider_screen_rider_selection_1_main_main_default;
	if (style_rider_screen_rider_selection_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_screen_rider_selection_1_main_main_default);
	else
		lv_style_init(&style_rider_screen_rider_selection_1_main_main_default);
	lv_style_set_img_recolor(&style_rider_screen_rider_selection_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_rider_screen_rider_selection_1_main_main_default, 0);
	lv_style_set_img_opa(&style_rider_screen_rider_selection_1_main_main_default, 255);
	lv_obj_add_style(ui->Rider_screen_Rider_selection_1, &style_rider_screen_rider_selection_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->Rider_screen_Rider_selection_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->Rider_screen_Rider_selection_1,&_Selection_box_226x224);
	lv_img_set_pivot(ui->Rider_screen_Rider_selection_1, 0,0);
	lv_img_set_angle(ui->Rider_screen_Rider_selection_1, 0);

	//Write codes Rider_screen_Rider_selection_2
	ui->Rider_screen_Rider_selection_2 = lv_img_create(ui->Rider_screen_container_rider);
	lv_obj_set_pos(ui->Rider_screen_Rider_selection_2, 273, 150);
	lv_obj_set_size(ui->Rider_screen_Rider_selection_2, 226, 224);

	//Write style state: LV_STATE_DEFAULT for style_rider_screen_rider_selection_2_main_main_default
	static lv_style_t style_rider_screen_rider_selection_2_main_main_default;
	if (style_rider_screen_rider_selection_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_screen_rider_selection_2_main_main_default);
	else
		lv_style_init(&style_rider_screen_rider_selection_2_main_main_default);
	lv_style_set_img_recolor(&style_rider_screen_rider_selection_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_rider_screen_rider_selection_2_main_main_default, 0);
	lv_style_set_img_opa(&style_rider_screen_rider_selection_2_main_main_default, 255);
	lv_obj_add_style(ui->Rider_screen_Rider_selection_2, &style_rider_screen_rider_selection_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->Rider_screen_Rider_selection_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->Rider_screen_Rider_selection_2,&_Selection_box_226x224);
	lv_img_set_pivot(ui->Rider_screen_Rider_selection_2, 0,0);
	lv_img_set_angle(ui->Rider_screen_Rider_selection_2, 0);

	//Write codes Rider_screen_Rider_selection_3
	ui->Rider_screen_Rider_selection_3 = lv_img_create(ui->Rider_screen_container_rider);
	lv_obj_set_pos(ui->Rider_screen_Rider_selection_3, 494, 150);
	lv_obj_set_size(ui->Rider_screen_Rider_selection_3, 226, 224);

	//Write style state: LV_STATE_DEFAULT for style_rider_screen_rider_selection_3_main_main_default
	static lv_style_t style_rider_screen_rider_selection_3_main_main_default;
	if (style_rider_screen_rider_selection_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_screen_rider_selection_3_main_main_default);
	else
		lv_style_init(&style_rider_screen_rider_selection_3_main_main_default);
	lv_style_set_img_recolor(&style_rider_screen_rider_selection_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_rider_screen_rider_selection_3_main_main_default, 0);
	lv_style_set_img_opa(&style_rider_screen_rider_selection_3_main_main_default, 255);
	lv_obj_add_style(ui->Rider_screen_Rider_selection_3, &style_rider_screen_rider_selection_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->Rider_screen_Rider_selection_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->Rider_screen_Rider_selection_3,&_Selection_box_226x224);
	lv_img_set_pivot(ui->Rider_screen_Rider_selection_3, 0,0);
	lv_img_set_angle(ui->Rider_screen_Rider_selection_3, 0);

	//Write codes Rider_screen_img_1
	ui->Rider_screen_img_1 = lv_img_create(ui->Rider_screen);
	lv_obj_set_pos(ui->Rider_screen_img_1, 57, 86);
	lv_obj_set_size(ui->Rider_screen_img_1, 170, 120);

	//Write style state: LV_STATE_DEFAULT for style_rider_screen_img_1_main_main_default
	static lv_style_t style_rider_screen_img_1_main_main_default;
	if (style_rider_screen_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rider_screen_img_1_main_main_default);
	else
		lv_style_init(&style_rider_screen_img_1_main_main_default);
	lv_style_set_img_recolor(&style_rider_screen_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_rider_screen_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_rider_screen_img_1_main_main_default, 255);
	lv_obj_add_style(ui->Rider_screen_img_1, &style_rider_screen_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->Rider_screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->Rider_screen_img_1,&_menu_button_170x120);
	lv_img_set_pivot(ui->Rider_screen_img_1, 0,0);
	lv_img_set_angle(ui->Rider_screen_img_1, 0);
}