#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _NUMBERS,
  _LOWER,  // symbols
  _RAISE,  // navigation
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  CW_LEFT,
  CW_RIGHT,
  CW_UP,
  CW_DOWN,
  AW_SWITCH,
};


//#define ATAB      OSL(_RAISE)
#define ATAB OSM(MOD_LCTL)

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define TABNEXT LCTL(KC_TAB)
#define TABPREV RCS(KC_TAB)
#define PSNEXT  LGUI(KC_TAB)
#define PSPREV  LSG(KC_TAB)

/// Left lower row
#define XMT  MT(MOD_LALT, KC_X)
#define BMT  MT(MOD_LALT | MOD_LSFT, KC_B)
#define CMT  MT(MOD_LGUI, KC_C)
#define VMT  MT(MOD_LCTL, KC_V)
#define ZMT  MT(MOD_RALT, KC_Z)

/// Right lower row
#define SLMT    MT(MOD_RALT, KC_SLASH)
#define DOTMT   MT(MOD_LALT, KC_DOT)
#define COMMT   MT(MOD_LGUI, KC_COMM)
#define MMT     MT(MOD_RCTL, KC_M)

#define F10ALT MT(MOD_LALT, KC_F10)
#define F11GUI MT(MOD_LGUI, KC_F11)
#define F12CTL MT(MOD_LCTL, KC_F12)

#define TODEF  TO(_QWERTY)
#define TOSYM  OSL(_LOWER)
#define TONUM  OSL(_NUMBERS)
#define TONAV  OSL(_RAISE)

#define STNAV TO(_RAISE)
#define STNUM TO(_NUMBERS)

#define SENT    OSM(MOD_LSFT)
#define SSYM    LT(_NUMBERS, KC_SPC)

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

#ifdef __APPLE__
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#else
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#endif

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
  [_QWERTY] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______,                              _______, KC_J,    KC_L,    KC_U,    KC_Y,    QK_AREP, _______, \
    COPY   , KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    _______,                              _______, KC_H,    KC_N,    KC_E ,   KC_I ,   KC_O,    _______, \
    PASTE  , ZMT,     XMT ,    CMT ,    VMT ,    BMT ,    KC_ESC ,                              KC_ESC , KC_K,    MMT ,    COMMT,   DOTMT,   QK_REP , _______, \
    _______, _______, _______, _______,          QK_LEAD, TOSYM  ,  ATAB   ,          SENT   ,  SSYM   , QK_LEAD,        _______, _______, _______, _______  \
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
  [_NUMBERS] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,_______,                       _______, KC_SPC,  KC_7,    KC_8,    KC_9,    KC_UNDS, _______, \
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,_______,                       _______, KC_COMM, KC_4,    KC_5,    KC_6,    KC_MINS, _______, \
    _______, KC_F9,   F10ALT,  F11GUI,  F12CTL,  KC_SPC ,_______,                       _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  _______, \
    _______, _______, _______, _______,          _______,TOSYM  ,TODEF  ,       _______,TODEF  , _______ ,          _______, _______, _______, _______  \
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
  [_LOWER] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,                        KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_TILD, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,                        KC_TRNS, KC_MINS, KC_DQT,  KC_ASTR, KC_BSLS, KC_QUES, KC_TRNS, \
    KC_LCTL, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_TRNS,                        KC_BSPC, KC_UNDS, KC_QUOT, KC_EQL,  KC_PLUS, KC_SCLN, KC_TRNS, \
    KC_LSFT, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,                        KC_DEL , KC_AMPR, KC_COLON,KC_LABK, KC_RABK, KC_SLSH, KC_TRNS, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_ASTR,          KC_TRNS, STNAV  , TODEF,        KC_BSPC, TONAV , KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
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
  [_RAISE] = LAYOUT(
    KC_F11 , KC_F1,   KC_F2  , KC_F3,   KC_F4,   KC_F5,   KC_TRNS,                        KC_TRNS, KC_F6,   KC_F7,   KC_F8  ,  KC_F9,   KC_F10,  KC_F12,  \
    KC_TRNS, CUT    , KC_TRNS, KC_TRNS, CW_UP  , KC_TRNS, KC_MS_WH_UP,                    KC_TRNS, KC_TRNS, KC_PGDN, KC_PGUP,  KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, COPY   , KC_TRNS, CW_LEFT, CW_DOWN, CW_RIGHT,KC_MS_WH_DOWN,                  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP  ,  KC_RGHT, KC_ENT , KC_TRNS, \
    KC_TRNS, KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL, KC_TRNS, KC_TRNS,                        KC_DEL , PSPREV,  TABPREV, TABNEXT,  PSNEXT,  KC_COMM, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS , TONUM  ,TODEF ,        KC_DEL ,KC_ENT , KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS   \
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
