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
     QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,   KC_NO,
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,          KC_BSLS,
     KC_INTJ,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,                    KC_ENT,
     KC_LSFT, KC_BSLS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,          KC_RSFT,   KC_NO,
     KC_LCTL, KC_LALT, KC_LGUI,   KC_NO,                         KC_SFN,                         KC_NO, KC_RGUI, KC_RALT, KC_RCTL,  KC_MAC
  ),

  [_SPACE_FN] = LAYOUT_all(
      KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_NO,
      KC_SWTR, _______, KC_PGUP, _______, _______, _______, KC_PGUP, KC_HOME, KC_END, _______, _______, _______, _______,          _______,
     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,                   _______,
     _______, _______, _______, _______, _______, _______,  KC_SPC, KC_PGDN, _______, _______, _______, _______,          _______,  KC_NO,
     _______, _______, _______,   KC_NO,                        _______,                         KC_NO, _______, _______, _______, _______
  ),

  [_MACOS_FN] = LAYOUT_all(
     _______, KC_BRDN, KC_BRUP, KC_MCTL, KC_AWND, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,   KC_NO,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_TERM,   KC_NO,
     _______, _______, _______,   KC_NO,                        _______,                         KC_NO, _______, _______, _______, _______
  ),

  [_INTELLIJ] = LAYOUT_all(
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_NO,
     _______, _______, _______, _______, KC_RNME, _______, _______, KC_USGE, KC_INLN, _______, KC_RPRP, _______, _______,          _______,
     _______, KC_RTAS, KC_SIGN, KC_ADBR, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
     _______, _______, _______, _______, _______, KC_RVAR, _______, _______, KC_RFUN, _______, _______, _______,          _______,   KC_NO,
     _______, _______, _______,   KC_NO,                        _______,                         KC_NO, _______, _______, _______, _______
  ),

  [_GAMING] = LAYOUT_all(
     QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,   KC_NO,
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,          KC_BSLS,
     KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,                    KC_ENT,
     KC_LSFT, KC_BSLS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,          KC_RSFT,   KC_NO,
     KC_LCTL, KC_LALT, KC_LGUI,   KC_NO,                         KC_SPC,                         KC_NO, KC_RGUI, KC_RALT, KC_RCTL, TD(TD_FN)
  ),

  [_GAMING_FN] = LAYOUT_all(
      KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_NO,
      KC_SWTR, _______, KC_PGUP, _______, _______, _______, KC_PGUP, KC_HOME, KC_END, _______, _______, _______, _______,          _______,
     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,                   _______,
     _______, _______, _______, _______, _______, _______,  KC_SPC, KC_PGDN, _______, _______, _______, _______,          _______,  KC_NO,
     _______, _______, _______,   KC_NO,                        _______,                         KC_NO, _______, _______, _______, _______
  ),

  [_GAMING_MEDIA] = LAYOUT_all(
     _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,   KC_NO,
     _______, _______, _______, _______, _______, _______, _______, KC_HOME,   KC_UP,  KC_END, _______, _______, _______,          _______,
     _______, _______, _______, _______, _______, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   _______,
     _______, _______, _______, _______, _______, _______,  KC_SPC, KC_PGDN, _______, _______, _______, _______,          KC_TERM,   KC_NO,
     _______, _______, _______,   KC_NO,                        _______,                         KC_NO, _______, _______, _______, _______
  ),

  [_KEYBOARD_CONFIG] = LAYOUT_all(
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  QK_BOOT,  KC_NO,
     _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______,          _______,
     _______, KC_GAME, _______, _______, _______, _______, _______, _______, _______, KC_LIVE, _______, _______,                   _______,
     _______, _______, KC_BASE, _______, _______, KC_VRSN, _______, _______, KC_MAKE, _______, _______, _______,          _______,   KC_NO,
     _______, _______, _______,   KC_NO,                        _______,                         KC_NO, _______, _______, _______, _______
  )
};
