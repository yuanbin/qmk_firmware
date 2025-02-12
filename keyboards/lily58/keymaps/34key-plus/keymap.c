#include "34key.h"
#include "features/achordion.h"
#include "features/swapper.h"
#include "features/num_word.h"

#define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)

#define L_ONEHAND L_LAST

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [L_BASE] = { ENCODER_CCW_CW(   KC_WH_U,    KC_WH_D), ENCODER_CCW_CW(   KC_VOLD,    KC_VOLU) },
    [L_SYMBOLS] = { ENCODER_CCW_CW(   A(S(KC_TAB)),    A(KC_TAB)), ENCODER_CCW_CW(   KC_NO,    KC_NO) },
    [L_NUMNAV] = { ENCODER_CCW_CW(  C(S(KC_TAB)) ,    C(KC_TAB)), ENCODER_CCW_CW(   KC_NO,    KC_NO) },
    [L_FNMOUSE] = { ENCODER_CCW_CW(   KC_NO,    KC_NO), ENCODER_CCW_CW(   KC_NO,    KC_NO) },
    [L_MAC] = { ENCODER_CCW_CW(   KC_NO,    KC_NO), ENCODER_CCW_CW(   KC_NO,    KC_NO) },
    [L_SYSMEDIA] = { ENCODER_CCW_CW(   KC_NO,    KC_NO), ENCODER_CCW_CW(   KC_NO,    KC_NO) },
    [L_NUMBERS] = { ENCODER_CCW_CW(   KC_NO,    KC_NO), ENCODER_CCW_CW(   KC_NO,    KC_NO) },
    [L_ONEHAND] = { ENCODER_CCW_CW(   KC_NO,    KC_NO), ENCODER_CCW_CW(   KC_NO,    KC_NO) }
};
#endif

/*
  lily58 on each side: 6 6 6 7 4
  l1 r1
  l2 r2j
  l3 r3
  l4 r4
  lt rt
*/

#define __BASE_L0__ KC_MS_BTN3,    KC_MS_BTN2,        KC_MS_BTN1,      ST_MACRO_ZOOMIN, ST_MACRO_ZOOMOUT, ST_MACRO_ZOOM_RESET
#define __BASE_R0__ KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MS_BTN1,      KC_MS_BTN2,       KC_MS_BTN3

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

    [L_BASE] = LAYOUT_wrapper(
	__BASE_L0__, __BASE_R0__,
	KC_ESCAPE, __BASE_L1__, __BASE_R1__, KC_DEL,
	OSM(MOD_LSFT), __BASE_L2__, __BASE_R2__, OSM(MOD_RSFT),
	NUMWORD, __BASE_L3__, _______, TG(L_ONEHAND), __BASE_R3__, CW_TOGG,
	KC_MS_BTN1, SW_APP, __BASE_LT__, __BASE_RT__, SW_WIN, _______
	),
    [L_SYMBOLS] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __SYMBOLS_L1__, __SYMBOLS_R1__, _______,
	_______, __SYMBOLS_L2__, __SYMBOLS_R2__, _______,
	_______, __SYMBOLS_L3__, _______, _______, __SYMBOLS_R3__, _______,
	_______, KC_NO, __SYMBOLS_LT__, __SYMBOLS_RT__, KC_NO, _______
	),
    [L_NUMNAV] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __NUMNAV_L1__, __NUMNAV_R1__, _______,
	_______, __NUMNAV_L2__, __NUMNAV_R2__, _______,
	_______, __NUMNAV_L3__, _______, _______, __NUMNAV_R3__, _______,
	_______, KC_NO, __NUMNAV_LT__, __NUMNAV_RT__, KC_NO, _______
	),
    [L_FNMOUSE] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __FNMOUSE_L1__, __FNMOUSE_R1__, _______,
	_______, __FNMOUSE_L2__, __FNMOUSE_R2__, _______,
	_______, __FNMOUSE_L3__, _______, _______, __FNMOUSE_R3__, _______,
	_______, KC_NO, __FNMOUSE_LT__, __FNMOUSE_RT__, KC_NO, _______
	),
    [L_MAC] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __MAC_L1__, __MAC_R1__, _______,
	_______, __MAC_L2__, __MAC_R2__, _______,
	_______, __MAC_L3__, _______, _______, __MAC_R3__, _______,
	_______, KC_NO, __MAC_LT__, __MAC_RT__, KC_NO, _______
	),
    [L_SYSMEDIA] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __SYSMEDIA_L1__, __SYSMEDIA_R1__, _______,
	_______, __SYSMEDIA_L2__, __SYSMEDIA_R2__, _______,
	_______, __SYSMEDIA_L3__, _______, _______, __SYSMEDIA_R3__, _______,
	_______, KC_NO, __SYSMEDIA_LT__, __SYSMEDIA_RT__, KC_NO, _______
	),
    [L_NUMBERS] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __NUMBERS_L1__, __NUMBERS_R1__, _______,
	_______, __NUMBERS_L2__, __NUMBERS_R2__, _______,
	_______, __NUMBERS_L3__, _______, _______, __NUMBERS_R3__, _______,
	_______, KC_NO, __NUMBERS_LT__, __NUMBERS_RT__, KC_NO, _______
	),
    [L_ONEHAND] = LAYOUT_wrapper(
	_______, __EMPTY_ROW__, __EMPTY_ROW__, _______,
	_______, __ONEHAND_L1__, __ONEHAND_R1__, _______,
	_______, __ONEHAND_L2__, __ONEHAND_R2__, _______,
	_______, __ONEHAND_L3__, _______, _______, __ONEHAND_R3__, _______,
	_______, KC_NO, __ONEHAND_LT__, __ONEHAND_RT__, KC_NO, _______
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
    }
    return true;
}
