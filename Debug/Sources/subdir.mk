################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Events.c \
../Sources/MX28R.c \
../Sources/main.c \
../Sources/mqx_tasks.c 

OBJS += \
./Sources/Events.o \
./Sources/MX28R.o \
./Sources/main.o \
./Sources/mqx_tasks.o 

C_DEPS += \
./Sources/Events.d \
./Sources/MX28R.d \
./Sources/main.d \
./Sources/mqx_tasks.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/user/workspace.kds/MX28R_Dev/Static_Code/System" -I"C:/Users/user/workspace.kds/MX28R_Dev/Static_Code/PDD" -I"C:/Users/user/workspace.kds/MX28R_Dev/Static_Code/IO_Map" -I"E:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/user/workspace.kds/MX28R_Dev/Sources" -I"C:/Users/user/workspace.kds/MX28R_Dev/Generated_Code" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/include" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/config" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/kernel" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/psp/cortex_m" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/psp/cortex_m/core/M4" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/psp/cortex_m/compiler/cwgcc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


