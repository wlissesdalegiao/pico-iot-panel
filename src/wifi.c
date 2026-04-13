#include "wifi.h"
#include "pico/cyw43_arch.h"
//#include "lwipopts.h"

bool connected = false;

void wifi_init_sta(const char *ssid, const char *pass) {
    if (cyw43_arch_init()) return;

    cyw43_arch_enable_sta_mode();

    if (cyw43_arch_wifi_connect_timeout_ms(ssid, pass, CYW43_AUTH_WPA2_AES_PSK, 10000) == 0) {
        connected = true;
    }
}

bool wifi_is_connected() {
    return connected;
}