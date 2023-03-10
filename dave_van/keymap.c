#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

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
  [0] = LAYOUT( /* Qwerty */
    KC_ESC,          KC_Q,    KC_W,    KC_E,  KC_R, KC_T,           KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,    KC_BSPC,
    LT(2, KC_TAB),   KC_A,    KC_S,    KC_D,  KC_F, KC_G,           KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN, LT(2, KC_ENT),
    TD(TD_SFT_CAPS), KC_Z,    KC_X,    KC_C,  KC_V, KC_B,           KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_QUOT),
    KC_LCTL,         KC_LALT, KC_LGUI,              LT(1, KC_SPC), KC_SPC,                 TG(3),  MO(4),   TG(5)
  ),
  [1] = LAYOUT( /* Lower */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  ),
  [2] = LAYOUT( /* Raise */
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  ),
  [3] = LAYOUT( /* FN Layer */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______, _______,                   _______, TG(3),   _______
  ),
  [4] = LAYOUT( /* Media Layer*/
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_VOLU, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MUTE,  KC_MRWD, KC_MFFD, KC_VOLD, _______,
    TG(6),   _______, _______,                   _______, KC_MPLY,                    _______, _______, _______
  ),
  [5] = LAYOUT( /* Nav Layer*/
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, KC_LALT, KC_LGUI,                   _______, _______,                   KC_LCTL, _______, TG(5)
  ),
  [6] = LAYOUT( /* RESET Layer*/
    RESET,   _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    TG(6),   _______, _______,                   _______,  _______,                   _______, _______, _______
  )
};


void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_OFF);
    rgblight_set_effect_range(0, 1);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}


uint32_t layer_state_set_user(uint32_t state){
  #ifdef RGBLIGHT_ENABLE

    uint8_t led0r = 0; uint8_t led0g = 0; uint8_t led0b = 0;
    uint8_t led1r = 0; uint8_t led1g = 0; uint8_t led1b = 0;
    uint8_t led2r = 0; uint8_t led2g = 0; uint8_t led2b = 0;

    if (layer_state_cmp(state, 0)) {
        led0g = 136, led0b = 204;
    }
    if (layer_state_cmp(state, 1)) {
      led1g = 136, led1b = 204;
    }
    if (layer_state_cmp(state, 2)) {
      led2g = 136, led2b = 204;
    }
    if (layer_state_cmp(state, 3)) {
      led0r = 64, led0b = 119;
    }
    if (layer_state_cmp(state, 4)) {
      led1r = 64, led1b = 119;
    }
    if (layer_state_cmp(state, 5)) {
      led2r = 64, led2b = 119;
    }
    if (layer_state_cmp(state, 6)) {
      led0r = 250, led1g = 250, led2b = 250;
    }

    setrgb(led0r, led0g, led0b, (LED_TYPE *)&led[0]);
    setrgb(led1r, led1g, led1b, (LED_TYPE *)&led[1]);
    setrgb(led2r, led2g, led2b, (LED_TYPE *)&led[2]);
    rgblight_set();
  #endif //RGBLIGHT_ENABLE
  return state;
}
