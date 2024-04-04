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
  DVOR,
  QWER,
  MOUSE,
  SYMBL,
  CNTRL,
};

#define MY_LGUI (LM(QWER, MOD_LGUI))
#define MY_LCTL (LM(QWER, MOD_LCTL))
#define MY_LNG2 (LT(MOUSE, KC_LNG2))
#define MY_SPC (LSFT_T(KC_SPC))
#define MY_LNG1 (LT(SYMBL, KC_LNG1))
#define MY_ENT (LT(MOUSE, KC_ENT))

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DVOR] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , _______  ,
    KC_TAB   , KC_QUOT  , KC_COMM  , KC_DOT   , KC_P     , KC_Y     ,                                  KC_F     , KC_G     , KC_C     , KC_R     , KC_L     , _______  ,
    MY_LGUI  , KC_A     , KC_O     , KC_E     , KC_U     , KC_I     ,                                  KC_D     , KC_H     , KC_T     , KC_N     , KC_S     , KC_MINS  ,
    KC_LSFT  , KC_SLSH  , KC_Q     , KC_J     , KC_K     , KC_X     , KC_LBRC  ,            KC_RBRC  , KC_B     , KC_M     , KC_W     , KC_V     , KC_Z     , _______  ,
    MO(CNTRL), TG(QWER) , MY_LCTL  , KC_LALT  , MY_LNG2  , MY_SPC   , MY_LNG1  ,            MY_ENT   , KC_BSPC  , _______  , _______  , _______  , KC_RALT  , _______
  ),

  [QWER] = LAYOUT_universal(
    _______  , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , _______  ,
    _______  , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , _______  ,
    _______  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_QUOT  , _______  ,
    _______  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , _______  ,            _______  , KC_N     , KC_M     ,KC_COMM   , KC_DOT   , KC_SLSH  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  ,_______   , _______  , _______  , _______
  ),

  [SYMBL] = LAYOUT_universal(
    KC_PWR   , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    KC_ESC   , KC_F12   , KC_F7    , KC_F8    , KC_F9    , _______  ,                                  _______  , KC_ASTR  , KC_EQL   , KC_MINS  , KC_BSLS  , KC_F12   ,
    _______  , KC_F11   , KC_F4    , KC_F5    , KC_F6    , _______  ,                                  _______  , KC_SCLN  , KC_LBRC  , KC_RBRC  , KC_GRV   , _______  ,
    _______  , KC_F10   , KC_F1    , KC_F2    , KC_F3    , _______  , _______  ,            _______  , _______  , _______  , KC_LPRN  , KC_RPRN  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , KC_DEL   , _______  , _______  , _______  , _______  , _______
  ),

  [MOUSE] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    KC_PWR   , _______  , KC_7     , KC_8     , KC_9     , _______  ,                                  KC_PGUP  , KC_HOME  , KC_UP    , KC_END   , _______  , _______  ,
    _______  , _______  , KC_4     , KC_5     , KC_6     , _______  ,                                  KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,
    _______  , KC_0     , KC_1     , KC_2     , KC_3     , _______  , _______  ,            _______  , _______  , KC_BTN1  , KC_BTN2  , KC_BTN3  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , KC_DEL   , _______  , _______  , _______  , _______  , _______
  ),

  // error: Number of keymap layers exceeds maximum set by DYNAMIC_KEYMAP_LAYER_COUNT
  // [CNTRL] = LAYOUT_universal(
  //   KC_KB_POWER, _______, _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______ , _______  ,
  //   _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______ , _______  ,
  //   _______  , _______  , _______  , _______  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
  //   _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EE_CLR  ,            EE_CLR  , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
  //   _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  // ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state)
{
  // Auto enable scroll mode when the highest layer is SYMBL
  keyball_set_scroll_mode(get_highest_layer(state) == SYMBL);
  return state;
}

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void)
{
  // keyball_oled_render_keyinfo();
  keyball_oled_render_ballinfo();
  keyball_oled_render_layerinfo();
}
#endif
