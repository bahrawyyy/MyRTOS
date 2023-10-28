################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Stm32_F103C6_Drivers/GPIO/subdir.mk
-include Stm32_F103C6_Drivers/EXTI/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include My_RTOS/subdir.mk
-include HAL/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
My_RTOS_Project.axf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
My_RTOS_Project.list \

OBJCOPY_HEX += \
My_RTOS_Project.hex \

OBJCOPY_BIN += \
My_RTOS_Project.bin \


# All Target
all: My_RTOS_Project.axf secondary-outputs

# Tool invocations
My_RTOS_Project.axf: $(OBJS) $(USER_OBJS) C:\Users\Abdallah\STM32CubeIDE\workspace_1.4.0\My_RTOS_Project\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "My_RTOS_Project.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Abdallah\STM32CubeIDE\workspace_1.4.0\My_RTOS_Project\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="My_RTOS_Project.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

My_RTOS_Project.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "My_RTOS_Project.list"
	@echo 'Finished building: $@'
	@echo ' '

My_RTOS_Project.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "My_RTOS_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

My_RTOS_Project.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "My_RTOS_Project.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
