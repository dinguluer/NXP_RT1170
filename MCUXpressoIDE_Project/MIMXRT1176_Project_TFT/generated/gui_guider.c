/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"


void setup_ui(lv_ui *ui){
	setup_scr_Rider_screen(ui);
	setup_scr_screen(ui);
	setup_scr_Logo_Screen(ui);
	setup_scr_rider_selected_screen(ui);
	setup_scr_screen_menu_scroll(ui);
	//setup_scr_screen_menu_roller(ui);
	setup_scr_screen_drawing(ui);

	//lv_scr_load(ui->screen);
	//lv_scr_load_anim(ui->Logo_Screen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 70, 0, false);
	lv_scr_load(ui->Logo_Screen);
}
