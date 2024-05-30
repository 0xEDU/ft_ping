#include "ft_ping.h"

// unsigned short calculate_checksum(void *b, int len) {
//     unsigned short *buf = b;
//     unsigned int sum = 0;
//
//     // Sum all 16-bit words
//     for (; len > 1; len -= 2)
//         sum += *buf++;
//
//     // If there's a single byte left, pad it with zero
//     if (len == 1)
//         sum += *(unsigned char *)buf;
//
//     // Fold 32-bit sum to 16 bits: add the upper 16 bits to the lower 16 bits
//     while (sum >> 16)
//         sum = (sum & 0xFFFF) + (sum >> 16);
//
//     // Take the one's complement of the sum
//     return ~sum;
// }

uint16_t calculate_checksum(unsigned char* buffer, int bytes) {
    uint32_t checksum = 0;
    unsigned char* end = buffer + bytes;

    // odd bytes add last byte and reset end
    if (bytes % 2 == 1) {
        end = buffer + bytes - 1;
        checksum += (*end) << 8;
    }

    // add words of two bytes, one by one
    while (buffer < end) {
        checksum += buffer[0] << 8;
        checksum += buffer[1];
        buffer += 2;
    }

    // add carry if any
    uint32_t carray = checksum >> 16;
    while (carray) {
        checksum = (checksum & 0xffff) + carray;
        carray = checksum >> 16;
    }

    // negate it
    checksum = ~checksum;

    return checksum & 0xffff;
}
