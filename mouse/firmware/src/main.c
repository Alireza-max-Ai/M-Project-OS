#include "pico/stdlib.h"
#include "sensor.h"
#include "usb_hid.h"
#include "buttons.h"
#include "led.h"

int main(void) {
    stdio_init_all();
    sensor_init();
    buttons_init();
    led_init();
    usb_hid_init();
    led_set_color(255, 255, 255);
    while (true) {
        if (sensor_motion_available()) {
            int16_t dx = sensor_read_dx();
            int16_t dy = sensor_read_dy();
            if (dx || dy) usb_hid_mouse_move(dx, dy);
        }
        usb_hid_mouse_buttons(buttons_read());
        led_update();
        sleep_us(1000);
    }
}
