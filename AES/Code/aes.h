#ifndef _AES_H_
#define _AES_H_
#include <stdint.h>

uint8_t state[16][2];
uint8_t ref_state[16];
uint8_t ref_key[16];

void AES_Run(void);
void AES_InitKey();
#endif
