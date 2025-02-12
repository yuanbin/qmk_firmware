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

#include "34key.h"
#include "features/achordion.h"
#include "features/swapper.h"
#include "features/num_word.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_4(__VA_ARGS__)

/*
  torn on each side: 6 6 6 4
  l1 r1
  l2 r2
  l3 r3
  lt rt
*/

// clang-format off
#define L_ONEHAND L_LAST

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

    [L_BASE] = LAYOUT_wrapper(
	KC_ESCAPE, __BASE_L1__, __BASE_R1__, KC_DEL,
	OSM(MOD_LSFT), __BASE_L2__, __BASE_R2__, OSM(MOD_RSFT),
	NUMWORD, __BASE_L3__, __BASE_R3__, CW_TOGG,
	KC_MS_BTN1, SW_APP, __BASE_LT__, __BASE_RT__, SW_WIN, _______
	),
    [L_SYMBOLS] = LAYOUT_wrapper(
	_______, __SYMBOLS_L1__, __SYMBOLS_R1__, _______,
	_______, __SYMBOLS_L2__, __SYMBOLS_R2__, _______,
	_______, __SYMBOLS_L3__, __SYMBOLS_R3__, _______,
	_______, KC_NO, __SYMBOLS_LT__, __SYMBOLS_RT__, KC_NO, _______
	),
      [L_NUMNAV] = LAYOUT_wrapper(
	_______, __NUMNAV_L1__, __NUMNAV_R1__, _______,
	_______, __NUMNAV_L2__, __NUMNAV_R2__, _______,
	_______, __NUMNAV_L3__, __NUMNAV_R3__, _______,
	_______, KC_NO, __NUMNAV_LT__, __NUMNAV_RT__, KC_NO, _______
	),
    [L_FNMOUSE] = LAYOUT_wrapper(
	_______, __FNMOUSE_L1__, __FNMOUSE_R1__, _______,
	_______, __FNMOUSE_L2__, __FNMOUSE_R2__, _______,
	_______, __FNMOUSE_L3__, __FNMOUSE_R3__, _______,
	_______, KC_NO, __FNMOUSE_LT__, __FNMOUSE_RT__, KC_NO, _______
	),
    [L_MAC] = LAYOUT_wrapper(
	_______, __MAC_L1__, __MAC_R1__, _______,
	_______, __MAC_L2__, __MAC_R2__, _______,
	_______, __MAC_L3__, _______, ST_MACRO_QR, ST_MACRO_MARK_BUF, ST_MACRO_KILL_BUF, ST_MACRO_JOIN_LINE, _______,
	_______, KC_NO, _______, _______, _______, _______, KC_NO, _______
	),
    [L_SYSMEDIA] = LAYOUT_wrapper(
	_______, __SYSMEDIA_L1__, __SYSMEDIA_R1__, _______,
	_______, __SYSMEDIA_L2__, __SYSMEDIA_R2__, _______,
	_______, __SYSMEDIA_L3__, __SYSMEDIA_R3__, _______,
	_______, KC_NO, __SYSMEDIA_LT__, __SYSMEDIA_RT__, KC_NO, _______
	),
    [L_NUMBERS] = LAYOUT_wrapper(
	_______, __NUMBERS_L1__, __NUMBERS_R1__, _______,
	_______, __NUMBERS_L2__, __NUMBERS_R2__, _______,
	_______, __NUMBERS_L3__, __NUMBERS_R3__, _______,
	_______, KC_NO, __NUMBERS_LT__, __NUMBERS_RT__, KC_NO, _______
	),
    [L_ONEHAND] = LAYOUT_wrapper(
	_______, __ONEHAND_L1__, __ONEHAND_R1__, _______,
	_______, __ONEHAND_L2__, __ONEHAND_R2__, _______,
	_______, __ONEHAND_L3__, __ONEHAND_R3__, _______,
	_______, KC_NO, __ONEHAND_LT__, __ONEHAND_RT__, KC_NO, _______
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

void housekeeping_task_user(void) {
    achordion_task();
}

bool sw_app_active = false;
bool sw_win_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_achordion(keycode, record))
        return false;
    if (!update_swapper(&sw_app_active, KC_LGUI, KC_TAB, SW_APP, keycode, record))
        return false; /* has update, stop process */
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
    case ST_MACRO_SWITCH_BUF:
	if (record->event.pressed) {
	    SEND_STRING(SS_RCTL(SS_TAP(X_X)) SS_DELAY(MACRO_DELAY) SS_TAP(X_B));
	}
	break;
    }
    return true;
}	
