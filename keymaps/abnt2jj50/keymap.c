/*
Copyright 2020 Guillaume Gérard

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public LicensezZZ
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum {
    TD_LSFT_CAPS,
    TD_ALT_ALTGR,
    TD_WIN_PT_EN,
    TD_SMC_QUEST,
    TD_AGUDO_CRASE,
    TD_TIL_CIRCUNF,
};

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _CONFIG,
};

enum keycodes {
    QWERTY
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_ALT_ALTGR] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),
    [TD_WIN_PT_EN] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_SPC)),
    [TD_SMC_QUEST] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, RALT(KC_W)),
    [TD_AGUDO_CRASE]= ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_LBRC)),
    [TD_TIL_CIRCUNF] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_QUOT)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   `  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |LS/Cap|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |En/Lsh|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Ct/F12|      | Win  |Gr/Alt| Lower|    Space    | Raise|  / ? | Left | Down |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, TD(TD_AGUDO_CRASE),
	KC_GRV, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, TD(TD_TIL_CIRCUNF),
	TD(TD_LSFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_SFTENT,
	LCTL_T(KC_F12), XXXXXXX, TD(TD_WIN_PT_EN), TD(TD_ALT_ALTGR), MO(_LOWER), KC_SPC, KC_SPC, MO(_RAISE), TD(TD_SMC_QUEST), KC_LEFT, KC_DOWN, KC_RGHT
    ),
	
    /* LOWER
     * ,-----------------------------------------------------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  Del |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |   [  |   ]  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Ltgg | Bri+ |      |      |      |      |      |   -  |   +  |   =  |   {  |   }  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Lmod | Hue+ |      |      |      |      |      |      |   |  |      | PgUp | Print|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Stat | Sat+ |      |      |      |  Play/Pause |CONFIG|   \  | Home | PgDn | End  |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT(
	XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,       KC_F8,         KC_F9,   KC_F10,  KC_DEL,
	XXXXXXX, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,      KC_F18,        KC_F19, KC_LBRC, KC_RBRC,
	RGB_TOG, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PMNS,     KC_PPLS,       KC_PEQL, KC_LCBR, KC_RCBR,
    RGB_MOD, RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     LSFT(KC_NUHS), XXXXXXX, KC_PGUP, KC_PSCR,
	RGB_M_P ,RGB_SAI, RGB_M_R, XXXXXXX, _______, KC_MPLY, KC_MPLY, MO(_CONFIG), KC_BSLS,       KC_HOME, KC_PGDN, KC_END
    ),

    /* RAISE
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      | VolU |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |CONFIG|  Play/Pause |      |      | Prev | VolD | Next |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT(
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MO(_CONFIG), XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT
    ),

    /* CONFIG
     * ,-----------------------------------------------------------------------------------.
     * |BOOTLD|      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_CONFIG] = LAYOUT(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
    }
    return true;
};
