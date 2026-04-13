#ifndef WIFI_H
#define WIFI_H

#include <stdbool.h>

// Inicializa Wi-Fi no modo station
void wifi_init_sta(const char *ssid, const char *password);

// Retorna status de conexão
bool wifi_is_connected(void);

#endif