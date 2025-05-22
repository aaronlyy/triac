// how to create a simple socket server with triac
#include <triac/socket.h>

#include <stdio.h>

int main() {
  int code = create_server();
  printf("Das ist der Code: %d", code);
}