#include "usb_hid.h"
#include "tusb.h"

void usb_hid_init(void) { tusb_init(); }

void usb_hid_mouse_move(int16_t dx, int16_t dy) {
    if (tud_hid_ready()) tud_hid_mouse_report(0, 0, dx, dy, 0, 0);
}

void usb_hid_mouse_buttons(uint8_t b) {
    if (tud_hid_ready()) tud_hid_mouse_report(0, b, 0, 0, 0, 0);
}