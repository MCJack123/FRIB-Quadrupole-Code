#include "drivers/st7789/st7789.hpp"
#include "common/pimoroni_bus.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "hardware/i2c.h"
#include "mcp3428.hpp"

#define DIST_BOARD_ADDR 8

static pimoroni::ST7789 display(320, 240, pimoroni::Rotation::ROTATE_0, false, pimoroni::get_spi_pins(pimoroni::BG_SPI_FRONT));
static uint8_t framebuf[320 * 240 * 2];
static pimoroni::PicoGraphics_PenRGB565 graphics(320, 240, framebuf);
static uint8_t bars[8];
static const char * const titles[8] = {
    "Channel 1 Attenuation",
    "Channel 1 Phase Shift",
    "Channel 2 Attenuation",
    "Channel 2 Phase Shift",
    "Channel 3 Attenuation",
    "Channel 3 Phase Shift",
    "Channel 4 Attenuation",
    "Channel 4 Phase Shift"
};
static bool button_state[4] = {true, true, true, true};
static int selected = 0;
static MCP3428 * adc;

static void render() {
    graphics.set_pen(0, 0, 0);
    graphics.clear();
    for (int i = 0; i < 8; i++) {
        graphics.set_pen(255, 255, 255);
        if (selected == i) {
            graphics.rectangle(pimoroni::Rect(0, i * 30, 320, 30));
            graphics.set_pen(0, 0, 0);
        }
        graphics.text(titles[i], pimoroni::Point(8, i * 30 + 2), 304);
        graphics.rectangle(pimoroni::Rect(8, i * 30 + 17, 303, 10));
        if (selected == i) {
            if (bars[i] > 0) {
                graphics.set_pen(255, 255, 255);
                graphics.rectangle(pimoroni::Rect(9, i * 30 + 18, 43.142 * bars[i], 8));
            }
        } else {
            if (bars[i] < 7) {
                graphics.set_pen(0, 0, 0);
                graphics.rectangle(pimoroni::Rect(9 + 43.142 * bars[i], i * 30 + 18, 43.142 * (7 - bars[i]), 8));
            }    
        }
    }
    display.update(&graphics);
}

static void update(int id = selected) {
    uint8_t data = id << 5 | bars[id] << 2;
    i2c_write_timeout_us(i2c0, DIST_BOARD_ADDR, &data, 1, false, 100000);
}

int main() {
    gpio_init(12); gpio_set_dir(12, GPIO_IN); gpio_set_pulls(12, true, false);
    gpio_init(13); gpio_set_dir(13, GPIO_IN); gpio_set_pulls(13, true, false);
    gpio_init(14); gpio_set_dir(14, GPIO_IN); gpio_set_pulls(14, true, false);
    gpio_init(15); gpio_set_dir(15, GPIO_IN); gpio_set_pulls(15, true, false);
    gpio_init(4); gpio_set_dir(4, GPIO_OUT); gpio_set_function(4, GPIO_FUNC_I2C); gpio_set_pulls(4, true, false);
    gpio_init(5); gpio_set_dir(5, GPIO_OUT); gpio_set_function(5, GPIO_FUNC_I2C); gpio_set_pulls(5, true, false);
    i2c_init(i2c0, 100000);
    adc = new MCP3428(0x68);
    render();
    display.set_backlight(255);
    while (true) {
        if (!gpio_get(12) && button_state[0]) { // A
            selected = (selected - 1) % 8;
            render();
        }
        button_state[0] = gpio_get(12);
        if (!gpio_get(13) && button_state[1]) { // B
            selected = (selected + 1) % 8;
            render();
        }
        button_state[1] = gpio_get(13);
        if (!gpio_get(14) && button_state[2]) { // X
            if (bars[selected] < 7) {
                bars[selected]++;
                update();
            }
            render();
        }
        button_state[2] = gpio_get(14);
        if (!gpio_get(15) && button_state[3]) { // Y
            if (bars[selected] > 0) {
                bars[selected]--;
                update();
            }
            render();
        }
        button_state[3] = gpio_get(15);
        uint8_t changed = adc->scan();
        if (changed & 1) {
            bars[0] = (uint16_t)adc->get(0) >> 12;
            update(0);
        }
        if (changed & 2) {
            bars[1] = (uint16_t)adc->get(1) >> 12;
            update(1);
        }
        if (changed & 4) {
            bars[2] = (uint16_t)adc->get(2) >> 12;
            update(2);
        }
        if (changed & 8) {
            bars[3] = (uint16_t)adc->get(3) >> 12;
            update(3);
        }
        if (changed) render();
        sleep_ms(100);
    }
    return 0;
}