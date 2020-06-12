#ifndef _RAND_H_
#define _RAND_H_
#include <stdint.h>

uint8_t rng()
{
  static unsigned res = 3547683731;
  res *= 342343143105;
  res += 115467341;
  return res >> 24;
}

#endif
