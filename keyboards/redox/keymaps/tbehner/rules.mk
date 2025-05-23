# MCU name
# MCU = atmega32u4

# Bootloader selection
# BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
#BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
#MOUSEKEY_ENABLE = yes       # Mouse keys
#EXTRAKEY_ENABLE = yes       # Audio control and System control
#CONSOLE_ENABLE = yes        # Console for debug
#COMMAND_ENABLE = yes        # Commands for debug and configuration
#NKRO_ENABLE = yes           # Enable N-Key Rollover
LTO_ENABLE = yes
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
#RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
#AUDIO_ENABLE = no           # Audio output
#CUSTOM_MATRIX = lite

# project specific files
# SRC += matrix.c
# QUANTUM_LIB_SRC += uart.c
COMBO_ENABLE = yes
LEADER_ENABLE = yes
REPEAT_KEY_ENABLE = yes
