#ifndef SHA3FUNC_H
#define SHA3FUNC_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ROTL64(x, y) (((x) << (y)) | ((x) >> (64 - (y))))

#define SHA3_LANE 25
#define SHA3_ROUNDS 24
#define SHA3_WIDTH  200

#if defined(SHA3_256) && (SHA3_256 == 1)
#define SHA3_RATE   136 
#define SHA3_MD_LEN 32
#elif defined(SHA3_384) && (SHA3_384 == 1)
#define SHA3_RATE 104
#define SHA3_MD_LEN 48
#else
#define SHA3_RATE 72
#define SHA3_MD_LEN 64
#endif

typedef struct {
    union {
        uint64_t m_words[SHA3_LANE];
        uint8_t m_bytes[SHA3_WIDTH];
    } m_state;
    int m_padpoint;
    int m_absorbed;
} KeccakState;

void fnKeccakAbsorb(KeccakState* p_state, uint8_t* p_input, size_t l_input_len);
void fnKeccakSqueeze(KeccakState* p_state, uint8_t* p_output);
void fnSHA3Digest(uint8_t* p_data, uint64_t n, uint8_t* p_digest);

#endif
