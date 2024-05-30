#ifndef FT_PING_H
#define FT_PING_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <arpa/inet.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_CODE 0

typedef struct s_icmp_header {
	uint8_t type;
	uint8_t code;
	uint16_t checksum;
	uint16_t id;
	uint16_t sequence;
} icmp_header_t;

void print_help();
unsigned short calculate_checksum(void *b, int len);

#endif // !FT_PING_H
