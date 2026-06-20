################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_Party/croutine.c \
../Third_Party/event_groups.c \
../Third_Party/list.c \
../Third_Party/queue.c \
../Third_Party/stream_buffer.c \
../Third_Party/tasks.c \
../Third_Party/timers.c 

OBJS += \
./Third_Party/croutine.o \
./Third_Party/event_groups.o \
./Third_Party/list.o \
./Third_Party/queue.o \
./Third_Party/stream_buffer.o \
./Third_Party/tasks.o \
./Third_Party/timers.o 

C_DEPS += \
./Third_Party/croutine.d \
./Third_Party/event_groups.d \
./Third_Party/list.d \
./Third_Party/queue.d \
./Third_Party/stream_buffer.d \
./Third_Party/tasks.d \
./Third_Party/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Third_Party/%.o Third_Party/%.su Third_Party/%.cyclo: ../Third_Party/%.c Third_Party/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"D:/Random/RTOS/RTOS_1/LED_3_RTOS_1/Third_Party" -I"D:/Random/RTOS/RTOS_1/LED_3_RTOS_1/Third_Party/portable/GCC/ARM_CM4F" -I"D:/Random/RTOS/RTOS_1/LED_3_RTOS_1/Third_Party/include" -I"C:/Users/MinnuDiary/Downloads/FreeRTOSv202406.04-LTS (3)/FreeRTOS-LTS/FreeRTOS/FreeRTOS-Kernel/include" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third_Party

clean-Third_Party:
	-$(RM) ./Third_Party/croutine.cyclo ./Third_Party/croutine.d ./Third_Party/croutine.o ./Third_Party/croutine.su ./Third_Party/event_groups.cyclo ./Third_Party/event_groups.d ./Third_Party/event_groups.o ./Third_Party/event_groups.su ./Third_Party/list.cyclo ./Third_Party/list.d ./Third_Party/list.o ./Third_Party/list.su ./Third_Party/queue.cyclo ./Third_Party/queue.d ./Third_Party/queue.o ./Third_Party/queue.su ./Third_Party/stream_buffer.cyclo ./Third_Party/stream_buffer.d ./Third_Party/stream_buffer.o ./Third_Party/stream_buffer.su ./Third_Party/tasks.cyclo ./Third_Party/tasks.d ./Third_Party/tasks.o ./Third_Party/tasks.su ./Third_Party/timers.cyclo ./Third_Party/timers.d ./Third_Party/timers.o ./Third_Party/timers.su

.PHONY: clean-Third_Party

