#ifndef PWM_H
#define PWM_H

#include <stdint.h>
#include "pico/stdlib.h"

// Inicializa PWM no pino especificado
void pwm_init_led(uint pin);

// Define duty cycle em porcentagem (0–100)
void pwm_set_percent(int percent);

#endif