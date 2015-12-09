################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/beacon.cpp \
/home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/frame.cpp \
/home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/mpdu.cpp \
/home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/networkinterfacedriver.cpp \
/home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/svpdu.cpp 

OBJS += \
./mdw/desenet/beacon.o \
./mdw/desenet/frame.o \
./mdw/desenet/mpdu.o \
./mdw/desenet/networkinterfacedriver.o \
./mdw/desenet/svpdu.o 

CPP_DEPS += \
./mdw/desenet/beacon.d \
./mdw/desenet/frame.d \
./mdw/desenet/mpdu.d \
./mdw/desenet/networkinterfacedriver.d \
./mdw/desenet/svpdu.d 


# Each subdirectory must supply rules for building sources it contributes
mdw/desenet/beacon.o: /home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/beacon.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -DTC_MESHSIM -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/platform/linux-meshsim -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/xf -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-sensor -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw/desenet -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common/board -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim/mcu -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim/board -I/usr/include/qt5 -I/usr/include/qt5/QtNetwork -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mdw/desenet/frame.o: /home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/frame.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -DTC_MESHSIM -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/platform/linux-meshsim -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/xf -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-sensor -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw/desenet -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common/board -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim/mcu -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim/board -I/usr/include/qt5 -I/usr/include/qt5/QtNetwork -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mdw/desenet/mpdu.o: /home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/mpdu.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -DTC_MESHSIM -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/platform/linux-meshsim -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/xf -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-sensor -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw/desenet -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common/board -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim/mcu -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim/board -I/usr/include/qt5 -I/usr/include/qt5/QtNetwork -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mdw/desenet/networkinterfacedriver.o: /home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/networkinterfacedriver.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -DTC_MESHSIM -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/platform/linux-meshsim -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/xf -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-sensor -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw/desenet -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common/board -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim/mcu -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim/board -I/usr/include/qt5 -I/usr/include/qt5/QtNetwork -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mdw/desenet/svpdu.o: /home/antoine/master/DeSEm/desenet-work/desenet-common/mdw/desenet/svpdu.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -DTC_MESHSIM -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/platform/linux-meshsim -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/xf -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-sensor -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/mdw/desenet -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/platform-common/board -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim/mcu -I/home/antoine/master/DeSEm/desenet-work/desenet-sensor/../desenet-common/platform/linux-meshsim/board -I/usr/include/qt5 -I/usr/include/qt5/QtNetwork -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


