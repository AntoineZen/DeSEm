################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/antoine/master/DeSEm/desenet-work/desenet-common/platform/platform-common/board/ledflasher.cpp 

OBJS += \
./platform/platform-common/board/ledflasher.o 

CPP_DEPS += \
./platform/platform-common/board/ledflasher.d 


# Each subdirectory must supply rules for building sources it contributes
platform/platform-common/board/ledflasher.o: /home/antoine/master/DeSEm/desenet-work/desenet-common/platform/platform-common/board/ledflasher.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -DTC_MESHSIM -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/platform/linux-meshsim -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/xf -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-sensor -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw/desenet -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common/board -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim/mcu -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim/board -I/usr/include/qt5 -I/usr/include/qt5/QtNetwork -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

