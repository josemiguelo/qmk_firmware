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
  * ,------------------------------.                  ,----------------------------------.
  * |Mouse/~   | Q | W | E | R | T |                  | Y | U | I  | O  |  P |BackSP     |
  * |----------+---+---+---+---+---|                  |---+---+----+----+----+----+------|
  * |LCtrl/Tab | A | S | D | F | G |                  | H | J | K  | L  | ;: |RCtrl/"'"  |
  * |----------+---+---+---+---+---|                  |---+---+----+----+----+----+------|
  * |LShift/Esc| Z | X | C | V | B |                  | N | M | ,< | .> | /? |RShift/"\" |
  * `----------+---+---+---+---+---+-----.  .---------+---+---+----+----+----+-----------'
               | Numpad|  Wind | Nav/Ent |  |Sym/Space| Lalt  | Fn |
               '--------+------+---------'  '---------+-------+----+                          
  */
  [0] = LAYOUT_split_3x6_3(
  LT(6,KC_TILD),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC,
  LCTL_T(KC_TAB),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,   KC_K,    KC_L,  KC_SCLN,  RCTL_T(KC_QUOT),
  LSFT_T(KC_ESC),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  RSFT_T(KC_BSLS),
                                        MO(3), KC_LGUI, LT(1,KC_ENT) , LT(2,KC_SPC), KC_LALT, MO(5)
  ),




  /* navigate
  * ,-------------------------------.                     ,--------------------------------.
  * |      |   |END | UP |HOME |BRIU|                     |VOLU |PGUP| UP |PGDN |   |Del   |
  * |------+---+----+----+-----+----|                     |-----+----+----+-----+---+------:
  * |LCtrl |   |LEFT|DOWN|RIGHT|BRID|                     |VOLD |LEFT|DOWN|RIGHT|   |RCtrl |
  * |------+---+----+----+-----+----|                     |-----+----+----+-----+---+------|
  * |LShift|   | CUT|COPY|PASTE|xxxx|                     |     |PREV |PLAY|NEXT|   |RShift|
  * `----------+---+---+---+---+---+---------.  .---------+---+---+----+----+---+---+------'
                   | Numpad|  Wind |         |  |Sym/Space| Lalt  | Adj |
                   '--------+------+---------'  '---------+-------+-----'                          
  */
  [1] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, KC_END,  KC_UP,   KC_HOME,    KC_BRIU,                KC_VOLU, KC_PGUP, KC_UP,   KC_PGDN,  XXXXXXX, KC_DEL,
    KC_RCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT,   KC_BRID,                KC_VOLD, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, KC_RCTL,
    KC_LSFT, XXXXXXX, KC_CUT,  KC_COPY, KC_PASTE,   XXXXXXX,                XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,  XXXXXXX, KC_RSFT,
                                        _______, _______, XXXXXXX,    _______, _______, MO(4)
  ),




  /* symbols
  * ,-------------------------------.                        ,--------------------------------.
  * |           |   | @ | # | $ | ( |                        | ) | & | * | ` |   |            |
  * |-----------+------+------+-----|                        |------+------+------+------+----|
  * |LCtrl      |   | ~ | - | \ | [ |                        | ] | = | % | ! |   |RCtrl       |
  * |-----------+------+------------|                        |------+--+---+------+------+----|
  * |LShift/ESC |   | / | _ | | | { |                        . } | + | ^ |   |   |RShift      |
  * `-----------+---+---+---+---+---+--------.  .---------+--+---+---+---+---+---+------------'
                   |        |      |         |  |         |       |     |
                   '--------+------+---------'  '---------+-------+-----'                          
  */
  [2] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, KC_AT  ,KC_HASH, KC_DLR , KC_LPRN,                      KC_RPRN, KC_AMPR, KC_ASTR, KC_GRV,  XXXXXXX, XXXXXXX,
      KC_LCTL, XXXXXXX, KC_TILD,KC_MINS, KC_BSLS, KC_LBRC,                      KC_RBRC, KC_EQL,  KC_PERC, KC_EXLM, XXXXXXX, KC_RCTL,
      KC_LSFT, XXXXXXX, KC_SLSH,KC_UNDS, KC_PIPE, KC_LCBR,                      KC_RCBR, KC_PLUS, KC_CIRC, XXXXXXX, XXXXXXX, KC_RSFT,
                                          XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
  ),

  



  /* numpad
  * ,---------------------------.                        ,---------------------------.
  * |       |   |   |   |   | - |                        | + | 7 | 8 | 9 |   |       |
  * |-------+------+------+-----|                        |------+------+-------------|
  * |LCtrl  |   |   |   |   | / |                        | * | 4 | 5 | 6 |   | RCtrl |
  * |-------+------+------+-----|                        |------------+------+-------|
  * |       |   |   |   |   | % |                        . 0 | 1 | 2 | 3 |   |       |
  * `----------+---+---+---+---+---+-----.  .---------+---+---+----+----+----+-------'
               |       |  Wind | Nav/Ent |  |Sym/Space| Lalt  | Fn |
               '--------+------+---------'  '---------+-------+----+                          
  */
  [3] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PMNS,                      KC_PPLS,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS,                      KC_PAST,    KC_4,    KC_5,    KC_6, XXXXXXX, KC_RCTL,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC,                         KC_0,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
                                          XXXXXXX, _______, _______,   _______, _______, _______
  ),





  /* adjust
  * ,--------------------------------.                        ,----------------------.
  * | RESET  |     |     |     |  |  |                        |   |   |   |   |   |  |
  * |-----------+------+------+------|                        |------+------+------+-|
  * | TOGGLE | HUI | SAI | VAI |  |  |                        |   |   |   |   |   |  |
  * |-----------+------+------+------|                        |------+------+------+-|
  * | MOD    | HUD | SAD | VAO |  |  |                        |   |   |   |   |   |  |
  * `-----------+---+---+---+---+---+--------.  .---------+---+---+---+---+---+---+--'
                   |        |      |         |  |         |       |     |
                   '--------+------+---------'  '---------+-------+-----'                          
  */
  [4] = LAYOUT_split_3x6_3(
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
  ),

  




  /* function
  * ,---------------------------------.                       ,--------------------------------.
  * |      | F1  | F2  | F3 | F4 | F5 |                       | F6 | F7 | F8 | F9 | F10 |      |
  * |------+-----+-----+----+----|----|                       |----+----+----+----+-----|------|
  * |LCtrl | F11 | F12 |    |    |    |                       |    |    |    |    |     |LCtrl |
  * |------+-----+-----+----+----+----|                       |----+----+----+----+-----|------|
  * |LShift|     |     |    |    |    |                       |    |    |    |    |     |LShift|
  * `------+-----+-----+----+----+----+---------.   .---------+----+----+----+----+-----+------|
                       | Numpad| Wind | Nav/Ent |   |Sym/Space|   Lalt  |    |
                       '--------+-----+---------'   '---------+---------+----'                          
  */
  [5] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
      KC_LCTL, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL,
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
                                          _______, _______, _______,   _______, _______, XXXXXXX
  ),

  





  /* mouse
  * ,---------------------------------------.                        ,-----------------------------.
  * |    |      |      |      |      |      |                        |     |     |     |    |   |  |
  * |-------+------+------+------+------+---|                        |------+------+------+--------|
  * |    | BTN2 | ACL0 | ACL1 | ACL2 | BTN1 |                        | MSL | MSD | MSU | MSR|   |  |
  * |-------+------+------+------+------+---|                        |------+------+------+--------|
  * |    |      | SCl  | SCU  | SCD  | SCR  |                        |     |     |     |    |   |  |
  * `---------------------------------------------------.  .---------+-----+-----+-----+----+---+--'
                              |        |      |         |  |         |     |     |
                              '--------+------+---------'  '---------+-----+-----'                          
  */
  [6] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_BTN2, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN1,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
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
