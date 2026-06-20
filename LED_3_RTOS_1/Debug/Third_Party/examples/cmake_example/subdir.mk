################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_Party/examples/cmake_example/main.c 

OBJS += \
./Third_Party/examples/cmake_example/main.o 

C_DEPS += \
./Third_Party/examples/cmake_example/main.d 


# Each subdirectory must supply rules for building sources it contributes
Third_Party/examples/cmake_example/%.o Third_Party/examples/cmake_example/%.su Third_Party/examples/cmake_example/%.cyclo: ../Third_Party/examples/cmake_example/%.c Third_Party/examples/cmake_example/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"D:/Random/RTOS/RTOS_1/LED_3_RTOS_1/Third_Party" -I"D:/Random/RTOS/RTOS_1/LED_3_RTOS_1/Third_Party/portable/GCC/ARM_CM4F" -I"D:/Random/RTOS/RTOS_1/LED_3_RTOS_1/Third_Party/include" -I"C:/Users/MinnuDiary/Downloads/FreeRTOSv202406.04-LTS (3)/FreeRTOS-LTS/FreeRTOS/FreeRTOS-Kernel/include" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third_Party-2f-examples-2f-cmake_example

clean-Third_Party-2f-examples-2f-cmake_example:
	-$(RM) ./Third_Party/examples/cmake_example/main.cyclo ./Third_Party/examples/cmake_example/main.d ./Third_Party/examples/cmake_example/main.o ./Third_Party/examples/cmake_example/main.su

.PHONY: clean-Third_Party-2f-examples-2f-cmake_example

