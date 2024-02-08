# Teensy LC
MCU = MKL26Z64
BOOTLOADER = halfkay
USE_CHIBIOS_CONTRIB = yes

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# There is not enough heap space ("cannot move location counter backwards") with this and all three UARTs turned on.
#CONSOLE_ENABLE = no
