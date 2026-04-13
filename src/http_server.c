#include "http_server.h"
#include "lwip/tcp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

static float g_temp = 0;
static uint16_t g_joy = 0;
static int g_pwm = 0;
static int remote_mode = 0;

// ================= HTML =================
const char *html_page =
"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
"<!DOCTYPE html><html><head><title>Pico W</title></head>"
"<body><h2>Painel IoT</h2>"
"<p>Temp: <span id='t'></span></p>"
"<p>Joy: <span id='j'></span></p>"
"<p>PWM: <span id='p'></span></p>"
"<input type='range' min='0' max='100' id='slider'>"
"<button onclick='setPWM()'>Enviar</button>"
"<script>"
"function update(){fetch('/data').then(r=>r.json()).then(d=>{"
"t.innerText=d.temp;j.innerText=d.joy;p.innerText=d.pwm;});}"
"function setPWM(){fetch('/set?pwm='+slider.value);}"
"setInterval(update,1000);"
"</script></body></html>";

// ================= DATA JSON =================
void send_json(struct tcp_pcb *tpcb) {
    char json[128];

    sprintf(json,
        "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\n\r\n"
        "{\"temp\":%.1f,\"joy\":%d,\"pwm\":%d}",
        g_temp, g_joy, g_pwm
    );

    tcp_write(tpcb, json, strlen(json), TCP_WRITE_FLAG_COPY);
}

// ================= PARSE =================
void handle_set(char *req) {
    char *p = strstr(req, "pwm=");
    if (p) {
        int val = atoi(p + 4);
        if (val >= 0 && val <= 100) {
            g_pwm = val;
            remote_mode = 1;
        }
    }
}

// ================= CALLBACK =================
static err_t http_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) {

    if (!p) {
        tcp_close(tpcb);
        return ERR_OK;
    }

    char *req = (char *)p->payload;

    if (strstr(req, "GET / ")) {
        tcp_write(tpcb, html_page, strlen(html_page), TCP_WRITE_FLAG_COPY);
    }
    else if (strstr(req, "GET /data")) {
        send_json(tpcb);
    }
    else if (strstr(req, "GET /set")) {
        handle_set(req);

        const char *ok =
        "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nOK";

        tcp_write(tpcb, ok, strlen(ok), TCP_WRITE_FLAG_COPY);
    }

    tcp_recved(tpcb, p->tot_len);
    pbuf_free(p);

    return ERR_OK;
}

// ================= ACCEPT =================
static err_t http_accept(void *arg, struct tcp_pcb *newpcb, err_t err) {
    tcp_recv(newpcb, http_recv);
    return ERR_OK;
}

// ================= INIT =================
void http_server_init(void) {
    struct tcp_pcb *pcb = tcp_new();
    tcp_bind(pcb, IP_ADDR_ANY, 80);

    pcb = tcp_listen(pcb);
    tcp_accept(pcb, http_accept);
}

// ================= API =================
void http_server_update_data(float temp, uint16_t joy, int pwm) {
    g_temp = temp;
    g_joy = joy;

    if (!remote_mode)
        g_pwm = pwm;
}

int http_get_remote_pwm(void) {
    return g_pwm;
}

int http_is_remote_mode(void) {
    return remote_mode;
}