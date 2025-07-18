

#ifndef SHA256_H
#define SHA256_H
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void sha256(uint8_t *input,size_t length, uint8_t *digest);
void sha256_33(uint8_t *input, uint8_t *digest);
void sha256_65(uint8_t *input, uint8_t *digest);
void sha256_checksum(uint8_t *input, int length, uint8_t *checksum);
bool sha256_file(const char* file_name, uint8_t* checksum);
void sha256sse_1B(uint32_t *i0, uint32_t *i1, uint32_t *i2, uint32_t *i3,
  uint8_t *d0, uint8_t *d1, uint8_t *d2, uint8_t *d3);
void sha256sse_2B(uint32_t *i0, uint32_t *i1, uint32_t *i2, uint32_t *i3,
  uint8_t *d0, uint8_t *d1, uint8_t *d2, uint8_t *d3);
void sha256sse_checksum(uint32_t *i0, uint32_t *i1, uint32_t *i2, uint32_t *i3,
  uint8_t *d0, uint8_t *d1, uint8_t *d2, uint8_t *d3);
std::string sha256_hex(unsigned char *digest);
void sha256sse_test();

#endif