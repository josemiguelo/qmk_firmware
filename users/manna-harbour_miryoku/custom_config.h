// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#if defined (KEYBOARD_crkbd)
    #define XXX KC_NO

    #define MIRYOKU_MAPPING( \
        K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \
        K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \
        K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \
        N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39  \
    ) \
    LAYOUT_split_3x6_3( \
    KC_LGUI, K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09,  XXX,     \
    K32,     K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19,  K37,     \
    XXX,     K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29,  XXX,     \
                         XXX,  K33,  K34,         K35,  K36,  XXX                        \
    )

    #define MIRYOKU_LAYER_BASE \
        KC_Q,              LALT_T(KC_W),      LCTL_T(KC_E),      LSFT_T(KC_R),      KC_T,              LT(U_NUM,KC_Y),    LSFT_T(KC_U),      LCTL_T(KC_I),      LALT_T(KC_O),      KC_P,              \
        LGUI_T(KC_A),      RALT_T(KC_S),      KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              RALT_T(KC_L),      LGUI_T(KC_QUOT),   \
        KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           \
        U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),KC_TAB,            LT(U_NAV,KC_ENT),  LT(U_SYM,KC_SPC),  LT(U_NUM,KC_DEL),  LT(U_FUN,KC_BSPC), U_NP,              U_NP

    #define MIRYOKU_LAYER_NAV \
        KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           CW_TOGG,           \
        U_NP,              KC_RALT,           U_NA,              U_NA,              U_NA,              KC_HOME,           KC_PGUP,           KC_PGDN,           KC_END,            KC_INS,            \
        U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
        U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

    #define MIRYOKU_LAYER_MEDIA \
        U_NP,              KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_BRIU,           RGB_HUI,           RGB_SAI,           RGB_VAI,           RGB_TOG,           \
        KC_LGUI,           KC_RALT,           U_NA,              U_NA,              U_NA,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           U_NU,              \
        U_NA,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BRID,           RGB_HUD,           RGB_SAD,           RGB_VAD,           RGB_MOD,           \
        U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MPLY,           KC_MSTP,           KC_MUTE,           U_NP,              U_NP
#endif

#define RGBLIGHT_SPLIT
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
