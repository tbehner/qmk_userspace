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


#define F10ALT MT(MOD_LALT, KC_F10)
#define F11GUI MT(MOD_LGUI, KC_F11)
#define F12CTL MT(MOD_LCTL, KC_F12)

const uint16_t PROGMEM esc_combo[] = { KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM ent_combo[] = { KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM tab_combo[] = { KC_N, KC_I, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(esc_combo, KC_ESC),
  COMBO(ent_combo, KC_ENT),
  COMBO(tab_combo, KC_TAB),
};

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   Q  |   W  |   E  |   R  |   T  | WinL |                    | WinR |   Y  |   U  |   I  |   O  |   P  |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   A  |   S  |   D  |   F  |   G  | WinD |                    | WinU |   H  |   J  |   K  |   L  |   ;  |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   Z  |   X  |   C  |   V  |   B  | Space|                    | Enter|   N  |   M  |   ,  |   .  |   /  |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_BASE] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______, _______, \
    _______,                   BASE_LEFT_UPPER,                    _______,                              _______,                      BASE_RIGHT_UPPER,          _______, \
    COPY   ,                   BASE_LEFT_MID,                      _______,                              _______,                      BASE_RIGHT_MID,            _______, \
    PASTE  ,                   BASE_LEFT_LOWER,                    _______,                              _______,                      BASE_RIGHT_LOWER,          _______, \
    _______, _______, _______, QK_LEAD,          GTSYM  , NTAB   , _______ ,           _______ , SSSFT ,  SSYM ,           QK_LEAD , _______, _______,_______  \
  ),


  /* Numbers
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC |   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
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


void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_N)) {
        // Leader, n => Enter
        SEND_STRING(SS_TAP(X_ENT));
    } else if (leader_sequence_one_key(KC_E)) {
        // Leader, e => Esc
        SEND_STRING(SS_TAP(X_ESC));
    } else if (leader_sequence_two_keys(KC_W, KC_S)) {
        // Leader, w, s => WezTerm Split vertical
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_DELAY(100) "|" SS_UP(X_LCTL) SS_UP(X_LALT) SS_UP(X_LSFT));
    } else if (leader_sequence_two_keys(KC_W, KC_H)) {
        // Leader, w, s => WezTerm Split horizontal
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_DELAY(100) "_" SS_UP(X_LCTL) SS_UP(X_LALT) SS_UP(X_LSFT));
    }
}
