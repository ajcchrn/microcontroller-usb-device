MCU = atmega8u2
F_OSC = 16000000UL

CC = avr-gcc
CXX = avr-g++
OBJCOPY = avr-objcopy
AVRDUDE = avrdude
AVRDUDE_FLAGS = -c avrispmkII -p $(MCU)

INCLUDE_PATH := $(PWD)/../include
AVRLIB_PATH := $(PWD)/../lib/avr
AVRLIB_OBJS := $(AVRLIB_PATH)/Port.o $(AVRLIB_PATH)/USART.o

TARGET = test_ports
OBJFILES = $(TARGET).o
CFLAGS = -Os -g -Wall -Wpedantic -mmcu=$(MCU) -I$(INCLUDE_PATH)
CXXFLAGS = -std=c++17 $(CFLAGS)
CPPFLAGS = -DF_OSC=$(F_OSC)
LDFLAGS = -Wl,-Map,$(TARGET).map -Wl,--gc-sections -mmcu=$(MCU)

all: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

$(TARGET).elf: $(OBJFILES) $(AVRLIB_OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@ 

$(AVRLIB_OBJS):
	$(MAKE) -C $(AVRLIB_PATH) CXX=$(CXX) CXXFLAGS="$(CXXFLAGS)" \
	       	CPPFLAGS="$(CPPFLAGS)" 

memstat: $(TARGET).hex
	avr-size -C --mcu=$(MCU) $(TARGET).elf

upload: $(TARGET).hex
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$<

.PHONY: clean memstat all
clean:
	-rm *.o *.hex *.map *.elf
