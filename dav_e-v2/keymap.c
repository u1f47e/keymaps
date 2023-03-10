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
/*
// Unicode
enum unicode_names {
    HIGHPHEN,
    SMILE,
    BANG,
    IRONY
};

const uint32_t PROGMEM unicode_map[] = {
    [HIGHPHEN] = 0x00AF, // ¯
    [SMILE] = 0x30C4, // ツ
    [BANG] = 0x203D, // ‽
    [IRONY] = 0x2E2E // ⸮
};
*/
// Custom keycodes
enum custom_keycodes {
    RICKROLL = SAFE_RANGE,
    SHRUGZ,
    BANG,
    IRONY
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RICKROLL:
        if (record->event.pressed) {
            // When keycode RICKROLL is pressed
            SEND_STRING("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
        } else {
            // When keycode RICKROLL is released
        }
        break;

    case SHRUGZ:
        if (record->event.pressed) {
            // When keycode SHRUGZ is pressed
            SEND_STRING(SS_LALT("00AF")"\\_("SS_LALT("30C4")")_/"SS_LALT("00AF"));
        } else {
        }
        break;

    case BANG:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("203D"));
        } else {
        }
        break;

    case IRONY:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("2E2E"));
        } else {
        }
        break;
    }
    return true;
};

// Tap dance declarations
enum {
    TD_SFT_CAPS = 0
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for shift, twice for capslock
    [TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    // Other declarations go here, separated by commas
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* qwerty */
		KC_GESC,         KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,      KC_I, KC_O,  KC_P,     KC_DEL, KC_BSPC,
		LT(2, KC_TAB),   KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,      KC_K, KC_L,  KC_SCLN,  LT(2, KC_ENT),
		TD(TD_SFT_CAPS), KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,    MO(3),    KC_N,    KC_M,      KC_COMM,     KC_DOT,   KC_SLSH, RSFT_T(KC_QUOT),
		KC_LCTL,         KC_LAPO,            KC_LGUI, LT(1, KC_SPC),	          KC_SPC,  KC_RGUI,                KC_RAPC,  MO(5)
    ),

    [1] = LAYOUT( /* lower */
		KC_GRV,      KC_1,      KC_2,      KC_3,      KC_4,       KC_5,             KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,   KC_TRNS,
		BANG,        KC_6,      KC_7,      KC_8,      KC_9,       KC_0,             KC_TRNS,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_TRNS,
		KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BSLS,  KC_TRNS,
		KC_TRNS,     KC_TRNS,                         KC_TRNS,    KC_TRNS,	        KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS
    ),

    [2] = LAYOUT( /* raise */
		KC_TILD,  KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,     KC_PERC,          KC_CIRC,   KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,  KC_MINS,  KC_EQL,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR,  KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_PIPE,  KC_TRNS,
		KC_TRNS,  KC_TRNS,                         KC_TRNS,    KC_TRNS,	         KC_TRNS,   KC_TRNS,                    KC_TRNS,  KC_TRNS
    ),

    [3] = LAYOUT( /* navigation */
		KC_TRNS,  KC_TRNS,   KC_UP,     KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
		KC_TRNS,  KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_TRNS,    KC_TRNS,          KC_LEFT,   KC_DOWN,  KC_UP,   KC_RIGHT, KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
		KC_LCTL,  KC_LALT,                         KC_LGUI,    KC_TRNS,	         KC_TRNS,   KC_TRNS,                     KC_TRNS,  OSL(4)
    ),

    [4] = LAYOUT( /* functions */
    	KC_F1,    KC_F2,     KC_F3,     KC_F4,     KC_F5,      KC_F6,            KC_F7,     KC_F8,    KC_F9,   KC_F10,  KC_F11,   KC_F12,    KC_F13,
		KC_TRNS,  KC_F14,    KC_F15,    KC_F16,    KC_F17,      KC_F18,           KC_F19,    KC_F20,   KC_F21,  KC_F23,  KC_F24,   KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_LCTL,  KC_LALT,                         KC_LGUI,    KC_TRNS,	         KC_TRNS,   KC_RGUI,                    KC_RALT,  KC_RCTL
	),

    [5] = LAYOUT( /* media */
		KC_TRNS,  KC_HOME,   KC_END,    KC_PGUP,   KC_PGDN,    KC_INS,           KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_PSCR,  KC_TRNS,   KC_TRNS,
		IRONY,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,           KC_TRNS,   KC_PGDN,  KC_PGUP, KC_TRNS, KC_VOLU,  KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,   KC_MUTE,  KC_MRWD, KC_MFFD, KC_VOLD,  KC_TRNS,
		KC_TRNS,  KC_TRNS,                         MO(6),      KC_TRNS,	         KC_MPLY,   RICKROLL,                   SHRUGZ,   KC_TRNS
    ),

    [6] = LAYOUT( /* reset */
		RESET,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,                         KC_TRNS,    KC_TRNS,	         KC_TRNS,   KC_TRNS,                    KC_TRNS,  KC_TRNS
    )
};


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
        writePinLow(B1);
        writePinHigh(B2);
        writePinLow(B3);
    } else if (get_highest_layer(state) == 3) {
        writePinLow(B1);
        writePinLow(B2);
        writePinHigh(B3);
    } else if (get_highest_layer(state) == 4) {
        writePinHigh(B1);
        writePinHigh(B2);
        writePinLow(B3);
    } else if (get_highest_layer(state) == 5) {
        writePinLow(B1);
        writePinHigh(B2);
        writePinHigh(B3);
    } else if (get_highest_layer(state) == 6) {
        writePinLow(B1);
        writePinHigh(B2);
        writePinLow(B3);
    } else {
    }
    return state;
}
