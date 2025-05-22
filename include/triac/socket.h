#ifndef TRIAC_SOCKET_H
#define TRIAC_SOCKET_H

#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

#include <sys/socket.h> // socket(), bind(), accept()
#include <arpa/inet.h> // sockaddr_in, htons, etc.
#include <netinet/in.h> // inet_pton(), inet_ntoa()
#include <unistd.h> // close()

typedef struct triac_socket_server triac_socket_server_t;
typedef struct triac_socket_client triac_socket_client_t;

/**
 * @brief Creates a new server socket
 *
 * Opens a TCP socket on given port and configures it
 *
 * @param socket Pointer to the socket struct
 * @param port Port that should be used. Should be between 0 and 65535
 * @param non_blocking Non-blocking or blocking
 * @return triac_socket_server
 */
triac_socket_server_t* triac_socket_server_create(uint16_t port, bool non_blocking);

/**
 * @brief Creates a new client socket and configure it
 *
 * Connects via TCP to given port
 *
 * @param socket Pointer to the socket struct
 * @param port Port to connect to. Should be between 0 and 65535
 * @return triac_socket_client
 */
triac_socket_client_t* triac_socket_client_create(uint16_t port, const char* address);

/**
 * @brief Destroys client socket
 *
 * Destroys client socket and frees up memory
 *
 * @param tsc Pointer to the socket struct
 * @return triac_socket_client
 */
void triac_socket_client_destroy(triac_socket_client_t *tsc);

#endif