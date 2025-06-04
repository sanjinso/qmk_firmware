CONVERT_TO=liatris
EXTRAFLAGS += -flto

# SRC += features/layer_lock.c
SRC += features/layer_lock.c

OLED_ENABLE = no
OLED_DRIVER_ENABLE = no  # Enables the use of OLED displays
ENCODER_ENABLE = no      # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
LEADER_ENABLE = no       # Enable the Leader Key feature

MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control

TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes

BLUETOOTH_ENABLE = no 
CONSOLE_ENABLE = no

LEADER_ENABLE = no       # Enable the Leader Key feature
WPM_ENABLE = no
PET_ENABLE = no

LTO_ENABL = yes

CAPS_WORD_ENABLE = yes
COMMAND_ENABL = yes
DYNAMIC_MACRO_ENABLE = no

LED_UPDATE_USER_ENABLE = yes
KEY_LOCK_ENABLE = yes

DEFERRED_EXEC_ENABLE = yes
