################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../generated/guider_fonts/lv_font_Alatsi_Regular_100.c \
../generated/guider_fonts/lv_font_Alatsi_Regular_12.c \
../generated/guider_fonts/lv_font_Alatsi_Regular_14.c \
../generated/guider_fonts/lv_font_Alatsi_Regular_15.c \
../generated/guider_fonts/lv_font_Alatsi_Regular_16.c \
../generated/guider_fonts/lv_font_Alatsi_Regular_18.c \
../generated/guider_fonts/lv_font_Alatsi_Regular_20.c \
../generated/guider_fonts/lv_font_Alatsi_Regular_22.c \
../generated/guider_fonts/lv_font_Alatsi_Regular_60.c \
../generated/guider_fonts/lv_font_Alatsi_Regular_80.c \
../generated/guider_fonts/lv_font_DSEG7Classic_Regular_100.c \
../generated/guider_fonts/lv_font_DSEG7Classic_Regular_80.c \
../generated/guider_fonts/lv_font_RussoOne_Regular_100.c \
../generated/guider_fonts/lv_font_RussoOne_Regular_80.c \
../generated/guider_fonts/lv_font_montserratMedium_20.c \
../generated/guider_fonts/lv_font_montserratMedium_22.c \
../generated/guider_fonts/lv_font_simsun_100.c \
../generated/guider_fonts/lv_font_simsun_12.c \
../generated/guider_fonts/lv_font_simsun_14.c \
../generated/guider_fonts/lv_font_simsun_15.c \
../generated/guider_fonts/lv_font_simsun_16.c \
../generated/guider_fonts/lv_font_simsun_18.c \
../generated/guider_fonts/lv_font_simsun_20.c \
../generated/guider_fonts/lv_font_simsun_22.c \
../generated/guider_fonts/lv_font_simsun_60.c \
../generated/guider_fonts/lv_font_simsun_80.c 

OBJS += \
./generated/guider_fonts/lv_font_Alatsi_Regular_100.o \
./generated/guider_fonts/lv_font_Alatsi_Regular_12.o \
./generated/guider_fonts/lv_font_Alatsi_Regular_14.o \
./generated/guider_fonts/lv_font_Alatsi_Regular_15.o \
./generated/guider_fonts/lv_font_Alatsi_Regular_16.o \
./generated/guider_fonts/lv_font_Alatsi_Regular_18.o \
./generated/guider_fonts/lv_font_Alatsi_Regular_20.o \
./generated/guider_fonts/lv_font_Alatsi_Regular_22.o \
./generated/guider_fonts/lv_font_Alatsi_Regular_60.o \
./generated/guider_fonts/lv_font_Alatsi_Regular_80.o \
./generated/guider_fonts/lv_font_DSEG7Classic_Regular_100.o \
./generated/guider_fonts/lv_font_DSEG7Classic_Regular_80.o \
./generated/guider_fonts/lv_font_RussoOne_Regular_100.o \
./generated/guider_fonts/lv_font_RussoOne_Regular_80.o \
./generated/guider_fonts/lv_font_montserratMedium_20.o \
./generated/guider_fonts/lv_font_montserratMedium_22.o \
./generated/guider_fonts/lv_font_simsun_100.o \
./generated/guider_fonts/lv_font_simsun_12.o \
./generated/guider_fonts/lv_font_simsun_14.o \
./generated/guider_fonts/lv_font_simsun_15.o \
./generated/guider_fonts/lv_font_simsun_16.o \
./generated/guider_fonts/lv_font_simsun_18.o \
./generated/guider_fonts/lv_font_simsun_20.o \
./generated/guider_fonts/lv_font_simsun_22.o \
./generated/guider_fonts/lv_font_simsun_60.o \
./generated/guider_fonts/lv_font_simsun_80.o 

C_DEPS += \
./generated/guider_fonts/lv_font_Alatsi_Regular_100.d \
./generated/guider_fonts/lv_font_Alatsi_Regular_12.d \
./generated/guider_fonts/lv_font_Alatsi_Regular_14.d \
./generated/guider_fonts/lv_font_Alatsi_Regular_15.d \
./generated/guider_fonts/lv_font_Alatsi_Regular_16.d \
./generated/guider_fonts/lv_font_Alatsi_Regular_18.d \
./generated/guider_fonts/lv_font_Alatsi_Regular_20.d \
./generated/guider_fonts/lv_font_Alatsi_Regular_22.d \
./generated/guider_fonts/lv_font_Alatsi_Regular_60.d \
./generated/guider_fonts/lv_font_Alatsi_Regular_80.d \
./generated/guider_fonts/lv_font_DSEG7Classic_Regular_100.d \
./generated/guider_fonts/lv_font_DSEG7Classic_Regular_80.d \
./generated/guider_fonts/lv_font_RussoOne_Regular_100.d \
./generated/guider_fonts/lv_font_RussoOne_Regular_80.d \
./generated/guider_fonts/lv_font_montserratMedium_20.d \
./generated/guider_fonts/lv_font_montserratMedium_22.d \
./generated/guider_fonts/lv_font_simsun_100.d \
./generated/guider_fonts/lv_font_simsun_12.d \
./generated/guider_fonts/lv_font_simsun_14.d \
./generated/guider_fonts/lv_font_simsun_15.d \
./generated/guider_fonts/lv_font_simsun_16.d \
./generated/guider_fonts/lv_font_simsun_18.d \
./generated/guider_fonts/lv_font_simsun_20.d \
./generated/guider_fonts/lv_font_simsun_22.d \
./generated/guider_fonts/lv_font_simsun_60.d \
./generated/guider_fonts/lv_font_simsun_80.d 


# Each subdirectory must supply rules for building sources it contributes
generated/guider_fonts/%.o: ../generated/guider_fonts/%.c generated/guider_fonts/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DLV_DEMO_CONF_INCLUDE_SIMPLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DSDK_I2C_BASED_COMPONENT_USED=1 -DVG_RESOLVE_ENGINE=0 -DVG_PE_COLOR_KEY=0 -DVG_IM_INDEX_FORMAT=0 -DVG_AYUV_INPUT_OUTPUT=0 -DVG_DOUBLE_IMAGE=0 -DVG_RECTANGLE_STRIP_MODE=0 -DVG_MMU=0 -DVG_IM_FILTER=0 -DVG_IM_YUV_PACKET=1 -DVG_IM_YUV_PLANAR=0 -DVG_PE_YUV_PACKET=1 -DVG_TARGET_TILED=1 -DVG_COMMAND_CALL=1 -DVG_SHARE_BUFFER_IM_16K=0 -DVG_OFFLINE_MODE=0 -DVG_RESOLUTION_2880=0 -DVG_PE_PREMULTIPLY=0 -DVG_POST_CONVERTER=0 -DVG_PRE_CONVERTER=0 -DVG_RENDER_BY_MESH=0 -DVG_TARGET_FAST_CLEAR=0 -DVG_BUFFER_NUMBER_OF_TARGET=0 -DVG_VIDEO_CLEAR_CONTROL=0 -DVG_VIDEO_CONTROL=0 -DVGLITE_TST_FIRMWARE=0 -DVG_LITE_SYS_GPU_CTRL=0 -DSERIAL_PORT_TYPE_UART=1 -DMCUXPRESSO_SDK -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\drivers" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\custom" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\generated\guider_customer_fonts" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\generated\guider_fonts" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\generated\images" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\generated" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\xip" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\component\serial_manager" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\component\uart" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\utilities" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\component\lists" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\lvgl\lvgl" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\lvgl\lvgl\src\font" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\lvgl" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\video" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\device" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\CMSIS" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\drivers" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\xip" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\component\serial_manager" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\component\uart" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\utilities" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\component\lists" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\lvgl\lvgl" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\lvgl\lvgl\src" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\lvgl" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\device" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\CMSIS" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\board" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\source" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\startup" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


