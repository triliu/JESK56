// Copyright 2024 Trent G. Marbach (https://github.com/triliu)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
//#include "quantum.h"

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _EXTRA, 
    _NUMPAD,
    _LATEX
};


layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return state;
}




#include "special_keycodes.h"
#include "tap_dances.c"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 
╭───────┬───────┬───────┬───────┬───────┬───────╮       ╭───────┬───────┬───────┬───────┬───────┬───────╮
│  Esc  │   1   │   2   │   3   │   4   │   5   │       │   6   │  7    │  8    │  9    │  0    │BSpace │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│  Tab  │   Q   │   W   │   E   │   R   │   T   │       │   Y   │  U    │  I    │  O    │  P    │   -   │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│ Mods  │   A   │   S   │   D   │   F   │   G   │       │   H   │   J   │   K   │   L   │   ?   │   '   │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│L Shift│   Z   │   X   │   C   │   V   │   B   │       │   N   │   M   │   ,   │   .   │   \   │ Enter │
╰───────┴───────┴───────┴───────┴───────┴───────╯       ╰───────┴───────┴───────┴───────┴───────┴───────╯
            ╭───────┬───────┬───────┬──────────────╮╭───────────────┬───────┬───────┬───────╮
            │ Mods  │  GUI  │ Layer*│     Space*   ││     Space*    │ Raise │ Repeat│ Mods  │
            ╰───────┴───────┴───────┴──────────────╯╰───────────────┴───────┴───────┴───────╯
 */

 [_QWERTY] = LAYOUT(
QK_GESC,        KC_1,         KC_2,         KC_3,           KC_4,           KC_5,                 KC_6,     KC_7,             KC_8,             KC_9,             KC_0,             BSDE, 
KC_TAB,         TD(QESC),     KC_W,         KC_E,           KC_R,           KC_T,                 KC_Y,     KC_U,             KC_I,             KC_O,             KC_P,             TD(MinBslh), 
TD(r4c1_CtAlt), KC_A,         LCTL_T(KC_S), LGUI_T(KC_D),   LALT_T(KC_F),   KC_G,                 KC_H,     RALT_T(KC_J),     RGUI_T(KC_K),     RCTL_T(KC_L),     EXQU,      HYPR_T(KC_QUOT) ,
KC_LSFT,        LSFT_T(KC_Z), KC_X,         KC_C,           KC_V,           KC_B,                 KC_N,     KC_M,             CMSC,             PECO,             SLAB,          TD(TD_ENTERDOT_LAYER), 
                                TD(r4c1_CtAlt),   KC_LGUI,  TD(TD_LAYER), TD(TD_SES_L), TD(TD_SES_R),   MO(_RAISE),    KC_RGUI,          TD(r4c1_CtAlt)   
),



/* LOWER  
╭───────┬───────┬───────┬───────┬───────┬───────╮       ╭───────┬───────┬───────┬───────┬───────┬───────╮
│   F1  │   F2  │   F3  │   F4  │   F5  │   F6  │       │   F7  │   F8  │   F9  │   F10 │   F11 │   F12 │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │   ?   │       │   =   │       │   ~   │       │       │   _   │   |   │   %   │   +   │   \   │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │   @   │   *   │   $   │       │   #   │       │   ^   │   &   │   *   │   (   │   )   │   ~   │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │   !   │   ^   │   {   │   }   │       │   &   │   -   │   {   │   }   │   |   │       │
╰───────┴───────┴───────┴───────┴───────┴───────╯       ╰───────┴───────┴───────┴───────┴───────┴───────╯
            ╭───────┬───────┬───────┬──────────────╮╭───────────────┬───────┬───────┬───────╮
            │       │       │       │              ││               │       │       │       │
            ╰───────┴───────┴───────┴──────────────╯╰───────────────┴───────┴───────┴───────╯
 */
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, KC_QUES, _______, KC_EQL, _______, KC_TILD,                 _______, KC_UNDS, KC_PIPE, KC_PERC, KC_PLUS, KC_BSLS,
  _______ , KC_AT, KC_ASTR, KC_DLR,  _______, KC_HASH,                 KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  _______, _______, KC_EXLM, KC_CIRC, KC_LCBR, KC_RCBR,                 KC_AMPR, KC_MINS , KC_LBRC, KC_RBRC, KC_PIPE, XXXXXXX,  
                    _______, _______, _______,  _______,                _______, _______, _______, _______
),



/* RAISE
╭───────┬───────┬───────┬───────┬───────┬───────╮       ╭───────┬───────┬───────┬───────┬───────┬───────╮
│       │       │       │       │       │       │       │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│   `   │   1   │   2   │   3   │   4   │   5   │       │   6   │   7   │   8   │   9   │   0   │       │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│   F1  │   F2  │   F3  │   F4  │   F5  │   F6  │       │   ←   │   ↓   │   ↑   │   →   │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│   F7  │   F8  │   F9  │   F10 │   F11 │   F12 │       │   +   │   -   │   =   │   (   │   )   │   \   │
╰───────┴───────┴───────┴───────┴───────┴───────╯       ╰───────┴───────┴───────┴───────┴───────┴───────╯
            ╭───────┬───────┬───────┬──────────────╮╭───────────────┬───────┬───────┬───────╮
            │       │       │       │              ││               │       │       │       │
            ╰───────┴───────┴───────┴──────────────╯╰───────────────┴───────┴───────┴───────╯
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, 
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                      KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                  _______,  _______, _______,  _______,                     _______, _______, _______, _______
),



/* ADJUST
╭───────┬───────┬───────┬───────┬───────┬───────╮       ╭───────┬───────┬───────┬───────┬───────┬───────╮
│       │       │       │       │       │       │       │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │       │       │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │       │       │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │       │       │       │       │       │       │       │       │
╰───────┴───────┴───────┴───────┴───────┴───────╯       ╰───────┴───────┴───────┴───────┴───────┴───────╯
            ╭───────┬───────┬───────┬──────────────╮╭───────────────┬───────┬───────┬───────╮
            │       │       │       │              ││               │       │       │       │
            ╰───────┴───────┴───────┴──────────────╯╰───────────────┴───────┴───────┴───────╯
 */
  [_ADJUST] = LAYOUT(
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, 
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ), 
  


  /* EXTRA
╭───────┬───────┬───────┬───────┬───────┬───────╮       ╭───────┬───────┬───────┬───────┬───────┬───────╮
│       │       │       │       │       │       │       │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │       │       │  Del  │       │PrintSc│Applica│       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│L Shift│   A   │   S   │  Del  │       │       │       │   ←   │   ↓   │   ↑   │   →   │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│L Ctrl │   Z   │   X   │   C   │   V   │       │       │  Home │Page Dn│Page Up│  End  │       │       │
╰───────┴───────┴───────┴───────┴───────┴───────╯       ╰───────┴───────┴───────┴───────┴───────┴───────╯
            ╭───────┬───────┬───────┬──────────────╮╭───────────────┬───────┬───────┬───────╮
            │       │       │       │              ││               │       │       │       │
            ╰───────┴───────┴───────┴──────────────╯╰───────────────┴───────┴───────┴───────╯
 */

  [_EXTRA] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_DEL,  XXXXXXX, KC_PSCR, KC_APP,   XXXXXXX, XXXXXXX,
  KC_LSFT, KC_A,    KC_S,    KC_DEL,  XXXXXXX, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX,
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,   XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______,    _______,  _______, _______, _______
  ), 



/*NUMPAD
╭───────┬───────┬───────┬───────┬───────┬───────╮       ╭───────┬───────┬───────┬───────┬───────┬───────╮
│       │  F1   │  F2   │  F3   │  F4   │  F5   │       │   +   │   -   │   *   │   /   │   ^   │ BSpace│
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │  F2   │  F10  │Applica│       │       │   7   │   8   │   9   │DeColou│ Space │ BSpace│
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │   A   │   S   │       │       │ Date  │       │   4   │   5   │   6   │ Time  │ Date  │NumLock│
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │   Z   │   X   │   C   │   V   │       │       │   1   │   2   │   3   │Ctrl : │ RShift│ Enter*│
╰───────┴───────┴───────┴───────┴───────┴───────╯       ╰───────┴───────┴───────┴───────┴───────┴───────╯
            ╭───────┬───────┬───────┬──────────────╮╭───────────────┬───────┬───────┬───────╮
            │       │~Numpad│~Numpad│ Tab/Enter    ││ Tab/Enter     │   0   │   0   │   .   │
            ╰───────┴───────┴───────┴──────────────╯╰───────────────┴───────┴───────┴───────╯
*/
    [_NUMPAD] = LAYOUT(  //See https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
  //KC_APP for right click application menu
KC_TRNS,  KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,                 KC_PPLS,  KC_PMNS,  KC_PAST,  KC_PSLS,          KC_CIRC,          KC_BSPC,                 // _ F1 F2 F3 F4 F5                        +  -   *   /         ^         <bsp>
KC_TRNS,  KC_NO,  KC_F2,  KC_F10,  KC_APP,  KC_NO,                 KC_P7,    KC_P8,    KC_P9,    EXC_DECOL,        KC_SPC,           KC_BSPC,                                           // _ Pu Up Pd Xd Xt                        7  8   9   (         )         <tab>
KC_TRNS,  KC_A,   KC_S,   KC_NO,   KC_NO,   RCS(KC_GRAVE),         KC_P4,    KC_P5,    KC_P6,    RCS(KC_SCLN),     RCTL(KC_SCLN),    KC_NUM,                                              // _ Le Do Ri Xc Xs                        4  5   6   :         .        
KC_TRNS,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_NO,                 KC_P1,    KC_P2,    KC_P3,    MT(MOD_RCTL, KC_COLN), KC_RSFT,          TD(TD_ENTERDOT_LAYER),              // _ __ __ __ __ __ F2          <numlock>  1  2   3   ,         <del>     <.layer/enter>
          KC_TRNS, TG(_NUMPAD), TG(_NUMPAD), TD(TD_TAB_ENT), TD(TD_TAB_ENT), KC_P0,   KC_P0,            KC_DOT),     
                                          
                                          
/* LATEX 
╭───────┬───────┬───────┬───────┬───────┬───────╮       ╭───────┬───────┬───────┬───────┬───────┬───────╮
│       │       │       │       │       │       │       │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │       │       │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │       │       │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │       │       │       │       │       │       │       │       │
╰───────┴───────┴───────┴───────┴───────┴───────╯       ╰───────┴───────┴───────┴───────┴───────┴───────╯
            ╭───────┬───────┬───────┬──────────────╮╭───────────────┬───────┬───────┬───────╮
            │       │       │       │              ││               │       │       │       │
            ╰───────┴───────┴───────┴──────────────╯╰───────────────┴───────┴───────┴───────╯
*/
  [_LATEX] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______,                   _______,  _______, _______, _______
  ), 

};


