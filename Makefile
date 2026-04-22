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
-Wl,-Map=$(TARGET).map \
-nostdlib

SRC = src/main.c startup/startup.c system/system_stm32l4xx.c $(DRIVERS_SRC)


OBJ = $(SRC:.c=.o)

all: $(TARGET).elf $(TARGET).bin

$(TARGET).elf: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

flash:
	openocd -f board/st_nucleo_l4.cfg \
	-c "program $(TARGET).elf verify reset exit"

clean:
	rm -f $(OBJ) *.elf *.bin *.map