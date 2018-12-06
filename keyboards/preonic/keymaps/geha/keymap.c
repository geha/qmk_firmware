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

#include "preonic.h"
#include "action_layer.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK_MDH,
  _LOWER,
  _RAISE,
  _NUMPAD,
  _MOVEMENT,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  CLMK_DH,
  LOWER,
  RAISE,
  MOVE,
  NUMPAD,
  ARROW,
  ZELDA,
  ONE_UP
};

#define KC_AE   RALT(KC_Q)
#define KC_OE   RALT(KC_P)
#define KC_UE   RALT(KC_Y)
#define KC_SS   RALT(KC_S)
#define KC_EURO RALT(KC_5)
#define KC_DEGR RALT(KC_COLN)
#define KC_LCA  LCA(KC_NO)
#define LT_NMPD LT(_NUMPAD, KC_TAB)
#define LT_MOVE LT(_MOVEMENT, KC_COMM)
#define M_FLOAT LCTL(LSFT(KC_9))
#define TG_NMPD ACTION_TAP_DANCE_DUAL_ROLE(KC_LCA, NUMPAD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |NumPad|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Alt | Move |Lower |    Space    |Raise | Move |  Alt |CtlAlt| Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS},
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {LT_NMPD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LGUI, KC_LALT, MOVE,    LOWER,   KC_SPC,  KC_SPC,  RAISE,   MOVE,    KC_RALT, KC_LCA,  KC_RCTL}
},

/* Colemak Mod-DH
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |NumPad|   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Alt | Move |Lower |    Space    |Raise | Move | Alt  | CA/NP| Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK_MDH] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS},
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {LT_NMPD, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LGUI, KC_LALT, MOVE,    LOWER,   KC_SPC,  KC_SPC,  RAISE,   MOVE,    KC_RALT, TG_NMPD, KC_RCTL}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |   &  |   *  |   ~  |      | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |   $  |   %  |   ^  |      | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |   !  |   @  |   #  |   °  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Backspace  |      |      | LAlt |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_AMPR, KC_ASTR, KC_TILD, _______, KC_BSPC},
  {_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_DLR,  KC_PERC, KC_CIRC, _______, KC_DEL },
  {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_EXLM, KC_AT,   KC_HASH, KC_DEGR, _______},
  {_______, _______, _______, _______, _______, KC_BSPC, KC_BSPC, _______, _______, KC_LALT, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   €  |      |      |      |      |      |   `  |   (  |   )  |      | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Ä  |   Ö  |   Ü  |   ß  |      |   _  |   -  |   {  |   }  |      | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   °  |      |      |      |      |   +  |   =  |   [  |   ]  |  ->  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Delete   |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_EURO, _______, _______, _______, _______, _______, KC_GRV,  KC_LPRN, KC_RPRN, _______, KC_BSPC},
  {_______, KC_AE,   KC_OE,   KC_UE,   KC_SS,   _______, KC_UNDS, KC_MINS, KC_LCBR, KC_RCBR, _______, KC_DEL },
  {_______, KC_DEGR, _______, _______, _______, _______, KC_PLUS, KC_EQL , KC_LBRC, KC_RBRC, ARROW,   _______},
  {_______, _______, _______, _______, _______, KC_DEL,  KC_DEL,  _______, _______, _______, _______, _______}
},

/* NumPad + Media
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |   /  |   *  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Prev | Play | Next |  :   |      | Esc  |   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Vol- | Mute | Vol+ |  .   | Calc |      |   4  |   5  |   6  |   +  | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      | Float|  ,   |      |      |   1  |   2  |   3  |   :  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |   ,  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, KC_ASTR, _______},
  {_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_COLN, _______, KC_ESC,  KC_7,    KC_8,    KC_9,    KC_MINS, KC_BSPC},
  {_______, KC_VOLD, KC_MUTE, KC_VOLU, KC_DOT,  KC_CALC, _______, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_DEL },
  {_______, _______, _______, M_FLOAT, KC_COMM, _______, _______, KC_1,    KC_2,    KC_3,    KC_COLN, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_0,    LT_MOVE, KC_DOT,  _______, _______}
},

/* Movement
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Pg Up |  Up  |Pg Dn |      |      |      |      |Pg Up |  Up  |Pg Dn | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Left | Down |Right |      |      |      |  Ins | Left | Down |Right | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Home |  End | Menu |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVEMENT] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_PGUP, KC_UP,   KC_PGDN, _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_BSPC},
  {_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_INS,  KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL },
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  KC_APP,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      | Zelda| OneUp|      |      |      |      |PrntSc| Scrl |Pause |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Aud on|AudOff|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Mus on|MusOff|      |      |      |      |Qwerty|ClmkDH|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|      |      |MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, ZELDA,   ONE_UP,  _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS},
  {_______, AU_ON,   AU_OFF,  _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, MU_ON,   MU_OFF,  MU_MOD,  _______, _______, _______, QWERTY,  CLMK_DH, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  _______, _______, MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE
  float zelda_song[][2]  = SONG(ZELDA_PUZZLE);
  float one_up_song[][2] = SONG(ONE_UP_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
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
        case NUMPAD:
          if (record->event.pressed) {
            layer_on(_NUMPAD);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_NUMPAD);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case ARROW:
          if (record->event.pressed) {
              SEND_STRING("->");
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
      }
    return true;
};
