// Vinokurov Ivan 2024
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct RSA_Public {
	uint32_t m_n;
	uint32_t m_e;
} RSA_Public;

typedef struct RSA_Private {
	// type 1
	uint32_t m_n;
	uint32_t m_d;

	// type 2
	uint32_t m_p;
	uint32_t m_q;
	uint32_t m_dP;
	uint32_t m_dQ;
	uint32_t m_qInv;
	uint32_t m_r_i;
	uint32_t m_d_i;
	uint32_t m_t_i;
} RSA_Private;

uint8_t* fnI20SP(uint32_t input, uint32_t outputLength);

uint32_t fnOS2IP(uint8_t* input);

uint32_t fnRSAEP(RSA_Public input, uint32_t m);

uint32_t fnRSADP(RSA_Private input, uint32_t c, uint8_t* type);