#include "pwm.h"
#include "hardware/pwm.h"

static uint slice;
static uint pwm_gpio;

void pwm_init_led(uint pin) {
    pwm_gpio = pin;

    gpio_set_function(pin, GPIO_FUNC_PWM);
    slice = pwm_gpio_to_slice_num(pin);

    pwm_set_clkdiv(slice, 125.0f); // 🔥 IMPORTANTE
    pwm_set_wrap(slice, 255);
    pwm_set_enabled(slice, true);
}

void pwm_set_percent(int percent) {
    if (percent > 100) percent = 100;
    if (percent < 0) percent = 0;

    uint level = percent * 255 / 100;
    pwm_set_gpio_level(pwm_gpio, level);
}