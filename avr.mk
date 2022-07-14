# Shared Makefile with AVR specific definitions
ROOT_PATH ?= $(shell git rev-parse --show-toplevel)
include $(ROOT_PATH)/common.mk
AVRLIB_PATH := $(LIB_PATH)/avr

CC = avr-gcc
OBJCOPY = avr-objcopy

# Lazy evaluation of the MCU and F_OSC variables
CPPFLAGS = -DF_OSC=$(F_OSC)
CFLAGS = -Os -g -Wall -Werror -Wpedantic -mmcu=$(MCU) -I$(INCLUDE_PATH)

LDFLAGS = -Wl,-Map,$(BUILD_PATH)/$(TARGET).map -Wl,--gc-sections -mmcu=$(MCU)
