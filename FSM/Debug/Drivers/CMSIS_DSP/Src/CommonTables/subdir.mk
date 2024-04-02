################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables.c \
../Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables_f16.c \
../Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs.c \
../Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs_f16.c \
../Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables.c \
../Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables_f16.c 

OBJS += \
./Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables.o \
./Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables_f16.o \
./Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs.o \
./Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs_f16.o \
./Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables.o \
./Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables_f16.o 

C_DEPS += \
./Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables.d \
./Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables_f16.d \
./Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs.d \
./Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs_f16.d \
./Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables.d \
./Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables_f16.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS_DSP/Src/CommonTables/%.o Drivers/CMSIS_DSP/Src/CommonTables/%.su Drivers/CMSIS_DSP/Src/CommonTables/%.cyclo: ../Drivers/CMSIS_DSP/Src/CommonTables/%.c Drivers/CMSIS_DSP/Src/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"C:/Users/aveng/OneDrive/Documents/STM32/WORKSPACE/radar/Drivers/CMSIS_DSP/Include" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS_DSP-2f-Src-2f-CommonTables

clean-Drivers-2f-CMSIS_DSP-2f-Src-2f-CommonTables:
	-$(RM) ./Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables.cyclo ./Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables.d ./Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables.o ./Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables.su ./Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables_f16.cyclo ./Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables_f16.d ./Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables_f16.o ./Drivers/CMSIS_DSP/Src/CommonTables/arm_common_tables_f16.su ./Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs.cyclo ./Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs.d ./Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs.o ./Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs.su ./Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs_f16.cyclo ./Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs_f16.d ./Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs_f16.o ./Drivers/CMSIS_DSP/Src/CommonTables/arm_const_structs_f16.su ./Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables.cyclo ./Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables.d ./Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables.o ./Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables.su ./Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables_f16.cyclo ./Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables_f16.d ./Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables_f16.o ./Drivers/CMSIS_DSP/Src/CommonTables/arm_mve_tables_f16.su

.PHONY: clean-Drivers-2f-CMSIS_DSP-2f-Src-2f-CommonTables

