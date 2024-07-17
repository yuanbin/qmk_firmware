/* Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h"
#include "features/swapper.h"
#include "features/num_word.h"
#define MACRO_DELAY 20
#define LAYOUT LAYOUT_split_3x6_4

enum custom_keycodes {
    SW_WIN = SAFE_RANGE,  // Switch to next window         (alt-tab)
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
    L_ONEHAND
};

/*
  keys on each side: 6 6 6 4
  l1 r1
  l2 r2
  l3 r3
  lt rt
*/

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |    |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | `    |   A  |   S  |   D  |   F  |   G  |    |   H  |   J  |   K  |   L  |   ;  |  [   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | \    |   Z  |   X  |   C  |   V  |   B  |    |   N  |   M  |   ,  |   .  |   /  |  ]   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ | Ctrl | Bksp | Del  |    |Enter |Space | Alt  | ____ |
 *               |      |      |Shift |Raise |    | Gui  |Lower |      |      |
 *               `---------------------------'    `---------------------------'
[_QWERTY] = LAYOUT_split_3x6_4(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
    KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_LBRC,
    KC_BSLS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC ,
                      R_DEL,   KC_LCTL, S_BSPC,  R_DEL,     G_ENT,   L_SPC,   KC_RALT, G_ENT
),
*/

    [L_BASE] = LAYOUT(
	KC_ESCAPE,          KC_Q,         LT(3,KC_W),     LT(2,KC_E),   LT(5,KC_R),   MT(MOD_LGUI,KC_T),
	MT(MOD_RGUI,KC_Y),  LT(5,KC_U),   LT(2,KC_I),     LT(3,KC_O),   KC_P,         _______,
	SW_WIN,     MT(MOD_LSFT, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), LT(1,KC_F),            LT(4,KC_G),
        LT(4,KC_H), LT(1,KC_J),         MT(MOD_RCTL, KC_K), MT(MOD_RALT, KC_L), MT(MOD_RSFT, KC_SCLN), ST_MACRO_RAR_N,
	NUMWORD, KC_Z,  KC_X, KC_C,     KC_V,   KC_B,
	KC_N,  KC_M, KC_COMMA, KC_DOT, KC_SLASH, CW_TOGG,
        KC_MS_BTN1, OSM(MOD_LSFT), KC_ENTER,      KC_BSPC,
	KC_TAB,  KC_SPACE,      OSM(MOD_RSFT), KC_MS_BTN1
	),
    [L_SYMBOLS] = LAYOUT(
	_______, KC_AT,          KC_LABK,        KC_RABK,        KC_HASH,        KC_PERC,
	KC_PIPE,        KC_COLN,        KC_LCBR,        KC_RCBR,        KC_GRAVE, _______,
	_______, KC_EXLM,        KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_DQUO,
	KC_AMPR,        KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_CIRC, _______,
	_______, ST_MACRO_HOME_DIR,     KC_BSLS,        KC_ASTR,        KC_QUOTE,       KC_QUES,
	KC_TILD,        KC_DLR,         KC_LBRC,        KC_RBRC,        ST_MACRO_PAREN_DIR,     _______,
	_______, _______, _______, _______,
	_______, _______, _______, _______
	),
      [L_NUMNAV] = LAYOUT(
	_______, KC_WWW_FORWARD, KC_HOME,        KC_UP,        KC_END,       ST_MACRO_ZOOMOUT,
	_______, KC_7,           KC_8,           KC_9,           KC_ASTR, _______,
	_______, KC_WWW_BACK, KC_LEFT,    KC_DOWN,         KC_RIGHT, ST_MACRO_ZOOMIN,
	_______, KC_4,           KC_5,           KC_6,          KC_DOT,        KC_MINUS,
	QK_BOOT, KC_WWW_HOME, KC_PGUP, _______,    KC_PGDN, ST_MACRO_ZOOM_RESET,
	_______, KC_1,           KC_2,           KC_3,           KC_SLASH,       QK_BOOT,
	KC_PSCR, KC_DELETE, KC_DOT,  _______,
	KC_EQUAL, ST_MACRO_RAR, KC_0, KC_PLUS
	),
    [L_FNMOUSE] = LAYOUT(
	_______, _______, KC_MS_WH_UP,  KC_MS_UP,       KC_MS_WH_DOWN, _______,
	KC_F12, KC_F7,          KC_F8,          KC_F9, KC_F15, _______,
	_______, KC_MS_WH_LEFT,    KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT,
	KC_F11, KC_F4,          KC_F5,          KC_F6, KC_F14, _______,
	_______, _______, _______, _______, _______, _______,
	KC_F10, KC_F1,          KC_F2,          KC_F3, KC_F13, _______,
	_______, KC_MS_BTN3,     KC_MS_BTN1,     KC_MS_BTN2,
	_______, _______, _______, _______
	),
      [L_MACSYS] = LAYOUT(
        _______, _______, _______, DM_PLY1, DM_PLY2, _______,
	_______, ST_MACRO_LANG, _______, _______, _______,  _______,
	_______, _______, _______, _______, _______, _______,
	_______, ST_MACRO_QR,     ST_MACRO_UNDO,     ST_MACRO_GOTO,     ST_MACRO_SAVE_FILE,    _______,
	_______, _______, _______, _______, _______, _______,
	_______, ST_MACRO_JOIN_LINE,    ST_MACRO_KILL_BUF,    ST_MACRO_MARK_BUF,    ST_MACRO_OPEN_FILE,    _______,
	KC_SYSTEM_SLEEP, KC_PWR, DM_REC1, DM_REC2,
	_______, DM_RSTP, _______, _______
	),
      [L_MEDIA] = LAYOUT(
	_______, _______, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,_______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,KC_MEDIA_STOP,  _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, KC_WWW_FAVORITES,KC_AUDIO_MUTE,  KC_MY_COMPUTER, _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______,
	_______, _______, _______, _______
	),
    [L_NUMBERS] = LAYOUT(
	_______, _______, _______, _______, _______, _______,
	_______, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
	_______, _______, _______, _______, _______, _______,
	_______, KC_4,    KC_5,    KC_6,    KC_DOT, KC_MINUS,
	_______, _______, _______, _______, _______, _______,
	_______, KC_1,    KC_2,    KC_3,    KC_SLASH,_______,
	_______, _______, KC_DOT, _______,
	KC_EQUAL, _______, KC_0,    KC_PLUS
	),
    [L_ONEHAND] = LAYOUT(
	_______, KC_WWW_FORWARD, KC_HOME, KC_WH_U, KC_END, ST_MACRO_ZOOMOUT,
        _______, _______, _______, _______, _______, _______,
	_______, KC_WWW_BACK, KC_BTN3, KC_BTN1, KC_BTN2, ST_MACRO_ZOOMIN,
        _______, _______, _______, _______, _______, _______,
	_______, KC_WWW_HOME, KC_PGUP, KC_WH_D,  KC_PGDN, ST_MACRO_ZOOM_RESET,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______
	),  
};

/*
const uint16_t PROGMEM encoder_keymaps[][2][2] = {
    [_QWERTY] =  { { C(S(KC_TAB)), C(KC_TAB) },     { KC_PGDN,      KC_PGUP } },
    [_LOWER]  =  { { C(KC_LEFT),   C(KC_RGHT) },    { KC_VOLD,      KC_VOLU } },
    [_RAISE]  =  { { KC_TRNS,      KC_TRNS },       { G(KC_TAB),    G(S(KC_TAB)) } },
    [_ADJUST] =  { { KC_TRNS,      KC_TRNS },       { KC_TRNS,      KC_TRNS } },
};
*/
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    torn_set_led(0, IS_LAYER_ON_STATE(state, L_NUMBERS));
    torn_set_led(1, IS_LAYER_ON_STATE(state, L_ONEHAND));
    return state;
}

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
