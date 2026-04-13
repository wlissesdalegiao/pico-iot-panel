#ifndef LWIPOPTS_H
#define LWIPOPTS_H

// Sistema sem OS
#define NO_SYS 1

// Socket API (não vamos usar diretamente, mas é seguro manter)
#define LWIP_SOCKET 0
#define LWIP_NETCONN 0

// Memória
#define MEM_ALIGNMENT 4
#define MEM_SIZE 4000

// TCP
#define LWIP_TCP 1
#define TCP_MSS 1460
#define TCP_WND (2 * TCP_MSS)
#define TCP_SND_BUF (2 * TCP_MSS)

// DHCP (importante pro Wi-Fi funcionar)
#define LWIP_DHCP 1

// DNS
#define LWIP_DNS 1

// Debug (opcional)
#define LWIP_DEBUG 0

#endif