// Copyright 2021 Christoph Rehmann (crehmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "haptic_utils.h"

#ifdef HAPTIC_ENABLE
    #include "drivers/haptic/drv2605l.h"
#endif

#ifdef HAPTIC_ENABLE
bool get_haptic_enabled_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case LLOCK:
        //     return true;
        //     break;
        // case KC_COPY_C:
        //     return true;
        //     break;
        // case KC_CUT_C:
        //     return true;
        //     break;
        case KC_CAPS:
            return true;
            break;
        case KC_TOG:
            return true;
            break;
        case KC_MOD: 
            return true;
            break;
        case KC_HUI: 
            return true;
            break;
        case KC_SAI: 
            return true;
            break;
        case KC_VAI: 
            return true;
            break;
        case KC_SPD: 
            return true;
            break;
        case KC_LOCK: 
            return true;
            break;
        case DM_REC1: 
            return true;
            break;
        case DM_REC2: 
            return true;
            break;
        case DM_PLY1: 
            return true;
            break;
        case DM_PLY2: 
            return true;
            break;
    }
        return false;
}
#endif

void process_layer_pulse(layer_state_t state) {
#ifdef HAPTIC_ENABLE
    switch (get_highest_layer(state)) {
        case BASE:
            // DRV_pulse(soft_bump);
                break;
        case QWERTY:
            // DRV_pulse(sh_dblsharp_tick);
                break;
        case GAME:
            // DRV_pulse(lg_dblclick_str);
                break;
        //DRV_pulse(soft_bump);
        //DRV_pulse(pulsing_sharp);        
    }
#endif
}
