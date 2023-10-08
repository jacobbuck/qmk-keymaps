#include QMK_KEYBOARD_H

#define _KC_MISSION_CONTROL LCTL(KC_UP)

enum layers {
  _BASE,
  _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty) layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
     * |-----------------------------------------------------------------------------------------+
     * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh | Up  | MC  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl |  Alt  |  Cmd  |              Space                | Cmd |  Fn  |Left |Down |Right|
     * `-----------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_directional(
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, XXXXXXX, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, _KC_MISSION_CONTROL,
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_SPC, KC_RGUI, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Fn layer
     * ,-----------------------------------------------------------------------------------------.
     * |  `  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |    Del    |
     * |-----------------------------------------------------------------------------------------+
     * |        | Br- | Br+ |     |     |     |     |Prev |Play |Next |Mute | Vol- | Vol+ |Reset |
     * |-----------------------------------------------------------------------------------------+
     * |         |     |     |     |Find |     |     |     |     |     |     |     |             |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |Undo | Cut |Copy |Paste|     |     |     |     |     |     | RSh |PgUp | MC  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl |  Alt  |  Cmd  |                                   | Cmd |  Fn  |Home |PgDn | End |
     * `-----------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_directional(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_DEL,
        XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, BL_TOGG, BL_STEP, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_FIND, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_PGUP, _______,
        _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_HOME, KC_PGDN, KC_END
    )
};
