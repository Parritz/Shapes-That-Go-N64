V=1
SOURCE_DIR=src
BUILD_DIR=build
include $(N64_INST)/include/n64.mk

all: shapesthatgo.z64
.PHONY: all

OBJS = $(BUILD_DIR)/main.o

shapesthatgo.z64: N64_ROM_TITLE="Shapes That Go"

$(BUILD_DIR)/shapesthatgo.elf: $(OBJS)

clean:
	rm -f $(BUILD_DIR)/* *.z64
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)