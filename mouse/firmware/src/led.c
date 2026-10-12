#include "led.h"
#include "pico/stdlib.h"

static uint8_t r[LED_COUNT], g[LED_COUNT], b[LED_COUNT];
static uint16_t offset = 0;

void led_init(void) {}

void led_set_color(uint8_t rv, uint8_t gv, uint8_t bv) {
    for (int i = 0; i < LED_COUNT; i++) { r[i]=rv; g[i]=gv; b[i]=bv; }
}

void led_rainbow(void) {
    for (int i = 0; i < LED_COUNT; i++) {
        int hue = (i * 360 / LED_COUNT + offset) % 360;
        int sec = hue / 60;
        int f = hue % 60;
        uint8_t q = 255 - (255 * f / 60);
        uint8_t t = 255 * f / 60;
        switch(sec) {
            case 0: r[i]=255; g[i]=t;   b[i]=0;   break;
            case 1: r[i]=q;   g[i]=255; b[i]=0;   break;
            case 2: r[i]=0;   g[i]=255; b[i]=t;   break;
            case 3: r[i]=0;   g[i]=q;   b[i]=255; break;
            case 4: r[i]=t;   g[i]=0;   b[i]=255; break;
            case 5: r[i]=255; g[i]=0;   b[i]=q;   break;
        }
    }
    offset = (offset + 5) % 360;
}

void led_update(void) { led_rainbow(); }