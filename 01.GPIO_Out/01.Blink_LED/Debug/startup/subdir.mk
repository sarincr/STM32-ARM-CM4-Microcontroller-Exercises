################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"/home/angicia/workspace/STM32F4_Neucleo/01.GPIO_In/01.Blink_LED/StdPeriph_Driver/inc" -I"/home/angicia/workspace/STM32F4_Neucleo/01.GPIO_In/01.Blink_LED/inc" -I"/home/angicia/workspace/STM32F4_Neucleo/01.GPIO_In/01.Blink_LED/CMSIS/device" -I"/home/angicia/workspace/STM32F4_Neucleo/01.GPIO_In/01.Blink_LED/CMSIS/core" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


