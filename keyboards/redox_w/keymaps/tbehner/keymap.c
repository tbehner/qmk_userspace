#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _NUMB 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  NUMB,
  ONESHOT,
  CW_LEFT,
  CW_RIGHT,
  CW_UP,
  CW_DOWN,
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_NUMB, KC_END)
#define KC_ADPU LT(_NUMB, KC_PGUP)

#define KC_MESC LT(_NAV, KC_ESC)
#define KC_SBSP LT(_SYMB, KC_BSPC)
#define KC_AENT LT(_NUMB, KC_ENT)

#define KC_SYMB TT(_SYMB)
#define KC_ADJ  TT(_NUMB)

// _QWERTY ->
// _SYMB -> Symbol Layer
// _NAV -> Navigation Layer
// _NUMB -> Number / Function Layer
// _SYMB -> Symbol Layer

#define PRAISESC LT(_SYMB, KC_ESC)
#define PNUMBENT LT(_NUMB, KC_ENT)
#define PSYMBSP  LT(_SYMB, KC_BSPC)

#define GTDEF TO(_QWERTY)
#define GTSYM OSL(_SYMB)
#define GTNAV OSL(_NAV)
#define GTNUM OSL(_NUMB)

#define SENT    OSM(MOD_LSFT)
#define SSYM  LT(_NUMB, KC_SPC)

#define NTAB      OSL(_NAV)
#define NUMB_ENT  LT(_NUMB,KC_ENT)
#define SYMB_BS   LT(_SYMB,KC_BSPC)
#define NUMB_BS   LT(_NUMB,KC_BSPC)
#define MEDIA_ESC LT(_NAV,KC_ESC)

#define NMBRS MO(_NUMB)
#define RAISE MO(_NAV)
#define LOWER MO(_SYMB)

#define TABNEXT LCTL(KC_TAB)
#define TABPREV RCS(KC_TAB)
#define PSNEXT  LGUI(KC_TAB)
#define PSPREV  LSG(KC_TAB)

#define NSYM LT(SYMB, KC_N)
#define TSYM LT(SYMB, KC_T)

#define SNAV LT(NAV, KC_S)
#define ENAV LT(NAV, KC_E)

/// Left lower row
#define XMT  MT(MOD_LALT, KC_X)
#define CMT  MT(MOD_LGUI, KC_C)
#define VMT  MT(MOD_LCTL, KC_V)
#define ZMT  MT(MOD_RALT, KC_Z)

#define SFTGUI MT(MOD_LGUI | MOD_LSFT, KC_SPC)  

/// Right lower row
#define DOTMT   MT(MOD_LALT, KC_DOT)
#define COMMT   MT(MOD_LGUI, KC_COMM)
#define MMT     MT(MOD_RCTL, KC_M)
#define SLMT    MT(MOD_RALT, KC_SLASH)

#define STNAV TO(_NAV)
#define STNUM TO(_NUMB)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)

#define MLEFT LCAG(KC_LEFT)
#define MRGHT LCAG(KC_RGHT)

#define PSNEXT  LGUI(KC_TAB)
#define PSPREV  LSG(KC_TAB)
#define ANEXT LALT(KC_TAB)
#define APREV LSA(KC_TAB)

const uint16_t PROGMEM esc_combo[] = { KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM tab_combo[] = { KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM enter_combo[] = { KC_U, KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(esc_combo, KC_ESC),
  COMBO(tab_combo, KC_TAB),
  COMBO(enter_combo, KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,CW_LEFT ,                          CW_RIGHT,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_D    ,CW_DOWN ,                          CW_UP   ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,ZMT     ,XMT     ,CMT     ,VMT     ,KC_B    ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,KC_K    ,MMT     ,COMMT   ,DOTMT   ,SLMT    ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     GTSYM   ,    NTAB    ,KC_TAB  ,        KC_ESC  ,SENT    ,    SSYM    ,     _______ ,_______ ,_______ ,KC_RALT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
                     ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,_______ ,                          _______ ,KC_MINS ,KC_DQT	,KC_ASTR ,KC_BSLS ,KC_QUES ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HASH ,KC_DLR  ,KC_LPRN ,KC_RPRN ,KC_GRV  ,_______ ,                          _______ ,KC_UNDS ,KC_QUOT ,KC_EQL  ,KC_PLUS ,KC_SCLN ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PERC ,KC_CIRC ,KC_LBRC ,KC_RBRC ,KC_TILD ,_______ ,_______ ,        _______ ,_______ ,KC_AMPR ,KC_COLON,KC_LABK ,KC_RABK ,KC_SLSH ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     GTNUM   ,    GTDEF   ,_______ ,        _______ ,KC_BSPC ,    STNAV   ,     _______ ,_______ ,_______ ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,MLEFT   ,MRGHT   ,CW_UP   ,KC_HOME ,_______ ,                          _______ ,APREV   ,_______ ,_______ ,ANEXT   ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,COPY    ,_______ ,CW_LEFT ,CW_DOWN ,CW_RIGHT,_______ ,                          _______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,PASTE   ,_______ ,KC_PGUP ,KC_PGDN ,KC_END  ,_______ ,_______ ,        _______ ,_______ ,PSPREV  ,TABPREV ,TABNEXT ,PSNEXT  ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        KC_DEL  ,KC_DEL ,     KC_ENT   ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NUMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,_______ ,_______ ,                          _______ ,KC_COLON,KC_7    ,KC_8    ,KC_9    ,KC_UNDS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,SFTGUI  ,_______ ,                          _______ ,KC_COMM ,KC_4    ,KC_5    ,KC_6    ,KC_MINS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,KC_SPC  ,_______ ,_______ ,        _______ ,_______ ,KC_0    ,KC_1    ,KC_2    ,KC_3    ,KC_DOT  ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     GTSYM   ,    GTDEF   ,_______ ,        _______ ,GTDEF   ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _QWERTY:
            set_led_off;
            break;
        case _SYMB:
            set_led_green;
            break;
        case _NAV:
            set_led_blue;
            break;
        case _NUMB:
            set_led_red;
            break;
        default:
            break;
    }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
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
