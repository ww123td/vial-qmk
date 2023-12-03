/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#define VIAL_KEYBOARD_UID {0xDF, 0x58, 0x75, 0x81, 0x9B, 0x5F, 0xB5, 0x24}

#define VIAL_UNLOCK_COMBO_ROWS {4, 5}
#define VIAL_UNLOCK_COMBO_COLS {4, 5}

#undef SPLIT_OLED_ENABLE
#define SPLIT_ACTIVITY_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
#define SPLIT_POINTING_ENABLE
#define AUTO_MOUSE_TIME 300
#define POINTING_DEVICE_RIGHT

/*#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 6
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_SLEEP
#    ifndef RGBLIGHT_LIMIT_VAL
#    	define RGBLIGHT_LIMIT_VAL 128
#    endif
#endif */

//#define RGB_MATRIX_ENABLE
#ifdef RGB_MATRIX_ENABLE
//#   define RGB_DISABLE_WHEN_USB_SUSPENDED
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 127
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#   define RGB_MATRIX_HUE_STEP 4
#   define RGB_MATRIX_SAT_STEP 4
#   define RGB_MATRIX_VAL_STEP 3
#   define RGB_MATRIX_SPD_STEP 8
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   define RGB_MATRIX_KEYPRESSES
#   define ENABLE_RGB_MATRIX_BREATHING
#   define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#   define ENABLE_RGB_MATRIX_HUE_WAVE
#   define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#   define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_MULTISPLASH // Sets the default mode, if none has been set
#define RGB_MATRIX_DEFAULT_HUE 191 // Sets the default hue value, if none has been set
#define RGB_MATRIX_DEFAULT_SAT 255 // Sets the default saturation value, if none has been set
#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
#define RGB_MATRIX_DEFAULT_SPD 64

#   endif
#define LAYER_STATE_16BIT
#define DYNAMIC_KEYMAP_LAYER_COUNT 16

#define TAPPING_TERM 200

