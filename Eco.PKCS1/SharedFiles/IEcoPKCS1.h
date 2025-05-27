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
#include "IEcoASNOne1.h"

#ifndef __IID_IEcoPKCS1Version
static const UGUID IID_IEcoPKCS1Version = { 0x01, 0x10, {0x0D, 0xFA, 0xC7, 0xE5, 0x15, 0x06, 0x40, 0x44, 0x85, 0x4A, 0x1B, 0x35, 0xF3, 0x50, 0x55, 0x43} };
#endif /* __IID_IEcoPKCS1Version */

typedef struct IEcoPKCS1Version* IEcoPKCS1VersionPtr_t;

typedef struct IEcoPKCS1VersionVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS1VersionPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS1VersionPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS1VersionPtr_t me);

    /* IEcoASNOne1Type */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS1VersionPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS1VersionPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS1VersionPtr_t me);

    /* IEcoPKCS1Version */
    IEcoASNOne1Value(ECOCALLMETHOD* set_Value)(/* in */ IEcoPKCS1VersionPtr_t me, /* in */ voidptr_t Value, /* in */ int32_t Size);
    IEcoASNOne1Value(ECOCALLMETHOD* get_Value)(/* in */ IEcoPKCS1VersionPtr_t me, /* out */ voidptr_t Value, /* out */ int32_t* Size);


} IEcoPKCS1VersionVTbl, *IEcoPKCS1VersionVTblPtr_t;

interface IEcoPKCS1Version {
    struct IEcoPKCS1VersionVTbl* pVTbl;
} IEcoPKCS1Version;

#ifndef __IID_IEcoPKCS1OtherPrimeInfos
static const UGUID IID_IEcoPKCS1OtherPrimeInfos = { 0x01, 0x10, {0x0D, 0xFA, 0xC7, 0xE5, 0x15, 0x06, 0x40, 0x44, 0x85, 0x4A, 0x1B, 0x35, 0xF3, 0x50, 0x55, 0x44} };
#endif /* __IID_IEcoPKCS1OtherPrimeInfos */

typedef struct IEcoPKCS1OtherPrimeInfos* IEcoPKCS1OtherPrimeInfosPtr_t;

typedef struct IEcoPKCS1OtherPrimeInfosVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me);

    /* IEcoASNOne1Type */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me);

    /* IEcoPKCS1OtherPrimeInfos */
    IEcoASNOne1Value(ECOCALLMETHOD* set_Value)(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me, /* in */ voidptr_t Value, /* in */ int32_t Size);
    IEcoASNOne1Value(ECOCALLMETHOD* get_Value)(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me, /* out */ voidptr_t Value, /* out */ int32_t* Size);


} IEcoPKCS1OtherPrimeInfosVTbl, *IEcoPKCS1OtherPrimeInfosVTblPtr_t;

interface IEcoPKCS1OtherPrimeInfos {
    struct IEcoPKCS1OtherPrimeInfosVTbl* pVTbl;
} IEcoPKCS1OtherPrimeInfos;

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

    /* IEcoASNOne1Type */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);


    /* IEcoPKCS1RSAPublicKey */
    IEcoASNOne1Value* (ECOCALLMETHOD *modulus)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *publicExponent)(/* in */ IEcoPKCS1RSAPublicKeyPtr_t me);

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

    /* IEcoASNOne1Type */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS1RSAPrivateKey */
    IEcoPKCS1Version* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *modulus)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *publicExponent)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *privateExponent)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *prime1)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *prime2)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *exponent1)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *exponent2)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *coefficient)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);
    IEcoPKCS1OtherPrimeInfos* (ECOCALLMETHOD *otherPrimeInfos)(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t me);


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
    int16_t (ECOCALLMETHOD *new_RSAPrivateKey)(/* in */ IEcoPKCS1Ptr_t me, /* out */ IEcoPKCS1RSAPrivateKey* ppIPKCS1RSAPrivateKey);
    int16_t (ECOCALLMETHOD *new_RSAPublicKey)(/* in */ IEcoPKCS1Ptr_t me, /* out */ IEcoPKCS1RSAPublicKey* ppIPKCS1RSAPublicKey);

} IEcoPKCS1VTbl, *IEcoPKCS1VTblPtr_t;

interface IEcoPKCS1 {
    struct IEcoPKCS1VTbl *pVTbl;
} IEcoPKCS1;


#endif /* __I_ECO_PKCS_1_H__ */
