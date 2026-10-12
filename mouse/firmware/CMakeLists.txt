Set-Content firmware\CMakeLists.txt -Encoding UTF8 -Value 'cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(m_mouse C CXX ASM)
set(CMAKE_C_STANDARD 11)
pico_sdk_init()
add_executable(m_mouse src/main.c src/sensor.c src/buttons.c src/led.c src/usb_hid.c)
target_link_libraries(m_mouse pico_stdlib hardware_spi tinyusb_device)
pico_enable_stdio_usb(m_mouse 1)
pico_add_extra_outputs(m_mouse)'