################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drviers/src/ADC.c \
../drviers/src/LCD.c \
../drviers/src/gpio.c 

OBJS += \
./drviers/src/ADC.o \
./drviers/src/LCD.o \
./drviers/src/gpio.o 

C_DEPS += \
./drviers/src/ADC.d \
./drviers/src/LCD.d \
./drviers/src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
drviers/src/%.o: ../drviers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F401xC -I"E:/embded/ADC_PROJECT/ADC/Core/Inc" -I"E:/embded/ADC_PROJECT/ADC/drviers/inc" -I"E:/embded/ADC_PROJECT/ADC/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"E:/embded/ADC_PROJECT/ADC/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


