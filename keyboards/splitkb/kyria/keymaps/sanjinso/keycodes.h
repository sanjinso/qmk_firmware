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
// #define KC_RST RESET
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

// Left-hand Bottom row mods BUTECK (zvwg)
#define GUI_Z LGUI_T(DE_Z)
#define ALT_V LALT_T(DE_V)
#define SHT_W LSFT_T(DE_W)
#define CTL_G LCTL_T(DE_G)

// Right-hand Bottom row mods BUTECK (äöyk)
#define CTL_AE LCTL_T(DE_AE)
#define SHT_OE RSFT_T(DE_OE)
#define ALT_Y LALT_T(DE_Y)
#define GUI_K LGUI_T(DE_K)

// Left-hand Bottom row mods QWERTY
#define GUI_Z LGUI_T(DE_Z)
#define ALT_X LALT_T(DE_X)
#define SHT_C LSFT_T(DE_C)
#define CTL_V LCTL_T(DE_V)

// Right-hand Bottom row mods QWERTY
#define CTL_M LCTL_T(DE_M)
#define SHT_COMM RSFT_T(DE_COMM)
#define ALT_DOT LALT_T(DE_DOT)
#define GUI_SLSH LGUI_T(DE_SLSH)

// Thumbcluster
#define UC_TL1 LT(INVRT, KC_NU)
#define UC_TL2 LT(MEDR,  KC_ESC)
#define UC_TL3 LT(NAVR,  KC_SPC)
#define UC_TL4 LT(MOUR,  KC_TAB)
#define UC_TL5 LT(MOURI, KC_TAB)

#define UC_TR1 LT(SYMBOL, KC_ENT)
#define UC_TR2 LT(NSL,    KC_BSPC)
#define UC_TR3 LT(FUNL,   KC_DEL)

// MISC
#define KC_LOCK QK_LOCK
#define KC_LEAD QK_LEAD 

enum custom_layers { BASE, INVRT, MEDR, NAVR, NAVRI, MOUR, MOURI, FUNL, NSL, SYMBOL, QWERTY, GAME, GAME_2 };
