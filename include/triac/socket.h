#ifndef TRIAC_SOCKET_H
#define TRIAC_SOCKET_H

#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

#include <sys/socket.h> // socket(), bind(), accept()
#include <arpa/inet.h> // sockaddr_in, htons, etc.
#include <netinet/in.h> // inet_pton(), inet_ntoa()
#include <unistd.h> // close()

#include "triac/types.h"

/**
 * @brief Allocate and create a new triac socket struct
 * 
 * This function initializes a new struct of type triac_socket_t and set default values to all members.
 *
 *
 * @return Pointer to triac_socket_t or NULL on failure
 */
triac_socket_t* triac_socket_alloc();


/**
 * @brief Sets given options in triac_socket
 *
 * Options are defined as bitmasks, use | for multiple options
 *
 * @param ts Pointer to a triac_socket_t
 * @param options Option constants connected with a bitwise or (|)
 */
void triac_socket_set_options(triac_socket_t* ts, triac_socket_options_t options);


/**
 * @brief Set host on triac socket struct
 *
 * This can be the remote host to connect to or 0.0.0.0 for a server socket
 *
 * @param ts Pointer to a triac_socket_t
 * @param host Host address
 */
void triac_socket_set_host(triac_socket_t* ts, triac_socket_host_t host);


/**
 * @brief Set port on triac socket struct
 *
 * This can be the remote port or a local port for a server socket
 *
 * @param ts Pointer to a triac_socket_t
 * @param port Port
 */
void triac_socket_set_port(triac_socket_t* ts, triac_socket_port_t port);


/**
 * @brief Set address family on triac socket struct
 *
 * This can be TRIAC_AF_IPV4, TRIAC_AF_IPV6 or TRIAC_AF_UNSPEC
 *
 * @param ts Pointer to a triac_socket_t
 * @param af Address family
 */
void triac_socket_set_address_family(triac_socket_t* ts, triac_socket_address_family_t af);


/**
 * @brief Set socket type on triac socket struct
 *
 * This can be TRIAC_S_TCP or TRIAC_S_UDP
 *
 * @param ts Pointer to a triac_socket_t
 * @param type Socket type
 */
void triac_socket_set_socket_type(triac_socket_t* ts, triac_socket_socket_type_t type);

/**
 * @brief Set role on triac socket struct
 *
 * This can be TRIAC_S_ROLE_SERVER, TRIAC_S_ROLE_CLIENT, TRIAC_S_ROLE_REMOTE_CLIENT
 *
 * @param ts Pointer to a triac_socket_t
 * @param type Role
 */
void triac_socket_set_role(triac_socket_t* ts, triac_socket_role_t role);


/**
 * @brief Configures set options on created socket
 *
 *
 *
 * @param ts Pointer to a triac_socket_t
 */
void triac_socket_configure_options(triac_socket_t* ts);


/**
 * @brief Configures and creates socket.
 *
 * Configures given triac socket using getaddrinfo + hints + options and creates it using socket().
 *
 * 
 * @param ts Pointer to a triac_socket_t
 */
void triac_socket_create(triac_socket_t* ts);


/**
 * @brief Connects socket.
 *
 * Connects given socket to set remote address
 *
 * 
 * @param ts Pointer to a triac_socket_t
 */
void triac_socket_connect(triac_socket_t* ts);


void triac_socket_bind(triac_socket_t* ts, triac_socket_host_t host, triac_socket_port_t port);
void triac_socket_listen(triac_socket_t* ts);

/**
 * @brief Destroys active socket
 *
 * Destroys active socket and frees up memory
 *
 * @param ts Pointer to a triac_socket_t
 */
void triac_socket_destroy(triac_socket_t *ts);

#endif