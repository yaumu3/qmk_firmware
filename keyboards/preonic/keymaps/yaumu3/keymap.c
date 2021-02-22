/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum user_macro {
  UM_CTLE,
};
#define M_CTLE MACROTAP(UM_CTLE) // LCTL or ESC + EN

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BSPC |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | LCTL*|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | ENT* |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LGUI | LCTL | LALT | ESC  |LOWER*|     SPC     |RAISE*| LEFT | DOWN |  UP  | RGHT |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  M_CTLE,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  KC_LGUI, KC_LCTL, KC_LALT, KC_ESC,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* LOWER
 * ,-----------------------------------------------------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | BSPC |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | LEFT | DOWN |  UP  | RGHT |   _  |  +   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSFT |      |      |      |      |      |      |      |      |      |   |  | RSFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LGUI | LCTL | LALT | ESC  |      |             |      | HOME | PGDN | PGUP | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, KC_PLUS,
  KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_RSFT,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* RAISE
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |   [  |   {  |   (  |      |      |   )  |   }  |   ]  |   -  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSFT |      |      |      |      |      |      |      |      |      |   \  | RSFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LGUI | LCTL | LALT | ESC  |      |             |      | HOME | PGDN | PGUP | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
  _______, _______, KC_LBRC, KC_LCBR, KC_LPRN, _______, _______, KC_RPRN, KC_RCBR, KC_RBRC, KC_MINS, KC_EQL,
  KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* ADJUST (LOWER + RAISE)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |QWERTY|      |      | RESET|      |      |      |      |      | PSCR |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | AUDIO|      |      |      |      | BR-  | VOL- | VOL+ | BR+  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  LED |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | LED- | LED+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, QWERTY,  _______, _______, RESET,   _______, _______, _______, _______, _______, KC_PSCR, _______,
  _______, AU_TOG,  _______, _______, _______, _______, KC_BRID, KC_VOLD, KC_VOLU, KC_BRIU, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______
)
};

static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        lower_pressed_time = record->event.time;
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) {
          register_code(KC_LANG2);  // macOS
          register_code(KC_MHEN);   // Windows
          unregister_code(KC_MHEN);
          unregister_code(KC_LANG2);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
          register_code(KC_LANG1);  // macOS
          register_code(KC_HENK);   // Windows
          unregister_code(KC_HENK);
          unregister_code(KC_LANG1);
        }
        raise_pressed = false;
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        // reset the flags
        lower_pressed = false;
        raise_pressed = false;
      }
    break;
  }
  return true;
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case UM_CTLE:
    return MACRO_TAP_HOLD_MOD( record, MACRO(U(LCTL), T(ESC), T(MHEN), T(LANG2), END), LCTL );
  };
  return MACRO_NONE;
}
