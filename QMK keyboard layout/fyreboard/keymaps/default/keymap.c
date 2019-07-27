/* Copyright 2019 fyrefawkes
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base, Osu mode */
      KC_ESC, TO(1),  KC_ENTER, \
      KC_S,  KC_D, KC_F, KC_J, KC_K, KC_L, \
      KC_F2, KC_R, KC_SPACE, KC_SPACE, KC_DOT, KC_SLASH, \
      KC_LEFT, KC_RIGHT, KC_UP, KC_DOWN \
  ),
  [1] = LAYOUT( /* KSM/8k mode */
      KC_ESC, TO(0), KC_ENTER, \
      KC_S,  KC_D, KC_F, KC_J, KC_K, KC_L, \
      KC_LEFT, KC_RIGHT, KC_C, KC_N, KC_UP, KC_DOWN, \
      KC_Q, KC_W, KC_O, KC_P \
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  uint8_t layer = biton32(layer_state);
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 3, .col = 1}));
    } else {
      tap_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 3, .col = 0}));
    }
  } else if (index == 1) { /* Second encoder */  
    if (clockwise) {
      tap_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 3, .col = 5}));
    } else {
      tap_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 3, .col = 4}));
    }
  }
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
