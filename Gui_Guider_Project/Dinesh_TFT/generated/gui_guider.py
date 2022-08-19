# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=800,h=480)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(800*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 800
disp_drv.ver_res = 480
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.add_flag(lv.obj.FLAG.HIDDEN)


screen = lv.obj()
# create style style_screen_main_main_default
style_screen_main_main_default = lv.style_t()
style_screen_main_main_default.init()
style_screen_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_main_main_default.set_bg_opa(0)

# add style for screen
screen.add_style(style_screen_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_container_Dial = lv.obj(screen)
screen_container_Dial.set_pos(0,0)
screen_container_Dial.set_size(800,480)
screen_ODO_roller_image = lv.img(screen_container_Dial)
screen_ODO_roller_image.set_pos(331,185)
screen_ODO_roller_image.set_size(146,29)
screen_ODO_roller_image.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp751120230.png','rb') as f:
        screen_ODO_roller_image_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp751120230.png')
    sys.exit()

screen_ODO_roller_image_img = lv.img_dsc_t({
  'data_size': len(screen_ODO_roller_image_img_data),
  'header': {'always_zero': 0, 'w': 146, 'h': 29, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_ODO_roller_image_img_data
})

screen_ODO_roller_image.set_src(screen_ODO_roller_image_img)
screen_ODO_roller_image.set_pivot(0,0)
screen_ODO_roller_image.set_angle(0)
# create style style_screen_odo_roller_image_main_main_default
style_screen_odo_roller_image_main_main_default = lv.style_t()
style_screen_odo_roller_image_main_main_default.init()
style_screen_odo_roller_image_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_odo_roller_image_main_main_default.set_img_recolor_opa(0)
style_screen_odo_roller_image_main_main_default.set_img_opa(255)

# add style for screen_ODO_roller_image
screen_ODO_roller_image.add_style(style_screen_odo_roller_image_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_ODO_roller_0 = lv.roller(screen_container_Dial)
screen_ODO_roller_0.set_pos(436,176)
screen_ODO_roller_0.set_options("0\n1\n2\n3\n4\n5\n6\n7\n8\n9", lv.roller.MODE.INFINITE)
screen_ODO_roller_0.set_visible_row_count(1)
try:
	screen_ODO_roller_0.set_style_text_font(lv.font_simsun_16, lv.PART.MAIN|lv.STATE.DEFAULT)
	screen_ODO_roller_0.set_style_text_font(lv.font_simsun_16, lv.PART.MAIN|lv.STATE.FOCUSED)
	screen_ODO_roller_0.set_style_text_font(lv.font_simsun_16, lv.PART.SELECTED|lv.STATE.DEFAULT)
except AttributeError:
	try:
		screen_ODO_roller_0.set_style_text_font(lv.font_montserrat_16, lv.PART.MAIN|lv.STATE.DEFAULT)
		screen_ODO_roller_0.set_style_text_font(lv.font_montserrat_16, lv.PART.MAIN|lv.STATE.FOCUSED)
		screen_ODO_roller_0.set_style_text_font(lv.font_montserrat_16, lv.PART.SELECTED|lv.STATE.DEFAULT)
	except AttributeError:
		screen_ODO_roller_0.set_style_text_font(lv.font_montserrat_16, lv.PART.MAIN|lv.STATE.DEFAULT)
		screen_ODO_roller_0.set_style_text_font(lv.font_montserrat_16, lv.PART.MAIN|lv.STATE.FOCUSED)
		screen_ODO_roller_0.set_style_text_font(lv.font_montserrat_16, lv.PART.SELECTED|lv.STATE.DEFAULT)
# create style style_screen_odo_roller_0_main_main_default
style_screen_odo_roller_0_main_main_default = lv.style_t()
style_screen_odo_roller_0_main_main_default.init()
style_screen_odo_roller_0_main_main_default.set_radius(0)
style_screen_odo_roller_0_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_odo_roller_0_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_odo_roller_0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_odo_roller_0_main_main_default.set_bg_opa(255)
style_screen_odo_roller_0_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_screen_odo_roller_0_main_main_default.set_border_width(0)
style_screen_odo_roller_0_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))

# add style for screen_ODO_roller_0
screen_ODO_roller_0.add_style(style_screen_odo_roller_0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_odo_roller_0_main_selected_default
style_screen_odo_roller_0_main_selected_default = lv.style_t()
style_screen_odo_roller_0_main_selected_default.init()
style_screen_odo_roller_0_main_selected_default.set_bg_color(lv.color_make(0xfa,0xfd,0xff))
style_screen_odo_roller_0_main_selected_default.set_bg_grad_color(lv.color_make(0x6f,0x5e,0xc5))
style_screen_odo_roller_0_main_selected_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_odo_roller_0_main_selected_default.set_bg_opa(142)
style_screen_odo_roller_0_main_selected_default.set_text_color(lv.color_make(0xFF,0xFF,0xFF))

# add style for screen_ODO_roller_0
screen_ODO_roller_0.add_style(style_screen_odo_roller_0_main_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

screen_Background_imgage = lv.img(screen_container_Dial)
screen_Background_imgage.set_pos(0,0)
screen_Background_imgage.set_size(800,480)
screen_Background_imgage.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp885887452.png','rb') as f:
        screen_Background_imgage_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp885887452.png')
    sys.exit()

screen_Background_imgage_img = lv.img_dsc_t({
  'data_size': len(screen_Background_imgage_img_data),
  'header': {'always_zero': 0, 'w': 800, 'h': 480, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_Background_imgage_img_data
})

screen_Background_imgage.set_src(screen_Background_imgage_img)
screen_Background_imgage.set_pivot(0,0)
screen_Background_imgage.set_angle(0)
# create style style_screen_background_imgage_main_main_default
style_screen_background_imgage_main_main_default = lv.style_t()
style_screen_background_imgage_main_main_default.init()
style_screen_background_imgage_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_background_imgage_main_main_default.set_img_recolor_opa(0)
style_screen_background_imgage_main_main_default.set_img_opa(103)

# add style for screen_Background_imgage
screen_Background_imgage.add_style(style_screen_background_imgage_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Time_Label = lv.label(screen_container_Dial)
screen_Time_Label.set_pos(685,12)
screen_Time_Label.set_size(100,32)
screen_Time_Label.set_text("10:28")
screen_Time_Label.set_long_mode(lv.label.LONG.WRAP)
screen_Time_Label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_time_label_main_main_default
style_screen_time_label_main_main_default = lv.style_t()
style_screen_time_label_main_main_default.init()
style_screen_time_label_main_main_default.set_radius(0)
style_screen_time_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_time_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_time_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_time_label_main_main_default.set_bg_opa(0)
style_screen_time_label_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_time_label_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_time_label_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_time_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_time_label_main_main_default.set_text_letter_space(2)
style_screen_time_label_main_main_default.set_pad_left(0)
style_screen_time_label_main_main_default.set_pad_right(0)
style_screen_time_label_main_main_default.set_pad_top(0)
style_screen_time_label_main_main_default.set_pad_bottom(0)

# add style for screen_Time_Label
screen_Time_Label.add_style(style_screen_time_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Date_Label = lv.label(screen_container_Dial)
screen_Date_Label.set_pos(8,9)
screen_Date_Label.set_size(169,45)
screen_Date_Label.set_text("May 24, 2022")
screen_Date_Label.set_long_mode(lv.label.LONG.WRAP)
screen_Date_Label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_date_label_main_main_default
style_screen_date_label_main_main_default = lv.style_t()
style_screen_date_label_main_main_default.init()
style_screen_date_label_main_main_default.set_radius(0)
style_screen_date_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_date_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_date_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_date_label_main_main_default.set_bg_opa(0)
style_screen_date_label_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_date_label_main_main_default.set_text_font(lv.font_montserratMedium_20)
except AttributeError:
    try:
        style_screen_date_label_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_date_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_date_label_main_main_default.set_text_letter_space(2)
style_screen_date_label_main_main_default.set_pad_left(0)
style_screen_date_label_main_main_default.set_pad_right(0)
style_screen_date_label_main_main_default.set_pad_top(0)
style_screen_date_label_main_main_default.set_pad_bottom(0)

# add style for screen_Date_Label
screen_Date_Label.add_style(style_screen_date_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Dial_image = lv.img(screen_container_Dial)
screen_Dial_image.set_size(500,388)
screen_Dial_image.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp681292913.png','rb') as f:
        screen_Dial_image_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp681292913.png')
    sys.exit()

screen_Dial_image_img = lv.img_dsc_t({
  'data_size': len(screen_Dial_image_img_data),
  'header': {'always_zero': 0, 'w': 500, 'h': 388, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_Dial_image_img_data
})

screen_Dial_image.set_src(screen_Dial_image_img)
screen_Dial_image.set_pivot(0,0)
screen_Dial_image.set_angle(0)
# create style style_screen_dial_image_main_main_default
style_screen_dial_image_main_main_default = lv.style_t()
style_screen_dial_image_main_main_default.init()
style_screen_dial_image_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_dial_image_main_main_default.set_img_recolor_opa(0)
style_screen_dial_image_main_main_default.set_img_opa(255)

# add style for screen_Dial_image
screen_Dial_image.add_style(style_screen_dial_image_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Dial_meter = lv.meter(screen_container_Dial)
screen_Dial_meter.set_pos(199,46)
screen_Dial_meter.set_size(400,400)
screen_Dial_meter_scale_1 = screen_Dial_meter.add_scale()
screen_Dial_meter.set_scale_ticks(screen_Dial_meter_scale_1, 6, 1, 20,
    lv.color_make(0xff, 0x00, 0x00))
screen_Dial_meter.set_scale_range(screen_Dial_meter_scale_1, 0, 60, 240, 150)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-404172724.png','rb') as f:
        screen_Dial_meter_scale_1_needleImg_0_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-404172724.png')
    sys.exit()

screen_Dial_meter_scale_1_needleImg_0_img = lv.img_dsc_t({
  'data_size': len(screen_Dial_meter_scale_1_needleImg_0_img_data),
  'header': {'always_zero': 0, 'w': 188, 'h': 36, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_Dial_meter_scale_1_needleImg_0_img_data
})
screen_Dial_meter_scale_1_needleImg_0 = screen_Dial_meter.add_needle_img(screen_Dial_meter_scale_1, screen_Dial_meter_scale_1_needleImg_0_img, 19, 18)
screen_Dial_meter.set_indicator_value(screen_Dial_meter_scale_1_needleImg_0, 0)
# create style style_screen_dial_meter_main_main_default
style_screen_dial_meter_main_main_default = lv.style_t()
style_screen_dial_meter_main_main_default.init()
style_screen_dial_meter_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_dial_meter_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_dial_meter_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_dial_meter_main_main_default.set_bg_opa(0)

# add style for screen_Dial_meter
screen_Dial_meter.add_style(style_screen_dial_meter_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_dial_meter_main_ticks_default
style_screen_dial_meter_main_ticks_default = lv.style_t()
style_screen_dial_meter_main_ticks_default.init()
style_screen_dial_meter_main_ticks_default.set_text_color(lv.color_make(0xff,0x00,0x00))
try:
    style_screen_dial_meter_main_ticks_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_screen_dial_meter_main_ticks_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_dial_meter_main_ticks_default.set_text_font(lv.font_montserrat_16)

# add style for screen_Dial_meter
screen_Dial_meter.add_style(style_screen_dial_meter_main_ticks_default, lv.PART.TICKS|lv.STATE.DEFAULT)

screen_High_Beam_BG = lv.img(screen_container_Dial)
screen_High_Beam_BG.set_pos(24,419)
screen_High_Beam_BG.set_size(50,40)
screen_High_Beam_BG.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1962942131.png','rb') as f:
        screen_High_Beam_BG_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1962942131.png')
    sys.exit()

screen_High_Beam_BG_img = lv.img_dsc_t({
  'data_size': len(screen_High_Beam_BG_img_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_High_Beam_BG_img_data
})

screen_High_Beam_BG.set_src(screen_High_Beam_BG_img)
screen_High_Beam_BG.set_pivot(0,0)
screen_High_Beam_BG.set_angle(0)
# create style style_screen_high_beam_bg_main_main_default
style_screen_high_beam_bg_main_main_default = lv.style_t()
style_screen_high_beam_bg_main_main_default.init()
style_screen_high_beam_bg_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_high_beam_bg_main_main_default.set_img_recolor_opa(0)
style_screen_high_beam_bg_main_main_default.set_img_opa(23)

# add style for screen_High_Beam_BG
screen_High_Beam_BG.add_style(style_screen_high_beam_bg_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_High_Beam = lv.img(screen_container_Dial)
screen_High_Beam.set_pos(24,419)
screen_High_Beam.set_size(50,40)
screen_High_Beam.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1822393521.png','rb') as f:
        screen_High_Beam_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1822393521.png')
    sys.exit()

screen_High_Beam_img = lv.img_dsc_t({
  'data_size': len(screen_High_Beam_img_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_High_Beam_img_data
})

screen_High_Beam.set_src(screen_High_Beam_img)
screen_High_Beam.set_pivot(0,0)
screen_High_Beam.set_angle(0)
# create style style_screen_high_beam_main_main_default
style_screen_high_beam_main_main_default = lv.style_t()
style_screen_high_beam_main_main_default.init()
style_screen_high_beam_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_high_beam_main_main_default.set_img_recolor_opa(0)
style_screen_high_beam_main_main_default.set_img_opa(255)

# add style for screen_High_Beam
screen_High_Beam.add_style(style_screen_high_beam_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Engine_BG = lv.img(screen_container_Dial)
screen_Engine_BG.set_pos(97,419)
screen_Engine_BG.set_size(50,40)
screen_Engine_BG.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp608435311.png','rb') as f:
        screen_Engine_BG_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp608435311.png')
    sys.exit()

screen_Engine_BG_img = lv.img_dsc_t({
  'data_size': len(screen_Engine_BG_img_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_Engine_BG_img_data
})

screen_Engine_BG.set_src(screen_Engine_BG_img)
screen_Engine_BG.set_pivot(0,0)
screen_Engine_BG.set_angle(0)
# create style style_screen_engine_bg_main_main_default
style_screen_engine_bg_main_main_default = lv.style_t()
style_screen_engine_bg_main_main_default.init()
style_screen_engine_bg_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_engine_bg_main_main_default.set_img_recolor_opa(0)
style_screen_engine_bg_main_main_default.set_img_opa(25)

# add style for screen_Engine_BG
screen_Engine_BG.add_style(style_screen_engine_bg_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Engine = lv.img(screen_container_Dial)
screen_Engine.set_pos(97,419)
screen_Engine.set_size(50,40)
screen_Engine.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp467886701.png','rb') as f:
        screen_Engine_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp467886701.png')
    sys.exit()

screen_Engine_img = lv.img_dsc_t({
  'data_size': len(screen_Engine_img_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_Engine_img_data
})

screen_Engine.set_src(screen_Engine_img)
screen_Engine.set_pivot(0,0)
screen_Engine.set_angle(0)
# create style style_screen_engine_main_main_default
style_screen_engine_main_main_default = lv.style_t()
style_screen_engine_main_main_default.init()
style_screen_engine_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_engine_main_main_default.set_img_recolor_opa(0)
style_screen_engine_main_main_default.set_img_opa(255)

# add style for screen_Engine
screen_Engine.add_style(style_screen_engine_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Fuel_BG = lv.img(screen_container_Dial)
screen_Fuel_BG.set_pos(653,419)
screen_Fuel_BG.set_size(50,40)
screen_Fuel_BG.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-43013213.png','rb') as f:
        screen_Fuel_BG_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-43013213.png')
    sys.exit()

screen_Fuel_BG_img = lv.img_dsc_t({
  'data_size': len(screen_Fuel_BG_img_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_Fuel_BG_img_data
})

screen_Fuel_BG.set_src(screen_Fuel_BG_img)
screen_Fuel_BG.set_pivot(0,0)
screen_Fuel_BG.set_angle(0)
# create style style_screen_fuel_bg_main_main_default
style_screen_fuel_bg_main_main_default = lv.style_t()
style_screen_fuel_bg_main_main_default.init()
style_screen_fuel_bg_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_fuel_bg_main_main_default.set_img_recolor_opa(0)
style_screen_fuel_bg_main_main_default.set_img_opa(23)

# add style for screen_Fuel_BG
screen_Fuel_BG.add_style(style_screen_fuel_bg_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Fuel = lv.img(screen_container_Dial)
screen_Fuel.set_pos(653,419)
screen_Fuel.set_size(50,40)
screen_Fuel.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-183561823.png','rb') as f:
        screen_Fuel_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-183561823.png')
    sys.exit()

screen_Fuel_img = lv.img_dsc_t({
  'data_size': len(screen_Fuel_img_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_Fuel_img_data
})

screen_Fuel.set_src(screen_Fuel_img)
screen_Fuel.set_pivot(0,0)
screen_Fuel.set_angle(0)
# create style style_screen_fuel_main_main_default
style_screen_fuel_main_main_default = lv.style_t()
style_screen_fuel_main_main_default.init()
style_screen_fuel_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_fuel_main_main_default.set_img_recolor_opa(0)
style_screen_fuel_main_main_default.set_img_opa(255)

# add style for screen_Fuel
screen_Fuel.add_style(style_screen_fuel_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Battery_BG = lv.img(screen_container_Dial)
screen_Battery_BG.set_pos(726,419)
screen_Battery_BG.set_size(50,40)
screen_Battery_BG.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-5165964.png','rb') as f:
        screen_Battery_BG_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-5165964.png')
    sys.exit()

screen_Battery_BG_img = lv.img_dsc_t({
  'data_size': len(screen_Battery_BG_img_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_Battery_BG_img_data
})

screen_Battery_BG.set_src(screen_Battery_BG_img)
screen_Battery_BG.set_pivot(0,0)
screen_Battery_BG.set_angle(0)
# create style style_screen_battery_bg_main_main_default
style_screen_battery_bg_main_main_default = lv.style_t()
style_screen_battery_bg_main_main_default.init()
style_screen_battery_bg_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_battery_bg_main_main_default.set_img_recolor_opa(0)
style_screen_battery_bg_main_main_default.set_img_opa(25)

# add style for screen_Battery_BG
screen_Battery_BG.add_style(style_screen_battery_bg_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Battery = lv.img(screen_container_Dial)
screen_Battery.set_pos(726,419)
screen_Battery.set_size(50,40)
screen_Battery.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-145714574.png','rb') as f:
        screen_Battery_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-145714574.png')
    sys.exit()

screen_Battery_img = lv.img_dsc_t({
  'data_size': len(screen_Battery_img_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_Battery_img_data
})

screen_Battery.set_src(screen_Battery_img)
screen_Battery.set_pivot(0,0)
screen_Battery.set_angle(0)
# create style style_screen_battery_main_main_default
style_screen_battery_main_main_default = lv.style_t()
style_screen_battery_main_main_default.init()
style_screen_battery_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_battery_main_main_default.set_img_recolor_opa(0)
style_screen_battery_main_main_default.set_img_opa(255)

# add style for screen_Battery
screen_Battery.add_style(style_screen_battery_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Speed = lv.img(screen_container_Dial)
screen_Speed.set_pos(252,281)
screen_Speed.set_size(290,185)
screen_Speed.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1807312403.png','rb') as f:
        screen_Speed_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1807312403.png')
    sys.exit()

screen_Speed_img = lv.img_dsc_t({
  'data_size': len(screen_Speed_img_data),
  'header': {'always_zero': 0, 'w': 290, 'h': 185, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_Speed_img_data
})

screen_Speed.set_src(screen_Speed_img)
screen_Speed.set_pivot(0,0)
screen_Speed.set_angle(0)
# create style style_screen_speed_main_main_default
style_screen_speed_main_main_default = lv.style_t()
style_screen_speed_main_main_default.init()
style_screen_speed_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_speed_main_main_default.set_img_recolor_opa(0)
style_screen_speed_main_main_default.set_img_opa(5)

# add style for screen_Speed
screen_Speed.add_style(style_screen_speed_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Speed_Label = lv.label(screen_container_Dial)
screen_Speed_Label.set_pos(317,332)
screen_Speed_Label.set_size(167,100)
screen_Speed_Label.set_text("50")
screen_Speed_Label.set_long_mode(lv.label.LONG.WRAP)
screen_Speed_Label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_speed_label_main_main_default
style_screen_speed_label_main_main_default = lv.style_t()
style_screen_speed_label_main_main_default.init()
style_screen_speed_label_main_main_default.set_radius(0)
style_screen_speed_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_speed_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_speed_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_speed_label_main_main_default.set_bg_opa(0)
style_screen_speed_label_main_main_default.set_text_color(lv.color_make(0xa8,0xa9,0xad))
try:
    style_screen_speed_label_main_main_default.set_text_font(lv.font_simsun_100)
except AttributeError:
    try:
        style_screen_speed_label_main_main_default.set_text_font(lv.font_montserrat_100)
    except AttributeError:
        style_screen_speed_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_speed_label_main_main_default.set_text_letter_space(2)
style_screen_speed_label_main_main_default.set_pad_left(0)
style_screen_speed_label_main_main_default.set_pad_right(0)
style_screen_speed_label_main_main_default.set_pad_top(0)
style_screen_speed_label_main_main_default.set_pad_bottom(0)

# add style for screen_Speed_Label
screen_Speed_Label.add_style(style_screen_speed_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_Speed_Unit = lv.label(screen_container_Dial)
screen_Speed_Unit.set_pos(353,423)
screen_Speed_Unit.set_size(100,32)
screen_Speed_Unit.set_text("Km/h")
screen_Speed_Unit.set_long_mode(lv.label.LONG.WRAP)
screen_Speed_Unit.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_speed_unit_main_main_default
style_screen_speed_unit_main_main_default = lv.style_t()
style_screen_speed_unit_main_main_default.init()
style_screen_speed_unit_main_main_default.set_radius(0)
style_screen_speed_unit_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_speed_unit_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_speed_unit_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_speed_unit_main_main_default.set_bg_opa(0)
style_screen_speed_unit_main_main_default.set_text_color(lv.color_make(0xa8,0xa9,0xad))
try:
    style_screen_speed_unit_main_main_default.set_text_font(lv.font_simsun_18)
except AttributeError:
    try:
        style_screen_speed_unit_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_screen_speed_unit_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_speed_unit_main_main_default.set_text_letter_space(2)
style_screen_speed_unit_main_main_default.set_pad_left(0)
style_screen_speed_unit_main_main_default.set_pad_right(0)
style_screen_speed_unit_main_main_default.set_pad_top(0)
style_screen_speed_unit_main_main_default.set_pad_bottom(0)

# add style for screen_Speed_Unit
screen_Speed_Unit.add_style(style_screen_speed_unit_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_container_dial_main_main_default
style_screen_container_dial_main_main_default = lv.style_t()
style_screen_container_dial_main_main_default.init()
style_screen_container_dial_main_main_default.set_radius(0)
style_screen_container_dial_main_main_default.set_bg_color(lv.color_make(0x11,0x12,0x12))
style_screen_container_dial_main_main_default.set_bg_grad_color(lv.color_make(0x0b,0x0c,0x0c))
style_screen_container_dial_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_container_dial_main_main_default.set_bg_opa(255)
style_screen_container_dial_main_main_default.set_border_color(lv.color_make(0x11,0x12,0x12))
style_screen_container_dial_main_main_default.set_border_width(0)
style_screen_container_dial_main_main_default.set_border_opa(0)
style_screen_container_dial_main_main_default.set_pad_left(0)
style_screen_container_dial_main_main_default.set_pad_right(0)
style_screen_container_dial_main_main_default.set_pad_top(0)
style_screen_container_dial_main_main_default.set_pad_bottom(0)

# add style for screen_container_Dial
screen_container_Dial.add_style(style_screen_container_dial_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Logo_Screen = lv.obj()
# create style style_logo_screen_main_main_default
style_logo_screen_main_main_default = lv.style_t()
style_logo_screen_main_main_default.init()
style_logo_screen_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_logo_screen_main_main_default.set_bg_opa(0)

# add style for Logo_Screen
Logo_Screen.add_style(style_logo_screen_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Logo_Screen_container_Logo = lv.obj(Logo_Screen)
Logo_Screen_container_Logo.set_pos(0,0)
Logo_Screen_container_Logo.set_size(800,480)
Logo_Screen_img_1 = lv.img(Logo_Screen_container_Logo)
Logo_Screen_img_1.set_pos(203,140)
Logo_Screen_img_1.set_size(400,200)
Logo_Screen_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1701814149.png','rb') as f:
        Logo_Screen_img_1_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1701814149.png')
    sys.exit()

Logo_Screen_img_1_img = lv.img_dsc_t({
  'data_size': len(Logo_Screen_img_1_img_data),
  'header': {'always_zero': 0, 'w': 400, 'h': 200, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': Logo_Screen_img_1_img_data
})

Logo_Screen_img_1.set_src(Logo_Screen_img_1_img)
Logo_Screen_img_1.set_pivot(0,0)
Logo_Screen_img_1.set_angle(0)
# create style style_logo_screen_img_1_main_main_default
style_logo_screen_img_1_main_main_default = lv.style_t()
style_logo_screen_img_1_main_main_default.init()
style_logo_screen_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_logo_screen_img_1_main_main_default.set_img_recolor_opa(0)
style_logo_screen_img_1_main_main_default.set_img_opa(255)

# add style for Logo_Screen_img_1
Logo_Screen_img_1.add_style(style_logo_screen_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_logo_screen_container_logo_main_main_default
style_logo_screen_container_logo_main_main_default = lv.style_t()
style_logo_screen_container_logo_main_main_default.init()
style_logo_screen_container_logo_main_main_default.set_radius(0)
style_logo_screen_container_logo_main_main_default.set_bg_color(lv.color_make(0x11,0x12,0x12))
style_logo_screen_container_logo_main_main_default.set_bg_grad_color(lv.color_make(0x0b,0x0c,0x0c))
style_logo_screen_container_logo_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_logo_screen_container_logo_main_main_default.set_bg_opa(255)
style_logo_screen_container_logo_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_logo_screen_container_logo_main_main_default.set_border_width(0)
style_logo_screen_container_logo_main_main_default.set_border_opa(0)
style_logo_screen_container_logo_main_main_default.set_pad_left(0)
style_logo_screen_container_logo_main_main_default.set_pad_right(0)
style_logo_screen_container_logo_main_main_default.set_pad_top(0)
style_logo_screen_container_logo_main_main_default.set_pad_bottom(0)

# add style for Logo_Screen_container_Logo
Logo_Screen_container_Logo.add_style(style_logo_screen_container_logo_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Rider_screen = lv.obj()
# create style style_rider_screen_main_main_default
style_rider_screen_main_main_default = lv.style_t()
style_rider_screen_main_main_default.init()
style_rider_screen_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_rider_screen_main_main_default.set_bg_opa(0)

# add style for Rider_screen
Rider_screen.add_style(style_rider_screen_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Rider_screen_container_rider = lv.obj(Rider_screen)
Rider_screen_container_rider.set_pos(0,0)
Rider_screen_container_rider.set_size(800,480)
Rider_screen_rider_bg_image = lv.img(Rider_screen_container_rider)
Rider_screen_rider_bg_image.set_pos(53,9)
Rider_screen_rider_bg_image.set_size(700,126)
Rider_screen_rider_bg_image.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1662160979.png','rb') as f:
        Rider_screen_rider_bg_image_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1662160979.png')
    sys.exit()

Rider_screen_rider_bg_image_img = lv.img_dsc_t({
  'data_size': len(Rider_screen_rider_bg_image_img_data),
  'header': {'always_zero': 0, 'w': 700, 'h': 126, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': Rider_screen_rider_bg_image_img_data
})

Rider_screen_rider_bg_image.set_src(Rider_screen_rider_bg_image_img)
Rider_screen_rider_bg_image.set_pivot(0,0)
Rider_screen_rider_bg_image.set_angle(0)
# create style style_rider_screen_rider_bg_image_main_main_default
style_rider_screen_rider_bg_image_main_main_default = lv.style_t()
style_rider_screen_rider_bg_image_main_main_default.init()
style_rider_screen_rider_bg_image_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_rider_screen_rider_bg_image_main_main_default.set_img_recolor_opa(0)
style_rider_screen_rider_bg_image_main_main_default.set_img_opa(30)

# add style for Rider_screen_rider_bg_image
Rider_screen_rider_bg_image.add_style(style_rider_screen_rider_bg_image_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Rider_screen_Rider_label = lv.label(Rider_screen_container_rider)
Rider_screen_Rider_label.set_pos(262,33)
Rider_screen_Rider_label.set_size(280,32)
Rider_screen_Rider_label.set_text("Who is riding today ?")
Rider_screen_Rider_label.set_long_mode(lv.label.LONG.WRAP)
Rider_screen_Rider_label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_rider_screen_rider_label_main_main_default
style_rider_screen_rider_label_main_main_default = lv.style_t()
style_rider_screen_rider_label_main_main_default.init()
style_rider_screen_rider_label_main_main_default.set_radius(0)
style_rider_screen_rider_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_rider_screen_rider_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_rider_screen_rider_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_rider_screen_rider_label_main_main_default.set_bg_opa(0)
style_rider_screen_rider_label_main_main_default.set_text_color(lv.color_make(0x8c,0x78,0x78))
try:
    style_rider_screen_rider_label_main_main_default.set_text_font(lv.font_montserratMedium_22)
except AttributeError:
    try:
        style_rider_screen_rider_label_main_main_default.set_text_font(lv.font_montserrat_22)
    except AttributeError:
        style_rider_screen_rider_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_rider_screen_rider_label_main_main_default.set_text_letter_space(2)
style_rider_screen_rider_label_main_main_default.set_pad_left(0)
style_rider_screen_rider_label_main_main_default.set_pad_right(0)
style_rider_screen_rider_label_main_main_default.set_pad_top(0)
style_rider_screen_rider_label_main_main_default.set_pad_bottom(0)

# add style for Rider_screen_Rider_label
Rider_screen_Rider_label.add_style(style_rider_screen_rider_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Rider_screen_Rider_selection_1 = lv.img(Rider_screen_container_rider)
Rider_screen_Rider_selection_1.set_pos(52,150)
Rider_screen_Rider_selection_1.set_size(226,224)
Rider_screen_Rider_selection_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-560592909.png','rb') as f:
        Rider_screen_Rider_selection_1_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-560592909.png')
    sys.exit()

Rider_screen_Rider_selection_1_img = lv.img_dsc_t({
  'data_size': len(Rider_screen_Rider_selection_1_img_data),
  'header': {'always_zero': 0, 'w': 226, 'h': 224, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': Rider_screen_Rider_selection_1_img_data
})

Rider_screen_Rider_selection_1.set_src(Rider_screen_Rider_selection_1_img)
Rider_screen_Rider_selection_1.set_pivot(0,0)
Rider_screen_Rider_selection_1.set_angle(0)
# create style style_rider_screen_rider_selection_1_main_main_default
style_rider_screen_rider_selection_1_main_main_default = lv.style_t()
style_rider_screen_rider_selection_1_main_main_default.init()
style_rider_screen_rider_selection_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_rider_screen_rider_selection_1_main_main_default.set_img_recolor_opa(0)
style_rider_screen_rider_selection_1_main_main_default.set_img_opa(255)

# add style for Rider_screen_Rider_selection_1
Rider_screen_Rider_selection_1.add_style(style_rider_screen_rider_selection_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Rider_screen_Rider_selection_2 = lv.img(Rider_screen_container_rider)
Rider_screen_Rider_selection_2.set_pos(273,150)
Rider_screen_Rider_selection_2.set_size(226,224)
Rider_screen_Rider_selection_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-560592909.png','rb') as f:
        Rider_screen_Rider_selection_2_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-560592909.png')
    sys.exit()

Rider_screen_Rider_selection_2_img = lv.img_dsc_t({
  'data_size': len(Rider_screen_Rider_selection_2_img_data),
  'header': {'always_zero': 0, 'w': 226, 'h': 224, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': Rider_screen_Rider_selection_2_img_data
})

Rider_screen_Rider_selection_2.set_src(Rider_screen_Rider_selection_2_img)
Rider_screen_Rider_selection_2.set_pivot(0,0)
Rider_screen_Rider_selection_2.set_angle(0)
# create style style_rider_screen_rider_selection_2_main_main_default
style_rider_screen_rider_selection_2_main_main_default = lv.style_t()
style_rider_screen_rider_selection_2_main_main_default.init()
style_rider_screen_rider_selection_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_rider_screen_rider_selection_2_main_main_default.set_img_recolor_opa(0)
style_rider_screen_rider_selection_2_main_main_default.set_img_opa(255)

# add style for Rider_screen_Rider_selection_2
Rider_screen_Rider_selection_2.add_style(style_rider_screen_rider_selection_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Rider_screen_Rider_selection_3 = lv.img(Rider_screen_container_rider)
Rider_screen_Rider_selection_3.set_pos(494,150)
Rider_screen_Rider_selection_3.set_size(226,224)
Rider_screen_Rider_selection_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-560592909.png','rb') as f:
        Rider_screen_Rider_selection_3_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-560592909.png')
    sys.exit()

Rider_screen_Rider_selection_3_img = lv.img_dsc_t({
  'data_size': len(Rider_screen_Rider_selection_3_img_data),
  'header': {'always_zero': 0, 'w': 226, 'h': 224, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': Rider_screen_Rider_selection_3_img_data
})

Rider_screen_Rider_selection_3.set_src(Rider_screen_Rider_selection_3_img)
Rider_screen_Rider_selection_3.set_pivot(0,0)
Rider_screen_Rider_selection_3.set_angle(0)
# create style style_rider_screen_rider_selection_3_main_main_default
style_rider_screen_rider_selection_3_main_main_default = lv.style_t()
style_rider_screen_rider_selection_3_main_main_default.init()
style_rider_screen_rider_selection_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_rider_screen_rider_selection_3_main_main_default.set_img_recolor_opa(0)
style_rider_screen_rider_selection_3_main_main_default.set_img_opa(255)

# add style for Rider_screen_Rider_selection_3
Rider_screen_Rider_selection_3.add_style(style_rider_screen_rider_selection_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_rider_screen_container_rider_main_main_default
style_rider_screen_container_rider_main_main_default = lv.style_t()
style_rider_screen_container_rider_main_main_default.init()
style_rider_screen_container_rider_main_main_default.set_radius(0)
style_rider_screen_container_rider_main_main_default.set_bg_color(lv.color_make(0x11,0x12,0x12))
style_rider_screen_container_rider_main_main_default.set_bg_grad_color(lv.color_make(0x0b,0x0c,0x0c))
style_rider_screen_container_rider_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_rider_screen_container_rider_main_main_default.set_bg_opa(255)
style_rider_screen_container_rider_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_rider_screen_container_rider_main_main_default.set_border_width(0)
style_rider_screen_container_rider_main_main_default.set_border_opa(0)
style_rider_screen_container_rider_main_main_default.set_pad_left(0)
style_rider_screen_container_rider_main_main_default.set_pad_right(0)
style_rider_screen_container_rider_main_main_default.set_pad_top(0)
style_rider_screen_container_rider_main_main_default.set_pad_bottom(0)

# add style for Rider_screen_container_rider
Rider_screen_container_rider.add_style(style_rider_screen_container_rider_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Rider_screen_img_1 = lv.img(Rider_screen)
Rider_screen_img_1.set_pos(57,86)
Rider_screen_img_1.set_size(170,120)
Rider_screen_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1481046324.png','rb') as f:
        Rider_screen_img_1_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1481046324.png')
    sys.exit()

Rider_screen_img_1_img = lv.img_dsc_t({
  'data_size': len(Rider_screen_img_1_img_data),
  'header': {'always_zero': 0, 'w': 170, 'h': 120, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': Rider_screen_img_1_img_data
})

Rider_screen_img_1.set_src(Rider_screen_img_1_img)
Rider_screen_img_1.set_pivot(0,0)
Rider_screen_img_1.set_angle(0)
# create style style_rider_screen_img_1_main_main_default
style_rider_screen_img_1_main_main_default = lv.style_t()
style_rider_screen_img_1_main_main_default.init()
style_rider_screen_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_rider_screen_img_1_main_main_default.set_img_recolor_opa(0)
style_rider_screen_img_1_main_main_default.set_img_opa(255)

# add style for Rider_screen_img_1
Rider_screen_img_1.add_style(style_rider_screen_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

rider_selected_screen = lv.obj()
# create style style_rider_selected_screen_main_main_default
style_rider_selected_screen_main_main_default = lv.style_t()
style_rider_selected_screen_main_main_default.init()
style_rider_selected_screen_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_rider_selected_screen_main_main_default.set_bg_opa(0)

# add style for rider_selected_screen
rider_selected_screen.add_style(style_rider_selected_screen_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

rider_selected_screen_container_rider_selected = lv.obj(rider_selected_screen)
rider_selected_screen_container_rider_selected.set_pos(0,0)
rider_selected_screen_container_rider_selected.set_size(800,480)
rider_selected_screen_Rider_selec_icon = lv.imgbtn(rider_selected_screen_container_rider_selected)
rider_selected_screen_Rider_selec_icon.set_pos(40,170)
rider_selected_screen_Rider_selec_icon.set_size(150,150)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp884690719.png','rb') as f:
        rider_selected_screen_Rider_selec_icon_imgReleased_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp884690719.png')
    sys.exit()

rider_selected_screen_Rider_selec_icon_imgReleased = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Rider_selec_icon_imgReleased_data),
  'header': {'always_zero': 0, 'w': 150, 'h': 150, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Rider_selec_icon_imgReleased_data
})
rider_selected_screen_Rider_selec_icon.set_src(lv.imgbtn.STATE.RELEASED, rider_selected_screen_Rider_selec_icon_imgReleased, None, None)

try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp884690719.png','rb') as f:
        rider_selected_screen_Rider_selec_icon_imgPressed_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp884690719.png')
    sys.exit()

rider_selected_screen_Rider_selec_icon_imgPressed = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Rider_selec_icon_imgPressed_data),
  'header': {'always_zero': 0, 'w': 150, 'h': 150, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Rider_selec_icon_imgPressed_data
})
rider_selected_screen_Rider_selec_icon.set_src(lv.imgbtn.STATE.PRESSED, rider_selected_screen_Rider_selec_icon_imgPressed, None, None)


try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp884690719.png','rb') as f:
        rider_selected_screen_Rider_selec_icon_imgCheckedReleased_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp884690719.png')
    sys.exit()

rider_selected_screen_Rider_selec_icon_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Rider_selec_icon_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 150, 'h': 150, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Rider_selec_icon_imgCheckedReleased_data
})
rider_selected_screen_Rider_selec_icon.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, rider_selected_screen_Rider_selec_icon_imgCheckedReleased, None, None)

try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp884690719.png','rb') as f:
        rider_selected_screen_Rider_selec_icon_imgCheckedPressed_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp884690719.png')
    sys.exit()

rider_selected_screen_Rider_selec_icon_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Rider_selec_icon_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 150, 'h': 150, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Rider_selec_icon_imgCheckedPressed_data
})
rider_selected_screen_Rider_selec_icon.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, rider_selected_screen_Rider_selec_icon_imgCheckedPressed, None, None)

# create style style_rider_selected_screen_rider_selec_icon_main_main_default
style_rider_selected_screen_rider_selec_icon_main_main_default = lv.style_t()
style_rider_selected_screen_rider_selec_icon_main_main_default.init()
style_rider_selected_screen_rider_selec_icon_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_rider_selected_screen_rider_selec_icon_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_rider_selected_screen_rider_selec_icon_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_rider_selected_screen_rider_selec_icon_main_main_default.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_rider_selec_icon_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_rider_selected_screen_rider_selec_icon_main_main_default.set_img_recolor_opa(0)
style_rider_selected_screen_rider_selec_icon_main_main_default.set_img_opa(255)

# add style for rider_selected_screen_Rider_selec_icon
rider_selected_screen_Rider_selec_icon.add_style(style_rider_selected_screen_rider_selec_icon_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_rider_selected_screen_rider_selec_icon_main_main_pressed
style_rider_selected_screen_rider_selec_icon_main_main_pressed = lv.style_t()
style_rider_selected_screen_rider_selec_icon_main_main_pressed.init()
style_rider_selected_screen_rider_selec_icon_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_rider_selected_screen_rider_selec_icon_main_main_pressed.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_rider_selected_screen_rider_selec_icon_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_rider_selected_screen_rider_selec_icon_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_rider_selec_icon_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_rider_selected_screen_rider_selec_icon_main_main_pressed.set_img_recolor_opa(0)

# add style for rider_selected_screen_Rider_selec_icon
rider_selected_screen_Rider_selec_icon.add_style(style_rider_selected_screen_rider_selec_icon_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_rider_selected_screen_rider_selec_icon_main_main_checked
style_rider_selected_screen_rider_selec_icon_main_main_checked = lv.style_t()
style_rider_selected_screen_rider_selec_icon_main_main_checked.init()
style_rider_selected_screen_rider_selec_icon_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_rider_selected_screen_rider_selec_icon_main_main_checked.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_rider_selected_screen_rider_selec_icon_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_rider_selected_screen_rider_selec_icon_main_main_checked.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_rider_selec_icon_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_rider_selected_screen_rider_selec_icon_main_main_checked.set_img_recolor_opa(0)

# add style for rider_selected_screen_Rider_selec_icon
rider_selected_screen_Rider_selec_icon.add_style(style_rider_selected_screen_rider_selec_icon_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

rider_selected_screen_Area_limit = lv.imgbtn(rider_selected_screen_container_rider_selected)
rider_selected_screen_Area_limit.set_pos(343,66)
rider_selected_screen_Area_limit.set_size(100,100)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-802309108.png','rb') as f:
        rider_selected_screen_Area_limit_imgReleased_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-802309108.png')
    sys.exit()

rider_selected_screen_Area_limit_imgReleased = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Area_limit_imgReleased_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Area_limit_imgReleased_data
})
rider_selected_screen_Area_limit.set_src(lv.imgbtn.STATE.RELEASED, rider_selected_screen_Area_limit_imgReleased, None, None)

try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-802309108.png','rb') as f:
        rider_selected_screen_Area_limit_imgPressed_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-802309108.png')
    sys.exit()

rider_selected_screen_Area_limit_imgPressed = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Area_limit_imgPressed_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Area_limit_imgPressed_data
})
rider_selected_screen_Area_limit.set_src(lv.imgbtn.STATE.PRESSED, rider_selected_screen_Area_limit_imgPressed, None, None)


try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-802309108.png','rb') as f:
        rider_selected_screen_Area_limit_imgCheckedReleased_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-802309108.png')
    sys.exit()

rider_selected_screen_Area_limit_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Area_limit_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Area_limit_imgCheckedReleased_data
})
rider_selected_screen_Area_limit.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, rider_selected_screen_Area_limit_imgCheckedReleased, None, None)

try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-802309108.png','rb') as f:
        rider_selected_screen_Area_limit_imgCheckedPressed_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-802309108.png')
    sys.exit()

rider_selected_screen_Area_limit_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Area_limit_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Area_limit_imgCheckedPressed_data
})
rider_selected_screen_Area_limit.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, rider_selected_screen_Area_limit_imgCheckedPressed, None, None)

# create style style_rider_selected_screen_area_limit_main_main_default
style_rider_selected_screen_area_limit_main_main_default = lv.style_t()
style_rider_selected_screen_area_limit_main_main_default.init()
style_rider_selected_screen_area_limit_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_rider_selected_screen_area_limit_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_rider_selected_screen_area_limit_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_rider_selected_screen_area_limit_main_main_default.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_area_limit_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_rider_selected_screen_area_limit_main_main_default.set_img_recolor_opa(0)
style_rider_selected_screen_area_limit_main_main_default.set_img_opa(255)

# add style for rider_selected_screen_Area_limit
rider_selected_screen_Area_limit.add_style(style_rider_selected_screen_area_limit_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_rider_selected_screen_area_limit_main_main_pressed
style_rider_selected_screen_area_limit_main_main_pressed = lv.style_t()
style_rider_selected_screen_area_limit_main_main_pressed.init()
style_rider_selected_screen_area_limit_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_rider_selected_screen_area_limit_main_main_pressed.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_rider_selected_screen_area_limit_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_rider_selected_screen_area_limit_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_area_limit_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_rider_selected_screen_area_limit_main_main_pressed.set_img_recolor_opa(0)

# add style for rider_selected_screen_Area_limit
rider_selected_screen_Area_limit.add_style(style_rider_selected_screen_area_limit_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_rider_selected_screen_area_limit_main_main_checked
style_rider_selected_screen_area_limit_main_main_checked = lv.style_t()
style_rider_selected_screen_area_limit_main_main_checked.init()
style_rider_selected_screen_area_limit_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_rider_selected_screen_area_limit_main_main_checked.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_rider_selected_screen_area_limit_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_rider_selected_screen_area_limit_main_main_checked.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_area_limit_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_rider_selected_screen_area_limit_main_main_checked.set_img_recolor_opa(0)

# add style for rider_selected_screen_Area_limit
rider_selected_screen_Area_limit.add_style(style_rider_selected_screen_area_limit_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

rider_selected_screen_Time_fence = lv.imgbtn(rider_selected_screen_container_rider_selected)
rider_selected_screen_Time_fence.set_pos(597,67)
rider_selected_screen_Time_fence.set_size(100,100)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1545575234.png','rb') as f:
        rider_selected_screen_Time_fence_imgReleased_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1545575234.png')
    sys.exit()

rider_selected_screen_Time_fence_imgReleased = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Time_fence_imgReleased_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Time_fence_imgReleased_data
})
rider_selected_screen_Time_fence.set_src(lv.imgbtn.STATE.RELEASED, rider_selected_screen_Time_fence_imgReleased, None, None)

try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1545575234.png','rb') as f:
        rider_selected_screen_Time_fence_imgPressed_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1545575234.png')
    sys.exit()

rider_selected_screen_Time_fence_imgPressed = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Time_fence_imgPressed_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Time_fence_imgPressed_data
})
rider_selected_screen_Time_fence.set_src(lv.imgbtn.STATE.PRESSED, rider_selected_screen_Time_fence_imgPressed, None, None)


try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1545575234.png','rb') as f:
        rider_selected_screen_Time_fence_imgCheckedReleased_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1545575234.png')
    sys.exit()

rider_selected_screen_Time_fence_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Time_fence_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Time_fence_imgCheckedReleased_data
})
rider_selected_screen_Time_fence.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, rider_selected_screen_Time_fence_imgCheckedReleased, None, None)

try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1545575234.png','rb') as f:
        rider_selected_screen_Time_fence_imgCheckedPressed_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1545575234.png')
    sys.exit()

rider_selected_screen_Time_fence_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Time_fence_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Time_fence_imgCheckedPressed_data
})
rider_selected_screen_Time_fence.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, rider_selected_screen_Time_fence_imgCheckedPressed, None, None)

# create style style_rider_selected_screen_time_fence_main_main_default
style_rider_selected_screen_time_fence_main_main_default = lv.style_t()
style_rider_selected_screen_time_fence_main_main_default.init()
style_rider_selected_screen_time_fence_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_rider_selected_screen_time_fence_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_rider_selected_screen_time_fence_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_rider_selected_screen_time_fence_main_main_default.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_time_fence_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_rider_selected_screen_time_fence_main_main_default.set_img_recolor_opa(0)
style_rider_selected_screen_time_fence_main_main_default.set_img_opa(255)

# add style for rider_selected_screen_Time_fence
rider_selected_screen_Time_fence.add_style(style_rider_selected_screen_time_fence_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_rider_selected_screen_time_fence_main_main_pressed
style_rider_selected_screen_time_fence_main_main_pressed = lv.style_t()
style_rider_selected_screen_time_fence_main_main_pressed.init()
style_rider_selected_screen_time_fence_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_rider_selected_screen_time_fence_main_main_pressed.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_rider_selected_screen_time_fence_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_rider_selected_screen_time_fence_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_time_fence_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_rider_selected_screen_time_fence_main_main_pressed.set_img_recolor_opa(0)

# add style for rider_selected_screen_Time_fence
rider_selected_screen_Time_fence.add_style(style_rider_selected_screen_time_fence_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_rider_selected_screen_time_fence_main_main_checked
style_rider_selected_screen_time_fence_main_main_checked = lv.style_t()
style_rider_selected_screen_time_fence_main_main_checked.init()
style_rider_selected_screen_time_fence_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_rider_selected_screen_time_fence_main_main_checked.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_rider_selected_screen_time_fence_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_rider_selected_screen_time_fence_main_main_checked.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_time_fence_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_rider_selected_screen_time_fence_main_main_checked.set_img_recolor_opa(0)

# add style for rider_selected_screen_Time_fence
rider_selected_screen_Time_fence.add_style(style_rider_selected_screen_time_fence_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

rider_selected_screen_Speed_limit = lv.imgbtn(rider_selected_screen_container_rider_selected)
rider_selected_screen_Speed_limit.set_pos(343,262)
rider_selected_screen_Speed_limit.set_size(100,100)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp651975392.png','rb') as f:
        rider_selected_screen_Speed_limit_imgReleased_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp651975392.png')
    sys.exit()

rider_selected_screen_Speed_limit_imgReleased = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Speed_limit_imgReleased_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Speed_limit_imgReleased_data
})
rider_selected_screen_Speed_limit.set_src(lv.imgbtn.STATE.RELEASED, rider_selected_screen_Speed_limit_imgReleased, None, None)

try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp651975392.png','rb') as f:
        rider_selected_screen_Speed_limit_imgPressed_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp651975392.png')
    sys.exit()

rider_selected_screen_Speed_limit_imgPressed = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Speed_limit_imgPressed_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Speed_limit_imgPressed_data
})
rider_selected_screen_Speed_limit.set_src(lv.imgbtn.STATE.PRESSED, rider_selected_screen_Speed_limit_imgPressed, None, None)


try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp651975392.png','rb') as f:
        rider_selected_screen_Speed_limit_imgCheckedReleased_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp651975392.png')
    sys.exit()

rider_selected_screen_Speed_limit_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Speed_limit_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Speed_limit_imgCheckedReleased_data
})
rider_selected_screen_Speed_limit.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, rider_selected_screen_Speed_limit_imgCheckedReleased, None, None)

try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp651975392.png','rb') as f:
        rider_selected_screen_Speed_limit_imgCheckedPressed_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp651975392.png')
    sys.exit()

rider_selected_screen_Speed_limit_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Speed_limit_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Speed_limit_imgCheckedPressed_data
})
rider_selected_screen_Speed_limit.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, rider_selected_screen_Speed_limit_imgCheckedPressed, None, None)

rider_selected_screen_Speed_limit.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_rider_selected_screen_speed_limit_main_main_default
style_rider_selected_screen_speed_limit_main_main_default = lv.style_t()
style_rider_selected_screen_speed_limit_main_main_default.init()
style_rider_selected_screen_speed_limit_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_rider_selected_screen_speed_limit_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_rider_selected_screen_speed_limit_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_rider_selected_screen_speed_limit_main_main_default.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_speed_limit_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_rider_selected_screen_speed_limit_main_main_default.set_img_recolor_opa(0)
style_rider_selected_screen_speed_limit_main_main_default.set_img_opa(255)

# add style for rider_selected_screen_Speed_limit
rider_selected_screen_Speed_limit.add_style(style_rider_selected_screen_speed_limit_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_rider_selected_screen_speed_limit_main_main_pressed
style_rider_selected_screen_speed_limit_main_main_pressed = lv.style_t()
style_rider_selected_screen_speed_limit_main_main_pressed.init()
style_rider_selected_screen_speed_limit_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_rider_selected_screen_speed_limit_main_main_pressed.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_rider_selected_screen_speed_limit_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_rider_selected_screen_speed_limit_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_speed_limit_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_rider_selected_screen_speed_limit_main_main_pressed.set_img_recolor_opa(0)

# add style for rider_selected_screen_Speed_limit
rider_selected_screen_Speed_limit.add_style(style_rider_selected_screen_speed_limit_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_rider_selected_screen_speed_limit_main_main_checked
style_rider_selected_screen_speed_limit_main_main_checked = lv.style_t()
style_rider_selected_screen_speed_limit_main_main_checked.init()
style_rider_selected_screen_speed_limit_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_rider_selected_screen_speed_limit_main_main_checked.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_rider_selected_screen_speed_limit_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_rider_selected_screen_speed_limit_main_main_checked.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_speed_limit_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_rider_selected_screen_speed_limit_main_main_checked.set_img_recolor_opa(0)

# add style for rider_selected_screen_Speed_limit
rider_selected_screen_Speed_limit.add_style(style_rider_selected_screen_speed_limit_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

rider_selected_screen_Mode_restriction = lv.imgbtn(rider_selected_screen_container_rider_selected)
rider_selected_screen_Mode_restriction.set_pos(597,268)
rider_selected_screen_Mode_restriction.set_size(100,100)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-379230061.png','rb') as f:
        rider_selected_screen_Mode_restriction_imgReleased_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-379230061.png')
    sys.exit()

rider_selected_screen_Mode_restriction_imgReleased = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Mode_restriction_imgReleased_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Mode_restriction_imgReleased_data
})
rider_selected_screen_Mode_restriction.set_src(lv.imgbtn.STATE.RELEASED, rider_selected_screen_Mode_restriction_imgReleased, None, None)

try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-379230061.png','rb') as f:
        rider_selected_screen_Mode_restriction_imgPressed_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-379230061.png')
    sys.exit()

rider_selected_screen_Mode_restriction_imgPressed = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Mode_restriction_imgPressed_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Mode_restriction_imgPressed_data
})
rider_selected_screen_Mode_restriction.set_src(lv.imgbtn.STATE.PRESSED, rider_selected_screen_Mode_restriction_imgPressed, None, None)


try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-379230061.png','rb') as f:
        rider_selected_screen_Mode_restriction_imgCheckedReleased_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-379230061.png')
    sys.exit()

rider_selected_screen_Mode_restriction_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Mode_restriction_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Mode_restriction_imgCheckedReleased_data
})
rider_selected_screen_Mode_restriction.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, rider_selected_screen_Mode_restriction_imgCheckedReleased, None, None)

try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-379230061.png','rb') as f:
        rider_selected_screen_Mode_restriction_imgCheckedPressed_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-379230061.png')
    sys.exit()

rider_selected_screen_Mode_restriction_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_Mode_restriction_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 100, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_Mode_restriction_imgCheckedPressed_data
})
rider_selected_screen_Mode_restriction.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, rider_selected_screen_Mode_restriction_imgCheckedPressed, None, None)

rider_selected_screen_Mode_restriction.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_rider_selected_screen_mode_restriction_main_main_default
style_rider_selected_screen_mode_restriction_main_main_default = lv.style_t()
style_rider_selected_screen_mode_restriction_main_main_default.init()
style_rider_selected_screen_mode_restriction_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_rider_selected_screen_mode_restriction_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_rider_selected_screen_mode_restriction_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_rider_selected_screen_mode_restriction_main_main_default.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_mode_restriction_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_rider_selected_screen_mode_restriction_main_main_default.set_img_recolor_opa(0)
style_rider_selected_screen_mode_restriction_main_main_default.set_img_opa(255)

# add style for rider_selected_screen_Mode_restriction
rider_selected_screen_Mode_restriction.add_style(style_rider_selected_screen_mode_restriction_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_rider_selected_screen_mode_restriction_main_main_pressed
style_rider_selected_screen_mode_restriction_main_main_pressed = lv.style_t()
style_rider_selected_screen_mode_restriction_main_main_pressed.init()
style_rider_selected_screen_mode_restriction_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_rider_selected_screen_mode_restriction_main_main_pressed.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_rider_selected_screen_mode_restriction_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_rider_selected_screen_mode_restriction_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_mode_restriction_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_rider_selected_screen_mode_restriction_main_main_pressed.set_img_recolor_opa(0)

# add style for rider_selected_screen_Mode_restriction
rider_selected_screen_Mode_restriction.add_style(style_rider_selected_screen_mode_restriction_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_rider_selected_screen_mode_restriction_main_main_checked
style_rider_selected_screen_mode_restriction_main_main_checked = lv.style_t()
style_rider_selected_screen_mode_restriction_main_main_checked.init()
style_rider_selected_screen_mode_restriction_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_rider_selected_screen_mode_restriction_main_main_checked.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_rider_selected_screen_mode_restriction_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_rider_selected_screen_mode_restriction_main_main_checked.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_mode_restriction_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_rider_selected_screen_mode_restriction_main_main_checked.set_img_recolor_opa(0)

# add style for rider_selected_screen_Mode_restriction
rider_selected_screen_Mode_restriction.add_style(style_rider_selected_screen_mode_restriction_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

rider_selected_screen_shield_select_icon = lv.imgbtn(rider_selected_screen_container_rider_selected)
rider_selected_screen_shield_select_icon.set_pos(95,250)
rider_selected_screen_shield_select_icon.set_size(40,40)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1769652542.png','rb') as f:
        rider_selected_screen_shield_select_icon_imgReleased_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1769652542.png')
    sys.exit()

rider_selected_screen_shield_select_icon_imgReleased = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_shield_select_icon_imgReleased_data),
  'header': {'always_zero': 0, 'w': 40, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_shield_select_icon_imgReleased_data
})
rider_selected_screen_shield_select_icon.set_src(lv.imgbtn.STATE.RELEASED, rider_selected_screen_shield_select_icon_imgReleased, None, None)

try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1769652542.png','rb') as f:
        rider_selected_screen_shield_select_icon_imgPressed_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1769652542.png')
    sys.exit()

rider_selected_screen_shield_select_icon_imgPressed = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_shield_select_icon_imgPressed_data),
  'header': {'always_zero': 0, 'w': 40, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_shield_select_icon_imgPressed_data
})
rider_selected_screen_shield_select_icon.set_src(lv.imgbtn.STATE.PRESSED, rider_selected_screen_shield_select_icon_imgPressed, None, None)


try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1769652542.png','rb') as f:
        rider_selected_screen_shield_select_icon_imgCheckedReleased_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1769652542.png')
    sys.exit()

rider_selected_screen_shield_select_icon_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_shield_select_icon_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 40, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_shield_select_icon_imgCheckedReleased_data
})
rider_selected_screen_shield_select_icon.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, rider_selected_screen_shield_select_icon_imgCheckedReleased, None, None)

try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1769652542.png','rb') as f:
        rider_selected_screen_shield_select_icon_imgCheckedPressed_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1769652542.png')
    sys.exit()

rider_selected_screen_shield_select_icon_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(rider_selected_screen_shield_select_icon_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 40, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': rider_selected_screen_shield_select_icon_imgCheckedPressed_data
})
rider_selected_screen_shield_select_icon.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, rider_selected_screen_shield_select_icon_imgCheckedPressed, None, None)

rider_selected_screen_shield_select_icon.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_rider_selected_screen_shield_select_icon_main_main_default
style_rider_selected_screen_shield_select_icon_main_main_default = lv.style_t()
style_rider_selected_screen_shield_select_icon_main_main_default.init()
style_rider_selected_screen_shield_select_icon_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_rider_selected_screen_shield_select_icon_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_rider_selected_screen_shield_select_icon_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_rider_selected_screen_shield_select_icon_main_main_default.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_shield_select_icon_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_rider_selected_screen_shield_select_icon_main_main_default.set_img_recolor_opa(0)
style_rider_selected_screen_shield_select_icon_main_main_default.set_img_opa(255)

# add style for rider_selected_screen_shield_select_icon
rider_selected_screen_shield_select_icon.add_style(style_rider_selected_screen_shield_select_icon_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_rider_selected_screen_shield_select_icon_main_main_pressed
style_rider_selected_screen_shield_select_icon_main_main_pressed = lv.style_t()
style_rider_selected_screen_shield_select_icon_main_main_pressed.init()
style_rider_selected_screen_shield_select_icon_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_rider_selected_screen_shield_select_icon_main_main_pressed.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_rider_selected_screen_shield_select_icon_main_main_pressed.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_rider_selected_screen_shield_select_icon_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_shield_select_icon_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_rider_selected_screen_shield_select_icon_main_main_pressed.set_img_recolor_opa(0)

# add style for rider_selected_screen_shield_select_icon
rider_selected_screen_shield_select_icon.add_style(style_rider_selected_screen_shield_select_icon_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_rider_selected_screen_shield_select_icon_main_main_checked
style_rider_selected_screen_shield_select_icon_main_main_checked = lv.style_t()
style_rider_selected_screen_shield_select_icon_main_main_checked.init()
style_rider_selected_screen_shield_select_icon_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_rider_selected_screen_shield_select_icon_main_main_checked.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_rider_selected_screen_shield_select_icon_main_main_checked.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_rider_selected_screen_shield_select_icon_main_main_checked.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_shield_select_icon_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_rider_selected_screen_shield_select_icon_main_main_checked.set_img_recolor_opa(0)

# add style for rider_selected_screen_shield_select_icon
rider_selected_screen_shield_select_icon.add_style(style_rider_selected_screen_shield_select_icon_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

rider_selected_screen_label_area = lv.label(rider_selected_screen_container_rider_selected)
rider_selected_screen_label_area.set_pos(300,188)
rider_selected_screen_label_area.set_size(200,32)
rider_selected_screen_label_area.set_text("AREA LIMIT")
rider_selected_screen_label_area.set_long_mode(lv.label.LONG.WRAP)
rider_selected_screen_label_area.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_rider_selected_screen_label_area_main_main_default
style_rider_selected_screen_label_area_main_main_default = lv.style_t()
style_rider_selected_screen_label_area_main_main_default.init()
style_rider_selected_screen_label_area_main_main_default.set_radius(0)
style_rider_selected_screen_label_area_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_rider_selected_screen_label_area_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_rider_selected_screen_label_area_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_rider_selected_screen_label_area_main_main_default.set_bg_opa(0)
style_rider_selected_screen_label_area_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_rider_selected_screen_label_area_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_rider_selected_screen_label_area_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_rider_selected_screen_label_area_main_main_default.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_label_area_main_main_default.set_text_letter_space(2)
style_rider_selected_screen_label_area_main_main_default.set_pad_left(0)
style_rider_selected_screen_label_area_main_main_default.set_pad_right(0)
style_rider_selected_screen_label_area_main_main_default.set_pad_top(0)
style_rider_selected_screen_label_area_main_main_default.set_pad_bottom(0)

# add style for rider_selected_screen_label_area
rider_selected_screen_label_area.add_style(style_rider_selected_screen_label_area_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

rider_selected_screen_label_time = lv.label(rider_selected_screen_container_rider_selected)
rider_selected_screen_label_time.set_pos(550,188)
rider_selected_screen_label_time.set_size(200,32)
rider_selected_screen_label_time.set_text("TIME FENCE")
rider_selected_screen_label_time.set_long_mode(lv.label.LONG.WRAP)
rider_selected_screen_label_time.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_rider_selected_screen_label_time_main_main_default
style_rider_selected_screen_label_time_main_main_default = lv.style_t()
style_rider_selected_screen_label_time_main_main_default.init()
style_rider_selected_screen_label_time_main_main_default.set_radius(0)
style_rider_selected_screen_label_time_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_rider_selected_screen_label_time_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_rider_selected_screen_label_time_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_rider_selected_screen_label_time_main_main_default.set_bg_opa(0)
style_rider_selected_screen_label_time_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_rider_selected_screen_label_time_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_rider_selected_screen_label_time_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_rider_selected_screen_label_time_main_main_default.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_label_time_main_main_default.set_text_letter_space(2)
style_rider_selected_screen_label_time_main_main_default.set_pad_left(0)
style_rider_selected_screen_label_time_main_main_default.set_pad_right(0)
style_rider_selected_screen_label_time_main_main_default.set_pad_top(0)
style_rider_selected_screen_label_time_main_main_default.set_pad_bottom(0)

# add style for rider_selected_screen_label_time
rider_selected_screen_label_time.add_style(style_rider_selected_screen_label_time_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

rider_selected_screen_label_speed = lv.label(rider_selected_screen_container_rider_selected)
rider_selected_screen_label_speed.set_pos(306,384)
rider_selected_screen_label_speed.set_size(200,32)
rider_selected_screen_label_speed.set_text("SPEED LIMIT")
rider_selected_screen_label_speed.set_long_mode(lv.label.LONG.WRAP)
rider_selected_screen_label_speed.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_rider_selected_screen_label_speed_main_main_default
style_rider_selected_screen_label_speed_main_main_default = lv.style_t()
style_rider_selected_screen_label_speed_main_main_default.init()
style_rider_selected_screen_label_speed_main_main_default.set_radius(0)
style_rider_selected_screen_label_speed_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_rider_selected_screen_label_speed_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_rider_selected_screen_label_speed_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_rider_selected_screen_label_speed_main_main_default.set_bg_opa(0)
style_rider_selected_screen_label_speed_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_rider_selected_screen_label_speed_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_rider_selected_screen_label_speed_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_rider_selected_screen_label_speed_main_main_default.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_label_speed_main_main_default.set_text_letter_space(2)
style_rider_selected_screen_label_speed_main_main_default.set_pad_left(0)
style_rider_selected_screen_label_speed_main_main_default.set_pad_right(0)
style_rider_selected_screen_label_speed_main_main_default.set_pad_top(0)
style_rider_selected_screen_label_speed_main_main_default.set_pad_bottom(0)

# add style for rider_selected_screen_label_speed
rider_selected_screen_label_speed.add_style(style_rider_selected_screen_label_speed_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

rider_selected_screen_label_mode = lv.label(rider_selected_screen_container_rider_selected)
rider_selected_screen_label_mode.set_pos(550,384)
rider_selected_screen_label_mode.set_size(200,32)
rider_selected_screen_label_mode.set_text("MODE RESTRICTION")
rider_selected_screen_label_mode.set_long_mode(lv.label.LONG.WRAP)
rider_selected_screen_label_mode.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_rider_selected_screen_label_mode_main_main_default
style_rider_selected_screen_label_mode_main_main_default = lv.style_t()
style_rider_selected_screen_label_mode_main_main_default.init()
style_rider_selected_screen_label_mode_main_main_default.set_radius(0)
style_rider_selected_screen_label_mode_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_rider_selected_screen_label_mode_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_rider_selected_screen_label_mode_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_rider_selected_screen_label_mode_main_main_default.set_bg_opa(0)
style_rider_selected_screen_label_mode_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_rider_selected_screen_label_mode_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_rider_selected_screen_label_mode_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_rider_selected_screen_label_mode_main_main_default.set_text_font(lv.font_montserrat_16)
style_rider_selected_screen_label_mode_main_main_default.set_text_letter_space(2)
style_rider_selected_screen_label_mode_main_main_default.set_pad_left(0)
style_rider_selected_screen_label_mode_main_main_default.set_pad_right(0)
style_rider_selected_screen_label_mode_main_main_default.set_pad_top(0)
style_rider_selected_screen_label_mode_main_main_default.set_pad_bottom(0)

# add style for rider_selected_screen_label_mode
rider_selected_screen_label_mode.add_style(style_rider_selected_screen_label_mode_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_rider_selected_screen_container_rider_selected_main_main_default
style_rider_selected_screen_container_rider_selected_main_main_default = lv.style_t()
style_rider_selected_screen_container_rider_selected_main_main_default.init()
style_rider_selected_screen_container_rider_selected_main_main_default.set_radius(0)
style_rider_selected_screen_container_rider_selected_main_main_default.set_bg_color(lv.color_make(0x11,0x12,0x12))
style_rider_selected_screen_container_rider_selected_main_main_default.set_bg_grad_color(lv.color_make(0x0b,0x0c,0x0c))
style_rider_selected_screen_container_rider_selected_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_rider_selected_screen_container_rider_selected_main_main_default.set_bg_opa(255)
style_rider_selected_screen_container_rider_selected_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_rider_selected_screen_container_rider_selected_main_main_default.set_border_width(0)
style_rider_selected_screen_container_rider_selected_main_main_default.set_border_opa(0)
style_rider_selected_screen_container_rider_selected_main_main_default.set_pad_left(0)
style_rider_selected_screen_container_rider_selected_main_main_default.set_pad_right(0)
style_rider_selected_screen_container_rider_selected_main_main_default.set_pad_top(0)
style_rider_selected_screen_container_rider_selected_main_main_default.set_pad_bottom(0)

# add style for rider_selected_screen_container_rider_selected
rider_selected_screen_container_rider_selected.add_style(style_rider_selected_screen_container_rider_selected_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll = lv.obj()
# create style style_screen_menu_scroll_main_main_default
style_screen_menu_scroll_main_main_default = lv.style_t()
style_screen_menu_scroll_main_main_default.init()
style_screen_menu_scroll_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_menu_scroll_main_main_default.set_bg_opa(0)

# add style for screen_menu_scroll
screen_menu_scroll.add_style(style_screen_menu_scroll_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_Container_menu_scroll = lv.obj(screen_menu_scroll)
screen_menu_scroll_Container_menu_scroll.set_pos(0,0)
screen_menu_scroll_Container_menu_scroll.set_size(800,480)
screen_menu_scroll_Menu_select_label_1 = lv.label(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_Menu_select_label_1.set_pos(436,110)
screen_menu_scroll_Menu_select_label_1.set_size(330,28)
screen_menu_scroll_Menu_select_label_1.set_text("Distance 72.5 Km")
screen_menu_scroll_Menu_select_label_1.set_long_mode(lv.label.LONG.WRAP)
screen_menu_scroll_Menu_select_label_1.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_screen_menu_scroll_menu_select_label_1_main_main_default
style_screen_menu_scroll_menu_select_label_1_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_select_label_1_main_main_default.init()
style_screen_menu_scroll_menu_select_label_1_main_main_default.set_radius(0)
style_screen_menu_scroll_menu_select_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_menu_select_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_menu_select_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_menu_scroll_menu_select_label_1_main_main_default.set_bg_opa(0)
style_screen_menu_scroll_menu_select_label_1_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_menu_scroll_menu_select_label_1_main_main_default.set_text_font(lv.font_simsun_22)
except AttributeError:
    try:
        style_screen_menu_scroll_menu_select_label_1_main_main_default.set_text_font(lv.font_montserrat_22)
    except AttributeError:
        style_screen_menu_scroll_menu_select_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_menu_scroll_menu_select_label_1_main_main_default.set_text_letter_space(2)
style_screen_menu_scroll_menu_select_label_1_main_main_default.set_pad_left(0)
style_screen_menu_scroll_menu_select_label_1_main_main_default.set_pad_right(0)
style_screen_menu_scroll_menu_select_label_1_main_main_default.set_pad_top(0)
style_screen_menu_scroll_menu_select_label_1_main_main_default.set_pad_bottom(0)

# add style for screen_menu_scroll_Menu_select_label_1
screen_menu_scroll_Menu_select_label_1.add_style(style_screen_menu_scroll_menu_select_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_Menu_select_label_2 = lv.label(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_Menu_select_label_2.set_pos(437,171)
screen_menu_scroll_Menu_select_label_2.set_size(330,28)
screen_menu_scroll_Menu_select_label_2.set_text("Time 1.36 M")
screen_menu_scroll_Menu_select_label_2.set_long_mode(lv.label.LONG.WRAP)
screen_menu_scroll_Menu_select_label_2.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_screen_menu_scroll_menu_select_label_2_main_main_default
style_screen_menu_scroll_menu_select_label_2_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_select_label_2_main_main_default.init()
style_screen_menu_scroll_menu_select_label_2_main_main_default.set_radius(0)
style_screen_menu_scroll_menu_select_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_menu_select_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_menu_select_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_menu_scroll_menu_select_label_2_main_main_default.set_bg_opa(0)
style_screen_menu_scroll_menu_select_label_2_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_menu_scroll_menu_select_label_2_main_main_default.set_text_font(lv.font_simsun_22)
except AttributeError:
    try:
        style_screen_menu_scroll_menu_select_label_2_main_main_default.set_text_font(lv.font_montserrat_22)
    except AttributeError:
        style_screen_menu_scroll_menu_select_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_menu_scroll_menu_select_label_2_main_main_default.set_text_letter_space(2)
style_screen_menu_scroll_menu_select_label_2_main_main_default.set_pad_left(0)
style_screen_menu_scroll_menu_select_label_2_main_main_default.set_pad_right(0)
style_screen_menu_scroll_menu_select_label_2_main_main_default.set_pad_top(0)
style_screen_menu_scroll_menu_select_label_2_main_main_default.set_pad_bottom(0)

# add style for screen_menu_scroll_Menu_select_label_2
screen_menu_scroll_Menu_select_label_2.add_style(style_screen_menu_scroll_menu_select_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_Menu_select_label_3 = lv.label(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_Menu_select_label_3.set_pos(437,229)
screen_menu_scroll_Menu_select_label_3.set_size(330,28)
screen_menu_scroll_Menu_select_label_3.set_text("Avg. Speed 60 Km/h")
screen_menu_scroll_Menu_select_label_3.set_long_mode(lv.label.LONG.WRAP)
screen_menu_scroll_Menu_select_label_3.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_screen_menu_scroll_menu_select_label_3_main_main_default
style_screen_menu_scroll_menu_select_label_3_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_select_label_3_main_main_default.init()
style_screen_menu_scroll_menu_select_label_3_main_main_default.set_radius(0)
style_screen_menu_scroll_menu_select_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_menu_select_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_menu_select_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_menu_scroll_menu_select_label_3_main_main_default.set_bg_opa(0)
style_screen_menu_scroll_menu_select_label_3_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_menu_scroll_menu_select_label_3_main_main_default.set_text_font(lv.font_simsun_22)
except AttributeError:
    try:
        style_screen_menu_scroll_menu_select_label_3_main_main_default.set_text_font(lv.font_montserrat_22)
    except AttributeError:
        style_screen_menu_scroll_menu_select_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_menu_scroll_menu_select_label_3_main_main_default.set_text_letter_space(2)
style_screen_menu_scroll_menu_select_label_3_main_main_default.set_pad_left(0)
style_screen_menu_scroll_menu_select_label_3_main_main_default.set_pad_right(0)
style_screen_menu_scroll_menu_select_label_3_main_main_default.set_pad_top(0)
style_screen_menu_scroll_menu_select_label_3_main_main_default.set_pad_bottom(0)

# add style for screen_menu_scroll_Menu_select_label_3
screen_menu_scroll_Menu_select_label_3.add_style(style_screen_menu_scroll_menu_select_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_Menu_select_label_4 = lv.label(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_Menu_select_label_4.set_pos(437,290)
screen_menu_scroll_Menu_select_label_4.set_size(330,28)
screen_menu_scroll_Menu_select_label_4.set_text("Max. Speed 70 Km/h")
screen_menu_scroll_Menu_select_label_4.set_long_mode(lv.label.LONG.WRAP)
screen_menu_scroll_Menu_select_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_screen_menu_scroll_menu_select_label_4_main_main_default
style_screen_menu_scroll_menu_select_label_4_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_select_label_4_main_main_default.init()
style_screen_menu_scroll_menu_select_label_4_main_main_default.set_radius(0)
style_screen_menu_scroll_menu_select_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_menu_select_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_menu_select_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_menu_scroll_menu_select_label_4_main_main_default.set_bg_opa(0)
style_screen_menu_scroll_menu_select_label_4_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_menu_scroll_menu_select_label_4_main_main_default.set_text_font(lv.font_simsun_22)
except AttributeError:
    try:
        style_screen_menu_scroll_menu_select_label_4_main_main_default.set_text_font(lv.font_montserrat_22)
    except AttributeError:
        style_screen_menu_scroll_menu_select_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_menu_scroll_menu_select_label_4_main_main_default.set_text_letter_space(2)
style_screen_menu_scroll_menu_select_label_4_main_main_default.set_pad_left(0)
style_screen_menu_scroll_menu_select_label_4_main_main_default.set_pad_right(0)
style_screen_menu_scroll_menu_select_label_4_main_main_default.set_pad_top(0)
style_screen_menu_scroll_menu_select_label_4_main_main_default.set_pad_bottom(0)

# add style for screen_menu_scroll_Menu_select_label_4
screen_menu_scroll_Menu_select_label_4.add_style(style_screen_menu_scroll_menu_select_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_Menu_select_label_5 = lv.label(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_Menu_select_label_5.set_pos(437,350)
screen_menu_scroll_Menu_select_label_5.set_size(330,28)
screen_menu_scroll_Menu_select_label_5.set_text("RESET")
screen_menu_scroll_Menu_select_label_5.set_long_mode(lv.label.LONG.WRAP)
screen_menu_scroll_Menu_select_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_screen_menu_scroll_menu_select_label_5_main_main_default
style_screen_menu_scroll_menu_select_label_5_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_select_label_5_main_main_default.init()
style_screen_menu_scroll_menu_select_label_5_main_main_default.set_radius(0)
style_screen_menu_scroll_menu_select_label_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_menu_select_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_menu_select_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_menu_scroll_menu_select_label_5_main_main_default.set_bg_opa(0)
style_screen_menu_scroll_menu_select_label_5_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_menu_scroll_menu_select_label_5_main_main_default.set_text_font(lv.font_simsun_22)
except AttributeError:
    try:
        style_screen_menu_scroll_menu_select_label_5_main_main_default.set_text_font(lv.font_montserrat_22)
    except AttributeError:
        style_screen_menu_scroll_menu_select_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_menu_scroll_menu_select_label_5_main_main_default.set_text_letter_space(2)
style_screen_menu_scroll_menu_select_label_5_main_main_default.set_pad_left(0)
style_screen_menu_scroll_menu_select_label_5_main_main_default.set_pad_right(0)
style_screen_menu_scroll_menu_select_label_5_main_main_default.set_pad_top(0)
style_screen_menu_scroll_menu_select_label_5_main_main_default.set_pad_bottom(0)

# add style for screen_menu_scroll_Menu_select_label_5
screen_menu_scroll_Menu_select_label_5.add_style(style_screen_menu_scroll_menu_select_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_Menu_select_1 = lv.img(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_Menu_select_1.set_pos(140,32)
screen_menu_scroll_Menu_select_1.set_size(180,130)
screen_menu_scroll_Menu_select_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-367325062.png','rb') as f:
        screen_menu_scroll_Menu_select_1_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-367325062.png')
    sys.exit()

screen_menu_scroll_Menu_select_1_img = lv.img_dsc_t({
  'data_size': len(screen_menu_scroll_Menu_select_1_img_data),
  'header': {'always_zero': 0, 'w': 180, 'h': 130, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_menu_scroll_Menu_select_1_img_data
})

screen_menu_scroll_Menu_select_1.set_src(screen_menu_scroll_Menu_select_1_img)
screen_menu_scroll_Menu_select_1.set_pivot(0,0)
screen_menu_scroll_Menu_select_1.set_angle(0)
# create style style_screen_menu_scroll_menu_select_1_main_main_default
style_screen_menu_scroll_menu_select_1_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_select_1_main_main_default.init()
style_screen_menu_scroll_menu_select_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_menu_scroll_menu_select_1_main_main_default.set_img_recolor_opa(0)
style_screen_menu_scroll_menu_select_1_main_main_default.set_img_opa(255)

# add style for screen_menu_scroll_Menu_select_1
screen_menu_scroll_Menu_select_1.add_style(style_screen_menu_scroll_menu_select_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_Menu_select_2 = lv.img(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_Menu_select_2.set_pos(140,161)
screen_menu_scroll_Menu_select_2.set_size(180,130)
screen_menu_scroll_Menu_select_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-367325062.png','rb') as f:
        screen_menu_scroll_Menu_select_2_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-367325062.png')
    sys.exit()

screen_menu_scroll_Menu_select_2_img = lv.img_dsc_t({
  'data_size': len(screen_menu_scroll_Menu_select_2_img_data),
  'header': {'always_zero': 0, 'w': 180, 'h': 130, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_menu_scroll_Menu_select_2_img_data
})

screen_menu_scroll_Menu_select_2.set_src(screen_menu_scroll_Menu_select_2_img)
screen_menu_scroll_Menu_select_2.set_pivot(0,0)
screen_menu_scroll_Menu_select_2.set_angle(0)
# create style style_screen_menu_scroll_menu_select_2_main_main_default
style_screen_menu_scroll_menu_select_2_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_select_2_main_main_default.init()
style_screen_menu_scroll_menu_select_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_menu_scroll_menu_select_2_main_main_default.set_img_recolor_opa(0)
style_screen_menu_scroll_menu_select_2_main_main_default.set_img_opa(255)

# add style for screen_menu_scroll_Menu_select_2
screen_menu_scroll_Menu_select_2.add_style(style_screen_menu_scroll_menu_select_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_Menu_select_3 = lv.img(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_Menu_select_3.set_pos(140,291)
screen_menu_scroll_Menu_select_3.set_size(180,130)
screen_menu_scroll_Menu_select_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-367325062.png','rb') as f:
        screen_menu_scroll_Menu_select_3_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-367325062.png')
    sys.exit()

screen_menu_scroll_Menu_select_3_img = lv.img_dsc_t({
  'data_size': len(screen_menu_scroll_Menu_select_3_img_data),
  'header': {'always_zero': 0, 'w': 180, 'h': 130, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_menu_scroll_Menu_select_3_img_data
})

screen_menu_scroll_Menu_select_3.set_src(screen_menu_scroll_Menu_select_3_img)
screen_menu_scroll_Menu_select_3.set_pivot(0,0)
screen_menu_scroll_Menu_select_3.set_angle(0)
# create style style_screen_menu_scroll_menu_select_3_main_main_default
style_screen_menu_scroll_menu_select_3_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_select_3_main_main_default.init()
style_screen_menu_scroll_menu_select_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_menu_scroll_menu_select_3_main_main_default.set_img_recolor_opa(0)
style_screen_menu_scroll_menu_select_3_main_main_default.set_img_opa(255)

# add style for screen_menu_scroll_Menu_select_3
screen_menu_scroll_Menu_select_3.add_style(style_screen_menu_scroll_menu_select_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_menu_top_line = lv.img(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_menu_top_line.set_pos(61,11)
screen_menu_scroll_menu_top_line.set_size(700,5)
screen_menu_scroll_menu_top_line.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1230288729.png','rb') as f:
        screen_menu_scroll_menu_top_line_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1230288729.png')
    sys.exit()

screen_menu_scroll_menu_top_line_img = lv.img_dsc_t({
  'data_size': len(screen_menu_scroll_menu_top_line_img_data),
  'header': {'always_zero': 0, 'w': 700, 'h': 5, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_menu_scroll_menu_top_line_img_data
})

screen_menu_scroll_menu_top_line.set_src(screen_menu_scroll_menu_top_line_img)
screen_menu_scroll_menu_top_line.set_pivot(0,0)
screen_menu_scroll_menu_top_line.set_angle(0)
# create style style_screen_menu_scroll_menu_top_line_main_main_default
style_screen_menu_scroll_menu_top_line_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_top_line_main_main_default.init()
style_screen_menu_scroll_menu_top_line_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_menu_scroll_menu_top_line_main_main_default.set_img_recolor_opa(0)
style_screen_menu_scroll_menu_top_line_main_main_default.set_img_opa(255)

# add style for screen_menu_scroll_menu_top_line
screen_menu_scroll_menu_top_line.add_style(style_screen_menu_scroll_menu_top_line_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_menu_bottom_line = lv.img(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_menu_bottom_line.set_pos(61,452)
screen_menu_scroll_menu_bottom_line.set_size(700,12)
screen_menu_scroll_menu_bottom_line.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp2073588695.png','rb') as f:
        screen_menu_scroll_menu_bottom_line_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp2073588695.png')
    sys.exit()

screen_menu_scroll_menu_bottom_line_img = lv.img_dsc_t({
  'data_size': len(screen_menu_scroll_menu_bottom_line_img_data),
  'header': {'always_zero': 0, 'w': 700, 'h': 12, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_menu_scroll_menu_bottom_line_img_data
})

screen_menu_scroll_menu_bottom_line.set_src(screen_menu_scroll_menu_bottom_line_img)
screen_menu_scroll_menu_bottom_line.set_pivot(0,0)
screen_menu_scroll_menu_bottom_line.set_angle(0)
# create style style_screen_menu_scroll_menu_bottom_line_main_main_default
style_screen_menu_scroll_menu_bottom_line_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_bottom_line_main_main_default.init()
style_screen_menu_scroll_menu_bottom_line_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_menu_scroll_menu_bottom_line_main_main_default.set_img_recolor_opa(0)
style_screen_menu_scroll_menu_bottom_line_main_main_default.set_img_opa(255)

# add style for screen_menu_scroll_menu_bottom_line
screen_menu_scroll_menu_bottom_line.add_style(style_screen_menu_scroll_menu_bottom_line_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_menu_vertical_line = lv.img(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_menu_vertical_line.set_pos(360,80)
screen_menu_scroll_menu_vertical_line.set_size(24,340)
screen_menu_scroll_menu_vertical_line.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp74860055.png','rb') as f:
        screen_menu_scroll_menu_vertical_line_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp74860055.png')
    sys.exit()

screen_menu_scroll_menu_vertical_line_img = lv.img_dsc_t({
  'data_size': len(screen_menu_scroll_menu_vertical_line_img_data),
  'header': {'always_zero': 0, 'w': 24, 'h': 340, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_menu_scroll_menu_vertical_line_img_data
})

screen_menu_scroll_menu_vertical_line.set_src(screen_menu_scroll_menu_vertical_line_img)
screen_menu_scroll_menu_vertical_line.set_pivot(0,0)
screen_menu_scroll_menu_vertical_line.set_angle(0)
# create style style_screen_menu_scroll_menu_vertical_line_main_main_default
style_screen_menu_scroll_menu_vertical_line_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_vertical_line_main_main_default.init()
style_screen_menu_scroll_menu_vertical_line_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_menu_scroll_menu_vertical_line_main_main_default.set_img_recolor_opa(0)
style_screen_menu_scroll_menu_vertical_line_main_main_default.set_img_opa(75)

# add style for screen_menu_scroll_menu_vertical_line
screen_menu_scroll_menu_vertical_line.add_style(style_screen_menu_scroll_menu_vertical_line_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_menu_label = lv.label(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_menu_label.set_pos(18,110)
screen_menu_scroll_menu_label.set_size(35,250)
screen_menu_scroll_menu_label.set_text("MENU")
screen_menu_scroll_menu_label.set_long_mode(lv.label.LONG.WRAP)
screen_menu_scroll_menu_label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_menu_scroll_menu_label_main_main_default
style_screen_menu_scroll_menu_label_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_label_main_main_default.init()
style_screen_menu_scroll_menu_label_main_main_default.set_radius(0)
style_screen_menu_scroll_menu_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_menu_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_menu_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_menu_scroll_menu_label_main_main_default.set_bg_opa(0)
style_screen_menu_scroll_menu_label_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_menu_scroll_menu_label_main_main_default.set_text_font(lv.font_simsun_60)
except AttributeError:
    try:
        style_screen_menu_scroll_menu_label_main_main_default.set_text_font(lv.font_montserrat_60)
    except AttributeError:
        style_screen_menu_scroll_menu_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_menu_scroll_menu_label_main_main_default.set_text_letter_space(2)
style_screen_menu_scroll_menu_label_main_main_default.set_pad_left(0)
style_screen_menu_scroll_menu_label_main_main_default.set_pad_right(0)
style_screen_menu_scroll_menu_label_main_main_default.set_pad_top(0)
style_screen_menu_scroll_menu_label_main_main_default.set_pad_bottom(0)

# add style for screen_menu_scroll_menu_label
screen_menu_scroll_menu_label.add_style(style_screen_menu_scroll_menu_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_menu_item_1 = lv.img(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_menu_item_1.set_pos(410,98)
screen_menu_scroll_menu_item_1.set_size(370,50)
screen_menu_scroll_menu_item_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1574388570.png','rb') as f:
        screen_menu_scroll_menu_item_1_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1574388570.png')
    sys.exit()

screen_menu_scroll_menu_item_1_img = lv.img_dsc_t({
  'data_size': len(screen_menu_scroll_menu_item_1_img_data),
  'header': {'always_zero': 0, 'w': 370, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_menu_scroll_menu_item_1_img_data
})

screen_menu_scroll_menu_item_1.set_src(screen_menu_scroll_menu_item_1_img)
screen_menu_scroll_menu_item_1.set_pivot(0,0)
screen_menu_scroll_menu_item_1.set_angle(0)
# create style style_screen_menu_scroll_menu_item_1_main_main_default
style_screen_menu_scroll_menu_item_1_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_item_1_main_main_default.init()
style_screen_menu_scroll_menu_item_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_menu_scroll_menu_item_1_main_main_default.set_img_recolor_opa(0)
style_screen_menu_scroll_menu_item_1_main_main_default.set_img_opa(255)

# add style for screen_menu_scroll_menu_item_1
screen_menu_scroll_menu_item_1.add_style(style_screen_menu_scroll_menu_item_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_menu_item_2 = lv.img(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_menu_item_2.set_pos(410,159)
screen_menu_scroll_menu_item_2.set_size(370,50)
screen_menu_scroll_menu_item_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1574388570.png','rb') as f:
        screen_menu_scroll_menu_item_2_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1574388570.png')
    sys.exit()

screen_menu_scroll_menu_item_2_img = lv.img_dsc_t({
  'data_size': len(screen_menu_scroll_menu_item_2_img_data),
  'header': {'always_zero': 0, 'w': 370, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_menu_scroll_menu_item_2_img_data
})

screen_menu_scroll_menu_item_2.set_src(screen_menu_scroll_menu_item_2_img)
screen_menu_scroll_menu_item_2.set_pivot(0,0)
screen_menu_scroll_menu_item_2.set_angle(0)
# create style style_screen_menu_scroll_menu_item_2_main_main_default
style_screen_menu_scroll_menu_item_2_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_item_2_main_main_default.init()
style_screen_menu_scroll_menu_item_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_menu_scroll_menu_item_2_main_main_default.set_img_recolor_opa(0)
style_screen_menu_scroll_menu_item_2_main_main_default.set_img_opa(255)

# add style for screen_menu_scroll_menu_item_2
screen_menu_scroll_menu_item_2.add_style(style_screen_menu_scroll_menu_item_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_menu_item_3 = lv.img(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_menu_item_3.set_pos(410,216)
screen_menu_scroll_menu_item_3.set_size(370,50)
screen_menu_scroll_menu_item_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1574388570.png','rb') as f:
        screen_menu_scroll_menu_item_3_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1574388570.png')
    sys.exit()

screen_menu_scroll_menu_item_3_img = lv.img_dsc_t({
  'data_size': len(screen_menu_scroll_menu_item_3_img_data),
  'header': {'always_zero': 0, 'w': 370, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_menu_scroll_menu_item_3_img_data
})

screen_menu_scroll_menu_item_3.set_src(screen_menu_scroll_menu_item_3_img)
screen_menu_scroll_menu_item_3.set_pivot(0,0)
screen_menu_scroll_menu_item_3.set_angle(0)
# create style style_screen_menu_scroll_menu_item_3_main_main_default
style_screen_menu_scroll_menu_item_3_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_item_3_main_main_default.init()
style_screen_menu_scroll_menu_item_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_menu_scroll_menu_item_3_main_main_default.set_img_recolor_opa(0)
style_screen_menu_scroll_menu_item_3_main_main_default.set_img_opa(255)

# add style for screen_menu_scroll_menu_item_3
screen_menu_scroll_menu_item_3.add_style(style_screen_menu_scroll_menu_item_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_menu_item_4 = lv.img(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_menu_item_4.set_pos(410,277)
screen_menu_scroll_menu_item_4.set_size(370,50)
screen_menu_scroll_menu_item_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1574388570.png','rb') as f:
        screen_menu_scroll_menu_item_4_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1574388570.png')
    sys.exit()

screen_menu_scroll_menu_item_4_img = lv.img_dsc_t({
  'data_size': len(screen_menu_scroll_menu_item_4_img_data),
  'header': {'always_zero': 0, 'w': 370, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_menu_scroll_menu_item_4_img_data
})

screen_menu_scroll_menu_item_4.set_src(screen_menu_scroll_menu_item_4_img)
screen_menu_scroll_menu_item_4.set_pivot(0,0)
screen_menu_scroll_menu_item_4.set_angle(0)
# create style style_screen_menu_scroll_menu_item_4_main_main_default
style_screen_menu_scroll_menu_item_4_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_item_4_main_main_default.init()
style_screen_menu_scroll_menu_item_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_menu_scroll_menu_item_4_main_main_default.set_img_recolor_opa(0)
style_screen_menu_scroll_menu_item_4_main_main_default.set_img_opa(255)

# add style for screen_menu_scroll_menu_item_4
screen_menu_scroll_menu_item_4.add_style(style_screen_menu_scroll_menu_item_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_scroll_menu_item_5 = lv.img(screen_menu_scroll_Container_menu_scroll)
screen_menu_scroll_menu_item_5.set_pos(410,338)
screen_menu_scroll_menu_item_5.set_size(370,50)
screen_menu_scroll_menu_item_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1574388570.png','rb') as f:
        screen_menu_scroll_menu_item_5_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1574388570.png')
    sys.exit()

screen_menu_scroll_menu_item_5_img = lv.img_dsc_t({
  'data_size': len(screen_menu_scroll_menu_item_5_img_data),
  'header': {'always_zero': 0, 'w': 370, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_menu_scroll_menu_item_5_img_data
})

screen_menu_scroll_menu_item_5.set_src(screen_menu_scroll_menu_item_5_img)
screen_menu_scroll_menu_item_5.set_pivot(0,0)
screen_menu_scroll_menu_item_5.set_angle(0)
# create style style_screen_menu_scroll_menu_item_5_main_main_default
style_screen_menu_scroll_menu_item_5_main_main_default = lv.style_t()
style_screen_menu_scroll_menu_item_5_main_main_default.init()
style_screen_menu_scroll_menu_item_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_menu_scroll_menu_item_5_main_main_default.set_img_recolor_opa(0)
style_screen_menu_scroll_menu_item_5_main_main_default.set_img_opa(255)

# add style for screen_menu_scroll_menu_item_5
screen_menu_scroll_menu_item_5.add_style(style_screen_menu_scroll_menu_item_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_menu_scroll_container_menu_scroll_main_main_default
style_screen_menu_scroll_container_menu_scroll_main_main_default = lv.style_t()
style_screen_menu_scroll_container_menu_scroll_main_main_default.init()
style_screen_menu_scroll_container_menu_scroll_main_main_default.set_radius(0)
style_screen_menu_scroll_container_menu_scroll_main_main_default.set_bg_color(lv.color_make(0x11,0x12,0x12))
style_screen_menu_scroll_container_menu_scroll_main_main_default.set_bg_grad_color(lv.color_make(0x0b,0x0c,0x0c))
style_screen_menu_scroll_container_menu_scroll_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_menu_scroll_container_menu_scroll_main_main_default.set_bg_opa(255)
style_screen_menu_scroll_container_menu_scroll_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_scroll_container_menu_scroll_main_main_default.set_border_width(0)
style_screen_menu_scroll_container_menu_scroll_main_main_default.set_border_opa(0)
style_screen_menu_scroll_container_menu_scroll_main_main_default.set_pad_left(0)
style_screen_menu_scroll_container_menu_scroll_main_main_default.set_pad_right(0)
style_screen_menu_scroll_container_menu_scroll_main_main_default.set_pad_top(0)
style_screen_menu_scroll_container_menu_scroll_main_main_default.set_pad_bottom(0)

# add style for screen_menu_scroll_Container_menu_scroll
screen_menu_scroll_Container_menu_scroll.add_style(style_screen_menu_scroll_container_menu_scroll_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_roller = lv.obj()
# create style style_screen_menu_roller_main_main_default
style_screen_menu_roller_main_main_default = lv.style_t()
style_screen_menu_roller_main_main_default.init()
style_screen_menu_roller_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_menu_roller_main_main_default.set_bg_opa(0)

# add style for screen_menu_roller
screen_menu_roller.add_style(style_screen_menu_roller_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_roller_container_menu_roller = lv.obj(screen_menu_roller)
screen_menu_roller_container_menu_roller.set_pos(0,0)
screen_menu_roller_container_menu_roller.set_size(800,480)
# create style style_screen_menu_roller_container_menu_roller_main_main_default
style_screen_menu_roller_container_menu_roller_main_main_default = lv.style_t()
style_screen_menu_roller_container_menu_roller_main_main_default.init()
style_screen_menu_roller_container_menu_roller_main_main_default.set_radius(0)
style_screen_menu_roller_container_menu_roller_main_main_default.set_bg_color(lv.color_make(0x11,0x12,0x12))
style_screen_menu_roller_container_menu_roller_main_main_default.set_bg_grad_color(lv.color_make(0x0b,0x0c,0x0c))
style_screen_menu_roller_container_menu_roller_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_menu_roller_container_menu_roller_main_main_default.set_bg_opa(255)
style_screen_menu_roller_container_menu_roller_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_roller_container_menu_roller_main_main_default.set_border_width(0)
style_screen_menu_roller_container_menu_roller_main_main_default.set_border_opa(255)
style_screen_menu_roller_container_menu_roller_main_main_default.set_pad_left(0)
style_screen_menu_roller_container_menu_roller_main_main_default.set_pad_right(0)
style_screen_menu_roller_container_menu_roller_main_main_default.set_pad_top(0)
style_screen_menu_roller_container_menu_roller_main_main_default.set_pad_bottom(0)

# add style for screen_menu_roller_container_menu_roller
screen_menu_roller_container_menu_roller.add_style(style_screen_menu_roller_container_menu_roller_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_menu_roller_roller_1 = lv.roller(screen_menu_roller)
screen_menu_roller_roller_1.set_pos(28,41)
screen_menu_roller_roller_1.set_options("1 HELLO\n2\n3\n4\n5", lv.roller.MODE.INFINITE)
screen_menu_roller_roller_1.set_visible_row_count(5)
try:
	screen_menu_roller_roller_1.set_style_text_font(lv.font_simsun_100, lv.PART.MAIN|lv.STATE.DEFAULT)
	screen_menu_roller_roller_1.set_style_text_font(lv.font_simsun_100, lv.PART.MAIN|lv.STATE.FOCUSED)
	screen_menu_roller_roller_1.set_style_text_font(lv.font_simsun_100, lv.PART.SELECTED|lv.STATE.DEFAULT)
except AttributeError:
	try:
		screen_menu_roller_roller_1.set_style_text_font(lv.font_montserrat_100, lv.PART.MAIN|lv.STATE.DEFAULT)
		screen_menu_roller_roller_1.set_style_text_font(lv.font_montserrat_100, lv.PART.MAIN|lv.STATE.FOCUSED)
		screen_menu_roller_roller_1.set_style_text_font(lv.font_montserrat_100, lv.PART.SELECTED|lv.STATE.DEFAULT)
	except AttributeError:
		screen_menu_roller_roller_1.set_style_text_font(lv.font_montserrat_16, lv.PART.MAIN|lv.STATE.DEFAULT)
		screen_menu_roller_roller_1.set_style_text_font(lv.font_montserrat_16, lv.PART.MAIN|lv.STATE.FOCUSED)
		screen_menu_roller_roller_1.set_style_text_font(lv.font_montserrat_16, lv.PART.SELECTED|lv.STATE.DEFAULT)
# create style style_screen_menu_roller_roller_1_main_main_default
style_screen_menu_roller_roller_1_main_main_default = lv.style_t()
style_screen_menu_roller_roller_1_main_main_default.init()
style_screen_menu_roller_roller_1_main_main_default.set_radius(5)
style_screen_menu_roller_roller_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_menu_roller_roller_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_menu_roller_roller_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_menu_roller_roller_1_main_main_default.set_bg_opa(255)
style_screen_menu_roller_roller_1_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_screen_menu_roller_roller_1_main_main_default.set_border_width(2)
style_screen_menu_roller_roller_1_main_main_default.set_text_color(lv.color_make(0x33,0x33,0x33))

# add style for screen_menu_roller_roller_1
screen_menu_roller_roller_1.add_style(style_screen_menu_roller_roller_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_menu_roller_roller_1_main_selected_default
style_screen_menu_roller_roller_1_main_selected_default = lv.style_t()
style_screen_menu_roller_roller_1_main_selected_default.init()
style_screen_menu_roller_roller_1_main_selected_default.set_bg_color(lv.color_make(0x1d,0xe0,0x10))
style_screen_menu_roller_roller_1_main_selected_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_menu_roller_roller_1_main_selected_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_screen_menu_roller_roller_1_main_selected_default.set_bg_opa(255)
style_screen_menu_roller_roller_1_main_selected_default.set_text_color(lv.color_make(0xFF,0xFF,0xFF))

# add style for screen_menu_roller_roller_1
screen_menu_roller_roller_1.add_style(style_screen_menu_roller_roller_1_main_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

screen_drawing = lv.obj()
# create style style_screen_drawing_main_main_default
style_screen_drawing_main_main_default = lv.style_t()
style_screen_drawing_main_main_default.init()
style_screen_drawing_main_main_default.set_bg_color(lv.color_make(0x25,0x04,0x04))
style_screen_drawing_main_main_default.set_bg_opa(255)

# add style for screen_drawing
screen_drawing.add_style(style_screen_drawing_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_container_drawing = lv.obj(screen_drawing)
screen_drawing_container_drawing.set_pos(0,0)
screen_drawing_container_drawing.set_size(800,480)
screen_drawing_canvas_1 = lv.canvas(screen_drawing_container_drawing)
screen_drawing_canvas_1.set_pos(400,400)
screen_drawing_canvas_1.set_size(100,40)
cbuf_screen_drawing_canvas_1 = bytearray(100 * 40 * 4)
screen_drawing_canvas_1.set_buffer(cbuf_screen_drawing_canvas_1, 100, 40, lv.img.CF.TRUE_COLOR_ALPHA)
screen_drawing_canvas_1.fill_bg(lv.color_make(0x00,0x00,0x00), 0)
# create style style_screen_drawing_canvas_1_main_main_default
style_screen_drawing_canvas_1_main_main_default = lv.style_t()
style_screen_drawing_canvas_1_main_main_default.init()
style_screen_drawing_canvas_1_main_main_default.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_screen_drawing_canvas_1_main_main_default.set_img_recolor_opa(0)

# add style for screen_drawing_canvas_1
screen_drawing_canvas_1.add_style(style_screen_drawing_canvas_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_18 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_18.set_pos(490,305)
screen_drawing_RPM_18.set_size(20,20)
screen_drawing_RPM_18.set_text("18")
screen_drawing_RPM_18.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_18.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_18_main_main_default
style_screen_drawing_rpm_18_main_main_default = lv.style_t()
style_screen_drawing_rpm_18_main_main_default.init()
style_screen_drawing_rpm_18_main_main_default.set_radius(0)
style_screen_drawing_rpm_18_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_18_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_18_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_18_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_18_main_main_default.set_text_color(lv.color_make(0xa8,0x10,0x1f))
try:
    style_screen_drawing_rpm_18_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_18_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_18_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_18_main_main_default.set_text_letter_space(0)
style_screen_drawing_rpm_18_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_18_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_18_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_18_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_18
screen_drawing_RPM_18.add_style(style_screen_drawing_rpm_18_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_17 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_17.set_pos(505,282)
screen_drawing_RPM_17.set_size(20,20)
screen_drawing_RPM_17.set_text("17")
screen_drawing_RPM_17.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_17.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_17_main_main_default
style_screen_drawing_rpm_17_main_main_default = lv.style_t()
style_screen_drawing_rpm_17_main_main_default.init()
style_screen_drawing_rpm_17_main_main_default.set_radius(0)
style_screen_drawing_rpm_17_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_17_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_17_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_17_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_17_main_main_default.set_text_color(lv.color_make(0xa8,0x10,0x1f))
try:
    style_screen_drawing_rpm_17_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_17_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_17_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_17_main_main_default.set_text_letter_space(0)
style_screen_drawing_rpm_17_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_17_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_17_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_17_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_17
screen_drawing_RPM_17.add_style(style_screen_drawing_rpm_17_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_16 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_16.set_pos(518,249)
screen_drawing_RPM_16.set_size(20,20)
screen_drawing_RPM_16.set_text("16")
screen_drawing_RPM_16.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_16.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_16_main_main_default
style_screen_drawing_rpm_16_main_main_default = lv.style_t()
style_screen_drawing_rpm_16_main_main_default.init()
style_screen_drawing_rpm_16_main_main_default.set_radius(0)
style_screen_drawing_rpm_16_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_16_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_16_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_16_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_16_main_main_default.set_text_color(lv.color_make(0xa8,0x10,0x1f))
try:
    style_screen_drawing_rpm_16_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_16_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_16_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_16_main_main_default.set_text_letter_space(0)
style_screen_drawing_rpm_16_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_16_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_16_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_16_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_16
screen_drawing_RPM_16.add_style(style_screen_drawing_rpm_16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_15 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_15.set_pos(521,216)
screen_drawing_RPM_15.set_size(20,20)
screen_drawing_RPM_15.set_text("15")
screen_drawing_RPM_15.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_15.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_15_main_main_default
style_screen_drawing_rpm_15_main_main_default = lv.style_t()
style_screen_drawing_rpm_15_main_main_default.init()
style_screen_drawing_rpm_15_main_main_default.set_radius(0)
style_screen_drawing_rpm_15_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_15_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_15_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_15_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_15_main_main_default.set_text_color(lv.color_make(0xa8,0x10,0x1f))
try:
    style_screen_drawing_rpm_15_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_15_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_15_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_15_main_main_default.set_text_letter_space(0)
style_screen_drawing_rpm_15_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_15_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_15_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_15_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_15
screen_drawing_RPM_15.add_style(style_screen_drawing_rpm_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_14 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_14.set_pos(517,180)
screen_drawing_RPM_14.set_size(20,20)
screen_drawing_RPM_14.set_text("14")
screen_drawing_RPM_14.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_14.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_14_main_main_default
style_screen_drawing_rpm_14_main_main_default = lv.style_t()
style_screen_drawing_rpm_14_main_main_default.init()
style_screen_drawing_rpm_14_main_main_default.set_radius(0)
style_screen_drawing_rpm_14_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_14_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_14_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_14_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_14_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_14_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_14_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_14_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_14_main_main_default.set_text_letter_space(0)
style_screen_drawing_rpm_14_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_14_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_14_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_14_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_14
screen_drawing_RPM_14.add_style(style_screen_drawing_rpm_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_13 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_13.set_pos(505,151)
screen_drawing_RPM_13.set_size(20,20)
screen_drawing_RPM_13.set_text("13")
screen_drawing_RPM_13.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_13.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_13_main_main_default
style_screen_drawing_rpm_13_main_main_default = lv.style_t()
style_screen_drawing_rpm_13_main_main_default.init()
style_screen_drawing_rpm_13_main_main_default.set_radius(0)
style_screen_drawing_rpm_13_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_13_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_13_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_13_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_13_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_13_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_13_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_13_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_13_main_main_default.set_text_letter_space(0)
style_screen_drawing_rpm_13_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_13_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_13_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_13_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_13
screen_drawing_RPM_13.add_style(style_screen_drawing_rpm_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_12 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_12.set_pos(484,124)
screen_drawing_RPM_12.set_size(20,20)
screen_drawing_RPM_12.set_text("12")
screen_drawing_RPM_12.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_12.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_12_main_main_default
style_screen_drawing_rpm_12_main_main_default = lv.style_t()
style_screen_drawing_rpm_12_main_main_default.init()
style_screen_drawing_rpm_12_main_main_default.set_radius(0)
style_screen_drawing_rpm_12_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_12_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_12_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_12_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_12_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_12_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_12_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_12_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_12_main_main_default.set_text_letter_space(0)
style_screen_drawing_rpm_12_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_12_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_12_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_12_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_12
screen_drawing_RPM_12.add_style(style_screen_drawing_rpm_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_11 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_11.set_pos(456,103)
screen_drawing_RPM_11.set_size(20,20)
screen_drawing_RPM_11.set_text("11")
screen_drawing_RPM_11.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_11.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_11_main_main_default
style_screen_drawing_rpm_11_main_main_default = lv.style_t()
style_screen_drawing_rpm_11_main_main_default.init()
style_screen_drawing_rpm_11_main_main_default.set_radius(0)
style_screen_drawing_rpm_11_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_11_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_11_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_11_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_11_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_11_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_11_main_main_default.set_text_letter_space(0)
style_screen_drawing_rpm_11_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_11_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_11_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_11_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_11
screen_drawing_RPM_11.add_style(style_screen_drawing_rpm_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_10 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_10.set_pos(425,91)
screen_drawing_RPM_10.set_size(20,20)
screen_drawing_RPM_10.set_text("10")
screen_drawing_RPM_10.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_10.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_10_main_main_default
style_screen_drawing_rpm_10_main_main_default = lv.style_t()
style_screen_drawing_rpm_10_main_main_default.init()
style_screen_drawing_rpm_10_main_main_default.set_radius(0)
style_screen_drawing_rpm_10_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_10_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_10_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_10_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_10_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_10_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_10_main_main_default.set_text_letter_space(0)
style_screen_drawing_rpm_10_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_10_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_10_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_10_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_10
screen_drawing_RPM_10.add_style(style_screen_drawing_rpm_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_9 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_9.set_pos(390,88)
screen_drawing_RPM_9.set_size(20,20)
screen_drawing_RPM_9.set_text("9")
screen_drawing_RPM_9.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_9.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_9_main_main_default
style_screen_drawing_rpm_9_main_main_default = lv.style_t()
style_screen_drawing_rpm_9_main_main_default.init()
style_screen_drawing_rpm_9_main_main_default.set_radius(0)
style_screen_drawing_rpm_9_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_9_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_9_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_9_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_9_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_9_main_main_default.set_text_letter_space(1)
style_screen_drawing_rpm_9_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_9_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_9_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_9_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_9
screen_drawing_RPM_9.add_style(style_screen_drawing_rpm_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_8 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_8.set_pos(357,92)
screen_drawing_RPM_8.set_size(20,20)
screen_drawing_RPM_8.set_text("8")
screen_drawing_RPM_8.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_8.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_8_main_main_default
style_screen_drawing_rpm_8_main_main_default = lv.style_t()
style_screen_drawing_rpm_8_main_main_default.init()
style_screen_drawing_rpm_8_main_main_default.set_radius(0)
style_screen_drawing_rpm_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_8_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_8_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_8_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_8_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_8_main_main_default.set_text_letter_space(1)
style_screen_drawing_rpm_8_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_8_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_8_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_8_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_8
screen_drawing_RPM_8.add_style(style_screen_drawing_rpm_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_7 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_7.set_pos(325,106)
screen_drawing_RPM_7.set_size(20,20)
screen_drawing_RPM_7.set_text("7")
screen_drawing_RPM_7.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_7.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_7_main_main_default
style_screen_drawing_rpm_7_main_main_default = lv.style_t()
style_screen_drawing_rpm_7_main_main_default.init()
style_screen_drawing_rpm_7_main_main_default.set_radius(0)
style_screen_drawing_rpm_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_7_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_7_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_7_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_7_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_7_main_main_default.set_text_letter_space(2)
style_screen_drawing_rpm_7_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_7_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_7_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_7_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_7
screen_drawing_RPM_7.add_style(style_screen_drawing_rpm_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_6 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_6.set_pos(296,129)
screen_drawing_RPM_6.set_size(20,20)
screen_drawing_RPM_6.set_text("6")
screen_drawing_RPM_6.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_6.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_6_main_main_default
style_screen_drawing_rpm_6_main_main_default = lv.style_t()
style_screen_drawing_rpm_6_main_main_default.init()
style_screen_drawing_rpm_6_main_main_default.set_radius(0)
style_screen_drawing_rpm_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_6_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_6_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_6_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_6_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_6_main_main_default.set_text_letter_space(2)
style_screen_drawing_rpm_6_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_6_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_6_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_6_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_6
screen_drawing_RPM_6.add_style(style_screen_drawing_rpm_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_5 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_5.set_pos(278,153.8235294117647)
screen_drawing_RPM_5.set_size(20,20)
screen_drawing_RPM_5.set_text("5")
screen_drawing_RPM_5.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_5.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_5_main_main_default
style_screen_drawing_rpm_5_main_main_default = lv.style_t()
style_screen_drawing_rpm_5_main_main_default.init()
style_screen_drawing_rpm_5_main_main_default.set_radius(0)
style_screen_drawing_rpm_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_5_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_5_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_5_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_5_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_5_main_main_default.set_text_letter_space(2)
style_screen_drawing_rpm_5_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_5_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_5_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_5_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_5
screen_drawing_RPM_5.add_style(style_screen_drawing_rpm_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_4 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_4.set_pos(266,186.76470588235296)
screen_drawing_RPM_4.set_size(20,20)
screen_drawing_RPM_4.set_text("4")
screen_drawing_RPM_4.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_4.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_4_main_main_default
style_screen_drawing_rpm_4_main_main_default = lv.style_t()
style_screen_drawing_rpm_4_main_main_default.init()
style_screen_drawing_rpm_4_main_main_default.set_radius(0)
style_screen_drawing_rpm_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_4_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_4_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_4_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_4_main_main_default.set_text_letter_space(2)
style_screen_drawing_rpm_4_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_4_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_4_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_4_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_4
screen_drawing_RPM_4.add_style(style_screen_drawing_rpm_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_3 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_3.set_pos(262,220)
screen_drawing_RPM_3.set_size(20,20)
screen_drawing_RPM_3.set_text("3")
screen_drawing_RPM_3.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_3.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_3_main_main_default
style_screen_drawing_rpm_3_main_main_default = lv.style_t()
style_screen_drawing_rpm_3_main_main_default.init()
style_screen_drawing_rpm_3_main_main_default.set_radius(0)
style_screen_drawing_rpm_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_3_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_3_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_3_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_3_main_main_default.set_text_letter_space(1)
style_screen_drawing_rpm_3_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_3_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_3_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_3_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_3
screen_drawing_RPM_3.add_style(style_screen_drawing_rpm_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_2 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_2.set_pos(269,258)
screen_drawing_RPM_2.set_size(20,20)
screen_drawing_RPM_2.set_text("2")
screen_drawing_RPM_2.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_2_main_main_default
style_screen_drawing_rpm_2_main_main_default = lv.style_t()
style_screen_drawing_rpm_2_main_main_default.init()
style_screen_drawing_rpm_2_main_main_default.set_radius(0)
style_screen_drawing_rpm_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_2_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_2_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_2_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_2_main_main_default.set_text_letter_space(2)
style_screen_drawing_rpm_2_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_2_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_2_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_2_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_2
screen_drawing_RPM_2.add_style(style_screen_drawing_rpm_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_1 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_1.set_pos(283,286)
screen_drawing_RPM_1.set_size(20,20)
screen_drawing_RPM_1.set_text("1")
screen_drawing_RPM_1.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_1_main_main_default
style_screen_drawing_rpm_1_main_main_default = lv.style_t()
style_screen_drawing_rpm_1_main_main_default.init()
style_screen_drawing_rpm_1_main_main_default.set_radius(0)
style_screen_drawing_rpm_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_1_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_1_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_1_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_1_main_main_default.set_text_letter_space(2)
style_screen_drawing_rpm_1_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_1_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_1_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_1_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_1
screen_drawing_RPM_1.add_style(style_screen_drawing_rpm_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_0 = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_0.set_pos(294,308)
screen_drawing_RPM_0.set_size(20,20)
screen_drawing_RPM_0.set_text("0")
screen_drawing_RPM_0.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_0.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_0_main_main_default
style_screen_drawing_rpm_0_main_main_default = lv.style_t()
style_screen_drawing_rpm_0_main_main_default.init()
style_screen_drawing_rpm_0_main_main_default.set_radius(0)
style_screen_drawing_rpm_0_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_0_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_0_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_0_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_rpm_0_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_screen_drawing_rpm_0_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_drawing_rpm_0_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_0_main_main_default.set_text_letter_space(0)
style_screen_drawing_rpm_0_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_0_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_0_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_0_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_0
screen_drawing_RPM_0.add_style(style_screen_drawing_rpm_0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Gear_label = lv.label(screen_drawing_container_drawing)
screen_drawing_Gear_label.set_pos(350,238)
screen_drawing_Gear_label.set_size(100,32)
screen_drawing_Gear_label.set_text("Gear")
screen_drawing_Gear_label.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_Gear_label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_gear_label_main_main_default
style_screen_drawing_gear_label_main_main_default = lv.style_t()
style_screen_drawing_gear_label_main_main_default.init()
style_screen_drawing_gear_label_main_main_default.set_radius(0)
style_screen_drawing_gear_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_gear_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_gear_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_gear_label_main_main_default.set_bg_opa(0)
style_screen_drawing_gear_label_main_main_default.set_text_color(lv.color_make(0x90,0x89,0x89))
try:
    style_screen_drawing_gear_label_main_main_default.set_text_font(lv.font_simsun_14)
except AttributeError:
    try:
        style_screen_drawing_gear_label_main_main_default.set_text_font(lv.font_montserrat_14)
    except AttributeError:
        style_screen_drawing_gear_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_gear_label_main_main_default.set_text_letter_space(0)
style_screen_drawing_gear_label_main_main_default.set_pad_left(0)
style_screen_drawing_gear_label_main_main_default.set_pad_right(0)
style_screen_drawing_gear_label_main_main_default.set_pad_top(0)
style_screen_drawing_gear_label_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_Gear_label
screen_drawing_Gear_label.add_style(style_screen_drawing_gear_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_GEAR_CIRCLE = lv.img(screen_drawing_container_drawing)
screen_drawing_GEAR_CIRCLE.set_pos(333,191)
screen_drawing_GEAR_CIRCLE.set_size(134,74)
screen_drawing_GEAR_CIRCLE.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-631215812.png','rb') as f:
        screen_drawing_GEAR_CIRCLE_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-631215812.png')
    sys.exit()

screen_drawing_GEAR_CIRCLE_img = lv.img_dsc_t({
  'data_size': len(screen_drawing_GEAR_CIRCLE_img_data),
  'header': {'always_zero': 0, 'w': 134, 'h': 74, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_drawing_GEAR_CIRCLE_img_data
})

screen_drawing_GEAR_CIRCLE.set_src(screen_drawing_GEAR_CIRCLE_img)
screen_drawing_GEAR_CIRCLE.set_pivot(0,0)
screen_drawing_GEAR_CIRCLE.set_angle(0)
# create style style_screen_drawing_gear_circle_main_main_default
style_screen_drawing_gear_circle_main_main_default = lv.style_t()
style_screen_drawing_gear_circle_main_main_default.init()
style_screen_drawing_gear_circle_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_drawing_gear_circle_main_main_default.set_img_recolor_opa(0)
style_screen_drawing_gear_circle_main_main_default.set_img_opa(42)

# add style for screen_drawing_GEAR_CIRCLE
screen_drawing_GEAR_CIRCLE.add_style(style_screen_drawing_gear_circle_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Gear_value_label = lv.label(screen_drawing_container_drawing)
screen_drawing_Gear_value_label.set_pos(349,157)
screen_drawing_Gear_value_label.set_size(100,100)
screen_drawing_Gear_value_label.set_text("2")
screen_drawing_Gear_value_label.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_Gear_value_label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_gear_value_label_main_main_default
style_screen_drawing_gear_value_label_main_main_default = lv.style_t()
style_screen_drawing_gear_value_label_main_main_default.init()
style_screen_drawing_gear_value_label_main_main_default.set_radius(0)
style_screen_drawing_gear_value_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_gear_value_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_gear_value_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_gear_value_label_main_main_default.set_bg_opa(0)
style_screen_drawing_gear_value_label_main_main_default.set_text_color(lv.color_make(0xb2,0xae,0xae))
try:
    style_screen_drawing_gear_value_label_main_main_default.set_text_font(lv.font_simsun_80)
except AttributeError:
    try:
        style_screen_drawing_gear_value_label_main_main_default.set_text_font(lv.font_montserrat_80)
    except AttributeError:
        style_screen_drawing_gear_value_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_gear_value_label_main_main_default.set_text_letter_space(0)
style_screen_drawing_gear_value_label_main_main_default.set_pad_left(0)
style_screen_drawing_gear_value_label_main_main_default.set_pad_right(0)
style_screen_drawing_gear_value_label_main_main_default.set_pad_top(0)
style_screen_drawing_gear_value_label_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_Gear_value_label
screen_drawing_Gear_value_label.add_style(style_screen_drawing_gear_value_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_speed_value_label = lv.label(screen_drawing_container_drawing)
screen_drawing_speed_value_label.set_pos(518,190)
screen_drawing_speed_value_label.set_size(262,90)
screen_drawing_speed_value_label.set_text("865")
screen_drawing_speed_value_label.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_speed_value_label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_speed_value_label_main_main_default
style_screen_drawing_speed_value_label_main_main_default = lv.style_t()
style_screen_drawing_speed_value_label_main_main_default.init()
style_screen_drawing_speed_value_label_main_main_default.set_radius(0)
style_screen_drawing_speed_value_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_speed_value_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_speed_value_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_speed_value_label_main_main_default.set_bg_opa(0)
style_screen_drawing_speed_value_label_main_main_default.set_text_color(lv.color_make(0x00,0x00,0xff))
try:
    style_screen_drawing_speed_value_label_main_main_default.set_text_font(lv.font_DSEG7Classic_Regular_80)
except AttributeError:
    try:
        style_screen_drawing_speed_value_label_main_main_default.set_text_font(lv.font_montserrat_80)
    except AttributeError:
        style_screen_drawing_speed_value_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_speed_value_label_main_main_default.set_text_letter_space(0)
style_screen_drawing_speed_value_label_main_main_default.set_pad_left(0)
style_screen_drawing_speed_value_label_main_main_default.set_pad_right(0)
style_screen_drawing_speed_value_label_main_main_default.set_pad_top(0)
style_screen_drawing_speed_value_label_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_speed_value_label
screen_drawing_speed_value_label.add_style(style_screen_drawing_speed_value_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_speed_unit_label = lv.label(screen_drawing_container_drawing)
screen_drawing_speed_unit_label.set_pos(596.6666666666667,274)
screen_drawing_speed_unit_label.set_size(100,32)
screen_drawing_speed_unit_label.set_text("km/h")
screen_drawing_speed_unit_label.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_speed_unit_label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_speed_unit_label_main_main_default
style_screen_drawing_speed_unit_label_main_main_default = lv.style_t()
style_screen_drawing_speed_unit_label_main_main_default.init()
style_screen_drawing_speed_unit_label_main_main_default.set_radius(0)
style_screen_drawing_speed_unit_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_speed_unit_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_speed_unit_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_speed_unit_label_main_main_default.set_bg_opa(0)
style_screen_drawing_speed_unit_label_main_main_default.set_text_color(lv.color_make(0x90,0x89,0x89))
try:
    style_screen_drawing_speed_unit_label_main_main_default.set_text_font(lv.font_simsun_15)
except AttributeError:
    try:
        style_screen_drawing_speed_unit_label_main_main_default.set_text_font(lv.font_montserrat_15)
    except AttributeError:
        style_screen_drawing_speed_unit_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_speed_unit_label_main_main_default.set_text_letter_space(0)
style_screen_drawing_speed_unit_label_main_main_default.set_pad_left(0)
style_screen_drawing_speed_unit_label_main_main_default.set_pad_right(0)
style_screen_drawing_speed_unit_label_main_main_default.set_pad_top(0)
style_screen_drawing_speed_unit_label_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_speed_unit_label
screen_drawing_speed_unit_label.add_style(style_screen_drawing_speed_unit_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_value_label = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_value_label.set_pos(15,190)
screen_drawing_RPM_value_label.set_size(262,90)
screen_drawing_RPM_value_label.set_text("450")
screen_drawing_RPM_value_label.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_value_label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_value_label_main_main_default
style_screen_drawing_rpm_value_label_main_main_default = lv.style_t()
style_screen_drawing_rpm_value_label_main_main_default.init()
style_screen_drawing_rpm_value_label_main_main_default.set_radius(0)
style_screen_drawing_rpm_value_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_value_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_value_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_value_label_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_value_label_main_main_default.set_text_color(lv.color_make(0x00,0x00,0xff))
try:
    style_screen_drawing_rpm_value_label_main_main_default.set_text_font(lv.font_DSEG7Classic_Regular_80)
except AttributeError:
    try:
        style_screen_drawing_rpm_value_label_main_main_default.set_text_font(lv.font_montserrat_80)
    except AttributeError:
        style_screen_drawing_rpm_value_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_value_label_main_main_default.set_text_letter_space(0)
style_screen_drawing_rpm_value_label_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_value_label_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_value_label_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_value_label_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_value_label
screen_drawing_RPM_value_label.add_style(style_screen_drawing_rpm_value_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_RPM_UNIT_label = lv.label(screen_drawing_container_drawing)
screen_drawing_RPM_UNIT_label.set_pos(95,274)
screen_drawing_RPM_UNIT_label.set_size(100,32)
screen_drawing_RPM_UNIT_label.set_text("x100 rpm")
screen_drawing_RPM_UNIT_label.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_RPM_UNIT_label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_rpm_unit_label_main_main_default
style_screen_drawing_rpm_unit_label_main_main_default = lv.style_t()
style_screen_drawing_rpm_unit_label_main_main_default.init()
style_screen_drawing_rpm_unit_label_main_main_default.set_radius(0)
style_screen_drawing_rpm_unit_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_unit_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_rpm_unit_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_rpm_unit_label_main_main_default.set_bg_opa(0)
style_screen_drawing_rpm_unit_label_main_main_default.set_text_color(lv.color_make(0x90,0x89,0x89))
try:
    style_screen_drawing_rpm_unit_label_main_main_default.set_text_font(lv.font_simsun_15)
except AttributeError:
    try:
        style_screen_drawing_rpm_unit_label_main_main_default.set_text_font(lv.font_montserrat_15)
    except AttributeError:
        style_screen_drawing_rpm_unit_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_rpm_unit_label_main_main_default.set_text_letter_space(0)
style_screen_drawing_rpm_unit_label_main_main_default.set_pad_left(0)
style_screen_drawing_rpm_unit_label_main_main_default.set_pad_right(0)
style_screen_drawing_rpm_unit_label_main_main_default.set_pad_top(0)
style_screen_drawing_rpm_unit_label_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_RPM_UNIT_label
screen_drawing_RPM_UNIT_label.add_style(style_screen_drawing_rpm_unit_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Logo_drawing = lv.img(screen_drawing_container_drawing)
screen_drawing_Logo_drawing.set_pos(340,4)
screen_drawing_Logo_drawing.set_size(113,63)
screen_drawing_Logo_drawing.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp458845107.png','rb') as f:
        screen_drawing_Logo_drawing_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp458845107.png')
    sys.exit()

screen_drawing_Logo_drawing_img = lv.img_dsc_t({
  'data_size': len(screen_drawing_Logo_drawing_img_data),
  'header': {'always_zero': 0, 'w': 113, 'h': 63, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_drawing_Logo_drawing_img_data
})

screen_drawing_Logo_drawing.set_src(screen_drawing_Logo_drawing_img)
screen_drawing_Logo_drawing.set_pivot(0,0)
screen_drawing_Logo_drawing.set_angle(0)
# create style style_screen_drawing_logo_drawing_main_main_default
style_screen_drawing_logo_drawing_main_main_default = lv.style_t()
style_screen_drawing_logo_drawing_main_main_default.init()
style_screen_drawing_logo_drawing_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_drawing_logo_drawing_main_main_default.set_img_recolor_opa(0)
style_screen_drawing_logo_drawing_main_main_default.set_img_opa(67)

# add style for screen_drawing_Logo_drawing
screen_drawing_Logo_drawing.add_style(style_screen_drawing_logo_drawing_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Time_level_drawing_1 = lv.label(screen_drawing_container_drawing)
screen_drawing_Time_level_drawing_1.set_pos(765,9)
screen_drawing_Time_level_drawing_1.set_size(25,26)
screen_drawing_Time_level_drawing_1.set_text("28")
screen_drawing_Time_level_drawing_1.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_Time_level_drawing_1.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_screen_drawing_time_level_drawing_1_main_main_default
style_screen_drawing_time_level_drawing_1_main_main_default = lv.style_t()
style_screen_drawing_time_level_drawing_1_main_main_default.init()
style_screen_drawing_time_level_drawing_1_main_main_default.set_radius(0)
style_screen_drawing_time_level_drawing_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_time_level_drawing_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_time_level_drawing_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_time_level_drawing_1_main_main_default.set_bg_opa(0)
style_screen_drawing_time_level_drawing_1_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_time_level_drawing_1_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_drawing_time_level_drawing_1_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_drawing_time_level_drawing_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_time_level_drawing_1_main_main_default.set_text_letter_space(2)
style_screen_drawing_time_level_drawing_1_main_main_default.set_pad_left(0)
style_screen_drawing_time_level_drawing_1_main_main_default.set_pad_right(0)
style_screen_drawing_time_level_drawing_1_main_main_default.set_pad_top(0)
style_screen_drawing_time_level_drawing_1_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_Time_level_drawing_1
screen_drawing_Time_level_drawing_1.add_style(style_screen_drawing_time_level_drawing_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Time_level_drawing_0 = lv.label(screen_drawing_container_drawing)
screen_drawing_Time_level_drawing_0.set_pos(756,9)
screen_drawing_Time_level_drawing_0.set_size(11,24)
screen_drawing_Time_level_drawing_0.set_text(":")
screen_drawing_Time_level_drawing_0.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_Time_level_drawing_0.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_screen_drawing_time_level_drawing_0_main_main_default
style_screen_drawing_time_level_drawing_0_main_main_default = lv.style_t()
style_screen_drawing_time_level_drawing_0_main_main_default.init()
style_screen_drawing_time_level_drawing_0_main_main_default.set_radius(0)
style_screen_drawing_time_level_drawing_0_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_time_level_drawing_0_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_time_level_drawing_0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_time_level_drawing_0_main_main_default.set_bg_opa(0)
style_screen_drawing_time_level_drawing_0_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_time_level_drawing_0_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_drawing_time_level_drawing_0_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_drawing_time_level_drawing_0_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_time_level_drawing_0_main_main_default.set_text_letter_space(1)
style_screen_drawing_time_level_drawing_0_main_main_default.set_pad_left(0)
style_screen_drawing_time_level_drawing_0_main_main_default.set_pad_right(0)
style_screen_drawing_time_level_drawing_0_main_main_default.set_pad_top(0)
style_screen_drawing_time_level_drawing_0_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_Time_level_drawing_0
screen_drawing_Time_level_drawing_0.add_style(style_screen_drawing_time_level_drawing_0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Time_level_drawing = lv.label(screen_drawing_container_drawing)
screen_drawing_Time_level_drawing.set_pos(716,9)
screen_drawing_Time_level_drawing.set_size(61,31)
screen_drawing_Time_level_drawing.set_text("10")
screen_drawing_Time_level_drawing.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_Time_level_drawing.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_time_level_drawing_main_main_default
style_screen_drawing_time_level_drawing_main_main_default = lv.style_t()
style_screen_drawing_time_level_drawing_main_main_default.init()
style_screen_drawing_time_level_drawing_main_main_default.set_radius(0)
style_screen_drawing_time_level_drawing_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_time_level_drawing_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_time_level_drawing_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_time_level_drawing_main_main_default.set_bg_opa(0)
style_screen_drawing_time_level_drawing_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_time_level_drawing_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_drawing_time_level_drawing_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_drawing_time_level_drawing_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_time_level_drawing_main_main_default.set_text_letter_space(1)
style_screen_drawing_time_level_drawing_main_main_default.set_pad_left(0)
style_screen_drawing_time_level_drawing_main_main_default.set_pad_right(0)
style_screen_drawing_time_level_drawing_main_main_default.set_pad_top(0)
style_screen_drawing_time_level_drawing_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_Time_level_drawing
screen_drawing_Time_level_drawing.add_style(style_screen_drawing_time_level_drawing_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Date_Label_drawing_2 = lv.label(screen_drawing_container_drawing)
screen_drawing_Date_Label_drawing_2.set_pos(92,9)
screen_drawing_Date_Label_drawing_2.set_size(53,24)
screen_drawing_Date_Label_drawing_2.set_text("2022")
screen_drawing_Date_Label_drawing_2.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_Date_Label_drawing_2.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_screen_drawing_date_label_drawing_2_main_main_default
style_screen_drawing_date_label_drawing_2_main_main_default = lv.style_t()
style_screen_drawing_date_label_drawing_2_main_main_default.init()
style_screen_drawing_date_label_drawing_2_main_main_default.set_radius(0)
style_screen_drawing_date_label_drawing_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_date_label_drawing_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_date_label_drawing_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_date_label_drawing_2_main_main_default.set_bg_opa(0)
style_screen_drawing_date_label_drawing_2_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_date_label_drawing_2_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_drawing_date_label_drawing_2_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_drawing_date_label_drawing_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_date_label_drawing_2_main_main_default.set_text_letter_space(2)
style_screen_drawing_date_label_drawing_2_main_main_default.set_pad_left(0)
style_screen_drawing_date_label_drawing_2_main_main_default.set_pad_right(0)
style_screen_drawing_date_label_drawing_2_main_main_default.set_pad_top(0)
style_screen_drawing_date_label_drawing_2_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_Date_Label_drawing_2
screen_drawing_Date_Label_drawing_2.add_style(style_screen_drawing_date_label_drawing_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Date_Label_drawing_1 = lv.label(screen_drawing_container_drawing)
screen_drawing_Date_Label_drawing_1.set_pos(82,9)
screen_drawing_Date_Label_drawing_1.set_size(7,19)
screen_drawing_Date_Label_drawing_1.set_text(",")
screen_drawing_Date_Label_drawing_1.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_Date_Label_drawing_1.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_screen_drawing_date_label_drawing_1_main_main_default
style_screen_drawing_date_label_drawing_1_main_main_default = lv.style_t()
style_screen_drawing_date_label_drawing_1_main_main_default.init()
style_screen_drawing_date_label_drawing_1_main_main_default.set_radius(0)
style_screen_drawing_date_label_drawing_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_date_label_drawing_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_date_label_drawing_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_date_label_drawing_1_main_main_default.set_bg_opa(0)
style_screen_drawing_date_label_drawing_1_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_date_label_drawing_1_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_drawing_date_label_drawing_1_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_drawing_date_label_drawing_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_date_label_drawing_1_main_main_default.set_text_letter_space(1)
style_screen_drawing_date_label_drawing_1_main_main_default.set_pad_left(0)
style_screen_drawing_date_label_drawing_1_main_main_default.set_pad_right(0)
style_screen_drawing_date_label_drawing_1_main_main_default.set_pad_top(0)
style_screen_drawing_date_label_drawing_1_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_Date_Label_drawing_1
screen_drawing_Date_Label_drawing_1.add_style(style_screen_drawing_date_label_drawing_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Date_Label_drawing_0 = lv.label(screen_drawing_container_drawing)
screen_drawing_Date_Label_drawing_0.set_pos(58,9)
screen_drawing_Date_Label_drawing_0.set_size(28,22)
screen_drawing_Date_Label_drawing_0.set_text("24")
screen_drawing_Date_Label_drawing_0.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_Date_Label_drawing_0.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_screen_drawing_date_label_drawing_0_main_main_default
style_screen_drawing_date_label_drawing_0_main_main_default = lv.style_t()
style_screen_drawing_date_label_drawing_0_main_main_default.init()
style_screen_drawing_date_label_drawing_0_main_main_default.set_radius(0)
style_screen_drawing_date_label_drawing_0_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_date_label_drawing_0_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_date_label_drawing_0_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_date_label_drawing_0_main_main_default.set_bg_opa(0)
style_screen_drawing_date_label_drawing_0_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_date_label_drawing_0_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_drawing_date_label_drawing_0_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_drawing_date_label_drawing_0_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_date_label_drawing_0_main_main_default.set_text_letter_space(1)
style_screen_drawing_date_label_drawing_0_main_main_default.set_pad_left(0)
style_screen_drawing_date_label_drawing_0_main_main_default.set_pad_right(0)
style_screen_drawing_date_label_drawing_0_main_main_default.set_pad_top(0)
style_screen_drawing_date_label_drawing_0_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_Date_Label_drawing_0
screen_drawing_Date_Label_drawing_0.add_style(style_screen_drawing_date_label_drawing_0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Date_Label_drawing = lv.label(screen_drawing_container_drawing)
screen_drawing_Date_Label_drawing.set_pos(18,9)
screen_drawing_Date_Label_drawing.set_size(40,23)
screen_drawing_Date_Label_drawing.set_text("May")
screen_drawing_Date_Label_drawing.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_Date_Label_drawing.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_screen_drawing_date_label_drawing_main_main_default
style_screen_drawing_date_label_drawing_main_main_default = lv.style_t()
style_screen_drawing_date_label_drawing_main_main_default.init()
style_screen_drawing_date_label_drawing_main_main_default.set_radius(0)
style_screen_drawing_date_label_drawing_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_date_label_drawing_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_date_label_drawing_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_date_label_drawing_main_main_default.set_bg_opa(0)
style_screen_drawing_date_label_drawing_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_date_label_drawing_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_screen_drawing_date_label_drawing_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_drawing_date_label_drawing_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_date_label_drawing_main_main_default.set_text_letter_space(1)
style_screen_drawing_date_label_drawing_main_main_default.set_pad_left(0)
style_screen_drawing_date_label_drawing_main_main_default.set_pad_right(0)
style_screen_drawing_date_label_drawing_main_main_default.set_pad_top(0)
style_screen_drawing_date_label_drawing_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_Date_Label_drawing
screen_drawing_Date_Label_drawing.add_style(style_screen_drawing_date_label_drawing_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_drawing_Guage_1 = lv.img(screen_drawing_container_drawing)
screen_drawing_drawing_Guage_1.set_pos(250,76)
screen_drawing_drawing_Guage_1.set_size(300,300)
screen_drawing_drawing_Guage_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1890479073.png','rb') as f:
        screen_drawing_drawing_Guage_1_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1890479073.png')
    sys.exit()

screen_drawing_drawing_Guage_1_img = lv.img_dsc_t({
  'data_size': len(screen_drawing_drawing_Guage_1_img_data),
  'header': {'always_zero': 0, 'w': 300, 'h': 300, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_drawing_drawing_Guage_1_img_data
})

screen_drawing_drawing_Guage_1.set_src(screen_drawing_drawing_Guage_1_img)
screen_drawing_drawing_Guage_1.set_pivot(0,0)
screen_drawing_drawing_Guage_1.set_angle(0)
# create style style_screen_drawing_drawing_guage_1_main_main_default
style_screen_drawing_drawing_guage_1_main_main_default = lv.style_t()
style_screen_drawing_drawing_guage_1_main_main_default.init()
style_screen_drawing_drawing_guage_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_drawing_drawing_guage_1_main_main_default.set_img_recolor_opa(0)
style_screen_drawing_drawing_guage_1_main_main_default.set_img_opa(255)

# add style for screen_drawing_drawing_Guage_1
screen_drawing_drawing_Guage_1.add_style(style_screen_drawing_drawing_guage_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_cluster_image = lv.img(screen_drawing_container_drawing)
screen_drawing_cluster_image.set_pos(4,60)
screen_drawing_cluster_image.set_size(793,327)
screen_drawing_cluster_image.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1722740508.png','rb') as f:
        screen_drawing_cluster_image_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1722740508.png')
    sys.exit()

screen_drawing_cluster_image_img = lv.img_dsc_t({
  'data_size': len(screen_drawing_cluster_image_img_data),
  'header': {'always_zero': 0, 'w': 793, 'h': 327, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_drawing_cluster_image_img_data
})

screen_drawing_cluster_image.set_src(screen_drawing_cluster_image_img)
screen_drawing_cluster_image.set_pivot(0,0)
screen_drawing_cluster_image.set_angle(0)
# create style style_screen_drawing_cluster_image_main_main_default
style_screen_drawing_cluster_image_main_main_default = lv.style_t()
style_screen_drawing_cluster_image_main_main_default.init()
style_screen_drawing_cluster_image_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_drawing_cluster_image_main_main_default.set_img_recolor_opa(0)
style_screen_drawing_cluster_image_main_main_default.set_img_opa(255)

# add style for screen_drawing_cluster_image
screen_drawing_cluster_image.add_style(style_screen_drawing_cluster_image_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_arc_indicator = lv.arc(screen_drawing_container_drawing)
screen_drawing_arc_indicator.set_pos(264,86)
screen_drawing_arc_indicator.set_size(275,275)
screen_drawing_arc_indicator.set_bg_angles(135, 45)
screen_drawing_arc_indicator.set_angles(135, 45)
screen_drawing_arc_indicator.set_rotation(0)
screen_drawing_arc_indicator.set_style_pad_top(20, lv.PART.MAIN | lv.STATE.DEFAULT)
screen_drawing_arc_indicator.set_style_pad_bottom(20, lv.PART.MAIN | lv.STATE.DEFAULT)
screen_drawing_arc_indicator.set_style_pad_left(20, lv.PART.MAIN | lv.STATE.DEFAULT)
screen_drawing_arc_indicator.set_style_pad_right(20, lv.PART.MAIN | lv.STATE.DEFAULT)
screen_drawing_arc_indicator.set_style_arc_rounded(False, lv.PART.INDICATOR | lv.STATE.DEFAULT)
screen_drawing_arc_indicator.set_style_arc_rounded(False, lv.PART.MAIN | lv.STATE.DEFAULT)
# create style style_screen_drawing_arc_indicator_main_main_default
style_screen_drawing_arc_indicator_main_main_default = lv.style_t()
style_screen_drawing_arc_indicator_main_main_default.init()
style_screen_drawing_arc_indicator_main_main_default.set_bg_color(lv.color_make(0xf6,0xf6,0xf6))
style_screen_drawing_arc_indicator_main_main_default.set_bg_grad_color(lv.color_make(0xf6,0xf6,0xf6))
style_screen_drawing_arc_indicator_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_arc_indicator_main_main_default.set_bg_opa(0)
style_screen_drawing_arc_indicator_main_main_default.set_border_width(0)
style_screen_drawing_arc_indicator_main_main_default.set_arc_color(lv.color_make(0xe6,0xe6,0xe6))
style_screen_drawing_arc_indicator_main_main_default.set_arc_width(12)

# add style for screen_drawing_arc_indicator
screen_drawing_arc_indicator.add_style(style_screen_drawing_arc_indicator_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_drawing_arc_indicator_main_indicator_default
style_screen_drawing_arc_indicator_main_indicator_default = lv.style_t()
style_screen_drawing_arc_indicator_main_indicator_default.init()
style_screen_drawing_arc_indicator_main_indicator_default.set_arc_color(lv.color_make(0xa8,0x10,0x1f))
style_screen_drawing_arc_indicator_main_indicator_default.set_arc_width(12)

# add style for screen_drawing_arc_indicator
screen_drawing_arc_indicator.add_style(style_screen_drawing_arc_indicator_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_screen_drawing_arc_indicator_main_knob_default
style_screen_drawing_arc_indicator_main_knob_default = lv.style_t()
style_screen_drawing_arc_indicator_main_knob_default.init()
style_screen_drawing_arc_indicator_main_knob_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_arc_indicator_main_knob_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_arc_indicator_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_arc_indicator_main_knob_default.set_bg_opa(81)
style_screen_drawing_arc_indicator_main_knob_default.set_pad_all(5)

# add style for screen_drawing_arc_indicator
screen_drawing_arc_indicator.add_style(style_screen_drawing_arc_indicator_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

screen_drawing_drawing_Guage_2 = lv.img(screen_drawing_container_drawing)
screen_drawing_drawing_Guage_2.set_pos(284,106)
screen_drawing_drawing_Guage_2.set_size(233,223)
screen_drawing_drawing_Guage_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-867939743.png','rb') as f:
        screen_drawing_drawing_Guage_2_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-867939743.png')
    sys.exit()

screen_drawing_drawing_Guage_2_img = lv.img_dsc_t({
  'data_size': len(screen_drawing_drawing_Guage_2_img_data),
  'header': {'always_zero': 0, 'w': 233, 'h': 223, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_drawing_drawing_Guage_2_img_data
})

screen_drawing_drawing_Guage_2.set_src(screen_drawing_drawing_Guage_2_img)
screen_drawing_drawing_Guage_2.set_pivot(0,0)
screen_drawing_drawing_Guage_2.set_angle(0)
# create style style_screen_drawing_drawing_guage_2_main_main_default
style_screen_drawing_drawing_guage_2_main_main_default = lv.style_t()
style_screen_drawing_drawing_guage_2_main_main_default.init()
style_screen_drawing_drawing_guage_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_drawing_drawing_guage_2_main_main_default.set_img_recolor_opa(0)
style_screen_drawing_drawing_guage_2_main_main_default.set_img_opa(255)

# add style for screen_drawing_drawing_Guage_2
screen_drawing_drawing_Guage_2.add_style(style_screen_drawing_drawing_guage_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_FUEL_image = lv.img(screen_drawing_container_drawing)
screen_drawing_FUEL_image.set_pos(390,325)
screen_drawing_FUEL_image.set_size(30,30)
screen_drawing_FUEL_image.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1631158980.png','rb') as f:
        screen_drawing_FUEL_image_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1631158980.png')
    sys.exit()

screen_drawing_FUEL_image_img = lv.img_dsc_t({
  'data_size': len(screen_drawing_FUEL_image_img_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 30, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_drawing_FUEL_image_img_data
})

screen_drawing_FUEL_image.set_src(screen_drawing_FUEL_image_img)
screen_drawing_FUEL_image.set_pivot(0,0)
screen_drawing_FUEL_image.set_angle(0)
# create style style_screen_drawing_fuel_image_main_main_default
style_screen_drawing_fuel_image_main_main_default = lv.style_t()
style_screen_drawing_fuel_image_main_main_default.init()
style_screen_drawing_fuel_image_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_drawing_fuel_image_main_main_default.set_img_recolor_opa(0)
style_screen_drawing_fuel_image_main_main_default.set_img_opa(255)

# add style for screen_drawing_FUEL_image
screen_drawing_FUEL_image.add_style(style_screen_drawing_fuel_image_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_FUEL_Empty_label = lv.label(screen_drawing_container_drawing)
screen_drawing_FUEL_Empty_label.set_pos(311,315)
screen_drawing_FUEL_Empty_label.set_size(20,20)
screen_drawing_FUEL_Empty_label.set_text("E")
screen_drawing_FUEL_Empty_label.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_FUEL_Empty_label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_fuel_empty_label_main_main_default
style_screen_drawing_fuel_empty_label_main_main_default = lv.style_t()
style_screen_drawing_fuel_empty_label_main_main_default.init()
style_screen_drawing_fuel_empty_label_main_main_default.set_radius(0)
style_screen_drawing_fuel_empty_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_fuel_empty_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_fuel_empty_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_fuel_empty_label_main_main_default.set_bg_opa(0)
style_screen_drawing_fuel_empty_label_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_fuel_empty_label_main_main_default.set_text_font(lv.font_simsun_14)
except AttributeError:
    try:
        style_screen_drawing_fuel_empty_label_main_main_default.set_text_font(lv.font_montserrat_14)
    except AttributeError:
        style_screen_drawing_fuel_empty_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_fuel_empty_label_main_main_default.set_text_letter_space(2)
style_screen_drawing_fuel_empty_label_main_main_default.set_pad_left(0)
style_screen_drawing_fuel_empty_label_main_main_default.set_pad_right(0)
style_screen_drawing_fuel_empty_label_main_main_default.set_pad_top(0)
style_screen_drawing_fuel_empty_label_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_FUEL_Empty_label
screen_drawing_FUEL_Empty_label.add_style(style_screen_drawing_fuel_empty_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_FUEL_Full_label = lv.label(screen_drawing_container_drawing)
screen_drawing_FUEL_Full_label.set_pos(474.28571428571433,314.2857142857143)
screen_drawing_FUEL_Full_label.set_size(20,20)
screen_drawing_FUEL_Full_label.set_text("F")
screen_drawing_FUEL_Full_label.set_long_mode(lv.label.LONG.WRAP)
screen_drawing_FUEL_Full_label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_drawing_fuel_full_label_main_main_default
style_screen_drawing_fuel_full_label_main_main_default = lv.style_t()
style_screen_drawing_fuel_full_label_main_main_default.init()
style_screen_drawing_fuel_full_label_main_main_default.set_radius(0)
style_screen_drawing_fuel_full_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_fuel_full_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_fuel_full_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_fuel_full_label_main_main_default.set_bg_opa(0)
style_screen_drawing_fuel_full_label_main_main_default.set_text_color(lv.color_make(0xf8,0xf7,0xf7))
try:
    style_screen_drawing_fuel_full_label_main_main_default.set_text_font(lv.font_simsun_14)
except AttributeError:
    try:
        style_screen_drawing_fuel_full_label_main_main_default.set_text_font(lv.font_montserrat_14)
    except AttributeError:
        style_screen_drawing_fuel_full_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_drawing_fuel_full_label_main_main_default.set_text_letter_space(1)
style_screen_drawing_fuel_full_label_main_main_default.set_pad_left(0)
style_screen_drawing_fuel_full_label_main_main_default.set_pad_right(0)
style_screen_drawing_fuel_full_label_main_main_default.set_pad_top(0)
style_screen_drawing_fuel_full_label_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_FUEL_Full_label
screen_drawing_FUEL_Full_label.add_style(style_screen_drawing_fuel_full_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Red_fuel_arc = lv.arc(screen_drawing_container_drawing)
screen_drawing_Red_fuel_arc.set_pos(260,92)
screen_drawing_Red_fuel_arc.set_size(280,280)
screen_drawing_Red_fuel_arc.set_bg_angles(111, 132)
screen_drawing_Red_fuel_arc.set_angles(111, 132)
screen_drawing_Red_fuel_arc.set_rotation(0)
screen_drawing_Red_fuel_arc.set_style_pad_top(0, lv.PART.MAIN | lv.STATE.DEFAULT)
screen_drawing_Red_fuel_arc.set_style_pad_bottom(0, lv.PART.MAIN | lv.STATE.DEFAULT)
screen_drawing_Red_fuel_arc.set_style_pad_left(0, lv.PART.MAIN | lv.STATE.DEFAULT)
screen_drawing_Red_fuel_arc.set_style_pad_right(0, lv.PART.MAIN | lv.STATE.DEFAULT)
screen_drawing_Red_fuel_arc.set_style_arc_rounded(False, lv.PART.INDICATOR | lv.STATE.DEFAULT)
screen_drawing_Red_fuel_arc.set_style_arc_rounded(False, lv.PART.MAIN | lv.STATE.DEFAULT)
# create style style_screen_drawing_red_fuel_arc_main_main_default
style_screen_drawing_red_fuel_arc_main_main_default = lv.style_t()
style_screen_drawing_red_fuel_arc_main_main_default.init()
style_screen_drawing_red_fuel_arc_main_main_default.set_bg_color(lv.color_make(0xf6,0xf6,0xf6))
style_screen_drawing_red_fuel_arc_main_main_default.set_bg_grad_color(lv.color_make(0xf6,0xf6,0xf6))
style_screen_drawing_red_fuel_arc_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_red_fuel_arc_main_main_default.set_bg_opa(0)
style_screen_drawing_red_fuel_arc_main_main_default.set_border_width(0)
style_screen_drawing_red_fuel_arc_main_main_default.set_arc_color(lv.color_make(0xe6,0xe6,0xe6))
style_screen_drawing_red_fuel_arc_main_main_default.set_arc_width(10)

# add style for screen_drawing_Red_fuel_arc
screen_drawing_Red_fuel_arc.add_style(style_screen_drawing_red_fuel_arc_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_drawing_red_fuel_arc_main_indicator_default
style_screen_drawing_red_fuel_arc_main_indicator_default = lv.style_t()
style_screen_drawing_red_fuel_arc_main_indicator_default.init()
style_screen_drawing_red_fuel_arc_main_indicator_default.set_arc_color(lv.color_make(0xa8,0x10,0x1f))
style_screen_drawing_red_fuel_arc_main_indicator_default.set_arc_width(10)

# add style for screen_drawing_Red_fuel_arc
screen_drawing_Red_fuel_arc.add_style(style_screen_drawing_red_fuel_arc_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_screen_drawing_red_fuel_arc_main_knob_default
style_screen_drawing_red_fuel_arc_main_knob_default = lv.style_t()
style_screen_drawing_red_fuel_arc_main_knob_default.init()
style_screen_drawing_red_fuel_arc_main_knob_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_red_fuel_arc_main_knob_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_red_fuel_arc_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_red_fuel_arc_main_knob_default.set_bg_opa(0)
style_screen_drawing_red_fuel_arc_main_knob_default.set_pad_all(5)

# add style for screen_drawing_Red_fuel_arc
screen_drawing_Red_fuel_arc.add_style(style_screen_drawing_red_fuel_arc_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

screen_drawing_Green_fuel_arc = lv.arc(screen_drawing_container_drawing)
screen_drawing_Green_fuel_arc.set_pos(260,92)
screen_drawing_Green_fuel_arc.set_size(280,280)
screen_drawing_Green_fuel_arc.set_bg_angles(46, 111)
screen_drawing_Green_fuel_arc.set_angles(46, 111)
screen_drawing_Green_fuel_arc.set_rotation(0)
screen_drawing_Green_fuel_arc.set_style_pad_top(0, lv.PART.MAIN | lv.STATE.DEFAULT)
screen_drawing_Green_fuel_arc.set_style_pad_bottom(0, lv.PART.MAIN | lv.STATE.DEFAULT)
screen_drawing_Green_fuel_arc.set_style_pad_left(0, lv.PART.MAIN | lv.STATE.DEFAULT)
screen_drawing_Green_fuel_arc.set_style_pad_right(0, lv.PART.MAIN | lv.STATE.DEFAULT)
screen_drawing_Green_fuel_arc.set_style_arc_rounded(False, lv.PART.INDICATOR | lv.STATE.DEFAULT)
screen_drawing_Green_fuel_arc.set_style_arc_rounded(False, lv.PART.MAIN | lv.STATE.DEFAULT)
# create style style_screen_drawing_green_fuel_arc_main_main_default
style_screen_drawing_green_fuel_arc_main_main_default = lv.style_t()
style_screen_drawing_green_fuel_arc_main_main_default.init()
style_screen_drawing_green_fuel_arc_main_main_default.set_bg_color(lv.color_make(0x11,0x12,0x12))
style_screen_drawing_green_fuel_arc_main_main_default.set_bg_grad_color(lv.color_make(0xf6,0xf6,0xf6))
style_screen_drawing_green_fuel_arc_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_green_fuel_arc_main_main_default.set_bg_opa(0)
style_screen_drawing_green_fuel_arc_main_main_default.set_border_width(0)
style_screen_drawing_green_fuel_arc_main_main_default.set_arc_color(lv.color_make(0x11,0x12,0x12))
style_screen_drawing_green_fuel_arc_main_main_default.set_arc_width(12)

# add style for screen_drawing_Green_fuel_arc
screen_drawing_Green_fuel_arc.add_style(style_screen_drawing_green_fuel_arc_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_drawing_green_fuel_arc_main_indicator_default
style_screen_drawing_green_fuel_arc_main_indicator_default = lv.style_t()
style_screen_drawing_green_fuel_arc_main_indicator_default.init()
style_screen_drawing_green_fuel_arc_main_indicator_default.set_arc_color(lv.color_make(0x1e,0xca,0x1c))
style_screen_drawing_green_fuel_arc_main_indicator_default.set_arc_width(10)

# add style for screen_drawing_Green_fuel_arc
screen_drawing_Green_fuel_arc.add_style(style_screen_drawing_green_fuel_arc_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_screen_drawing_green_fuel_arc_main_knob_default
style_screen_drawing_green_fuel_arc_main_knob_default = lv.style_t()
style_screen_drawing_green_fuel_arc_main_knob_default.init()
style_screen_drawing_green_fuel_arc_main_knob_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_green_fuel_arc_main_knob_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_green_fuel_arc_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_green_fuel_arc_main_knob_default.set_bg_opa(0)
style_screen_drawing_green_fuel_arc_main_knob_default.set_pad_all(5)

# add style for screen_drawing_Green_fuel_arc
screen_drawing_Green_fuel_arc.add_style(style_screen_drawing_green_fuel_arc_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

screen_drawing_FUEL_level = lv.img(screen_drawing_container_drawing)
screen_drawing_FUEL_level.set_pos(303,326)
screen_drawing_FUEL_level.set_size(197,49)
screen_drawing_FUEL_level.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-2124469024.png','rb') as f:
        screen_drawing_FUEL_level_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-2124469024.png')
    sys.exit()

screen_drawing_FUEL_level_img = lv.img_dsc_t({
  'data_size': len(screen_drawing_FUEL_level_img_data),
  'header': {'always_zero': 0, 'w': 197, 'h': 49, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_drawing_FUEL_level_img_data
})

screen_drawing_FUEL_level.set_src(screen_drawing_FUEL_level_img)
screen_drawing_FUEL_level.set_pivot(0,0)
screen_drawing_FUEL_level.set_angle(0)
# create style style_screen_drawing_fuel_level_main_main_default
style_screen_drawing_fuel_level_main_main_default = lv.style_t()
style_screen_drawing_fuel_level_main_main_default.init()
style_screen_drawing_fuel_level_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_drawing_fuel_level_main_main_default.set_img_recolor_opa(0)
style_screen_drawing_fuel_level_main_main_default.set_img_opa(255)

# add style for screen_drawing_FUEL_level
screen_drawing_FUEL_level.add_style(style_screen_drawing_fuel_level_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_engine_temperature = lv.img(screen_drawing_container_drawing)
screen_drawing_engine_temperature.set_pos(518,426)
screen_drawing_engine_temperature.set_size(30,30)
screen_drawing_engine_temperature.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-472328908.png','rb') as f:
        screen_drawing_engine_temperature_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-472328908.png')
    sys.exit()

screen_drawing_engine_temperature_img = lv.img_dsc_t({
  'data_size': len(screen_drawing_engine_temperature_img_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 30, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_drawing_engine_temperature_img_data
})

screen_drawing_engine_temperature.set_src(screen_drawing_engine_temperature_img)
screen_drawing_engine_temperature.set_pivot(0,0)
screen_drawing_engine_temperature.set_angle(0)
# create style style_screen_drawing_engine_temperature_main_main_default
style_screen_drawing_engine_temperature_main_main_default = lv.style_t()
style_screen_drawing_engine_temperature_main_main_default.init()
style_screen_drawing_engine_temperature_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_drawing_engine_temperature_main_main_default.set_img_recolor_opa(0)
style_screen_drawing_engine_temperature_main_main_default.set_img_opa(255)

# add style for screen_drawing_engine_temperature
screen_drawing_engine_temperature.add_style(style_screen_drawing_engine_temperature_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_engine_temp_drawing = lv.img(screen_drawing_container_drawing)
screen_drawing_engine_temp_drawing.set_pos(552,435)
screen_drawing_engine_temp_drawing.set_size(211,20)
screen_drawing_engine_temp_drawing.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1949701356.png','rb') as f:
        screen_drawing_engine_temp_drawing_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1949701356.png')
    sys.exit()

screen_drawing_engine_temp_drawing_img = lv.img_dsc_t({
  'data_size': len(screen_drawing_engine_temp_drawing_img_data),
  'header': {'always_zero': 0, 'w': 211, 'h': 20, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_drawing_engine_temp_drawing_img_data
})

screen_drawing_engine_temp_drawing.set_src(screen_drawing_engine_temp_drawing_img)
screen_drawing_engine_temp_drawing.set_pivot(0,0)
screen_drawing_engine_temp_drawing.set_angle(0)
# create style style_screen_drawing_engine_temp_drawing_main_main_default
style_screen_drawing_engine_temp_drawing_main_main_default = lv.style_t()
style_screen_drawing_engine_temp_drawing_main_main_default.init()
style_screen_drawing_engine_temp_drawing_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_drawing_engine_temp_drawing_main_main_default.set_img_recolor_opa(0)
style_screen_drawing_engine_temp_drawing_main_main_default.set_img_opa(255)

# add style for screen_drawing_engine_temp_drawing
screen_drawing_engine_temp_drawing.add_style(style_screen_drawing_engine_temp_drawing_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Battery_0_drawing = lv.img(screen_drawing_container_drawing)
screen_drawing_Battery_0_drawing.set_pos(252,426)
screen_drawing_Battery_0_drawing.set_size(30,30)
screen_drawing_Battery_0_drawing.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1669006229.png','rb') as f:
        screen_drawing_Battery_0_drawing_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp1669006229.png')
    sys.exit()

screen_drawing_Battery_0_drawing_img = lv.img_dsc_t({
  'data_size': len(screen_drawing_Battery_0_drawing_img_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 30, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_drawing_Battery_0_drawing_img_data
})

screen_drawing_Battery_0_drawing.set_src(screen_drawing_Battery_0_drawing_img)
screen_drawing_Battery_0_drawing.set_pivot(0,0)
screen_drawing_Battery_0_drawing.set_angle(0)
# create style style_screen_drawing_battery_0_drawing_main_main_default
style_screen_drawing_battery_0_drawing_main_main_default = lv.style_t()
style_screen_drawing_battery_0_drawing_main_main_default.init()
style_screen_drawing_battery_0_drawing_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_drawing_battery_0_drawing_main_main_default.set_img_recolor_opa(0)
style_screen_drawing_battery_0_drawing_main_main_default.set_img_opa(255)

# add style for screen_drawing_Battery_0_drawing
screen_drawing_Battery_0_drawing.add_style(style_screen_drawing_battery_0_drawing_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_drawing_Battery_0_drawing_level = lv.img(screen_drawing_container_drawing)
screen_drawing_Battery_0_drawing_level.set_pos(37,435)
screen_drawing_Battery_0_drawing_level.set_size(211,20)
screen_drawing_Battery_0_drawing_level.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1810240437.png','rb') as f:
        screen_drawing_Battery_0_drawing_level_img_data = f.read()
except:
    print('Could not open C:\\Users\\nxf77952\\OneDrive - NXP\\NXP\\Client\\Arrow\\RT1170_DInesh\\Dinesh_GUI_guider_1.0.1\\Zhenhua__share\\Dinesh_TFT\\generated\\mPythonImages\\mp-1810240437.png')
    sys.exit()

screen_drawing_Battery_0_drawing_level_img = lv.img_dsc_t({
  'data_size': len(screen_drawing_Battery_0_drawing_level_img_data),
  'header': {'always_zero': 0, 'w': 211, 'h': 20, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_drawing_Battery_0_drawing_level_img_data
})

screen_drawing_Battery_0_drawing_level.set_src(screen_drawing_Battery_0_drawing_level_img)
screen_drawing_Battery_0_drawing_level.set_pivot(0,0)
screen_drawing_Battery_0_drawing_level.set_angle(0)
# create style style_screen_drawing_battery_0_drawing_level_main_main_default
style_screen_drawing_battery_0_drawing_level_main_main_default = lv.style_t()
style_screen_drawing_battery_0_drawing_level_main_main_default.init()
style_screen_drawing_battery_0_drawing_level_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_drawing_battery_0_drawing_level_main_main_default.set_img_recolor_opa(0)
style_screen_drawing_battery_0_drawing_level_main_main_default.set_img_opa(255)

# add style for screen_drawing_Battery_0_drawing_level
screen_drawing_Battery_0_drawing_level.add_style(style_screen_drawing_battery_0_drawing_level_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_drawing_container_drawing_main_main_default
style_screen_drawing_container_drawing_main_main_default = lv.style_t()
style_screen_drawing_container_drawing_main_main_default.init()
style_screen_drawing_container_drawing_main_main_default.set_radius(0)
style_screen_drawing_container_drawing_main_main_default.set_bg_color(lv.color_make(0x11,0x12,0x12))
style_screen_drawing_container_drawing_main_main_default.set_bg_grad_color(lv.color_make(0x0b,0x0c,0x0c))
style_screen_drawing_container_drawing_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_drawing_container_drawing_main_main_default.set_bg_opa(255)
style_screen_drawing_container_drawing_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_drawing_container_drawing_main_main_default.set_border_width(0)
style_screen_drawing_container_drawing_main_main_default.set_border_opa(0)
style_screen_drawing_container_drawing_main_main_default.set_pad_left(0)
style_screen_drawing_container_drawing_main_main_default.set_pad_right(0)
style_screen_drawing_container_drawing_main_main_default.set_pad_top(0)
style_screen_drawing_container_drawing_main_main_default.set_pad_bottom(0)

# add style for screen_drawing_container_drawing
screen_drawing_container_drawing.add_style(style_screen_drawing_container_drawing_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_FONT = lv.obj()
# create style style_screen_font_main_main_default
style_screen_font_main_main_default = lv.style_t()
style_screen_font_main_main_default.init()
style_screen_font_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_font_main_main_default.set_bg_opa(0)

# add style for screen_FONT
screen_FONT.add_style(style_screen_font_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_FONT_cont_1 = lv.obj(screen_FONT)
screen_FONT_cont_1.set_pos(0,0)
screen_FONT_cont_1.set_size(800,480)
screen_FONT_label_12 = lv.label(screen_FONT_cont_1)
screen_FONT_label_12.set_pos(163,342)
screen_FONT_label_12.set_size(525,100)
screen_FONT_label_12.set_text("roso_100 , ")
screen_FONT_label_12.set_long_mode(lv.label.LONG.WRAP)
screen_FONT_label_12.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_font_label_12_main_main_default
style_screen_font_label_12_main_main_default = lv.style_t()
style_screen_font_label_12_main_main_default.init()
style_screen_font_label_12_main_main_default.set_radius(0)
style_screen_font_label_12_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_12_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_12_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_font_label_12_main_main_default.set_bg_opa(0)
style_screen_font_label_12_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_font_label_12_main_main_default.set_text_font(lv.font_RussoOne_Regular_100)
except AttributeError:
    try:
        style_screen_font_label_12_main_main_default.set_text_font(lv.font_montserrat_100)
    except AttributeError:
        style_screen_font_label_12_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_font_label_12_main_main_default.set_text_letter_space(1)
style_screen_font_label_12_main_main_default.set_pad_left(0)
style_screen_font_label_12_main_main_default.set_pad_right(0)
style_screen_font_label_12_main_main_default.set_pad_top(0)
style_screen_font_label_12_main_main_default.set_pad_bottom(0)

# add style for screen_FONT_label_12
screen_FONT_label_12.add_style(style_screen_font_label_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_FONT_label_3 = lv.label(screen_FONT_cont_1)
screen_FONT_label_3.set_pos(51,137)
screen_FONT_label_3.set_size(100,32)
screen_FONT_label_3.set_text("default_15 , ")
screen_FONT_label_3.set_long_mode(lv.label.LONG.WRAP)
screen_FONT_label_3.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_font_label_3_main_main_default
style_screen_font_label_3_main_main_default = lv.style_t()
style_screen_font_label_3_main_main_default.init()
style_screen_font_label_3_main_main_default.set_radius(0)
style_screen_font_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_font_label_3_main_main_default.set_bg_opa(0)
style_screen_font_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_font_label_3_main_main_default.set_text_font(lv.font_Alatsi_Regular_15)
except AttributeError:
    try:
        style_screen_font_label_3_main_main_default.set_text_font(lv.font_montserrat_15)
    except AttributeError:
        style_screen_font_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_font_label_3_main_main_default.set_text_letter_space(1)
style_screen_font_label_3_main_main_default.set_pad_left(0)
style_screen_font_label_3_main_main_default.set_pad_right(0)
style_screen_font_label_3_main_main_default.set_pad_top(0)
style_screen_font_label_3_main_main_default.set_pad_bottom(0)

# add style for screen_FONT_label_3
screen_FONT_label_3.add_style(style_screen_font_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_FONT_label_2 = lv.label(screen_FONT_cont_1)
screen_FONT_label_2.set_pos(41,108)
screen_FONT_label_2.set_size(100,32)
screen_FONT_label_2.set_text("default_14 , ")
screen_FONT_label_2.set_long_mode(lv.label.LONG.WRAP)
screen_FONT_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_font_label_2_main_main_default
style_screen_font_label_2_main_main_default = lv.style_t()
style_screen_font_label_2_main_main_default.init()
style_screen_font_label_2_main_main_default.set_radius(0)
style_screen_font_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_font_label_2_main_main_default.set_bg_opa(0)
style_screen_font_label_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_font_label_2_main_main_default.set_text_font(lv.font_Alatsi_Regular_14)
except AttributeError:
    try:
        style_screen_font_label_2_main_main_default.set_text_font(lv.font_montserrat_14)
    except AttributeError:
        style_screen_font_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_font_label_2_main_main_default.set_text_letter_space(1)
style_screen_font_label_2_main_main_default.set_pad_left(0)
style_screen_font_label_2_main_main_default.set_pad_right(0)
style_screen_font_label_2_main_main_default.set_pad_top(0)
style_screen_font_label_2_main_main_default.set_pad_bottom(0)

# add style for screen_FONT_label_2
screen_FONT_label_2.add_style(style_screen_font_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_FONT_label_1 = lv.label(screen_FONT_cont_1)
screen_FONT_label_1.set_pos(0,70)
screen_FONT_label_1.set_size(200,32)
screen_FONT_label_1.set_text("default_12 , ")
screen_FONT_label_1.set_long_mode(lv.label.LONG.WRAP)
screen_FONT_label_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_font_label_1_main_main_default
style_screen_font_label_1_main_main_default = lv.style_t()
style_screen_font_label_1_main_main_default.init()
style_screen_font_label_1_main_main_default.set_radius(0)
style_screen_font_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_font_label_1_main_main_default.set_bg_opa(0)
style_screen_font_label_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_font_label_1_main_main_default.set_text_font(lv.font_Alatsi_Regular_12)
except AttributeError:
    try:
        style_screen_font_label_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_font_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_font_label_1_main_main_default.set_text_letter_space(1)
style_screen_font_label_1_main_main_default.set_pad_left(0)
style_screen_font_label_1_main_main_default.set_pad_right(0)
style_screen_font_label_1_main_main_default.set_pad_top(0)
style_screen_font_label_1_main_main_default.set_pad_bottom(0)

# add style for screen_FONT_label_1
screen_FONT_label_1.add_style(style_screen_font_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_font_cont_1_main_main_default
style_screen_font_cont_1_main_main_default = lv.style_t()
style_screen_font_cont_1_main_main_default.init()
style_screen_font_cont_1_main_main_default.set_radius(0)
style_screen_font_cont_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_font_cont_1_main_main_default.set_bg_opa(255)
style_screen_font_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_cont_1_main_main_default.set_border_width(0)
style_screen_font_cont_1_main_main_default.set_border_opa(255)
style_screen_font_cont_1_main_main_default.set_pad_left(0)
style_screen_font_cont_1_main_main_default.set_pad_right(0)
style_screen_font_cont_1_main_main_default.set_pad_top(0)
style_screen_font_cont_1_main_main_default.set_pad_bottom(0)

# add style for screen_FONT_cont_1
screen_FONT_cont_1.add_style(style_screen_font_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_FONT_label_4 = lv.label(screen_FONT)
screen_FONT_label_4.set_pos(42,183)
screen_FONT_label_4.set_size(100,32)
screen_FONT_label_4.set_text("default_16 , ")
screen_FONT_label_4.set_long_mode(lv.label.LONG.WRAP)
screen_FONT_label_4.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_font_label_4_main_main_default
style_screen_font_label_4_main_main_default = lv.style_t()
style_screen_font_label_4_main_main_default.init()
style_screen_font_label_4_main_main_default.set_radius(0)
style_screen_font_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_font_label_4_main_main_default.set_bg_opa(0)
style_screen_font_label_4_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_font_label_4_main_main_default.set_text_font(lv.font_Alatsi_Regular_16)
except AttributeError:
    try:
        style_screen_font_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_font_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_font_label_4_main_main_default.set_text_letter_space(1)
style_screen_font_label_4_main_main_default.set_pad_left(0)
style_screen_font_label_4_main_main_default.set_pad_right(0)
style_screen_font_label_4_main_main_default.set_pad_top(0)
style_screen_font_label_4_main_main_default.set_pad_bottom(0)

# add style for screen_FONT_label_4
screen_FONT_label_4.add_style(style_screen_font_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_FONT_label_5 = lv.label(screen_FONT)
screen_FONT_label_5.set_pos(0,232)
screen_FONT_label_5.set_size(165,32)
screen_FONT_label_5.set_text("default_18 , ")
screen_FONT_label_5.set_long_mode(lv.label.LONG.WRAP)
screen_FONT_label_5.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_font_label_5_main_main_default
style_screen_font_label_5_main_main_default = lv.style_t()
style_screen_font_label_5_main_main_default.init()
style_screen_font_label_5_main_main_default.set_radius(0)
style_screen_font_label_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_font_label_5_main_main_default.set_bg_opa(0)
style_screen_font_label_5_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_font_label_5_main_main_default.set_text_font(lv.font_Alatsi_Regular_18)
except AttributeError:
    try:
        style_screen_font_label_5_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_screen_font_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_font_label_5_main_main_default.set_text_letter_space(1)
style_screen_font_label_5_main_main_default.set_pad_left(0)
style_screen_font_label_5_main_main_default.set_pad_right(0)
style_screen_font_label_5_main_main_default.set_pad_top(0)
style_screen_font_label_5_main_main_default.set_pad_bottom(0)

# add style for screen_FONT_label_5
screen_FONT_label_5.add_style(style_screen_font_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_FONT_label_6 = lv.label(screen_FONT)
screen_FONT_label_6.set_pos(0,289)
screen_FONT_label_6.set_size(180,32)
screen_FONT_label_6.set_text("default_20 , ")
screen_FONT_label_6.set_long_mode(lv.label.LONG.WRAP)
screen_FONT_label_6.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_font_label_6_main_main_default
style_screen_font_label_6_main_main_default = lv.style_t()
style_screen_font_label_6_main_main_default.init()
style_screen_font_label_6_main_main_default.set_radius(0)
style_screen_font_label_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_font_label_6_main_main_default.set_bg_opa(0)
style_screen_font_label_6_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_font_label_6_main_main_default.set_text_font(lv.font_Alatsi_Regular_20)
except AttributeError:
    try:
        style_screen_font_label_6_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_screen_font_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_font_label_6_main_main_default.set_text_letter_space(1)
style_screen_font_label_6_main_main_default.set_pad_left(0)
style_screen_font_label_6_main_main_default.set_pad_right(0)
style_screen_font_label_6_main_main_default.set_pad_top(0)
style_screen_font_label_6_main_main_default.set_pad_bottom(0)

# add style for screen_FONT_label_6
screen_FONT_label_6.add_style(style_screen_font_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_FONT_label_7 = lv.label(screen_FONT)
screen_FONT_label_7.set_pos(0,328)
screen_FONT_label_7.set_size(162,32)
screen_FONT_label_7.set_text("default_22 , ")
screen_FONT_label_7.set_long_mode(lv.label.LONG.WRAP)
screen_FONT_label_7.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_font_label_7_main_main_default
style_screen_font_label_7_main_main_default = lv.style_t()
style_screen_font_label_7_main_main_default.init()
style_screen_font_label_7_main_main_default.set_radius(0)
style_screen_font_label_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_font_label_7_main_main_default.set_bg_opa(0)
style_screen_font_label_7_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_font_label_7_main_main_default.set_text_font(lv.font_Alatsi_Regular_22)
except AttributeError:
    try:
        style_screen_font_label_7_main_main_default.set_text_font(lv.font_montserrat_22)
    except AttributeError:
        style_screen_font_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_font_label_7_main_main_default.set_text_letter_space(1)
style_screen_font_label_7_main_main_default.set_pad_left(0)
style_screen_font_label_7_main_main_default.set_pad_right(0)
style_screen_font_label_7_main_main_default.set_pad_top(0)
style_screen_font_label_7_main_main_default.set_pad_bottom(0)

# add style for screen_FONT_label_7
screen_FONT_label_7.add_style(style_screen_font_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_FONT_label_8 = lv.label(screen_FONT)
screen_FONT_label_8.set_pos(257,52)
screen_FONT_label_8.set_size(333,59)
screen_FONT_label_8.set_text("default_60 , ")
screen_FONT_label_8.set_long_mode(lv.label.LONG.WRAP)
screen_FONT_label_8.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_font_label_8_main_main_default
style_screen_font_label_8_main_main_default = lv.style_t()
style_screen_font_label_8_main_main_default.init()
style_screen_font_label_8_main_main_default.set_radius(0)
style_screen_font_label_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_font_label_8_main_main_default.set_bg_opa(0)
style_screen_font_label_8_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_font_label_8_main_main_default.set_text_font(lv.font_Alatsi_Regular_60)
except AttributeError:
    try:
        style_screen_font_label_8_main_main_default.set_text_font(lv.font_montserrat_60)
    except AttributeError:
        style_screen_font_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_font_label_8_main_main_default.set_text_letter_space(1)
style_screen_font_label_8_main_main_default.set_pad_left(0)
style_screen_font_label_8_main_main_default.set_pad_right(0)
style_screen_font_label_8_main_main_default.set_pad_top(0)
style_screen_font_label_8_main_main_default.set_pad_bottom(0)

# add style for screen_FONT_label_8
screen_FONT_label_8.add_style(style_screen_font_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_FONT_label_10 = lv.label(screen_FONT)
screen_FONT_label_10.set_pos(250,125)
screen_FONT_label_10.set_size(472,80)
screen_FONT_label_10.set_text("default_80 , ")
screen_FONT_label_10.set_long_mode(lv.label.LONG.WRAP)
screen_FONT_label_10.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_font_label_10_main_main_default
style_screen_font_label_10_main_main_default = lv.style_t()
style_screen_font_label_10_main_main_default.init()
style_screen_font_label_10_main_main_default.set_radius(0)
style_screen_font_label_10_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_font_label_10_main_main_default.set_bg_opa(0)
style_screen_font_label_10_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_font_label_10_main_main_default.set_text_font(lv.font_Alatsi_Regular_80)
except AttributeError:
    try:
        style_screen_font_label_10_main_main_default.set_text_font(lv.font_montserrat_80)
    except AttributeError:
        style_screen_font_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_font_label_10_main_main_default.set_text_letter_space(1)
style_screen_font_label_10_main_main_default.set_pad_left(0)
style_screen_font_label_10_main_main_default.set_pad_right(0)
style_screen_font_label_10_main_main_default.set_pad_top(0)
style_screen_font_label_10_main_main_default.set_pad_bottom(0)

# add style for screen_FONT_label_10
screen_FONT_label_10.add_style(style_screen_font_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_FONT_label_11 = lv.label(screen_FONT)
screen_FONT_label_11.set_pos(129,235)
screen_FONT_label_11.set_size(671,140)
screen_FONT_label_11.set_text("default_100 , ")
screen_FONT_label_11.set_long_mode(lv.label.LONG.WRAP)
screen_FONT_label_11.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_font_label_11_main_main_default
style_screen_font_label_11_main_main_default = lv.style_t()
style_screen_font_label_11_main_main_default.init()
style_screen_font_label_11_main_main_default.set_radius(0)
style_screen_font_label_11_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_11_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_font_label_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_font_label_11_main_main_default.set_bg_opa(0)
style_screen_font_label_11_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_font_label_11_main_main_default.set_text_font(lv.font_Alatsi_Regular_100)
except AttributeError:
    try:
        style_screen_font_label_11_main_main_default.set_text_font(lv.font_montserrat_100)
    except AttributeError:
        style_screen_font_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_font_label_11_main_main_default.set_text_letter_space(1)
style_screen_font_label_11_main_main_default.set_pad_left(0)
style_screen_font_label_11_main_main_default.set_pad_right(0)
style_screen_font_label_11_main_main_default.set_pad_top(0)
style_screen_font_label_11_main_main_default.set_pad_bottom(0)

# add style for screen_FONT_label_11
screen_FONT_label_11.add_style(style_screen_font_label_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)




# content from custom.py

# Load the default screen
lv.scr_load(screen)

while SDL.check():
    time.sleep_ms(5)
