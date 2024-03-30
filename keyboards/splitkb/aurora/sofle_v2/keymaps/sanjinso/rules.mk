CONVERT_TO=liatris

EXTRAFLAGS += -flto
SRC += features/layer_lock.c
SRC += features/haptic_utils.c

HAPTIC_ENABLE = yes
HAPTIC_DRIVER += DRV2605L

OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes  # Enables the use of OLED dislays

MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control

RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE = yes

ENCODER_ENABLE = yes      # Enables the use of one or more encoders
#ENCODER_MAP_ENABLE = yes


TAP_DANCE_ENABLE = yes
KEY_LOCK_ENABLE = yes
COMBO_ENABLE = yes

BLUETOOTH_ENABLE = no 
CONSOLE_ENABLE = no

LEADER_ENABLE = no       # Enable the Leader Key feature
WPM_ENABLE = no
PET_ENABLE = no

LTO_ENABLE = yes


CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes


CONSOLE_ENABLE = yes