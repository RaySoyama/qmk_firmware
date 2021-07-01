/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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
#include "version.h"

enum layers {
    _QWERTY,
    _GAMES,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY,
    GAMES,
    LOWER,
    RAISE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    /* QWERTY
     * .--------------------------------------------------------------.          .--------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | PREV   |          | NEXT   | 6      | 7      | 8      | 9      | 0      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
     * | TAB    | Q      | W      | E      | R      | T      |        |          | PLAY   | Y      | U      | I      | O      | P      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
     * |        | A      | S      | D      | F      | G      |        |          |        | H      | J      | K      | L      | ;      | '      |
     * |--------+--------+--------+--------+--------+--------+--------'          '--------+--------+--------+--------+--------+--------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      |                            | N      | M      | ,      | .      | /      | Return |
     * |--------+--------+--------+--------+--------+--------' .--------.      .--------. '--------|--------+--------+--------+--------+--------|
     * | Control|        |        | LALT   | Windows|          |        |      | GAMES  |          |        | LEFT   | DOWN   | UP     | RIGHT  |
     * '--------------------------------------------'          '--------'      '--------'          '--------------------------------------------'
     *                                       .--------------------------.      .--------------------------.
     *                                       | SPACE  | LOWER  |        |      |        | RAISE  | SPACE  |
     *                                       '--------------------------'      '--------------------------'
     */

    [_QWERTY] = LAYOUT_moonlander(
        KC_ESC,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_MPRV,        KC_MNXT,  KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    _______,        KC_MPLY,  KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_BSPC,
        _______,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    _______,        _______,  KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENT,
        KC_LCTL,  _______,  _______, KC_LALT, KC_LGUI,          _______,        GAMES,             _______, KC_LEFT,  KC_DOWN, KC_UP,    KC_RIGHT,
                                              KC_SPC,  LOWER ,  _______,        _______,  RAISE,  KC_SPC
    ),      

    /* GAMES
     * .--------------------------------------------------------------.          .--------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | PREV   |          | NEXT   | 6      | 7      | 8      | 9      | 0      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
     * | TAB    | Q      | W      | E      | R      | T      | Y      |          | PLAY   | Y      | U      | I      | O      | P      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
     * |        | A      | S      | D      | F      | G      | H      |          |        | H      | J      | K      | L      | ;      | '      |
     * |--------+--------+--------+--------+--------+--------+--------'          '--------+--------+--------+--------+--------+--------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      |                            | N      | M      | ,      | .      | /      | Return |
     * |--------+--------+--------+--------+--------+--------' .--------.      .--------. '--------|--------+--------+--------+--------+--------|
     * | Control|        |        | LALT   | Windows|          |        |      | GAMES  |          |        | LEFT   | DOWN   | UP     | RIGHT  |
     * '--------------------------------------------'          '--------'      '--------'          '--------------------------------------------'
     *                                       .--------------------------.      .--------------------------.
     *                                       | SPACE  | LOWER  |        |      |        | RAISE  | SPACE  |
     *                                       '--------------------------'      '--------------------------'
     */

    [_GAMES] = LAYOUT_moonlander(
        _______,  _______,  _______,  _______,  _______,  _______,   _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,   KC_Y,        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,   KC_H,        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                          _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,            ________,     _______,            _______,  _______,  _______,  _______,  _______,
                                                _______,  _______,  ________,     _______,  _______,  _______
    ),

    /* LOWER
     * .--------------------------------------------------------------.          .--------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | PREV   |          | NEXT   | 6      | 7      | 8      | 9      | 0      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
     * | TAB    | Q      | W      | E      | R      | T      |        |          | PLAY   | Y      | U      | I      | O      | P      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
     * |        | A      | S      | D      | F      | G      |        |          |        | H      | J      | K      | L      | ;      | '      |
     * |--------+--------+--------+--------+--------+--------+--------'          '--------+--------+--------+--------+--------+--------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      |                            | N      | M      | ,      | .      | /      | Return |
     * |--------+--------+--------+--------+--------+--------' .--------.      .--------. '--------|--------+--------+--------+--------+--------|
     * | Control|        |        | LALT   | Windows|          |        |      | GAMES  |          |        | LEFT   | DOWN   | UP     | RIGHT  |
     * '--------------------------------------------'          '--------'      '--------'          '--------------------------------------------'
     *                                       .--------------------------.      .--------------------------.
     *                                       | SPACE  | LOWER  |        |      |        | RAISE  | SPACE  |
     *                                       '--------------------------'      '--------------------------'
     */

    [_LOWER] = LAYOUT_moonlander(
        KC_ESC,   KC_F1,    KC_F2,    KC_3,    KC_4,    KC_5,    KC_MPRV,        KC_MNXT,  KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    _______,        KC_MPLY,  KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_BSPC,
        _______,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    _______,        _______,  KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_LSFT,  _______,  KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENT,
        KC_LCTL,  _______,  _______, KC_LALT, KC_LGUI,          _______,        GAMES,             _______, KC_LEFT,  KC_DOWN, KC_UP,    KC_RIGHT,
                                              KC_SPC,  LOWER ,  _______,        _______,  KC_TAB,  KC_ENT
    ),

    /* RAISE
     * .--------------------------------------------------------------.          .--------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | PREV   |          | NEXT   | 6      | 7      | 8      | 9      | 0      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
     * | TAB    | Q      | W      | E      | R      | T      |        |          | PLAY   | Y      | U      | I      | O      | P      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
     * |        | A      | S      | D      | F      | G      |        |          |        | H      | J      | K      | L      | ;      | '      |
     * |--------+--------+--------+--------+--------+--------+--------'          '--------+--------+--------+--------+--------+--------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      |                            | N      | M      | ,      | .      | /      | Return |
     * |--------+--------+--------+--------+--------+--------' .--------.      .--------. '--------|--------+--------+--------+--------+--------|
     * | Control|        |        | LALT   | Windows|          |        |      | GAMES  |          |        | LEFT   | DOWN   | UP     | RIGHT  |
     * '--------------------------------------------'          '--------'      '--------'          '--------------------------------------------'
     *                                       .--------------------------.      .--------------------------.
     *                                       | SPACE  | LOWER  |        |      |        | RAISE  | SPACE  |
     *                                       '--------------------------'      '--------------------------'
     */

    [_RAISE] = LAYOUT_moonlander(
        KC_ESC,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_MPRV,        KC_MNXT,  KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    _______,        KC_MPLY,  KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_BSPC,
        _______,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    _______,        _______,  KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_LSFT,  _______,  KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENT,
        KC_LCTL,  _______,  _______, KC_LALT, KC_LGUI,          _______,        GAMES,             _______, KC_LEFT,  KC_DOWN, KC_UP,    KC_RIGHT,
                                              KC_SPC,  LOWER ,  _______,        _______,  KC_TAB,  KC_ENT
    ),

    /* ADJUST
     * .--------------------------------------------------------------.          .--------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | PREV   |          | NEXT   | 6      | 7      | 8      | 9      | 0      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
     * | TAB    | Q      | W      | E      | R      | T      |        |          | PLAY   | Y      | U      | I      | O      | P      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
     * |        | A      | S      | D      | F      | G      |        |          |        | H      | J      | K      | L      | ;      | '      |
     * |--------+--------+--------+--------+--------+--------+--------'          '--------+--------+--------+--------+--------+--------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      |                            | N      | M      | ,      | .      | /      | Return |
     * |--------+--------+--------+--------+--------+--------' .--------.      .--------. '--------|--------+--------+--------+--------+--------|
     * | Control|        |        | LALT   | Windows|          |        |      | GAMES  |          |        | LEFT   | DOWN   | UP     | RIGHT  |
     * '--------------------------------------------'          '--------'      '--------'          '--------------------------------------------'
     *                                       .--------------------------.      .--------------------------.
     *                                       | SPACE  | LOWER  |        |      |        | RAISE  | SPACE  |
     *                                       '--------------------------'      '--------------------------'
     */

    [_ADJUST] = LAYOUT_moonlander(
        KC_ESC,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_MPRV,        KC_MNXT,  KC_6,    KC_7,    KC_8,     KC_9,    KC_0,     KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    _______,        KC_MPLY,  KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_BSPC,
        _______,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    _______,        _______,  KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_LSFT,  _______,  KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENT,
        KC_LCTL,  _______,  _______, KC_LALT, KC_LGUI,          _______,        GAMES,             _______, KC_LEFT,  KC_DOWN, KC_UP,    KC_RIGHT,
                                              KC_SPC,  LOWER ,  _______,        _______,  KC_TAB,  KC_ENT
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
            case QWERTY:
                if (record->event.pressed) 
                {
                    set_single_persistent_default_layer(_QWERTY);
                }
          
                return false;   
            case GAMES:
                if (record->event.pressed) 
                {
                    set_single_persistent_default_layer(_GAMES);
                } 
                return false;
        }
        return true;
}