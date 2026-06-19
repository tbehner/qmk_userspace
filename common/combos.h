const uint16_t PROGMEM move_workspace[] = { KC_D, KC_S, COMBO_END};

// [Q, W] => Cut
const uint16_t PROGMEM cut_combo[] = { KC_Q, KC_W, COMBO_END};

// [H, N] => Backspace
const uint16_t PROGMEM bspc_combo[] = { KC_H, KC_N, COMBO_END};

// [U, Y] => Delete
const uint16_t PROGMEM del_combo[] = { KC_U, KC_Y, COMBO_END};

// [W, F] => Copy
const uint16_t PROGMEM copy_combo[] = { KC_W, KC_F, COMBO_END};

// [F, P] => Paste
const uint16_t PROGMEM paste_combo[] = { KC_F, KC_P, COMBO_END};

// [W, F, P] => Shift + Ins
const uint16_t PROGMEM insert_combo[] = { KC_W, KC_F, KC_P, COMBO_END};

// [S, T] => Enter
const uint16_t PROGMEM left_ent_combo[] = { KC_T, KC_S, COMBO_END};

// [T, R] => Tab
const uint16_t PROGMEM left_tab_combo[] = { KC_T, KC_R, COMBO_END};

// [L, U] => Esc
const uint16_t PROGMEM esc_combo[] = { KC_L, KC_U, COMBO_END};

// [N, E] => Enter
const uint16_t PROGMEM ent_combo[] = { KC_N, KC_E, COMBO_END};

// [N, I] => Tab
const uint16_t PROGMEM tab_combo[] = { KC_N, KC_I, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(esc_combo, KC_ESC),
  COMBO(ent_combo, KC_ENT),
  COMBO(left_ent_combo, KC_ENT),
  COMBO(tab_combo, KC_TAB),
  COMBO(copy_combo, LCTL(KC_C)),
  COMBO(paste_combo, LCTL(KC_V)),
  COMBO(insert_combo, LSFT(KC_INS)),
  COMBO(move_workspace, LCTL(LGUI(KC_RGHT))),
  COMBO(cut_combo, LCTL(KC_X)),
  COMBO(bspc_combo, KC_BSPC),
  COMBO(del_combo, KC_DEL),
};
