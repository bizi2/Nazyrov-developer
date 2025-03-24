#ifndef MD5FUNC_H
#define MD5FUNC_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long ulong_t;

/* MD5 context. */
typedef struct {
	ulong_t m_state[4];
	ulong_t m_count[2];
	uint8_t m_buffer[64];                         
} MD5Context;

void fnMD5Init(MD5Context* context);
void fnMD5Update(MD5Context* context, uint8_t* input, uint32_t inputLen);
void fnMD5Final(uint8_t digest[16], MD5Context* context);

#endif