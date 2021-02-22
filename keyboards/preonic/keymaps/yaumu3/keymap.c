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
  UM_EMLU,
  UM_EMLJ,
  UM_KHRU,
  UM_KHRJ
};
#define M_CTLE MACROTAP(UM_CTLE) // LCTL or ESC + EN
#define M_EMLU MACROTAP(UM_EMLU) // LOWER or EN (for US layout)
#define M_EMLJ MACROTAP(UM_EMLJ) // LOWER or EN (for JP layout)
#define M_KHRU MACROTAP(UM_KHRU) // RAISE or JP (for US layout)
#define M_KHRJ MACROTAP(UM_KHRJ) // RAISE or JP (for JP layout)

enum preonic_layers {
  _US,
  _JP,
  _LWR_US,
  _LWR_JP,
  _RSE_US,
  _RSE_JP,
  _ADJUST
};

enum preonic_keycodes {
  US = SAFE_RANGE,
  JP,
  LWR_US,
  LWR_JP,
  RSE_US,
  RSE_JP
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
[_US] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  M_CTLE,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  KC_LGUI, KC_LCTL, KC_LALT, KC_ESC,  M_EMLU,  KC_SPC,  KC_SPC,  M_KHRU,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
[_JP] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_6,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    US,      KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  M_CTLE,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  KC_LGUI, KC_LCTL, KC_LALT, KC_ESC,  M_EMLJ,  KC_SPC,  KC_SPC,  M_KHRJ,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
[_LWR_US] = LAYOUT_preonic_grid(
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, KC_PLUS,
  KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_RSFT,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),
[_LWR_JP] = LAYOUT_preonic_grid(
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
[_RSE_US] = LAYOUT_preonic_grid(
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
  _______, _______, KC_LBRC, KC_LCBR, KC_LPRN, _______, _______, KC_RPRN, KC_RCBR, KC_RBRC, KC_MINS, KC_EQL,
  KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_RSE_JP] = LAYOUT_preonic_grid(
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
 * |      |  US  |  JP  |      | RESET|      |      |      |      |      | PSCR |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | AUDIO|      |      |      |      | BR-  | VOL- | VOL+ | BR+  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |CLICKY|      |      |      |      |      |      |      |  LED |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | LED- | LED+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  EEP_RST, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, US,      JP,      _______, RESET,   _______, _______, _______, _______, _______, KC_PSCR, _______,
  _______, AU_TOG,  _______, _______, _______, _______, KC_BRID, KC_VOLD, KC_VOLU, KC_BRIU, _______, _______,
  _______, _______, _______, CK_TOGG, _______, _______, _______, _______,  _______, _______, _______, RGB_TOG,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______
)
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  rgblight_sethsv(0, 0, 0);
#endif
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(default_layer_state)) {
    case _US:
      state = update_tri_layer_state(state, _RSE_US, _LWR_US, _ADJUST);
      break;
    case _JP:
      state = update_tri_layer_state(state, _RSE_JP, _LWR_JP, _ADJUST);
      break;
  }
#ifdef RGBLIGHT_ENABLE
    switch (biton32(state)) {
      case _RSE_US:
      case _RSE_JP:
        rgblight_sethsv(HSV_ORANGE);
        break;
      case _LWR_US:
      case _LWR_JP:
        rgblight_sethsv(HSV_CYAN);
        break;
      case _ADJUST:
        rgblight_sethsv(HSV_RED);
        break;
      default: //  for any other layers, or the default layer
        rgblight_sethsv(0, 0, 0);
        break;
    }
#endif
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case US:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_US);
      }
      return false;
      break;
    case JP:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_JP);
      }
      return false;
      break;
  }
  return true;
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case UM_CTLE:
    return MACRO_TAP_HOLD_MOD( record, MACRO(U(LCTL), T(ESC), T(MHEN), T(LANG2), END), LCTL );
    case UM_EMLU:
    return MACRO_TAP_HOLD_LAYER( record, MACRO(T(MHEN), T(LANG2), END), _LWR_US );
    case UM_EMLJ:
    return MACRO_TAP_HOLD_LAYER( record, MACRO(T(MHEN), T(LANG2), END), _LWR_JP );
    case UM_KHRU:
    return MACRO_TAP_HOLD_LAYER( record, MACRO(T(HENK), T(LANG1), END), _RSE_US );
    case UM_KHRJ:
    return MACRO_TAP_HOLD_LAYER( record, MACRO(T(HENK), T(LANG1), END), _RSE_JP );
  };
  return MACRO_NONE;
}
