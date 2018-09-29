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
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"/home/angicia/Work Lab/Workbench/STM32F4_Neucleo/02.GPIO_In/03.Button_OR/StdPeriph_Driver/inc" -I"/home/angicia/Work Lab/Workbench/STM32F4_Neucleo/02.GPIO_In/03.Button_OR/inc" -I"/home/angicia/Work Lab/Workbench/STM32F4_Neucleo/02.GPIO_In/03.Button_OR/CMSIS/device" -I"/home/angicia/Work Lab/Workbench/STM32F4_Neucleo/02.GPIO_In/03.Button_OR/CMSIS/core" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


