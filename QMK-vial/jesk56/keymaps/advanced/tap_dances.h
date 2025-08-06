
//Tap-dance type definitions
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_SINGLE_HOLD_INTERUPT,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;



//TD
// Tap dance enums
enum {
    //ADV_BOT_RIGHT_BRACKETS_LEFTS,
    //ADV_BOT_RIGHT_BRACKETS_RIGHTS,
    //TD_SPC_ENT,
    TD_TAB_ENT, 
    TD_SES_L,               //Space_***_Enter_DotSpaceShift_TAB_DotEnterShift
    TD_SES_R,               //Space_***_Enter_DotSpaceShift_TAB_DotEnterShift
    TD_ENTERDOT_LAYER,
    ENC_L_CP,
    TD_LAYER,
    QESC,
    r4c1_CtAlt,
    MinBslh         //TD_MINUS_BACKSLASH
};


int cur_dance(tap_dance_state_t *state);
int cur_dance2(tap_dance_state_t *state);


// For the x tap dance. Put it here so it can be used in any keymap
void mL_finished(tap_dance_state_t *state, void *user_data);      //Space_***_Enter_DotSpaceShift_TAB_DotEnterShift
void mL_reset(tap_dance_state_t *state, void *user_data);
void mR_finished(tap_dance_state_t *state, void *user_data);      //Space_***_Enter_DotSpaceShift_TAB_DotEnterShift
void mR_reset(tap_dance_state_t *state, void *user_data);

void enterdot_layer_finished(tap_dance_state_t *state, void *user_data);
void enterdot_layer_reset(tap_dance_state_t *state, void *user_data);
void ENC_L_cp_finished(tap_dance_state_t *state, void *user_data);
void ENC_L_cp_reset(tap_dance_state_t *state, void *user_data);
void layer_finished(tap_dance_state_t *state, void *user_data);
void layer_reset(tap_dance_state_t *state, void *user_data);
void qesc_finished(tap_dance_state_t *state, void *user_data);
void qesc_reset(tap_dance_state_t *state, void *user_data);
void r4c1_CtAlt_finished(tap_dance_state_t *state, void *user_data);
void r4c1_CtAlt_reset(tap_dance_state_t *state, void *user_data);
void MinBslh_finished(tap_dance_state_t *state, void *user_data);
void MinBslh_reset(tap_dance_state_t *state, void *user_data);

/* Tap-dance - advanced setup is finished
 *
 */





// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_TAB_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_TAB,KC_ENT),
    [TD_SES_L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mL_finished, mL_reset),     //Space, Enter, Shift
    [TD_SES_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mR_finished, mR_reset),     //Space, Enter, Shift
    [TD_ENTERDOT_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, enterdot_layer_finished, enterdot_layer_reset),
    [ENC_L_CP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ENC_L_cp_finished, ENC_L_cp_reset),
    [TD_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset),
    [QESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, qesc_finished, qesc_reset),
    [r4c1_CtAlt] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, r4c1_CtAlt_finished, r4c1_CtAlt_reset),
    [MinBslh] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, MinBslh_finished, MinBslh_reset),
};

