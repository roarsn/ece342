################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Drivers/CMSIS_DSP/Src/WindowFunctions/subdir.mk
-include Drivers/CMSIS_DSP/Src/TransformFunctions/subdir.mk
-include Drivers/CMSIS_DSP/Src/SupportFunctions/subdir.mk
-include Drivers/CMSIS_DSP/Src/StatisticsFunctions/subdir.mk
-include Drivers/CMSIS_DSP/Src/MatrixFunctions/subdir.mk
-include Drivers/CMSIS_DSP/Src/FilteringFunctions/subdir.mk
-include Drivers/CMSIS_DSP/Src/FastMathFunctions/subdir.mk
-include Drivers/CMSIS_DSP/Src/DistanceFunctions/subdir.mk
-include Drivers/CMSIS_DSP/Src/ComplexMathFunctions/subdir.mk
-include Drivers/CMSIS_DSP/Src/CommonTables/subdir.mk
-include Drivers/CMSIS_DSP/Src/BasicMathFunctions/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := radar
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
radar.elf \

MAP_FILES += \
radar.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
radar.list \


# All Target
all: main-build

# Main-build Target
main-build: radar.elf secondary-outputs

# Tool invocations
radar.elf radar.map: $(OBJS) $(USER_OBJS) C:\Users\aveng\OneDrive\Documents\STM32\WORKSPACE\radar\STM32F446ZETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "radar.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\aveng\OneDrive\Documents\STM32\WORKSPACE\radar\STM32F446ZETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="radar.map" -Wl,--gc-sections -static -u _printf_float --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

radar.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "radar.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout radar.elf radar.list radar.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
