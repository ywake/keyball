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

enum keymap_layer
{
  DVOR, // Dvorak layer
  QWER, // Qwerty layer
  MOUSE, // Mouse & Function layer, No character.
  SYMBL, // Symbol & Number layer
};

#define MY_LGUI (LM(QWER, MOD_LGUI))
#define MY_LCTL (LM(QWER, MOD_LCTL))
#define MY_LNG2 (LT(MOUSE, KC_LNG2))
#define MY_SPC  (SFT_T(KC_SPC))
#define MY_LNG1 (LT(SYMBL, KC_LNG1))
#define MY_ENT  (LT(MOUSE, KC_ENT))
#define EMOJI   (C(LCMD(KC_SPC)))
#define MY_PSCR (LCMD(LSFT(KC_5)))
#define BALL    (_______)
#define RESERVE (_______)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [DVOR] = LAYOUT_universal(
    KC_TAB  , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y    ,                               KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , _______ ,
    MY_LGUI , KC_A    , KC_O    , KC_E    , KC_U    , KC_I    ,                               KC_D    , KC_H    , KC_T    , KC_N    , KC_S    , KC_MINS ,
    KC_LSFT , KC_SLSH , KC_Q    , KC_J    , KC_K    , KC_X    ,                               KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , KC_RSFT ,
                        MY_LCTL , KC_LALT , MY_LNG2 , MY_SPC  , MY_LNG1 ,           MY_ENT  , KC_BSPC ,           BALL    , BALL    , TG(QWER)
  ),

  [QWER] = LAYOUT_universal(
    KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,                               KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , _______ ,
    RESERVE , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    ,                               KC_H    , KC_J    , KC_K    , KC_L    , KC_QUOT , _______ ,
    RESERVE , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,                               KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , RESERVE ,
                        RESERVE , RESERVE , RESERVE , RESERVE , RESERVE ,           RESERVE , KC_BSPC ,           BALL    , BALL    , RESERVE
  ),

  [MOUSE] = LAYOUT_universal(
    KC_ESC  , KC_F10  , KC_F1   , KC_F2   , KC_F3   , XXXXXXX ,                               KC_PGUP , KC_HOME , KC_UP   , KC_END  ,S(KC_TAB), KC_TAB  ,
    RESERVE , KC_F11  , KC_F4   , KC_F5   , KC_F6   , MY_PSCR ,                               KC_PGDN , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX , _______ ,
    RESERVE , KC_F12  , KC_F7   , KC_F8   , KC_F9   , EMOJI   ,                               KC_BTN4 , KC_BTN1 , KC_BTN2 , KC_BTN3 , KC_BTN5 , RESERVE ,
                        RESERVE , RESERVE , RESERVE , RESERVE , RESERVE ,           RESERVE , KC_DEL  ,           BALL    , BALL    , RESERVE
  ),

  [SYMBL] = LAYOUT_universal(
    _______ , KC_0    , KC_1    , KC_2    , KC_3    , XXXXXXX ,                               KC_CIRC , KC_AMPR , KC_LBRC , KC_RBRC , KC_PIPE , _______ ,
    RESERVE , KC_PDOT , KC_4    , KC_5    , KC_6    , XXXXXXX ,                               KC_HASH , KC_SCLN , KC_LPRN , KC_RPRN , KC_GRV  , _______ ,
    RESERVE , XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX ,                               KC_DLR  , KC_ASTR , KC_EQL  , KC_MINS , KC_BSLS , RESERVE ,
                        RESERVE , RESERVE , RESERVE , RESERVE , RESERVE ,           RESERVE , KC_DEL  ,           BALL    , BALL    , RESERVE
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is SYMBL
    keyball_set_scroll_mode(get_highest_layer(state) == SYMBL);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    // keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
