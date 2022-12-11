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
#define SS_EISU SEND_STRING(SS_TAP(X_INT5) SS_TAP(X_LNG2))
#define SS_KANA SEND_STRING(SS_TAP(X_INT4) SS_TAP(X_LNG1))

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
  CTL_ESC,
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
  KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,  KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTL_ESC, KC_A,    KC_S,    KC_D,   KC_F,  KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  KC_LGUI, KC_LCTL, KC_LALT, KC_ESC, LOWER, KC_SPC,  KC_SPC,  RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
 * |      |      |      |      | BOOT |      |      |      |      |      | PSCR |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | AUDIO|      |      |      |      | BR-  | VOL- | VOL+ | BR+  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | CAPS |      |      |CLICKY|      |      |      |      |      |      |      |  LED |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | LED- | LED+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  EE_CLR,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, QK_BOOT, _______, _______, _______, _______, _______, KC_PSCR, _______,
  _______, AU_TOG,  _______, _______, _______, _______, KC_BRID, KC_VOLD, KC_VOLU, KC_BRIU, _______, _______,
  KC_CAPS, _______, _______, CK_TOGG, QWERTY,  _______, _______, _______, _______, _______, _______, RGB_TOG,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______
)
};

void keyboard_pre_init_user(void) {
    rgblight_disable();
}

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(0, 0, 0);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (biton32(default_layer_state)) {
    case _QWERTY:
      state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
      break;
  }
#ifdef RGBLIGHT_ENABLE
    switch (biton32(state)) {
      case _LOWER:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom(HSV_CYAN);
        break;
      case _RAISE:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom(HSV_ORANGE);
        break;
      case _ADJUST:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
        rgblight_sethsv_noeeprom(HSV_RED);
        break;
      default: //  for any other layers, or the default layer
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom(0, 0, 0);
        break;
    }
#endif
  return state;
}

// result of process_record_user
#define PROCESS_OVERRIDDEN_BEHAVIOR false
#define PROCESS_USUAL_BEHAVIOR true
static bool lctrl_pressed = false;
static bool lower_pressed = false;
static bool raise_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return PROCESS_OVERRIDDEN_BEHAVIOR;
    case CTL_ESC:
      if (record->event.pressed) {
        lctrl_pressed = true;
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
        if (lctrl_pressed) {
          SEND_STRING(SS_TAP(X_ESC));
          SS_EISU;
        }
        lctrl_pressed = false;
      }
      return PROCESS_OVERRIDDEN_BEHAVIOR;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
        if (lower_pressed) {
          SS_EISU;
        }
        lower_pressed = false;
      }
      return PROCESS_OVERRIDDEN_BEHAVIOR;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
        if (raise_pressed) {
          SS_KANA;
        }
        raise_pressed = false;
      }
      return PROCESS_OVERRIDDEN_BEHAVIOR;
    default:
      if (record->event.pressed) {
        lctrl_pressed = false;
        lower_pressed = false;
        raise_pressed = false;
      }
      break;
  }
  return PROCESS_USUAL_BEHAVIOR;
};
