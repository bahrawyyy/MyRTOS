################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../My_RTOS/CortexMxOS_Porting.c \
../My_RTOS/My_RTOS_FIFO.c \
../My_RTOS/Schedular.c 

OBJS += \
./My_RTOS/CortexMxOS_Porting.o \
./My_RTOS/My_RTOS_FIFO.o \
./My_RTOS/Schedular.o 

C_DEPS += \
./My_RTOS/CortexMxOS_Porting.d \
./My_RTOS/My_RTOS_FIFO.d \
./My_RTOS/Schedular.d 


# Each subdirectory must supply rules for building sources it contributes
My_RTOS/CortexMxOS_Porting.o: ../My_RTOS/CortexMxOS_Porting.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/My_RTOS/inc" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/CMSIS_V5" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/HAL/includes" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"My_RTOS/CortexMxOS_Porting.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
My_RTOS/My_RTOS_FIFO.o: ../My_RTOS/My_RTOS_FIFO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/My_RTOS/inc" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/CMSIS_V5" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/HAL/includes" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"My_RTOS/My_RTOS_FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
My_RTOS/Schedular.o: ../My_RTOS/Schedular.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/My_RTOS/inc" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/CMSIS_V5" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/HAL/includes" -I"C:/Users/Abdallah/STM32CubeIDE/workspace_1.4.0/My_RTOS_Project/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"My_RTOS/Schedular.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

