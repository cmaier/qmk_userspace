/* Copyright 2019 Ryota Goto
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "cmaier.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all(
     QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC, XXXXXXX,
      KC_TAB,    KC_Q,    KC_W,    KC_E,    LP_R,    LP_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,          KC_BSLS,
     MO_INTJ,    KC_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,    KC_H,  HOME_J,  HOME_K,  HOME_L, KC_SCLN, KC_QUOT,                    KC_ENT,
     KC_LSFT, KC_BSLS,    KC_Z,    KC_X,    LP_C,    LP_V,    KC_B,    LP_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,          KC_RSFT, XXXXXXX,
     KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,                         LT_SFN,                       XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL,  MO_MAC
  ),

  [_SPACE_FN] = LAYOUT_all(
      KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL, XXXXXXX,
     KC_SWTR, KC_TBAK, KC_AWND, KC_TFWD, _______, _______, KC_PGUP, KC_HOME,  KC_END, _______, _______, KC_TBAK, KC_TFWD,          _______,
     _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,                   _______,
     _______, _______, _______, _______, _______, _______,  KC_SPC, KC_PGDN, _______, _______, _______, _______,          _______, _______,
     _______, _______, _______, _______,                        _______,                       _______, _______, _______, _______, _______
  ),

  [_MACOS_FN] = LAYOUT_all(
     XXXXXXX, KC_BRDN, KC_BRUP, KC_MCTL, KC_AWND, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_TERM, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_INTELLIJ] = LAYOUT_all(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RNME, XXXXXXX, XXXXXXX, KC_USGE, KC_INLN, XXXXXXX, KC_RPRP, XXXXXXX, XXXXXXX,          XXXXXXX,
     XXXXXXX, KC_RTAS, KC_SIGN, KC_ADBR, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RVAR, XXXXXXX, XXXXXXX, KC_RFUN, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_GAMING] = LAYOUT_all(
     QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC, XXXXXXX,
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,          KC_BSLS,
       KC_F7,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,                    KC_ENT,
     KC_LSFT, KC_BSLS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,          KC_RSFT, XXXXXXX,
     _______, KC_LGUI, KC_LALT, XXXXXXX,                         KC_SPC,                       XXXXXXX, KC_RALT, KC_RGUI, _______, TD(TD_FN)
  ),

  [_GAMING_FN] = LAYOUT_all(
      KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL, XXXXXXX,
     KC_SWTR, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME,  KC_END, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,                   XXXXXXX,
     XXXXXXX, XXXXXXX, TO_BASE, XXXXXXX, XXXXXXX, XXXXXXX,  KC_SPC, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_GAMING_MEDIA] = LAYOUT_all(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_TERM, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_CONFIG] = LAYOUT_all(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
     XXXXXXX, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATU, UG_SATU, UG_SATD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
     XXXXXXX, TO_GAME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KLVE, XXXXXXX, XXXXXXX,                   XXXXXXX,
     XXXXXXX, XXXXXXX, TO_BASE, XXXXXXX, XXXXXXX, KC_VRSN, XXXXXXX, XXXXXXX, KC_MAKE, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};
