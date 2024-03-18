/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoAES1InvCipher
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoAES1InvCipher
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2023 Ivan Vinokurov. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECO_AES_1_INVERSE_CIPHER_H__
#define __I_ECO_AES_1_INVERSE_CIPHER_H__

#include "IEcoBase1.h"

/* IEcoAES1InvCipher IID = {47258337-CCF4-4A74-9DCA-F20FABD063E8} */
#ifndef __IID_IEcoAES1InvCipher
static const UGUID IID_IEcoAES1InvCipher = {0x01, 0x10, {0x47, 0x25, 0x83, 0x37, 0xCC, 0xF4, 0x4A, 0x74, 0x9D, 0xCA, 0xF2, 0x0F, 0xAB, 0xD0, 0x63, 0xE8}};
#endif /* __IID_IEcoAES1InvCipher */

typedef struct IEcoAES1InvCipher* IEcoAES1InvCipherPtr_t;

typedef struct IEcoAES1InvCipherVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoAES1InvCipherPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoAES1InvCipherPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoAES1InvCipherPtr_t me);

    /* IEcoAES1InvCipher */
    void (ECOCALLMETHOD *InvShiftRows)(/* in */ IEcoAES1InvCipherPtr_t me, /* in */ state_t* state);
    void (ECOCALLMETHOD *InvSubBytes)(/* in */ IEcoAES1InvCipherPtr_t me, /* in */ state_t* state);
    void (ECOCALLMETHOD *InvMixColumns)(/* in */ IEcoAES1InvCipherPtr_t me, /* in */ state_t* state);
    void (ECOCALLMETHOD *AddRoundKey)(/* in */ IEcoAES1InvCipherPtr_t me, /* in */ uint8_t round, /* in */ state_t* state, /* in */ uint8_t* roundKey);

} IEcoAES1InvCipherVTbl, *IEcoAES1InvCipherVTblPtr_t;

interface IEcoAES1InvCipher {
    struct IEcoAES1InvCipherVTbl *pVTbl;
} IEcoAES1InvCipher;


#endif /* __I_ECO_AES_1_INVERSE_CIPHER_H__ */
