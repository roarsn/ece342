################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f64.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q15.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q31.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f64.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q15.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q31.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q15.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q31.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f64.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q15.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q31.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f64.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f64.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f64.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q15.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q31.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_opt_q31.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q15.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q31.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q7.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f64.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q15.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q31.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f64.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f64.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f64.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q15.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q31.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f64.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q15.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q31.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q7.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f16.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f32.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q15.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q31.c \
../Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q7.c 

OBJS += \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f64.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q15.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q31.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f64.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q15.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q31.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q15.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q31.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f64.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q15.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q31.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f64.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f64.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f64.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q15.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q31.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_opt_q31.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q15.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q31.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q7.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f64.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q15.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q31.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f64.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f64.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f64.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q15.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q31.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f64.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q15.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q31.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q7.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f16.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f32.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q15.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q31.o \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q7.o 

C_DEPS += \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f64.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q15.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q31.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f64.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q15.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q31.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q15.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q31.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f64.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q15.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q31.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f64.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f64.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f64.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q15.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q31.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_opt_q31.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q15.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q31.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q7.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f64.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q15.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q31.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f64.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f64.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f64.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q15.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q31.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f64.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q15.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q31.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q7.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f16.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f32.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q15.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q31.d \
./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q7.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS_DSP/Src/MatrixFunctions/%.o Drivers/CMSIS_DSP/Src/MatrixFunctions/%.su Drivers/CMSIS_DSP/Src/MatrixFunctions/%.cyclo: ../Drivers/CMSIS_DSP/Src/MatrixFunctions/%.c Drivers/CMSIS_DSP/Src/MatrixFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"C:/Users/aveng/OneDrive/Documents/STM32/WORKSPACE/radar/Drivers/CMSIS_DSP/Include" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS_DSP-2f-Src-2f-MatrixFunctions

clean-Drivers-2f-CMSIS_DSP-2f-Src-2f-MatrixFunctions:
	-$(RM) ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f64.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f64.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f64.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_householder_f64.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q15.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q15.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q15.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q15.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q31.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q31.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q31.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_add_q31.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f64.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f64.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f64.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cholesky_f64.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q15.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q15.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q15.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q15.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q31.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q31.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q31.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_mult_q31.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q15.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q15.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q15.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q15.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q31.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q31.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q31.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_cmplx_trans_q31.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f64.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f64.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f64.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_f64.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q15.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q15.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q15.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q15.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q31.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q31.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q31.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_init_q31.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f16.d
	-$(RM) ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f64.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f64.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f64.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_inverse_f64.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f64.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f64.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f64.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_ldlt_f64.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f64.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f64.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f64.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_f64.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q15.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q15.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q15.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q15.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q31.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q31.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q31.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_fast_q31.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_opt_q31.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_opt_q31.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_opt_q31.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_opt_q31.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q15.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q15.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q15.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q15.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q31.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q31.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q31.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q31.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q7.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q7.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q7.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_mult_q7.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f64.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f64.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f64.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_qr_f64.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q15.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q15.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q15.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q15.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q31.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q31.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q31.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_scale_q31.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f64.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f64.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f64.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_lower_triangular_f64.su
	-$(RM) ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f64.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f64.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f64.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_solve_upper_triangular_f64.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f64.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f64.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f64.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_f64.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q15.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q15.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q15.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q15.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q31.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q31.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q31.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_sub_q31.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f64.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f64.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f64.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_f64.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q15.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q15.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q15.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q15.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q31.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q31.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q31.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q31.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q7.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q7.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q7.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_trans_q7.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f16.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f16.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f16.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f16.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f32.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f32.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f32.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_f32.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q15.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q15.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q15.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q15.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q31.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q31.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q31.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q31.su ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q7.cyclo ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q7.d ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q7.o ./Drivers/CMSIS_DSP/Src/MatrixFunctions/arm_mat_vec_mult_q7.su

.PHONY: clean-Drivers-2f-CMSIS_DSP-2f-Src-2f-MatrixFunctions

