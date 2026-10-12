#include "sensor.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SPI_PORT spi0
#define PIN_SCK 2
#define PIN_MOSI 3
#define PIN_MISO 4
#define PIN_CS 5
#define PIN_MOTION 6

static void sw(uint8_t r, uint8_t v) {
    uint8_t b[2] = {r|0x80, v};
    gpio_put(PIN_CS, 0);
    spi_write_blocking(SPI_PORT, b, 2);
    gpio_put(PIN_CS, 1);
    sleep_us(50);
}

static uint8_t sr(uint8_t r) {
    uint8_t t = r & 0x7F, x = 0;
    gpio_put(PIN_CS, 0);
    spi_write_blocking(SPI_PORT, &t, 1);
    sleep_us(35);
    spi_read_blocking(SPI_PORT, 0, &x, 1);
    gpio_put(PIN_CS, 1);
    sleep_us(50);
    return x;
}

void sensor_init(void) {
    spi_init(SPI_PORT, 2000000);
    gpio_set_function(PIN_SCK, GPIO_FUNC_SPI);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
    gpio_init(PIN_CS); gpio_set_dir(PIN_CS, GPIO_OUT); gpio_put(PIN_CS, 1);
    gpio_init(PIN_MOTION); gpio_set_dir(PIN_MOTION, GPIO_IN);
    sw(0x3A, 0x5A);
    sleep_ms(50);
}

bool sensor_motion_available(void) { return gpio_get(PIN_MOTION) == 0; }

int16_t sensor_read_dx(void) {
    return (int16_t)((sr(PMW3360_DELTA_X_H) << 8) | sr(PMW3360_DELTA_X_L));
}

int16_t sensor_read_dy(void) {
    return (int16_t)((sr(PMW3360_DELTA_Y_H) << 8) | sr(PMW3360_DELTA_Y_L));
}