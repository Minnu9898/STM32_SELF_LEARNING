################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_Party/portable/MemMang/heap_4.c 

OBJS += \
./Third_Party/portable/MemMang/heap_4.o 

C_DEPS += \
./Third_Party/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Third_Party/portable/MemMang/%.o Third_Party/portable/MemMang/%.su Third_Party/portable/MemMang/%.cyclo: ../Third_Party/portable/MemMang/%.c Third_Party/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"D:/Random/RTOS/RTOS_1/LED_3_RTOS_1/Third_Party" -I"D:/Random/RTOS/RTOS_1/LED_3_RTOS_1/Third_Party/portable/GCC/ARM_CM4F" -I"D:/Random/RTOS/RTOS_1/LED_3_RTOS_1/Third_Party/include" -I"C:/Users/MinnuDiary/Downloads/FreeRTOSv202406.04-LTS (3)/FreeRTOS-LTS/FreeRTOS/FreeRTOS-Kernel/include" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third_Party-2f-portable-2f-MemMang

clean-Third_Party-2f-portable-2f-MemMang:
	-$(RM) ./Third_Party/portable/MemMang/heap_4.cyclo ./Third_Party/portable/MemMang/heap_4.d ./Third_Party/portable/MemMang/heap_4.o ./Third_Party/portable/MemMang/heap_4.su

.PHONY: clean-Third_Party-2f-portable-2f-MemMang

