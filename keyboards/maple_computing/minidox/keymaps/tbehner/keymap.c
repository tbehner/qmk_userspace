#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _SYMB,
    _NUMB,
    _NAV
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  SYMB,
  NUMB,
  NAV,
  CW_LEFT,
  CW_RIGHT,
  CW_UP,
  CW_DOWN,
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

/// Left lower row
#define XMT  MT(MOD_LALT, KC_X)
#define CMT  MT(MOD_LGUI, KC_C)
#define VMT  MT(MOD_LCTL, KC_V)
#define ZMT  MT(MOD_RALT, KC_Z)

/// Right lower row
#define DOTMT   MT(MOD_LALT, KC_DOT)
#define COMMT   MT(MOD_LGUI, KC_COMM)
#define MMT     MT(MOD_RCTL, KC_M)
#define SLMT    MT(MOD_RALT, KC_SLASH)

#define SENT    OSM(MOD_LSFT)

//#define NTAB  OSL(_NAV)
#define NTAB  OSM(MOD_LCTL)//OSL(STICKY_MDIA)
#define SSYM  LT(_NUMB, KC_SPC)

#define GTDEF TO(_BASE)
#define GTSYM OSL(_SYMB)
#define GTNAV OSL(_NAV)
#define GTNUM OSL(_NUMB)

#define STNAV TO(_NAV)
#define STNUM TO(_NUMB)

#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)

#define TABNEXT LCTL(KC_TAB)
#define TABPREV RCS(KC_TAB)

#define PSNEXT  LGUI(KC_TAB)
#define PSPREV  LSG(KC_TAB)
#define ANEXT LALT(KC_TAB)
#define APREV LSA(KC_TAB)

#define MLEFT LCAG(KC_LEFT)
#define MRGHT LCAG(KC_RGHT)



const uint16_t PROGMEM esc_combo[] = { KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM tab_combo[] = { KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM ent_combo[] = { KC_U, KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(esc_combo, KC_ESC),
  COMBO(ent_combo, KC_ENT),
  COMBO(tab_combo, KC_TAB),
};


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
[_BASE] = LAYOUT_split_3x5_3(
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
  ZMT ,    XMT ,    CMT ,    VMT ,    KC_B,         KC_K,    MMT ,    COMMT,   DOTMT,   SLMT,
                    KC_TAB , GTSYM ,  NTAB,         SENT,    SSYM,    KC_ESC
),

[_SYMB] = LAYOUT_split_3x5_3(
  // left hand
  KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                    KC_MINS, KC_DQT,  KC_ASTR, KC_BSLS, KC_QUES,
  KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                     KC_UNDS, KC_QUOT, KC_EQL,  KC_PLUS, KC_ENT ,
  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                    KC_AMPR, KC_COLON,KC_LABK, KC_RABK, KC_ENT ,
                    STNUM  , STNAV  , GTDEF  ,                    KC_BSPC, GTNAV,   KC_TRNS
),

[_NAV] = LAYOUT_split_3x5_3(
  // left hand
  KC_TRNS, MLEFT  , MRGHT,   CW_UP  , KC_HOME,                    APREV,   KC_TRNS, KC_TRNS, ANEXT,   KC_TRNS,
  COPY   , KC_TRNS, CW_LEFT, CW_DOWN, CW_RIGHT,                   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TRNS,
  PASTE  , KC_INS , KC_PGUP, KC_PGDN, KC_END ,                    PSPREV,  TABPREV, TABNEXT, PSNEXT,  KC_TRNS,
                    KC_TRNS, GTNUM  , GTDEF  ,                    KC_DEL , KC_ENT, KC_TRNS
),

[_NUMB] = LAYOUT_split_3x5_3(
  // left hand
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS,           KC_SPC , KC_7,    KC_8,    KC_9,    KC_UNDS,
  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,           KC_COMM, KC_4,    KC_5,    KC_6,    KC_MINS,
  KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_SPC ,           KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,
                   KC_TRNS,  GTSYM,   GTDEF  ,           KC_TRNS, GTDEF,   KC_TRNS
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
