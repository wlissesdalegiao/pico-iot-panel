#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#include "adc.h"
#include "pwm.h"
#include "buttons.h"
#include "display.h"
#include "wifi.h"
#include "http_client.h"

typedef enum {
    MODE_MANUAL = 0,
    MODE_AUTO
} system_mode_t;

volatile system_mode_t mode = MODE_MANUAL;

void button_callback(uint gpio, uint32_t events) {
    mode = (mode == MODE_MANUAL) ? MODE_AUTO : MODE_MANUAL;
}

int main() {
    stdio_init_all();
    sleep_ms(2000);

    adc_init_all();
    pwm_init_led(11); // GPIO LED PWM (verde)
    buttons_init(5, button_callback); // botão com interrupção
    display_init();
/*
    // degub display
   
    sleep_ms(5000);
    display_draw_string(0, 0, "TESTE");
    display_update();
    sleep_ms(5000);
*/
    wifi_init_sta("Olele", "87478889");

    while (1) {
        float temp = read_internal_temperature();
        uint16_t joy = adc_read_channel(0);

        int pwm_percent;

        if (mode == MODE_MANUAL) {
            pwm_percent = joy * 100 / 4095;
        } else {
            pwm_percent = (temp > 30) ? 20 : 80;
        }

        pwm_set_percent(pwm_percent);

        display_main_screen(temp, joy, pwm_percent, wifi_is_connected(), mode);

        printf("Temp: %.2f | Joy: %d | PWM: %d%%\n", temp, joy, pwm_percent);

        http_send_data(temp, joy, pwm_percent);

        sleep_ms(1000);
    }
}