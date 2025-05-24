#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>

#include "triac/socket.h"
#include "triac/constants.h"
#include "triac/types.h"

struct triac_socket {
  triac_socket_file_descriptor_t sfd;
  triac_socket_options_t options;
  triac_socket_host_t host;
  triac_socket_port_t port;
  triac_socket_address_family_t address_family;
  triac_socket_socket_type_t socket_type;
  triac_socket_role_t role;
};

triac_socket_t* triac_socket_alloc() {
  triac_socket_t* ts = malloc(sizeof(triac_socket_t));
  if (!ts) {
    perror("[triac] malloc() failed");
    return NULL;
  }

  // initialize struct with default values
  ts->host[0] = '\0';
  ts->port[0] = '\0';
  ts->options = 0;
  ts->sfd = -1;
  ts->address_family = TRIAC_S_AF_UNSPEC;
  ts->socket_type = TRIAC_S_TCP;
  ts->role = TRIAC_S_ROLE_CLIENT;

  printf("[triac] Socket allocated\n");

  return ts;
}

void triac_socket_set_options(triac_socket_t* ts, triac_socket_options_t options) {
  ts->options = options;
  printf("[triac] Socket options set\n");
}

void triac_socket_set_host(triac_socket_t* ts, triac_socket_host_t host) {
  snprintf(ts->host, sizeof(ts->host), "%s", host);
  printf("[triac] Socket host set\n");
}

void triac_socket_set_port(triac_socket_t* ts, triac_socket_port_t port) {
  snprintf(ts->port, sizeof(ts->port), "%s", port);
  printf("[triac] Socket port set\n");
}

void triac_socket_set_address_family(triac_socket_t* ts, triac_socket_address_family_t af) {
  ts->address_family = af;
  printf("[triac] Socket address family set\n");
}

void triac_socket_set_socket_type(triac_socket_t* ts, triac_socket_socket_type_t socket_type) {
  ts->socket_type = socket_type;
  printf("[triac] Socket socket type set\n");
}

void triac_socket_set_role(triac_socket_t* ts, triac_socket_role_t role) {
  ts->role = role;
  printf("[triac] Socket role set\n");
}

void triac_socket_create(triac_socket_t* ts) {
  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = ts->address_family;
  hints.ai_socktype = ts->socket_type;
  hints.ai_flags = ts->role == TRIAC_S_ROLE_SERVER ? AI_PASSIVE : 0;

  const char* host = ts->host[0] == '\0' && ts->role == TRIAC_S_ROLE_SERVER
    ? "0.0.0.0"
    : ts->host;

  getaddrinfo(host, ts->port, &hints, &res);

  ts->sfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  freeaddrinfo(res);
  printf("[triac] Socket created\n");
}

void triac_socket_configure_options(triac_socket_t* ts) {
  printf("[triac] Socket configured with options\n");
  
}

void triac_socket_connect(triac_socket_t* ts) {
  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = ts->address_family;
  hints.ai_socktype = ts->socket_type;
  hints.ai_flags = ts->role == TRIAC_S_ROLE_SERVER ? AI_PASSIVE : 0;

  const char* host = ts->host[0] == '\0' && ts->role == TRIAC_S_ROLE_SERVER
    ? "0.0.0.0"
    : ts->host;

  int rc = getaddrinfo(host, ts->port, &hints, &res);
  if (rc != 0) {
    fprintf(stderr, "[triac] getaddrinfo: %s\n", gai_strerror(rc));
    return;
  }

  if(connect(ts->sfd, res->ai_addr, res->ai_addrlen) < 0) {
    perror("[triac] Connection failed");
    return;
  }

  freeaddrinfo(res);
  printf("[triac] Socket connected\n");
}

void triac_socket_destroy(triac_socket_t *ts) {
  if (!ts) return;
  if (ts->sfd >= 0) {
    close(ts->sfd);
  }
  free(ts);
  printf("[triac] Socket destroyed\n");
}