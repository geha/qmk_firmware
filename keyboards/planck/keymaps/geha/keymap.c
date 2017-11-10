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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _COLEMAK_MDH,
  _LOWER,
  _RAISE,
  _MOVEMENT,
  _MEDIA,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  CLMK_DH,
  LOWER,
  RAISE,
  MOVE,
  MEDIA,
  EXT_PLV,
  ZELDA,
  ONE_UP
};

enum tap_dance_keys {
  TD_UMLS = 0
};

#define KC_AE RALT(KC_Q)
#define KC_OE RALT(KC_P)
#define KC_UE RALT(KC_Y)
#define KC_SS RALT(KC_S)
#define M_FLOAT LCTL(LSFT(KC_9))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Alt | Media|Lower | Bksp |Space |Raise | Move |  Alt |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LGUI, KC_LALT, MEDIA,   LOWER,   KC_BSPC, KC_SPC,  RAISE,   MOVE,    KC_RALT, KC_RGUI, KC_RCTL}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Alt | Media|Lower | Bksp |Space |Raise | Move |  Alt |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LGUI, KC_LALT, MEDIA,   LOWER,   KC_BSPC, KC_SPC,  RAISE,   MOVE,    KC_RALT, KC_RGUI, KC_RCTL}
},

/* Colemak Mod-DH
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Alt | Media|Lower | Bksp |Space |Raise | Move |  Alt |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK_MDH] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LGUI, KC_LALT, MEDIA,   LOWER,   KC_BSPC, KC_SPC,  RAISE,   MOVE,    KC_RALT, KC_RGUI, KC_RCTL}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |   -  |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Del |      |      |   0  |   ,  | Calc |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6,    KC_MINS, KC_ASTR},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,    KC_PLUS, _______},
  {_______, _______, _______, _______, _______, KC_DEL,  _______, _______, KC_0,    KC_COMM, KC_CALC, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Ä  |   Ö  |   Ü  |   ß  |      |      |   -  |   =  |   {  |   }  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   [  |   ]  |      |      |   _  |   +  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Del |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {_______, KC_AE,   KC_OE,   KC_UE,   KC_SS,   _______, _______, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS},
  {_______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, _______},
  {_______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______}
},

/* Movement
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |Pg Up |  Up  |Pg Dn | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Left | Down |Right | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Home |  End |      | Menu |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVEMENT] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_DEL },
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS },
  {_______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  _______, KC_APP,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Media
 * ,-----------------------------------------------------------------------------------.
 * |      | Vol- | Mute | Vol+ |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Prev | Play | Next |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Float|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MEDIA] = {
  {_______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, M_FLOAT, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset| Debug|      |      |      |      |      |      |PrntSc| Scrl |Pause |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|ClmkDH|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   ZELDA,   ONE_UP,  _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, CLMK_DH, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

#ifdef AUDIO_ENABLE
  float zelda_song[][2]  = SONG(ZELDA_PUZZLE);
  float one_up_song[][2] = SONG(ONE_UP_SOUND);
#endif

void dance_umlauts_finished(qk_tap_dance_state_t *state, void *user_data) {
  register_code16(KC_RALT);
  switch (state->count) {
    case 1:
      register_code16(KC_Q);
      break;
    case 2:
      register_code16(KC_P);
      break;
    case 3:
      register_code16(KC_Y);
      break;
    default:
      register_code16(KC_S);
      break;
  }
};

void dance_umlauts_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      unregister_code16(KC_Q);
      break;
    case 2:
      unregister_code16(KC_P);
      break;
    case 3:
      unregister_code16(KC_Y);
      break;
    default:
      unregister_code16(KC_S);
      break;
  }
  unregister_code16(KC_RALT);
};

qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap dance macros for umlauts and sharp s
  [TD_UMLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_umlauts_finished, dance_umlauts_reset)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case CLMK_DH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK_MDH);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case MOVE:
      if (record->event.pressed) {
        layer_on(_MOVEMENT);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_MOVEMENT);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case MEDIA:
      if (record->event.pressed) {
        layer_on(_MEDIA);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_MEDIA);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ZELDA:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(zelda_song);
        #endif
      }
      return false;
      break;
    case ONE_UP:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(one_up_song);
        #endif
      }
      return false;
      break;
  };
  return true;
}
