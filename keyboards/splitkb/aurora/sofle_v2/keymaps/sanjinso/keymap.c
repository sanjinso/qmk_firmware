#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keycodes.h"
//#include "icons.c"
//#include "oled.c"

#include "features/layer_lock.h"
#include "features/haptic_utils.h"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
    LLOCK = SAFE_RANGE,
};

/* ********
* TAP DANCE
**********/
enum {
    TD_CURNCY,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_CURNCY] = ACTION_TAP_DANCE_DOUBLE(DE_DLR, DE_EURO),
};

uint16_t copy_paste_timer;
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
* Base Layer: BUTECK-XCV
* ,-----------------------------------------------.                              ,------------------------------------------.
* |            |      |      |      |      |      |                              |      |      |      |      |      |       |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | NEXT LYR   |   F  |   M  |   L  |   C  |   P  |                              |   Ü  |   ,  |   .  |   U  |   B  |   ß   |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | ESC        |   S  |   N  |   R  |   T  |   D  |                              |   O  |   A  |   E  |   I  |   H  |   X   |
* |------------+------+------+------+------+------|-------.              ,-------+------+------+------+------+-------|
* | RESET LYR |   Z  |   V  |   W  |   G  |   J  |       |              |       |   Q  |   Ä  |   Ö  |   Y  |   K  |   -   |
* `----------------------+------+--------+--------+-------------.  ,-------------+------+------+------+---------------------'
*                        | ____ | INVRT | MEDIA | NAVI  | MOUSE |  | SYM  | NUM    | FUNC   | ?      | ____ |
*                        |      | Escape| Enter | Space | Tab   |  | Enter| Bspace | Delete | Leader |      |
*                         `-------------------------------------'  `----------------------------------------'
*/
[BASE] = LAYOUT(
  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,                                         KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,  KC_NU,  
  TO(QWERTY),   DE_F,  DE_M,  DE_L,  DE_C,  DE_P,                                     DE_UE,  DE_COMM, DE_DOT, DE_U,  DE_B,  DE_SS,
  KC_ESC,      DE_S,  DE_N,  DE_R,  DE_T,  DE_D,                                     DE_O,   DE_A,    DE_E,   DE_I,  DE_H,  DE_X,
  TO(BASE), GUI_Z, ALT_V, SHT_W, CTL_G, DE_J, KC_NU,                      KC_NU,   DE_Q,   CTL_AE,  SHT_OE, ALT_Y, GUI_K, DE_MINS,
                        KC_NU, UC_TL1, UC_TL2, UC_TL3, UC_TL4,      UC_TR1, UC_TR2, UC_TR3, KC_LEAD, KC_TRNS
),


/*
 * Invert Layer: INVRT
 *
 * ,-----------------------------------------------.                              ,-----------------------------------------.
 * |            |      |      |      |      |      |                              |      |      |      |      |      |      |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      ß     |   B  |   U  |  .   |   ,  |   Ü  |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      X     |   H  |   I  |  E   |   A  |   O  |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+------+                              +------+------+------+------+------+------|
 * | Backspace  |   K  |   Y  |   Ö  |   Ä  |   Q  |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * `------------------------+------+--------+------+-------------.  ,-------------+------+------+------+--------------------'
*                         | ____ | INVRT | MEDIA | NAVI  | MOUSE |  |      |        |        |        | ____ |
*                         |      | Escape| Enter | Space | Tab   |  | Enter| Bspace | Delete |        |      |
*                          `-------------------------------------'  `----------------------------------------'
*/
[INVRT] = LAYOUT(
  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,                                           KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,  KC_NU,  
  DE_SS,   DE_B,  DE_U,  DE_DOT, DE_COMM, DE_UE,                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  DE_X,    DE_H, DE_I, DE_E,  DE_A,   DE_O,                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_BSPC, GUI_K,  ALT_Y,  SHT_OE,  CTL_AE,   DE_Q, KC_NU,                      KC_NU,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),


/*
* Base Layer: MEDIA
*
* ,----------------------------------------------.                              ,-----------------------------------------.
* |            |      |      |      |      |     |                              |      |      |      |      |      |      |
* |------------+------+------+------+------+-----|                              |------+------+------+------+------+------|
* | RESET LYR | ____ | ____ | ____ | ____ | ____ |                              | RGB  | RGB  | RGB  | RGB  | RGB  | ____ |
* |-----------+------+------+------+------+------|                              |------+------+------+------+------+------|
* | LOCK LYR  | GUI  | TM-  | TM+ | TM_TOGGLE| ____ |                              | ____ | PREV | VOLD | VOLU | NEXT | ____ |
* |-----------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
* | RESET LYR | ____ | ____ | ____ | ____ | ____ | ____ | ____ |  | ____ | ____ | ____ | STOP | PLAY | MUTE | ____ | ____ |
* `-----------------------+------+--------+------+------+------|  |------+------+------+------+------+--------------------'
*                       | ____ | INVRT | MEDIA | NAVI  | MOUSE |  |      |        |        | ____ | ____ |
*                       | ____ | Escape| Enter | Space | Tab   |  | STOP | PLAY  | MUTE    | ____ | ____ |
*                        `-------------------------------------'  `--------------------------------------'
*/
[MEDR] = LAYOUT(
  RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT,                    RGB_MODE_XMAS, RGB_MODE_GRADIENT, RGB_MODE_RGBTEST, RGB_MODE_TWINKLE, KC_NU, KC_NU,
                    TO(BASE),  KC_NU,   KC_NU,    KC_NU,    KC_NU,   KC_NU,                                               KC_TOG,  KC_MOD,              KC_HUI,        KC_SAI,        KC_VAI,  KC_SPD,
                    LLOCK,     KC_NU,   KC_F14,    KC_F15,    KC_F16,   KC_NU,                                               KC_NU,   KC_MPRV,             KC_VOLD,       KC_VOLU,       KC_MNXT, KC_NU,
                    TO(BASE),  KC_LGUI, KC_LALT,  KC_LSFT,  KC_LCTL, KC_NU, KC_NU,                                    KC_NU,  KC_NU,   KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_NU,   KC_NU,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_TRNS, KC_TRNS
),


/*
* Navigation Layer: NAVR
*
* ,-----------------------------------------------.                              ,------------------------------------------.
* |            |      |      |      |      |      |                              |      |      |      |      |      |       |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | RESET LYR  | ____ | ____ | ____ | ____ | ____ |                              | COPY | CUT | PASTE  | UNDO | REDO | ____ |
* |------------+------+------+------+------+------|                              |-------+------+------+------+------+------|
* | LOCK LYR   | GUI  | ALT  | CTRL | SHIFT| ____ |                              | CAPS  | LEFT | DOWN | UP   | RIGHT| ____ |
* |------------+------+------+------+------+------+-------------.  ,-------------+-------+------+------+------+------+------|
* | RESET LYR | ____ | ____ | ____ | ____ | ____ | ____ | ____ |  | ____ | ____ | INS   | HOME | PGDN | PGUP | END  | ____ |
* `----------------------+------+--------+--------+------+------|  |------+------+-------+------+------+--------------------'
*                        | ____ | INVRT | MEDIA | NAVI  | MOUSE |  |      |        |        | ____ | ____ |
*                        | ____ | Escape| Enter | Space | Tab   |  | Enter| Bspace | Delete | ____ | ____ |
*                         `-------------------------------------'  `--------------------------------------'
*/
[NAVR] = LAYOUT(
  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,                                          KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,
  TO(BASE),  KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,                              KC_COPY_C, KC_CUT_C, KC_PASTE_C, KC_UNDO_C, KC_REDO_C, KC_NU, 
  LLOCK,     KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,                              KC_CAPS,   KC_LEFT,   KC_DOWN,  KC_UP,     KC_RGHT,    KC_NU,
  TO(BASE),  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NU, KC_NU,                      KC_NU,  KC_INS,    KC_HOME,   KC_PGDN,  KC_PGUP,   KC_END,     KC_NU,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),


/*
 * MouseControl Layer: MOUR
 *
* ,-----------------------------------------------.                              ,------------------------------------------.
* |            |      |      |      |      |      |                              |      |      |      |      |      |       |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | RESET LYR  | ____ | ____ | ____ | ____ | ____ |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | LOCK LYR   | GUI  | ALT  | CTRL | SHIFT| ____ |                              | ____ |MLEFT |MDOWN | MUP  |MRIGHT| ____ |
 * |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | RESET LYR | ____ | ALGR | ____ | ____ | ____ | ____ | ____ |  | ____ | ____ | ____ |WLEFT |WDOWN | WUP  |WRIGHT| ____ |
 * `----------------------+------+--------+------+--------+------|  |------+------+------+------+------+--------------------'
 *                            | ____ | INVR | ____ | ____ | ____ |  |      |      |      | ____ | ____ |
 *                            | ____ | ____ | ____ | ____ | ____ |  | BTN1 | BTN3 | BTN2 | ____ | ____ |
 *                            `----------------------------- ----'  `----------------------------------'
*/
[MOUR] = LAYOUT(
  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,                                            KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,
  TO(BASE), KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,                                 KC_NU, KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,
  LLOCK,    KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,                                 KC_NU, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NU,
  TO(BASE), KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NU, KC_NU,                      KC_NU,  KC_NU, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NU,
                      KC_NP,   UC_TL5,  KC_NU,   KC_NU, KC_NU, KC_BTN1, KC_BTN3, KC_BTN2, KC_NP, KC_TRNS
),


/*
 * MouseControl Layer: MOUR INVRT
 *
* ,-----------------------------------------------.                              ,------------------------------------------.
* |            |      |      |      |      |      |                              |      |      |      |      |      |       |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | RESET LYR  | ____ | ____ | ____ | ____ | ____ |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | LOCK LYR   |MLEFT |MDOWN | MUP  |MRIGHT| ____ |                              | ____ |SHIFT | CTRL | ALT  | GUI| ____ |
 * |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | RESET LYR |WLEFT |WDOWN | WUP  |WRIGHT| ____ | ____ | ____ |  | ____ | ____ | ____ | ____ | ____ | ALGR | ____ | ____ |
 * `----------------------+------+--------+------+--------+------|  |------+------+------+------+------+--------------------'
 *                            | ____ | ____ | ____ | ____ | ____ |  |      |      |      | ____ | ____ |
 *                            | ____ | ____ | ____ | ____ | ____ |  | BTN1 | BTN3 | BTN2 | ____ | ____ |
 *                            `----------------------------- ----'  `----------------------------------'
*/
[MOURI] = LAYOUT(
  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,                                           KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,
  TO(BASE), KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,                                KC_NU, KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,
  LLOCK,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NU,                                KC_NU, KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU, 
  TO(BASE), KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NU, KC_NU,                      KC_NU,  KC_NU, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_NU,
                      KC_NP,   KC_NP,  KC_BTN2,   KC_BTN3, KC_BTN1, KC_BTN1, KC_BTN3, KC_BTN2, KC_NP, KC_TRNS
),


/*
 * Function Layer: FUNL
 *
*  ,-----------------------------------------------.                               ,------------------------------------------.
 * |            |      |      |      |      |      |                               |      |      |      |      |      |       |
 * |------------+------+------+------+------+------|                               |------+------+------+------+------+-------|
 * | RESET LYR  |  F12 |  F7  |  F8  |  F9  | PRINT |                              | KeyLock | MR1 | MR2 | MP1 | MP2 | MStop |
 * |------------+------+------+------+------+-------|                              |------+------+------+------+------+------|
 * | LOCK LYR   |  F11 |  F4  |  F5  |  F6  | SLock |                              | CLR EEROM | SHIFT| CTRL | ALT  | GUI  | ____ |
 * |------------+------+------+------+------+-------+-------------.  ,-------------+------+------+------+------+------+------|
 * | RESET LYR |  F10 |  F1  |  F2  |  F3  | PAUSE | ____ | ____ |  | ____ | ____ | ____ | ____ | BRGHT- | BRGHT+ | ____ | DEBUG |
 * `-----------------------+-------+-------+-------+-------+------|  |------+------+------+------+------+--------------------'
 *                         | _____ | _____ | _____ | _____ | ____ |  | ____ | ____ | ____ | ____ | ____ |
 *                         | RGB Vibrance  | RGB Saturation | RGB Hue   | RGB Mode | RGB Toggle  |  |      |      |      |      |      |
 *                         `--------------------------------------'  `----------------------------------'
*/ 
[FUNL] = LAYOUT(
  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,                                              KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,
  TO(BASE),  KC_F12, KC_F7,  KC_F8,  KC_F9, KC_PSCR,                                     DM_REC1,  DM_PLY1, DM_REC2, DM_PLY2, KC_NU, DM_RSTP,
  TO(FUNL),  KC_F11, KC_F4,  KC_F5,  KC_F6, KC_SCROLL_LOCK,                              EE_CLR,   KC_LOCK, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_NU, KC_NU,
  TO(BASE),  KC_F10, KC_F1,  KC_F2,  KC_F3, KC_PAUS, KC_NU,                      KC_NU,  KC_NU,   KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,   DB_TOGG,
                            RGB_VAI,  RGB_SAI, RGB_HUI,  RGB_MOD, RGB_TOG,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),


/*
 * Number Layer: NSL
 *
* ,-----------------------------------------------.                              ,------------------------------------------.
* |            |      |      |      |      |      |                              |      |      |      |      |      |       |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* |            |  -   |  7   |  8   |  9   |  +   |                              | ___  | ___  | ___  | ___  | ___  |  ___   |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LOCK LYR  | .   |  4   |  5   |  6   |  ,   |                              | ___  | SHIFT| CTRL | ALT  | GUI  |  ___   |
 * |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |            |  /   |  1   |  2   |  3   |  *   |  ___ |  ___ |  |  ___ |  ___ | ___  | ___  |  ___ |  ___ | ___  |  ___   |
 * `----------------------+------+--------+------+--------+------|  |------+------+------+------+------+----------------------'
 *                        |  ___ |  ___   | _____ |  ___   | ___ |  |  ___ |  ___ |  ___ | ___  | ___  |
 *                        |  ___ |Backspce| Space |   0    |  =  |  |      |      |      |      |      |
 *                        `--------------------------------------'  `----------------------------------'
*/
[NSL] = LAYOUT(
  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,                                       KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,
  TO(BASE),  DE_MINS, DE_7, DE_8, DE_9, DE_PLUS,                                  KC_NA, KC_NA,  KC_NA,   KC_NA,   KC_NU,   KC_NU,
  LLOCK,   DE_DOT,  DE_4, DE_5, DE_6, DE_COMM,                                    KC_NA, KC_NA,  KC_NA,   KC_NA,   KC_NA,   KC_NU,
  TO(BASE),DE_BSLS, DE_1, DE_2, DE_3, DE_ASTR, KC_NU,                      KC_NU,  KC_NA, KC_LCTL,   KC_LSFT, KC_LALT, KC_LGUI, KC_NU,
                         KC_NP, KC_BSPC, KC_SPC, DE_0, DE_EQL,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS
),


/*
* Symbol Layer: SYMBOL
*
* ,-------------------------------------------.                              ,------------------------------------------.
* |        |      |      |      |      |      |                              |      |      |      |      |      |       |
* |--------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* |        |  !   |  ?   |  [   |  ]   |  ^   |                              |   °  |      |  &   |  %   |  |   |   §    |
* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
* |  LOCK  |  \   |  /   |  (   |  )   |  @   |                              |   `  |  {   |  }   |  +   |  =   |   ²    |
* |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
* |        |  #   |  $€  |  <   |  >   |  *   |      |      |  |      |      |   ~  |      |      |  "   |  '   |   ³    |
* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
*                        |      |      |      |      |      |  |      |      |      |      |      |
*                        |      |      |      |      |      |  |      |      |      |      |      |
*                        `----------------------------------'  `----------------------------------'
*/
[SYMBOL] = LAYOUT(
  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,                                                      KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,
    TO(BASE), DE_EXLM, DE_QUES,   DE_LBRC, DE_RBRC, DE_CIRC,                                     DE_DEG, KC_TRNS, DE_AMPR,DE_PERC,DE_PIPE,DE_SECT,
    TO(SYMBOL), DE_BSLS, DE_SLSH,  DE_LPRN, DE_RPRN, DE_AT,                                      DE_GRV, DE_LCBR, DE_RCBR, DE_PLUS, DE_EQL, DE_SUP2,
    TO(BASE), DE_HASH, TD(TD_CURNCY), DE_LABK, DE_RABK, DE_ASTR, KC_NU,                      KC_NU, DE_TILD, KC_TRNS,  KC_TRNS, DE_DQUO,  DE_QUOT, DE_SUP3,
                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/*
 * Base Layer: QWERTY
 *
* ,-----------------------------------------------.                              ,------------------------------------------.
* |            |      |      |      |      |      |                              |      |      |      |      |      |       |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | Next LYR |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |-----------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LSFT      |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |-----------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Reset LYR|   Z  |   X  |   C  |   V  |   B  | CCCV |      |  | Del  |Leader|   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `-------------------------+------+------+------+------+      |  |------+------+------+------+------+----------------------'
 *                       |  ___ | INVERT | MEDIA | NAVI  | MOUSE|  | SYM  | NUM      | FUNC   |        |       |
 *                       |      | Enter  | Escape| Space | Tab  |  | Enter| Bspace   | Delete |        |       |
 *                       `--------------------------------------'  `-------------------------------------------'
 */
[QWERTY] = LAYOUT(
  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,                                                                  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,
    TO(GAME), DE_Q, DE_W, DE_E, DE_R, DE_T,                                                                  KC_Y, KC_U,  KC_I,  KC_O,  KC_P,  KC_PIPE,
    KC_LSFT,  DE_A, DE_S, DE_D, DE_F, DE_G,                                                                  DE_H, DE_J, DE_K, DE_L, DE_X, DE_QUOT,
    TO(BASE), GUI_Z, ALT_X, SHT_C, CTL_V, DE_B, KC_NU,                                                   KC_NU,  DE_N,  CTL_M, SHT_COMM, ALT_DOT, GUI_SLSH, DE_MINS, 
        KC_NU, LT(INVRT, KC_ESC), LT(MEDR, KC_ENT), LT(NAVR, KC_SPC), LT(MOUR, KC_TAB),     LT(SYMBOL, KC_ENT), LT(NSL, KC_BSPC), LT(FUNL, KC_DEL), KC_NU, KC_TRNS
),


 /*
 * Base Layer: GAMING
 * C V Y X      G T B H Z N M J U     K I 
 *
 * Y, B, Z, N, M, J, U 
 * ,----------------------------------------------.                              ,------------------------------------------.
 * |            |      |      |      |      |     |                              |      |      |      |      |      |       |
 * |------------+------+------+------+------+-----|                              |------+------+------+------+------+-------|
 * | RESET LYR |  I   |   Q  |   T  |   E  |   R  |                               |      |      |      |      |      |        |
 * |-----------+------+------+------+------+------|                               |------+------+------+------+------+--------|
 * | LTAB      | Shift|   A  |   W  |   D  |   F  |                               |      |      |      |      |      |        |
 * |-----------+------+------+------+------+------+--------------.  ,-------------+------+------+------+------+------+--------|
 * |  Z        | CTRL |   X  |   S  |   C  |   G  |       |      |  |      |      |      |      |      |      |      |        |
 * `-------------------------+------+------+------+-------+      |  |------+------+------+------+------+----------------------'
 *                       | ____ |        |        |       |      |  |      |          |         |        |       |
 *                       |      |  ESC   | ALT/V | Space  |MOD1/H|  |      |          |         |        |       |
 *                       `--------------------------------------'  `---------------------------------------------'
 */
[GAME] = LAYOUT(
  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,                                                      KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,
    TO(BASE),KC_I,   KC_Q,    KC_T,    KC_E,    KC_R,                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TAB,  KC_LSFT, KC_A,    KC_W,    KC_D,    KC_F,                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_Z,    KC_LCTL, KC_X,    KC_S,    KC_C,    KC_G, KC_NU,                            KC_NU,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
               KC_NU, KC_ESC, LALT_T(DE_V), KC_SPC,  LT(GAME_2, KC_H),     KC_ENT, KC_BSPC, KC_DEL, KC_TRNS, KC_TRNS
),


 /*
 * Base Layer: GAMING_2
 *
 * ,-----------------------------------------------.                              ,------------------------------------------.
* |            |      |      |      |      |      |                              |      |      |      |      |      |       |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | RESET LYR |  F1  |  F2  |  F3  |  F4  |  F5  |                               |      |      |      |      |      |        |
 * |-----------+------+------+------+------+------|                               |------+------+------+------+------+--------|
 * |     J     |   1  |   2  |   3  |   4  |   5  |                               |      |      |      |      |      |        |
 * |-----------+------+------+------+------+------+--------------.  ,-------------+------+------+------+------+------+--------|
 * |     U     |   Y  |   B  |   N  |   M  |   Z  |       |      |  |      |      |      |      |      |      |      |        |
 * `-------------------------+------+------+------+-------+      |  |------+------+------+------+------+----------------------'
 *                       | ____ |        |        |       |      |  |      |          |         |        |       |
 *                       |      |        |        | Space |  H   |  |      |          |         |        |       |
 *                       `--------------------------------------'  `---------------------------------------------'
 */
[GAME_2] = LAYOUT(
   KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,                                                  KC_NU, KC_NU, KC_NU, KC_NU, KC_NU, KC_NU,
   TO(BASE),KC_F1, KC_F2,  KC_F3,   KC_F4,   KC_F5,                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_J,    KC_1, KC_2,    KC_3,    KC_4,    KC_5,                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_U,    KC_Y, KC_B,    KC_N,    KC_M,    KC_Z, KC_NU,                             KC_NU,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

};

/* ********
* TAPPING TERM (FIXED)
**********/

//Tapping Term 200
//How long does it have to be pressed to activate layer instead of keypress
//Lower Tapping term is needed for quicker activation of modifier. However there are Combos too.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_Z:
            return TAPPING_TERM + 10; //210
        case ALT_V:
            return TAPPING_TERM - 20; //180
        case SHT_W:
            return TAPPING_TERM - 40; //170
        case CTL_G:
            return TAPPING_TERM - 30; //170
            //return TAPPING_TERM - 30; //170

        case GUI_K:
            return TAPPING_TERM + 10; //210
        case ALT_Y:
            return TAPPING_TERM + 30; //230
        case CTL_AE:
            return TAPPING_TERM + 30; //230
        case SHT_OE:
            return TAPPING_TERM - 90; //110
            //return TAPPING_TERM - 50; //170
            //return TAPPING_TERM - 30; //170

        default:        
            return TAPPING_TERM;

        case UC_TR2:
            return TAPPING_TERM - 45; //120 
        case UC_TR1:
            return TAPPING_TERM - 50; //140 
    }
}


/* *********
* QUICK TAPPING TERM (DOUBLE_PRESS_AUTO_REPEAT_TERM)
**********/
//QUICK TAPPING TERM 80
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //BSPC -> NUML
        case UC_TR2: 
            return QUICK_TAP_TERM -20; //60
        //DEL -> FUNL
        case UC_TR3:
            return QUICK_TAP_TERM -10; //70
        //ENTER -> SYM
        case UC_TR1:
            return QUICK_TAP_TERM -10; //60
        default:
            return QUICK_TAP_TERM;
    }
}


/* ********
* MISC
**********/
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        //case DE_A ... DE_Z:
        case KC_A ... KC_Z:
        case DE_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        //case DE_1 ... DE_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case DE_BSLS:
        case DE_SLSH:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}


/* 
* Permissive Hold per Key
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_G:
            return true;
        case ALT_V:
            return true;
        default:
            return false;
    }
}
*/

/*
* Hold on other key per key
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_BSPC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
*/ 


/* ********
* COMBOS
**********/
// #define CTRL_W_COMBO CTL_T(KC_W)

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case CTRL_W_COMBO:
//             if (record->event.pressed) {
//                 // Key is pressed
//                 register_code(KC_LCTL);
//                 register_code(KC_W);
//             } else {
//                 // Key is released
//                 unregister_code(KC_W);
//                 unregister_code(KC_LCTL);
//             }
//             return false; // We handled this keypress, QMK should skip it
//         default:
//             return true; // Let QMK send the enter press/release events
//     }
// }

//Combos for instant activation of shortcuts
//Name of combos
#ifdef COMBO_ENABLE
enum combo_events  {
    CTRL_C,
    CTRL_V,
    CTRL_X,
    CTRL_S,
    CTRL_Z,
    SHIFT_CTRL_Z,

    ALT_TAB,
    CTRL_TAB,
    SHIFT_CTRL_TAB,

    WIN_CTRL_LEFT,
    WIN_CTRL_RIGHT,

    ALT_UP,
    ALT_LEFT,
    ALT_RIGHT,
    ALT_DOWN,
    RWIN_SHIFT_S,
    // CTRL_W,
    // CTRL_W_B,

    BSPC_LSFT_CLEAR,
    QUICK_WINDOWS,
    QUICK_VBOX,

    CTRL_A,

    COMBO_LENGTH

};
int COMBO_LEN = COMBO_LENGTH;

//Combo Activation
const uint16_t PROGMEM copy_combo[]  = { CTL_G, DE_C, COMBO_END };
const uint16_t PROGMEM paste_combo[] = { CTL_G, DE_V, COMBO_END };
const uint16_t PROGMEM cut_combo[] = { CTL_G, DE_X, COMBO_END };
const uint16_t PROGMEM save_combo[]  = { CTL_G, DE_S, COMBO_END };
const uint16_t PROGMEM undo_combo[]  = { CTL_G, DE_Z, COMBO_END };
const uint16_t PROGMEM redo_combo[]  = { CTL_G, SHT_W, DE_Z, COMBO_END };

const uint16_t PROGMEM alt_tab_combo[] = { ALT_V, UC_TL4, COMBO_END };
const uint16_t PROGMEM ctrl_tab_combo[] = { CTL_G, UC_TL4, COMBO_END };
const uint16_t PROGMEM shift_ctrl_tab_combo[] = { CTL_G, SHT_W, UC_TL4, COMBO_END };

const uint16_t PROGMEM win_ctrl_left_combo[] = { GUI_Z, CTL_G, KC_LEFT, COMBO_END };
const uint16_t PROGMEM win_ctrl_right_combo[] = { GUI_Z, CTL_G, KC_RGHT, COMBO_END };

const uint16_t PROGMEM alt_up_combo[] = { ALT_V, KC_UP, COMBO_END };
const uint16_t PROGMEM alt_down_combo[] = { ALT_V, KC_DOWN, COMBO_END };
const uint16_t PROGMEM alt_left_combo[] = { ALT_V, KC_LEFT, COMBO_END };
const uint16_t PROGMEM alt_right_combo[] = { ALT_V, KC_RGHT, COMBO_END };
const uint16_t PROGMEM rwin_shift_s_combo[] = { GUI_K, SHT_OE, DE_S, COMBO_END };
// const uint16_t PROGMEM close_combo[]  = { CTL_G, DE_W, COMBO_END };
// const uint16_t PROGMEM close_combo_b[]  = { DE_R, DE_W, COMBO_END };

const uint16_t PROGMEM clear_line_combo[] = {KC_BSPC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM quick_win_combo[]  = {UC_TL4, UC_TR1, COMBO_END };
const uint16_t PROGMEM quick_vbox_combo[]  = {GUI_Z, CTL_G, COMBO_END };

const uint16_t PROGMEM select_all_combo[] = { CTL_G, DE_A, COMBO_END };
 

//Combo Action
combo_t key_combos[COMBO_COUNT] = {
    [CTRL_C]  = COMBO(copy_combo, LCTL(DE_C)),
    [CTRL_V] = COMBO(paste_combo, LCTL(DE_V)),
    [CTRL_X] = COMBO(cut_combo, LCTL(DE_X)),
    [CTRL_S]  = COMBO(save_combo, LCTL(DE_S)),
    [CTRL_Z] = COMBO(undo_combo, LCTL(DE_V)),
    [SHIFT_CTRL_Z] = COMBO(redo_combo, LCA_T(DE_Z)),
    [ALT_TAB] = COMBO_ACTION(alt_tab_combo),
    [CTRL_TAB] = COMBO(ctrl_tab_combo, LCTL(KC_TAB)),
    [SHIFT_CTRL_TAB] = COMBO(shift_ctrl_tab_combo, LCA_T(KC_TAB)),
    [WIN_CTRL_LEFT] = COMBO(win_ctrl_left_combo, LGUI(LCTL(KC_TAB))),
    [WIN_CTRL_RIGHT] = COMBO(win_ctrl_right_combo, LGUI(LCTL(KC_TAB))),
    [ALT_UP] = COMBO(alt_up_combo, LALT(KC_UP)),
    [ALT_DOWN] = COMBO(alt_down_combo, LALT(KC_DOWN)),
    [ALT_LEFT] = COMBO(alt_left_combo, LALT(KC_LEFT)),
    [ALT_RIGHT] = COMBO(alt_right_combo, LALT(KC_RGHT)),
    [RWIN_SHIFT_S] = COMBO(rwin_shift_s_combo, LGUI(LSFT(DE_S))),
    // [CTRL_W] = COMBO(close_combo, LCTL(DE_W)),
    // [CTRL_W_B] = COMBO(close_combo_b, LCTL(DE_W)),
    [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
    [QUICK_WINDOWS] = COMBO_ACTION(quick_win_combo),
    [QUICK_VBOX] = COMBO_ACTION(quick_vbox_combo),
    [CTRL_A] = COMBO_ACTION(select_all_combo),
};


//Combo Processing
void process_combo_event(uint16_t combo_index, bool pressed) {
    action_tapping_process((keyrecord_t){});
    switch(combo_index) {
        case ALT_TAB:
            if (pressed) {
                tap_code16(LALT(KC_TAB)); 
                //DRV_pulse(7);
                //DRV_pulse(sh_dblsharp_tick);
            }
            break;
        case BSPC_LSFT_CLEAR:
            if (pressed) {
                tap_code16(KC_END);
                tap_code16(S(KC_HOME));
                tap_code16(KC_BSPC);
            }   
            break;
        case QUICK_WINDOWS:
            if (pressed) {
                tap_code16(KC_LGUI);
            }
            break;
        case QUICK_VBOX:
            if (pressed) {
                register_code16(KC_LGUI);
                tap_code16(KC_LCTL);
            }       
            break;
    }
}

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        // case CTRL_W_B:
           // return false;
        case CTRL_A:
            return false;
    }

    /*
    switch (combo_index) {
        case CTRL_TAB:
           return false;
    }
    */ 
    return true;
}

bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case RWIN_SHIFT_S:
           return false;
        case SHIFT_CTRL_Z:
           return false;
        case SHIFT_CTRL_TAB:
           return false;
        case CTRL_TAB:
           return false;
        case WIN_CTRL_LEFT:
           return false;
        case WIN_CTRL_RIGHT:
           return false;
        case BSPC_LSFT_CLEAR:
            return false;
        case QUICK_WINDOWS:
            return false;
    }    
    return true;
}
#endif


/* ********
* TAPPING TERM CALCULATOR
**********/
/*
float thumb_factor  = 0.95;
float index_factor  = 1.1;
float middle_factor = 1.2;
float ring_factor   = 1.25;
float pinky_factor  = 1.15;
float td_factor     = 1.4;

// define the per_key_tapping_term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // thumb keys
        case RSFT_T(KC_DEL):
            return TAPPING_TERM * thumb_factor;
        case RCTL_T(KC_TAB):
            return TAPPING_TERM * thumb_factor;
        case LT(_NAV, KC_LEFT):
            return TAPPING_TERM * thumb_factor;
        case LT(_NAV, KC_RIGHT):
            return TAPPING_TERM * thumb_factor;
        case LT(_LOWER, KC_BSPC):
            return TAPPING_TERM * thumb_factor;
        case LT(_LOWER_DE, KC_BSPC):
            return TAPPING_TERM * thumb_factor;
        case LT(_RAISE, KC_ENT):
            return TAPPING_TERM * thumb_factor;
        case LT(_RAISE_DE, KC_ENT):
            return TAPPING_TERM * thumb_factor;
        case LT(_NAV, KC_SPC):
            return TAPPING_TERM * 1.0;
        case LALT_T(KC_ESC):
            return TAPPING_TERM * thumb_factor;

        // index finger keys
        case LCTL_T(KC_P):
            return TAPPING_TERM * index_factor;
        case RCTL_T(KC_L):
            return TAPPING_TERM * (index_factor + 0.1);
        case LT(_NUM, KC_B):
            return TAPPING_TERM * (index_factor + 0.1);
        case LT(_NUM, KC_J):
            return TAPPING_TERM * index_factor;

        // middle finger keys
        case LSFT_T(KC_F):
            return TAPPING_TERM * middle_factor;
        case RSFT_T(KC_U):
            return TAPPING_TERM * middle_factor;

        // ring finger keys
        case LALT_T(KC_W):
            return TAPPING_TERM * ring_factor;
        case LALT_T(KC_Y):
            return TAPPING_TERM * ring_factor;
        case LGUI_T(KC_TAB):
            return TAPPING_TERM * ring_factor;

        // pinky keys
        case LGUI_T(KC_Q):
            return TAPPING_TERM * pinky_factor;
        case RGUI_T(KC_SCLN):
            return TAPPING_TERM * pinky_factor;
        case RGUI_T(KC_LBRC):
            return TAPPING_TERM * pinky_factor;
        case LT(_MOUSE, KC_Z):
            return TAPPING_TERM * pinky_factor;
        case LT(_MOUSE, KC_SLSH):
            return TAPPING_TERM * pinky_factor;
        case LCTL_T(KC_CAPS):
            return TAPPING_TERM * pinky_factor;

        // tap-dance actions
        case TD(TD_PRN):
            return TAPPING_TERM * td_factor;
        case TD(TD_BRC):
            return TAPPING_TERM * td_factor;
        case TD(TD_CBR):
            return TAPPING_TERM * td_factor;
        case TD(TD_PRN_DE):
            return TAPPING_TERM * td_factor;
        case TD(TD_BRC_DE):
            return TAPPING_TERM * td_factor;
        case TD(TD_CBR_DE):
            return TAPPING_TERM * td_factor;
        case TD(TD_VIM_GG):
            return TAPPING_TERM * td_factor;

        default:
            return TAPPING_TERM;
    }
}
*/



/* ********
* ENCODERS
**********/

 /*
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    //First Encoder
    
    if (index == 0) {
        switch (biton32(layer_state)) {
            case QWERTY:
                // History scrubbing. For Adobe products, hold shift while moving
                // backward to go forward instead.
                if (clockwise) {
                    tap_code16(C(KC_Z));
                } else {
                    tap_code16(C(KC_Y));
                }
                break;
            default:
                // Switch between windows on Windows with alt tab.
                if (clockwise) {
                    if (!is_alt_tab_active) {
                        is_alt_tab_active = true;
                        register_code(KC_LALT);
                    }
                    alt_tab_timer = timer_read();
                    tap_code16(KC_TAB);
                } else {
                    tap_code16(S(KC_TAB));
                }
                break;
        }
    //Encoder 2
    } else if (index == 1) {

        
    //switch (biton32(layer_state)) {
    //switch (get_highest_layer(layer_state)) {
    switch (biton32(layer_state)) {
        case FUNL:
            //History Control
            if (clockwise) {
                tap_code16(C(KC_Y));
            } else {
                tap_code16(C(KC_Z));
            }
            break;
    
        case MEDR:
            // Volume control.
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
        }
            break;
    
        case QWERTY:
            //Scrolling
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
            break;

        case BASE:
            //Scrolling
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
            break;

        case MOUR:
            //Zoomig
            if (clockwise) {
                tap_code16(C(DE_MINS));
            } else {
                tap_code16(C(DE_PLUS));
            }
            break;
    }
        
    return true;
}
#endif
    */


/*

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    // 0 is left-half encoder,
    // 1 is right-half encoder
    if (index == 0) {
        switch (biton32(layer_state)) {
            case MEDR:
                // Volume control
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;

        }
                    
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif

*/


#ifdef ENCODER_ENABLE


static bool is_alt_pressed;
static bool is_ctrl_pressed;

bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0 is left-half encoder               
    // 1 is right-half encoder
    if (index == 0) {

        switch (get_highest_layer(layer_state)) {
        //switch (biton32(layer_state)) {

            case BASE:
                is_ctrl_pressed = get_mods() & MOD_MASK_CTRL;
                if (is_ctrl_pressed) {
                     // Switch between windows on Windows with alt esc.
                    register_code(KC_LALT);
                    is_alt_tab_active = true;
                    if (clockwise) {            
                        tap_code(KC_ESC);
                    } else {
                        register_code(KC_LSFT);
                        tap_code(KC_ESC );
                        unregister_code(KC_LSFT); 
                    }
                    alt_tab_timer = timer_read();
                    break;

                } else {
                    
                    is_alt_pressed = get_mods() & MOD_MASK_ALT;
                    if (is_alt_pressed) {
                        if (clockwise) {            
                            tap_code(KC_TAB);
                        } else {
                            register_code(KC_LSFT);
                            tap_code(KC_TAB);
                            unregister_code(KC_LSFT); 
                        }
                    
                    } else {
                        // Volume control
                        if (clockwise) {
                            tap_code(KC_VOLU);
                        } else {
                            tap_code(KC_VOLD);
                        }
                        break;       
                    }

                }



 
               
            /*
     
            */      
            case NAVR:
                // Scroll
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case INVRT:
                // Scroll
                if (clockwise) {
                    tap_code(KC_RIGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
            case MEDR:
                // Scroll
                if (clockwise) {
                    //tap_code(KC_MOD);
                } else {
                    //tap_code(SHT_MOD);
                }
                break;

            case SYMBOL:
                // Scroll
                if (clockwise) {
                    //tap_code(DE_SLSH);
                } else {
                    //tap_code(DE_BSLS);
        }       
                break;
        }
        return false;

    }
    if (index == 1) {
        //switch (biton32(layer_state)) {
        switch (get_highest_layer(layer_state)) {
            case BASE:
                // Volume control
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case NAVR:
                // Scroll
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case MOUR:

                // Scroll
                if (clockwise) {
                    register_code(KC_LCTL);
                    tap_code(DE_PLUS);
                    unregister_code(KC_LCTL); 

                } else {
                    register_code(KC_LCTL);
                    tap_code(DE_MINS);
                    unregister_code(KC_LCTL);                 }
                break;
            case FUNL:
                //History Control
                if (clockwise) {
                    //tap_code16(C(KC_Y));
                } else {
                    //tap_code16(C(KC_Z));
                }
            break;
    
        }
        return true;
    }

    
    
    return true;
}
#endif



/* ********
* HAPTIC FEEDBACK
**********/

//https://www.reddit.com/r/ErgoMechKeyboards/comments/134n3mq/help_haptic_device_on_both_split_halves/
/*
void housekeeping_task_user(void) {
    if (!is_keyboard_master()) {
        static layer_state_t temp_state = 0;
        if (temp_state != layer_state) {
            temp_state = layer_state_set_user(layer_state);
        }
    }
}
*/
//This will trigger the layer_state_set_user function if the layer changes, but only on the slave side (since it's not processed normally).
//You could just add the code here instead, but either way, it should get you what you want.
