/* Copyright 2021 Terry Mathews
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation,  either version 2 of the License,  or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not,  see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// Tap dance declarations
enum {
	TD_SFT_CAPS = 0
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	// Tap once for shift, twice for capslock
	[TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
	// Other declarations go here, separated by commas
};

enum layer_names {
    _BL,
    _R,
    _L,
    _FL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_BL] = LAYOUT(
  KC_ESC,         KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,           KC_DEL, KC_BSPC, KC_PGUP, KC_P7, KC_P8, KC_P9,  \
  LT(_R, KC_TAB),  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,        LT(_R, KC_ENT),  KC_PGDN, KC_P4, KC_P5, KC_P6,  \
  TD(TD_SFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,  RSFT_T(KC_QUOT),  KC_UP,   KC_P1, KC_P2, KC_P3,  \
  KC_LCTL, KC_LALT, KC_LGUI, LT(_L, KC_SPC), KC_SPC, KC_SPC, TG(_FL), KC_RALT, KC_RCTL,                 KC_LEFT,  KC_DOWN, KC_RIGHT, KC_P0, KC_PENT),

  /* Keymap _R: Raise */
  [_R] = LAYOUT(
  KC_TILD,  KC_EXLM, KC_AT,  KC_HASH,  KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, KC_HOME,  C(A(KC_DEL)), KC_MPLY, KC_VOLU, \
  _______,  _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,          KC_END,   KC_MPRV, KC_MNXT, KC_VOLD, \
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, _______, _______,           S(G(KC_4)), KC_MUTE, KC_CAPS, \
  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,                            _______, _______, _______,  _______, _______
  ),

  /* Keymap _L: Lower */
  [_L] = LAYOUT(
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, KC_VOLU,  C(G(KC_Q)), KC_MPLY, KC_VOLU, \
  _______,  _______, _______, _______, _______, _______, _______, KC_MINUS, KC_EQL, KC_LBRC, KC_RBRC, _______,          KC_VOLD,  KC_MPRV, KC_MNXT, KC_VOLD, \
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______, _______,           S(G(KC_3)), _______, KC_CAPS, \
  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,                            _______, _______, _______,  _______, _______
  ),
  /* Keymap _FL: Function Layer
   */
[_FL] = LAYOUT(
  QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F13, KC_F14, KC_F15, KC_F16, \
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,           KC_F9, KC_F10, KC_F11, KC_F12, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_F5, KC_F6,  KC_F7,  KC_F8,  \
  KC_LCTL, KC_LALT, KC_LGUI, LT(_L, KC_SPC),  KC_SPC, KC_SPC, TG(_FL), KC_RALT, KC_RCTL, KC_LEFT,                                     KC_F1, KC_F2,  KC_F3,  KC_F4)
};

