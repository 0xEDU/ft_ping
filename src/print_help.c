#include "ft_ping.h"

void print_help() {
  printf("Usage: ft_ping [OPTION...] HOST ...\n");
  printf("Send ICMP ECHO_REQUEST packets to network hosts.\n\n");
  printf(" Options valid for all request types:\n\n");
  printf("  -v       verbose output\n\n");
  printf(" Print this message:\n\n");
  printf("  -?       give this help list\n\n");
  printf("Made with love by Edu :)\n");
  exit(EXIT_SUCCESS);
}
