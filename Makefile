TARGET = blinky

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

CPU = cortex-m4
DRIVERS_SRC = $(wildcard Drivers/*.c)

CFLAGS = \
-mcpu=$(CPU) \
-mthumb \
-O0 \
-g \
-ffreestanding \
-Wall \
-DSTM32L476xx \
-I CMSIS/CMSIS_5/CMSIS/Core/Include \
-I Device/cmsis-device-l4/Include \
-I Include

LDFLAGS = \
-T linker/linker.ld \
-Wl,-Map=build/$(TARGET).map \
-nostartfiles --specs=nosys.specs -lc

APP=uart

ifdef APP
  MAIN_SRC = src/main_$(APP).c
else
  MAIN_SRC = src/main.c
endif

SRC = $(MAIN_SRC) startup/startup.c system/system_stm32l4xx.c $(DRIVERS_SRC)


BUILD = build
OBJ = $(SRC:%.c=$(BUILD)/%.o)

all: $(BUILD)/$(TARGET).elf $(BUILD)/$(TARGET).bin

# take all object files and turn into elf
$(BUILD)/$(TARGET).elf: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

# take all c files and turn into object files (mirrors source tree under build/)
$(BUILD)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# take elf and turn into executable binary
$(BUILD)/$(TARGET).bin: $(BUILD)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

flash: $(BUILD)/$(TARGET).elf
	openocd -f board/st_nucleo_l4.cfg \
	-c "program $(BUILD)/$(TARGET).elf verify reset exit"

clean:
	rm -rf $(BUILD)

.PHONY: all flash clean