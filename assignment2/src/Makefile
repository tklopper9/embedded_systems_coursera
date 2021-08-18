#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	<FILE>.o - Builds <FILE>.o object file:
#	build - builds and links all object files
#	all - same as build
#	clean - removes all generated files
#
# Platform Overrides:
#      CPU -
#      ARCH -
#      SPECS -
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = ($1)

ifeq ($(PLATFORM), HOST)
  CC = gcc
  # should we get the overrides from the host machine?
else
  CC = arm-none-eabi-gcc
  CPU = cortex-m4
  ARCH = armv7e-m
  SPECS = nosys-specs

CFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)

%.o : %.c
  $(CC) -c $< $(CFLAGS) -o $@

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

.PHONY: clean
clean:
  rm -f $(OBJS) $(TARGET).out $(TARGET).map

# Architectures Specific Flags
LINKER_FILE = 
CPU = 
ARCH = 
SPECS = 

# Compiler Flags and Defines
CC = 
LD = 
LDFLAGS = 
CFLAGS = 
CPPFLAGs = 

