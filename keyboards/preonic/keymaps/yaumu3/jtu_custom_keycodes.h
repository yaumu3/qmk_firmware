// Keycodes to use jis keycode in us keymap

#pragma once

#include "action.h"
#include "quantum_keycodes.h"

enum jtu_custom_keycodes {
  JU_GRV = SAFE_RANGE,
  JU_TILD,
  JU_2,
  JU_AT,
  JU_6,
  JU_CIRC,
  JU_7,
  JU_AMPR,
  JU_8,
  JU_ASTR,
  JU_9,
  JU_LPRN,
  JU_0,
  JU_RPRN,
  JU_MINS,
  JU_UNDS,
  JU_EQL,
  JU_PLUS,
  JU_LBRC,
  JU_LCBR,
  JU_RBRC,
  JU_RCBR,
  JU_BSLS,
  JU_PIPE,
  JU_SCLN,
  JU_QUOT,
  JU_CAPS,
  JTU_SAFE_RANGE
};

bool process_record_user_jtu(uint16_t keycode, keyrecord_t *record);
