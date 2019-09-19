#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#ifdef AUDIO_ENABLE
    // #define STARTUP_SONG SONG(PREONIC_SOUND)
    #define STARTUP_SONG SONG(NO_SOUND)
    #define GOODBYE_SONG SONG(NO_SOUND)
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// time in ms for tap dances to register
#define TAPPING_TERM 150

// modifiers are cleared on layer change (weak modifiers)
#define PREVENT_STUCK_MODIFIERS

// https://docs.qmk.fm/feature_advanced_keycodes.html#permissive-hold
#define PERMISSIVE_HOLD

// Sets the delay between `register_code` and `unregister_code`, if you're having issues with it registering properly (common on VUSB boards). The value is in milliseconds.
// Used for volume change on rotary knob
#define TAP_CODE_DELAY 20

#define ENCODER_RESOLUTION 2

#define MOUSEKEY_MOVE_DELTA 4
#define MOUSEKEY_DELAY 200              // Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL 16            // Time between cursor movements
#define MOUSEKEY_MAX_SPEED 10           // Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX 90         // Time until maximum cursor speed is reached
#define MOUSEKEY_WHEEL_MAX_SPEED 2      // Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX 120  // Time until maximum scroll speed is reached

#endif
