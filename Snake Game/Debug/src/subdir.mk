################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Game.cpp \
../src/GameObject.cpp \
../src/Main.cpp \
../src/TextureManager.cpp 

OBJS += \
./src/Game.o \
./src/GameObject.o \
./src/Main.o \
./src/TextureManager.o 

CPP_DEPS += \
./src/Game.d \
./src/GameObject.d \
./src/Main.d \
./src/TextureManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


