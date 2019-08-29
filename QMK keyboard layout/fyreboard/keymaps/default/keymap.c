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
      KC_ESC, MO(6),  KC_ENTER, \
      KC_S, KC_D, KC_F, KC_J, KC_K, KC_L, \
      KC_F2, KC_R, KC_SPACE, KC_SPACE, KC_DOT, KC_SLASH, \
      KC_LEFT, KC_RIGHT, KC_UP, KC_DOWN \
  ),
  [1] = LAYOUT( /* KSM/8k mode */
      KC_ESC, KC_TRNS, KC_ENTER, \
      KC_S, KC_D, KC_F, KC_J, KC_K, KC_L, \
      KC_F2, KC_TAB, KC_C, KC_N, KC_PGUP, KC_PGDOWN, \
      KC_Q, KC_W, KC_O, KC_P \
  ),
  [2] = LAYOUT( /* Function Button */
      KC_ESC, KC_TRNS, KC_ENTER, \
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, \
      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
      KC_LEFT, KC_RIGHT, KC_UP, KC_DOWN \
  ),
  [3] = LAYOUT( /* Programmer mode */
      KC_ESC, KC_TRNS, KC_ENTER, \
      KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, \
      KC_INS, KC_DEL, KC_HOME, KC_END, KC_PGUP, KC_PGDOWN, \
      KC_LEFT, KC_RIGHT, KC_UP, KC_DOWN \
  ),
  [6] = LAYOUT( /* Layer Switching and audio control*/
      KC_NO, KC_TRNS,  KC_NO, \
      TO(0), TO(1), TO(2), TO(3), KC_NO, KC_NO, \
      MO(7), KC_MUTE, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, \
      KC_NO, KC_NO, KC_VOLD, KC_VOLU \
  ),
  [7] = LAYOUT( /* Reset Layer */
      KC_NO, KC_TRNS,  KC_NO, \
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, RESET, \
      KC_NO, KC_NO, KC_NO, KC_NO \
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
