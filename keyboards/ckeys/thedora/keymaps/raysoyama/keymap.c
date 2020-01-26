#include QMK_KEYBOARD_H

enum layers {
  _BASE,                // base layer
  _FUNCTION,           // Function Layers
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
    //           │         │         │         │         │         │
    //           │         │    0    │         │         │  Bspace │
    //  ROTORY   │         │         │         │         │         │
    //  RIGHT:   ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  VOL UP   │         │         │         │         │         │
    //           │    7    │    8    │    9    │         │         │
    //  ROTORY   │         │         │         │         │         │
    //  LEFT:    ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  VOL DOWN │         │         │         │         │         │
    //           │    6    │    5    │    4    │         │         │
    //           │         │         │         │         │         │
    // ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │         │         │
    // │         │    1    │    2    │    3    │   Func  │  Shift  │
    // │         │         │         │         │         │         │
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

      [_BASE] = LAYOUT(
        KC_NO, KC_0,   KC_9, KC_NO, KC_BSPACE,  KC_MEDIA_PLAY_PAUSE,
        KC_7,  KC_8,   KC_9, KC_NO, KC_NO,
        KC_4,  KC_5,   KC_6, KC_NO, KC_NO,
        KC_1,  KC_2,   KC_3, MO(_FUNCTION),     KC_RSHIFT
      ),

    //           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
    //           │         │         │         │         │         │
    //           │  ResetE │   F10   │         │         │         │
    //  ROTORY   │         │         │         │         │         │
    //  RIGHT:   ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  VOL UP   │         │         │         │         │         │
    //           │   F7    │   F8    │    F9   │         │         │
    //  ROTORY   │         │         │         │         │         │
    //  LEFT:    ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  VOL DOWN │         │         │         │         │         │
    //           │   F6    │   F5    │   F4    │    -    │         │
    //           │         │         │         │         │         │
    // ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │         │         │
    // │         │   F1    │    F2   │   F3    │   Func  │   Symb  │
    // │         │         │         │         │         │         │
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

      [_FUNCTION] = LAYOUT(
        EEPROM_RESET,  KC_F10,  KC_F9, KC_NO, KC_BSPACE,  RESET,
        KC_F7,  KC_F8,   KC_F9, KC_NO, KC_NO,
        KC_F4,  KC_F5,   KC_F6, KC_NO, KC_NO,
        KC_F1,  KC_F2,   KC_F3, KC_NO, KC_RSHIFT
      ),


/*
//           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
//           │         │         │         │         │         │
//           │    7    │    8    │    9    │    /    │  ADMIN  │
//  ROTORY   │         │         │         │         │         │
//  RIGHT:   ├─────────┼─────────┼─────────┼─────────┼─────────┤
//  VOL UP   │         │         │         │         │         │
//           │    4    │    5    │    6    │    *    │  MOUSE  │
//  ROTORY   │         │         │         │         │         │
//  LEFT:    ├─────────┼─────────┼─────────┼─────────┼─────────┤
//  VOL DOWN │         │         │         │         │         │
//           │    1    │    2    │    3    │    -    │  MIDI   │
//           │         │         │         │         │         │
// ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
// │  TOGGLE │         │         │         │         │         │
// │  MUSIC  │    0    │    .    │    =    │    +    │  MUSIC  │
// │         │         │         │         │         │         │
// └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

  [_BASE] = LAYOUT(
    KC_KP_7, KC_KP_8,   KC_KP_9,     KC_PSLS, MO(_ADMIN), MU_TOG,
    KC_KP_4, KC_KP_5,   KC_KP_6,     KC_PAST, TG(_MOUSE),
    KC_KP_1, KC_KP_2,   KC_KP_3,     KC_PMNS, TG(_MIDI),
    KC_KP_0, KC_KP_DOT, KC_KP_EQUAL, KC_PPLS, MO(_MUSIC)
  ),

// MUSIC LAYER
 //          ┌─────────┬─────────┬─────────┬─────────┬─────────┐
 //          │         │         │         │         │         │
 //          │         │         │         │         │         │
 // ROTORY   │         │         │         │         │         │
 // RIGHT:   ├─────────┼─────────┼─────────┼─────────┼─────────┤
 // PAGE UP  │         │         │         │         │         │
 //          │         │         │         │         │         │
 // ROTORY   │         │         │         │         │         │
 // LEFT:    ├─────────┼─────────┼─────────┼─────────┼─────────┤
 // PAGE DOWN│         │         │         │         │         │
 //          │         │         │         │  MODE   │         │
 //          │         │         │         │         │         │
 //┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
 //│         │         │         │         │         │         │
 //│         │ RECORD  │  STOP   │         │  PLAY   │         │
 //│         │         │         │         │         │         │
 //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

  [_MUSIC] = LAYOUT(
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, MU_MOD,
    KC_LCTL, KC_LALT, _______, KC_LGUI, _______
  ),

// MIDI LAYER
//           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
//           │         │         │         │         │         │
//           │   D♯    │    E    │    F    │   F♯    │    G    │
//  ROTORY   │         │         │         │         │         │
//  RIGHT:   ├─────────┼─────────┼─────────┼─────────┼─────────┤
//  PAGE UP  │         │         │         │         │         │
//           │   A♯    │    B    │    C    │   C♯    │    D    │
//  ROTORY   │         │         │         │         │         │
//  LEFT:    ├─────────┼─────────┼─────────┼─────────┼─────────┤
//  PAGE DOWN│         │         │         │         │         │
//           │    F    │   F♯    │    G    │   G♯    │    A    │
//           │         │         │         │         │         │
// ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
// │         │         │         │         │         │         │
// │         │    C    │   C♯    │    D    │   D♯    │    E    │
// │         │         │         │         │         │         │
// └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

  [_MIDI] = LAYOUT(
    MI_Ds_3, MI_E_3,  MI_F_3, MI_Fs_3, MI_G_3, _______,
    MI_As_2, MI_B_2,  MI_C_3, MI_Cs_3, MI_D_3,
    MI_F_2,  MI_Fs_2, MI_G_2, MI_Gs_2, TG(_MIDI),
    MI_C_2,  MI_Cs_2, MI_D_2, MI_Ds_2, MI_E_2
  ),

// MOUSE LAYER
//           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
//           │         │         │         │         │         │
//           │  BTN 5  │         │  WHEEL  │         │         │
//  ROTORY   │         │         │   UP    │         │         │
//  RIGHT:   ├─────────┼─────────┼─────────┼─────────┼─────────┤
//  PAGE DOWN│         │         │         │         │         │
//           │         │  LEFT   │  MOUSE  │  RIGHT  │         │
//  ROTORY   │         │  CLICK  │   UP    │  CLICK  │         │
//  LEFT:    ├─────────┼─────────┼─────────┼─────────┼─────────┤
//  PAGE UP  │         │         │         │         │         │
//           │  BTN 4  │  MOUSE  │  MOUSE  │  MOUSE  │         │
//           │         │  LEFT   │  DOWN   │  RIGHT  │         │
// ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
// │         │         │         │         │         │         │
// │         │  BTN 3  │  WHEEL  │  WHEEL  │  WHEEL  │         │
// │         │         │  LEFT   │  DOWN   │  RIGHT  │         │
// └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

  [_MOUSE] = LAYOUT(
    KC_MS_BTN5, _______,       KC_MS_WH_UP,   _______,        _______,    _______,
    _______,    KC_MS_BTN1,    KC_MS_UP,      KC_MS_BTN2,     TG(_MOUSE),
    KC_MS_BTN4, KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_RIGHT,    _______,
    KC_MS_BTN3, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, _______
  ),

// ADMIN LAYER
//           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
//           │         │         │         │         │         │
//           │  RESET  │         │         │         │         │
//  ROTORY   │         │         │         │         │         │
//  RIGHT:   ├─────────┼─────────┼─────────┼─────────┼─────────┤
//  PAGE UP  │         │         │         │         │         │
//           │    4    │    5    │    6    │    *    │         │
//  ROTORY   │         │         │         │         │         │
//  LEFT:    ├─────────┼─────────┼─────────┼─────────┼─────────┤
//  PAGE DOWN│         │         │         │         │         │
//           │    1    │    2    │    3    │         │         │
//           │         │         │         │         │         │
// ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
// │         │         │         │         │         │         │
// │         │    0    │    .    │    =    │         │         │
// │         │         │         │         │         │         │
// └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

  [_ADMIN] = LAYOUT(
    RESET,   _______, _______, _______, TG(_ADMIN), _______,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______
  ),
*/
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}
