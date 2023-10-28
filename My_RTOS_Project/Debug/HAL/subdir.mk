################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KPD_program.c \
../HAL/Lcd.c 

OBJS += \
./HAL/KPD_program.o \
./HAL/Lcd.o 

C_DEPS += \
./HAL/KPD_program.d \
./HAL/Lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KPD_program.o: ../HAL/KPD_program.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/My_RTOS/inc" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/CMSIS_V5" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/HAL/includes" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KPD_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/Lcd.o: ../HAL/Lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/My_RTOS/inc" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/CMSIS_V5" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/HAL/includes" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

