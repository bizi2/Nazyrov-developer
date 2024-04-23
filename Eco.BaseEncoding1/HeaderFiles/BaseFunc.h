#ifndef BASEFUNC_H
#define BASEFUNC_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define BASE64_LENGTH(inlen) ((((inlen) + 2) / 3) * 4)
#define BASE32_LENGTH(inlen) (((inlen) * 8 + 4) / 5)
#define BASE16_LENGTH(inlen) (((inlen) * 2 ))

bool fnIsBase64(int8_t ch);

void fnBase64Encode(const int8_t*  in, size_t inlen,
	int8_t*  out, size_t outlen);

size_t fnBase64EncodeAlloc(const int8_t* in, size_t inlen, int8_t* out);

bool fnBase64Decode(const int8_t*  in, size_t inlen,
	int8_t*  out, size_t* outlen);

bool fnBase64DecodeAlloc(const int8_t* in, size_t inlen,
	int8_t** out, size_t* outlen);

#endif /* BASEFUNC_H */