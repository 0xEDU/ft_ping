#ifndef FT_PING_H
#define FT_PING_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <arpa/inet.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define ICMP_ECHO_CODE 0
#define PACKET_SIZE 64

typedef struct s_icmp_header {
	u_int8_t type;
	u_int8_t code;
	u_int16_t checksum;
	u_int16_t id;
	u_int16_t sequence;
	
	double sending_ts;
	char magic[11];
} icmp_header_t;

struct iphdr {
    unsigned int ihl:4;
    unsigned int version:4;
    u_int8_t tos;
    u_int16_t tot_len;
    u_int16_t id;
    u_int16_t frag_off;
    u_int8_t ttl;
    u_int8_t protocol;
    u_int16_t check;
    u_int32_t saddr;
    u_int32_t daddr;
};

void print_help();
// unsigned short calculate_checksum(void *b, int len);
uint16_t calculate_checksum(unsigned char* buffer, int bytes);

#endif // !FT_PING_H
