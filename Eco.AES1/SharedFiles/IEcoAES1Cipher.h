/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoAES1Cipher
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoAES1Cipher
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

#ifndef __I_ECO_AES_1_CIPHER_H__
#define __I_ECO_AES_1_CIPHER_H__

#include "IEcoBase1.h"

/* IEcoAES1Cipher IID = {7D1B1D14-1DB1-489E-85FE-B57B973D49E1} */
#ifndef __IID_IEcoAES1Cipher
static const UGUID IID_IEcoAES1Cipher = {0x01, 0x10, {0x7D, 0x1B, 0x1D, 0x14, 0x1D, 0xB1, 0x48, 0x9E, 0x85, 0xFE, 0xB5, 0x7B, 0x97, 0x3D, 0x49, 0xE1}};
#endif /* __IID_IEcoAES1Cipher */

typedef struct IEcoAES1Cipher* IEcoAES1CipherPtr_t;

typedef struct IEcoAES1CipherVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoAES1CipherPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoAES1CipherPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoAES1CipherPtr_t me);

    /* IEcoAES1Cipher */
    void (ECOCALLMETHOD *SubBytes)(/* in */ IEcoAES1CipherPtr_t me, /* in */ state_t* state);
    void (ECOCALLMETHOD *ShiftRows)(/* in */ IEcoAES1CipherPtr_t me, /* in */ state_t* state);
    void (ECOCALLMETHOD *MixColumns)(/* in */ IEcoAES1CipherPtr_t me, /* in */ state_t* state);
    void (ECOCALLMETHOD *AddRoundKey)(/* in */ IEcoAES1CipherPtr_t me, /* in */ uint8_t round, /* in */ state_t* state, /* in */ uint8_t* roundKey);

} IEcoAES1CipherVTbl, *IEcoAES1CipherVTblPtr_t;

interface IEcoAES1Cipher {
    struct IEcoAES1CipherVTbl *pVTbl;
} IEcoAES1Cipher;


#endif /* __I_ECO_AES_1_CIPHER_H__ */
