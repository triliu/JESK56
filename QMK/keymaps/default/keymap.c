// Copyright 2024 Trent G. Marbach (https://github.com/triliu)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST,
    _EXTRA
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* QWERTY
 * ,-----------------------------------------.         ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |         |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |         |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |         |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * | LCTRL|   Z  |   X  |   C  |   V  |   B  |         |   N  |   M  |   ,  |   .  |   /  |EXTRA |
 * `-----------------------------------------|---------|-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | Space || Space |RAISE | Del  |Enter |
 *                   |      |      |      |       ||       |      |      |      |
 *                   `----------------------------''-------'------'------'------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  MO(_EXTRA),
                  KC_LALT, KC_LGUI,  LOWER,    KC_SPACE,                  KC_SPACE, RAISE,   KC_DEL,  KC_ENT
),
/* LOWER
 * ,-----------------------------------------.         ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |         |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |      |      |      |      |      |      |         |      |      |      |      |      |      |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |         |   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |      |      |      |      |      |      |         |      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------|---------|-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | Space || Space |RAISE | Del  |Enter |
 *                   |      |      |      |       ||       |      |      |      |
 *                   `----------------------------''-------'------'------'------'
 */
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______,                 _______, _______, _______,_______, _______, _______,
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                 KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  _______, _______, _______, _______, _______, _______,                  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX,  
                    _______, _______, _______,  _______,                _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.         ,-----------------------------------------.
 * |MOD   | MODR |  S+  |  S-  |  B+  |  B-  |         |      |      |      |      |      |      |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |         |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |         |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |         |   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------|---------|-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | Space || Space |RAISE | Del  |Enter |
 *                   |      |      |      |       ||       |      |      |      |
 *                   `----------------------------''-------'------'------'------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                      KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                  _______,  _______, _______,  _______,                     _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.         ,-----------------------------------------.
 * |      |      |      |      |      |      |         |      |      |      |      |      |      |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |      |      |      |      |      |      |         |      |      |      |      |      |      |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |      |      |      |      |      |      |         |      |      |      |      |      |      |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |      |      |      |      |      |      |         |      |      |      |      |      |      |
 * `-----------------------------------------|---------|-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______,                   _______,  _______, _______, _______
  ), 
  
  /* EXTRA
 * ,-----------------------------------------.         ,-----------------------------------------.
 * |      |      |      |      |      |      |         |      |      |      |      |      |      |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |      |      |      |      |      |      |         |      |      |      |      |      |      |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |      |      |      |      |      |      |         |      | Left | Down |  Up  | Right|      |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |      |      |      |      |      |      |         |      |      |      |      |      |      |
 * `-----------------------------------------|---------|-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_EXTRA] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______,                   _______,  _______, _______, _______
  ), 
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
