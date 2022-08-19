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

static void mask_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    static int16_t mask_top_id = -1;
    static int16_t mask_bottom_id = -1;

    if (code == LV_EVENT_COVER_CHECK) {
        lv_event_set_cover_res(e, LV_COVER_RES_MASKED);

    } else if (code == LV_EVENT_DRAW_MAIN_BEGIN) {
        /* add mask */
        const lv_font_t * font = lv_obj_get_style_text_font(obj, LV_PART_MAIN);
        lv_coord_t line_space = lv_obj_get_style_text_line_space(obj, LV_PART_MAIN);
        lv_coord_t font_h = lv_font_get_line_height(font);

        lv_area_t roller_coords;
        lv_obj_get_coords(obj, &roller_coords);

        lv_area_t rect_area;
        rect_area.x1 = roller_coords.x1;
        rect_area.x2 = roller_coords.x2;
        rect_area.y1 = roller_coords.y1;
        rect_area.y2 = roller_coords.y1 + (lv_obj_get_height(obj) - font_h - line_space) / 2;

        lv_draw_mask_fade_param_t * fade_mask_top = lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_top, &rect_area, LV_OPA_TRANSP, rect_area.y1, LV_OPA_COVER, rect_area.y2);
        mask_top_id = lv_draw_mask_add(fade_mask_top, NULL);

        rect_area.y1 = rect_area.y2 + font_h + line_space - 1;
        rect_area.y2 = roller_coords.y2;

        lv_draw_mask_fade_param_t * fade_mask_bottom =lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_bottom, &rect_area, LV_OPA_COVER, rect_area.y1, LV_OPA_TRANSP, rect_area.y2);
        mask_bottom_id = lv_draw_mask_add(fade_mask_bottom, NULL);

    } else if (code == LV_EVENT_DRAW_POST_END) {
        lv_draw_mask_fade_param_t * fade_mask_top = lv_draw_mask_remove_id(mask_top_id);
        lv_draw_mask_fade_param_t * fade_mask_bottom = lv_draw_mask_remove_id(mask_bottom_id);
        lv_mem_buf_release(fade_mask_top);
        lv_mem_buf_release(fade_mask_bottom);
        mask_top_id = -1;
        mask_bottom_id = -1;
    }
}

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
	lv_style_set_border_opa(&style_screen_menu_roller_container_menu_roller_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_menu_roller_container_menu_roller_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_menu_roller_container_menu_roller_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_menu_roller_container_menu_roller_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_menu_roller_container_menu_roller_main_main_default, 0);
	lv_obj_add_style(ui->screen_menu_roller_container_menu_roller, &style_screen_menu_roller_container_menu_roller_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	// ==========================   roller  ===================================

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, lv_color_black());
    lv_style_set_text_color(&style, lv_color_white());
    lv_style_set_border_color(&style, lv_color_black());
    lv_style_set_border_width(&style, 0);
    lv_style_set_bg_opa(&style, 0);
    lv_style_set_border_opa(&style, 0);
    lv_style_set_pad_all(&style, 0);
//    lv_obj_add_style(lv_scr_act(), &style, 0);

    ui->roller1 = lv_roller_create(ui->screen_menu_roller_container_menu_roller);
    lv_obj_add_style(ui->roller1, &style, 0);  // 0 --> LV_PART_MAIN|LV_STATE_DEFAULT
    lv_obj_set_style_bg_opa(ui->roller1, LV_OPA_TRANSP, LV_PART_SELECTED);

//#if LV_FONT_MONTSERRAT_22
//    lv_obj_set_style_text_font(ui->roller1, &lv_font_montserratMedium_22, LV_PART_SELECTED);

    lv_obj_set_style_text_font(ui->roller1, &lv_font_montserratMedium_22, LV_PART_SELECTED);
    lv_obj_set_style_text_font(ui->roller1, &lv_font_montserratMedium_22, LV_PART_MAIN);

//    lv_obj_set_style_text_font(ui->roller1, &lv_font_montserratMedium_22, LV_PART_SELECTED|LV_STATE_DEFAULT);
//    lv_obj_set_style_text_font(ui->roller1, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
//    lv_obj_set_style_text_font(ui->roller1, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    //#endif

    lv_roller_set_options(ui->roller1,
                        "January\n"
                        "February\n"
                        "March\n"
                        "April\n"
                        "May\n"
                        "June\n"
//                        "July\n"
//                        "August\n"
//                        "September\n"
//                        "October\n"
//                        "November\n"
//                        "December"
						,LV_ROLLER_MODE_INFINITE);//LV_ROLLER_MODE_NORMAL);

    lv_obj_center(ui->roller1);
    lv_roller_set_visible_row_count(ui->roller1, 3);
    lv_obj_add_event_cb(ui->roller1, mask_event_cb, LV_EVENT_ALL, NULL);

    //lv_roller_set_selected(ui->roller1,2,LV_ANIM_ON);
    //lv_roller_get_selected

//    lv_obj_set_size(btn, 210, lv_pct(100));
//    lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, 0);

    //https://github.com/lvgl/lvgl/issues/1102

}
