#include "rand.h"

static const uint8_t sbox[64] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7, 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8, 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0, 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13};

static uint8_t masked_sbox[64];

void __attribute__((optimize("unroll-loops"))) sboxf_MT_unrolled(uint8_t in[2], uint8_t out[2])
{
  int i;
  uint8_t rand = in[1];
  uint8_t rand2 = rng() & 63;
  for(i = 0; i < 64; i++)
  {
    masked_sbox[i ^ rand] = sbox[i] ^ rand2;
  }
  out[0] = masked_sbox[in[0]];
  out[1] = rand2;
}

void sboxf_MT(uint8_t in[2], uint8_t out[2])
{
  int i;
  uint8_t rand = in[1];
  uint8_t rand2 = rng() & 63;
  for(i = 0; i < 64; i++)
  {
    masked_sbox[i ^ rand] = sbox[i] ^ rand2;
  }
  out[0] = masked_sbox[in[0]];
  out[1] = rand2;
}
