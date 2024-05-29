#pragma once

#ifdef OLED_ENABLE
    #undef OLED_FONT_H
    #define OLED_FONT_H "./oled/glcdfont.c"
#endif

//Reduce Firmware Space
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
#define NO_MUSIC_MODE
#define LAYER_STATE_16BIT

//Try to fix double activation
//#define DEBOUNCE 15

#ifdef HAPTIC_ENABLE
    #define SPLIT_HAPTIC_ENABLE
    // this configuration has no effect because the haptic exclusion is implemented with
    // __attribute__((weak)) bool get_haptic_enabled_key(uint16_t keycode, keyrecord_t *record)
    // in the default keymap and reacts only to mouse clicks. 
    #define NO_HAPTIC_MOD
    #define NO_HAPTIC_FN
    #define NO_HAPTIC_ALPHA
    #define NO_HAPTIC_PUNCTUATION
    #define NO_HAPTIC_NAV 
    #define NO_HAPTIC_NUMERIC
    #define DRV_GREETING       alert_750ms
    #define DRV_MODE_DEFAULT   sharp_tick1
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_KNIGHT
  #define RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_EFFECT_RGB_TEST
  #define RGBLIGHT_EFFECT_ALTERNATING
  #define RGBLIGHT_EFFECT_TWINKLE
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_SLEEP
#endif

#ifdef RGB_MATRIX_ENABLE
  //#define RGB_MATRIX_LED_COUNT 70
  //#define RGB_MATRIX_SPLIT {35,35}

  #define RGB_MATRIX_HUE_STEP 8
  #define RGB_MATRIX_SAT_STEP 8
  #define RGB_MATRIX_VAL_STEP 8
  #define RGB_MATRIX_SPD_STEP 10

  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  #define SPLIT_TRANSPORT_MIRROR
  #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
  #define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
  //#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255

  // RGB Matrix Animation modes. Explicitly enabled
  // For full list of effects, see:
  // https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
  //#define ENABLE_RGB_MATRIX_ALPHAS_MODS
  #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_BREATHING
  #define ENABLE_RGB_MATRIX_BAND_SAT
  #define ENABLE_RGB_MATRIX_BAND_VAL
  #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  #define ENABLE_RGB_MATRIX_CYCLE_ALL
  #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
  #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
  #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
  #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
  #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
  #define ENABLE_RGB_MATRIX_DUAL_BEACON
  #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
  #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  #define ENABLE_RGB_MATRIX_RAINDROPS
  #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
  #define ENABLE_RGB_MATRIX_HUE_BREATHING
  #define ENABLE_RGB_MATRIX_HUE_PENDULUM
  #define ENABLE_RGB_MATRIX_HUE_WAVE
  #define ENABLE_RGB_MATRIX_PIXEL_RAIN
  #define ENABLE_RGB_MATRIX_PIXEL_FLOW
  #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
  // enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
  //#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
  //#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
  // enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
  //#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  //#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
  //#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  //#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  //#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  //#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
  #define ENABLE_RGB_MATRIX_SPLASH
  //#define ENABLE_RGB_MATRIX_MULTISPLASH
  //#define ENABLE_RGB_MATRIX_SOLID_SPLASH
  //#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif


#ifndef NO_DEBUG
  #define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
  #define NO_PRINT
#endif // !NO_PRINT

#define ENCODER_RESOLUTION 2

//#define TAPPING_TERM 220
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

//Without this: Quick Double Tapping makes Autorepeat
//#define QUICK_TAP_TERM
#define QUICK_TAP_TERM_PER_KEY
#define QUICK_TAP_TERM 90

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      8 //6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    52 //64

#ifdef COMBO_ENABLE
  #define COMBO_VARIABLE_LEN
  #define COMBO_COUNT COMBO_VARIABLE_LEN
  #define COMBO_MUST_PRESS_IN_ORDER
  #define COMBO_MUST_TAP_PER_COMBO
  #define COMBO_TERM 45
  //#define COMBO_HOLD_TERM 175  // how long at least one of the combo keys must be held to trigger
#endif

#define LEADER_TIMEOUT 300
#define LAYER_LOCK_IDLE_TIMEOUT 60000

//Caps Word
#define CAPS_WORD_IDLE_TIMEOUT 5000
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT

//Change Both CTLs to Magic Command
#define IS_COMMAND() (get_mods() == MOD_MASK_CTRL)



// If key is pressed quickly and released while 
//Tap-Hold Button is pressed: do hold action. 
#define PERMISSIVE_HOLD
//#define PERMISSIVE_HOLD_PER_KEY

//If key is pressed down while Tap-Hold Button is pressed
// do hold action, even if its under tapping term (not recommended
//for fast typists and homerow mods)
//  Try using combos instead
//#define HOLD_ON_OTHER_KEY_PRESS 
//#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

//Bilateral Combos for Shift (Homerow Rollover)
//#define BILATERAL_COMBINATIONS 100

