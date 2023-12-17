#include QMK_KEYBOARD_H
#include "version.h"
#include "swapper.h"
#include "num_word.h"

#define MOON_LED_LEVEL LED_LEVEL
#define TR KC_TRANSPARENT
#define MC_DELAY 20

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    MACRO_LEADER,
    MACRO_HOMEDIR,
    MACRO_PARENDIR,
    MACRO_ZOOMIN,
    MACRO_ZOOMOUT,
    SW_WIN,  // Switch to next window         (alt-tab)
    NUMWORD
};

enum layers {
    L_BASE = 0,
    L_SYMBOLS,
    L_MEDIA,
    L_NUMBERS
};
/*
  keys on each side: 7 7 7 6 6 3
  l1 r1
  l2 r2
  l3 r3
  l4 r4
  l5 r5
  lt rt
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_moonlander(
        KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_AUDIO_VOL_UP, //l1
        KC_AUDIO_MUTE,  KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS, //r1
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_AUDIO_VOL_DOWN, //l2
        KC_HYPR,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS, //r2
        MT(MOD_LSFT, KC_ESCAPE), MT(MOD_LSFT, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), LT(1,KC_F), LT(2,KC_G), SW_WIN, //l3
        MACRO_LEADER,     LT(2,KC_H),     LT(1,KC_J),     MT(MOD_RCTL, KC_K),MT(MOD_RALT, KC_L),MT(MOD_RSFT, KC_SCLN),KC_QUOTE, //r3
        KC_LEFT_GUI,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B, //l4
        KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_LEFT, //r4
        KC_GRAVE,       KC_HOME,        MT(MOD_LSFT, KC_END),  KC_PAGE_UP,     KC_PGDN,        KC_HOME, // l5
        KC_END,         KC_UP,          KC_DOWN,        MT(MOD_RSFT, KC_LBRC),KC_RBRC,        KC_RIGHT, //r5
        KC_ENTER,       KC_BSPC,        NUMWORD, //lt
        CW_TOGG,        KC_TAB,         KC_SPACE //rt
                                 ),
    [L_SYMBOLS] = LAYOUT_moonlander(
        DM_REC1,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          TR,
        TR,             KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
        DM_REC2,        KC_AT,          KC_LABK,        KC_RABK,        KC_HASH,        KC_PERC,        TR,
        TR,             KC_PIPE,        KC_COLN,        KC_LCBR,        KC_RCBR,        KC_CIRC,        KC_F12,
        DM_PLY1,        KC_EXLM,        KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_DQUO,        TR,
        TR,             KC_AMPR,        KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_GRAVE,       TR,
        DM_PLY2,        MACRO_HOMEDIR,     KC_BSLS,        KC_ASTR,        KC_SLASH,       KC_QUES,
        KC_TILD,        KC_DLR,         KC_LBRC,        KC_RBRC,        MACRO_PARENDIR,     TR,
        DM_RSTP,        TR, TR, TR, TR, RGB_MODE_FORWARD,
        RGB_TOG,        TR, TR, TR, TR, TR,
        RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,
        RGB_SLD,        RGB_HUD,        RGB_HUI
                                    ),
    [L_MEDIA] = LAYOUT_moonlander(
        TR, TR, TR, TR, TR, KC_PSCR, KC_CAPS, //l1
        KC_DELETE, TR, TR, TR, TR, TR, TR, //r1
        TR, TR, MACRO_ZOOMIN, KC_MS_UP, MACRO_ZOOMOUT, TR, TR, //l2
        TR, TR, KC_7, KC_8, KC_9, TR, TR, //r2
        TR, KC_WWW_BACK, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WWW_FORWARD, TR, //l3
        TR, TR, KC_4, KC_5, KC_6, TR, TR, //r3
        TR, TR, TR, TR, TR, TR, //l4
        TR, KC_1, KC_2, KC_3, TR, TR, //r4
        QK_BOOT, TR, TR, KC_MS_BTN2, KC_MS_BTN1, MOON_LED_LEVEL, //l5
        KC_SYSTEM_SLEEP, KC_0, KC_DOT, TR, TR, TR, //r5
        TR, TR, TR, TR, TR, TR //thumb
                                  ),
    [L_NUMBERS] = LAYOUT_moonlander(
        TR, TR, TR, TR, TR, TR, TR, //l1
        TR, TR, TR, TR, TR, TR, TR, //r1
        TR, TR, TR, TR, TR, TR, TR, //l2
        TR, TR, KC_7, KC_8, KC_9, TR, TR, //r2
        TR, TR, TR, TR, TR, TR, TR, //l3
        TR, TR, KC_4, KC_5, KC_6, TR, TR, //r3
        TR, TR, TR, TR, TR, TR, //l4
        TR, KC_1, KC_2, KC_3, TR, TR, //r4
        TR, TR, TR, TR, TR, TR, //l5
        TR, KC_0, KC_DOT, TR, TR, TR, //r5
        TR, TR, TR, TR, TR, TR //thumb
                                    ),
};


bool sw_win_active = false;
bool sw_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WIN, keycode, record))
        return false; // has update, stop process

    if (!process_record_num_word(NUMWORD, L_NUMBERS, keycode, record))
        return false;

    switch (keycode) {
    case MACRO_LEADER:
        if (record->event.pressed) {
            SEND_STRING(SS_RALT(SS_TAP(X_R)));
        }
        break;
    case MACRO_HOMEDIR:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(MC_DELAY) SS_TAP(X_SLASH));
        }
        break;
    case MACRO_PARENDIR:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_DOT) SS_DELAY(MC_DELAY) SS_TAP(X_DOT) SS_DELAY(MC_DELAY) SS_TAP(X_SLASH));
        }
        break;
    case MACRO_ZOOMIN:
        if (record->event.pressed) {
            SEND_STRING(SS_RCTL(SS_RSFT(SS_TAP(X_EQUAL))));
        }
        break;
    case MACRO_ZOOMOUT:
        if (record->event.pressed) {
            SEND_STRING(SS_RCTL(SS_TAP(X_MINUS)));
        }
        break;

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    }

    return true;
}
