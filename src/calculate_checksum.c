#include "ft_ping.h"

uint16_t calculate_checksum(unsigned char *buffer, int bytes) {
  uint32_t checksum = 0;
  unsigned char *end = buffer + bytes;

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
