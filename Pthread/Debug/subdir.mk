################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../example1_hello.cpp \
../example2_hello32.cpp \
../hello_arg1.cpp \
../main.cpp 

OBJS += \
./example1_hello.o \
./example2_hello32.o \
./hello_arg1.o \
./main.o 

CPP_DEPS += \
./example1_hello.d \
./example2_hello32.d \
./hello_arg1.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


