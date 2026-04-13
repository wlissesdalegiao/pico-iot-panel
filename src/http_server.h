#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <stdint.h>
#include <stdint.h>

// Inicializa servidor HTTP
void http_server_init(void);

// Atualiza dados que serão enviados à página
void http_server_update_data(float temp, uint16_t joy, int pwm);

// Retorna PWM definido remotamente
int http_get_remote_pwm(void);

// Verifica se modo remoto está ativo
int http_is_remote_mode(void);

#endif