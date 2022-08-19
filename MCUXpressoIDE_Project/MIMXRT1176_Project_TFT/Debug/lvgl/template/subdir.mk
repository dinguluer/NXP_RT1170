################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/template/lvgl_support.c 

OBJS += \
./lvgl/template/lvgl_support.o 

C_DEPS += \
./lvgl/template/lvgl_support.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/template/%.o: ../lvgl/template/%.c lvgl/template/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MIMXRT1176DVMAA -DCPU_MIMXRT1176DVMAA_cm7 -DSDK_OS_BAREMETAL -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -DLV_CONF_INCLUDE_SIMPLE -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\drivers" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\source\generated" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\xip" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\component\serial_manager" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\component\uart" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\utilities" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\component\lists" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\lvgl\lvgl" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\lvgl\lvgl\src" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\lvgl" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\video" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\source\generated\guider_customer_fonts" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\source\generated\guider_fonts" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\lvgl\template" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\device" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\CMSIS" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\drivers" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\xip" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\component\serial_manager" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\component\uart" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\utilities" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\component\lists" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\lvgl\lvgl" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\lvgl\lvgl\src" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\lvgl" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\lvgl\template" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\device" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\CMSIS" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\board" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\source" -I"C:\Users\nxf77952\Documents\MCUXpressoIDE_11.5.0_7232\workspace\MIMXRT1176_Project\startup" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


