
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_E)) {
        // Leader, f => Types the below string
        SEND_STRING(SS_TAP(X_ESC));
    } else if (leader_sequence_one_key(KC_N)) {
        SEND_STRING(SS_TAP(X_ENT));
    } else if (leader_sequence_two_keys(KC_T, KC_E)) {
        SEND_STRING(SS_LCTL("\\n"));
    } else if (leader_sequence_two_keys(KC_T, KC_S)) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT("|"))));
    } else if (leader_sequence_two_keys(KC_T, KC_H)) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT("_"))));
    }
}
