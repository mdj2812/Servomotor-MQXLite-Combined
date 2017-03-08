################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/ALIM_12V_RLY.c \
../Generated_Code/Cpu.c \
../Generated_Code/MQX1.c \
../Generated_Code/MX28R_DE.c \
../Generated_Code/MX28R_RE.c \
../Generated_Code/MX28R_RS485.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/Pins1.c \
../Generated_Code/SystemTimer1.c 

OBJS += \
./Generated_Code/ALIM_12V_RLY.o \
./Generated_Code/Cpu.o \
./Generated_Code/MQX1.o \
./Generated_Code/MX28R_DE.o \
./Generated_Code/MX28R_RE.o \
./Generated_Code/MX28R_RS485.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/Pins1.o \
./Generated_Code/SystemTimer1.o 

C_DEPS += \
./Generated_Code/ALIM_12V_RLY.d \
./Generated_Code/Cpu.d \
./Generated_Code/MQX1.d \
./Generated_Code/MX28R_DE.d \
./Generated_Code/MX28R_RE.d \
./Generated_Code/MX28R_RS485.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/Pins1.d \
./Generated_Code/SystemTimer1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/user/workspace.kds/MX28R_Dev/Static_Code/System" -I"C:/Users/user/workspace.kds/MX28R_Dev/Static_Code/PDD" -I"C:/Users/user/workspace.kds/MX28R_Dev/Static_Code/IO_Map" -I"E:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/user/workspace.kds/MX28R_Dev/Sources" -I"C:/Users/user/workspace.kds/MX28R_Dev/Generated_Code" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/include" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/config" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/kernel" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/psp/cortex_m" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/psp/cortex_m/core/M4" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/psp/cortex_m/compiler/cwgcc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


