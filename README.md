# Commands to build and flash

Build:

`make`

Flash:

`make flash`

### debug with GDB

Terminal A (run OpenOCD and leave it running):

`make openocd`

Terminal B:

`arm-none-eabi-gdb blinky.elf`

Then in GDB:

`target extended-remote :3333`

`monitor reset halt`

`load`

`monitor reset init`

`continue`

