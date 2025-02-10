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

#include "34key.h"
#include "features/achordion.h"
#include "features/swapper.h"
#include "features/num_word.h"

#define LAYOUT_wrapper(...)   LAYOUT_universal(__VA_ARGS__)

/*
  keyball61 on each side: 6 6 6 7 7
  l1 r1
  l2 r2
  l3 r3
  l4 r4
  l5 r5
*/

// clang-format off
#define L_AUTOMOUSE L_LAST

#define __BASE_L0__ KC_MS_BTN3,    KC_MS_BTN2,        KC_MS_BTN1,      ST_MACRO_ZOOMIN, ST_MACRO_ZOOMOUT, ST_MACRO_ZOOM_RESET
#define __BASE_R0__ KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MS_BTN1,      KC_MS_BTN2,       KC_MS_BTN3

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

    [L_BASE] = LAYOUT_wrapper(
	__BASE_L0__, __BASE_R0__,
	KC_ESCAPE, __BASE_L1__, __BASE_R1__, KC_DEL,
	OSM(MOD_LSFT), __BASE_L2__, __BASE_R2__, OSM(MOD_RSFT),
	NUMWORD, __BASE_L3__, _______, _______, __BASE_R3__, CW_TOGG,
	_______, _______, _______, _______, SW_WIN, __BASE_LT__, __BASE_RT__, __EMPTY_ROW__
	),
    [L_SYMBOLS] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __SYMBOLS_L1__, __SYMBOLS_R1__, _______,
	_______, __SYMBOLS_L2__, __SYMBOLS_R2__, _______,
	_______, __SYMBOLS_L3__, _______, _______, __SYMBOLS_R3__, _______,
	__EMPTY_ROW__, __SYMBOLS_LT__, __SYMBOLS_RT__, __EMPTY_ROW__
	),
      [L_NUMNAV] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __NUMNAV_L1__, __NUMNAV_R1__, _______,
	_______, __NUMNAV_L2__, __NUMNAV_R2__, _______,
	_______, __NUMNAV_L3__, _______, _______, __NUMNAV_R3__, _______,
	__EMPTY_ROW__, __NUMNAV_LT__, __NUMNAV_RT__, __EMPTY_ROW__	  
	),
    [L_FNMOUSE] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______,  SCRL_DVI, SCRL_DVD, SSNP_VRT, SSNP_FRE, SSNP_HOR, __FNMOUSE_R1__, _______,
	_______, __EMPTY_ROW__, __FNMOUSE_R2__, _______,
	_______, AML_TO, AML_I50, AML_D50, CPI_I100, CPI_D100, _______, _______, __FNMOUSE_R3__, _______,
	__EMPTY_ROW__, __FNMOUSE_LT__, __FNMOUSE_RT__, __EMPTY_ROW__
	),
      [L_MAC] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __MAC_L1__, __MAC_R1__, _______,
	_______, __MAC_L2__, __MAC_R2__, _______,
	_______, __MAC_L3__, _______, _______, __MAC_R3__, _______,
	__EMPTY_ROW__, __MAC_LT__, __MAC_RT__, __EMPTY_ROW__
	),
      [L_SYSMEDIA] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __SYSMEDIA_L1__, _______, UG_TOGG, UG_NEXT, _______, _______, _______,
	_______, __SYSMEDIA_L2__, __SYSMEDIA_R2__, _______,
	_______, __SYSMEDIA_L3__, _______, _______, __SYSMEDIA_R3__, _______,
	__EMPTY_ROW__, __SYSMEDIA_LT__, __SYSMEDIA_RT__, __EMPTY_ROW__
	),
    [L_NUMBERS] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __NUMBERS_L1__, __NUMBERS_R1__, _______,
	_______, __NUMBERS_L2__, __NUMBERS_R2__, _______,
	_______, __NUMBERS_L3__, _______, _______, __NUMBERS_R3__, _______,
	__EMPTY_ROW__, __NUMBERS_LT__, __NUMBERS_RT__, __EMPTY_ROW__
	),
    [L_AUTOMOUSE] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __AUTOMOUSE_L1__, __AUTOMOUSE_R1__, _______,
	_______, __AUTOMOUSE_L2__, __AUTOMOUSE_R2__, _______,
	_______, __AUTOMOUSE_L3__, _______, _______, __AUTOMOUSE_R3__, _______,
	__EMPTY_ROW__, __AUTOMOUSE_LT__, __AUTOMOUSE_RT__, __EMPTY_ROW__
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
    set_auto_mouse_layer(L_AUTOMOUSE);
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
