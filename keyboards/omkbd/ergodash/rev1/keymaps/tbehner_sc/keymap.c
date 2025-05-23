#include QMK_KEYBOARD_H


enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMB,
    _SYMB,
    _NAV
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  CW_LEFT,
  CW_RIGHT,
  CW_UP,
  CW_DOWN,
  AW_SWITCH,
};

#include "common/common_keys.h"
#include "common/combos.h"

#define EISU LALT(KC_GRV)
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |Pscree|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_BASE] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______, _______, \
    _______,                   BASE_LEFT_UPPER,                    _______,                              _______,                      BASE_RIGHT_UPPER,          _______, \
    COPY   ,                   BASE_LEFT_MID,                      _______,                              _______,                      BASE_RIGHT_MID,            _______, \
    PASTE  ,                   BASE_LEFT_LOWER,                    _______,                              _______,                      BASE_RIGHT_LOWER,          _______, \
    _______, _______, _______, QK_LEAD,          GTSYM  , NTAB   , _______ ,           _______ , SSSFT ,  SSYM ,           QK_LEAD , _______, _______,_______  \
  ),

  [_NUMB] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______,                 NUMBER_LEFT_UPPER,          _______,                       _______,                    NUMBER_RIGHT_UPPER,       _______, \
    _______,                 NUMBER_LEFT_MID,            _______,                       _______,                    NUMBER_RIGHT_MID,         _______, \
    _______,                 NUMBER_LEFT_LOWER,          _______,                       _______,                    NUMBER_RIGHT_LOWER,       _______, \
    _______, _______, _______, _______,          GTSYM  ,GTDEF  ,_______,       _______,_______, GTDEF  ,          _______, _______, _______, _______  \
  ),


  /* Symbols:
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_SYMB] = LAYOUT_wrapper(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_TILD,                  SYMBOL_LEFT_UPPER,          _______,                        _______,                   SYMBOL_RIGHT_UPPER,        _______, \
    KC_LCTL,                  SYMBOL_LEFT_MID,            _______,                        KC_BSPC,                   SYMBOL_RIGHT_MID,          _______, \
    KC_LSFT,                  SYMBOL_LEFT_LOWER,          _______,                        KC_DEL ,                   SYMBOL_RIGHT_LOWER,        _______, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_ASTR,          STNAV  , GTDEF  , _______,       _______,KC_BSPC, GTNAV  ,          _______, _______, _______, _______ \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      | PgUp |Insert|      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      | PgDn |      |      | MsWUp|                    |      |   H  |   J  |   K  |   L  |  ;   |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | MsWDn|                    |      | WinP | TabP | TabN | WinN |  ,   |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_NAV] = LAYOUT_wrapper(
    KC_F11 , KC_F1,   KC_F2  , KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8  ,  KC_F9,   KC_F10,  KC_F12,  \
    _______,                   NAVIGATION_LEFT_UPPER,     KC_MS_WH_UP,                    _______,                   NAVIGATION_RIGHT_UPPER,     _______, \
    _______,                   NAVIGATION_LEFT_MID,       KC_MS_WH_DOWN,                  _______,                   NAVIGATION_RIGHT_MID,       _______, \
    _______,                   NAVIGATION_LEFT_LOWER,      _______,                        KC_DEL,                   NAVIGATION_RIGHT_LOWER,     _______, \
    _______, _______, _______, _______,          GTNUM   , GTDEF  ,_______,        KC_DEL, KC_DEL, KC_ENT,           _______,  _______, _______, _______   \
  ),
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
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
  return true;
}

#include "leader_functions/functions.c"
