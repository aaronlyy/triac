#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "triac/socket.h"

struct triac_socket_server {
  int fd;
  uint16_t port;
  bool non_blocking;
};

struct triac_socket_client {
  int fd;
  struct sockaddr_in server_address;
};

triac_socket_server_t* triac_socket_server_create(uint16_t port, bool non_blocking) {
  return 0;
}

triac_socket_client_t* triac_socket_client_create(uint16_t port, const char* address) {

  // create new tsc struct
  triac_socket_client_t* tsc = malloc(sizeof(triac_socket_client_t));
  if (!tsc) {
    perror("[triac] malloc() failed");
    return NULL;
  }

  // the socket() function creates a new socket and returns the index pointing at the socket in the socket table of the operating system
  // the function takes the following arguments: TCP or UDP (AF_INET/2 for TCP), SOCK_STREAM (bc TCP), 0 for protocol default
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("[triac] socket() failed");
    free(tsc);
    return NULL;
  }
  tsc->fd = sock;

  // now we configure the socket using the sockaddr_in struct from in.h
  // the struct needs 3 members: sin_family, sin_port, sin_addr
  tsc->server_address.sin_port = port;
  tsc->server_address.sin_family = AF_INET;
  tsc->server_address.sin_port = htons(port); // we use htons() to convert port to the right data format (host to network short)
  // we use inet_pton() (presentation to numeric), to convert the char* to inet_addr_t and directly write it to the struct
  int result = inet_pton(AF_INET, address, &tsc->server_address.sin_addr);
  if (result <= 0) {
    if (result == 0) {
      fprintf(stderr, "[triac] Invalid address given to inet_pton()\n");
    }
    else {
      perror("[triac] inet_pton() failed");
    }
    close(tsc->fd);
    free(tsc);
    return NULL;
  }

  // nothing failed, yay!
  printf("[triac] Client socket created\n");
  return tsc;
}

void triac_socket_client_destroy(triac_socket_client_t *tsc) {
  if (!tsc) return;
  if (tsc->fd >= 0) {
    close(tsc->fd);
  }
  free(tsc);
  printf("[triac] Client socket closed\n");
}