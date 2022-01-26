#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keycodes.h"
 
uint16_t copy_paste_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
* Base Layer: BUTECK-XCV
*
* ,-----------------------------------------------.                              ,------------------------------------------.
* | RESET LYR  |   F  |   M  |   L  |   C  |   P  |                              |   Ü  |   ,  |   .  |   U  |   B  |   ß   |
* |------------+------+------+------+------+------|                              |------+------+------+------+------+-------|
* | LOCK LYR   |   S  |   N  |   R  |   T  |   D  |                              |   O  |   A  |   E  |   I  |   H  |   X   |
* |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-------|
* | TOGGLE LYR |   Z  |   V  |   W  |   G  |   J  | ____ | RESET|  | ____ | ____ |   Q  |   Ä  |   Ö  |   Y  |   K  |   -   |
* `----------------------+------+--------+--------+------+------|  |------+------+------+------+------+---------------------'
*                        | ____ | INVRT | MEDIA | NAVI  | MOUSE |  | SYM  | NUM    | FUNC   | ?      | ____ |
*                        |      | Escape| Enter | Space | Tab   |  | Enter| Bspace | Delete | Leader |      |
*                         `-------------------------------------'  `----------------------------------------'
*/
[BASE] = LAYOUT(
  TO(BASE),   DE_F,         DE_M,           DE_L,         DE_C,         DE_P,                                            DE_UE,  DE_COMM,      DE_DOT,        DE_U,         DE_B,         DE_SS,
  KC_NU,      LGUI_T(DE_S), LALT_T(DE_N),   LCTL_T(DE_R), LSFT_T(DE_T), DE_D,                                            DE_O,   LSFT_T(DE_A), LCTL_T(DE_E),  LALT_T(DE_I), LGUI_T(DE_H), DE_X,
  TO(NSL), DE_Z,         ALGR_T(DE_V),   DE_W,         DE_G,         DE_J, KC_NU,   KC_RST,       KC_NU,     KC_NU,   DE_Q,   DE_AE,        DE_OE,         ALGR_T(DE_Y), DE_K,         DE_MINS,
                KC_NU, LT(INVRT, KC_ESC), LT(MEDR, KC_ENT), LT(NAVR, KC_SPC), LT(MOUR, KC_TAB),      LT(SYMBOL, KC_ENT), LT(NSL, KC_BSPC), LT(FUNL, KC_DEL), KC_NU, KC_NU
),


/*
 * Invert Layer: INVRT
 *
 * ,-----------------------------------------------.                              ,-----------------------------------------.
 * |      ß     |   B  |   U  |  .   |   ,  |   Ü  |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      X     |   H  |   I  |  E   |   A  |   O  |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | Backspace  |   K  |   Y  |   Ö  |   Ä  |   Q  | ____ | ____ |  | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * `------------------------+------+--------+------+------+------|  |------+------+------+------+------+--------------------'
*                         | ____ | INVRT | MEDIA | NAVI  | MOUSE |  |      |        |        |        | ____ |
*                         |      | Escape| Enter | Space | Tab   |  | Enter| Bspace | Delete |        |      |
*                          `-------------------------------------'  `----------------------------------------'
*/
[INVRT] = LAYOUT(
  DE_SS,   DE_B, DE_U,   DE_DOT, DE_COMM, DE_UE,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  DE_X,    LGUI_T(DE_H), LALT_T(DE_I), LCTL_T(DE_E), LSFT_T(DE_A), DE_O,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_BSPC, DE_K, DE_Y,   DE_OE,  DE_AE,   DE_Q,  KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),


/*
* Base Layer: MEDIA
*
* ,----------------------------------------------.                              ,-----------------------------------------.
* | RESET LYR | ____ | ____ | ____ | ____ | ____ |                              | RGB  | RGB  | RGB  | RGB  | RGB  | ____ |
* |-----------+------+------+------+------+------|                              |------+------+------+------+------+------|
* | LOCK LYR  | GUI  | ALT  | CTRL | SHIFT| ____ |                              | ____ | PREV | VOLD | VOLU | NEXT | ____ |
* |-----------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
* | TOGGLELYR | ____ | ALGR | ____ | ____ | ____ | ____ | ____ |  | ____ | ____ | ____ | STOP | PLAY | MUTE | ____ | ____ |
* `-----------------------+------+--------+------+------+------|  |------+------+------+------+------+--------------------'
*                       | ____ | INVRT | MEDIA | NAVI  | MOUSE |  |      |        |        | ____ | ____ |
*                       | ____ | Escape| Enter | Space | Tab   |  | STOP | PLAY  | MUTE    | ____ | ____ |
*                        `-------------------------------------'  `--------------------------------------'
*/
[MEDR] = LAYOUT(
  TO(BASE),  KC_NU,   KC_NU,    KC_NU,    KC_NU,   KC_NU,                                               KC_TOG,  KC_MOD,              KC_HUI,        KC_SAI,        KC_VAI,  KC_NU,
  TO(MEDR),  KC_LGUI, KC_LALT,  KC_LCTL,  KC_LSFT, KC_NU,                                               KC_NU,   KC_MPRV,             KC_VOLD,       KC_VOLU,       KC_MNXT, KC_NU,
  TO(BASE),  KC_NU,   KC_ALGR,  KC_NU,    KC_NU,   KC_NU, KC_NU, KC_NU,   KC_NU,               KC_NU,   KC_NU,   KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_NU,   KC_NU,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_TRNS, KC_TRNS

),


/*
* Navigation Layer: NAVR
*
* ,-----------------------------------------------.                              ,------------------------------------------.
* | RESET LYR  | ____ | ____ | ____ | ____ | ____ |                              | AGAIN | UNDO | CUT  | COPY | PASTE| ____ |
* |------------+------+------+------+------+------|                              |-------+------+------+------+------+------|
* | LOCK LYR   | GUI  | ALT  | CTRL | SHIFT| ____ |                              | CAPS  | LEFT | DOWN | UP   | RIGHT| ____ |
* |------------+------+------+------+------+------+-------------.  ,-------------+-------+------+------+------+------+------|
* | TOGGLE LYR | ____ | ALGR | ____ | ____ | ____ | ____ | ____ |  | ____ | ____ | INS   | HOME | PGDN | PGUP | END  | ____ |
* `----------------------+------+--------+--------+------+------|  |------+------+-------+------+------+--------------------'
*                        | ____ | INVRT | MEDIA | NAVI  | MOUSE |  |      |        |        | ____ | ____ |
*                        | ____ | Escape| Enter | Space | Tab   |  | Enter| Bspace | Delete | ____ | ____ |
*                         `-------------------------------------'  `--------------------------------------'
*/

[NAVR] = LAYOUT(
  TO(BASE),  KC_NU,   KC_NU,    KC_NU,    KC_NU,   KC_NU,                              KC_REDO_C, KC_UNDO_C, KC_CUT_C, KC_COPY_C, KC_PASTE_C, KC_NU,
  TO(NAVR),  KC_LGUI, KC_LALT,  KC_LCTL,  KC_LSFT, KC_NU,                              KC_CAPS,   KC_LEFT,   KC_DOWN,  KC_UP,     KC_RGHT,    KC_NU,
  TO(BASE),  KC_NU,   KC_ALGR,  KC_NU,    KC_NU,   KC_NU, KC_NU, KC_NU,  KC_NU, KC_NU, KC_INS,    KC_HOME,   KC_PGDN,  KC_PGUP,   KC_END,     KC_NU,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),


/*
 * MouseControl Layer: MOUR
 *
 * ,-----------------------------------------------.                              ,-----------------------------------------.
 * | RESET LYR  | ____ | ____ | ____ | ____ | ____ |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | LOCK LYR   | GUI  | ALT  | CTRL | SHIFT| ____ |                              | ____ |MLEFT |MDOWN | MUP  |MRIGHT| ____ |
 * |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | TOGGLE LYR | ____ | ALGR | ____ | ____ | ____ | ____ | ____ |  | ____ | ____ | ____ |WLEFT |WDOWN | WUP  |WRIGHT| ____ |
 * `----------------------+------+--------+------+--------+------|  |------+------+------+------+------+--------------------'
 *                            | ____ | ____ | ____ | ____ | ____ |  |      |      |      | ____ | ____ |
 *                            | ____ | ____ | ____ | ____ | ____ |  | BTN1 | BTN3 | BTN2 | ____ | ____ |
 *                            `----------------------------- ----'  `----------------------------------'
*/
[MOUR] = LAYOUT(
  TO(BASE), KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,                                 KC_NU, KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,
  TO(MOUR), KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NU,                                 KC_NU, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NU,
  TO(BASE), KC_NU,   KC_ALGR, KC_NU,   KC_NU,   KC_NU, KC_NU, KC_NU,   KC_NU,   KC_NU, KC_NU, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NU,
                      KC_NP,   KC_NP,  KC_NU,   KC_NU, KC_NU, KC_BTN1, KC_BTN3, KC_BTN2, KC_NP, KC_NP
),


/*
 * Function Layer: FUNL
 *
 * ,------------------------------------------------.                              ,-----------------------------------------.
 * | RESET LYR  |  F12 |  F7  |  F8  |  F9  | PRINT |                              | ____ | ____ | ____ | ____ | ____ | ____ |
 * |------------+------+------+------+------+-------|                              |------+------+------+------+------+------|
 * | LOCK LYR   |  F11 |  F4  |  F5  |  F6  | SLock |                              | ____ | SHIFT| CTRL | ALT  | GUI  | ____ |
 * |------------+------+------+------+------+-------+-------------.  ,-------------+------+------+------+------+------+------|
 * | TOGGLE LYR |  F10 |  F1  |  F2  |  F3  | PAUSE | ____ | ____ |  | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
 * `-----------------------+-------+-------+-------+-------+------|  |------+------+------+------+------+--------------------'
 *                         | _____ | _____ | _____ | _____ | ____ |  | ____ | ____ | ____ | ____ | ____ |
 *                         | _____ | _____ | App   | Space | Tab  |  |      |      |      |      |      |
 *                         `--------------------------------------'  `----------------------------------'
*/ 
[FUNL] = LAYOUT(
  TO(BASE),  KC_F12, KC_F7,  KC_F8,  KC_F9, KC_PSCR,                                 KC_NU, KC_NU,   KC_NU,   KC_NU,   KC_RST,  KC_NU,
  TO(FUNL),  KC_F11, KC_F4,  KC_F5,  KC_F6, KC_SLCK,                                 KC_NU, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NU,
  TO(BASE),  KC_F10, KC_F1,  KC_F2,  KC_F3, KC_PAUS, KC_NU,  KC_NU,    KC_NU, KC_NU, KC_NU, KC_NU,   KC_NU,   KC_ALGR, KC_NU,   KC_NU,
                            KC_NP,  KC_NP, KC_APP,  KC_SPC, KC_TAB,   KC_NU, KC_NU, KC_NU, KC_NP,   KC_NP
),


/*
 * Number Layer: NSL
 *
 * ,-----------------------------------------------.                              ,-------------------------------------------.
 * |            |  [   |  7   |  8   |  9  |   ]   |                              | ___  | ___  | ___  | ___  | ___  |  ___   |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |            |  ;   |  4   |  5   |  6  |   =   |                              | ___  | SHIFT| CTRL | ALT  | GUI  |  ___   |
 * |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |            |  ´   |  1   |  2   |  3   |  \   |  ___ |  ___ |  |  ___ |  ___ | ___  | ___  |  ___ |  ___ | ___  |  ___   |
 * `----------------------+------+--------+------+--------+------|  |------+------+------+------+------+----------------------'
 *                        |  ___ |  ___   | _____ |  ___   | ___  |  |  ___ |  ___ |  ___ | ___  | ___  |
 *                        |  ___ |  ___   | Enter |   0    |  -   |  |      |      |      |      |      |
 *                        `--------------------------------------'  `----------------------------------'
*/
[NSL] = LAYOUT(
  TO(BASE), DE_LBRC, DE_7,  DE_8,  DE_9,  DE_RBRC,                                 KC_NA, KC_NA,   KC_NA,   KC_NA,   KC_RST,  KC_NU,
  TO(NSL),  DE_SCLN, DE_4,  DE_5,  DE_6,  DE_EQL,                                  KC_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NU,
  TO(QWERTY),  KC_GRV,  DE_1,  DE_2,  DE_3,  DE_BSLS, KC_NU, KC_NU,     KC_NU, KC_NU, KC_NA, KC_NA,   KC_NA,   KC_ALGR, KC_NA,   KC_NU,
                          KC_NP, KC_NP, DE_DOT,  DE_0,  DE_MINS,   KC_NA, KC_NA, KC_NA, KC_NP,   KC_NP
),


/*
 * Number Layer: NSSL
 *
 * ,-----------------------------------------------.                              ,-------------------------------------------.
 * |            |  {   |  &   |  *   |  (  |   }   |                              | ___  | ___  | ___  | ___  | ___  |  ___   |
 * |------------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |            |  :   |  $   |  %   |  ^  |   +   |                              | ___  | SHIFT| CTRL | ALT  | GUI  |  ___   |
 * |------------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |            |  ~   |  !   |  @   |  #   |  |   |  ___ |  ___ |  |  ___ |  ___ | ___  | ___  |  ___ |  ___ | ___  |  ___   |
 * `----------------------+------+--------+------+--------+------|  |------+------+------+------+------+----------------------'
 *                        |  ___ |  ___   |  ___ |  ___   | ___  |  |  ___ |  ___ |  ___ | ___  | ___  |
 *                        |  ___ |  ___   |   (  |   )    |  _   |  |      |      |      |      |      |
 *                        `--------------------------------------'  `----------------------------------'
*/
[NSSL] = LAYOUT(
  TO(BASE),  KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RCBR,                                 KC_NA, KC_NA,   KC_NA,   KC_NA,   KC_RST,  KC_NU,
  TO(NSSL),  KC_COLN, KC_DLR,  KC_PERC, KC_CIRC,  KC_PLUS,                                 KC_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NU,
  TO(BASE),  KC_TILD, KC_EXLM, KC_AT,   KC_HASH,  KC_PIPE, KC_NU, KC_NU,     KC_NU, KC_NU, KC_NA, KC_NA,   KC_NA,   KC_ALGR, KC_NA,   KC_NU,
                               KC_NP, KC_NP, KC_GT, KC_RPRN, KC_UNDS,     KC_NA, KC_NA, KC_NA, KC_NP,  KC_NP
),

  
 /*
  * Symbol Layer: SYMBOL
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |  !   |  ?   |  [   |  ]   |  ^   |                              |   °  |      |  &   |  %   |  |   |   §    |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |  \   |  /   |  (   |  )   |  @   |                              |   `  |  {   |  }   |  +   |  =   |   ²    |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |  #   |  $€  |  <   |  >   |  *   |      |      |  |      |      |   ~  |      |      |  "   |  '   |   ³    |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
    [SYMBOL] = LAYOUT(
      TO(BASE), DE_EXLM, DE_QUES,   DE_LBRC, DE_RBRC, DE_CIRC,                                     DE_DEG, KC_TRNS, DE_AMPR,DE_PERC,DE_PIPE,DE_SECT,
      TO(SYMBOL), DE_BSLS, DE_SLSH,  DE_LPRN, DE_RPRN, DE_AT,                                      DE_GRV, DE_LCBR, DE_RCBR, DE_PLUS, DE_EQL, DE_SUP2,
      TO(BASE), DE_HASH, DE_DLR, DE_LABK, DE_RABK, DE_ASTR, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, DE_TILD, KC_TRNS,  KC_TRNS, DE_DQUO,  DE_QUOT, DE_SUP3,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),


/*
 * Base Layer: QWERTY
 *
 * ,----------------------------------------------.                              ,-------------------------------------------.
 * | RESET LYR |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |-----------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LSFT      |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |-----------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | TOGGLE LYR|   Z  |   X  |   C  |   V  |   B  | CCCV |      |  | Del  |Leader|   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `-------------------------+------+------+------+------+      |  |------+------+------+------+------+----------------------'
 *                       |  ___ | INVERT | MEDIA | NAVI  | MOUSE|  | SYM  | NUM      | FUNC   |        |       |
 *                       |      | Enter  | Escape| Space | Tab  |  | Enter| Bspace   | Delete |        |       |
 *                       `--------------------------------------'  `-------------------------------------------'
 */
    [QWERTY] = LAYOUT(
      TO(BASE), DE_Q,         DE_W,         DE_E,         DE_R,         DE_T,                                          KC_Y, KC_U,         KC_I,            KC_O,         KC_P,            KC_PIPE,
      KC_LSFT,  LGUI_T(DE_A), LALT_T(DE_S), LCTL_T(DE_D), LSFT_T(DE_F), DE_G,                                          DE_H, LSFT_T(DE_J), LCTL_T(DE_K),    LALT_T(DE_L), LGUI_T(DE_SCLN), DE_QUOT,
      TO(GAMEPAD),  DE_Z,         DE_X,         DE_C,         DE_V,         DE_B,   _______, _______,     KC_DEL, _______, DE_N, DE_M,         DE_COMM,         DE_DOT,       DE_SLSH,         DE_MINS,
                  KC_NU, LT(INVRT, KC_ENT), LT(MEDR, KC_ESC), LT(NAVR, KC_SPC), LT(MOUR, KC_TAB),     LT(SYMBOL, KC_ENT), LT(NSL, KC_BSPC), LT(FUNL, KC_DEL), KC_NU, KC_NU
    ),


 /*
 * Base Layer: GAMING
 *
 * ,-------------------------------------------.                                  ,-------------------------------------------.
 * | RESET LYR |   K  |   Q  |   X  |   E  |   R  |                               |      |      |      |      |      |        |
 * |-----------+------+------+------+------+------|                               |------+------+------+------+------+--------|
 * | LTAB      |   G  |   A  |   W  |   D  |   F  |                               |      |      |      |      |      |        |
 * |-----------+------+------+------+------+------+--------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTL      | LSFT |   Z  |   S  |   C  |   V  |       |      |  |      |      |      |      |      |      |      |        |
 * `-------------------------+------+------+------+-------+      |  |------+------+------+------+------+----------------------'
 *                       | ____ |        |        |       |      |  |      |          |         |        |       |
 *                       |      | MAGIC  |   V    | Space |  H   |  |      |          |         |        |       |
 *                       `--------------------------------------'  `---------------------------------------------'
 */

    [GAMEPAD] = LAYOUT(
        TO(BASE),KC_K,    KC_Q,    KC_X,    KC_E,    KC_R,                                                 _______, _______, _______, _______, _______, _______,
        KC_TAB,  KC_G,    KC_A,    KC_W,    KC_D,    KC_F,                                                 _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_LSFT, KC_Z,    KC_S,    KC_C,    KC_V,  _______, _______,      _______, LALT(KC_PSCR), _______, _______, _______, _______, _______, _______,
                              _______, MAGIC_TOGGLE_NKRO, KC_V, KC_SPC, KC_H,      _______, _______, _______, _______, _______
    ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, BASE, QWERTY, GAMEPAD);
}

//OLED CONFIGURATION
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    //oled_write_P(PSTR("       Kyria rev1.0\n\n"), false);
    
    // Host Keyboard Layer Status
    oled_write_P(PSTR("\n       "), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("BUTECK-CV"), false);
            break;
        case MEDR:
            oled_write_P(PSTR("Media"), false);
            break;
        case NAVR:
            oled_write_P(PSTR("Navigation"), false);
            break;
        case MOUR:
            oled_write_P(PSTR("Mouse"), false);
            break;
        case NSSL:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case NSL:
            oled_write_P(PSTR("Numbers"), false);
            break;
        case FUNL:5;
            oled_write_P(PSTR("Functions"), false);
            break;
        case INVRT:
            oled_write_P(PSTR("Onehand"), false);
            break;
        case SYMBOL:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case QWERTY:
            oled_write_P(PSTR("QWERTY"), false);
            break;
        case GAMEPAD:
            oled_write_P(PSTR("Game"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined"), false);
    }
    oled_write_P(PSTR("\n"), false);

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
    return false;
}
#endif

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
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
    } else if (index == 1) {
        switch (biton32(layer_state)) {
            case QWERTY:
                // Scrolling with PageUp and PgDn.
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            default:
                // Volume control.
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
    return true;
}
#endif

