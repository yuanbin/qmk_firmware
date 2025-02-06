#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h"
#include "features/swapper.h"
#include "features/num_word.h"
#define MOON_LED_LEVEL LED_LEVEL
#define MACRO_DELAY 20

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    SW_WIN,  // Switch to next window         (alt-tab)
    NUMWORD,
    ST_MACRO_HOME_DIR,
    ST_MACRO_PAREN_DIR,
    ST_MACRO_RAR,
    ST_MACRO_RAR_N,
    ST_MACRO_LANG,
    ST_MACRO_ZOOMIN,
    ST_MACRO_ZOOMOUT,
    ST_MACRO_ZOOM_RESET,
    ST_MACRO_QR,
    ST_MACRO_UNDO,
    ST_MACRO_GOTO,
    ST_MACRO_SAVE_FILE,
    ST_MACRO_JOIN_LINE,
    ST_MACRO_KILL_BUF,
    ST_MACRO_MARK_BUF,
    ST_MACRO_OPEN_FILE,
    ST_MACRO_SWITCH_BUF,
    MAC_SPOTLIGHT,
    MAC_LOCK,
};

enum layers {
    L_BASE = 0,
    L_SYMBOLS,
    L_NUMNAV,
    L_FNMOUSE,
    L_MACSYS,
    L_MEDIA,
    L_NUMBERS,
    L_ONEHAND
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
	KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1, ST_MACRO_ZOOMIN, ST_MACRO_ZOOMOUT, ST_MACRO_ZOOM_RESET, _______,
	_______, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3,
	QK_REP, KC_Q,     LT(3,KC_W),     LT(2,KC_E),     LT(5,KC_R), MT(MOD_LGUI,KC_T),  KC_MS_BTN2,
	KC_MS_BTN2, MT(MOD_RGUI,KC_Y),     LT(5,KC_U),     LT(2,KC_I),     LT(3,KC_O), KC_P,  KC_DEL,
	SW_WIN,MT(MOD_LSFT, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_D),LT(1,KC_F),     LT(4,KC_G),     KC_MS_BTN1,
	KC_MS_BTN1, LT(4,KC_H),     LT(1,KC_J),     MT(MOD_RCTL, KC_K),MT(MOD_RALT, KC_L),MT(MOD_RSFT, KC_SCLN), KC_ESCAPE,
	NUMWORD, KC_Z,           KC_X,           MT(MOD_MEH,KC_C),           KC_V,           KC_B,
	KC_N,           KC_M,           MT(MOD_MEH,KC_COMMA),       KC_DOT,         KC_SLASH,       CW_TOGG,
	_______, _______,       KC_MS_BTN2, KC_MS_BTN1, OSM(MOD_LSFT),  TG(L_ONEHAND),
	_______, OSM(MOD_RSFT), KC_MS_BTN1,    KC_MS_BTN2,   _______,        _______,
	KC_ENTER,       KC_BSPC,        _______,                 _______, KC_TAB,         KC_SPACE
	),
    [L_SYMBOLS] = LAYOUT_moonlander(
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, KC_AT,          KC_LABK,        KC_RABK,        KC_HASH,        KC_PERC,        _______,
	_______, KC_PIPE,        KC_COLN,        KC_LCBR,        KC_RCBR,        KC_GRAVE,        _______,
	_______, KC_EXLM,        KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_DQUO,        _______,
	_______, KC_AMPR,        KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_CIRC,       _______,
	_______, ST_MACRO_HOME_DIR,     KC_BSLS,        KC_ASTR,        KC_QUOTE,       KC_QUES,
	KC_TILD,        KC_DLR,         KC_LBRC,        KC_RBRC,        ST_MACRO_PAREN_DIR,     _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______,                 _______, _______, _______
	),
    [L_NUMNAV] = LAYOUT_moonlander(
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, KC_WWW_FORWARD, KC_HOME,        KC_UP,        KC_END,       ST_MACRO_ZOOMOUT, _______,
	_______, _______, KC_7,           KC_8,           KC_9,           KC_ASTR,        _______,
	_______, KC_WWW_BACK, KC_LEFT,    KC_DOWN,         KC_RIGHT, ST_MACRO_ZOOMIN,        _______,
	_______, _______, KC_4,           KC_5,           KC_6,           KC_DOT,        KC_MINUS,
	_______, KC_WWW_HOME, KC_PGUP, _______,    KC_PGDN, ST_MACRO_ZOOM_RESET,
	_______, KC_1,           KC_2,           KC_3,           KC_SLASH,       _______,
	QK_BOOT,        _______, KC_PSCR,        KC_DELETE,      KC_APP,  _______,
	_______, KC_0,           KC_PLUS,         KC_EQUAL,       _______, KC_CAPS,
	_______, _______, _______,                 _______, _______, ST_MACRO_RAR
	),
    [L_FNMOUSE] = LAYOUT_moonlander(
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, KC_MS_WH_UP,  KC_MS_UP,       KC_MS_WH_DOWN, _______, _______,
	_______, KC_F12, KC_F7,          KC_F8,           KC_F9,          KC_F15, _______,
	_______, KC_MS_WH_LEFT,    KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT,  _______,
	_______, KC_F11, KC_F4,          KC_F5,          KC_F6,          KC_F14, _______,
	_______, _______, _______, _______, _______, _______,
	KC_F10, KC_F1,          KC_F2,          KC_F3,          KC_F13, _______,
	_______, _______, _______, _______, KC_MS_BTN3,     _______,
	_______, _______,         _______,         _______,         _______, _______,
	KC_MS_BTN1, KC_MS_BTN2, _______,                 _______, _______, _______
	),
    [L_MACSYS] = LAYOUT_moonlander(
	_______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
	_______, MEH(KC_Z), MEH(KC_F9), MEH(KC_F8), MEH(KC_F7), MEH(KC_F12), _______,
	_______, _______, RALT(KC_S), ST_MACRO_UNDO,  LCTL(LALT(KC_J)), ST_MACRO_LANG,     _______,
	_______, MEH(KC_Y), MEH(KC_F6), MEH(KC_F5), MEH(KC_F4), MEH(KC_F11), _______,
	_______, _______, ST_MACRO_GOTO,     ST_MACRO_SWITCH_BUF,     ST_MACRO_OPEN_FILE,     ST_MACRO_SAVE_FILE,    _______,
	_______, MEH(KC_X), MEH(KC_F3), MEH(KC_F2), MEH(KC_F1), MEH(KC_F10),
	_______, ST_MACRO_QR,    ST_MACRO_MARK_BUF,    ST_MACRO_KILL_BUF,    ST_MACRO_JOIN_LINE,   _______,
	_______, _______, MOON_LED_LEVEL, KC_SYSTEM_SLEEP, MAC_LOCK, _______,
	_______,  DM_RSTP, _______, _______, _______, _______,
	DM_PLY2, DM_PLY1, _______,                 _______, DM_REC1, DM_REC2
	),
    [L_MEDIA] = LAYOUT_moonlander(
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,_______, _______,
	_______, _______, RGB_VAI,        RGB_VAD,        RGB_SAI,        RGB_SAD,        _______,
	_______, _______, KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,KC_MEDIA_STOP,  _______, _______,
	_______, _______, RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        _______,
	_______, _______, KC_WWW_FAVORITES,KC_AUDIO_MUTE,  KC_MY_COMPUTER, _______,
	_______, RGB_HUI,        RGB_HUD,        RGB_SPI,        RGB_SPD,        _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______,                 _______, _______, _______
	),
    [L_NUMBERS] = LAYOUT_moonlander(
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
	_______, _______, _______, KC_DOT, _______, _______, _______,
	_______, _______, KC_4,    KC_5,    KC_6,    KC_DOT, KC_MINUS,
	_______, _______, _______, _______, _______, _______,
	_______, KC_1,    KC_2,    KC_3,    KC_SLASH,_______,
	_______, _______, _______, _______, _______, _______,
	_______, KC_0,    KC_PLUS,  KC_EQUAL,_______, _______,
	_______, _______, _______, _______, _______, _______
	),
        [L_ONEHAND] = LAYOUT(
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, KC_WWW_FORWARD, KC_HOME, KC_WH_U, KC_END, ST_MACRO_ZOOMOUT, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, KC_WWW_BACK, KC_BTN3, KC_BTN1, KC_BTN2, ST_MACRO_ZOOMIN, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, KC_WWW_HOME, KC_PGUP, KC_WH_D, KC_PGDN, ST_MACRO_ZOOM_RESET,
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______
	),
};

void matrix_scan_user(void) {
    achordion_task();
}

bool sw_win_active = false;
bool sw_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_achordion(keycode, record))
	return false;
    if (!update_swapper(&sw_win_active, KC_LGUI, KC_TAB, SW_WIN, keycode, record))
        return false; /* has update, stop process */
    if (!process_record_num_word(NUMWORD, L_NUMBERS, keycode, record))
        return false;

    switch (keycode) {
    case ST_MACRO_HOME_DIR:
	if (record->event.pressed) {
	    SEND_STRING(SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(MACRO_DELAY) SS_TAP(X_SLASH));
	}
	break;
    case ST_MACRO_PAREN_DIR:
	if (record->event.pressed) {
	    SEND_STRING(SS_TAP(X_DOT) SS_DELAY(MACRO_DELAY) SS_TAP(X_DOT) SS_DELAY(MACRO_DELAY) SS_TAP(X_SLASH));
	}
	break;
    case ST_MACRO_RAR:
	if (record->event.pressed) {
	    SEND_STRING(SS_RALT(SS_TAP(X_R)));
	}
	break;
    case ST_MACRO_RAR_N:
	if (record->event.pressed) {
	    SEND_STRING(SS_RALT(SS_TAP(X_R)) SS_DELAY(MACRO_DELAY) SS_TAP(X_N));
	}
	break;
    case ST_MACRO_LANG:
	if (record->event.pressed) {
	    SEND_STRING(SS_RCTL(SS_RSFT(SS_TAP(X_SPACE))));
	}
	break;
    case ST_MACRO_ZOOMIN:
	if (record->event.pressed) {
	    SEND_STRING(SS_RCTL(SS_RSFT(SS_TAP(X_EQUAL))));
	}
	break;
    case ST_MACRO_ZOOMOUT:
	if (record->event.pressed) {
	    SEND_STRING(SS_RCTL(SS_TAP(X_MINUS)));
	}
	break;
    case ST_MACRO_ZOOM_RESET:
	if (record->event.pressed) {
	    SEND_STRING(SS_RCTL(SS_TAP(X_0)));
	}
	break;
    case ST_MACRO_QR:
	if (record->event.pressed) {
	    SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_5))));
	}
	break;
    case ST_MACRO_UNDO:
	if (record->event.pressed) {
	    SEND_STRING(SS_RCTL(SS_RSFT(SS_TAP(X_MINUS))));
	}
	break;
    case ST_MACRO_GOTO:
	if (record->event.pressed) {
	    SEND_STRING(SS_RALT(SS_TAP(X_G)) SS_DELAY(MACRO_DELAY) SS_TAP(X_G));
	}
	break;
    case ST_MACRO_SAVE_FILE:
	if (record->event.pressed) {
	    SEND_STRING(SS_RCTL(SS_TAP(X_X)) SS_DELAY(MACRO_DELAY) SS_RCTL(SS_TAP(X_S)));
	}
	break;
    case ST_MACRO_JOIN_LINE:
	if (record->event.pressed) {
	    SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_6))));
	}
	break;
    case ST_MACRO_KILL_BUF:
	if (record->event.pressed) {
	    SEND_STRING(SS_RCTL(SS_TAP(X_X)) SS_DELAY(MACRO_DELAY) SS_TAP(X_K));
	}
	break;
    case ST_MACRO_MARK_BUF:
	if (record->event.pressed) {
	    SEND_STRING(SS_RCTL(SS_TAP(X_X)) SS_DELAY(MACRO_DELAY) SS_TAP(X_H));
	}
	break;
    case ST_MACRO_OPEN_FILE:
	if (record->event.pressed) {
	    SEND_STRING(SS_RCTL(SS_TAP(X_X)) SS_DELAY(MACRO_DELAY) SS_RCTL(SS_TAP(X_F)));
	}
	break;
    case ST_MACRO_SWITCH_BUF:
	if (record->event.pressed) {
	    SEND_STRING(SS_RCTL(SS_TAP(X_X)) SS_DELAY(MACRO_DELAY) SS_TAP(X_B));
	}
	break;
    case MAC_SPOTLIGHT:
	HCS(0x221);
    case MAC_LOCK:
	HCS(0x19E);

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
