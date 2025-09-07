
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

// wechsel auf die 4 häufigsten Layer
// Leader N -> L_GUI + 1
// Leader E -> L_GUI + 2
// Leader I -> L_GUI + 3
// Leader O -> L_GUI + 4
// Leader m + {NEIO} -> verschieben auf einen der Layer

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_N)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_1)));
    } else if (leader_sequence_one_key(KC_E)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_2)));
    } else if (leader_sequence_one_key(KC_I)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_3)));
    } else if (leader_sequence_one_key(KC_O)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_4)));
    } else if (leader_sequence_two_keys(KC_T, KC_E)) {
        SEND_STRING(SS_LCTL("\\n"));
    } else if (leader_sequence_two_keys(KC_T, KC_S)) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT("|"))));
    } else if (leader_sequence_two_keys(KC_T, KC_H)) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT("_"))));
    } else if (leader_sequence_one_key(KC_H)) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))));
    } else if (leader_sequence_one_key(KC_I)) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_RIGHT))));
    }
}
