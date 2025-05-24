// example how to create a socket client and connect to a server
#include <stdio.h>

#include "triac/socket.h"
#include "triac/constants.h"

int main() {

  triac_socket_t* client = triac_socket_alloc();

  triac_socket_set_address_family(client, TRIAC_S_AF_UNSPEC);
  triac_socket_set_host(client, "0.0.0.0");
  triac_socket_set_port(client, "3402");
  triac_socket_set_options(client, TRIAC_S_OPT_REUSEADDR);
  
  triac_socket_create(client);
  triac_socket_connect(client);

  triac_socket_destroy(client);
}