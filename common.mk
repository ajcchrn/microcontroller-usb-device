# Common Makefile included by avr.mk and samd21.mk

ROOT_PATH := $(shell git rev-parse --show-toplevel)
DESTDIR ?= $(ROOT_PATH)

INCLUDE_PATH := $(DESTDIR)/include
LIB_PATH := $(DESTDIR)/lib
BUILD_PATH := $(DESTDIR)/build
