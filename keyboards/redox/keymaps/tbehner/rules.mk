# MCU name
# MCU = atmega32u4

# Bootloader selection
# BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
#BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
#NKRO_ENABLE = yes           # Enable N-Key Rollover

# Platz sparen: nichts davon wird im Keymap benutzt
COMMAND_ENABLE = no    # Deaktiviert die Magic-Befehle (Bootloader-Sprung etc.)
CONSOLE_ENABLE = no    # Deaktiviert Debugging-Output
MOUSEKEY_ENABLE = no   # Keine Maussteuerung über die Tastatur
EXTRAKEY_ENABLE = no   # Media-Tasten, Systemsteuerung
MUSIC_ENABLE = no      # Musik-Modus
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
