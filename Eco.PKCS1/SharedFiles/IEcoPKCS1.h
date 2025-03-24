/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoPKCS1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoPKCS1
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

#ifndef __I_ECO_PKCS_1_H__
#define __I_ECO_PKCS_1_H__

#include "IEcoBase1.h"

/* IEcoPKCS1RSAPublicKey IID = {0DFAC7E5-1506-4044-854A-1B35F3505542} */
#ifndef __IID_IEcoPKCS1RSAPublicKey
static const UGUID IID_IEcoPKCS1RSAPublicKey = {0x01, 0x10, {0x0D, 0xFA, 0xC7, 0xE5, 0x15, 0x06, 0x40, 0x44, 0x85, 0x4A, 0x1B, 0x35, 0xF3, 0x50, 0x55, 0x42}};
#endif /* __IID_IEcoPKCS1RSAPublicKey */

typedef struct IEcoPKCS1RSAPublicKey* IEcoPKCS1RSAPublicKeyPtr_t;

typedef struct IEcoPKCS1RSAPublicKeyVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t (ECOCALLMETHOD *ToDo)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me);

    /* IEcoPKCS1RSAPublicKey */
    IEcoASNOneINTEGER* (ECOCALLMETHOD *modulus)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me);
    IEcoASNOneINTEGER* (ECOCALLMETHOD *publicExponent)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me);

} IEcoPKCS1RSAPublicKeyVTbl, *IEcoPKCS1RSAPublicKeyVTblPtr_t;

interface IEcoPKCS1RSAPublicKey {
    struct IEcoPKCS1RSAPublicKeyVTbl *pVTbl;
} IEcoPKCS1RSAPublicKey;


/* IEcoPKCS1RSAPrivateKey IID = {6E6CD6ED-F8D5-4D20-9946-3A25D35FBFC9} */
#ifndef __IID_IEcoPKCS1RSAPrivateKey
static const UGUID IID_IEcoPKCS1RSAPrivateKey = {0x01, 0x10, {0x6E, 0x6C, 0xD6, 0xED, 0xF8, 0xD5, 0x4D, 0x20, 0x99, 0x46, 0x3A, 0x25, 0xD3, 0x5F, 0xBF, 0xC9}};
#endif /* __IID_IEcoPKCS1RSAPrivateKey */

typedef struct IEcoPKCS1RSAPrivateKey* IEcoPKCS1RSAPrivateKeyPtr_t;

typedef struct IEcoPKCS1RSAPrivateKeyVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t (ECOCALLMETHOD *ToDo)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);

    /* IEcoPKCS1RSAPrivateKey */
    IEcoPKCS1Version* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOneINTEGER* (ECOCALLMETHOD *modulus)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOneINTEGER* (ECOCALLMETHOD *publicExponent)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOneINTEGER* (ECOCALLMETHOD *privateExponent)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOneINTEGER* (ECOCALLMETHOD *prime1)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOneINTEGER* (ECOCALLMETHOD *prime2)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOneINTEGER* (ECOCALLMETHOD *exponent1)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOneINTEGER* (ECOCALLMETHOD *exponent2)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOneINTEGER* (ECOCALLMETHOD *coefficient)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoPKCS1OtherPrimeInfos* (ECOCALLMETHOD *otherPrimeInfos)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me, /* in | out */ bool_t* OPTIONAL);


} IEcoPKCS1RSAPrivateKeyVTbl, *IEcoPKCS1RSAPrivateKeyVTblPtr_t;

interface IEcoPKCS1RSAPrivateKey {
    struct IEcoPKCS1RSAPrivateKeyVTbl *pVTbl;
} IEcoPKCS1RSAPrivateKey;



/* IEcoPKCS1 IID = {0873B45E-0450-4CCF-A2C9-2CDEAD2A7855} */
#ifndef __IID_IEcoPKCS1
static const UGUID IID_IEcoPKCS1 = {0x01, 0x10, {0x08, 0x73, 0xB4, 0x5E, 0x04, 0x50, 0x4C, 0xCF, 0xA2, 0xC9, 0x2C, 0xDE, 0xAD, 0x2A, 0x78, 0x55}};
#endif /* __IID_IEcoPKCS1 */

typedef struct IEcoPKCS1* IEcoPKCS1Ptr_t;

typedef struct IEcoPKCS1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS1Ptr_t me);

    /* IEcoPKCS1 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoPKCS1Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoPKCS1VTbl, *IEcoPKCS1VTblPtr_t;

interface IEcoPKCS1 {
    struct IEcoPKCS1VTbl *pVTbl;
} IEcoPKCS1;


#endif /* __I_ECO_PKCS_1_H__ */
