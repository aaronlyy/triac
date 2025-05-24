#pragma once

#include <sys/socket.h>

// socket related constants
#define TRIAC_S_AF_IPV4 AF_INET // IPv4 address family
#define TRIAC_S_AF_IPV6 AF_INET6 // IPv6 address family
#define TRIAC_S_AF_UNSPEC AF_UNSPEC // both

#define TRIAC_S_PF_IPV4 PF_INET // IPv4 address family
#define TRIAC_S_PF_IPV6 PF_INET6 // IPv6 address family

#define TRIAC_S_TCP SOCK_STREAM // TCP Socket
#define TRIAC_S_UDP SOCK_DGRAM // UPD Socket

#define TRIAC_S_ROLE_SERVER 0
#define TRIAC_S_ROLE_CLIENT 1
#define TRIAC_S_ROLE_REMOTE_CLIENT 2

#define TRIAC_S_OPT_NONBLOCK (1 << 0)
#define TRIAC_S_OPT_REUSEADDR (1 << 1)
#define TRIAC_S_OPT_KEEPALIVE (1 << 2)
#define TRIAC_S_OPT_TCP_NODELAY (1 << 3)
#define TRIAC_S_OPT_TIMEOUT (1 << 4)
#define TRIAC_S_OPT_REUSEPORT (1 << 5)