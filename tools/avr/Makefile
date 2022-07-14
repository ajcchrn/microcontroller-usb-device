include ../../avr.mk

MCU ?= atmega8u2
PROGRAMMER ?= avrispmkII

OBJCOPY = avr-objcopy
AVRDUDE = avrdude
AVRDUDE_FLAGS := -c $(PROGRAMMER) -p $(MCU)

all: flash

flash: $(BUILD_PATH)/$(TARGET).hex
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$<

$(BUILD_PATH)/$(TARGET).hex: $(BUILD_PATH)/$(TARGET).elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

.PHONY: clean
clean:
	-cd $(BUILD_PATH) && rm -f *.hex
