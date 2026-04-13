#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include <stdint.h>

// Inicializa display SSD1306
void display_init(void);

// Limpa buffer
void display_clear(void);

// Atualiza tela
void display_update(void);

// Escreve string na tela
void display_draw_string(int x, int y, const char *str);

// Tela principal do sistema
void display_main_screen(float temp, uint16_t joy, int pwm, bool wifi_ok, int mode);

#endif