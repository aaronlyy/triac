#include <triac/socket.h>

#include <stdio.h>
#include <stdbool.h>


struct triac_socket {
  int fd;
  uint16_t port;
  bool non_blocking;
};


int create_server() {
  return 0;
}