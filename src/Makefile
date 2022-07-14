include ../avr.mk
MCU = atmega8u2
TARGET = test

all: $(BUILD_PATH)/$(TARGET).elf

$(BUILD_PATH)/$(TARGET).elf: $(BUILD_PATH)/$(TARGET).o
	$(CC) $(LDFLAGS) $^ $(LIBFLAGS) -o $@

$(BUILD_PATH)/%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONEY: clean
clean:
	-cd $(BUILD_PATH) && rm -f *.o *.map *.elf
