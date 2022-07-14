include ../../avr.mk

TARGET = libavr.a
OBJFILES = usart.o
#MCU ?= avr35 # For ATmega8u2
MCU ?= atmega8u2 # Required for avr/io.h
F_OSC ?= 16000000UL # Required by usart.h

all: $(LIB_PATH)/$(TARGET)

$(LIB_PATH)/$(TARGET): $(BUILD_PATH)/$(OBJFILES)
	ar -cvq $@ $^

$(BUILD_PATH)/%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	-cd $(BUILD_PATH) && rm -f $(OBJFILES) 
	-cd $(LIB_PATH) && rm -f $(TARGET)
