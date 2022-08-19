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

volatile uint8_t button_state_pressed = 0;
volatile uint8_t button_state_released = 0;

uint16_t xxxxx;

//#define RIDER_SCREEN_LOGO_FONT lv_font_montserratMedium_22

#define RIDER_SCREEN_LOGO_FONT lv_font_Alatsi_Regular_22

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

//    lv_obj_clear_flag(guider_ui.Rider_screen_Rider_selection_1, LV_OBJ_FLAG_HIDDEN);
//    lv_obj_add_flag(guider_ui.Rider_screen_Rider_selection_2, LV_OBJ_FLAG_HIDDEN);
//	lv_obj_add_flag(guider_ui.Rider_screen_Rider_selection_3, LV_OBJ_FLAG_HIDDEN);

    if(code == LV_EVENT_CLICKED) {
        //LV_LOG_USER("Clicked");
        //__asm volatile ("nop");
    }
    else if(code == LV_EVENT_PRESSED) {
    	//__asm volatile ("nop");
    	button_state_pressed = 1;
    }
    else if(code == LV_EVENT_RELEASED) {
    	//__asm volatile ("nop");
    	button_state_released = 1;
    }
    else
	{
    	//__asm volatile ("nop");
	}
}

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
	lv_style_set_text_font(&style_rider_screen_rider_label_main_main_default, &RIDER_SCREEN_LOGO_FONT);
	lv_style_set_text_letter_space(&style_rider_screen_rider_label_main_main_default, 2);
	lv_style_set_pad_left(&style_rider_screen_rider_label_main_main_default, 0);
	lv_style_set_pad_right(&style_rider_screen_rider_label_main_main_default, 0);
	lv_style_set_pad_top(&style_rider_screen_rider_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_rider_screen_rider_label_main_main_default, 0);
	lv_obj_add_style(ui->Rider_screen_Rider_label, &style_rider_screen_rider_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Rider_screen_Rider_selection_1
	ui->Rider_screen_Rider_selection_1 = lv_img_create(ui->Rider_screen_container_rider);
	lv_obj_set_pos(ui->Rider_screen_Rider_selection_1, 64, 150);
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
	lv_obj_set_pos(ui->Rider_screen_Rider_selection_2, 285, 150);
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
	lv_obj_set_pos(ui->Rider_screen_Rider_selection_3, 506, 150);
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

	//Dinesh
	//DInesh
	lv_obj_add_flag(ui->Rider_screen_Rider_selection_2, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->Rider_screen_Rider_selection_3, LV_OBJ_FLAG_HIDDEN);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// create the Scroller : Snapping
	    //lv_obj_t * panel = lv_obj_create(ui->Rider_screen_container_rider);
	    ui->panel= lv_obj_create(ui->Rider_screen_container_rider);
	    lv_obj_set_size(ui->panel, 720, 240);
	    lv_obj_set_scroll_snap_x(ui->panel, LV_SCROLL_SNAP_CENTER);
	    lv_obj_set_flex_flow(ui->panel, LV_FLEX_FLOW_ROW);
	    //lv_obj_align(ui->panel, LV_ALIGN_CENTER, 0, 20);     //https://docs.lvgl.io/latest/en/html/widgets/obj.html?highlight=lv_obj_align
	    lv_obj_align(ui->panel, LV_ALIGN_CENTER, 0, 20);

        // Dinesh
        /*Add the transition and some transformation to the presses state.*/
	    // style Default
	    // best comments -->  https://chowdera.com/2022/01/202201152354563630.html
	    static lv_style_t style;
	    lv_style_init(&style);  // ?????????????????
	    lv_style_set_img_opa(&style, 100);
        /*Init the pressed style*/
        static lv_style_t style_pr;
        lv_style_init(&style_pr);
        /*Ad a large outline when pressed*/
        lv_style_set_outline_width(&style_pr, 80/*100 210+1*/); // Set the outline width
        lv_style_set_outline_opa(&style_pr, LV_OPA_TRANSP); // Set the outline transparency to transparent
        //lv_style_set_translate_y(&style_pr, 5);//translate y Direction down 5 Pixels
        //lv_style_set_shadow_ofs_y(&style_pr, 3);// Shadow offset is 3, This moves down when the key is pressed 5 Pixels +3 The shadow of a pixel point ,
                                                // And the shadow offset when the key is not pressed 8 The two pixels are consistent ,
                                                //So the bottom of the shadow doesn't move , Only the button body moves down when pressed 5 Pixels
        lv_style_set_bg_color(&style_pr, lv_palette_darken(LV_PALETTE_BLUE, 2));
        lv_style_set_bg_grad_color(&style_pr, lv_palette_darken(LV_PALETTE_BLUE, 4));
        /*Add a transition to the the outline*/
        static lv_style_transition_dsc_t trans;
        static lv_style_prop_t props[] = {LV_STYLE_OUTLINE_WIDTH, LV_STYLE_OUTLINE_OPA, 0};
        lv_style_transition_dsc_init(&trans, props, lv_anim_path_linear, 200, 0, NULL); // Initial transition to linear animation
        lv_style_set_transition(&style_pr, &trans);

	    int i;
	    for(i = 1; i < 7; i++) {
	        lv_obj_t * btn ;

	        //btn = lv_btn_create(ui->panel);
	        btn = lv_imgbtn_create(ui->panel);
//	        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED,NULL, &_Man_alpha_210x210,NULL);
//	        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_PRESSED,NULL, &_Man_alpha_210x210,NULL);
	    	//lv_imgbtn_set_src(ui->Rider_screen_button, LV_IMGBTN_STATE_RELEASED, NULL, &_Battery_0_alpha_100x50, NULL);
	        //lv_imgbtn_set_src(btn, LV_BTN_STATE_PRESSED, &_Battery_0_50x40);

	        if(i==1)
	        {
	        	ui->btn1 = btn ;
		        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED,NULL, &_Man_alpha_210x210,NULL);
		        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_PRESSED,NULL, &_Man_alpha_210x210,NULL);
	        }
	        else if(i== 2)
	        {
	        	ui->btn2 = btn;
		        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED,NULL, &_women_alpha_210x210,NULL);
		        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_PRESSED,NULL, &_women_alpha_210x210,NULL);
	        }
	        else if(i== 3)
	        {
	        	ui->btn3 = btn;
		        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED,NULL, &_boy_alpha_210x210,NULL);
		        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_PRESSED,NULL, &_boy_alpha_210x210,NULL);
	        }
	        else if(i== 4)
	        {
	        	ui->btn4 = btn;
		        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED,NULL, &_girl_alpha_210x210,NULL);
		        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_PRESSED,NULL, &_girl_alpha_210x210,NULL);
	        }
	        else if(i== 5)
	        {
	        	ui->btn5 = btn;
		        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED,NULL, &_Man_alpha_210x210,NULL);
		        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_PRESSED,NULL, &_Man_alpha_210x210,NULL);
	        }
	        else if(i== 6)
	        {
	        	ui->btn6 = btn;
	        	lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED,NULL, &_add_user_alpha_210x210,NULL);
	        	lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_PRESSED,NULL, &_add_user_alpha_210x210,NULL);
	        }
	        else
	        {
	        	__asm volatile ("nop");
	        }
	        lv_obj_set_size(btn, 210, lv_pct(100));
	        lv_obj_t * label = lv_label_create(btn);
//	        if(i == 3) {
//	            lv_label_set_text_fmt(label, "Panel %d\nno snap", i);
//	            lv_obj_clear_flag(btn, LV_OBJ_FLAG_SNAPABLE);
//	        } else {
//	            lv_label_set_text_fmt(label, "Panel %d", i);
//	        }
	        lv_label_set_text_fmt(label, "Rider - %d", i);
	        //lv_obj_center(label);
	        lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, 0);
	        static lv_style_t topstyle;
	        lv_style_set_text_color(&topstyle, lv_color_make(0x8c, 0x78, 0x78));
	        lv_obj_add_style(label, &topstyle, LV_PART_MAIN|LV_STATE_DEFAULT);
	        // https://docs.lvgl.io/8.0/widgets/core/label.html
	        //https://forum.lvgl.io/t/label-background-color/2733

	        //DInesh
	        lv_obj_add_style(btn, &style, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_add_style(btn, &style_pr, LV_PART_MAIN|LV_STATE_PRESSED);
//	        lv_obj_set_size(btn, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
//	        lv_obj_center(btn);

	    }
	    lv_obj_update_snap(ui->panel, LV_ANIM_ON);
	    //lv_obj_add_flag(ui->panel, LV_OBJ_FLAG_SCROLL_ONE);
	    lv_obj_clear_flag(ui->panel, LV_OBJ_FLAG_SCROLL_ONE);

	    // lv_obj_set_scrollbar_mode   lv_obj_set_scroll_dir  lv_obj_set_scroll_snap_x  lv_obj_set_scroll_snap_y
	    lv_obj_set_scrollbar_mode(ui->panel,LV_SCROLLBAR_MODE_OFF);
	    // $$$$$$$$$$$$$$$$$$$$
	    // Scrollbar color
	//    static lv_style_t style_red;
	//    lv_style_init(&style_red);
	//    lv_style_set_bg_color(&style_red, lv_color_make(0xFF,0x00,0x00));  //#define LV_COLOR_RED     LV_COLOR_MAKE(0xFF,0x00,0x00)  --->  https://github.com/sidddy/lvgl/blob/master/lv_misc/lv_color.h
	//    lv_obj_add_style(ui->panel, &style_red, LV_PART_SCROLLBAR);

	      //The direction in which scrolling happens can be controlled by lv_obj_set_scroll_dir(obj, LV_DIR_...)
	    lv_obj_set_scroll_dir(ui->panel, LV_DIR_RIGHT|LV_DIR_LEFT);
//	    lv_obj_scroll_by(ui->panel,-900,0,LV_ANIM_OFF);
//	    lv_obj_scroll_by(ui->panel,900,0,LV_ANIM_OFF);  // Move right

	    //change panel opacity to --> 0
	    static lv_style_t style_panel;
	    lv_style_set_bg_color(&style_panel, lv_color_make(0xff, 0xff, 0xff));
	    lv_style_set_bg_opa(&style_panel, 0);
	    lv_style_set_border_width(&style_panel, 0);
	    lv_style_set_border_opa(&style_panel, 0);
	    lv_obj_add_style(ui->panel, &style_panel, LV_PART_MAIN|LV_STATE_DEFAULT);

	    // Set Event Handler for -->  ui->btn2
	    lv_obj_add_event_cb(ui->btn2, event_handler, LV_EVENT_PRESSED, NULL);
	    lv_obj_add_event_cb(ui->btn2, event_handler, LV_EVENT_RELEASED, NULL);
//	    lv_event_send(ui->btn3,LV_EVENT_CLICKED,NULL);
	//
	//    lv_obj_add_style(btn1, &style, 0);
	//    lv_obj_add_style(btn1, &style_pr, LV_STATE_PRESSED);

	//    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);
	//    lv_arc_set_rotation
	//    lv_draw_rect_dsc_t
	//    lv_canvas_draw_rect
	//	lv_draw_rect_dsc_t

}
