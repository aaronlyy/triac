#pragma once

#include <stdint.h>

// socket related types
typedef char triac_socket_host_t[256];
typedef char triac_socket_port_t[16];
typedef int triac_socket_file_descriptor_t; // socket file descriptor
typedef int triac_socket_address_family_t; // address family
typedef int triac_socket_protocol_family_t; // protocol family
typedef int triac_socket_type_t; // socket type
typedef uint32_t triac_socket_options_t; // socket options as bitmask
typedef struct triac_socket triac_socket_t;