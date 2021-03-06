#include QMK_KEYBOARD_H

enum custom_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    QWERTY = SAFE_RANGE,
    LEAGUE,
    ValorantPasta
};

enum layer_names {
    _QWERTY,
    _LEAGUE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | Print  | ScrLock|  Pause | 6      | 7      | 8      | 9      | 0      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | Insert | Home   | PgUp   | Y      | U      | I      | O      | P      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * |        | A      | S      | D      | F      | G      | Delete | End    | PgDown | H      | J      | K      | L      | ;      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      |        | UP     |        | N      | M      | ,      | .      | /      | Return |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | Control|        | LALT   | Windows| LOWER  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | RAISE  | LEFT   | DOWN   | UP     | RIGHT  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_5x15(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_PSCR,    KC_SLCK,    KC_PAUS,        KC_6,       KC_7,   KC_8,       KC_9,       KC_0,       KC_BSPC,
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_INS,     KC_HOME,    KC_PGUP,        KC_Y,       KC_U,   KC_I,       KC_O,       KC_P,       KC_BSPC,
    _______,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_DEL,     KC_END,     KC_PGDN,        KC_H,       KC_J,   KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
    KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       _______,    KC_UP,      _______,        KC_N,       KC_M,   KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT,
    KC_LCTL,    _______,    KC_LALT,    KC_LGUI,    LOWER,      KC_SPC,     KC_LEFT,    KC_DOWN,    KC_RIGHT,       KC_SPC,     RAISE,  KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT),

     /* LEAGUE
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      |        |        | 6      | 7      | 8      | 9      | 0      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * |        | Q      | W      | E      | R      | T      | Y      |        |        | Y      | U      | I      | O      | P      | Backspc|
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CapsLck| A      | S      | D      | F      | G      | H      |        |        | H      | J      | K      | L      | ;      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      |        |        |        | N      | M      | ,      | .      | /      | Return |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | Control| Windows| LALT   | LOWER  | SPACE  | SPACE  |        |        |        | SPACE  | SPACE  |  RAISE |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_LEAGUE] = LAYOUT_ortho_5x15(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,     KC_NO,    KC_NO,        KC_6,       KC_7,   KC_8,       KC_9,       KC_0,       KC_BSPC,
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,     KC_NO,    KC_NO,        KC_Y,       KC_U,   KC_I,       KC_O,       KC_P,       KC_BSPC,
    _______,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,     KC_NO,    KC_NO,        KC_H,       KC_J,   KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
    KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_NO,    KC_NO,    KC_NO,        KC_N,       KC_M,   KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT,
    KC_LCTL,    _______,    KC_LALT,    KC_NO,      LOWER,      KC_SPC,     KC_LEFT,  KC_DOWN,  KC_RIGHT,     KC_SPC,     RAISE,  KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT),

    /* LOWER
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |        | F1     | F2     | F3     | F4     | F5     | F11    |        | F12    | F6     | F7     | F8     | F9     | F10    |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | ~      |!       | @      | #      | $      | %      |        |        |        | ^      | &      | *      | (      | )      | Del    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        | _      | +      | {      | }      | |      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |     
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_5x15(
    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F11,     _______, KC_F12,  KC_F6,    KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
    KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    _______,    _______, _______, KC_CIRC,  KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DEL,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,  KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_PIPE, 
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,  _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,  _______,    _______,    _______,    _______,    _______),

    /* RAISE
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | `      | 1      | 2      | 3      | 4      |  5     |        |        |        | 6      |  7     | 8      | 9      | 0      |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |       |         |        |        |        |        |        |        |        | -      | =      | [      | ]      | \      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_5x15(
    _______,    _______, _______,   _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_GRV,     KC_1,    KC_2,      KC_3,       KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    RAISE,      KC_HOME, KC_PGDN,   KC_END,     _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______,    _______, _______,   _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,    _______, _______,   _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* ADJUST
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | RESET  |        |        |        |        |        |        |        |        |rgbplain|rgbtest | rgbmode|        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |rgb tog | bl_tog |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | rgb hi | rgb sai|rgb vai | bl inc |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | rgb hd | rgb sad|rgb vad | bl dec |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_5x15(
    RESET,      EEP_RST, _______, _______, _______,     _______,    _______, _______, _______,  RGB_M_P, RGB_M_T, RGB_MOD, _______, QWERTY,  LEAGUE,
    _______,    _______, _______, _______, RGB_TOG,     BL_TOGG,    _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______,    _______, RGB_HUI, RGB_SAI, RGB_VAI,     BL_INC,     _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______,    _______, RGB_HUD, RGB_SAD, RGB_VAD,     BL_DEC,     _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    ValorantPasta,    _______, _______, _______, _______,     _______,    _______, _______, _______,  _______, _______, _______, _______, _______, _______),

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
        case LEAGUE:
            if (record->event.pressed) 
            {
                set_single_persistent_default_layer(_LEAGUE);
            } 
            return false;
        case ValorantPasta:
            if (record->event.pressed)
            {
                SEND_STRING("To be clear, in Valorant, shooting matters. You dont kill with abilities. Abilities create tactical opportunities to take the right shot. Characters have abilities that augment their gunplay, instead of fighting directly with their abilities.");
            }
            return false;
    }
    return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
