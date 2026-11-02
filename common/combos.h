/*
 * Combo overview (Colemak)
 *
 *   ┌───┬───┬───┬───┬───┐                 ┌───┬───┬───┬───┬───┐
 *   │ Q │ W │ F │ P │ G │                 │ J │ L │ U │ Y │ ; │
 *   └───┴───┴───┴───┴───┘                 └───┴───┴───┴───┴───┘
 *    └─┘ └─────┘   └─┘                         └─────┘ └─────┘
 *    Cut  Zellij   Nav                           Esc
 *        └───────────┘                                  Zellij
 *           Shift+Ins
 *
 *   ┌───┬───┬───┬───┬───┐                 ┌───┬───┬───┬───┬───┐
 *   │ A │ R │ S │ T │ D │                 │ H │ N │ E │ I │ O │
 *   └───┴───┴───┴───┴───┘                 └───┴───┴───┴───┴───┘
 *    └─────┘                               └─┘
 *     Copy                                 Bsp
 *    └────*────┘
 *       Paste
 *         └─┘   └─┘                            └─────┘
 *        Lead   Ent                              Ent
 *         └──*──┘   └──*──┘                         └─────┘
 *             Tab    WsMov                           Lead
 *                                                        └─────┘
 *                                                         Del
 *                                                └────*────┘
 *                                                     Tab
 *
 *   * = non-adjacent pair
 *
 *   [F, T] (cross-row) => toggle the nav layer on and off
 *   [F, P] => one shot the nav layer
 *
 *   Combo keycodes are resolved against the base layer
 *   (COMBO_ONLY_FROM_LAYER 0), so every combo works on every layer.
 */

const uint16_t PROGMEM move_workspace[] = { KC_D, KC_S, COMBO_END};

// [Q, W] => Cut
const uint16_t PROGMEM cut_combo[] = { KC_Q, KC_W, COMBO_END};

// [H, E] => Backspace
const uint16_t PROGMEM bspc_combo[] = { KC_H, KC_E, COMBO_END};

// [U, Y] => Zellij layer (right hand)
const uint16_t PROGMEM zellij_uy_combo[] = { KC_U, KC_Y, COMBO_END};

// [W, F] => Zellij layer (left hand)
const uint16_t PROGMEM zellij_wf_combo[] = { KC_W, KC_F, COMBO_END};

// [F, P] => one shot navigation
const uint16_t PROGMEM osl_nav_combo[] = { KC_F, KC_P, COMBO_END};

// [W, F, P] => Shift + Ins
const uint16_t PROGMEM insert_combo[] = { KC_W, KC_F, KC_P, COMBO_END};

// [S, T] => Enter
const uint16_t PROGMEM left_ent_combo[] = { KC_T, KC_S, COMBO_END};

// [T, R] => Tab
const uint16_t PROGMEM left_tab_combo[] = { KC_T, KC_R, COMBO_END};

// [T, F] => toggle nav layer (on and off)
const uint16_t PROGMEM toggle_nav_combo[] = { KC_T, KC_F, COMBO_END};

// [L, U] => Esc
const uint16_t PROGMEM esc_combo[] = { KC_L, KC_U, COMBO_END};

// [N, E] => Enter
const uint16_t PROGMEM ent_combo[] = { KC_N, KC_E, COMBO_END};

// [N, I] => Tab
const uint16_t PROGMEM tab_combo[] = { KC_N, KC_I, COMBO_END};

// [R, S] => Leader (left hand)
const uint16_t PROGMEM leader_left_combo[] = { KC_R, KC_S, COMBO_END};

// [E, I] => Leader (right hand)
const uint16_t PROGMEM leader_right_combo[] = { KC_E, KC_I, COMBO_END};

// [A, R] => Copy
const uint16_t PROGMEM copy_combo[] = { KC_A, KC_R, COMBO_END};

// [A, S] => Paste
const uint16_t PROGMEM paste_combo[] = { KC_A, KC_S, COMBO_END};

// [I, O] => Delete
const uint16_t PROGMEM del_combo[] = { KC_I, KC_O, COMBO_END};

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
  COMBO(leader_left_combo, QK_LEAD),
  COMBO(leader_right_combo, QK_LEAD),
  COMBO(zellij_wf_combo, OSL(_ZELLIJ)),
  COMBO(zellij_uy_combo, OSL(_ZELLIJ)),
  COMBO(toggle_nav_combo, TG(_NAV)),
  COMBO(osl_nav_combo, OSL(_NAV)),
};

