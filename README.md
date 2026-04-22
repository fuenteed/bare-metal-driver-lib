Project: The goal of this project is to be a portable CLI framework for async tasks specified by the user via commands such as 
`set pwm 50` or `i2c scan` or something like that. Still defining the scope and possibilities.

The target board for this project is my STM32L476RG.

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

