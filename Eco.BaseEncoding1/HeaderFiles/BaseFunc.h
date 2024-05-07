#ifndef BASEFUNC_H
#define BASEFUNC_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BASE64_LENGTH_ENCODE(inlen) ((((inlen) + 2) / 3) * 4)
#define BASE32_LENGTH_ENCODE(inlen) ((inlen / 5) * 8 + ((inlen % 5 != 0) ? 8 : 0))
#define BASE16_LENGTH_ENCODE(inlen) (((inlen) * 2 ))

#define BASE64_LENGTH_DECODE(inlen) ((3 * ((inlen) / 4)) + 2)
#define BASE32_LENGTH_DECODE(inlen) ((inlen / 8) * 5 + ((inlen % 8 != 0) ? 5 : 0))
#define BASE16_LENGTH_DECODE(inlen) (((inlen) / 2 ))

bool fnIsBase64(int8_t ch);

void fnBase64Encode(const int8_t*  in, size_t inlen,
	int8_t*  out, size_t outlen);

void fnBase32Encode(int8_t* in, size_t inlen,
	int8_t* out, size_t outlen);

void fnBase16Encode(int8_t* in, size_t inlen,
	int8_t* out, size_t outlen);

void* fnBase64EncodeAlloc(const int8_t* in, size_t* inlen, size_t* outlen);

void* fnBase32EncodeAlloc(const int8_t* in, size_t* inlen, size_t* outlen);

void*  fnBase16EncodeAlloc(const int8_t* in, size_t* inlen, size_t* outlen);

bool fnBase64Decode(const int8_t*  in, size_t inlen,
	int8_t*  out, size_t outlen);

bool fnBase32Decode(const int8_t* in, size_t inlen,
	int8_t* out, size_t outlen);

bool fnBase16Decode(const int8_t* in, size_t inlen,
	int8_t* out, size_t outlen);

void* fnBase64DecodeAlloc(const int8_t* in, size_t* inlen, size_t* outlen);

void* fnBase32DecodeAlloc(const int8_t* in, size_t* inlen, size_t* outlen);

void* fnBase16DecodeAlloc(const int8_t* in, size_t* inlen, size_t* outlen);

#endif /* BASEFUNC_H */