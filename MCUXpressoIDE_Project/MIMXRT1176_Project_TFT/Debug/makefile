################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xip/subdir.mk
-include video/subdir.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include lvgl/lvgl/src/widgets/subdir.mk
-include lvgl/lvgl/src/misc/subdir.mk
-include lvgl/lvgl/src/hal/subdir.mk
-include lvgl/lvgl/src/gpu/subdir.mk
-include lvgl/lvgl/src/font/subdir.mk
-include lvgl/lvgl/src/extra/widgets/win/subdir.mk
-include lvgl/lvgl/src/extra/widgets/tileview/subdir.mk
-include lvgl/lvgl/src/extra/widgets/tabview/subdir.mk
-include lvgl/lvgl/src/extra/widgets/spinner/subdir.mk
-include lvgl/lvgl/src/extra/widgets/spinbox/subdir.mk
-include lvgl/lvgl/src/extra/widgets/span/subdir.mk
-include lvgl/lvgl/src/extra/widgets/msgbox/subdir.mk
-include lvgl/lvgl/src/extra/widgets/meter/subdir.mk
-include lvgl/lvgl/src/extra/widgets/list/subdir.mk
-include lvgl/lvgl/src/extra/widgets/led/subdir.mk
-include lvgl/lvgl/src/extra/widgets/keyboard/subdir.mk
-include lvgl/lvgl/src/extra/widgets/imgbtn/subdir.mk
-include lvgl/lvgl/src/extra/widgets/colorwheel/subdir.mk
-include lvgl/lvgl/src/extra/widgets/chart/subdir.mk
-include lvgl/lvgl/src/extra/widgets/calendar/subdir.mk
-include lvgl/lvgl/src/extra/widgets/animimg/subdir.mk
-include lvgl/lvgl/src/extra/themes/mono/subdir.mk
-include lvgl/lvgl/src/extra/themes/default/subdir.mk
-include lvgl/lvgl/src/extra/themes/basic/subdir.mk
-include lvgl/lvgl/src/extra/layouts/grid/subdir.mk
-include lvgl/lvgl/src/extra/layouts/flex/subdir.mk
-include lvgl/lvgl/src/extra/subdir.mk
-include lvgl/lvgl/src/draw/subdir.mk
-include lvgl/lvgl/src/core/subdir.mk
-include generated/images/subdir.mk
-include generated/guider_fonts/subdir.mk
-include generated/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include custom/subdir.mk
-include component/uart/subdir.mk
-include component/serial_manager/subdir.mk
-include component/lists/subdir.mk
-include board/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := MIMXRT1176_Project_TFT
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: MIMXRT1176_Project_TFT.axf

# Tool invocations
MIMXRT1176_Project_TFT.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="MIMXRT1176_Project_TFT.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -T MIMXRT1176_Project_Debug.ld -o "MIMXRT1176_Project_TFT.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) MIMXRT1176_Project_TFT.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "MIMXRT1176_Project_TFT.axf"; # arm-none-eabi-objcopy -v -O binary "MIMXRT1176_Project_TFT.axf" "MIMXRT1176_Project_TFT.bin" ; # checksum -p MIMXRT1176xxxxx -d "MIMXRT1176_Project_TFT.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
