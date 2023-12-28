#include "SHA3Func.h"
#define SHA3_CONST(x) x

static const uint64_t g_keccakfRndc[24] = {
    SHA3_CONST(0x0000000000000001UL), SHA3_CONST(0x0000000000008082UL),
    SHA3_CONST(0x800000000000808aUL), SHA3_CONST(0x8000000080008000UL),
    SHA3_CONST(0x000000000000808bUL), SHA3_CONST(0x0000000080000001UL),
    SHA3_CONST(0x8000000080008081UL), SHA3_CONST(0x8000000000008009UL),
    SHA3_CONST(0x000000000000008aUL), SHA3_CONST(0x0000000000000088UL),
    SHA3_CONST(0x0000000080008009UL), SHA3_CONST(0x000000008000000aUL),
    SHA3_CONST(0x000000008000808bUL), SHA3_CONST(0x800000000000008bUL),
    SHA3_CONST(0x8000000000008089UL), SHA3_CONST(0x8000000000008003UL),
    SHA3_CONST(0x8000000000008002UL), SHA3_CONST(0x8000000000000080UL),
    SHA3_CONST(0x000000000000800aUL), SHA3_CONST(0x800000008000000aUL),
    SHA3_CONST(0x8000000080008081UL), SHA3_CONST(0x8000000000008080UL),
    SHA3_CONST(0x0000000080000001UL), SHA3_CONST(0x8000000080008008UL)
};

static const uint8_t g_keccakfRotc[24] = {
    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14, 27, 41, 56, 8, 25, 43, 62,
    18, 39, 61, 20, 44
};

static const uint8_t g_keccakfPiln[24] = {
    10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4, 15, 23, 19, 13, 12, 2, 20,
    14, 22, 9, 6, 1
};

void fnKeccakPermutation(uint64_t p_state[KECCAK_LANE]) {
    int l_round, i, j;
    uint64_t C[5], D;

    for (l_round = 0; l_round < KECCAK_ROUNDS; l_round++) {
        // Шаг Тета
        for (i = 0; i < 5; ++i) {
            C[i] = p_state[i] ^ p_state[i + 5] ^ p_state[i + 10] ^ p_state[i + 15] ^ p_state[i + 20];
        }
        for (i = 0; i < 5; ++i) {
            D = C[(i + 4) % 5] ^ ROTL64(C[(i + 1) % 5], 1);
            for (j = 0; j < 25; j += 5) {
                p_state[j + i] ^= D;
            }
        }

        // Шаг Ро и шаг Пи
        uint64_t current = p_state[1];
        for (i = 0; i < 24; ++i) {
            int l_index = g_keccakfPiln[i];
            uint64_t temp = p_state[l_index];
            p_state[l_index] = ROTL64(current, g_keccakfRotc[i]);
            current = temp;
        }

        // Шаг Кси
        for (j = 0; j < 25; j += 5) {
            for (i = 0; i < 5; i++) {
                C[i] = p_state[j + i];
            }
            for (i = 0; i < 5; i++) {
                p_state[j + i] ^= (~C[(i + 1) % 5]) & C[(i + 2) % 5];
            }
        }

        // Шаг Йота
        p_state[0] ^= g_keccakfRndc[l_round];
    }
}

void fnKeccakInitialize(KeccakState* p_state) {
    memset(p_state->m_state, 0, KECCAK_LANE * sizeof(uint64_t));
    p_state->m_rate = KECCAK_RATE;
    p_state->m_capacity = KECCAK_CAPACITY;
}

void fnKeccakAbsorb(KeccakState* p_state, const uint8_t* p_input, size_t l_input_len) {

}

void fnKeccakSqueeze(KeccakState* p_state, uint8_t* p_output, size_t l_output_len) {

}