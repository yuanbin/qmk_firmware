#include "34key.h"
#include "features/achordion.h"
#include "features/swapper.h"
#include "features/num_word.h"

#define MOON_LED_LEVEL LED_LEVEL

#define LAYOUT_wrapper(...)   LAYOUT_moonlander(__VA_ARGS__)

/*
  moonlander on each side: 7 7 7 6 6 3
  l1 r1
  l2 r2
  l3 r3
  l4 r4
  l5 r5
  lt rt
*/

// clang-format off
#define L_ONEHAND L_LAST

#define __BASE_L0__ KC_MS_BTN3,    KC_MS_BTN2,        KC_MS_BTN1,      ST_MACRO_ZOOMIN, ST_MACRO_ZOOMOUT, ST_MACRO_ZOOM_RESET
#define __BASE_R0__ KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MS_BTN1,      KC_MS_BTN2,       KC_MS_BTN3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_wrapper(
	__BASE_L0__, _______, _______, __BASE_R0__,
	KC_ESCAPE, __BASE_L1__, _______, _______, __BASE_R1__, KC_DEL,
	OSM(MOD_LSFT), __BASE_L2__, _______, _______, __BASE_R2__, OSM(MOD_RSFT),
	NUMWORD, __BASE_L3__, __BASE_R3__, CW_TOGG,
	_______, _______, _______, _______, KC_MS_BTN1, _______,
	TG(L_ONEHAND), SW_WIN, _______, _______, _______, _______,
	__BASE_LT__, _______, _______, __BASE_RT__
	),
    [L_SYMBOLS] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, _______, _______, __EMPTY_ROW__, _______,
	_______, __SYMBOLS_L1__, _______, _______, __SYMBOLS_R1__, _______,
	_______, __SYMBOLS_L2__, _______, _______, __SYMBOLS_R2__, _______,
	_______, __SYMBOLS_L3__, __SYMBOLS_R3__, _______,
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	__SYMBOLS_LT__, _______, _______, __SYMBOLS_RT__
	),
    [L_NUMNAV] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, _______, _______, __EMPTY_ROW__, _______,
	_______, __NUMNAV_L1__, _______, _______, __NUMNAV_R1__, _______,
	_______, __NUMNAV_L2__, _______, _______, __NUMNAV_R2__, _______,
	_______, __NUMNAV_L3__, __NUMNAV_R3__, _______,
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	__NUMNAV_LT__, _______, _______, __NUMNAV_RT__
	),
    [L_FNMOUSE] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, _______, _______, __EMPTY_ROW__, _______,
	_______, __FNMOUSE_L1__, _______, _______, __FNMOUSE_R1__, _______,
	_______, __FNMOUSE_L2__, _______, _______, __FNMOUSE_R2__, _______,
	_______, __FNMOUSE_L3__, __FNMOUSE_R3__, _______,
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	__FNMOUSE_LT__, _______, _______, __FNMOUSE_RT__
	),
    [L_MAC] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, _______, _______, __EMPTY_ROW__, _______,
	_______, __MAC_L1__, _______, _______, __MAC_R1__, _______,
	_______, __MAC_L2__, _______, _______, __MAC_R2__, _______,
	_______, __MAC_L3__, __MAC_R3__, _______,
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	__MAC_LT__, _______, _______, __MAC_RT__
	),
    [L_SYSMEDIA] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, _______, _______, __EMPTY_ROW__, _______,
	_______, __SYSMEDIA_L1__, _______, _______, _______, RGB_VAI, RGB_VAD, RGB_SAI, RGB_SAD , _______,
	_______, __SYSMEDIA_L2__, _______, _______, _______, RGB_TOG, TOGGLE_LAYER_COLOR, RGB_MODE_FORWARD,  _______, _______, 
	_______, __SYSMEDIA_L3__, _______, RGB_HUI, RGB_HUD, RGB_SPI, RGB_SPD, _______,
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	__SYSMEDIA_LT__, _______, _______, __SYSMEDIA_RT__
	),
    [L_NUMBERS] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, _______, _______, __EMPTY_ROW__, _______,
	_______, __NUMBERS_L1__, _______, _______, __NUMBERS_R1__, _______,
	_______, __NUMBERS_L2__, _______, _______, __NUMBERS_R2__, _______,
	_______, __NUMBERS_L3__, __NUMBERS_R3__, _______,
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	__NUMBERS_LT__, _______, _______, __NUMBERS_RT__
	),
    [L_ONEHAND] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, _______, _______, __EMPTY_ROW__, _______,
	_______, __ONEHAND_L1__, _______, _______, __ONEHAND_R1__, _______,
	_______, __ONEHAND_L2__, _______, _______, __ONEHAND_R2__, _______,
	_______, __ONEHAND_L3__, __ONEHAND_R3__, _______,
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	__ONEHAND_LT__, _______, _______, __ONEHAND_RT__
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
    /* case RGB_SLD: */
    /*     if (rawhid_state.rgb_control) { */
    /*         return false; */
    /*     } */
    /*     if (record->event.pressed) { */
    /*         rgblight_mode(1); */
    /*     } */
    /*     return false; */
    }
    return true;
}
