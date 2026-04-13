#include "wifi.h"
#include "pico/cyw43_arch.h"
#include <stdio.h>
#include "lwip/netif.h"
#include "lwip/ip4_addr.h"

bool connected = false;

void wifi_init_sta(const char *ssid, const char *pass) {

    printf("Inicializando WiFi...\n");

    if (cyw43_arch_init()) {
        printf("Erro ao iniciar WiFi\n");
        return;
    }

    cyw43_arch_enable_sta_mode();
    sleep_ms(500);

    printf("Conectando a %s...\n", ssid);

    int result = cyw43_arch_wifi_connect_timeout_ms(
        ssid,
        pass,
        CYW43_AUTH_WPA2_AES_PSK,
        15000
    );

    if (result == 0) {
        connected = true;
        printf("WiFi conectado!\n");
    } else {
        printf("Falha ao conectar. Código: %d\n", result);
    }

    if (result == 0) {
        connected = true;

        struct netif *netif = &cyw43_state.netif[0];

        printf("WiFi conectado!\n");
        printf("IP: %s\n", ip4addr_ntoa(&netif->ip_addr));
    }
}

bool wifi_is_connected() {
    return connected;
}