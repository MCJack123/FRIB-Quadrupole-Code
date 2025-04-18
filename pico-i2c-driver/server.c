#include <hardware/gpio.h>
#include <hardware/i2c.h>
#include <pico/binary_info.h>
#include <pico/stdio.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned char sz, cmd, addr, reg;
    int val;
    unsigned char buf[32];
    // Initialize LED
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, true);
    // Initialize USB stdio
    stdio_init_all();
    // Initialize I2C
    i2c_init(i2c0, 100000);
    for (int i = 0; i < 23; i++) gpio_set_function(i, GPIO_FUNC_NULL);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));
    // Wait for serial to be ready
    sleep_ms(2000);
    while (getchar_timeout_us(0) != PICO_ERROR_TIMEOUT);
    gpio_put(PICO_DEFAULT_LED_PIN, true);
    addr = 8;
    while (true) {
        // Read byte from serial
        gpio_put(PICO_DEFAULT_LED_PIN, false);
        val = getchar_timeout_us(0);
        if (val == PICO_ERROR_TIMEOUT) continue;
        // Write byte to I2C
        gpio_put(PICO_DEFAULT_LED_PIN, true);
        unsigned char c = val;
        i2c_write_timeout_us(i2c0, addr, &c, 1, false, 100000);
    }
}
