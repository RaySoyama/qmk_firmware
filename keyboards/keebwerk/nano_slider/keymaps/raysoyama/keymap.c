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

// Defines names for use in layer keycodes and the keymap
enum layer_names { _BASE, _FN, _DEMO };

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,

    GeForce,
    Record,
    ToggleChannel,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
    {
        [_BASE] = LAYOUT(
            KC_PAUSE,
            GeForce, Record, KC_CAPSLOCK,
            KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, ToggleChannel)
    };

bool channelToggle = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case GeForce:
        if (record->event.pressed)
        {
            SEND_STRING(SS_LCTRL(SS_LALT("a")));
        }
        return false;
        break;

    case Record:
        if (record->event.pressed)
        {
            SEND_STRING(SS_LCTRL(SS_LALT("b")));
        }
        return false;
        break;

    case ToggleChannel:
        if (record->event.pressed)
        {
            if (channelToggle == true)
            {
                channelToggle = false;
            }
            else
            {
                channelToggle = true;
            }
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

uint8_t divisor           = 0;

void    slider(void) {
    if (divisor++) { // only run the slider function 1/256 times it's called
        return;
    }

    uint8_t sliderValue = 0x7F - (analogReadPin(SLIDER_PIN) >> 3);

    if (sliderValue < 10)
    {
        sliderValue = 0;
    }
    else if (sliderValue > 124)
    {
        sliderValue = 127;
    }


    if (channelToggle == true)
    {
        midi_send_cc(&midi_device, 2, 0x3E, sliderValue);
    }
    else
    {
        midi_send_cc(&midi_device, 3, 0x3E, sliderValue);
    }
}   

void matrix_scan_user(void) { slider(); }

bool led_update_user(led_t led_state) { return true; }
