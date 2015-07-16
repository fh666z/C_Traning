################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../bug2_stack.cpp \
../bug3.cpp \
../bug5.cpp \
../detached.cpp \
../example1_hello.cpp \
../example2_hello32.cpp \
../hello_arg1.cpp \
../hello_arg2.cpp \
../join.cpp \
../main.cpp 

OBJS += \
./bug2_stack.o \
./bug3.o \
./bug5.o \
./detached.o \
./example1_hello.o \
./example2_hello32.o \
./hello_arg1.o \
./hello_arg2.o \
./join.o \
./main.o 

CPP_DEPS += \
./bug2_stack.d \
./bug3.d \
./bug5.d \
./detached.d \
./example1_hello.d \
./example2_hello32.d \
./hello_arg1.d \
./hello_arg2.d \
./join.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


