################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../External_Interrupts.c \
../gpio.c \
../main.c \
../seven_segment.c \
../timer1.c 

OBJS += \
./External_Interrupts.o \
./gpio.o \
./main.o \
./seven_segment.o \
./timer1.o 

C_DEPS += \
./External_Interrupts.d \
./gpio.d \
./main.d \
./seven_segment.d \
./timer1.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


