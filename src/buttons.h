#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdint.h>
#include "pico/stdlib.h"

// Inicializa botão com interrupção
void buttons_init(uint pin, void (*callback)(uint, uint32_t));

#endif