################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_anatop_ai.c \
../drivers/fsl_cache.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_dcdc.c \
../drivers/fsl_elcdif.c \
../drivers/fsl_flexcan.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lcdifv2.c \
../drivers/fsl_lpi2c.c \
../drivers/fsl_lpuart.c \
../drivers/fsl_mipi_dsi.c \
../drivers/fsl_pit.c \
../drivers/fsl_pmu.c \
../drivers/fsl_pxp.c \
../drivers/fsl_soc_mipi_csi2rx.c \
../drivers/fsl_soc_src.c 

OBJS += \
./drivers/fsl_anatop_ai.o \
./drivers/fsl_cache.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_dcdc.o \
./drivers/fsl_elcdif.o \
./drivers/fsl_flexcan.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lcdifv2.o \
./drivers/fsl_lpi2c.o \
./drivers/fsl_lpuart.o \
./drivers/fsl_mipi_dsi.o \
./drivers/fsl_pit.o \
./drivers/fsl_pmu.o \
./drivers/fsl_pxp.o \
./drivers/fsl_soc_mipi_csi2rx.o \
./drivers/fsl_soc_src.o 

C_DEPS += \
./drivers/fsl_anatop_ai.d \
./drivers/fsl_cache.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_dcdc.d \
./drivers/fsl_elcdif.d \
./drivers/fsl_flexcan.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lcdifv2.d \
./drivers/fsl_lpi2c.d \
./drivers/fsl_lpuart.d \
./drivers/fsl_mipi_dsi.d \
./drivers/fsl_pit.d \
./drivers/fsl_pmu.d \
./drivers/fsl_pxp.d \
./drivers/fsl_soc_mipi_csi2rx.d \
./drivers/fsl_soc_src.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DLV_DEMO_CONF_INCLUDE_SIMPLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DSDK_I2C_BASED_COMPONENT_USED=1 -DVG_RESOLVE_ENGINE=0 -DVG_PE_COLOR_KEY=0 -DVG_IM_INDEX_FORMAT=0 -DVG_AYUV_INPUT_OUTPUT=0 -DVG_DOUBLE_IMAGE=0 -DVG_RECTANGLE_STRIP_MODE=0 -DVG_MMU=0 -DVG_IM_FILTER=0 -DVG_IM_YUV_PACKET=1 -DVG_IM_YUV_PLANAR=0 -DVG_PE_YUV_PACKET=1 -DVG_TARGET_TILED=1 -DVG_COMMAND_CALL=1 -DVG_SHARE_BUFFER_IM_16K=0 -DVG_OFFLINE_MODE=0 -DVG_RESOLUTION_2880=0 -DVG_PE_PREMULTIPLY=0 -DVG_POST_CONVERTER=0 -DVG_PRE_CONVERTER=0 -DVG_RENDER_BY_MESH=0 -DVG_TARGET_FAST_CLEAR=0 -DVG_BUFFER_NUMBER_OF_TARGET=0 -DVG_VIDEO_CLEAR_CONTROL=0 -DVG_VIDEO_CONTROL=0 -DVGLITE_TST_FIRMWARE=0 -DVG_LITE_SYS_GPU_CTRL=0 -DSERIAL_PORT_TYPE_UART=1 -DMCUXPRESSO_SDK -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\drivers" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\custom" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\generated\guider_customer_fonts" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\generated\guider_fonts" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\generated\images" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\generated" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\xip" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\component\serial_manager" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\component\uart" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\utilities" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\component\lists" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\lvgl\lvgl" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\lvgl\lvgl\src\font" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\lvgl" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\video" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\device" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\CMSIS" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\drivers" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\xip" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\component\serial_manager" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\component\uart" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\utilities" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\component\lists" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\lvgl\lvgl" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\lvgl\lvgl\src" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\lvgl" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\device" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\CMSIS" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\board" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\source" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project_TFT\startup" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


