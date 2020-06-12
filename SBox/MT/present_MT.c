#include "rand.h"

const uint8_t sbox[16] = {0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2};

static uint8_t masked_sbox[16];

void __attribute__((optimize("unroll-loops"))) sboxf_MT_unrolled(uint8_t in[2], uint8_t out[2])
{
  int i;
  uint8_t rand = in[1];
  uint8_t rand2 = rng() & 15;
  for(i = 0; i < 16; i++)
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
  uint8_t rand2 = rng() & 15;
  for(i = 0; i < 16; i++)
  {
    masked_sbox[i ^ rand] = sbox[i] ^ rand2;
  }
  out[0] = masked_sbox[in[0]];
  out[1] = rand2;
}
