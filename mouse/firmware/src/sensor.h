#ifndef SENSOR_H
#define SENSOR_H
#include <stdint.h>
#include <stdbool.h>
#define PMW3360_DELTA_X_L 0x03
#define PMW3360_DELTA_X_H 0x04
#define PMW3360_DELTA_Y_L 0x05
#define PMW3360_DELTA_Y_H 0x06
void    sensor_init(void);
bool    sensor_motion_available(void);
int16_t sensor_read_dx(void);
int16_t sensor_read_dy(void);
#endif
