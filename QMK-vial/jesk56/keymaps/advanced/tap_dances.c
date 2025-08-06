#include "tap_dances.h"
#include QMK_KEYBOARD_H
#include "quantum.h"

int cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

int cur_dance2(tap_dance_state_t *state) {
    if (state->count == 1) {
        if ( !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}



/*
// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t bot_right_L_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t bot_right_R_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};*/

static td_tap_t mL_tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};
static td_tap_t mR_tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};
static td_tap_t enterdot_layer_tap_state = {
  .is_press_action = true,  
  .state = TD_NONE
};
static td_tap_t ENC_L_cp_tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};
static td_tap_t layer_tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};
static td_tap_t qesc_tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};
static td_tap_t CtAlt_tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};
static td_tap_t MinBslh_tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};




//Functions that control what our tap dance key does
//Space_***_Enter_DotSpaceShift_TAB_DotEnterShift
void mL_finished (tap_dance_state_t *state, void *user_data) {
  mL_tap_state.state = cur_dance(state);
  switch (mL_tap_state.state) {
    case TD_SINGLE_TAP:   tap_code(KC_SPC);   break;
    case TD_SINGLE_HOLD:   tap_code(KC_SPC);   break;
    case TD_DOUBLE_TAP:   tap_code(KC_ENT);   break;  
    case TD_DOUBLE_HOLD:  tap_code(KC_DOT);   tap_code(KC_SPC);   register_code(KC_LEFT_SHIFT);   break;  
    case TD_TRIPLE_TAP:   tap_code(KC_TAB);   break; 
    case TD_TRIPLE_HOLD:  tap_code(KC_DOT);   tap_code(KC_ENT);   register_code(KC_LEFT_SHIFT);   break;
    default: break;
  }
}   



void mL_reset(tap_dance_state_t*state, void *user_data) {
  switch (mL_tap_state.state) {
    //case TD_SINGLE_TAP: unregister_code(KC_SPC); break;
    //case TD_SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LSFT)); break;
    //case TD_SINGLE_HOLD: unregister_code(KC_LEFT_SHIFT); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_LEFT_SHIFT); break;
    case TD_TRIPLE_HOLD: unregister_code(KC_LEFT_SHIFT); break;
    default: break;
  }
  mL_tap_state.state = TD_NONE;
}

//Functions that control what our tap dance key does
//Space_***_Enter_DotSpaceShift_TAB_DotEnterShift
void mR_finished (tap_dance_state_t *state, void *user_data) {
  mR_tap_state.state = cur_dance(state);
  switch (mR_tap_state.state) { 
    case TD_SINGLE_TAP:   tap_code(KC_SPC);   break;
    case TD_SINGLE_HOLD:   tap_code(KC_SPC);   break;
    case TD_DOUBLE_TAP:   tap_code(KC_ENT);   break;  
    case TD_DOUBLE_HOLD:  tap_code(KC_DOT);   tap_code(KC_SPC);   register_code(KC_LEFT_SHIFT);   break;  
    case TD_TRIPLE_TAP:   tap_code(KC_TAB);   break; 
    case TD_TRIPLE_HOLD:  tap_code(KC_DOT);   tap_code(KC_ENT);   register_code(KC_LEFT_SHIFT);   break;
    default: break;
  }
}   



void mR_reset(tap_dance_state_t*state, void *user_data) {
  switch (mR_tap_state.state) {
    //case TD_SINGLE_TAP: unregister_code(KC_SPC); break;
    //case TD_SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LSFT)); break;
    //case TD_SINGLE_HOLD: unregister_code(KC_LEFT_SHIFT); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_LEFT_SHIFT); break;
    case TD_TRIPLE_HOLD: unregister_code(KC_LEFT_SHIFT); break;
    default: break;
  }
  mR_tap_state.state = TD_NONE;
}






//Functions that control what our tap dance key does
void enterdot_layer_finished (tap_dance_state_t *state, void *user_data) {
  enterdot_layer_tap_state.state = cur_dance2(state);
  switch (enterdot_layer_tap_state.state) {
    case TD_SINGLE_TAP: 
      tap_code(KC_ENT); //,KC_ENT;   //   register_code(KC_SPC);
      break;
    case TD_SINGLE_HOLD:
      layer_on(_EXTRA);  
      break;
    // case TD_DOUBLE_HOLD:
    //   tap_code(KC_DOT); 
    //   tap_code(KC_SPC);
    //   register_mods(MOD_BIT(KC_LSFT));
    //   break;
    case TD_DOUBLE_TAP: 
      tap_code(KC_DOT);  
      tap_code(KC_ENT); 
      break;    
    // case TD_TRIPLE_TAP: 
    //   tap_code(KC_DOT); 
    //   tap_code(KC_ENT);
    //   //register_code(KC_LEFT_SHIFT);
    //   break;
    default: break;
  }
}   
void enterdot_layer_reset(tap_dance_state_t*state, void *user_data) {
  switch (enterdot_layer_tap_state.state) {
    // case TD_SINGLE_TAP: unregister_code(KC_SPC); break;
    case TD_SINGLE_HOLD: layer_off(_EXTRA); break;
    // //case TD_SINGLE_HOLD: unregister_code(KC_LEFT_SHIFT); break;
    // case TD_DOUBLE_HOLD: unregister_mods(MOD_BIT(KC_LSFT)); break; // layer_off(_NP); break;
    default: break;
  }
  enterdot_layer_tap_state.state = TD_NONE;
}



void ENC_L_cp_finished (tap_dance_state_t *state, void *user_data) {
    ENC_L_cp_tap_state.state = cur_dance2(state);
    switch (ENC_L_cp_tap_state.state) {
    case TD_SINGLE_TAP: 
      register_mods(MOD_BIT(KC_LCTL));
      tap_code16(KC_C);
      unregister_mods(MOD_BIT(KC_LCTL));
      break;
    //case TD_SINGLE_HOLD:
    //  layer_on(_);  
    //  break;
    case TD_DOUBLE_TAP: 
      register_mods(MOD_BIT(KC_LCTL));
      tap_code16(KC_V);
      unregister_mods(MOD_BIT(KC_LCTL));
      break;   
    case TD_TRIPLE_TAP: 
      register_mods(MOD_BIT(KC_LCTL));
      tap_code16(KC_X);
      unregister_mods(MOD_BIT(KC_LCTL));
      break;   
    default: break;
  }
}
void ENC_L_cp_reset (tap_dance_state_t *state, void *user_data) {
  ENC_L_cp_tap_state.state = TD_NONE;
}



void layer_finished (tap_dance_state_t *state, void *user_data) {
    layer_tap_state.state = cur_dance2(state);
    switch (layer_tap_state.state) {
    case TD_SINGLE_TAP: 
      layer_on(_NUMPAD);   
      break;
    case TD_SINGLE_HOLD:
      layer_on(_LOWER);  
      break;
    default: break;
  }
}
void layer_reset (tap_dance_state_t *state, void *user_data) {
    switch (layer_tap_state.state) {
      case TD_SINGLE_HOLD: layer_off(_LOWER); break;
    default: break;
  }
  layer_tap_state.state = TD_NONE;
}


void qesc_finished (tap_dance_state_t *state, void *user_data) {
    qesc_tap_state.state = cur_dance(state);
    switch (qesc_tap_state.state) {
    case TD_SINGLE_TAP: 
      tap_code16(KC_Q); 
      break;
    case TD_SINGLE_HOLD:
      tap_code16(KC_ESC);
      break;
    default: break;
  }
}
void qesc_reset (tap_dance_state_t *state, void *user_data) {
  qesc_tap_state.state = TD_NONE;
}




void r4c1_CtAlt_finished (tap_dance_state_t *state, void *user_data) {
    CtAlt_tap_state.state = cur_dance2(state);
    switch (CtAlt_tap_state.state) {
      case TD_SINGLE_TAP: 
        set_oneshot_mods(MOD_BIT(KC_LCTL));
        break;
      case TD_SINGLE_HOLD:
        register_mods(MOD_BIT(KC_LCTL));
        break;
      case TD_DOUBLE_TAP: 
        set_oneshot_mods(MOD_BIT(KC_LALT));
        break;   
      case TD_DOUBLE_HOLD: 
        register_mods(MOD_BIT(KC_LALT));  
        break;   
      case TD_TRIPLE_TAP: 
        register_mods(MOD_BIT(KC_LCTL));
        register_mods(MOD_BIT(KC_LALT));
        break;   
      case TD_TRIPLE_HOLD: 
        register_mods(MOD_BIT(KC_LCTL));
        register_mods(MOD_BIT(KC_LALT));
        break;    
      default: break;
    }
}
void r4c1_CtAlt_reset (tap_dance_state_t *state, void *user_data) {
  switch (CtAlt_tap_state.state) {
    case TD_SINGLE_TAP: 
      unregister_mods(MOD_BIT(KC_LCTL));
      break;
    case TD_SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LCTL));
      break;
    case TD_DOUBLE_TAP: 
      unregister_mods(MOD_BIT(KC_LALT));
      break;   
    case TD_DOUBLE_HOLD: 
      unregister_mods(MOD_BIT(KC_LALT));
      break;   
    case TD_TRIPLE_TAP: 
      unregister_mods(MOD_BIT(KC_LCTL));
      unregister_mods(MOD_BIT(KC_LALT));
      break;   
    case TD_TRIPLE_HOLD: 
      unregister_mods(MOD_BIT(KC_LCTL));
      unregister_mods(MOD_BIT(KC_LALT));
      break;    
    default: break;
  }
  CtAlt_tap_state.state = TD_NONE;
}


void MinBslh_finished (tap_dance_state_t *state, void *user_data) {
    CtAlt_tap_state.state = cur_dance2(state);
    switch (CtAlt_tap_state.state) {
      case TD_SINGLE_TAP: 
        tap_code16(KC_MINS);
        break;
      case TD_SINGLE_HOLD:
        tap_code16(KC_BSLS);
        break;
      case TD_DOUBLE_HOLD: 
        tap_code16(KC_BSLS);
        layer_on(_LATEX); 
        break;    
      default: break;
    }
}


void MinBslh_reset (tap_dance_state_t *state, void *user_data) {
  switch (CtAlt_tap_state.state) {
    case TD_DOUBLE_HOLD: 
      case TD_SINGLE_HOLD: layer_off(_LOWER);
      break;   
    default: break;
  }
  MinBslh_tap_state.state = TD_NONE;
}




// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}

