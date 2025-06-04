#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#define NO_MUSIC_MODE
#define LAYER_STATE_16BIT

#define DEBOUNCE 20

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_SLEEP
#endif

//DEBUGGING
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#define ENCODER_RESOLUTION 2

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

//Without this: Quick Double Tapping makes Autorepeat
//#define QUICK_TAP_TERM
#define QUICK_TAP_TERM_PER_KEY
#define QUICK_TAP_TERM 90

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD

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
#define MOUSEKEY_MAX_SPEED      8
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    52


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
//#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
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

