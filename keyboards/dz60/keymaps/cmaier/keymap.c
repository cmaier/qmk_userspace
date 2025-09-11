#include QMK_KEYBOARD_H
#include "cmaier.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_ansi(
      QK_GESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0, KC_MINS, KC_EQL,KC_BSPC,
           KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,   KC_O,   KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
            KC_INTJ,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L, KC_SCLN, KC_QUOT,   KC_ENTER,
              KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT, KC_SLSH,        KC_RSFT,
         KC_LCTL, KC_LALT, KC_LGUI,               KC_SFN             , KC_RGUI, KC_RALT, KC_RCTL,  KC_MAC),

//   [_SPACE_FN] = LAYOUT_60_ansi_kc(
//       KC_GRV,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12,   KC_DEL,
//        SWTR,KC_NO,KC_UP,KC_NO,KC_NO,KC_NO,KC_NO,KC_HOME,KC_UP,END, _, _,  _,     _,
//                _,LEFT,DOWN,RGHT,    _,   _,PGUP,LEFT,DOWN,RGHT,   _,    _,       _,
//                  _,   _,   _,   _,   _, SPC,PGDN,   _,   _,   _,   _,            _,
//             _,    _,    _,                _              ,    _,    _,    _,    _),

//   [_MACOS_FN] = LAYOUT_60_ansi_kc(
//        KC_NO,BRDN,BRUP,MCTL,AWND,   _,   _,MPRV,MPLY,MNXT,MUTE,VOLD,VOLU,    KC_NO,
//         _,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,  _,  _,  _,  _,       _,
//                _,   _,   _,   _,   _,   _,   _,   _,   _,   _,   _,   _,         _,
//                  _,   _,   _,   _,   _,   _,   _,   _,   _,   _,   _,         TERM,
//             _,    _,    _,                _              ,    _,    _,    _,    _),

//   [_INTELLIJ] = LAYOUT_60_ansi_kc(
//        KC_NO,   _,   _,   _,   _,   _,   _,   _,   _,   _,   _,   _,   _,    KC_NO,
//         _,KC_NO,KC_NO,KC_NO,KC_RNME,KC_NO,KC_NO,KC_USGE,KC_INLN, _,RPRP, _, _,   _,
//                _,RTAS,SIGN,ADBR,   _,   _,   _,   _,   _,   _,   _,   _,         _,
//                  _,   _,   _,   _,RVAR,   _,   _,RFUN,   _,   _,   _,            _,
//             _,    _,    _,                _              ,    _,    _,    _,    _),

//   [_GAMING] = LAYOUT_60_ansi_kc(
//      QK_GESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,  KC_BSPC,
//            TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,   O,   P,LBRC,RBRC,   BSLS,
//             GFUN,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT,     ENTER,
//               LSFT,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,         RSFT,
//          LCTL, LALT, LGUI,               SPC             , RGUI, RALT, RCTL, GMMA),

//   [_GAMING_FN] = LAYOUT_60_ansi_kc(
//       KC_GRV,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12,   KC_DEL,
//        SWTR,KC_NO,KC_UP,KC_NO,KC_NO,KC_NO,KC_NO,KC_HOME,KC_UP,END, _, _,  _,     _,
//                _,LEFT,DOWN,RGHT,   _,   _,PGUP,LEFT,DOWN,RGHT,   _,   _,         _,
//                  _,   _,   _,   _,   _, SPC,PGDN,   _,   _,   _,   _,            _,
//             _,    _,    _,                _              ,    _,    _,    _,    _),

//   [_GAMING_MEDIA] = LAYOUT_60_ansi_kc(
//        KC_NO,   _,   _,   _,   _,   _,   _,MPRV,MPLY,MNXT,MUTE,VOLD,VOLU,  KC_DEL,
//         _,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, KC_HOME, KC_UP, END, _, _, _,    _,
//                _,   _,   _,   _,   _,   _,PGUP,LEFT,DOWN,RGHT,   _,   _,        _,
//                  _,   _,   _,   _,   _, SPC,PGDN,   _,   _,   _,   _,           _,
//             _,    _,    _,                _              ,    _,    _,    _,    _),

//   [_KEYBOARD_CONFIG] = LAYOUT_60_ansi_kc(
//        KC_NO,   _,   _,   _,   _,   _,   _,   _,   _,   _,   _,   _,   _,  QK_BOOT,
//         _,UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATU, UG_SATU, UG_SATD, _, _, _, _, _,
//                _,BASE,   _,   _,   _,   _,   _,   _,   _,LIVE,   _,   _,         _,
//                  _,GAME,   _,   _,VRSN,   _,   _,MAKE,   _,   _,   _,            _,
//             _,    _,    _,                _              ,    _,    _,    _,    _)
};
