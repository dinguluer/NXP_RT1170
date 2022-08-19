/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *screen;
	lv_obj_t *screen_container_Dial;
	lv_obj_t *screen_ODO_roller_image;
	lv_obj_t *screen_ODO_roller_0;
	lv_obj_t *screen_ODO_roller_1;
	lv_obj_t *screen_ODO_roller_2;
	lv_obj_t *screen_ODO_roller_3;
	lv_obj_t *screen_ODO_roller_4;
	lv_obj_t *screen_ODO_roller_5;
	lv_obj_t *screen_ODO_roller_6;
	lv_obj_t *screen_Background_imgage;
	lv_obj_t *screen_Time_Label;
	lv_obj_t *screen_Date_Label;
	lv_obj_t *screen_Dial_image;
	lv_obj_t *screen_Dial_meter;
	lv_obj_t *screen_High_Beam_BG;
	lv_obj_t *screen_High_Beam;
	lv_obj_t *screen_Engine_BG;
	lv_obj_t *screen_Engine;
	lv_obj_t *screen_Fuel_BG;
	lv_obj_t *screen_Fuel;
	lv_obj_t *screen_Battery_BG;
	lv_obj_t *screen_Battery;
	lv_obj_t *screen_Speed;
	lv_obj_t *screen_Speed_Label;
	lv_obj_t *screen_Speed_Unit;
	lv_obj_t *Logo_Screen;
	lv_obj_t *Logo_Screen_container_Logo;
	lv_obj_t *Logo_Screen_img_1;
	lv_obj_t *Rider_screen;
	lv_obj_t *Rider_screen_container_rider;
	lv_obj_t *Rider_screen_rider_bg_image;
	lv_obj_t *Rider_screen_Rider_label;
	lv_obj_t *Rider_screen_Rider_selection_1;
	lv_obj_t *Rider_screen_Rider_selection_2;
	lv_obj_t *Rider_screen_Rider_selection_3;
	lv_obj_t *rider_selected_screen;
	lv_obj_t *rider_selected_screen_container_rider_selected;
	lv_obj_t *rider_selected_screen_Rider_selec_icon;
	lv_obj_t *rider_selected_screen_Rider_selec_icon_label;
	lv_obj_t *rider_selected_screen_Area_limit;
	lv_obj_t *rider_selected_screen_Area_limit_label;
	lv_obj_t *rider_selected_screen_Time_fence;
	lv_obj_t *rider_selected_screen_Time_fence_label;
	lv_obj_t *rider_selected_screen_Speed_limit;
	lv_obj_t *rider_selected_screen_Speed_limit_label;
	lv_obj_t *rider_selected_screen_Mode_restriction;
	lv_obj_t *rider_selected_screen_Mode_restriction_label;
	lv_obj_t *rider_selected_screen_shield_select_icon;
	lv_obj_t *rider_selected_screen_shield_select_icon_label;
	lv_obj_t *rider_selected_screen_label_area;
	lv_obj_t *rider_selected_screen_label_time;
	lv_obj_t *rider_selected_screen_label_speed;
	lv_obj_t *rider_selected_screen_label_mode;
    lv_obj_t *screen_menu_scroll;
	lv_obj_t *screen_menu_scroll_Container_menu_scroll;
	lv_obj_t *screen_menu_scroll_Menu_select_label_1;
	lv_obj_t *screen_menu_scroll_Menu_select_label_2;
	lv_obj_t *screen_menu_scroll_Menu_select_label_3;
	lv_obj_t *screen_menu_scroll_Menu_select_label_4;
	lv_obj_t *screen_menu_scroll_Menu_select_label_5;
	lv_obj_t *screen_menu_scroll_Menu_select_1;
	lv_obj_t *screen_menu_scroll_Menu_select_2;
	lv_obj_t *screen_menu_scroll_Menu_select_3;
	lv_obj_t *screen_menu_scroll_menu_top_line;
	lv_obj_t *screen_menu_scroll_menu_bottom_line;
	lv_obj_t *screen_menu_scroll_menu_vertical_line;
	lv_obj_t *screen_menu_scroll_menu_label;
	lv_obj_t *screen_menu_scroll_menu_item_1;
	lv_obj_t *screen_menu_scroll_menu_item_2;
	lv_obj_t *screen_menu_scroll_menu_item_3;
	lv_obj_t *screen_menu_scroll_menu_item_4;
	lv_obj_t *screen_menu_scroll_menu_item_5;
	lv_obj_t *screen_menu_roller;
	lv_obj_t *screen_menu_roller_container_menu_roller;
	lv_obj_t *screen_drawing;
	lv_obj_t *screen_drawing_container_drawing;
	lv_obj_t *screen_drawing_canvas_triangle_L_1;
	lv_obj_t *screen_drawing_canvas_triangle_L_2;
	lv_obj_t *screen_drawing_canvas_triangle_R_1;
	lv_obj_t *screen_drawing_canvas_triangle_R_2;
	lv_obj_t *screen_drawing_RPM_18;
	lv_obj_t *screen_drawing_RPM_17;
	lv_obj_t *screen_drawing_RPM_16;
	lv_obj_t *screen_drawing_RPM_15;
	lv_obj_t *screen_drawing_RPM_14;
	lv_obj_t *screen_drawing_RPM_13;
	lv_obj_t *screen_drawing_RPM_12;
	lv_obj_t *screen_drawing_RPM_11;
	lv_obj_t *screen_drawing_RPM_10;
	lv_obj_t *screen_drawing_RPM_9;
	lv_obj_t *screen_drawing_RPM_8;
	lv_obj_t *screen_drawing_RPM_7;
	lv_obj_t *screen_drawing_RPM_6;
	lv_obj_t *screen_drawing_RPM_5;
	lv_obj_t *screen_drawing_RPM_4;
	lv_obj_t *screen_drawing_RPM_3;
	lv_obj_t *screen_drawing_RPM_2;
	lv_obj_t *screen_drawing_RPM_1;
	lv_obj_t *screen_drawing_RPM_0;
	lv_obj_t *screen_drawing_Gear_label;
	lv_obj_t *screen_drawing_GEAR_CIRCLE;
	lv_obj_t *screen_drawing_Gear_value_label;
	lv_obj_t *screen_drawing_speed_value_label;
	lv_obj_t *screen_drawing_speed_unit_label;
	lv_obj_t *screen_drawing_RPM_value_label;
	lv_obj_t *screen_drawing_RPM_UNIT_label;
	lv_obj_t *screen_drawing_Logo_drawing;
	lv_obj_t *screen_drawing_Time_level_drawing_1;
	lv_obj_t *screen_drawing_Time_level_drawing_0;
	lv_obj_t *screen_drawing_Time_level_drawing;
	lv_obj_t *screen_drawing_Date_Label_drawing_2;
	lv_obj_t *screen_drawing_Date_Label_drawing_1;
	lv_obj_t *screen_drawing_Date_Label_drawing_0;
	lv_obj_t *screen_drawing_Date_Label_drawing;
	lv_obj_t *screen_drawing_drawing_Guage_1;
	lv_obj_t *screen_drawing_cluster_image;
	lv_obj_t *screen_drawing_arc_indicator;
	lv_obj_t *canvas_1;
	lv_obj_t *screen_drawing_drawing_Guage_2;
	lv_obj_t *screen_drawing_FUEL_image;
	lv_obj_t *screen_drawing_FUEL_Empty_label;
	lv_obj_t *screen_drawing_FUEL_Full_label;
	lv_obj_t *screen_drawing_Red_fuel_arc;
	lv_obj_t *screen_drawing_Green_fuel_arc;
	lv_obj_t *screen_drawing_FUEL_level;
	lv_obj_t *screen_drawing_engine_temperature;
	lv_obj_t *screen_drawing_engine_temp_drawing;
	lv_obj_t *screen_drawing_Battery_0_drawing;
	lv_obj_t *screen_drawing_Battery_0_drawing_level;

	//Dinesh
	lv_meter_indicator_t *screen_Dial_meter_scale_1_ndimg_0;
	lv_obj_t * panel;
	lv_obj_t *btn1;
	lv_obj_t *btn2;
	lv_obj_t *btn3;
	lv_obj_t *btn4;
	lv_obj_t *btn5;
	lv_obj_t *btn6;
	//Dinesh
	lv_obj_t *panel_scroll_menu;
	lv_obj_t *panel_scroll_btn1;
	lv_obj_t *panel_scroll_btn2;
	lv_obj_t *panel_scroll_btn3;
	lv_obj_t *panel_scroll_btn4;
	lv_obj_t *panel_scroll_btn5;
	lv_obj_t *panel_scroll_btn6;
	//DInesh
	lv_obj_t *roller1;
	//Dinesh
	lv_obj_t * line1;
	lv_obj_t * line2;
	lv_obj_t * line3;
	lv_obj_t * line4;
	lv_obj_t * line5;
	lv_obj_t * line6;
	lv_obj_t * line7;
	lv_obj_t * line8;
	lv_obj_t * line9;
	lv_obj_t * line10;
	lv_obj_t * line11;
	lv_obj_t * line12;
	lv_obj_t * line13;
	lv_obj_t * line14;
	lv_obj_t * line15;
	lv_obj_t * line16;
	lv_obj_t * line17;
	lv_obj_t * line18;
	lv_obj_t * line19;
	lv_obj_t * line20;
	lv_obj_t * line21;
	lv_obj_t * line22;
	lv_obj_t * line23;
	lv_obj_t * line24;
	lv_obj_t * line25;
	lv_obj_t * line26;
	lv_obj_t * line27;
	lv_obj_t * line28;
	lv_obj_t * line29;
	lv_obj_t * line30;
	lv_obj_t * line31;
	lv_obj_t * line32;
	lv_obj_t * line33;
	lv_obj_t * line34;
	lv_obj_t * line35;
	lv_obj_t * line36;
	lv_obj_t * line37;
	lv_obj_t * line38;
	lv_obj_t * line39;
	lv_obj_t * line40;
	lv_obj_t * line41;
	lv_obj_t * line42;
	lv_obj_t * line43;
	lv_obj_t * line44;
	lv_obj_t * line45;
	lv_obj_t * line46;
	lv_obj_t * line47;
	lv_obj_t * line48;
	lv_obj_t * line49;
	lv_obj_t * line50;
	lv_obj_t * line51;
	lv_obj_t * line52;
	lv_obj_t * line53;
	lv_obj_t * line54;
	lv_obj_t * line55;
	lv_obj_t * line56;
	lv_obj_t * line57;
	lv_obj_t * line58;
	lv_obj_t * line59;
	lv_obj_t * line60;
	lv_obj_t * line61;
	lv_obj_t * line62;
	lv_obj_t * line63;
	lv_obj_t * line64;
	lv_obj_t * line65;
	lv_obj_t * line66;
	lv_obj_t * line67;
	lv_obj_t * line68;
	lv_obj_t * line69;
	lv_obj_t * line70;



	//Dinesh
	lv_obj_t * right_line1;
	lv_obj_t * right_line2;
	lv_obj_t * right_line3;
	lv_obj_t * right_line4;
	lv_obj_t * right_line5;
	lv_obj_t * right_line6;
	lv_obj_t * right_line7;
	lv_obj_t * right_line8;
	lv_obj_t * right_line9;
	lv_obj_t * right_line10;
	lv_obj_t * right_line11;
	lv_obj_t * right_line12;
	lv_obj_t * right_line13;
	lv_obj_t * right_line14;
	lv_obj_t * right_line15;
	lv_obj_t * right_line16;
	lv_obj_t * right_line17;
	lv_obj_t * right_line18;
	lv_obj_t * right_line19;
	lv_obj_t * right_line20;
	lv_obj_t * right_line21;
	lv_obj_t * right_line22;
	lv_obj_t * right_line23;
	lv_obj_t * right_line24;
	lv_obj_t * right_line25;
	lv_obj_t * right_line26;
	lv_obj_t * right_line27;
	lv_obj_t * right_line28;
	lv_obj_t * right_line29;
	lv_obj_t * right_line30;
	lv_obj_t * right_line31;
	lv_obj_t * right_line32;
	lv_obj_t * right_line33;
	lv_obj_t * right_line34;
	lv_obj_t * right_line35;
	lv_obj_t * right_line36;
	lv_obj_t * right_line37;
	lv_obj_t * right_line38;
	lv_obj_t * right_line39;
	lv_obj_t * right_line40;
	lv_obj_t * right_line41;
	lv_obj_t * right_line42;
	lv_obj_t * right_line43;
	lv_obj_t * right_line44;
	lv_obj_t * right_line45;
	lv_obj_t * right_line46;
	lv_obj_t * right_line47;
	lv_obj_t * right_line48;
	lv_obj_t * right_line49;
	lv_obj_t * right_line50;
	lv_obj_t * right_line51;
	lv_obj_t * right_line52;
	lv_obj_t * right_line53;
	lv_obj_t * right_line54;
	lv_obj_t * right_line55;
	lv_obj_t * right_line56;
	lv_obj_t * right_line57;
	lv_obj_t * right_line58;
	lv_obj_t * right_line59;
	lv_obj_t * right_line60;
	lv_obj_t * right_line61;
	lv_obj_t * right_line62;
	lv_obj_t * right_line63;
	lv_obj_t * right_line64;
	lv_obj_t * right_line65;
	lv_obj_t * right_line66;
	lv_obj_t * right_line67;
	lv_obj_t * right_line68;
	lv_obj_t * right_line69;
	lv_obj_t * right_line70;

	//Dinesh
	lv_obj_t * batteryline1;
	lv_obj_t * batteryline2;
	lv_obj_t * batteryline3;
	lv_obj_t * batteryline4;
	lv_obj_t * batteryline5;
	lv_obj_t * batteryline6;
	lv_obj_t * batteryline7;
	lv_obj_t * batteryline8;
	lv_obj_t * batteryline9;
	lv_obj_t * batteryline10;

	//Dinesh
	lv_obj_t * templine1;
	lv_obj_t * templine2;
	lv_obj_t * templine3;
	lv_obj_t * templine4;
	lv_obj_t * templine5;
	lv_obj_t * templine6;
	lv_obj_t * templine7;
	lv_obj_t * templine8;
	lv_obj_t * templine9;
	lv_obj_t * templine10;

	//Dinesh
	lv_obj_t *meterlineS_1;
	lv_obj_t * meterline1;
	lv_obj_t * meterline2;
	lv_obj_t * meterline3;
	lv_obj_t * meterline4;
	lv_obj_t * meterline5;
	lv_obj_t * meterline6;
	lv_obj_t * meterline7;
	lv_obj_t * meterline8;
	lv_obj_t * meterline9;
	lv_obj_t * meterline10;
	lv_obj_t * meterline11;
	lv_obj_t * meterline12;
	lv_obj_t * meterline13;
	lv_obj_t * meterline14;
	lv_obj_t * meterline15;
	lv_obj_t * meterline16;
	lv_obj_t * meterline17;
	lv_obj_t *meterlineE_1;

	lv_obj_t *draw_arc_indicator;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
void setup_scr_Logo_Screen(lv_ui *ui);
void setup_scr_Rider_screen(lv_ui *ui);
void setup_scr_rider_selected_screen(lv_ui *ui);
void setup_scr_screen_menu_scroll(lv_ui *ui);
void setup_scr_screen_menu_roller(lv_ui *ui);
void setup_scr_screen_drawing(lv_ui *ui);
LV_IMG_DECLARE(_Speedo_meter_2_290x185);
LV_IMG_DECLARE(_rider_header_700x126);
LV_IMG_DECLARE(_Selection_box_226x224);
LV_IMG_DECLARE(_Engine_0_50x40);
LV_IMG_DECLARE(_Battery_0_50x40);
LV_IMG_DECLARE(_mode_restriction_alpha_100x100);
LV_IMG_DECLARE(_Area_limit_alpha_100x100);
LV_IMG_DECLARE(_NXP_LOGO_400x200);
LV_IMG_DECLARE(_Back_gnd_800x480);
LV_IMG_DECLARE(_Fuel_0_50x40);
LV_IMG_DECLARE(_Time_fence_alpha_100x100);
LV_IMG_DECLARE(_Dial_500x388);
LV_IMG_DECLARE(_Scheild_select_alpha_40x40);
LV_IMG_DECLARE(_High_Beam_0_50x40);
LV_IMG_DECLARE(_Women_selected_alpha_150x150);
LV_IMG_DECLARE(_needle_alpha_188x36);
LV_IMG_DECLARE(_Fuel_2_50x40);
LV_IMG_DECLARE(_Engine_2_50x40);
LV_IMG_DECLARE(_High_Beam_2_50x40);
LV_IMG_DECLARE(_Battery_2_50x40);
LV_IMG_DECLARE(_speed_limit_alpha_100x100);
LV_IMG_DECLARE(_Menu_item_select_370x50);
LV_IMG_DECLARE(_Selection_box_180x130);
LV_IMG_DECLARE(_Menu_Bottom_line_700x12);
LV_IMG_DECLARE(_Menu_TOP_line_700x5);
LV_IMG_DECLARE(_Menu_vertical_line_24x340);
LV_IMG_DECLARE(_odoback_136x24);
LV_IMG_DECLARE(_odoback_146x29);
LV_IMG_DECLARE(_CLuster__drawing__background_793x327);
LV_IMG_DECLARE(_engine_temperature_30x30);
LV_IMG_DECLARE(_Fuel_0_10x10);
LV_IMG_DECLARE(_odoback_136x24);
LV_IMG_DECLARE(_Gear_circle_134x74);
LV_IMG_DECLARE(_Battery_level_211x20);
LV_IMG_DECLARE(_Battery_0_30x30);
LV_IMG_DECLARE(_NXP_LOGO_113x63);
LV_IMG_DECLARE(_drawing_Guage_1_300x300);
LV_IMG_DECLARE(_Dial_500x388);
LV_IMG_DECLARE(_engine_temp_211x20);
LV_IMG_DECLARE(_drawing_Guage_2_233x223);
LV_IMG_DECLARE(_FUEL_level_197x49);
LV_IMG_DECLARE(_Fuel_0_30x30);
//Dinesh
LV_IMG_DECLARE(_Man_alpha_210x210);
LV_IMG_DECLARE(_women_alpha_210x210);
LV_IMG_DECLARE(_boy_alpha_210x210);
LV_IMG_DECLARE(_girl_alpha_210x210);
LV_IMG_DECLARE(_add_user_alpha_210x210);
//DInesh
LV_IMG_DECLARE(_menu_button_170x120);

#ifdef __cplusplus
}
#endif
#endif

