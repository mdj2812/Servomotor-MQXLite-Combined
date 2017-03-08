################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MQXLITE/kernel/idletask.c \
../MQXLITE/kernel/int.c \
../MQXLITE/kernel/klog.c \
../MQXLITE/kernel/lwevent.c \
../MQXLITE/kernel/lwlog.c \
../MQXLITE/kernel/lwmem.c \
../MQXLITE/kernel/lwmsgq.c \
../MQXLITE/kernel/lwsem.c \
../MQXLITE/kernel/lwtimer.c \
../MQXLITE/kernel/mqx_utils.c \
../MQXLITE/kernel/mqxlite.c \
../MQXLITE/kernel/mutex.c \
../MQXLITE/kernel/qu_test.c \
../MQXLITE/kernel/sched.c \
../MQXLITE/kernel/task.c \
../MQXLITE/kernel/time_ticks.c 

OBJS += \
./MQXLITE/kernel/idletask.o \
./MQXLITE/kernel/int.o \
./MQXLITE/kernel/klog.o \
./MQXLITE/kernel/lwevent.o \
./MQXLITE/kernel/lwlog.o \
./MQXLITE/kernel/lwmem.o \
./MQXLITE/kernel/lwmsgq.o \
./MQXLITE/kernel/lwsem.o \
./MQXLITE/kernel/lwtimer.o \
./MQXLITE/kernel/mqx_utils.o \
./MQXLITE/kernel/mqxlite.o \
./MQXLITE/kernel/mutex.o \
./MQXLITE/kernel/qu_test.o \
./MQXLITE/kernel/sched.o \
./MQXLITE/kernel/task.o \
./MQXLITE/kernel/time_ticks.o 

C_DEPS += \
./MQXLITE/kernel/idletask.d \
./MQXLITE/kernel/int.d \
./MQXLITE/kernel/klog.d \
./MQXLITE/kernel/lwevent.d \
./MQXLITE/kernel/lwlog.d \
./MQXLITE/kernel/lwmem.d \
./MQXLITE/kernel/lwmsgq.d \
./MQXLITE/kernel/lwsem.d \
./MQXLITE/kernel/lwtimer.d \
./MQXLITE/kernel/mqx_utils.d \
./MQXLITE/kernel/mqxlite.d \
./MQXLITE/kernel/mutex.d \
./MQXLITE/kernel/qu_test.d \
./MQXLITE/kernel/sched.d \
./MQXLITE/kernel/task.d \
./MQXLITE/kernel/time_ticks.d 


# Each subdirectory must supply rules for building sources it contributes
MQXLITE/kernel/%.o: ../MQXLITE/kernel/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/user/workspace.kds/MX28R_Dev/Static_Code/System" -I"C:/Users/user/workspace.kds/MX28R_Dev/Static_Code/PDD" -I"C:/Users/user/workspace.kds/MX28R_Dev/Static_Code/IO_Map" -I"E:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/user/workspace.kds/MX28R_Dev/Sources" -I"C:/Users/user/workspace.kds/MX28R_Dev/Generated_Code" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/include" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/config" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/kernel" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/psp/cortex_m" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/psp/cortex_m/core/M4" -I"C:/Users/user/workspace.kds/MX28R_Dev/MQXLITE/psp/cortex_m/compiler/cwgcc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


