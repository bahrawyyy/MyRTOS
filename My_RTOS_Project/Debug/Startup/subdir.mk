################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c6tx.s 

OBJS += \
./Startup/startup_stm32f103c6tx.o 

S_DEPS += \
./Startup/startup_stm32f103c6tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f103c6tx.o: ../Startup/startup_stm32f103c6tx.s
	arm-none-eabi-gcc -gdwarf-2 -mcpu=cortex-m3 -g3 -c -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/My_RTOS/inc" -I../Inc -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/CMSIS_V5" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/HAL/includes" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/Stm32_F103C6_Drivers/inc" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f103c6tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

