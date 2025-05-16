#include QMK_KEYBOARD_H

#include "common/sway_layer_defs.h"
#include "common/common_keys.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _SYMB,
    _NUMB,
    _NAV,
    _SWAY
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  SYMB,
  NUMB,
  NAV,
  SWAY,
  CW_LEFT,
  CW_RIGHT,
  CW_UP,
  CW_DOWN,
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

/// new home row modifiers
///
#define TB_Q KC_Q, WMT
#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

#include "common/combos.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Ctrl | LOWER|      |    |      | RAISE| Shift|
 *                  `-------------| Space|    |BckSpc|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */

[_BASE] = LAYOUT_wrapper(
        BASE_LEFT_UPPER,                        BASE_RIGHT_UPPER,
        BASE_LEFT_MID  ,                        BASE_RIGHT_MID  ,
        BASE_LEFT_LOWER,                        BASE_RIGHT_LOWER,
        GTSWY, GTSYM ,  NTAB,         SSSFT,    SSYM,    QK_LEAD
),

[_SYMB] = LAYOUT_wrapper(
  // left hand
        SYMBOL_LEFT_UPPER,                                        SYMBOL_RIGHT_UPPER,
        SYMBOL_LEFT_MID,                                          SYMBOL_RIGHT_MID,
        SYMBOL_LEFT_LOWER,                                        SYMBOL_RIGHT_LOWER,
        STNUM  , STNAV  , GTDEF  ,                    KC_BSPC, GTNAV,   KC_TRNS
),

[_NAV] = LAYOUT_wrapper(
  // left hand
                      NAVIGATION_LEFT_UPPER,                     NAVIGATION_RIGHT_UPPER,
                      NAVIGATION_LEFT_MID,                       NAVIGATION_RIGHT_MID,
                      NAVIGATION_LEFT_LOWER,                     NAVIGATION_RIGHT_LOWER,
                    KC_TRNS, GTNUM  , GTDEF  ,                    KC_DEL , KC_ENT, KC_TRNS
),

[_NUMB] = LAYOUT_wrapper(
  // left hand
                NUMBER_LEFT_UPPER,                            NUMBER_RIGHT_UPPER,
                NUMBER_LEFT_MID  ,                            NUMBER_RIGHT_MID  ,
                NUMBER_LEFT_LOWER,                            NUMBER_RIGHT_LOWER,
                   KC_TRNS,  GTSYM,   GTDEF  ,           KC_TRNS, GTDEF,   KC_TRNS
),

[_SWAY] = LAYOUT_split_3x5_3(
  // left hand
  MWS1 ,  MWS2,     MWS3,    MWS4,    MWS5,            MWS6,   MWS7,  MWS8,  MWS9,    MWS10,
  MWLEFT, MWDOWN,   MWUP,    MWRIGHT, KC_NO,           FLEFT,  FDOWN, FUP,   FRIGHT,  KC_NO,
  SSHOR,  SSVER,   SSTAB,    SSSTA,   SSTSP,           SPARE,  SSFUL, KC_NO, KC_NO,   KC_NO,
                   KC_TRNS,  GTDEF,   GTDEF,           SSSFT,  MSLEFT, MSRIGHT

),
};

/* void persistant_default_layer_set(uint16_t default_layer) { */
/*   eeconfig_update_default_layer(default_layer); */
/*   default_layer_set(default_layer); */
/* } */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(record->event.pressed){
    switch (keycode) {
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
