// example how to create a socket client and connect to a server
#include <stdio.h>
#include "triac/socket.h"

int main() {
  triac_socket_client_t *tsc = triac_socket_client_create(3402, "0.0.0.0");

  printf("wow!\n");

  triac_socket_client_destroy(tsc);
}