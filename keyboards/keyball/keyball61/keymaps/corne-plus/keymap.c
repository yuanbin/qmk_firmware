/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "version.h"
#include "features/achordion.h"
#include "features/swapper.h"
#include "features/num_word.h"
#define MACRO_DELAY 20

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
    ST_MACRO_SWITCH_BUF,
};

enum layers {
    L_BASE = 0,
    L_SYMBOLS,
    L_NUMNAV,
    L_FNMOUSE,
    L_MACSYS,
    L_MEDIA,
    L_NUMBERS,
    //    L_ONEHAND,
    L_AUTO_MOUSE
};

/*
  keys on each side: 6 6 6 7 7
  l1 r1
  l2 r2
  l3 r3
  l4 r4
  l5 r5
*/

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
  QWERTY
  ,-----------------------------------------.                    ,-----------------------------------------.
  |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
  |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
  `-----------------------------------------/       /     \      \-----------------------------------------'
             | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
             |      |      |      |      |/       /         \      \ |      |      |      |      |
             `----------------------------------'           '------''---------------------------'

	[0] = LAYOUT_universal(
	KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
	KC_DEL   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_INT3  ,
	KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , S(KC_7)  ,
	MO(1)    , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
	_______  , KC_LCTL  , KC_LALT  , KC_LGUI,LT(1,KC_LNG2),LT(2,KC_SPC),LT(3,KC_LNG1),    KC_BSPC,LT(2,KC_ENT),LT(1,KC_LNG2),KC_RGUI, _______ , KC_RALT  , KC_PSCR
	),
	     
*/

    [L_BASE] = LAYOUT_universal(
	KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1, ST_MACRO_ZOOMIN, ST_MACRO_ZOOMOUT, ST_MACRO_ZOOM_RESET,
	KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3,
	QK_REP,          KC_Q,         LT(3,KC_W),     LT(2,KC_E),   LT(5,KC_R),   MT(MOD_LGUI,KC_T),
	MT(MOD_RGUI,KC_Y),  LT(5,KC_U),   LT(2,KC_I),     LT(3,KC_O),   KC_P,         KC_DEL,
	SW_WIN,     MT(MOD_LSFT, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), LT(1,KC_F),            LT(4,KC_G),
        LT(4,KC_H), LT(1,KC_J),         MT(MOD_RCTL, KC_K), MT(MOD_RALT, KC_L), MT(MOD_RSFT, KC_SCLN), KC_ESCAPE,
	NUMWORD, KC_Z,  KC_X, MT(MOD_MEH,KC_C),     KC_V,   KC_B, KC_MS_BTN1,
	OSM(MOD_RSFT), KC_N,  KC_M, MT(MOD_MEH,KC_COMMA), KC_DOT, KC_SLASH, CW_TOGG,
	_______, _______, _______, KC_MS_BTN1, OSM(MOD_LSFT), KC_ENTER,      KC_BSPC,
	KC_TAB,  KC_SPACE,      OSM(MOD_RSFT), KC_MS_BTN1, _______, _______, _______
	),
    [L_SYMBOLS] = LAYOUT_universal(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, KC_AT,          KC_LABK,        KC_RABK,        KC_HASH,        KC_PERC,
	KC_PIPE,        KC_COLN,        KC_LCBR,        KC_RCBR,        KC_GRAVE, _______,
	_______, KC_EXLM,        KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_DQUO,
	KC_AMPR,        KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_CIRC, _______,
	_______, ST_MACRO_HOME_DIR,     KC_BSLS,        KC_ASTR,        KC_QUOTE,       KC_QUES, _______,
	_______, KC_TILD,        KC_DLR,         KC_LBRC,        KC_RBRC,        ST_MACRO_PAREN_DIR,     _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______
	),
      [L_NUMNAV] = LAYOUT_universal(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, KC_WWW_FORWARD, KC_HOME,        KC_UP,        KC_END,       ST_MACRO_ZOOMOUT,
	_______, KC_7,           KC_8,           KC_9,           KC_ASTR, _______,
	_______, KC_WWW_BACK, KC_LEFT,    KC_DOWN,         KC_RIGHT, ST_MACRO_ZOOMIN,
	_______, KC_4,           KC_5,           KC_6,          KC_DOT,        KC_MINUS,
	QK_BOOT, KC_WWW_HOME, KC_PGUP, _______,    KC_PGDN, ST_MACRO_ZOOM_RESET, _______,
	_______, KC_0, KC_1,           KC_2,           KC_3,           KC_SLASH,       QK_BOOT,
	_______, _______, _______, KC_PSCR, KC_DELETE, _______,  _______,
	KC_EQUAL, ST_MACRO_RAR, KC_0, KC_PLUS, _______, _______, _______
	),
    [L_FNMOUSE] = LAYOUT_universal(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
        _______, SCRL_DVI, SCRL_DVD, SSNP_VRT, SSNP_FRE, SSNP_HOR,
	KC_F12, KC_F7,          KC_F8,          KC_F9, KC_F15, _______,
        _______, _______, _______, _______, _______, _______,
	KC_F11, KC_F4,          KC_F5,          KC_F6, KC_F14, _______,
	_______, AML_TO, AML_I50, AML_D50, CPI_I100, CPI_D100, _______,
	_______,KC_F10, KC_F1,          KC_F2,          KC_F3, KC_F13, _______,
        _______, _______, _______, _______, _______, KBC_RST, KBC_SAVE,
	_______, _______, _______, _______, _______, _______, _______
	),
      [L_MACSYS] = LAYOUT_universal(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
        _______, MEH(KC_Z), MEH(KC_F9), MEH(KC_F8), MEH(KC_F7), MEH(KC_F12),
	_______, RALT(KC_S), ST_MACRO_UNDO,  LCTL(LALT(KC_J)), ST_MACRO_LANG,  _______,
        _______, MEH(KC_Y), MEH(KC_F6), MEH(KC_F5), MEH(KC_F4), MEH(KC_F11),
	_______, ST_MACRO_GOTO,     ST_MACRO_SWITCH_BUF,     ST_MACRO_OPEN_FILE,     ST_MACRO_SAVE_FILE,    _______,
        _______, MEH(KC_X), MEH(KC_F3), MEH(KC_F2), MEH(KC_F1), MEH(KC_F10),  _______,
	_______, DM_RSTP, ST_MACRO_QR,    ST_MACRO_MARK_BUF,    ST_MACRO_KILL_BUF,    ST_MACRO_JOIN_LINE,    _______,
	_______, _______, _______, KC_SYSTEM_SLEEP, KC_PWR, DM_PLY2, DM_PLY1,
	DM_REC1, DM_REC2, DM_RSTP, _______, _______, _______, _______
	),
      [L_MEDIA] = LAYOUT_universal(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,_______,
	_______, UG_TOGG, UG_NEXT, _______, _______, _______,
	_______, _______, KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,KC_MEDIA_STOP,  _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, KC_WWW_FAVORITES,KC_AUDIO_MUTE,  KC_MY_COMPUTER, _______, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______
	),
    [L_NUMBERS] = LAYOUT_universal(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
	_______, _______, _______, _______, _______, _______,
	_______, KC_4,    KC_5,    KC_6,    KC_DOT, KC_MINUS,
	_______, _______, _______, _______, _______, _______,  _______,
	_______, KC_0, KC_1,    KC_2,    KC_3,    KC_SLASH,_______,
	_______, _______, _______, _______, _______, _______, _______,
	KC_EQUAL, _______, KC_0,    KC_PLUS, _______, _______, _______
	),
#if 0
    [L_ONEHAND] = LAYOUT_universal(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
	_______, KC_WWW_FORWARD, KC_HOME, KC_WH_U, KC_END, ST_MACRO_ZOOMOUT,
        _______, _______, _______, _______, _______, _______,
	_______, KC_WWW_BACK, KC_BTN3, KC_BTN1, KC_BTN2, ST_MACRO_ZOOMIN,
        _______, _______, _______, _______, _______, _______,
	_______, KC_WWW_HOME, KC_PGUP, KC_WH_D,    KC_PGDN, ST_MACRO_ZOOM_RESET, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
	),
#endif
    [L_AUTO_MOUSE] = LAYOUT_universal(
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, KC_MS_BTN3, KC_MS_BTN2, SCRL_MO, KC_MS_BTN1, _______,
        _______, KC_MS_BTN1, SCRL_MO, KC_MS_BTN2, KC_MS_BTN3, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
	),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_layer(L_AUTO_MOUSE);
    // always required before the auto mouse feature will work
    set_auto_mouse_enable(true);
}
#endif

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
    }
    return true;
}
