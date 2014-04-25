################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Edge.cpp \
../src/Graph.cpp \
../src/People.cpp \
../src/Vertex.cpp \
../src/main.cpp 

OBJS += \
./src/Edge.o \
./src/Graph.o \
./src/People.o \
./src/Vertex.o \
./src/main.o 

CPP_DEPS += \
./src/Edge.d \
./src/Graph.d \
./src/People.d \
./src/Vertex.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


