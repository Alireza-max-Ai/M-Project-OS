#ifndef USB_HID_H
#define USB_HID_H
#include <stdint.h>
void usb_hid_init(void);
void usb_hid_mouse_move(int16_t dx, int16_t dy);
void usb_hid_mouse_buttons(uint8_t buttons);
#endif