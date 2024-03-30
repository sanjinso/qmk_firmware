


/* ********
* OLED
**********/

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}


/*
static void render_layer_state(uint8_t const state) {
	static char const base_layer[] PROGMEM = {
		0x20, 0x9a, 0x9b, 0x9c, 0x20,
		0x20, 0xba, 0xbb, 0xbc, 0x20,
		0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
	static char const numb_layer[] PROGMEM = {
		0x20, 0x94, 0x95, 0x96, 0x20,
		0x20, 0xb4, 0xb5, 0xb6, 0x20,
		0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
	static char const symb_layer[] PROGMEM = {
		0x20, 0x97, 0x98, 0x99, 0x20,
		0x20, 0xb7, 0xb8, 0xb9, 0x20,
		0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
	static char const func_layer[] PROGMEM = {
		0x20, 0x9d, 0x9e, 0x9f, 0x20,
		0x20, 0xbd, 0xbe, 0xbf, 0x20,
		0x20, 0xdd, 0xde, 0xdf, 0x20, 0};

	switch(state) {
	case FNC: oled_write_P(func_layer, false); break;
	case SYM: oled_write_P(symb_layer, false); break;
	case NUM: oled_write_P(numb_layer, false); break;
	default:  oled_write_P(base_layer, false);
	}
}


// Primary modifier status display function
void render_mod_status(void) {
	render_logo();

	oled_set_cursor(0,6);
	render_layer_state(get_highest_layer(layer_state|default_layer_state));

	oled_set_cursor(0,11);
	render_gui_alt(
		get_mods() & MOD_MASK_GUI,
		get_mods() & MOD_MASK_ALT);
	render_ctrl_shift(
		get_mods() & MOD_MASK_CTRL,
		get_mods() & MOD_MASK_SHIFT ||
		host_keyboard_led_state().caps_lock);
}
© 2022 GitHub, 

*/

//Layer Lock Indicator
//https://getreuer.info/posts/keyboards/layer-lock/#representing-the-current-layer-lock-state
void layer_lock_set_user(layer_state_t locked_layers) {
  // Do something like `set_led(is_layer_locked(NAV));`
}

//Caps Lock Word Indicator
//https://getreuer.info/posts/keyboards/caps-word/index.html
void caps_word_set_user(bool active) {
  if (active) {
    // Do something when Caps Word activates.
  } else {
    // Do something when Caps Word deactivates.
  }
}

//Kyria Logo
static void render_kyria_logo(void) {
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    //oled_write_raw_P(icon_rocket, sizeof(icon_rocket));
}


//Better Way to change OLED only when entering or exiting layer
//https://getreuer.info/posts/keyboards/triggers/index.html#on-entering-or-exiting-a-layer

/*
layer_state_t layer_state_set_user(layer_state_t state) {
  // Use `static` variable to remember the previous status.
  static bool adjust_on = false;

  if (adjust_on != IS_LAYER_ON_STATE(state, ADJUST)) {
    adjust_on = !adjust_on;
    if (adjust_on) {  // Just entered the ADJUST layer.
      PLAY_SONG(MAJOR_SONG);
    } else {          // Just exited the ADJUST layer.
      PLAY_SONG(GOODBYE_SONG);
    }
  }

  return state;
}
*/


static void render_status(void) {
    // QMK Logo and version information
    //render_qmk_logo();
    //oled_write_P(icon_qmk, false);
    //oled_write_raw_P(icon_rocket, sizeof(icon_rocket));
    
    //oled_write_P(PSTR("       Kyria rev1.0\n\n"), false);

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
    oled_write_P(PSTR("\n"), false);

    // Host Keyboard Higehst Layer
    switch (get_highest_layer(layer_state)) {
        case BASE:
            #ifdef RGBLIGHT_ENABLE
                rgblight_setrgb (RGB_WHITE);
            #endif
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("      <BUTECK-CVX> \n"), false);
            oled_write_P(PSTR("       QWERTY   "), false);
            //oled_write_raw_P(icon_rocket, sizeof(icon_rocket));
            break;
        case MEDR:
            oled_write_P(PSTR("       MEDIA     \n"), false);
            oled_write_P(PSTR("                 \n"), false);
            oled_write_P(PSTR("                 "), false);
            //oled_write_raw_P(icon_media, sizeof(icon_media));
            break;
        case NAVR:
            oled_write_P(PSTR("       NAVIGATION\n"), false);
            oled_write_P(PSTR("                 \n"), false);
            oled_write_P(PSTR("                 "), false);
            //oled_write_raw_P(icon_nav, sizeof(icon_nav));
            break;
        case MOUR:
            oled_write_P(PSTR("       MOUSE     \n"), false);
            oled_write_P(PSTR("                 \n"), false);
            oled_write_P(PSTR("                 "), false);
            //oled_write_raw_P(icon_mouse, sizeof(icon_mouse));
            break;
        case MOURI:
            oled_write_P(PSTR("       MOUSE-INVRT\n"), false);
            oled_write_P(PSTR("                 \n"), false);
            oled_write_P(PSTR("                 "), false);
            //oled_write_raw_P(icon_mouse, sizeof(icon_mouse));
            break;
        case NSL:
            oled_write_P(PSTR("       NUMBERS  \n"), false);
            oled_write_P(PSTR("                 \n"), false);
            oled_write_P(PSTR("                 "), false);
            break;
        case FUNL:
            oled_write_P(PSTR("       FUNCTIONS  \n"), false);
            oled_write_P(PSTR("                 \n"), false);
            oled_write_P(PSTR("                 "), false);
            //oled_write_raw_P(icon_funl, sizeof(icon_funl));
            break;
        case INVRT:
            oled_write_P(PSTR("       ONEHAND   \n"), false);
            oled_write_P(PSTR("                 \n"), false);
            oled_write_P(PSTR("                 "), false);
            //oled_write_raw_P(icon_onehand, sizeof(icon_onehand));
            break;
        case SYMBOL:
            oled_write_P(PSTR("       SYMBOLS   \n"), false);
            oled_write_P(PSTR("                 \n"), false);
            oled_write_P(PSTR("                 "), false);
            break;
        case QWERTY:
            #ifdef RGBLIGHT_ENABLE
                rgblight_setrgb (RGB_BLUE);
            #endif
            oled_write_P(PSTR("       BUTECK-CVX\n"), false);
            oled_write_P(PSTR("      <QWERTY>    \n"), false);
            oled_write_P(PSTR("       GAME     "), false);
            break;
        case GAME:
            #ifdef RGBLIGHT_ENABLE
                rgblight_setrgb(RGB_ORANGE);
            #endif
            oled_write_P(PSTR("       QWERTY     \n"), false);
            oled_write_P(PSTR("      <GAME>    \n"), false);
            oled_write_P(PSTR("                 "), false);
            //oled_write_raw_P(icon_gamepad, sizeof(icon_gamepad));
            break;
        case GAME_2:
            #ifdef RGBLIGHT_ENABLE
                rgblight_setrgb(RGB_RED);
            #endif
            oled_write_P(PSTR("       GAME-2     \n"), false);
            oled_write_P(PSTR("                 \n"), false);
            oled_write_P(PSTR("                 "), false);
            //oled_write_raw_P(icon_gamepad, sizeof(icon_gamepad));
            break;
        default:
            oled_write_P(PSTR("UNDEFINED"), false);
    }
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


