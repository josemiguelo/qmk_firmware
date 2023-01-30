/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* qwerty
  * ,-------------------------------.                        ,--------------------------------.
  * |NUMP / ~   | Q | W | E | R | T |                        | Y | U | I | O | P |Fn / BackSP |
  * |-----------+------+------+-----|                        |------+------+------+------+----|
  * |LCtrl/Tab  | A | S | D | F | G |                        | H | J | K | L |;: |RCtrl / '   |
  * |-----------+------+------+-----|                        |------+------+------+------+----|
  * |LShift/ESC | Z | X | C | V | B |.--------.    .---------. N | M |,< |.> |/? |RShift / /? |
  * `-------------------------------/         /    \          \-------------------------------'
  *                | NAV  | LGUI | /Mous/Ent /      \SYM/Space \  | RGUI | RAlt |
  *                |      |      |/         /        \          \ |      |      |
  *                `-----------------------'          '-------------------------'
  */
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  LT(3,KC_TILD),   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,   LT(5,KC_BSPC) ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  LCTL_T(KC_TAB),   KC_A,   KC_S,    KC_D,    KC_F,      KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,RCTL_T(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  LSFT_T(KC_ESC),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,KC_SLSH,RSFT_T(KC_BSLS),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(1), KC_LGUI, LT(6,KC_ENT) , LT(2,KC_SPC), KC_RGUI, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  /* navigate
  * ,-----------------------------------.                     ,-----------------------------.
  * |         |    |    |    |     |    |                     |     |    | UP |     |   |   |
  * |---------+----+----+----+-----+----|                     |-----+----+----+-----+---+---|
  * |LCtrl/Tab|    |    |    |     |    |                     |     |LEFT|DOWN|RIGHT|   |   |
  * |---------+----+----+----+-----+----|                     |-----+----+----+-----+---+---|
  * |BRID     |BRIU|UNDO|COPY|PASTE|VOLD|.---------.  .-------.VOLU |PREV|PLAY|NEXT |   |   |
  * `-----------------------------------/         /    \         \--------------------------'
  *                    | NAV  | LGUI | /Mous/Ent /      \SYM/Space\  | RGUI  | ADJ |
  *                    |      |      |/         /        \         \ |       |     |
  *                    `-----------------------'          '---------''-------------'
  */
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BRMD, KC_BRMU, LGUI(KC_Z), LGUI(KC_C), LGUI(KC_V), KC_VOLD,             KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, MO(4)
                                      //`--------------------------'  `--------------------------'
  ),

  /* symbols
  * ,-------------------------------.                        ,--------------------------------.
  * |NUMP / ~   | ! | @ | # | $ | % |                        | ^ | & | * | ( | ) |Fn / BackSP |
  * |-----------+------+------+-----|                        |------+------+------+------+----|
  * |LCtrl/Tab  | A | S | D | F | G |                        | - | = | [ | ] | \ |RCtrl  / '  |
  * |-----------+------+------+-----|                        |------+------+------+------+----|
  * |LShift/ESC | Z | X | C | V | B |.--------.    .---------. _ | + | { | } | | |RShift / /  |
  * `-------------------------------/         /    \          \-------------------------------'
  *                | NAV  | LGUI | /Mous/Ent /      \SYM/Space \  | RGUI | RAlt |
  *                |      |      |/         /        \          \ |      |      |
  *                `-----------------------'          '-------------------------'
  */
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  /* numpad
  * ,-------------------------------.                        ,-----------------------.
  * |           |   |   |   |   |   |                        | + | 7 | 8 | 9 | - |   |
  * |-----------+------+------+-----|                        |------+------+---------|
  * |LCtrl/Tab  |   |   |   |   |   |                        | * | 4 | 5 | 6 | / |   |
  * |-----------+------+------+-----|                        |------+------+---------|
  * |           |   |   |   |   |   |.--------.    .---------.   | 1 | 2 | 3 | 0 |   |
  * `-------------------------------/         /    \          \----------------------'
  *                | NAV  | LGUI | /Mous/Ent /      \SYM/Space \  | RGUI | RAlt |
  *                |      |      |/         /        \          \ |      |      |
  *                `-----------------------'          '-------------------------'
  */
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PPLS,    KC_7,    KC_8,    KC_9, KC_MINS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PAST,    KC_4,    KC_5,    KC_6, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),


  /* adjust
  * ,--------------------------------.                        ,----------------------.
  * | RESET  |     |     |     |  |  |                        |   |   |   |   |   |  |
  * |-----------+------+------+------|                        |------+------+------+-|
  * | TOGGLE | HUI | SAI | VAI |  |  |                        |   |   |   |   |   |  |
  * |-----------+------+------+------|                        |------+------+------+-|
  * | MOD    | HUD | SAD | VAO |  |  |.--------.    .---------.   |   |   |   |   |  |
  * `-------------------------------/         /    \          \----------------------'
  *                | NAV  | LGUI | /Mous/Ent /      \SYM/Space \  | RGUI | RAlt |
  *                |      |      |/         /        \          \ |      |      |
  *                `-----------------------'          '-------------------------'
  */
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  /* function
  * ,-------------------------------------.                       ,----------------------------------.
  * |          | F1  | F2  | F3 | F4 | F5 |                       | F6 | F7 | F8 | F9 | F10 |   |    |
  * |----------+------+------+------+-----|                       |------+------+------+------+------|
  * |LCtrl/Tab | F11 | F12 |    |    |    |                       |    |    |    |    |     |   |    |
  * |----------+------+------+-----+------|                       |------+------+------+------+------|
  * |          |   |   |   |    |   |.--------.    .---------.    |    |    |    |    |     |   |    |
  * `-------------------------------/         /    \          \---------------------------------'----'
  *                | NAV  | LGUI | /Mous/Ent /      \SYM/Space \  | RGUI | RAlt |
  *                |      |      |/         /        \          \ |      |      |
  *                `-----------------------'          '-------------------------'
  */
  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,                         KC_F6,    KC_F7,    KC_F8,  KC_F9, KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  /* mouse
  * ,---------------------------------------.                        ,-----------------------------.
  * |    |      |      |      |      |      |                        |     |     | MSU |   |   |   |
  * |-------+------+------+------+------+---|                        |------+------+------+--------|
  * |    | BTN2 | ACL0 | ACL1 | ACL2 | BTN1 |                        |     | MSL | MSD | MSR|   |   |
  * |-------+------+------+------+------+---|                        |------+------+------+--------|
  * |    |      | SCl  | SCU  | SCD  | SCR  |.--------.    .---------.     |     |     |   |   |   |
  * `---------------------------------------/         /    \          \----------------------------'
  *                        | NAV  | LGUI | /Mous/Ent /      \SYM/Space \  | RGUI | RAlt |
  *                        |      |      |/         /        \          \ |      |      |
  *                        `-----------------------'          '-------------------------'
  */
  [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BTN2, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN1,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_QWERTY 0
#define L_NAVIGATE 2
#define L_SYMBOLS 4
#define L_NUMPAD 8
#define L_ADJUST 16
#define L_FUNCTION 32

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_QWERTY:
            oled_write_ln_P(PSTR("Qwerty"), false);
            break;
        case L_NAVIGATE:
            oled_write_ln_P(PSTR("Navigate"), false);
            break;
        case L_SYMBOLS:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case L_NUMPAD:
            oled_write_ln_P(PSTR("Numpad"), false);
            break;
        case L_FUNCTION:
            oled_write_ln_P(PSTR("Function"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_NAVIGATE:
        case L_ADJUST|L_SYMBOLS:
        case L_ADJUST|L_NAVIGATE|L_SYMBOLS:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
