LTO_ENABLE = yes            # Link Time Optimization enabled
# BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes        # Mouse keys
# EXTRAKEY_ENABLE = yes        # Audio control and System control
# CONSOLE_ENABLE = no         # Console for debug
# COMMAND_ENABLE = no         # Commands for debug and configuration
# NKRO_ENABLE = yes            # N-Key Rollover
# BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
# AUDIO_ENABLE = no           # Audio output
# SWAP_HANDS_ENABLE = no      # Enable one-hand typing
RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.
OLED_ENABLE = yes           # OLED display
DYNAMIC_MACRO_ENABLE = yes
#VIA_ENABLE = yes
#RGB_MATRIX_ENABLE = yes
#ENCODER_MAP_ENABLE = yes
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes

#BOOTLOADER = caterina
#BOOTLOADER = atmel-dfu

SRC += features/swapper.c
SRC += features/num_word.c
SRC += features/achordion.c

# If you want to change the display of OLED, you need to change here
# SRC +=  ./lib/rgb_state_reader.c \
#         ./lib/layer_state_reader.c \
#         ./lib/logo_reader.c \
#         ./lib/keylogger.c \
#         ./lib/mode_icon_reader.c \
#         ./lib/host_led_state_reader.c \
#         ./lib/timelogger.c \
