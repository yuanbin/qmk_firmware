#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "version.h"

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
    L_MAC,
    L_SYSMEDIA,
    L_NUMBERS,
    L_LAST
};

//clang-format off

#define __EMPTY_ROW__ _______, _______, _______, _______, _______
// naming: layer_side_row. e.g. BASE_L1
#define __BASE_L1__ KC_Q,               LT(3,KC_W),         LT(2,KC_E),           LT(5,KC_R),          MT(MOD_LGUI,KC_T)
#define __BASE_R1__ MT(MOD_RGUI,KC_Y),  LT(5,KC_U),         LT(2,KC_I),           LT(3,KC_O),          KC_P
#define __BASE_L2__ MT(MOD_LSFT, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D),   LT(1,KC_F),          LT(4,KC_G)
#define __BASE_R2__ LT(4,KC_H),         LT(1,KC_J),         MT(MOD_RCTL, KC_K),   MT(MOD_RALT, KC_L),  MT(MOD_RSFT, KC_SCLN)
#define __BASE_L3__ KC_Z,               KC_X,               MT(MOD_MEH,KC_C),     KC_V,                KC_B
#define __BASE_R3__ KC_N,               KC_M,               MT(MOD_MEH,KC_COMMA), KC_DOT,              KC_SLASH
#define __BASE_LT__ KC_ENTER,           KC_BSPC
#define __BASE_RT__ KC_TAB,             KC_SPACE

#define __SYMBOLS_L1__ KC_AT,             KC_LABK,        KC_RABK,        KC_HASH,        KC_PERC
#define __SYMBOLS_R1__ KC_PIPE,           KC_COLN,        KC_LCBR,        KC_RCBR,        KC_GRAVE
#define __SYMBOLS_L2__ KC_EXLM,           KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_DQUO
#define __SYMBOLS_R2__ KC_AMPR,           KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_CIRC
#define __SYMBOLS_L3__ ST_MACRO_HOME_DIR, KC_BSLS,        KC_ASTR,        KC_QUOTE,       KC_QUES
#define __SYMBOLS_R3__ KC_TILD,           KC_DLR,         KC_LBRC,        KC_RBRC,        ST_MACRO_PAREN_DIR
#define __SYMBOLS_LT__ KC_ESCAPE,         NUMWORD   
#define __SYMBOLS_RT__ CW_TOGG,           _______

#define __NUMNAV_L1__ KC_WWW_FORWARD,     KC_HOME,        KC_UP,          KC_END,         ST_MACRO_ZOOMOUT
#define __NUMNAV_R1__ KC_PLUS,            KC_7,           KC_8,           KC_9,           KC_ASTR
#define __NUMNAV_L2__ KC_WWW_BACK,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       ST_MACRO_ZOOMIN
#define __NUMNAV_R2__ KC_MINUS,           KC_4,           KC_5,           KC_6,           KC_DOT
#define __NUMNAV_L3__ KC_WWW_HOME,        KC_PGUP,        KC_APP,         KC_PGDN,        ST_MACRO_ZOOM_RESET
#define __NUMNAV_R3__ KC_0,               KC_1,           KC_2,           KC_3,           KC_SLASH
#define __NUMNAV_LT__ _______,            _______
#define __NUMNAV_RT__ KC_EQUAL,           ST_MACRO_RAR

#define __FNMOUSE_L1__ _______,           KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  _______
#define __FNMOUSE_R1__ KC_F12,            KC_F7,          KC_F8,          KC_F9,          KC_F15
#define __FNMOUSE_L2__ KC_MS_WH_LEFT,     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT
#define __FNMOUSE_R2__ KC_F11,            KC_F4,          KC_F5,          KC_F6,          KC_F14
#define __FNMOUSE_L3__ _______,           KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1,     _______
#define __FNMOUSE_R3__ KC_F10,            KC_F1,          KC_F2,          KC_F3,          KC_F13
#define __FNMOUSE_LT__ _______,           _______
#define __FNMOUSE_RT__ _______,           _______

#define __MAC_L1__ MEH(KC_Z), MEH(KC_F9),     MEH(KC_F8),          MEH(KC_F7),         MEH(KC_F12)
#define __MAC_R1__ _______,   RALT(KC_S),     ST_MACRO_UNDO,       LCTL(LALT(KC_J)),   ST_MACRO_LANG
#define __MAC_L2__ MEH(KC_Y), MEH(KC_F6),     MEH(KC_F5),          MEH(KC_F4),         MEH(KC_F11)
#define __MAC_R2__ _______,   ST_MACRO_GOTO,  ST_MACRO_SWITCH_BUF, ST_MACRO_OPEN_FILE, ST_MACRO_SAVE_FILE
#define __MAC_L3__ MEH(KC_X), MEH(KC_F3),     MEH(KC_F2),          MEH(KC_F1),         MEH(KC_F10)
#define __MAC_R3__ DM_RSTP,   ST_MACRO_QR,    ST_MACRO_MARK_BUF,   ST_MACRO_KILL_BUF,  ST_MACRO_JOIN_LINE
#define __MAC_LT__ DM_PLY2, DM_PLY1
#define __MAC_RT__ DM_REC1, DM_REC2

#define __SYSMEDIA_L1__ _______, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_UP,    KC_MEDIA_NEXT_TRACK, KC_SYSTEM_SLEEP
#define __SYSMEDIA_R1__ __EMPTY_ROW__
#define __SYSMEDIA_L2__ _______, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_VOL_DOWN,  KC_MEDIA_STOP,       KC_DELETE
#define __SYSMEDIA_R2__ __EMPTY_ROW__
#define __SYSMEDIA_L3__ _______, KC_WWW_FAVORITES,    KC_AUDIO_MUTE,      KC_MY_COMPUTER,      _______
#define __SYSMEDIA_R3__ __EMPTY_ROW__
#define __SYSMEDIA_LT__ KC_CAPS, QK_BOOT
#define __SYSMEDIA_RT__ QK_BOOT, KC_SYRQ

#define __NUMBERS_L1__ __EMPTY_ROW__ 
#define __NUMBERS_R1__ __NUMNAV_R1__
#define __NUMBERS_L2__ __EMPTY_ROW__
#define __NUMBERS_R2__ __NUMNAV_R2__
#define __NUMBERS_L3__ __EMPTY_ROW__
#define __NUMBERS_R3__ __NUMNAV_R3__
#define __NUMBERS_LT__ _______, _______
#define __NUMBERS_RT__ KC_EQUAL, _______

#define __ONEHAND_L1__ KC_WWW_FORWARD, KC_HOME, KC_WH_U, KC_END,  ST_MACRO_ZOOMOUT
#define __ONEHAND_R1__ __EMPTY_ROW__
#define __ONEHAND_L2__ KC_WWW_BACK,    KC_BTN3, KC_BTN2, KC_BTN1, ST_MACRO_ZOOMIN
#define __ONEHAND_R2__ __EMPTY_ROW__
#define __ONEHAND_L3__ KC_WWW_HOME,    KC_PGUP, KC_WH_D, KC_PGDN, ST_MACRO_ZOOM_RESET
#define __ONEHAND_R3__ __EMPTY_ROW__
#define __ONEHAND_LT__ _______, _______
#define __ONEHAND_RT__ _______, _______

#define __AUTOMOUSE_L1__ __EMPTY_ROW__
#define __AUTOMOUSE_R1__ __EMPTY_ROW__ 
#define __AUTOMOUSE_L2__ _______, KC_MS_BTN2, SCRL_MO, KC_MS_BTN1, _______
#define __AUTOMOUSE_R2__ _______, KC_MS_BTN1, SCRL_MO, KC_MS_BTN2, _______
#define __AUTOMOUSE_L3__ _______, _______, KC_MS_BTN3, _______, _______
#define __AUTOMOUSE_R3__ _______, _______, KC_MS_BTN3, _______, _______
#define __AUTOMOUSE_LT__ _______, _______
#define __AUTOMOUSE_RT__ _______, _______

// clang-format on
