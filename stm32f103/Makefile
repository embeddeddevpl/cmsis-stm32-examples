BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/obj
NAME      := cmsis-stm32f103

ELF       := $(BUILD_DIR)/$(NAME).elf
HEX       := $(BUILD_DIR)/$(NAME).hex
BIN       := $(BUILD_DIR)/$(NAME).bin

TOOLCHAIN := /home/lagun/workspace/toolchains/gcc-arm-none-eabi-8-2018-q4-major/bin/arm-none-eabi
CC        := $(TOOLCHAIN)-gcc
LD        := $(TOOLCHAIN)-gcc
AR        := $(TOOLCHAIN)-gcc
OBJCOPY   := $(TOOLCHAIN)-objcopy
OBJDUMP   := $(TOOLCHAIN)-objdump
SIZE      := $(TOOLCHAIN)-size

SOURCES   := $(shell find . -name "*.c" -o -name "*.s" -o -name "*.S")
VPATH 	  := $(dir $(SOURCES))
OBJECTS   := $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(notdir $(SOURCES)))))

INCLUDES  := \
	./third-party/cmsis \
	./third-party/stm32 \
	./peripherals \

INCLUDES_FLAG := $(addprefix -I, $(INCLUDES))

DEFINES := \
	STM32F10X_MD \
	STM32F103RBTx \

DEFINES_FLAG := $(addprefix -D, $(DEFINES))

CFLAGS := -mcpu=cortex-m3 -mthumb -O0 -mfloat-abi=soft -c -g -Wall -Wextra $(INCLUDES_FLAG) $(DEFINES_FLAG)

LDSCRIPT := ac6_linkerscript.ld
LDFLAGS  := -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -g --specs=nosys.specs -T$(LDSCRIPT) $(INCLUDES_FLAG) $(DEFINES_FLAG)

all: build_dir $(BIN)

$(HEX): $(ELF)
	@echo "Creating hex file: $@"
	$(OBJCOPY) -O ihex $< $@

$(BIN): $(ELF)
	@echo "Creating bin file: $@"
	$(OBJCOPY) -O binary $< $@

$(ELF): $(OBJECTS)
	@echo "Linking: $@"
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS)

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling: $<"
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o: %.s
	@echo "Compiling: $<"
	$(AR) $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o: %.S
	@echo "Compiling: $<"
	$(AR) $(CFLAGS) $< -o $@

build_dir:
	@mkdir -p $(BUILD_DIR)/obj

size: $(ELF)
	$(SIZE) $< 

clean: 
	rm -rf ${BUILD_DIR}

flash:
	 st-flash erase && st-flash write $(BIN) 0x8000000 

.PHONY: all build_dir size clean flash
