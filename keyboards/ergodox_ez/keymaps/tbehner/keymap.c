#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE, // default layer
    STICKY_SYMB, // Symbols
    STICKY_MDIA, // navigation Layer
    STICKY_NUMB, // Number Layer
    COMMAND,     // Command layer
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD,
  CW_LEFT,
  CW_RIGHT,
  CW_UP,
  CW_DOWN,
  AW_SWITCH,
  TRM_INS,
};

#define CTL_SPC MT(MOD_RCTL, KC_SPC)
#define NUMB_ENT LT(NUMB,KC_ENT)
#define SYMB_BS LT(SYMB,KC_BSPC)
#define MEDIA_ESC LT(MDIA,KC_ESC)

#define ATAB  MT(MOD_LALT, KC_TAB)

#define ZSHFT MT(MOD_LSFT, KC_Z)
#define SSHFT MT(MOD_LSFT, KC_SLSH)

#define TABNEXT LCTL(KC_TAB)
#define TABPREV RCS(KC_TAB)

#define PSNEXT  LGUI(KC_TAB)
#define PSPREV  LSG(KC_TAB)
#define ANEXT LALT(KC_TAB)
#define APREV LSA(KC_TAB)

#define MLEFT LCAG(KC_LEFT)
#define MRGHT LCAG(KC_RGHT)

#define NSYM KC_N
#define TSYM KC_T

#define SNAV KC_S
#define ENAV KC_E

#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define CTLC LCTL(KC_C)
#define CTLX LCTL(KC_X)
#define CTLW LCTL(KC_W)
#define LSAB LSA(KC_B)
#define LSAK LSA(KC_K)

#define SCLB

/// new home row modifiers and thumb cluster
///
/// Left upper row
#define PMT   MT(MOD_LCTL | MOD_LSFT, KC_P)
#define FMT   MT(MOD_LGUI | MOD_LSFT, KC_F)
#define WMT   MT(MOD_LALT | MOD_LSFT, KC_W)

/// Left home row
#define AMT   KC_A
#define RMT   KC_R
#define SMT   KC_S
#define TMT   KC_T

/// Right home row
#define OMT   KC_O
#define IMT   KC_I
#define EMT   KC_E
#define NMT   KC_N

/// Left lower row
#define BMT  MT(MOD_LALT | MOD_LSFT, KC_B)
#define CMT  MT(MOD_LGUI, KC_C)
#define VMT  MT(MOD_LCTL, KC_V)
#define XMT  MT(MOD_LALT, KC_X)
#define ZMT  MT(MOD_LSFT, KC_Z)

/// Right lower row
#define DOTMT   MT(MOD_LALT, KC_DOT)
#define COMMT   MT(MOD_LGUI, KC_COMM)
#define MMT     MT(MOD_RCTL, KC_M)
#define KMT    MT(MOD_RALT, KC_K)

#define SENT    OSM(MOD_LSFT)

#define NTAB  OSM(MOD_LCTL)//OSL(STICKY_MDIA)
#define SSYM  LT(STICKY_NUMB, KC_SPC)

#define GTDEF TO(BASE)
#define GTSYM OSL(STICKY_SYMB)
#define GTNAV OSL(STICKY_MDIA)
#define GTNUM OSL(STICKY_NUMB)
#define GTCOM OSL(COMMAND)

#define STNAV TO(STICKY_MDIA)
#define STNUM TO(STICKY_NUMB)

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
[BASE] = LAYOUT_ergodox_pretty(
  KC_NO,        KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_PLUS,              KC_EQL,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_NO,
  KC_NO,        KC_Q,        WMT  ,         FMT  ,   KC_P,    KC_G,    CW_LEFT,              CW_RIGHT,     KC_J,    KC_L,    KC_U ,   KC_Y ,    QK_AREP,   KC_NO,
  KC_NO,        AMT  ,       RMT  ,         SMT  ,   TMT ,    KC_D,                                        KC_H,    NMT ,    EMT ,    IMT  ,    OMT  ,     KC_NO,
  KC_NO,        ZMT  ,       XMT  ,         CMT  ,   VMT ,    BMT,     CW_DOWN,              CW_UP,        KMT ,    MMT ,    COMMT,   DOTMT,    QK_REP ,    KC_NO,
  KC_NO,        KC_LSFT,     KC_TAB,        KC_LGUI, QK_LEAD,                                              QK_LEAD, KC_SPC,  KC_RALT, KC_RSFT,  KC_NO,
                                                             KC_HOME, KC_END  ,              KC_PGUP, KC_PGDN,
                                                                      KC_TAB  ,              KC_ESC,
                                                     GTSYM, NTAB,     KC_TAB  ,              KC_ESC, SENT , SSYM
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
[STICKY_SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_MINS, KC_DQT,  KC_ASTR, KC_BSLS, KC_QUES, KC_F12,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                        KC_UNDS, KC_QUOT, KC_EQL,  KC_PLUS, KC_SCLN, KC_TRNS,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,     KC_DQT , KC_AMPR, KC_COLON,KC_LABK, KC_RABK, KC_SLSH, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_DOT,  KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      STNAV   , GTDEF  ,KC_TRNS,     KC_TRNS, KC_BSPC, GTNAV
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
[STICKY_MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, MLEFT  , MRGHT,   CW_UP  , KC_TRNS, KC_TRNS,          KC_TRNS, APREV,   KC_PGDN, KC_PGUP, ANEXT,   KC_INS , KC_TRNS,
  KC_TRNS, COPY   , KC_TRNS, CW_LEFT, CW_DOWN, CW_RIGHT,                           KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, PASTE  , CTLX   , CTLC   , CTLW   , KC_TRNS, KC_TRNS,          KC_TRNS, PSPREV,  TABPREV, TABNEXT, PSNEXT,  KC_TRNS, KC_TRNS,
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
[STICKY_NUMB] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS, KC_TRNS,     KC_TRNS, KC_SPC  ,KC_7,    KC_8,    KC_9,    KC_UNDS, KC_TRNS,
  KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,                       KC_COMM, KC_4,    KC_5,    KC_6,    KC_MINS, KC_TRNS,
  KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_SPC , KC_TRNS,     KC_TRNS, KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      GTSYM,   GTDEF  , KC_TRNS,     KC_TRNS, KC_TRNS, GTDEF
),

/* Keymap 4: Commands
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
[COMMAND] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, TRM_INS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, GTDEF  , KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
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
