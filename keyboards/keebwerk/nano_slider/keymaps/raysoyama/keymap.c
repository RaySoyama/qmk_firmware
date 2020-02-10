/* Copyright 2020 Duckle
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
#include "analog.h"
#include "qmk_midi.h"
#include "rgblight.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names { _BASE, _FN, _DEMO };

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    PowerMute,
    GeForce,
    Record,
    ToggleChannel,
    PrintOneScreen,
};
/*
    PowerMute = Control+Alt+Break
    GeForce = Control+Alt+A
    Record = Control+Alt+B
    ToggleChannel = Switches Slider Midi output from 3 to 4 and back
    PrintOneScreen = Control+Alt+Print

*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_BASE] = LAYOUT(PowerMute, GeForce, Record, PrintOneScreen, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, ToggleChannel)};

bool channelToggle = true;
bool resetToggle   = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PowerMute:
            if (record->event.pressed) {
                if (resetToggle == true) {
                    reset_keyboard();
                } else {
                    SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_PAUSE))));
                }
            }
            return false;
            break;

        case GeForce:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_LALT("a")));
            }
            return false;
            break;

        case Record:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_LALT("b")));
            }
            return false;
            break;

        case ToggleChannel:
            if (record->event.pressed) {
                resetToggle = true;

                if (channelToggle == true) {
                    channelToggle = false;
                    rgblight_sethsv_noeeprom(HSV_RED);
                } else {
                    channelToggle = true;

                    rgblight_sethsv_noeeprom(HSV_BLUE);
                }
            } else {
                resetToggle = false;
            }
            return false;
            break;
        case PrintOneScreen:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_PSCREEN))));
            }
            return false;
            break;
    }

    return true;
}

void matrix_init_user(void) {
    // Set up the ADC for the slider
    analogReference(ADC_REF_POWER);
}

uint8_t divisor = 0;

void slider(void) {
    if (divisor++) {  // only run the slider function 1/256 times it's called
        return;
    }

    uint8_t sliderValue = 0x7F - (analogReadPin(SLIDER_PIN) >> 3);

    if (sliderValue < 20) {
        sliderValue = 0;
    } else if (sliderValue > 124) {
        sliderValue = 127;
    }

    if (channelToggle == true) {
        midi_send_cc(&midi_device, 2, 0x3E, sliderValue);
    } else {
        midi_send_cc(&midi_device, 3, 0x3E, sliderValue);
    }
}

void matrix_scan_user(void) { slider(); }

bool led_update_user(led_t led_state) { return true; }

void keyboard_post_init_user(void) {
    // Call the post init code.
    rgblight_enable_noeeprom();          // enables Rgb, without saving settings
    rgblight_sethsv_noeeprom(HSV_BLUE);  // sets the color to teal/cyan without saving
}
