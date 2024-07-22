/* Copyright 2018 'Masayuki Sunahara'
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

#define VIAL_KEYBOARD_UID {0xD7, 0x19, 0xB6, 0xB2, 0x7A, 0x8B, 0x83, 0x76}
#define VIAL_UNLOCK_COMBO_ROWS {0,2}
#define VIAL_UNLOCK_COMBO_COLS {0,0}
//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS
#define VIAL_TAP_DANCE_ENTRIES 5
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
