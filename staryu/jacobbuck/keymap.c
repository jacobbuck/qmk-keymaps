#include QMK_KEYBOARD_H

#define _KC_APPLICATION_WINDOWS LCTL(KC_DOWN)
#define _KC_SHOW_DESKTOP KC_F11

#define _HSV_FUCHSIA 213, 255, 255
#define _HSV_PURPLE 184, 255, 255
#define _HSV_GREEN 70, 255, 255
#define _HSV_YELLOW 40, 255, 255

enum layers {
    _LAYER0,
    _LAYER1,
    _LAYER2,
    _LAYER3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Audio
    [_LAYER0] = LAYOUT(
        TO(_LAYER3), TO(_LAYER1),
        KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, KC_AUDIO_VOL_UP
    ),
    // Media
    [_LAYER1] = LAYOUT(
        TO(_LAYER0), TO(_LAYER2),
        KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK
    ),
    // Brightness
    [_LAYER2] = LAYOUT(
        TO(_LAYER1), TO(_LAYER3),
        KC_BRIGHTNESS_DOWN, KC_NO, KC_BRIGHTNESS_UP
    ),
    // Misc
    [_LAYER3] = LAYOUT(
        TO(_LAYER2), TO(_LAYER0),
        KC_MISSION_CONTROL, _KC_APPLICATION_WINDOWS, _KC_SHOW_DESKTOP
    ),
};

void eeconfig_init_user(void) {
    backlight_enable();
    rgblight_enable();
    rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
}

void keyboard_post_init_user(void) {
    backlight_level(BACKLIGHT_LEVELS - 1);
    // layer_state_set_user is not called for inital state - set it here
    rgblight_sethsv(_HSV_FUCHSIA);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _LAYER1:
            rgblight_sethsv_noeeprom(_HSV_PURPLE);
            break;
        case _LAYER2:
            rgblight_sethsv_noeeprom(_HSV_GREEN);
            break;
        case _LAYER3:
            rgblight_sethsv_noeeprom(_HSV_YELLOW);
            break;
        case _LAYER0:
        default: //  for any other layers, or the default layer
            rgblight_sethsv_noeeprom(_HSV_FUCHSIA);
            break;
    }
    return state;
}
