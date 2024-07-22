/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
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

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

/*enum td_keycodes {
    LT_BTN5,
    LT_BTN3,
    LT_BTN1,
    MDL_SCRL
};

typedef enum {
    NONE,
    UNKNOWN,
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_SINGLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);

void mseBtn5_finished(tap_dance_state_t *state, void *user_data);
void mseBtn5_reset(tap_dance_state_t *state, void *user_data);
void mseBtn3_finished(tap_dance_state_t *state, void *user_data);
void mseBtn3_reset(tap_dance_state_t *state, void *user_data);
void mseBtn1_finished(tap_dance_state_t *state, void *user_data);
void mseBtn1_reset(tap_dance_state_t *state, void *user_data);
void mdlBtn_finished(tap_dance_state_t *state, void *user_data);
void mdlBtn_reset(tap_dance_state_t *state, void *user_data);

bool btn5_held = false;
//uint16_t lt_hold_timer = 0;
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_BTN1, DRAG_SCROLL, KC_BTN3,
          KC_BTN2, KC_BTN5
    ),
    [1] = LAYOUT(
        KC_BTN1, DPI_CONFIG, KC_BTN3,
          MO(2), _______
    ),
    [2] = LAYOUT(
        KC_TAB, _______, KC_SLASH,
          _______, _______
    )
};
/*
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        // Interrupted means some other button was pressed in the tapping term
        if (state->interrupted || !state->pressed) {
            xprintf("SINGLE_TAP\n");
            return SINGLE_TAP;
        } else {
            xprintf("SINGLE_HOLD\n");
            return SINGLE_HOLD;
        }
    }

    if (state->count == 2) {
        if (state->interrupted) {
            xprintf("DOUBLE_SINGLE_TAP\n");
            return DOUBLE_SINGLE_TAP;
        } else if (state->pressed) {
            xprintf("DOUBLE_HOLD\n");
            return DOUBLE_HOLD;
        } else {
            xprintf("DOUBLE_TAP\n");
            return DOUBLE_TAP;
        }

    } else {
        xprintf("UNKNOWN\n");
        return UNKNOWN; // Any number higher than the maximum state value you return above
    }
};

static td_tap_t tap_state05 = {
    .is_press_action = true,
    .state = NONE
};

static td_tap_t tap_state = {
    .is_press_action = true,
    .state = NONE
};

void mseBtn5_finished(tap_dance_state_t *state, void *user_data) {
    tap_state05.state = cur_dance(state);
    switch (tap_state05.state) {
        case SINGLE_HOLD:
            layer_on(1);
            btn5_held = true;
        break;
        default:
        break;
    }
};

void mseBtn5_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state05.state) {
        case SINGLE_TAP:
            tap_code16(KC_BTN4);
        break;
        case SINGLE_HOLD:
            layer_off(1);
            btn5_held = false;
        break;
        case DOUBLE_TAP:
            xprintf(" button 5 double tapped\n");
            tap_code16(KC_BTN5);
        break;
        case NONE:
        break;
        case UNKNOWN:
        break;
        case DOUBLE_SINGLE_TAP:
        break;
        case DOUBLE_HOLD:
        break;
        default:
        break;
        }
        tap_state05.state = NONE;
};

void mseBtn3_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            register_code16(KC_ESC);
        break;
        case SINGLE_HOLD:
            register_code16(KC_COMMA);
        break;
        default:
            register_code16(KC_ESC);
        break;
    }
};

void mseBtn3_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case SINGLE_TAP:
            unregister_code16(KC_ESC);
        break;
        case SINGLE_HOLD:
            unregister_code16(KC_COMMA);
        break;
        default:
            unregister_code16(KC_ESC);
        break;
        }
    tap_state.state = NONE;
    if (!layer_state_is(0) && !btn5_held) {
        layer_clear();
    }
};

void mseBtn1_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            register_code16(KC_ENTER);
        break;
        case SINGLE_HOLD:
            register_code16(KC_DOT);
        break;
        default:
        break;
        }
};

void mseBtn1_reset(tap_dance_state_t *state, void *user_data) {
    switch(tap_state.state) {
        case SINGLE_TAP:
            unregister_code16(KC_ENTER);
        break;
        case SINGLE_HOLD:
            unregister_code16(KC_DOT);
        break;
        default:
        break;
    }
    tap_state.state = NONE;
    if (!layer_state_is(0) && !btn5_held) {
        layer_clear();
    }
};

void mdlBtn_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_HOLD:
            is_drag_scroll = true;
        break;
        default:
        break;
        }
};

void mdlBtn_reset(tap_dance_state_t *state, void *user_data) {
    switch(tap_state.state) {
        case SINGLE_TAP:
            is_drag_scroll = !is_drag_scroll;
        break;
        case SINGLE_HOLD:
            is_drag_scroll = false;
        break;
        default:
        break;
    }
    tap_state.state = NONE;
};

tap_dance_action_t tap_dance_actions[] = {
    [LT_BTN5]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mseBtn5_finished, mseBtn5_reset),
    [LT_BTN3]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mseBtn3_finished, mseBtn3_reset),
    [LT_BTN1]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mseBtn1_finished, mseBtn1_reset),
    [MDL_SCRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mdlBtn_finished, mdlBtn_reset),
};
*/
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_BTN5:
            if (record->event.pressed) {        //when RGB_MACRO is pressed
                lt_hold_timer = timer_read();  //  mark the time it was pressed
                layer_on(1);                //  go to (layer)
            } else {                            //when RGB_MACRO is released
                layer_off(1);               //  leave (layer)
                if (timer_elapsed(lt_hold_timer) < LT_HOLD_LIMIT)
                    tap_code16(KC_BTN5);        //  toggle RGB if held less than RGB_HOLD_LIMIT ms
            }
            break;
        }
    return true;
} */
