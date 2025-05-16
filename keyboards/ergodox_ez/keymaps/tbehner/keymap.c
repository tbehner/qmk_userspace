#include QMK_KEYBOARD_H
#include "version.h"
#include "common/common_keys.h"

enum layers {
    _BASE, // default layer
    _SYMB, // Symbols
    _NAV, // navigation Layer
    _NUMB, // Number Layer
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  SYMB,
  NUMB,
  NAV,
  RGB_SLD,
  CW_LEFT,
  CW_RIGHT,
  CW_UP,
  CW_DOWN,
  AW_SWITCH,
  TRM_INS,
};


// UY -> Ent
const uint16_t PROGMEM enter_combo[] = { KC_U, KC_Y, COMBO_END};
// m, -> Ent
const uint16_t PROGMEM lower_enter_combo[] = { KC_N, KC_E, COMBO_END};
// LU -> Esc
const uint16_t PROGMEM esc_combo[] = { KC_L, KC_U, COMBO_END};
// NI -> Tab
const uint16_t PROGMEM tab_combo[] = { KC_N, KC_I, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(enter_combo, KC_ENT),
  COMBO(lower_enter_combo, KC_ENT),
  COMBO(tab_combo, KC_TAB),
  COMBO(esc_combo, KC_ESC),
};

#define LAYOUT_wrapper(...) LAYOUT_ergodox_pretty(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |   +  |           |  =   |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | WinL |           | WinR |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |        |
 * |--------+------+------+------+------+------| WinDn|           | WinUp|------+------+------+------+------+--------|
 * |  Shift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |        |
 * `--------+------+------+------+------+-------------'           `------------+-----+------+------+------+--------'
 *   |      | Shift| Tab | LGui |   Alt |                                       |Enter|Space | RAlt | Shift |       |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  L1  |       | Del  |        |      |
 *                                 | LGui | Alt  |------|       |------| Enter  |Space |
 *                                 |      |      |Esc/L1|       | Back |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_BASE] = LAYOUT_wrapper(
  KC_NO,        KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_PLUS,              KC_EQL,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_NO,
  KC_NO,                            BASE_LEFT_UPPER,                   CW_LEFT,              CW_RIGHT,                       BASE_RIGHT_UPPER,            KC_NO,
  KC_NO,                            BASE_LEFT_MID,                                                                           BASE_RIGHT_MID,            KC_NO,
  KC_NO,                            BASE_LEFT_LOWER,                   CW_DOWN,              CW_UP,                          BASE_RIGHT_LOWER,            KC_NO,
  KC_NO,        KC_LSFT,     KC_TAB,        KC_LGUI, QK_LEAD,                                              QK_LEAD, KC_SPC,  KC_RALT, KC_RSFT,  KC_NO,
                                                             KC_HOME, KC_END  ,              KC_PGUP, KC_PGDN,
                                                                      KC_TAB  ,              KC_ESC,
                                                     GTSYM, NTAB,     KC_TAB  ,              KC_ESC, SSSFT , SSYM
),


/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   -  |   "  |   *  |   \  |   ?  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------|   _  |   '  |   =  |   +  | Enter|        |
 * |---------+------+------+------+------+------|      |           |   "  |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   :  |   <  |   >  | Enter|        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_SYMB] = LAYOUT_wrapper(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS,                  SYMBOL_LEFT_UPPER,          KC_TRNS,     KC_TRNS,                   SYMBOL_RIGHT_UPPER,        KC_F12,
  KC_TRNS,                  SYMBOL_LEFT_MID,                                                    SYMBOL_RIGHT_MID,          KC_TRNS,
  KC_TRNS,                  SYMBOL_LEFT_LOWER,          KC_TRNS,     KC_DQT ,                   SYMBOL_RIGHT_LOWER,        KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, STNUM  ,                                         KC_TRNS, KC_TRNS, KC_DOT,  KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      STNAV  ,  GTDEF  ,KC_TRNS,     KC_TRNS, KC_BSPC, GTNAV
),

/* Keymap 2: Media and VIM-like keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | PgUp |Insert|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | PgDn |      |      |------|           |------| Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_NAV] = LAYOUT_wrapper(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,                   NAVIGATION_LEFT_UPPER,    KC_TRNS,          KC_TRNS,                    NAVIGATION_RIGHT_UPPER,    KC_TRNS,
  KC_TRNS,                   NAVIGATION_LEFT_MID,                                                    NAVIGATION_RIGHT_MID,      KC_TRNS,
  KC_TRNS,                   NAVIGATION_LEFT_LOWER,    KC_TRNS,          KC_TRNS,                    NAVIGATION_RIGHT_LOWER,    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
                                                        KC_TRNS,          KC_TRNS,
                                      GTNUM,   GTDEF  , KC_TRNS,          KC_TRNS,  KC_DEL , KC_ENT
),

/* Keymap 3: Numbers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |           |      |   =  |   7  |   8  |   9  |   _  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |------|           |------|   +  |   4  |   5  |   6  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F9  |  F10 |  F11 |  F12 |      |      |           |      |   0  |   1  |   2  |   3  |   .  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_NUMB] = LAYOUT_wrapper(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,                  NUMBER_LEFT_UPPER,          KC_TRNS,     KC_TRNS,                   NUMBER_RIGHT_UPPER,        KC_TRNS,
  KC_TRNS,                  NUMBER_LEFT_MID,                                                    NUMBER_RIGHT_MID,          KC_TRNS,
  KC_TRNS,                  NUMBER_LEFT_LOWER,          KC_TRNS,     KC_TRNS,                   NUMBER_RIGHT_LOWER,        KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      GTSYM,   GTDEF  , KC_TRNS,     KC_TRNS, KC_TRNS, GTDEF
),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      case TRM_INS: // Alacritty enter insert mode
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) " " SS_UP(X_LCTL) SS_UP(X_LSFT));
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

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

#include "leader_functions/functions.c"
