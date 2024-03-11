#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h"
#include "features/swapper.h"
#include "features/num_word.h"
#define MACRO_DELAY 20

enum custom_keycodes {
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
};

enum layers {
    L_BASE = 0,
    L_SYMBOLS,
    L_NUMNAV,
    L_FNMOUSE,
    L_MACSYS,
    L_MEDIA,
    L_NUMBERS,
};

/*
  keys on each side: 6 6 6 7 4
  l1 r1
  l2 r2
  l3 r3
  l4 r4
  lt rt
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 *

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RGUI
),
*/

    [L_BASE] = LAYOUT(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	KC_ESCAPE,          KC_Q,         LT(3,KC_W),     LT(2,KC_E),   LT(5,KC_R),   KC_T,
	MT(MOD_RGUI,KC_Y),  LT(5,KC_U),   LT(2,KC_I),     LT(3,KC_O),   KC_P,         _______,
	SW_WIN,     MT(MOD_LSFT, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), LT(1,KC_F),            LT(4,KC_G),
        LT(4,KC_H), LT(1,KC_J),         MT(MOD_RCTL, KC_K), MT(MOD_RALT, KC_L), MT(MOD_RSFT, KC_SCLN), _______,
	NUMWORD, KC_Z,  KC_X, KC_C,     KC_V,   KC_B, _______,
	_______, KC_N,  KC_M, KC_COMMA, KC_DOT, KC_SLASH, CW_TOGG,
	_______, OSM(MOD_LSFT), KC_ENTER,      KC_BSPC,
	KC_TAB,  KC_SPACE,      OSM(MOD_RSFT), _______
	),
    [L_SYMBOLS] = LAYOUT(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, KC_AT,          KC_LABK,        KC_RABK,        KC_HASH,        KC_PERC,
	KC_PIPE,        KC_COLN,        KC_LCBR,        KC_RCBR,        KC_CIRC, _______,
	_______, KC_EXLM,        KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_DQUO,
	KC_AMPR,        KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_GRAVE, _______,
	_______, ST_MACRO_HOME_DIR,     KC_BSLS,        KC_ASTR,        KC_QUOTE,       KC_QUES, _______,
	_______, KC_TILD,        KC_DLR,         KC_LBRC,        KC_RBRC,        ST_MACRO_PAREN_DIR,     _______,
	_______, _______, _______, _______,
	_______, _______, _______, _______
	),
      [L_NUMNAV] = LAYOUT(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, KC_HOME,        KC_UP,        KC_END,       _______,
	_______, KC_7,           KC_8,           KC_9,           KC_ASTR, _______,
	_______, KC_WWW_BACK, KC_LEFT,    KC_DOWN,         KC_RIGHT, KC_WWW_FORWARD,
	_______, KC_4,           KC_5,           KC_6,           KC_DOT,        KC_MINUS,
	QK_BOOT, _______, KC_PGUP, KC_WWW_HOME,    KC_PGDN, _______, _______,
	_______, _______, KC_1,           KC_2,           KC_3,           KC_SLASH,       _______,
	KC_PSCR, KC_DELETE, KC_APP,  _______,
	_______, KC_0,      KC_PLUS, KC_EQUAL
	),
    [L_FNMOUSE] = LAYOUT(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, _______,
	_______, KC_F7,          KC_F8,          KC_F9,          _______, _______,
	_______, KC_MS_WH_UP,    KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,
	_______, KC_F4,          KC_F5,          KC_F6,          _______, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______,_______, KC_F1,          KC_F2,          KC_F3,          _______, _______,
	_______, KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1,
	_______, KC_F10,         KC_F11,         KC_F12
	),
      [L_MACSYS] = LAYOUT(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
	_______, ST_MACRO_LANG, ST_MACRO_ZOOMIN,     ST_MACRO_ZOOMOUT,     ST_MACRO_ZOOM_RESET,     _______,
	_______, _______, _______, DM_PLY1,        DM_PLY2,        _______,
	_______, ST_MACRO_QR,     ST_MACRO_UNDO,     ST_MACRO_GOTO,     ST_MACRO_SAVE_FILE,    _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, ST_MACRO_JOIN_LINE,    ST_MACRO_KILL_BUF,    ST_MACRO_MARK_BUF,    ST_MACRO_OPEN_FILE,    _______,
	KC_SYSTEM_SLEEP, _______, DM_REC1, DM_REC2,
	KC_PWR, DM_RSTP, _______, _______
	),
      [L_MEDIA] = LAYOUT(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,_______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,KC_MEDIA_STOP,  _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, KC_WWW_FAVORITES,KC_AUDIO_MUTE,  KC_MY_COMPUTER, _______, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______,
	_______, _______, _______, _______
	),
    [L_NUMBERS] = LAYOUT(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
	_______, _______, _______, _______, _______, _______,
	_______, KC_4,    KC_5,    KC_6,    KC_DOT, KC_MINUS,
	_______, _______, _______, _______, _______, _______,  _______,
	_______, _______, KC_1,    KC_2,    KC_3,    KC_SLASH,_______,
	_______, _______, _______, _______,
	_______, KC_0,    KC_PLUS,  KC_EQUAL
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
    if (!update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WIN, keycode, record))
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
    }
    return true;
}
