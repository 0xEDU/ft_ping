#ifndef FT_PING_H
#define FT_PING_H

#include <arpa/inet.h>
#include <netdb.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define ICMP_ECHO_CODE 0
#define PACKET_SIZE 64

void print_help();
// unsigned short calculate_checksum(void *b, int len);
uint16_t calculate_checksum(unsigned char *buffer, int bytes);

#endif // !FT_PING_H
