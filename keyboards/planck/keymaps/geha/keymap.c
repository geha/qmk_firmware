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
#include "keymap_german.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _MOVEMENT,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  MOVE,
  EXT_PLV
};

enum tap_dance_keys {
  TD_AE_OE = 0,
  TD_UE_SS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Move | GUI  |Lower | Bksp |Space |Raise | Move |  Ä Ö |  Ü ß | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    DE_Y,    KC_U,    KC_I,    KC_O,         KC_P,         KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,         DE_SCLN,      KC_ENT },
  {KC_LSFT, DE_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,       DE_SLSH,      DE_DQOT},
  {KC_LCTL, KC_LALT, MOVE,    KC_LGUI, LOWER,   KC_BSPC, KC_SPC,  RAISE,   MOVE,    TD(TD_AE_OE), TD(TD_UE_SS), KC_RCTL}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | GUI  |Lower | Bksp |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    DE_Y,    KC_SCLN, KC_BSPC},
  {KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT },
  {KC_LSFT, DE_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT},
  {KC_LCTL, KC_LALT, KC_LGUI, KC_LGUI, LOWER,   KC_BSPC, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |   \  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |   ?  | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   0  |   ,  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {DE_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6,    DE_BSLS, DE_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,    DE_QST,  KC_INS},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_COMM, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ä  |   ö  |   ü  |   ß  |      |      |   _  |   +  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   -  |   =  |   {  |   }  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Del |      |      |      |   <  |   >  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {DE_GRV,  DE_EXLM, DE_AT,   DE_HASH, DE_DLR,  DE_PERC, DE_CIRC, DE_AMPR, DE_ASTR, DE_LPRN, DE_RPRN, KC_BSPC},
  {_______, DE_AE,   DE_OE,   DE_UE,   DE_SS,   _______, _______, DE_UNDS, DE_PLUS, DE_LBRC, DE_RBRC, _______},
  {_______, _______, _______, _______, _______, _______, _______, DE_MINS, DE_EQL,  DE_LCBR, DE_RCBR, DE_QUOT},
  {_______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, DE_LESS, DE_MORE, _______}
},

/* Movement
 * ,-----------------------------------------------------------------------------------.
 * |      | Home |  Up  | End  | Pg Up|      | Pg Up| Home |  Up  | End  |      | Next |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right| Pg Dn|      | Pg Dn| Left | Down |Right |      | Vol+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Vol- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVEMENT] = {
  {_______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_MNXT},
  {_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_VOLU},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |PrntSc| Scrl |Pause |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      |      |  °   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|PrntSc| Scrl |Pause |      |  ´   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______, _______, DE_RING},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  KC_PSCR, KC_SLCK, KC_PAUS, _______, DE_ACUT},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

#ifdef AUDIO_ENABLE
  // float plover_song[][2]     = SONG(PLOVER_SOUND);
  // float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for single quotation mark and twice for double
  [TD_AE_OE] = ACTION_TAP_DANCE_DOUBLE(DE_AE, DE_OE),
  [TD_UE_SS] = ACTION_TAP_DANCE_DOUBLE(DE_UE, DE_SS)
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
  }
  return true;
}
