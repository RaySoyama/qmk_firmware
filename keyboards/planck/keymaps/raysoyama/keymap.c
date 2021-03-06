/* Copyright 2015-2017 Jack Humbert
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


/* make planck/rev6:raysoyama:dfu-util
raysoyama change list
Swapped Esc and Tab
Swapped Backspace for Del on upper and lower layers
Removed alternative keyboard layouts, Davorak, Plover, ect
Removed RGB
Removed Win/Mac Mods
Swapped the ctrl key and func key
made func key the music board key
Removed the audio in and out key

Removed All memory of non QWERTY Layout
Replaced Raise Delete with backspace
Removed ISO shit from raise
Removed Megalo
Added  Git Macros
*/


#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LEAGUE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  GitAdd,
  GitCommit,
  GitPush,

  PerforceCommit,

  PastaOne,
  PastaTwo,

  SongStop,
  SongOne,
  SongTwo,
  SongThree,
  SongFour,
  SongFive,

  LEAGUE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Music| Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, RGB_TOG,   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* LEAGUE
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Win  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_LEAGUE] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_NO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_NO,   KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,  _______, KC_HOME, KC_END,  _______,
    _______, MU_OFF, _______, _______, _______, _______, _______, _______,  _______, KC_VOLD, KC_VOLU, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, MU_OFF, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |RESET |      |      |      |      |      |      |      |      |      |      |Discrd|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |song 1|song 2|song 3|song 4|song 5| STOP |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |GitAdd|GitCmt|GitPus|Perfor|      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET   , _______   , _______   , _______   ,       _______   , _______   , _______, _______, _______,  _______,  QWERTY,  LEAGUE,
    _______ , _______   , _______   , _______   ,       _______   , _______   , _______, _______, _______,  _______,  _______, _______,
    SongOne , SongTwo   , SongThree , SongFour  ,       SongFive  , SongStop  , _______, _______, _______,  _______,  _______, KC_ENT,
    GitAdd  , GitCommit , GitPush   , PerforceCommit ,  _______   , _______   , _______, _______, PastaOne, PastaTwo, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);

 
  float git_add_song[][2]  = SONG(GIT_Song_ADD);
  float git_commit_song[][2]  = SONG(GIT_Song_COMMIT);
  float git_push_song[][2]  = SONG(GIT_Song_PUSH);

  float song_one[][2] = SONG(PLATINUM_DISCO); 
  float song_two[][2] = SONG(RENAI_CIRCULATION);
  float song_three[][2] = SONG(ISABELLAS_LULLABY);
  float song_four[][2] = SONG(CELESTE_FIRSTSTEPS);
  float song_five[][2] = SONG(CELESTE_FIRSTSTEPS);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
  switch (keycode)
  { 
    case QWERTY:
      if (record->event.pressed) 
      {
        set_single_persistent_default_layer(_QWERTY);
      }
      
      return false;
      break;
   
    case LEAGUE:
      if (record->event.pressed) 
      {
        set_single_persistent_default_layer(_LEAGUE);
      }
      
      return false;
      break;

    case GitAdd:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(git_add_song);
        #endif
        SEND_STRING("git add .\n");
      }
      
      return false;
      break;
    
    case GitCommit:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(git_commit_song);
        #endif
        
        SEND_STRING("git commit -m \"\""SS_TAP(X_LEFT));
      }
      
      return false;
      break;
    
    case GitPush:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(git_push_song);
        #endif
        
        SEND_STRING("git push\n");
      }
      
      return false;
      break;
  
    case PerforceCommit:
        if (record->event.pressed)
        {
          #ifdef AUDIO_ENABLE
            stop_all_notes();
            PLAY_SONG(git_push_song);
          #endif

          SEND_STRING("Ray Soyama - ");
        }

      return false;
      break;
        
    //Pasta
    case PastaOne:
      if (record->event.pressed)
      {
        SEND_STRING("You cheated not only the game, but yourself. You didn't grow. You didn't improve. You took a shortcut and gained nothing. You experienced a hollow victory. Nothing was risked and nothing was gained. It's sad that you don't know the difference.");
      }
      
      return false;
      break;
    
    case PastaTwo:
      if (record->event.pressed)
      {
        SEND_STRING("What the fuck did you just fucking say about me, you little bitch? I'll have you know I graduated top of my class in the Navy Seals, and I've been involved in numerous secret raids on Al-Quaeda, and I have over 300 confirmed kills. I am trained in gorilla warfare and I'm the top sniper in the entire US armed forces. You are nothing to me but just another target. I will wipe you the fuck out with precision the likes of which has never been seen before on this Earth, mark my fucking words. You think you can get away with saying that shit to me over the Internet? Think again, fucker. As we speak I am contacting my secret network of spies across the USA and your IP is being traced right now so you better prepare for the storm, maggot. The storm that wipes out the pathetic little thing you call your life. You're fucking dead, kid. I can be anywhere, anytime, and I can kill you in over seven hundred ways, and that's just with my bare hands. Not only am I extensively trained in unarmed combat, but I have access to the entire arsenal of the United States Marine Corps and I will use it to its full extent to wipe your miserable ass off the face of the continent, you little shit. If only you could have known what unholy retribution your little \"clever\" comment was about to bring down upon you, maybe you would have held your fucking tongue. But you couldn't, you didn't, and now you're paying the price, you goddamn idiot. I will shit fury all over you and you will drown in it. You're fucking dead, kiddo.");
      }
      
      return false;
      break;

    //SONGS
    case SongStop:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
      
      return false;
      break;
    
    case SongOne:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(song_one);
        #endif
      }
      
      return false;
      break;
    
    case SongTwo:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(song_two);
        #endif
      }
      
      return false;
      break;
    
    case SongThree:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(song_three);
        #endif
      }
      
      return false;
      break;
    
    case SongFour:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(song_four);
        #endif
      }
      
      return false;
      break;
    
    case SongFive:
      if (record->event.pressed)
      {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(song_five);
        #endif
      }
      
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) 
{
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) 
{
  switch (index) 
  {
    case 0: 
    {
      #ifdef AUDIO_ENABLE
        static bool play_sound = false;
      #endif
      
      if (active) 
      {
        #ifdef AUDIO_ENABLE
          if (play_sound) 
          { 
            PLAY_SONG(plover_song); 
          }
        #endif
        
        layer_on(_ADJUST);
      } 
      else 
      {
        #ifdef AUDIO_ENABLE
          if (play_sound) 
          { 
            PLAY_SONG(plover_gb_song); 
          }
        #endif
        
        layer_off(_ADJUST);
      }
      
      #ifdef AUDIO_ENABLE
        play_sound = true;
      #endif
      
      break;
    }
    
    case 1:
      if (active) 
      {
        muse_mode = true;
      } 
      else 
      {
        muse_mode = false;
      }

    }
}

void matrix_scan_user(void) 
{
  #ifdef AUDIO_ENABLE
    if (muse_mode) 
    {
      if (muse_counter == 0) 
      {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        
        if (muse_note != last_muse_note) 
        {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      
      muse_counter = (muse_counter + 1) % muse_tempo;
    } 
    else
    {
      if (muse_counter) 
      {
        stop_all_notes();
        muse_counter = 0;
      }
    }
  #endif
}

bool music_mask_user(uint16_t keycode) 
{
  switch (keycode) 
  {
    case RAISE:
    
    case LOWER:
      return false;
    
    default:
      return true;
  }
}
