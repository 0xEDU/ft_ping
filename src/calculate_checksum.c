#include "ft_ping.h"

unsigned short calculate_checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;

    // Sum all 16-bit words
    for (; len > 1; len -= 2)
        sum += *buf++;

    // If there's a single byte left, pad it with zero
    if (len == 1)
        sum += *(unsigned char *)buf;

    // Fold 32-bit sum to 16 bits: add the upper 16 bits to the lower 16 bits
    while (sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);

    // Take the one's complement of the sum
    return ~sum;
}
