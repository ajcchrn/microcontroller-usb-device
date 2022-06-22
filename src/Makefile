MCU = atmega8u2
F_CPU = 16000000UL

CC = avr-gcc
CXX = avr-g++
OBJCOPY = avr-objcopy
AVRDUDE = avrdude
AVRDUDE_FLAGS = -c avrispmkII -p $(MCU)
INCLUDE_PATH = ../include

TARGET = test_ports
OBJFILES = $(TARGET).o Port.o
CFLAGS = -Os -g -Wall -Wpedantic \
	 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums \
	 -ffunction-sections -fdata-sections \
	 -mmcu=$(MCU) -I$(INCLUDE_PATH)
CXXFLAGS = -std=c++17 $(CFLAGS)
CPPFLAGS = -DF_CPU=$(F_CPU)
LDFLAGS = -Wl,-Map,$(TARGET).map -Wl,--gc-sections -mmcu=$(MCU)

all: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

$(TARGET).elf: $(OBJFILES) 
	$(CXX) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@ 

memstat: $(TARGET).hex
	avr-size -C --mcu=$(MCU) $(TARGET).elf

upload: $(TARGET).hex
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$<

.PHONY: clean memstat all
clean:
	-rm *.o *.hex *.map *.elf
