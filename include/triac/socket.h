#ifndef TRIAC_SOCKET_H
#define TRIAC_SOCKET_H

// typing stuff
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

// struct that holds a socket information
// it is used to crate a new socket
typedef struct triac_socket triac_socket_t;


/**
 * @brief Creates a new server socket
 *
 * Opens a TCP socket on given port and configures it
 *
 * @param sock Pointer to the socket struct
 * @param port Port that should be used. Should be between 0 and 65535
 * @param non_blocking Non-blocking or blocking
 * @return 0 on success, -1 on error
 */
int triac_socket_create(uint16_t port, bool non_blocking);


// triack_socket_accept
// triac_socket_listen
// triac_socket_close

#endif