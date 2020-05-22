/*
Copyright (C) 2020 Jocelyn Turcotte <turcotte.j@gmail.com>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"

// Colemak's colon position
#define MY_COLN MOD(MOD_LSHIFT, KC_P)

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSLS, KC_GRV,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RCTL, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LALT, KC_RALT, LAYER_2, LAYER_1, KC_LGUI,                                     KC_SPC,  KC_LEFT, KC_UP,   KC_RGHT, LAYER_1, \
                                                                                                       KC_DOWN \
    )};

void setupKeymap() {

    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______, \
    _______, KC_PGUP, KC_VOLD, KC_MPLY, KC_VOLU, _______, _______, _______, _______, KC_DQUO, KC_LCBR, KC_RCBR, MY_COLN, _______, \
    _______, KC_PGDN, KC_LEFT, KC_UP,   KC_RGHT, KC_DEL,  KC_SPC,  _______, _______, KC_QUOT, KC_LBRC, KC_RBRC, _______, _______, \
    _______, _______, KC_HOME, KC_DOWN, KC_END,  KC_BSPC,                   _______, _______, KC_LT,   KC_GT,   KC_QUES, _______, \
    _______, _______, _______, _______, _______,                                     _______, KC_HOME, KC_PGUP, KC_END,  _______, \
                                                                                                       KC_PGDN \
    );

    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, \
                                                                                                       _______ \
    );

    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
        }
    }

}
