
#ifndef RIPEMD160_H
#define RIPEMD160_H

#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

/** A hasher class for RIPEMD-160. */
class CRIPEMD160
{
private:
    uint32_t s[5];
    unsigned char buf[64];
    uint64_t bytes;

public:
    CRIPEMD160();
    void Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[20]);
};

void ripemd160(unsigned char *input,int length,unsigned char *digest);
void ripemd160_32(unsigned char *input, unsigned char *digest);
void ripemd160sse_32(uint8_t *i0, uint8_t *i1, uint8_t *i2, uint8_t *i3,
  uint8_t *d0, uint8_t *d1, uint8_t *d2, uint8_t *d3);
void ripemd160sse_test();
std::string ripemd160_hex(unsigned char *digest);

static inline bool ripemd160_comp_hash(uint8_t *h0, uint8_t *h1) {
  uint32_t *h0i = (uint32_t *)h0;
  uint32_t *h1i = (uint32_t *)h1;
  return (h0i[0] == h1i[0]) &&
    (h0i[1] == h1i[1]) &&
    (h0i[2] == h1i[2]) &&
    (h0i[3] == h1i[3]) &&
    (h0i[4] == h1i[4]);
}

#endif // RIPEMD160_H
