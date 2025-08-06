#include QMK_KEYBOARD_H
#include "quantum.h"

enum my_keycodes {
  CMSC = SAFE_RANGE,  //CoMma Semi-Colon
  PECO,               //PEriod COlon
  EXQU,               //EXclamation QUestion
  SLAB,               //SLAsh Backslash
  BSDE,               //BackSpace DElete
};



enum custom_keycodes {
    //QMK_THM = SAFE_RANGE,
    //QMK_LEM,
    //QMK_REF,
    //QMK_CITE,
    //QMK_FRAC,
    EXC_DECOL,
};

uint8_t mod_state;
bool delkey_was_last; 

uint16_t last_keycode;
uint16_t last_mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  //I attempted to make the repeat key work for (Shift + BSPACE = DEL), but failed
  //note that 'return false;' makes sure that the ongoing program does not process the key as normal
  

  mod_state = get_mods();

  delkey_was_last=false;
  switch (keycode) {
    case CMSC:{ //CoMma Semi-Colon
      static bool ShiftSColon_key_registered;
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          register_code(KC_SCLN);
          // Update the boolean variable to reflect the status of KC_DEL
          ShiftSColon_key_registered = true;
          // Reapplying modifier state so that the held shift key(s)
          // still work even after having tapped the Backspace/Delete key.
          set_mods(mod_state);
          return false;
        }
        else{
          register_code(KC_COMM);
          return false;
        }
      }
      else{
        if(ShiftSColon_key_registered){
          del_mods(MOD_MASK_SHIFT);
          unregister_code(KC_SCLN);
          set_mods(mod_state);
          ShiftSColon_key_registered=false;
          return false;
        }
        else{
          unregister_code(KC_COMM);
          return false;
        }
      }
    }
    case PECO:{ //PEriod COlon
    static bool ShiftColon_key_registered;
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          register_mods(MOD_LSFT);
          register_code(KC_SCLN);
          // Update the boolean variable to reflect the status of KC_DEL
          ShiftColon_key_registered = true;
          // Reapplying modifier state so that the held shift key(s)
          // still work even after having tapped the Backspace/Delete key.
          set_mods(mod_state);
          return false;
        }
        else{
          register_code(KC_DOT);
          return false;
        }
      }
      else{
        if(ShiftColon_key_registered){
          register_mods(MOD_LSFT);
          unregister_code(KC_SCLN);
          set_mods(mod_state);
          ShiftColon_key_registered=false;
          return false;
        }
        else{
          unregister_code(KC_DOT);
          return false;
        }
      }
    }
    case EXQU:{ //EXclamation QUestion
      static bool EXQU_key_registered;
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          register_mods(MOD_LSFT);
          register_code(KC_1);
          // Update the boolean variable to reflect the status of KC_DEL
          EXQU_key_registered = true;
          // Reapplying modifier state so that the held shift key(s)
          // still work even after having tapped the Backspace/Delete key.
          set_mods(mod_state);
          return false;
        }
        else{
          del_mods(MOD_MASK_SHIFT);
          register_mods(MOD_LSFT);
          register_code(KC_SLSH);
          set_mods(mod_state);
          return false;
        }
      }
      else{
        if(EXQU_key_registered){
          register_mods(MOD_LSFT);
          unregister_code(KC_1);
          set_mods(mod_state);
          EXQU_key_registered=false;
          return false;
        }
        else{
          register_mods(MOD_LSFT);
          unregister_code(KC_SLSH);
          set_mods(mod_state);
          return false;
        }
      }
    }
    case SLAB:{ //SLAsh Backslash
      static bool EXQU_key_registered;
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          register_code(KC_SLSH);
          // Update the boolean variable to reflect the status of KC_DEL
          EXQU_key_registered = true;
          // Reapplying modifier state so that the held shift key(s)
          // still work even after having tapped the Backspace/Delete key.
          set_mods(mod_state);
          return false;
        }
        else{
          register_code(KC_BSLS);
          return false;
        }
      }
      else{
        if(EXQU_key_registered){
          unregister_code(KC_SLSH);
          EXQU_key_registered=false;
          return false;
        }
        else{
          unregister_code(KC_BSLS);
          return false;
        }
      }
    }   
    case BSDE:{ //BackSpace DElete
      static bool BSDE_key_registered;
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          register_code(KC_DEL);
          // Update the boolean variable to reflect the status of KC_DEL
          BSDE_key_registered = true;
          // Reapplying modifier state so that the held shift key(s)
          // still work even after having tapped the Backspace/Delete key.
          set_mods(mod_state);
          return false;
        }
        else{
          register_code(KC_BSPC);
          return false;
        }
      }
      else{
        if(BSDE_key_registered){
          del_mods(MOD_MASK_SHIFT);
          unregister_code(KC_DEL);
          BSDE_key_registered=false;
          set_mods(mod_state);
          return false;
        }
        else{
          unregister_code(KC_BSPC);
          return false;
        }
      }
    }
  case EXC_DECOL:
    SEND_STRING(SS_LALT("hhn"));
    break;    
  case KC_BSPC:
      {
      // Initialize a boolean variable that keeps track
      // of the delete key status: registered or not?
      static bool delkey_registered;
      if (record->event.pressed) {
          // Detect the activation of either shift keys
          if (mod_state & MOD_MASK_SHIFT) {
              // First temporarily canceling both shifts so that
              // shift isn't applied to the KC_DEL keycode
              del_mods(MOD_MASK_SHIFT);
              register_code(KC_DEL);
              delkey_was_last=true;
              // Update the boolean variable to reflect the status of KC_DEL
              delkey_registered = true;
              // Reapplying modifier state so that the held shift key(s)
              // still work even after having tapped the Backspace/Delete key.
              set_mods(mod_state);
              return false;
          }
      } else { // on release of KC_BSPC
          // In case KC_DEL is still being sent even after the release of KC_BSPC
          if (delkey_registered) {
              unregister_code(KC_DEL);
              delkey_registered = false;
              return false;
          }
      }
      // Let QMK process the KC_BSPC keycode as usual outside of shift
      return true;
      }
  

    }
    return true; 
}