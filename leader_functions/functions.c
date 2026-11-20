
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {

    // LEADER + [0-9] sway goto workspace
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

    // LEADER + T + [0-9] sway move window to workspace
    } else if (leader_sequence_two_keys(KC_G, KC_M)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_1))));
    } else if (leader_sequence_two_keys(KC_G, KC_COMM)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_2))));
    } else if (leader_sequence_two_keys(KC_G, KC_DOT)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_3))));
    } else if (leader_sequence_two_keys(KC_G, KC_N)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_4))));
    } else if (leader_sequence_two_keys(KC_G, KC_E)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_5))));
    } else if (leader_sequence_two_keys(KC_G, KC_I)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_6))));
    } else if (leader_sequence_two_keys(KC_G, KC_L)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_7))));
    } else if (leader_sequence_two_keys(KC_G, KC_U)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_8))));
    } else if (leader_sequence_two_keys(KC_G, KC_Y)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_9))));
    } else if (leader_sequence_two_keys(KC_G, KC_K)) {
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_0))));
    }

    // LEADER + F + [0-9] awesomewm add focus to to workspace
    else if (leader_sequence_two_keys(KC_F, KC_M)) {
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_1))));
    } else if (leader_sequence_two_keys(KC_F, KC_COMM)) {
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_2))));
    } else if (leader_sequence_two_keys(KC_F, KC_DOT)) {
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_3))));
    } else if (leader_sequence_two_keys(KC_F, KC_N)) {
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_4))));
    } else if (leader_sequence_two_keys(KC_F, KC_E)) {
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_5))));
    } else if (leader_sequence_two_keys(KC_F, KC_I)) {
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_6))));
    } else if (leader_sequence_two_keys(KC_F, KC_L)) {
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_7))));
    } else if (leader_sequence_two_keys(KC_F, KC_U)) {
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_8))));
    } else if (leader_sequence_two_keys(KC_F, KC_Y)) {
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_9))));
    } else if (leader_sequence_two_keys(KC_F, KC_K)) {
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_0))));
    }

    // LEADER + O awesomewm move focused window to other screen
    else if (leader_sequence_one_key(KC_O)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_O)));
    }

    // LEADER + A/R/S/T awesomewm focus window left / up / down / right
    else if (leader_sequence_one_key(KC_A)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
    }
    else if (leader_sequence_one_key(KC_T)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
    }
    else if (leader_sequence_one_key(KC_S)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_UP)));
    }
    else if (leader_sequence_one_key(KC_R)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_DOWN)));
    }

    // LEADER + X/C focus by index up and down
    else if (leader_sequence_one_key(KC_C)){
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_DOWN))));
    }
    else if (leader_sequence_one_key(KC_X)){
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_UP))));
    }


    // LEADER + K + A/R/S/T awesomewm swap window left / up / down / right
    else if (leader_sequence_two_keys(KC_K, KC_A)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
    }
    else if (leader_sequence_two_keys(KC_K, KC_T)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
    }
    else if (leader_sequence_two_keys(KC_K, KC_S)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_UP)));
    }
    else if (leader_sequence_two_keys(KC_K, KC_R)) {
        SEND_STRING(SS_LGUI(SS_TAP(X_DOWN)));
    }

    // TODO V nochmal überdenken
    // LEADER + V + R/S awesomewm focus screen on the left / right
    else if (leader_sequence_two_keys(KC_V, KC_S)) {
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_LEFT))));
    }
    else if (leader_sequence_two_keys(KC_V, KC_R)) {
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_RIGHT))));
    }


}
