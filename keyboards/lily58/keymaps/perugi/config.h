/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */
#define MASTER_LEFT

/* Tap dance */
#define TAPPING_TERM 150
// #define QUICK_TAP_TERM 0

/* Unicode OS support */
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_WINCOMPOSE

/* Caps word */
#define CAPS_WORD_INVERT_ON_SHIFT

#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 70
#define RGBLED_SPLIT {35, 35}
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

// // Underglow
// #undef RGBLED_NUM
// #define RGBLED_NUM 6 // Number of LEDs
// #define RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_SLEEP
