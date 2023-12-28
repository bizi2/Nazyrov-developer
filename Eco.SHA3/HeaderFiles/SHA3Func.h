#ifndef SHA3FUNC_H
#define SHA3FUNC_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ROTL64(x, y) (((x) << (y)) | ((x) >> (64 - (y))))

#define KECCAK_LANE 25
#define KECCAK_ROUNDS 24
#define KECCAK_CAPACITY 512
#define KECCAK_RATE 1088

typedef struct {
    uint64_t m_state[KECCAK_LANE];
    int m_rate;
    int m_capacity;
} KeccakState;

void fnKeccakInitialize(KeccakState* p_state);
void fnKeccakAbsorb(KeccakState* p_state, uint8_t* p_input, size_t l_input_len);
void fnKeccakSqueeze(KeccakState* p_state, uint8_t* p_output, size_t l_output_len);

#endif
