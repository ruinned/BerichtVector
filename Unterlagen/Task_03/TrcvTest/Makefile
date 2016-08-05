#/*!
# ******************************************************************************
# * \brief    makefile
# *
# *           -
# *
# * \project  
# * \file     $Workfile: makefile $
# * \author   Andreas Herkommer
# * \bug      -
# * \warning  -
# * \todo     -
# ******************************************************************************
# */
# *-----------------------------------------------------------------------------
# * File History
# *-----------------------------------------------------------------------------
#$Log:$
#

#################################################################
# Define all the working directories & programms here:
#
COMPILERPATH=D:/usr/Task_03/TrcvTest/Compiler/bin/
COMPILER = $(COMPILERPATH)avr-gcc
OBJDUMP  = $(COMPILERPATH)avr-objdump
OBJCOPY  = $(COMPILERPATH)avr-objcopy
AVRDUDE  = $(COMPILERPATH)avrdude

#################################################################
# Define all directories which contain files to include
#
DIRS = include main core io ./Compiler/avr/include ./Compiler/avr/include/avr

#################################################################
# All object files necessary for this project
#
objects = main.o HardwareSerial.o HardwareSerial0.o Print.o dio.o spi.o trcvSpi.o trcvDio.o protocol.o

#################################################################
# The Compiler & Linker flags to use
#
CPPFLAGS  = -g -Wall -Os -Winline -finline -mmcu=atmega328p -ffunction-sections -fdata-sections -DF_CPU=16000000u
CFLAGS  = -g -Wall -Os -Winline -finline -mmcu=atmega328p -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=16000000u
#          -Wl,-u,vfprintf -lprintf_min

LDFLAGS = -Wl,--gc-sections
# -lc -Wl,-Map,linker.Map -Wl,--cref

#################################################################
# The linker requires the path to the objects.
#
BUILD_LINK_OBJS	= $(foreach file, $(objects), object/$(file))

#################################################################
# make will search in the following directories:
#
VPATH_CPP  = $(foreach inc, $(DIRS), :$(inc))
VPATH_C  = $(foreach inc, $(DIRS), :$(inc))
VPATH_H  = $(foreach inc, $(DIRS), :$(inc))

vpath %.cpp $(VPATH_CPP)
vpath %.c $(VPATH_C)
vpath %.h $(VPATH_H)

#################################################################
# Our actual build process:
#
# Generate the .s files
# Link them together to create firmware.elf
# Disassemble firmware.elf
# Build ihex file from firmware.elf
#
INCLUDES = $(foreach inc, $(DIRS), -I$(inc))

all:	$(BUILD_LINK_OBJS:.o=.s) $(BUILD_LINK_OBJS:.o=.d)
		$(COMPILER) $(CFLAGS) $(LDFLAGS) $(BUILD_LINK_OBJS:.o=.s) -o firmware.elf
	    $(OBJDUMP) -h firmware.elf > main_map.txt
		$(OBJDUMP) -dSt firmware.elf > firmware.s
		$(OBJCOPY) -O ihex firmware.elf firmware.hex

#################################################################
# Include Dependencies
#
-include $(BUILD_LINK_OBJS:.o=.d)
$(BUILD_LINK_OBJS:.o=.s): Makefile

#################################################################
# Rule to generate dependency files
#
object/%.d: %.cpp
	$(COMPILER) $(CPPFLAGS) $(INCLUDES) -MM -MT 'object/$(*F).s object/$(*F).d' $< -o $@

object/%.d: %.c
	$(COMPILER) $(CFLAGS) $(INCLUDES) -MM -MT 'object/$(*F).s object/$(*F).d' $< -o $@

#################################################################
# Rule to compile source files
#
object/%.s: %.cpp
	$(COMPILER) $(CPPFLAGS) $(INCLUDES) $< -S -o $@

object/%.s: %.c
	$(COMPILER) $(CFLAGS) $(INCLUDES) $< -S -o $@

    #################################################################
# Rule to clean all unneccessary files
#
clean:
	rm -f object/*.s
	rm -f object/*.d
	rm -f firmware.*
    
avrdude: firmware.hex
	$(AVRDUDE) -p m328p -c arduino -b 115200 -P COM3 -U flash:w:firmware.hex

.PHONY: all clean 

