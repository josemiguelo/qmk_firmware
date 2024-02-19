/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUMPAD,
    LAYER_NAV,
    LAYER_POINTER,
    LAYER_FUNCTION,
    LAYER_MEDIA,
    LAYER_SYMBOL,
    LAYER_BOOT,
    LAYER_GAMING,
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define POINTER  MO(LAYER_POINTER)
#define MEDIA    MO(LAYER_MEDIA)
#define GAMING   TG(LAYER_GAMING)
#define BOOT     MO(LAYER_BOOT)

#define PT_Z     LT(LAYER_POINTER, KC_Z)
#define PT_SLSH  LT(LAYER_POINTER, KC_SLSH)
#define NAV_SPC  LT(LAYER_NAV, KC_SPC)
#define SYM_ENT  LT(LAYER_SYMBOL, KC_ENT)
#define NUM_TAB  LT(LAYER_NUMPAD, KC_TAB)
#define FUN_DEL  LT(LAYER_FUNCTION, KC_DEL)
#define POI_BSPC LT(LAYER_POINTER, KC_BSPC)

#define SFT_QUOT    LSFT_T(KC_QUOT)

#define SFT_R LSFT_T(KC_R)
#define CTL_E LCTL_T(KC_E)
#define ALT_W LALT_T(KC_W)
#define SFT_U LSFT_T(KC_U)
#define CTL_I LCTL_T(KC_I)
#define ALT_O LALT_T(KC_O)
#define CTL_D LCTL(KC_D)
#define CTL_U LCTL(KC_U)

#define COPY        LCTL(KC_C)
#define PASTE       LCTL(KC_V)
#define CUT         LCTL(KC_X)
#define UNDO        LCTL(KC_Z)
#define QUITWIN     LGUI(KC_Q)
#define NEX_WORK    LCTL(LGUI(KC_J))
#define PRE_WORK    LCTL(LGUI(KC_K))
#define SEND        LCTL(KC_ENT)
#define C_CLICK     LCTL(KC_BTN1)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

#define TAPPING_TERM 200

enum {
  TD_ACCENT = 0,
  TD_TILDE
};

void td_accent (tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    register_code16(KC_RALT);
    register_code16(KC_QUOT);
    unregister_code16(KC_QUOT);
    unregister_code16(KC_RALT);
  } else {
    tap_code(KC_QUOT);
  }
}

void td_tilde (tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    register_code16(KC_RALT);
    register_code16(KC_TILD);
    unregister_code16(KC_TILD);
    unregister_code16(KC_RALT);
  } else {
    tap_code16(KC_TILD);
  }
}

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_ACCENT] = ACTION_TAP_DANCE_FN(td_accent)
 ,[TD_TILDE]  = ACTION_TAP_DANCE_FN(td_tilde)
};


#define TD_QUOT    TD(TD_ACCENT)
#define TD_TILD    TD(TD_TILDE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, KC_LGUI, KC_LCBR, KC_LBRC, KC_LPRN, KC_CAPS,     KC_ENT, KC_RPRN, KC_RBRC, KC_RCBR, KC_LGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    KC_Q,   ALT_W,   CTL_E,   SFT_R,    KC_T,       KC_Y,   SFT_U,   CTL_I,   ALT_O,    KC_P, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_RSFT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       BOOT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,    BOOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                           SYM_ENT, NUM_TAB,    FUN_DEL,NAV_SPC, POI_BSPC,
                                                      MEDIA,    XXXXXXX,  GAMING
  //                                     ╰──────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_NUMPAD] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QUITWIN,    KC_PPLS,    KC_7,    KC_8,    KC_9, KC_PMNS, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,PRE_WORK,NEX_WORK,    KC_ASTR,    KC_4,    KC_5,    KC_6, KC_SLSH, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_COMM,    KC_1,    KC_2,    KC_3,  KC_DOT, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                           XXXXXXX, _______,    XXXXXXX,    KC_0, KC_BSPC,
                                                    XXXXXXX,    XXXXXXX, XXXXXXX
  //                                     ╰──────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_SYMBOL] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,  KC_ESC, KC_PGUP,   KC_UP, KC_PGDN,  KC_SPC,    KC_GRV, KC_EXLM, KC_ASTR, KC_PERC, KC_CIRC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,    KC_DLR,  KC_EQL, KC_UNDS, KC_MINS, TD_QUOT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    UNDO,     CUT,    COPY,   PASTE,  KC_DEL,    KC_HASH,KC_PPLS,   KC_AT, KC_AMPR, KC_DQUO, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                           _______, XXXXXXX,    KC_BSLS, TD_TILD, KC_PIPE,
                                                    XXXXXXX,    XXXXXXX, XXXXXXX
  //                                     ╰──────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_NAV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, XXXXXXX,    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
          SEND, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                            KC_ESC, XXXXXXX,    XXXXXXX, _______, XXXXXXX,
                                                    XXXXXXX,    XXXXXXX, XXXXXXX
  //                                     ╰──────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, C_CLICK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                           XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______,
                                                    XXXXXXX,    XXXXXXX, XXXXXXX
  //                                     ╰──────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_FUNCTION] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                           XXXXXXX, XXXXXXX,    _______, XXXXXXX, XXXXXXX,
                                                    XXXXXXX,    XXXXXXX, XXXXXXX
  //                                     ╰──────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_MEDIA] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    RGB_MOD, KC_VOLU, KC_MPRV, KC_BRIU, XXXXXXX, XXXXXXX,
  // ├───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,   RGB_RMOD, KC_VOLD, KC_MNXT, KC_BRID, XXXXXXX, XXXXXXX,
  // ├───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    RGB_TOG, KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                           _______, _______,    XXXXXXX, XXXXXXX, XXXXXXX,
                                                    XXXXXXX,    XXXXXXX, XXXXXXX
  //                                     ╰──────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_GAMING] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,  KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    XXXXXXX,    KC_U,    KC_I,    KC_O,    KC_Y, XXXXXXX,
  // ├───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX,    KC_Q, XXXXXXX,    KC_E, XXXXXXX,    XXXXXXX,    KC_J,    KC_K,    KC_L,    KC_H, XXXXXXX,
  // ├───────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                              KC_W, XXXXXXX,    XXXXXXX,    KC_J, XXXXXXX,
                                                    XXXXXXX,    _______, XXXXXXX
  //                                     ╰──────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_BOOT] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, S_D_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S_D_MOD, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, DPI_MOD, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT,    QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, DPI_MOD, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                           RGB_TOG, RGB_MOD,    XXXXXXX, RGB_MOD, RGB_TOG,
                                                    RGB_RMOD,   XXXXXXX,RGB_RMOD
  //                                     ╰──────────────────╯ ╰───────────────────────────╯
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

void shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb(RGB_RED);
#endif // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
}
