################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/beacon.cpp \
/home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/frame.cpp \
/home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/networkinterfacedriver.cpp 

OBJS += \
./mdw/desenet/beacon.o \
./mdw/desenet/frame.o \
./mdw/desenet/networkinterfacedriver.o 

CPP_DEPS += \
./mdw/desenet/beacon.d \
./mdw/desenet/frame.d \
./mdw/desenet/networkinterfacedriver.d 


# Each subdirectory must supply rules for building sources it contributes
mdw/desenet/beacon.o: /home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/beacon.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DTC_STM32 -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/xf -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/cmsis -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/stm32f1-stdperiph -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-sensor/platform/olimex-stm32f103-stk -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/target -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/critical -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-sensor -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/desenet -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw/desenet -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common/board -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/board -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mdw/desenet/frame.o: /home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/frame.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DTC_STM32 -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/xf -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/cmsis -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/stm32f1-stdperiph -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-sensor/platform/olimex-stm32f103-stk -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/target -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/critical -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-sensor -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/desenet -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw/desenet -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common/board -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/board -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mdw/desenet/networkinterfacedriver.o: /home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/networkinterfacedriver.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DTC_STM32 -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/xf -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/cmsis -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/stm32f1-stdperiph -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-sensor/platform/olimex-stm32f103-stk -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/target -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/critical -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-sensor -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/desenet -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw/desenet -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common/board -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/olimex-stm32f103-stk/board -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

