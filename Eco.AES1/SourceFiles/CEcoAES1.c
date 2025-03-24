/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoAES1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoAES1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2023 Ivan Vinokurov. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoAES1.h"


static const uint8_t g_sbox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };

static const uint8_t g_rsbox[256] = {
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d };

static const uint8_t g_Rcon[11] = {
    0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 };


static uint8_t fnXTime(uint8_t _x) {
    return ((_x << 1) ^ (((_x >> 7) & 1) * 0x1b));
}

static uint8_t fnGetSBoxValue(uint8_t _index) {
    return g_sbox[_index];
}

static uint8_t fnGetSBoxInvertValue(uint8_t _index) {
    return g_rsbox[_index];
}

static uint8_t fnMultiply(uint8_t _x, uint8_t _y) {
    return (((_y & 1) * _x) ^
            ((_y >> 1 & 1) * fnXTime(_x)) ^
            ((_y >> 2 & 1) * fnXTime(fnXTime(_x))) ^
            ((_y >> 3 & 1) * fnXTime(fnXTime(fnXTime(_x)))) ^
            ((_y >> 4 & 1) * fnXTime(fnXTime(fnXTime(fnXTime(_x))))));
}

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoAES1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoAES1_QueryInterface(/* in */ IEcoAES1Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoAES1) ) {
        *ppv = &pCMe->m_pVTblIAES;
        pCMe->m_pVTblIAES->AddRef((IEcoAES1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoAES1Cipher) ) {
        *ppv = &pCMe->m_pVTblIAESCipher;
        pCMe->m_pVTblIAES->AddRef((IEcoAES1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoAES1InvCipher) ) {
        *ppv = &pCMe->m_pVTblIAESInvCipher;
        pCMe->m_pVTblIAES->AddRef((IEcoAES1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIAES;
        pCMe->m_pVTblIAES->AddRef((IEcoAES1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoAES1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoAES1_AddRef(/* in */ IEcoAES1Ptr_t me) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoAES1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoAES1_Release(/* in */ IEcoAES1Ptr_t me) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoAES1((IEcoAES1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция get_KeySize
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoAES1_get_KeySize(/* in */ IEcoAES1Ptr_t me) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Nk;
}

/*
 *
 * <сводка>
 *   Функция set_KeySize
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_set_KeySize(/* in */ IEcoAES1Ptr_t me, /* in */ uint32_t keySize) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    pCMe->m_Nk = keySize;
}

/*
 *
 * <сводка>
 *   Функция get_BlockSize
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoAES1_get_BlockSize(/* in */ IEcoAES1Ptr_t me) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Nb;
}

/*
 *
 * <сводка>
 *   Функция set_BlockSize
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_set_BlockSize(/* in */ IEcoAES1Ptr_t me, /* in */ uint32_t blockSize) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    pCMe->m_Nb = blockSize;
}

/*
 *
 * <сводка>
 *   Функция get_Mode
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint8_t ECOCALLMETHOD CEcoAES1_get_Mode(/* in */ IEcoAES1Ptr_t me) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_iMode;
}

/*
 *
 * <сводка>
 *   Функция set_Mode
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_set_Mode(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t mode) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    pCMe->m_iMode = mode;
}

/*
 *
 * <сводка>
 *   Функция get_Padding
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint8_t ECOCALLMETHOD CEcoAES1_get_Padding(/* in */ IEcoAES1Ptr_t me) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_iPaddingMode;
}

/*
 *
 * <сводка>
 *   Функция set_Padding
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_set_Padding(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t paddingMode) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    pCMe->m_iPaddingMode = paddingMode;
}

/*
 *
 * <сводка>
 *   Функция get_Key
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint8_t* ECOCALLMETHOD CEcoAES1_get_Key(/* in */ IEcoAES1Ptr_t me) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_pKey;
}

/*
 *
 * <сводка>
 *   Функция set_Key
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_set_Key(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t* key) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    pCMe->m_pKey = key;
}

/*
 *
 * <сводка>
 *   Функция get_IV
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint8_t* ECOCALLMETHOD CEcoAES1_get_IV(/* in */ IEcoAES1Ptr_t me) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_pIV;
}

/*
 *
 * <сводка>
 *   Функция set_IV
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_set_IV(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t* iv) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    pCMe->m_pIV = iv;
}

/*
 *
 * <сводка>
 *   Функция Encrypt
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoAES1_Encrypt(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t* input, /* out */ uint8_t** output) {
    CEcoAES1* pCMe = (CEcoAES1*)me;
    uint8_t l_round = 0;
    uint8_t* _roundKey = 0;
    state_t* _state =  (state_t*)input;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

   // fnCipher((state_t*)_buf, _roundKey);



    pCMe->m_pVTblIAESCipher->AddRoundKey((IEcoAES1CipherPtr_t)&pCMe->m_pVTblIAESCipher, l_round, _state, _roundKey);

    // Всего Nr раундов, первые Nr - 1 из них - одинаковые.
    for (l_round = 1; l_round < pCMe->m_Nr; ++l_round) {
        pCMe->m_pVTblIAESCipher->SubBytes((IEcoAES1CipherPtr_t)&pCMe->m_pVTblIAESCipher, _state);
        pCMe->m_pVTblIAESCipher->ShiftRows((IEcoAES1CipherPtr_t)&pCMe->m_pVTblIAESCipher, _state);
        pCMe->m_pVTblIAESCipher->MixColumns((IEcoAES1CipherPtr_t)&pCMe->m_pVTblIAESCipher, _state);
        pCMe->m_pVTblIAESCipher->AddRoundKey((IEcoAES1CipherPtr_t)&pCMe->m_pVTblIAESCipher, l_round, _state, _roundKey);
    }

    // Последний раунд. Здесь fnMixColumns не используется.
    pCMe->m_pVTblIAESCipher->SubBytes((IEcoAES1CipherPtr_t)&pCMe->m_pVTblIAESCipher, _state);
    pCMe->m_pVTblIAESCipher->ShiftRows((IEcoAES1CipherPtr_t)&pCMe->m_pVTblIAESCipher, _state);
    pCMe->m_pVTblIAESCipher->AddRoundKey((IEcoAES1CipherPtr_t)&pCMe->m_pVTblIAESCipher, pCMe->m_Nr, _state, _roundKey);
    return 0;

}

/*
 *
 * <сводка>
 *   Функция Decrypt
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoAES1_Decrypt(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t* input, /* out */ uint8_t** output) {
    CEcoAES1* pCMe = (CEcoAES1*)me;
    uint8_t l_round = 0;
    uint8_t* _roundKey = 0;
    state_t* _state =  (state_t*)input;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    //fnCipherInv((state_t*)_buf, _roundKey);



    pCMe->m_pVTblIAESInvCipher->AddRoundKey((IEcoAES1InvCipherPtr_t)&pCMe->m_pVTblIAESInvCipher, pCMe->m_Nr, _state, _roundKey);

    // Всего Nr раундов, первые Nr - 1 из них - одинаковые.
    for (l_round = (pCMe->m_Nr - 1); l_round > 0; --l_round) {
        pCMe->m_pVTblIAESInvCipher->InvShiftRows((IEcoAES1InvCipherPtr_t)&pCMe->m_pVTblIAESInvCipher, _state);
        pCMe->m_pVTblIAESInvCipher->InvSubBytes((IEcoAES1InvCipherPtr_t)&pCMe->m_pVTblIAESInvCipher, _state);
        pCMe->m_pVTblIAESInvCipher->AddRoundKey((IEcoAES1InvCipherPtr_t)&pCMe->m_pVTblIAESInvCipher, l_round, _state, _roundKey);
        pCMe->m_pVTblIAESInvCipher->InvMixColumns((IEcoAES1InvCipherPtr_t)&pCMe->m_pVTblIAESInvCipher, _state);
    }

    // Последний раунд. Здесь fnMixColumns не используется.
    pCMe->m_pVTblIAESInvCipher->InvShiftRows((IEcoAES1InvCipherPtr_t)&pCMe->m_pVTblIAESInvCipher, _state);
    pCMe->m_pVTblIAESInvCipher->InvSubBytes((IEcoAES1InvCipherPtr_t)&pCMe->m_pVTblIAESInvCipher, _state);
    pCMe->m_pVTblIAESInvCipher->AddRoundKey((IEcoAES1InvCipherPtr_t)&pCMe->m_pVTblIAESInvCipher, 0, _state, _roundKey);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция GenerateKey
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoAES1_GenerateKey(/* in */ IEcoAES1Ptr_t me, /* out */ uint8_t** key, /* out */ uint8_t* keySize) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция GenerateIV
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoAES1_GenerateIV(/* in */ IEcoAES1Ptr_t me,  /* out */ uint8_t** iv, /* out */ uint8_t* ivSize) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция KeyExpansion
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoAES1_KeyExpansion(/* in */ IEcoAES1Ptr_t me, /* in */ uint8_t* key, /* in */ uint8_t keySize, /* out */ uint8_t** roundKeys, /* out */ uint8_t* roundKeysSize) {
    CEcoAES1* pCMe = (CEcoAES1*)me;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoAES1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoAES1_Cipher_QueryInterface(/* in */ IEcoAES1CipherPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*));

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoAES1) ) {
        *ppv = &pCMe->m_pVTblIAES;
        pCMe->m_pVTblIAES->AddRef((IEcoAES1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoAES1Cipher) ) {
        *ppv = &pCMe->m_pVTblIAESCipher;
        pCMe->m_pVTblIAES->AddRef((IEcoAES1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoAES1InvCipher) ) {
        *ppv = &pCMe->m_pVTblIAESInvCipher;
        pCMe->m_pVTblIAES->AddRef((IEcoAES1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIAES;
        pCMe->m_pVTblIAES->AddRef((IEcoAES1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoAES1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoAES1_Cipher_AddRef(/* in */ IEcoAES1CipherPtr_t me) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoAES1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoAES1_Cipher_Release(/* in */ IEcoAES1CipherPtr_t me) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoAES1((IEcoAES1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция SubBytes
 * </сводка>
 *
 * <описание>
 *   Заменяет байты из State на байты из SBox
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_SubBytes(/* in */ IEcoAES1CipherPtr_t me, /* in */ state_t* state) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*));
    uint8_t i, j;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            (*state)[j][i] = fnGetSBoxValue((*state)[j][i]);
        }
    }
}

/*
 *
 * <сводка>
 *   Функция ShiftRows
 * </сводка>
 *
 * <описание>
 *   Циклический сдвиг трёх последних строк влево на определённые промежутки
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_ShiftRows(/* in */ IEcoAES1CipherPtr_t me, /* in */ state_t* state) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*));
    uint8_t temp;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    /* Повернуть первый ряд на 1 колонку влево */
    temp = (*state)[0][1];
    (*state)[0][1] = (*state)[1][1];
    (*state)[1][1] = (*state)[2][1];
    (*state)[2][1] = (*state)[3][1];
    (*state)[3][1] = temp;

    /* Повернуть второй ряд на 2 колонки влево */
    temp = (*state)[0][2];
    (*state)[0][2] = (*state)[2][2];
    (*state)[2][2] = temp;

    temp = (*state)[1][2];
    (*state)[1][2] = (*state)[3][2];
    (*state)[3][2] = temp;

    /* Повернуть третий ряд на 3 колонки влево */
    temp = (*state)[0][3];
    (*state)[0][3] = (*state)[3][3];
    (*state)[3][3] = (*state)[2][3];
    (*state)[2][3] = (*state)[1][3];
    (*state)[1][3] = temp;
}

/*
 *
 * <сводка>
 *   Функция MixColumns
 * </сводка>
 *
 * <описание>
 *   Перемешивает данные из колонок State чтобы создать новые колонки
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_MixColumns(/* in */ IEcoAES1CipherPtr_t me, /* in */ state_t* state) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*));
    uint8_t i;
    uint8_t Tmp, Tm, t;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    for (i = 0; i < 4; ++i) {
        t = (*state)[i][0];
        Tmp = (*state)[i][0] ^ (*state)[i][1] ^ (*state)[i][2] ^ (*state)[i][3];

        Tm = (*state)[i][0] ^ (*state)[i][1];
        Tm = fnXTime(Tm);
        (*state)[i][0] ^= Tm ^ Tmp;

        Tm = (*state)[i][1] ^ (*state)[i][2];
        Tm = fnXTime(Tm);
        (*state)[i][1] ^= Tm ^ Tmp;

        Tm = (*state)[i][2] ^ (*state)[i][3];
        Tm = fnXTime(Tm);
        (*state)[i][2] ^= Tm ^ Tmp;

        Tm = (*state)[i][3] ^ t;
        Tm = fnXTime(Tm);
        (*state)[i][3] ^= Tm ^ Tmp;
    }

}

/*
 *
 * <сводка>
 *   Функция AddRoundKey
 * </сводка>
 *
 * <описание>
 *   Добавление RoundKey к State при помощи операции XOR
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_AddRoundKey(/* in */ IEcoAES1CipherPtr_t me, /* in */ uint8_t round, /* in */ state_t* state, /* in */ uint8_t* roundKey) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*));
    uint8_t i, j;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            (*state)[i][j] ^= roundKey[(round * pCMe->m_Nb * 4) + (i * pCMe->m_Nb) + j];
        }
    }
}

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoAES1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoAES1_InvCipher_QueryInterface(/* in */ IEcoAES1InvCipherPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*)*2);

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoAES1) ) {
        *ppv = &pCMe->m_pVTblIAES;
        pCMe->m_pVTblIAES->AddRef((IEcoAES1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoAES1Cipher) ) {
        *ppv = &pCMe->m_pVTblIAESCipher;
        pCMe->m_pVTblIAES->AddRef((IEcoAES1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoAES1InvCipher) ) {
        *ppv = &pCMe->m_pVTblIAESInvCipher;
        pCMe->m_pVTblIAES->AddRef((IEcoAES1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIAES;
        pCMe->m_pVTblIAES->AddRef((IEcoAES1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoAES1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoAES1_InvCipher_AddRef(/* in */ IEcoAES1InvCipherPtr_t me) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*)*2);

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoAES1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoAES1_InvCipher_Release(/* in */ IEcoAES1InvCipherPtr_t me) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*)*2);

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoAES1((IEcoAES1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция InvShiftRows
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_InvShiftRows(/* in */ IEcoAES1InvCipherPtr_t me, /* in */ state_t* state) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*)*2);
    uint8_t temp;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    /* Первый ряд на 1 колонку вправо */
    temp = (*state)[3][1];
    (*state)[3][1] = (*state)[2][1];
    (*state)[2][1] = (*state)[1][1];
    (*state)[1][1] = (*state)[0][1];
    (*state)[0][1] = temp;

    /* Второй ряд на 2 колонки вправо */
    temp = (*state)[0][2];
    (*state)[0][2] = (*state)[2][2];
    (*state)[2][2] = temp;

    temp = (*state)[1][2];
    (*state)[1][2] = (*state)[3][2];
    (*state)[3][2] = temp;

    /* Третий ряд на 3 колонки вправо */
    temp = (*state)[0][3];
    (*state)[0][3] = (*state)[1][3];
    (*state)[1][3] = (*state)[2][3];
    (*state)[2][3] = (*state)[3][3];
    (*state)[3][3] = temp;
}

/*
 *
 * <сводка>
 *   Функция InvSubBytes
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_InvSubBytes(/* in */ IEcoAES1InvCipherPtr_t me, /* in */ state_t* state) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*)*2);
    uint8_t i, j;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            (*state)[j][i] = fnGetSBoxInvertValue((*state)[j][i]);
        }
    }
}

/*
 *
 * <сводка>
 *   Функция InvMixColumns
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_InvMixColumns(/* in */ IEcoAES1InvCipherPtr_t me, /* in */ state_t* state) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*)*2);
    int i;
    uint8_t a, b, c, d;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    for (i = 0; i < 4; ++i) {
        a = (*state)[i][0];
        b = (*state)[i][1];
        c = (*state)[i][2];
        d = (*state)[i][3];

        (*state)[i][0] = fnMultiply(a, 0x0e) ^ fnMultiply(b, 0x0b) ^ fnMultiply(c, 0x0d) ^ fnMultiply(d, 0x09);
        (*state)[i][1] = fnMultiply(a, 0x09) ^ fnMultiply(b, 0x0e) ^ fnMultiply(c, 0x0b) ^ fnMultiply(d, 0x0d);
        (*state)[i][2] = fnMultiply(a, 0x0d) ^ fnMultiply(b, 0x09) ^ fnMultiply(c, 0x0e) ^ fnMultiply(d, 0x0b);
        (*state)[i][3] = fnMultiply(a, 0x0b) ^ fnMultiply(b, 0x0d) ^ fnMultiply(c, 0x09) ^ fnMultiply(d, 0x0e);
    }
}

/*
 *
 * <сводка>
 *   Функция InvAddRoundKey
 * </сводка>
 *
 * <описание>
 *   Добавление RoundKey к State при помощи операции XOR
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoAES1_InvAddRoundKey(/* in */ IEcoAES1InvCipherPtr_t me, /* in */ uint8_t round, /* in */ state_t* state, /* in */ uint8_t* roundKey) {
    CEcoAES1* pCMe = (CEcoAES1*)((uint64_t)me - sizeof(struct IEcoUnknown*)*2);
    uint8_t i, j;

    /* Проверка указателей */
    if (me == 0 ) {
        return;
    }

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            (*state)[i][j] ^= roundKey[(round * pCMe->m_Nb * 4) + (i * pCMe->m_Nb) + j];
        }
    }
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoAES1(/*in*/ IEcoAES1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoAES1* pCMe = (CEcoAES1*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return result;
} 

/* Create Virtual Table IEcoAES1 */
IEcoAES1VTbl g_x84F33CD46FEC4788B062F86A7D65BC4BVTbl = {
    CEcoAES1_QueryInterface,
    CEcoAES1_AddRef,
    CEcoAES1_Release,
    CEcoAES1_get_KeySize,
    CEcoAES1_set_KeySize,
    CEcoAES1_get_BlockSize,
    CEcoAES1_set_BlockSize,
    CEcoAES1_get_Mode,
    CEcoAES1_set_Mode,
    CEcoAES1_get_Padding,
    CEcoAES1_set_Padding,
    CEcoAES1_get_Key,
    CEcoAES1_set_Key,
    CEcoAES1_get_IV,
    CEcoAES1_set_IV,
    CEcoAES1_Encrypt,
    CEcoAES1_Decrypt,
    CEcoAES1_GenerateKey,
    CEcoAES1_GenerateIV,
    CEcoAES1_KeyExpansion

};

/* Create Virtual Table IEcoAES1Cipher */
IEcoAES1CipherVTbl g_x7D1B1D141DB1489E85FEB57B973D49E1VTbl = {
    CEcoAES1_Cipher_QueryInterface,
    CEcoAES1_Cipher_AddRef,
    CEcoAES1_Cipher_Release,
    CEcoAES1_SubBytes,
    CEcoAES1_ShiftRows,
    CEcoAES1_MixColumns,
    CEcoAES1_AddRoundKey
};

/* Create Virtual Table IEcoAES1InvCipher */
IEcoAES1InvCipherVTbl g_x47258337CCF44A749DCAF20FABD063E8VTbl = {
    CEcoAES1_InvCipher_QueryInterface,
    CEcoAES1_InvCipher_AddRef,
    CEcoAES1_InvCipher_Release,
    CEcoAES1_InvShiftRows,
    CEcoAES1_InvSubBytes,
    CEcoAES1_InvMixColumns,
    CEcoAES1_InvAddRoundKey
};


/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoAES1(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoAES1Ptr_t* ppIEcoAES1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoAES1* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoAES1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoAES1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoAES1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoAES1 */
    pCMe->m_pVTblIAES = &g_x84F33CD46FEC4788B062F86A7D65BC4BVTbl;
    pCMe->m_pVTblIAESCipher = &g_x7D1B1D141DB1489E85FEB57B973D49E1VTbl;
    pCMe->m_pVTblIAESInvCipher = &g_x47258337CCF44A749DCAF20FABD063E8VTbl;

    /* Инициализация данных */
    pCMe->m_Nb = 4;     // Кол-во колонн в состоянии AES. Всегда равно 4.
    pCMe->m_Nk = 4;     // Кол-во 32-битных слов в ключе.
    pCMe->m_Nr = 10;    // Кол-во раундов в AES шифровальщике.

    /* Возврат указателя на интерфейс */
    *ppIEcoAES1 = (IEcoAES1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoAES1(/* in */ IEcoAES1Ptr_t pIEcoAES1) {
    CEcoAES1* pCMe = (CEcoAES1*)pIEcoAES1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoAES1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
