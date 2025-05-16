#pragma once

/// Left upper row
#define PMT   MT(MOD_LCTL | MOD_LSFT, KC_P)
#define FMT   MT(MOD_LGUI | MOD_LSFT, KC_F)
#define WMT   MT(MOD_LALT | MOD_LSFT, KC_W)

/// Left lower row
#define BMT  MT(MOD_LALT | MOD_LSFT, KC_B)
#define XMT  MT(MOD_LALT, KC_X)
#define CMT  MT(MOD_LGUI, KC_C)
#define VMT  MT(MOD_LCTL, KC_V)
#define ZMT  MT(MOD_RSFT, KC_Z)

/// Right lower row
#define DOTMT   MT(MOD_LALT, KC_DOT)
#define COMMT   MT(MOD_LGUI, KC_COMM)
#define MMT     MT(MOD_RCTL, KC_M)
#define KMT     MT(MOD_RALT, KC_K)

#define SSSFT    OSM(MOD_LSFT)

//#define NTAB  OSL(_NAV)
#define NTAB  OSM(MOD_LCTL)//OSL(STICKY_MDIA)
#define SSYM  LT(_NUMB, KC_SPC)

#define GTDEF TO(_BASE)
#define GTSYM OSL(_SYMB)
#define GTNAV OSL(_NAV)
#define GTNUM OSL(_NUMB)
#define GTSWY OSL(_SWAY)

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

/// Ctrl + Alt + Gui + Left
#define MLEFT LCAG(KC_LEFT)
/// Ctrl + Alt + Gui + Left
#define MRGHT LCAG(KC_RGHT)


#ifdef __APPLE__
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#else
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#endif

// BASE LAYER  ---- COLEMAK
#define BASE_LEFT_UPPER         KC_Q,    WMT ,    FMT ,    PMT ,    KC_G
#define BASE_RIGHT_UPPER        KC_J,    KC_L,    KC_U,    KC_Y,    QK_AREP
#define BASE_LEFT_MID           KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define BASE_RIGHT_MID          KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define BASE_LEFT_LOWER         ZMT ,    XMT ,    CMT ,    VMT ,    BMT
#define BASE_RIGHT_LOWER        KMT ,    MMT ,    COMMT,   DOTMT,   QK_REP


#define SYMBOL_LEFT_UPPER       KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE
#define SYMBOL_RIGHT_UPPER      KC_MINS, KC_DQT,  KC_ASTR, KC_BSLS, KC_QUES
#define SYMBOL_LEFT_MID         KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV
#define SYMBOL_RIGHT_MID        KC_UNDS, KC_QUOT, KC_EQL,  KC_PLUS, KC_SCLN
#define SYMBOL_LEFT_LOWER       KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD
#define SYMBOL_RIGHT_LOWER      KC_AMPR, KC_COLON,KC_LABK, KC_RABK, KC_SLSH


#define NAVIGATION_LEFT_UPPER   KC_TRNS, MLEFT  , MRGHT,   CW_UP  , KC_HOME
#define NAVIGATION_RIGHT_UPPER  APREV,   KC_PGDN, KC_PGUP, ANEXT,   KC_TRNS
#define NAVIGATION_LEFT_MID     COPY   , KC_TRNS, CW_LEFT, CW_DOWN, CW_RIGHT
#define NAVIGATION_RIGHT_MID    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TRNS
#define NAVIGATION_LEFT_LOWER   PASTE  , KC_INS , KC_LGUI, KC_LCTL, BMT
#define NAVIGATION_RIGHT_LOWER  PSPREV,  TABPREV, TABNEXT, PSNEXT,  KC_TRNS


#define NUMBER_LEFT_UPPER       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS
#define NUMBER_RIGHT_UPPER      KC_SPC , KC_7,    KC_8,    KC_9,    KC_UNDS
#define NUMBER_LEFT_MID         KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS
#define NUMBER_RIGHT_MID        KC_COMM, KC_4,    KC_5,    KC_6,    KC_MINS
#define NUMBER_LEFT_LOWER       KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_SPC
#define NUMBER_RIGHT_LOWER      KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT

