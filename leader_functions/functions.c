
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {

    // sway goto workspace
    if (leader_sequence_one_key(KC_M)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_1)));
    } else if (leader_sequence_one_key(KC_COMM)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_2)));
    } else if (leader_sequence_one_key(KC_DOT)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_3)));
    } else if (leader_sequence_one_key(KC_N)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_4)));
    } else if (leader_sequence_one_key(KC_E)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_5)));
    } else if (leader_sequence_one_key(KC_I)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_6)));
    } else if (leader_sequence_one_key(KC_L)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_7)));
    } else if (leader_sequence_one_key(KC_U)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_8)));
    } else if (leader_sequence_one_key(KC_Y)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_9)));
    } else if (leader_sequence_one_key(KC_K)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_0)));

    // sway move window to workspace
    } else if (leader_sequence_two_keys(KC_T, KC_M)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_1))));
    } else if (leader_sequence_two_keys(KC_T, KC_COMM)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_2))));
    } else if (leader_sequence_two_keys(KC_T, KC_DOT)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_3))));
    } else if (leader_sequence_two_keys(KC_T, KC_N)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_4))));
    } else if (leader_sequence_two_keys(KC_T, KC_E)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_5))));
    } else if (leader_sequence_two_keys(KC_T, KC_I)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_6))));
    } else if (leader_sequence_two_keys(KC_T, KC_L)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_7))));
    } else if (leader_sequence_two_keys(KC_T, KC_U)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_8))));
    } else if (leader_sequence_two_keys(KC_T, KC_Y)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_9))));
    } else if (leader_sequence_two_keys(KC_T, KC_K)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_0))));
    }

    else if (leader_sequence_one_key(KC_C)){
        SEND_STRING(SS_TAP(X_ENT));
    }

}
