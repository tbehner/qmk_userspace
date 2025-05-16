const uint16_t PROGMEM esc_combo[] = { KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM ent_combo[] = { KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM tab_combo[] = { KC_N, KC_I, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(esc_combo, KC_ESC),
  COMBO(ent_combo, KC_ENT),
  COMBO(tab_combo, KC_TAB),
};


