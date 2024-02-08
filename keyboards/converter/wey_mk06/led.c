
#include "stdint.h"
#include "led.h"
#include "quantum.h"

extern void mk06_set_led(uint8_t led);

void led_set(uint8_t usb_led) {
    uint8_t led = 0;

    if (usb_led & !host_keyboard_led_state().scroll_lock)
        led |= 1;
    if (usb_led & !host_keyboard_led_state().num_lock)
        led |= 2;
    if (usb_led & !host_keyboard_led_state().caps_lock)
        led |= 4;

    mk06_set_led(led);
}
