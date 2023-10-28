################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/EXTI/Stm32_F103C6_EXTI_driver.c 

OBJS += \
./Stm32_F103C6_Drivers/EXTI/Stm32_F103C6_EXTI_driver.o 

C_DEPS += \
./Stm32_F103C6_Drivers/EXTI/Stm32_F103C6_EXTI_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/EXTI/Stm32_F103C6_EXTI_driver.o: ../Stm32_F103C6_Drivers/EXTI/Stm32_F103C6_EXTI_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/My_RTOS/inc" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/CMSIS_V5" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/HAL/includes" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/EXTI/Stm32_F103C6_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

