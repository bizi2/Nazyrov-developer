/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoBaseEncoding1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoBaseEncoding1
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECOBASEENCODING1_H__
#define __I_ECOBASEENCODING1_H__

#include "IEcoBase1.h"

/* IEcoBaseEncoding1 IID = {A61019F6-E1D2-4B12-AD73-16D88BBFE375} */
#ifndef __IID_IEcoBaseEncoding1
static const UGUID IID_IEcoBaseEncoding1 = {0x01, 0x10, {0xA6, 0x10, 0x19, 0xF6, 0xE1, 0xD2, 0x4B, 0x12, 0xAD, 0x73, 0x16, 0xD8, 0x8B, 0xBF, 0xE3, 0x75}};
#endif /* __IID_IEcoBaseEncoding1 */

typedef struct IEcoBaseEncoding1* IEcoBaseEncoding1Ptr_t;

typedef struct IEcoBaseEncoding1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoBaseEncoding1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoBaseEncoding1Ptr_t me);

    /* IEcoBaseEncoding1 */

    /* Encode memory allocation */
    void* (ECOCALLMETHOD *fnBase64EncMemAllocate)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in,
        /* out */ size_t* inlen, /* out */ size_t* outlen);
    void* (ECOCALLMETHOD* fnBase32EncMemAllocate)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in,
        /* out */ size_t* inlen, /* out */ size_t* outlen);
    void* (ECOCALLMETHOD* fnBase16EncMemAllocate)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in,
        /* out */ size_t* inlen, /* out */ size_t* outlen);

    /* Decode memory allocation */
    void* (ECOCALLMETHOD* fnBase64DecMemAllocate)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in,
        /* out */ size_t* inlen, /* out */ size_t* outlen);
    void* (ECOCALLMETHOD* fnBase32DecMemAllocate)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in,
        /* out */ size_t* inlen, /* out */ size_t* outlen);
    void* (ECOCALLMETHOD* fnBase16DecMemAllocate)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in,
        /* out */ size_t* inlen, /* out */ size_t* outlen);

    /* Encode */
    void (ECOCALLMETHOD* fnBase64Enc)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* in */ const size_t inlen,
        /* out */ const int8_t* out, /* in */ const size_t outlen);
    void (ECOCALLMETHOD* fnBase32Enc)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* in */ const size_t inlen,
        /* out */ const int8_t* out, /* in */ const size_t outlen);
    void (ECOCALLMETHOD* fnBase16Enc)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* in */ const size_t inlen,
        /* out */ const int8_t* out, /* in */ const size_t outlen);

    /* Decode */
    void (ECOCALLMETHOD* fnBase64Dec)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* in */ const size_t inlen,
        /* out */ const int8_t* out, /* in */ const size_t outlen);
    void (ECOCALLMETHOD* fnBase32Dec)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* in */ const size_t inlen,
        /* out */ const int8_t* out, /* in */ const size_t outlen);
    void (ECOCALLMETHOD* fnBase16Dec)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in, /* in */ const size_t inlen,
        /* out */ const int8_t* out, /* in */ const size_t outlen);

    /* Encode Shell */
    int8_t* (ECOCALLMETHOD* fnBase64EncSh)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in);
    int8_t* (ECOCALLMETHOD* fnBase32EncSh)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in);
    int8_t* (ECOCALLMETHOD* fnBase16EncSh)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in);

    /* Decode Shell */
    int8_t* (ECOCALLMETHOD* fnBase64DecSh)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in);
    int8_t* (ECOCALLMETHOD* fnBase32DecSh)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in);
    int8_t* (ECOCALLMETHOD* fnBase16DecSh)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ const int8_t* in);

} IEcoBaseEncoding1VTbl, *IEcoBaseEncoding1VTblPtr_t;

interface IEcoBaseEncoding1 {
    struct IEcoBaseEncoding1VTbl *pVTbl;
} IEcoBaseEncoding1;


#endif /* __I_ECOBASEENCODING1_H__ */
