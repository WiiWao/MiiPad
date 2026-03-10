// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


// Where the macro-key is called. You would put these in the layouts
enum custom_keycodes {
    AA = SAFE_RANGE,
    DRIVE,
    GITHUB,
    DESMOS,
    CHESS,
    MY_OTHER_MACRO,
};

// This is the macro stuff, each case is their own macro
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case AA:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("AAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
        } else {
            // when keycode QMKBEST is released
        }
        break;

    // Opens Google Drive
    case DRIVE:
        if (record->event.pressed) {
            tap_code16(C(KC_T)); // opens up a new tab
            wait_ms(100); // small delay incase needed
            SEND_STRING("http://drive.google.com/\n");
        }
        break;

    // Opens GitHub
    case GITHUB:
        if (record->event.pressed) {
            tap_code16(C(KC_T)); // opens up a new tab
            wait_ms(100); // small delay incase needed
            SEND_STRING("https://github.com/\n");
        }
        break;

    // Opens desmos scientific calculator
    case DESMOS:
        if (record->event.pressed) {
            tap_code16(C(KC_T)); // opens up a new tab
            wait_ms(100); // small delay incase needed
            SEND_STRING("https://www.desmos.com/scientific\n");
        }
        break;

    // Opens chess.com
    case CHESS:
        if (record->event.pressed) {
            tap_code16(C(KC_T)); // opens up a new tab
            wait_ms(100); // small delay incase needed
            SEND_STRING("https://chess.com/\n");
        }
        break;

    case MY_OTHER_MACRO:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("ac")); // selects all and copies
        }
        break;
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        DRIVE,   GITHUB,   DESMOS,   CHESS,
        KC_1,   KC_2,   KC_3,   KC_4,
        KC_VOLU,   KC_VOLD,   KC_MUTE,   TG(1)
    ),

    [1] = LAYOUT(
        KC_A,   KC_8,   KC_4,   QK_BOOT,
        KC_E,   KC_4,   KC_5,   KC_6,
        KC_I,   KC_7,   KC_8,   TG(1)
    )
};