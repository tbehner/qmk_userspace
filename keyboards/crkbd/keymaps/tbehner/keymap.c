/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "common/common_keys.h"

enum layers {
  _BASE,
  _NUMB,
  _SYMB,
  _NAV,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NUMB,
  NAV,
  CW_LEFT,
  CW_RIGHT,
  CW_UP,
  CW_DOWN,
  AW_SWITCH,
};

#include "common/combos.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_wrapper(
  //,-------------------------------------------.                    ,--------------------------------------------.
                      BASE_LEFT_UPPER           ,                         BASE_RIGHT_UPPER ,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                      BASE_LEFT_MID             ,                         BASE_RIGHT_MID   ,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                      BASE_LEFT_LOWER           ,                         BASE_RIGHT_LOWER ,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                QK_LEAD,   GTSYM,  NTAB  ,     SSSFT,   SSYM  , QK_LEAD
                            //`--------------------------'  `--------------------------'

  ),

    [_NUMB] = LAYOUT_wrapper(
  //,-------------------------------------------.                    ,---------------------------------------------
                      NUMBER_LEFT_UPPER           ,                         NUMBER_RIGHT_UPPER ,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
                      NUMBER_LEFT_MID             ,                         NUMBER_RIGHT_MID   ,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
                      NUMBER_LEFT_LOWER           ,                         NUMBER_RIGHT_LOWER ,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                               _______, GTSYM    ,  GTDEF,   _______,   GTDEF, _______
                            //`--------------------------'  `--------------------------'
  ),

    [_SYMB] = LAYOUT_wrapper(
  //,-------------------------------------------.                    ,---------------------------------------------
                      SYMBOL_LEFT_UPPER           ,                         SYMBOL_RIGHT_UPPER ,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
                      SYMBOL_LEFT_MID             ,                         SYMBOL_RIGHT_MID   ,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
                      SYMBOL_LEFT_LOWER           ,                         SYMBOL_RIGHT_LOWER ,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                               KC_TRNS ,   STNAV,  GTDEF ,     KC_BSPC,  GTNAV, KC_TRNS
                            //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_wrapper(
  //,-------------------------------------------.                    ,---------------------------------------------
                      NAVIGATION_LEFT_UPPER           ,                         NAVIGATION_RIGHT_UPPER ,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
                      NAVIGATION_LEFT_MID             ,                         NAVIGATION_RIGHT_MID   ,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
                      NAVIGATION_LEFT_LOWER           ,                         NAVIGATION_RIGHT_LOWER ,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                KC_TRNS, GTNUM,  GTDEF  ,     KC_DEL, KC_ENT  , KC_TRNS
                            //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case AW_SWITCH:
        SEND_STRING(SS_DOWN(X_LCTL) "c" SS_UP(X_LCTL) "w");
        return false;
      case CW_LEFT:
        SEND_STRING(SS_DOWN(X_LCTL) "w" SS_UP(X_LCTL) "h");
        return false;
      case CW_RIGHT:
        SEND_STRING(SS_DOWN(X_LCTL) "w" SS_UP(X_LCTL) "l");
        return false;
      case CW_DOWN:
        SEND_STRING(SS_DOWN(X_LCTL) "w" SS_UP(X_LCTL) "j");
        return false;
      case CW_UP:
        SEND_STRING(SS_DOWN(X_LCTL) "w" SS_UP(X_LCTL) "k");
        return false;
    }
  }
  return true;
}

#include "leader_functions/functions.c"
