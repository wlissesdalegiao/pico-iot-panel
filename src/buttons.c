#include "buttons.h"
#include "pico/stdlib.h"

// Ponteiro para função do usuário
static void (*user_callback)(uint, uint32_t);

// Controle de debounce
static absolute_time_t last_press = {0};

// Callback da interrupção (ISR)
static void gpio_callback(uint gpio, uint32_t events) {

    // debounce de 200 ms
    if (absolute_time_diff_us(last_press, get_absolute_time()) > 200000) {
        last_press = get_absolute_time();

        if (user_callback != NULL) {
            user_callback(gpio, events);
        }
    }
}

// Inicialização do botão
void buttons_init(uint pin, void (*callback)(uint, uint32_t)) {

    user_callback = callback;

    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_up(pin);

    gpio_set_irq_enabled_with_callback(
        pin,
        GPIO_IRQ_EDGE_FALL,
        true,
        &gpio_callback
    );
}