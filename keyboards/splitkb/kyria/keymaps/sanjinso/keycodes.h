#pragma once

//German Umlaute
#define DE_SS KC_MINS
#define DE_AE KC_QUOT
#define DE_UE KC_LBRC
#define DE_OE KC_SCLN

// Dummy Keycodes
#define KC_NP KC_NO // key is not present
#define KC_NA KC_NO // present but not available for use
#define KC_NU KC_NO // available but not used

//Non-KC_ keycodes
#define KC_RST RESET
#define KC_TOG RGB_TOG
#define KC_MOD RGB_MOD
#define KC_HUI RGB_HUI
#define KC_SAI RGB_SAI
#define KC_VAI RGB_VAI

//Clipboard 
#define KC_UNDO_C LCTL(DE_Z)
#define KC_REDO_C LCTL(DE_Y)
#define KC_CUT_C LCTL(DE_X)
#define KC_COPY_C LCTL(DE_C)
#define KC_PASTE_C LCTL(DE_V)

enum layers { BASE, MBO, MEDR, NAVR, MOUR, NSSL, NSL, FUNL, INVRT, SYMBOL, QWERTY, GAMEPAD};
