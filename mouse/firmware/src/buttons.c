#include "buttons.h"
#include "pico/stdlib.h"

void buttons_init(void) {
    gpio_init(7); gpio_set_dir(7, GPIO_IN); gpio_pull_up(7);
    gpio_init(8); gpio_set_dir(8, GPIO_IN); gpio_pull_up(8);
    gpio_init(9); gpio_set_dir(9, GPIO_IN); gpio_pull_up(9);
}

uint8_t buttons_read(void) {
    uint8_t s = 0;
    if (!gpio_get(7)) s |= BTN_LEFT;
    if (!gpio_get(8)) s |= BTN_RIGHT;
    if (!gpio_get(9)) s |= BTN_MIDDLE;
    return s;
}