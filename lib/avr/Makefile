CXX = avr-g++
OBJCOPY = avr-objcopy
F_OSC ?= 16000000UL
# For ATmega8u2 use -mmcu=avr35
MCU = avr35
VPATH = src

TARGET = libavrcxx.a
OBJFILES = Port.o USART.o
HEADERS := $(PWD)/../../include
CPPFLAGS = -DF_OSC=$(F_OSC)
CXXFLAGS = -std=c++17 -Os -g -Wall -Wpedantic -mmcu=$(MCU) -I$(HEADERS) 

all: $(TARGET)

$(TARGET): $(OBJFILES)
	ar -cvq $@ $^

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm *.o *.a
