#include QMK_KEYBOARD_H

enum uno_keycode { UNO = SAFE_RANGE };

static uint16_t       pressTimer                      = 0xFFFF;
const uint8_t PROGMEM RGBLED_RAINBOW_MOOD_INTERVALS[] = {10, 25, 50};

char maxLetter = 'z';

#define COUNTER X_A

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT(UNO)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UNO:
            if (record->event.pressed) {
                pressTimer = timer_read();
                SEND_STRING(" ");
            } else {
                uint16_t timeElapsed = timer_elapsed(pressTimer);

                if (timeElapsed > 5000) {
                    reset_keyboard();
                }
            }

            break;
    }
    return false;
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(0, 0, 0);
    rgblight_mode(1);
    // rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
}
