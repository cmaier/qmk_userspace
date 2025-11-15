/*
  Copyright 2019 Christian Maier <cmaierrr@gmail.com> @cmaier

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "cmaier.h"
#include "version.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

static uint32_t key_keep_alive_timer = 0;
static bool key_keep_alive_trigger = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_MAKE:
    case KC_VRSN:
      process_record_keyboard(keycode, record);

    case KC_BRDN:
    case KC_BRUP:
    case KC_SWTR:
    case KC_AWND:
    case KC_TERM:
      return process_record_macos(keycode, record);

    case KC_ADBR:
    case KC_RFUN:
    case KC_RNME:
    case KC_RPRP:
    case KC_RTAS:
    case KC_RVAR:
    case KC_INLN:
    case KC_SIGN:
    case KC_USGE:
      process_record_intellij(keycode, record);
      break;

    case KC_LIVE:
      if (record->event.pressed) {
          key_keep_alive_trigger ^= true;

          if (key_keep_alive_trigger) {
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_setrgb(RGB_MY_PINK);
          } else {
            rgblight_disable_noeeprom();
          }
      }
      break;
  }

  return process_record_keymap(keycode, record);
}

void matrix_scan_user(void) {
    // KC_LIVE, Keep alive!
    if (timer_elapsed32(key_keep_alive_timer) > 260000) { // 4'20"
        key_keep_alive_timer = timer_read32();  // resets timer
        if (key_keep_alive_trigger) { // tap if enabled
            tap_code(MS_RGHT);
            // tap_code(KC_MS_DOWN);
            tap_code(MS_LEFT);
            // tap_code(KC_MS_UP);
        }
    }
}

enum combo_events {
  KBD_CONFIG,
};

const uint16_t PROGMEM kbd_combo[] = {KC_LCTL, KC_RCTL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [KBD_CONFIG] = COMBO_ACTION(kbd_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case KBD_CONFIG:
      if (pressed) {
        layer_on(_KEYBOARD_CONFIG);
      } else {
        layer_off(_KEYBOARD_CONFIG);
      }
      break;
  }
}

// TAP DANCE START

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (tap_dance_state_t *state);

//for the fn tap dance. Put it here so it can be used in any keymap
void fn_finished (tap_dance_state_t *state, void *user_data);
void fn_reset (tap_dance_state_t *state, void *user_data);

int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
  if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'fn' tap dance.
static tap fntap_state = {
  .is_press_action = true,
  .state = 0
};

void fn_finished (tap_dance_state_t *state, void *user_data) {
  fntap_state.state = cur_dance(state);
  switch (fntap_state.state) {
    case SINGLE_HOLD: layer_on(_GAMING_MEDIA); break;
    case DOUBLE_HOLD: layer_on(_GAMING_FN); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void fn_reset (tap_dance_state_t *state, void *user_data) {
  switch (fntap_state.state) {
    case SINGLE_HOLD: layer_off(_GAMING_MEDIA); break;
    case DOUBLE_HOLD: layer_off(_GAMING_FN);
  }
  fntap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_finished, fn_reset)
};

// TAP DANCE END

void process_record_keyboard(uint16_t keycode, keyrecord_t *record) {
  bool isPressed = record->event.pressed;
  switch (keycode) {
    case KC_MAKE:
      if (isPressed) {
        send_string_with_delay_P(PSTR("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER)), MACRO_TIMER);
      }
      break;

    case KC_VRSN:
      if (isPressed) {
        send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), MACRO_TIMER);
      }
      break;
  }
}

void process_record_intellij(uint16_t keycode, keyrecord_t *record) {
  bool isPressed = record->event.pressed;
  switch (keycode) {
    case KC_ADBR:
      if (isPressed) {
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_F5)SS_UP(X_LSFT)SS_UP(X_LALT));
      }
      break;

    case KC_RFUN:
      if (isPressed) {
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_DOWN(X_LGUI)"m"SS_UP(X_LGUI)SS_UP(X_LSFT)SS_UP(X_LALT));
      }
      break;

    case KC_RNME:
      if (isPressed) {
        SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_F6)SS_UP(X_LSFT));
      }
      break;

    case KC_RPRP:
      if (isPressed) {
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI)"p"SS_UP(X_LGUI)SS_UP(X_LSFT));
      }
      break;

    case KC_RTAS:
      if (isPressed) {
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_DOWN(X_LGUI)"a"SS_UP(X_LGUI)SS_UP(X_LSFT)SS_UP(X_LALT));
      }
      break;

    case KC_RVAR:
      if (isPressed) {
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI)"v"SS_UP(X_LGUI)SS_UP(X_LALT));
      }
      break;

    case KC_INLN:
      if (isPressed) {
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI)"n"SS_UP(X_LGUI)SS_UP(X_LALT));
      }
      break;

    case KC_SIGN:
      if (isPressed) {
        SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_F6)SS_UP(X_LGUI));
      }
      break;

    case KC_USGE:
      if (isPressed) {
        SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_F7)SS_UP(X_LALT));
      }
      break;
  }
}

bool process_record_macos(uint16_t keycode, keyrecord_t *record) {
  bool isPressed = record->event.pressed;
  uint8_t key;
  switch (keycode) {
    case KC_BRDN:
    case KC_BRUP:
      // Clear the RGUI modifier placed by LM for _ML layer as brightness don't
      // work with modifiers.
      key = (keycode == KC_BRDN) ? KC_SCRL : KC_PAUS;
      if (isPressed) {
          unregister_mods(MOD_RGUI);
          add_key(key);
          send_keyboard_report();
      } else {
          del_key(key);
          send_keyboard_report();
      }
      return false; // Skip all further processing of this key

    case KC_SWTR:
      if (isPressed) {
        SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_GRAVE)SS_UP(X_LGUI));
      }
      break;

    case KC_AWND:
      if (isPressed) {
        SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_DOWN)SS_UP(X_LCTL));
      }
      break;

    case KC_TERM:
      if (isPressed) {
        SEND_STRING(SS_RALT("/"));
      }
      break;
  }

  return true;
}

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_disable();
}
#endif
