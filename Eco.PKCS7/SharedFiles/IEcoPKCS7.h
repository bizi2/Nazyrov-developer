/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoPKCS7
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoPKCS7
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

#ifndef __I_ECOPKCS7_H__
#define __I_ECOPKCS7_H__

#include "IEcoBase1.h"
#include "IEcoASNOne1.h"

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7
static const UGUID IID_IEcoPKCS7 = {0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xF6}};
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7Version
static const UGUID IID_IEcoPKCS7Version = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xF0} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7ContentInfo
static const UGUID IID_IEcoPKCS7ContentInfo = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xF2} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7AlgorithmIdentifier
static const UGUID IID_IEcoPKCS7AlgorithmIdentifier = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xF3} };
#endif /* __IID_IEcoPKCS7 

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7DigestAlgorithmIdentifiers
static const UGUID IID_IEcoPKCS7DigestAlgorithmIdentifiers = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xF5} };
#endif /* __IID_IEcoPKCS7 

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7RecipientInfo
static const UGUID IID_IEcoPKCS7RecipientInfo = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xF9} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7RecipientInfos
static const UGUID IID_IEcoPKCS7RecipientInfos = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xFA} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7IssuerAndSerialNumber
static const UGUID IID_IEcoPKCS7IssuerAndSerialNumber = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xFB} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7SignerInfo
static const UGUID IID_IEcoPKCS7SignerInfo = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xFC} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7SignerInfos
static const UGUID IID_IEcoPKCS7SignerInfos = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xFD} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7SignedData
static const UGUID IID_IEcoPKCS7SignedData = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xFE} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7EnvelopedData
static const UGUID IID_IEcoPKCS7EnvelopedData = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xFF} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7EncryptedContentInfo
static const UGUID IID_IEcoPKCS7EncryptedContentInfo = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xA0} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7DigestInfo
static const UGUID IID_IEcoPKCS7DigestInfo = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xA1} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7SignedAndEnvelopedData
static const UGUID IID_IEcoPKCS7SignedAndEnvelopedData = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xA2} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7DigestedData
static const UGUID IID_IEcoPKCS7DigestedData = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xA3} };
#endif /* __IID_IEcoPKCS7 */

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7EncryptedData
static const UGUID IID_IEcoPKCS7EncryptedData = { 0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xA4} };
#endif /* __IID_IEcoPKCS7 */

typedef struct IEcoPKCS7Version* IEcoPKCS7VersionPtr_t;

typedef struct IEcoPKCS7VersionVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS7VersionPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS7VersionPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS7VersionPtr_t me);

    /* IEcoASNOne1Type */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7VersionPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7VersionPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7VersionPtr_t me);

    /* IEcoPKCS7Version */
    IEcoASNOne1Value(ECOCALLMETHOD* set_Value)(/* in */ IEcoPKCS7VersionPtr_t me, /* in */ voidptr_t Value, /* in */ int32_t Size);
    IEcoASNOne1Value(ECOCALLMETHOD* get_Value)(/* in */ IEcoPKCS7VersionPtr_t me, /* out */ voidptr_t Value, /* out */ int32_t* Size);


} IEcoPKCS7VersionVTbl, * IEcoPKCS7VersionVTblPtr_t;

interface IEcoPKCS7Version {
    struct IEcoPKCS7VersionVTbl* pVTbl;
} IEcoPKCS7Version;

typedef struct IEcoPKCS7DigestAlgorithmIdentifiers* IEcoPKCS7DigestAlgorithmIdentifiersPtr_t;

typedef struct IEcoPKCS7DigestAlgorithmIdentifiersVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS7DigestAlgorithmIdentifiersPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS7DigestAlgorithmIdentifiersPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS7DigestAlgorithmIdentifiersPtr_t me);

    /* IEcoASNOne1Type */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7VersionPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7VersionPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7VersionPtr_t me);

    /* IEcoPKCS7DigestAlgorithmIdentifiers */
    IEcoASNOne1ValueSet(ECOCALLMETHOD* set_Value)(/* in */ IEcoPKCS7DigestAlgorithmIdentifiersPtr_t me, /* in */ voidptr_t Value, /* in */ int32_t Size);
    IEcoASNOne1ValueSet(ECOCALLMETHOD* get_Value)(/* in */ IEcoPKCS7DigestAlgorithmIdentifiersPtr_t me, /* out */ voidptr_t Value, /* out */ int32_t* Size);

} IEcoPKCS7DigestAlgorithmIdentifiersVTbl, * IEcoPKCS7DigestAlgorithmIdentifiersVTblPtr_t;

interface IEcoPKCS7DigestAlgorithmIdentifiers {
    struct IEcoPKCS7DigestAlgorithmIdentifiersVTbl* pVTbl;
} IEcoPKCS7DigestAlgorithmIdentifiers;

typedef struct IEcoPKCS7ContentInfo* IEcoPKCS7ContentInfoPtr_t;

typedef struct IEcoPKCS7ContentInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7ContentInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7ContentInfoPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7ContentInfoPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7ContentInfoPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7ContentInfoPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7ContentInfoPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7ContentInfoPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7ContentInfoPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7ContentInfoPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7ContentInfo */
    IEcoASNOne1Value* (ECOCALLMETHOD *contentType)(/* in */ IEcoPKCS7ContentInfoPtr_t me);
	IEcoASNOne1Value* (ECOCALLMETHOD *content)(/* in */ IEcoPKCS7ContentInfoPtr_t me);

} IEcoPKCS7ContentInfoVTbl, *IEcoPKCS7ContentInfoVTblPtr_t;

interface IEcoPKCS7ContentInfo {
    struct IEcoPKCS7ContentInfoVTbl *pVTbl;
} IEcoPKCS7ContentInfo;

typedef struct IEcoPKCS7AlgorithmIdentifier* IEcoPKCS7AlgorithmIdentifierPtr_t;

typedef struct IEcoPKCS7AlgorithmIdentifierVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS7AlgorithmIdentifierPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS7AlgorithmIdentifierPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS7AlgorithmIdentifierPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7AlgorithmIdentifierPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7AlgorithmIdentifierPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7AlgorithmIdentifierPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7AlgorithmIdentifierPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7AlgorithmIdentifierPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7AlgorithmIdentifierPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7AlgorithmIdentifier */
    IEcoASNOne1Value* (ECOCALLMETHOD* algorithm)(/* in */ IEcoPKCS7AlgorithmIdentifierPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD* parameters)(/* in */ IEcoPKCS7AlgorithmIdentifierPtr_t me);

} IEcoPKCS7AlgorithmIdentifierVTbl, *IEcoPKCS7AlgorithmIdentifierVTblPtr_t;

interface IEcoPKCS7AlgorithmIdentifier {
    struct IEcoPKCS7AlgorithmIdentifierVTbl* pVTbl;
} IEcoPKCS7AlgorithmIdentifier;

typedef struct IEcoPKCS7IssuerAndSerialNumber* IEcoPKCS7IssuerAndSerialNumberPtr_t;

typedef struct IEcoPKCS7IssuerAndSerialNumberVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS7IssuerAndSerialNumberPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS7IssuerAndSerialNumberPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS7IssuerAndSerialNumberPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7IssuerAndSerialNumberPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7IssuerAndSerialNumberPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7IssuerAndSerialNumberPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7IssuerAndSerialNumberPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7IssuerAndSerialNumberPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7IssuerAndSerialNumberPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7IssuerAndSerialNumber */
    IEcoASNOne1Value* (ECOCALLMETHOD* issuer)(/* in */ IEcoPKCS7IssuerAndSerialNumberPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD* serialNumber)(/* in */ IEcoPKCS7IssuerAndSerialNumberPtr_t me);

} IEcoPKCS7IssuerAndSerialNumberVTbl, * IEcoPKCS7IssuerAndSerialNumberVTblPtr_t;

interface IEcoPKCS7IssuerAndSerialNumber{
    struct IEcoPKCS7IssuerAndSerialNumberVTbl* pVTbl;
} IEcoPKCS7IssuerAndSerialNumber;

typedef struct IEcoPKCS7RecipientInfo* IEcoPKCS7RecipientInfoPtr_t;

typedef struct IEcoPKCS7RecipientInfoVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS7RecipientInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS7RecipientInfoPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS7RecipientInfoPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7RecipientInfoPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7RecipientInfoPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7RecipientInfoPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7RecipientInfoPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7RecipientInfoPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7RecipientInfoPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7RecipientInfo */
    IEcoPKCS7Version* (ECOCALLMETHOD* version)(/* in */ IEcoPKCS7RecipientInfoPtr_t me);
    IEcoPKCS7IssuerAndSerialNumber* (ECOCALLMETHOD* issuerAndSerialNumber)(/* in */ IEcoPKCS7RecipientInfoPtr_t me);
    IEcoPKCS7AlgorithmIdentifier* (ECOCALLMETHOD* keyEncryptionAlgorithm)(/* in */ IEcoPKCS7RecipientInfoPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD* encryptedKey)(/* in */ IEcoPKCS7RecipientInfoPtr_t me);

} IEcoPKCS7RecipientInfoVTbl, *IEcoPKCS7RecipientInfoVTblPtr_t;

interface IEcoPKCS7RecipientInfo {
    struct IEcoPKCS7RecipientInfoVTbl* pVTbl;
} IEcoPKCS7RecipientInfo;

typedef struct IEcoPKCS7RecipientInfos* IEcoPKCS7RecipientInfosPtr_t;

typedef struct IEcoPKCS7RecipientInfosVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS7RecipientInfosPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS7RecipientInfosPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS7RecipientInfosPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7RecipientInfosPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7RecipientInfosPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7RecipientInfosPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7RecipientInfosPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7RecipientInfosPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7RecipientInfosPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7RecipientInfos */
    IEcoPKCS7RecipientInfo* (ECOCALLMETHOD* riSet)(/* in */ IEcoPKCS7RecipientInfosPtr_t me);
    IEcoPKCS7RecipientInfo* (ECOCALLMETHOD* riSequence)(/* in */ IEcoPKCS7RecipientInfosPtr_t me);

} IEcoPKCS7RecipientInfosVTbl, *IEcoPKCS7RecipientInfosVTblPtr_t;

interface IEcoPKCS7RecipientInfos {
    struct IEcoPKCS7RecipientInfosVTbl* pVTbl;
} IEcoPKCS7RecipientInfos;

typedef struct IEcoPKCS7SignerInfo* IEcoPKCS7SignerInfoPtr_t;

typedef struct IEcoPKCS7SignerInfoVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS7SignerInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS7SignerInfoPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7SignerInfoPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7SignerInfoPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7SignerInfoPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7SignerInfoPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7SignerInfo */
    IEcoPKCS7Version* (ECOCALLMETHOD* version)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
    IEcoPKCS7IssuerAndSerialNumber* (ECOCALLMETHOD* issuerAndSerialNumber)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
    IEcoPKCS7AlgorithmIdentifier* (ECOCALLMETHOD* digestAlgorithm)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
    IEcoASNOne1ValueSet* (ECOCALLMETHOD* authenticatedAttributes)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
    IEcoPKCS7AlgorithmIdentifier* (ECOCALLMETHOD* digestEncryptionAlgorithm)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD* encryptedDigest)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
    IEcoASNOne1ValueSet* (ECOCALLMETHOD* unauthenticatedAttributes)(/* in */ IEcoPKCS7SignerInfoPtr_t me);

} IEcoPKCS7SignerInfoVTbl, *IEcoPKCS7SignerInfoVTblPtr_t;

interface IEcoPKCS7SignerInfo {
    struct IEcoPKCS7SignerInfoVTbl* pVTbl;
} IEcoPKCS7SignerInfo;

typedef struct IEcoPKCS7SignerInfos* IEcoPKCS7SignerInfosPtr_t;

typedef struct IEcoPKCS7SignerInfosVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS7SignerInfosPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS7SignerInfosPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS7SignerInfosPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7SignerInfosPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7SignerInfosPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7SignerInfosPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7SignerInfosPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7SignerInfosPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7SignerInfosPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7SignerInfos */
    IEcoPKCS7SignerInfo* (ECOCALLMETHOD* siSet)(/* in */ IEcoPKCS7SignerInfosPtr_t me);
    IEcoPKCS7SignerInfo* (ECOCALLMETHOD* siSequence)(/* in */ IEcoPKCS7SignerInfosPtr_t me);

} IEcoPKCS7SignerInfosVTbl, *IEcoPKCS7SignerInfosVTblPtr_t;

interface IEcoPKCS7SignerInfos {
    struct IEcoPKCS7SignerInfosVTbl* pVTbl;
} IEcoPKCS7SignerInfos;

typedef struct IEcoPKCS7SignedData* IEcoPKCS7SignedDataPtr_t;

typedef struct IEcoPKCS7SignedDataVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7SignedDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7SignedDataPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7SignedDataPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7SignedDataPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7SignedDataPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7SignedDataPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7SignedDataPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7SignedDataPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7SignedDataPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7SignedData */
    IEcoPKCS7Version* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS7SignedDataPtr_t me);
	IEcoPKCS7DigestAlgorithmIdentifiers* (ECOCALLMETHOD *digestAlgorithms)(/* in */ IEcoPKCS7SignedDataPtr_t me);
	IEcoASNOne1ValueSet* (ECOCALLMETHOD *certificates)(/* in */ IEcoPKCS7SignedDataPtr_t me);
	IEcoASNOne1ValueSet* (ECOCALLMETHOD *crls)(/* in */ IEcoPKCS7SignedDataPtr_t me);
    IEcoPKCS7SignerInfos* (ECOCALLMETHOD *signerInfos)(/* in */ IEcoPKCS7SignedDataPtr_t me);

} IEcoPKCS7SignedDataVTbl, *IEcoPKCS7SignedDataVTblPtr_t;

interface IEcoPKCS7SignedData {
    struct IEcoPKCS7SignedDataVTbl *pVTbl;
} IEcoPKCS7SignedData;

typedef struct IEcoPKCS7EncryptedContentInfo* IEcoPKCS7EncryptedContentInfoPtr_t;

typedef struct IEcoPKCS7EncryptedContentInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7EnvelopedData */
    IEcoASNOne1Value* (ECOCALLMETHOD *contentType)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me);
    IEcoPKCS7AlgorithmIdentifier* (ECOCALLMETHOD *contentEncryptionAlgorithm)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me);
	IEcoASNOne1Value* (ECOCALLMETHOD *encryptedContent)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me); // EncryptedContent ::= OCTET STRING

} IEcoPKCS7EncryptedContentInfoVTbl, *IEcoPKCS7EncryptedContentInfoVTblPtr_t;

interface IEcoPKCS7EncryptedContentInfo {
    struct IEcoPKCS7EncryptedContentInfoVTbl *pVTbl;
} IEcoPKCS7EncryptedContentInfo;

typedef struct IEcoPKCS7EnvelopedData* IEcoPKCS7EnvelopedDataPtr_t;

typedef struct IEcoPKCS7EnvelopedDataVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7EnvelopedData */
    IEcoPKCS7Version* (ECOCALLMETHOD* version)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);
    IEcoPKCS7RecipientInfos* (ECOCALLMETHOD* recipientInfos)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);
    IEcoPKCS7EncryptedContentInfo* (ECOCALLMETHOD* encryptedContentInfo)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);

} IEcoPKCS7EnvelopedDataVTbl, *IEcoPKCS7EnvelopedDataVTblPtr_t;

interface IEcoPKCS7EnvelopedData{
    struct IEcoPKCS7EnvelopedDataVTbl* pVTbl;
} IEcoPKCS7EnvelopedData;

typedef struct IEcoPKCS7DigestInfo* IEcoPKCS7DigestInfoPtr_t;

typedef struct IEcoPKCS7DigestInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7DigestInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7DigestInfoPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7DigestInfoPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7DigestInfoPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7DigestInfoPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7DigestInfoPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7DigestInfoPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7DigestInfoPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7DigestInfoPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7DigestInfo */
    IEcoPKCS7AlgorithmIdentifier* (ECOCALLMETHOD *digestAlgorithm)(/* in */ IEcoPKCS7DigestInfoPtr_t me);
	IEcoASNOne1Value* (ECOCALLMETHOD *digest)(/* in */ IEcoPKCS7DigestInfoPtr_t me);

} IEcoPKCS7DigestInfoVTbl, *IEcoPKCS7DigestInfoVTblPtr_t;

interface IEcoPKCS7DigestInfo {
    struct IEcoPKCS7DigestInfoVTbl *pVTbl;
} IEcoPKCS7DigestInfo;

typedef struct IEcoPKCS7SignedAndEnvelopedData* IEcoPKCS7SignedAndEnvelopedDataPtr_t;

typedef struct IEcoPKCS7SignedAndEnvelopedDataVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7SignedAndEnvelopedData */
    IEcoPKCS7Version* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
	IEcoPKCS7RecipientInfos* (ECOCALLMETHOD *recipientInfos)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
	IEcoPKCS7DigestAlgorithmIdentifiers* (ECOCALLMETHOD *digestAlgorithms)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
	IEcoPKCS7EncryptedContentInfo* (ECOCALLMETHOD *encryptedContentInfo)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
	IEcoASNOne1ValueSet* (ECOCALLMETHOD *certificates)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
	IEcoASNOne1ValueSet* (ECOCALLMETHOD *crls)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
    IEcoPKCS7SignerInfos* (ECOCALLMETHOD *signerInfos)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);

} IEcoPKCS7SignedAndEnvelopedDataVTbl, *IEcoPKCS7SignedAndEnvelopedDataVTblPtr_t;

interface IEcoPKCS7SignedAndEnvelopedData {
    struct IEcoPKCS7SignedAndEnvelopedDataVTbl *pVTbl;
} IEcoPKCS7SignedAndEnvelopedData;

typedef struct IEcoPKCS7DigestedData* IEcoPKCS7DigestedDataPtr_t;

typedef struct IEcoPKCS7DigestedDataVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7DigestedDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7DigestedDataPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7DigestedDataPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7DigestedDataPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7DigestedDataPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7DigestedDataPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7DigestedDataPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7DigestedDataPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7DigestedDataPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7DigestedData */
    IEcoPKCS7Version* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS7DigestedDataPtr_t me);
	IEcoPKCS7AlgorithmIdentifier* (ECOCALLMETHOD *digestAlgorithm)(/* in */ IEcoPKCS7DigestedDataPtr_t me);
	IEcoPKCS7ContentInfo* (ECOCALLMETHOD *contentInfo)(/* in */ IEcoPKCS7DigestedDataPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD *digest)(/* in */ IEcoPKCS7DigestedDataPtr_t me);

} IEcoPKCS7DigestedDataVTbl, *IEcoPKCS7DigestedDataVTblPtr_t;

interface IEcoPKCS7DigestedData {
    struct IEcoPKCS7DigestedDataVTbl *pVTbl;
} IEcoPKCS7DigestedData;

typedef struct IEcoPKCS7EncryptedData* IEcoPKCS7EncryptedDataPtr_t;

typedef struct IEcoPKCS7EncryptedDataVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7EncryptedDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7EncryptedDataPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7EncryptedDataPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS7EncryptedDataPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS7EncryptedDataPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS7EncryptedDataPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS7EncryptedDataPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS7EncryptedDataPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS7EncryptedDataPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS7EncryptedData */
    IEcoPKCS7Version* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS7EncryptedDataPtr_t me);
    IEcoPKCS7EncryptedContentInfo* (ECOCALLMETHOD *encryptedContentInfo)(/* in */ IEcoPKCS7EncryptedDataPtr_t me);

} IEcoPKCS7EncryptedDataVTbl, *IEcoPKCS7EncryptedDataVTblPtr_t;

interface IEcoPKCS7EncryptedData {
    struct IEcoPKCS7EncryptedDataVTbl *pVTbl;
} IEcoPKCS7EncryptedData;


typedef struct IEcoPKCS7* IEcoPKCS7Ptr_t;

typedef struct IEcoPKCS7VTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS7Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS7Ptr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS7Ptr_t me);

    /* IEcoPKCS7 */
    int16_t(ECOCALLMETHOD* new_ContentInfo)(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7ContentInfo* ppIPKCS7ContentInfo);
    int16_t(ECOCALLMETHOD* new_DigestInfo)(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7DigestInfo* ppIPKCS7DigestInfo);
    int16_t(ECOCALLMETHOD* new_EncryptedContentInfo)(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7EncryptedContentInfo* ppIPKCS7EncryptedContentInfo);
    int16_t(ECOCALLMETHOD* new_EncryptedData)(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7EncryptedData* ppIPKCS7EncryptedData);
    int16_t(ECOCALLMETHOD* new_EnvelopedData)(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7EnvelopedData* ppIPKCS7EnvelopedData);
    int16_t(ECOCALLMETHOD* new_SignedAndEnvelopedData)(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7SignedAndEnvelopedData* ppIPKCS7SignedAndEnvelopedData);
    int16_t(ECOCALLMETHOD* new_SignedData)(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7SignedData* ppIPKCS7SignedData);
    int16_t(ECOCALLMETHOD* new_SignerInfo)(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7SignerInfo* ppIPKCS7SignerInfo);
    int16_t(ECOCALLMETHOD* new_SignedData)(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7SignedData* ppIPKCS7SignedData);
    int16_t(ECOCALLMETHOD* new_SignerInfos)(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7SignerInfos* ppIPKCS7SignerInfos);
    int16_t(ECOCALLMETHOD* new_RecipientInfo)(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7RecipientInfo* ppIPKCS7RecipientInfo);
    int16_t(ECOCALLMETHOD* new_RecipientInfos)(/* in */ IEcoPKCS7Ptr_t me, /* out */ IEcoPKCS7RecipientInfos* ppIPKCS7RecipientInfos);

} IEcoPKCS7VTbl, *IEcoPKCS7VTblPtr_t;

interface IEcoPKCS7{
    struct IEcoPKCS7VTbl* pVTbl;
} IEcoPKCS7;

#endif /* __I_ECOPKCS7_H__ */
