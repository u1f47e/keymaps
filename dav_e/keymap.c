/* Copyright 2018 Holten Campbell
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* qwerty */
		KC_GESC,         KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,              KC_Y,   KC_U,     KC_I, KC_O,    KC_P,    KC_BSPC, KC_DEL,
		LT(2, KC_TAB),   KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,   KC_J,     KC_K, KC_L,    KC_SCLN, LT(2, KC_ENT),
		TD(TD_SFT_CAPS), KC_Z,     KC_X,     KC_C,    KC_V,    KC_B, LT(3, KC_B), KC_N,   KC_M,     KC_COMM,       KC_DOT,  KC_SLSH, RSFT_T(KC_QUOT),
		KC_LCTL,         KC_LALT,            KC_LGUI, LT(1, KC_SPC),	          KC_SPC, KC_RGUI,                 TG(3),   MO(4)
    ),

    [1] = LAYOUT( /* lower */
		KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,       KC_5,             KC_6,      KC_7,      KC_8,     KC_9,     KC_0,     KC_TRNS,   KC_TRNS,
		KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_MINS,   KC_EQL,   KC_LBRC,  KC_RBRC,  KC_TRNS,
		KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_BSLS,  KC_TRNS,
		BL_TOGG,   BL_STEP,                         KC_TRNS,    KC_TRNS,	      KC_TRNS,   KC_TRNS,                       KC_TRNS,  KC_TRNS
    ),

    [2] = LAYOUT( /* raise */
		KC_TRNS,  KC_EXLM,  KC_AT,     KC_HASH,   KC_DLR,     KC_PERC,          KC_CIRC,   KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,  KC_MINS,  KC_EQL,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR,  KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_P1,     KC_P2,    KC_P3,   KC_TRNS, KC_PIPE,  KC_TRNS,
		KC_TRNS,  KC_TRNS,                         KC_TRNS,    KC_TRNS,	         KC_PENT,   KC_PDOT,                    KC_TRNS,  KC_TRNS
    ),

    [3] = LAYOUT( /* fn-nav */
		KC_F1,    KC_F2,     KC_UP,     KC_F3,     KC_F4,      KC_F5,            KC_F6,     KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,
		KC_TRNS,  KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_LCTL,  KC_LALT,                         KC_LGUI,    KC_TRNS,	         KC_TRNS,   KC_TRNS,                    TG(3),    KC_TRNS
    ),

    [4] = LAYOUT( /* media */
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_HOME,   KC_PGDN,  KC_PGUP, KC_END,  KC_VOLU,  KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, MO(5),   KC_TRNS,   KC_MUTE,  KC_MRWD, KC_MFFD, KC_VOLD,  KC_TRNS,
		KC_LCTL,  KC_LALT,                         KC_LGUI,    KC_TRNS,	         KC_MPLY,   KC_TRNS,                    KC_TRNS,  KC_TRNS
    ),

    [5] = LAYOUT( /* reset */
		RESET,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,                         KC_TRNS,    KC_TRNS,	         KC_TRNS,   KC_TRNS,                    KC_TRNS,  KC_TRNS
    )
};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B1);
  writePinLow(B1);
  // set NumLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set ScrollLock LED to output and low
  setPinOutput(B3);
  writePinLow(B3);
}

void matrix_scan_user(void) {

}

/*
void led_set_user(uint8_t usb_led) {

  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinHigh(B1);
  } else {
    writePinLow(B1);
  }

  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    writePinHigh(B3);
  } else {
    writePinLow(B3);

}
*/

//function for layer indicator LED
layer_state_t layer_state_set_user(layer_state_t state)
{
    if (get_highest_layer(state) == 0) {
    writePinHigh(B1);
    writePinHigh(B2);
    writePinHigh(B3);
    } else if (get_highest_layer(state) == 1) {
        writePinHigh(B1);
        writePinLow(B2);
        writePinLow(B3);
    } else if (get_highest_layer(state) == 2) {
        writePinHigh(B2);
        writePinLow(B1);
        writePinLow(B3);
    } else if (get_highest_layer(state) == 3) {
        writePinHigh(B3);
        writePinLow(B1);
        writePinLow(B2);
    } else if (get_highest_layer(state) == 4) {
        writePinHigh(B1);
        writePinHigh(B3);
        writePinLow(B2);
    } else if (get_highest_layer(state) == 5) {
        writePinLow(B1);
        writePinLow(B2);
        writePinLow(B3);
    } else {
    }
    return state;
}
