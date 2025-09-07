const uint16_t PROGMEM esc_combo[] = { KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM ent_combo[] = { KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM tab_combo[] = { KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM copy_combo[] = { KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM paste_combo[] = { KC_T, KC_R, COMBO_END};
const uint16_t PROGMEM insert_combo[] = { KC_T, KC_S, KC_R, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(esc_combo, KC_ESC),
  COMBO(ent_combo, KC_ENT),
  COMBO(tab_combo, KC_TAB),
  COMBO(copy_combo, LCTL(KC_C)),
  COMBO(paste_combo, LCTL(KC_V)),
  COMBO(insert_combo, LSFT(KC_INS)),
};


