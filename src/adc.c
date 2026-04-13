#include "adc.h"
#include "hardware/adc.h"
#include "pico/stdlib.h"

void adc_init_all(void) {
    adc_init();
    adc_gpio_init(26); // ADC0 (joystick eixo Y)
    adc_set_temp_sensor_enabled(true);
}

uint16_t adc_read_channel(uint8_t ch) {
    adc_select_input(ch);
    sleep_us(5);
    return adc_read();
}

float read_internal_temperature(void) {
    const float conv = 3.3f / (1 << 12);

    adc_select_input(4);
    uint16_t raw = adc_read();

    float voltage = raw * conv;
    return 27.0f - (voltage - 0.706f) / 0.001721f;
}