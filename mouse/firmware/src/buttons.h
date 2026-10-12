#ifndef BUTTONS_H
#define BUTTONS_H
#include <stdint.h>
#define BTN_LEFT 0x01
#define BTN_RIGHT 0x02
#define BTN_MIDDLE 0x04
void    buttons_init(void);
uint8_t buttons_read(void);
#endif