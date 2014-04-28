################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/People.cpp \
../src/ProjResp.cpp \
../src/Students.cpp \
../src/Supervisors.cpp \
../src/connection.cpp \
../src/graphviewer.cpp \
../src/main.cpp 

OBJS += \
./src/People.o \
./src/ProjResp.o \
./src/Students.o \
./src/Supervisors.o \
./src/connection.o \
./src/graphviewer.o \
./src/main.o 

CPP_DEPS += \
./src/People.d \
./src/ProjResp.d \
./src/Students.d \
./src/Supervisors.d \
./src/connection.d \
./src/graphviewer.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


