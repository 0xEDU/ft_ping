#ifndef FT_PING_H
#define FT_PING_H

#include <arpa/inet.h>
#include <netdb.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct s_host {
  struct sockaddr_in addr;
  char ip_str[INET_ADDRSTRLEN];
} t_host;

void print_help();
uint16_t calculate_checksum(unsigned char *buffer, int bytes);

#endif // !FT_PING_H
