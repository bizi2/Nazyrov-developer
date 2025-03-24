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

/* IEcoPKCS7 IID = {9748EA58-DD75-41E5-B0A2-03702BD96EF6} */
#ifndef __IID_IEcoPKCS7
static const UGUID IID_IEcoPKCS7 = {0x01, 0x10, {0x97, 0x48, 0xEA, 0x58, 0xDD, 0x75, 0x41, 0xE5, 0xB0, 0xA2, 0x03, 0x70, 0x2B, 0xD9, 0x6E, 0xF6}};
#endif /* __IID_IEcoPKCS7 */

typedef struct IEcoPKCS7* IEcoPKCS7Ptr_t;

typedef struct IEcoPKCS7VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7Ptr_t me);

    /* IEcoPKCS7 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoPKCS7Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoPKCS7VTbl, *IEcoPKCS7VTblPtr_t;

interface IEcoPKCS7 {
    struct IEcoPKCS7VTbl *pVTbl;
} IEcoPKCS7;

typedef struct IEcoPKCS7ContentInfo* IEcoPKCS7ContentInfoPtr_t;

typedef struct IEcoPKCS7ContentInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7ContentInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7ContentInfoPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7ContentInfoPtr_t me);

    /* IEcoPKCS7ContentInfo */
    IEcoPKCS7ContentType* (ECOCALLMETHOD *contentType)(/* in */ IEcoPKCS7ContentInfoPtr_t me);
	IEcoPKCS7Content* (ECOCALLMETHOD *content)(/* in */ IEcoPKCS7ContentInfoPtr_t me);

} IEcoPKCS7ContentInfoVTbl, *IEcoPKCS7ContentInfoPtr_t;

interface IEcoPKCS7ContentInfo {
    struct IEcoPKCS7ContentInfoVTbl *pVTbl;
} IEcoPKCS7ContentInfo;

typedef struct IEcoPKCS7SignedData* IEcoPKCS7SignedDataPtr_t;

typedef struct IEcoPKCS7SignedDataVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7SignedDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7SignedDataPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7SignedDataPtr_t me);

    /* IEcoPKCS7SignedData */
    IEcoPKCS7Version* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS7SignedDataPtr_t me);
	IEcoPKCS7DigestAlgorithmIdentifiers* (ECOCALLMETHOD *digestAlgorithms)(/* in */ IEcoPKCS7SignedDataPtr_t me);
	IEcoASNOneCHOICE* (ECOCALLMETHOD *certificates)(/* in */ IEcoPKCS7SignedDataPtr_t me);
	IEcoASNOneCHOICE* (ECOCALLMETHOD *crls)(/* in */ IEcoPKCS7SignedDataPtr_t me);
    IEcoPKCS7SignerInfos* (ECOCALLMETHOD *signerInfos)(/* in */ IEcoPKCS7SignedDataPtr_t me);

} IEcoPKCS7SignedDataVTbl, *IEcoPKCS7SignedDataPtr_t;

interface IEcoPKCS7SignedData {
    struct IEcoPKCS7SignedDataVTbl *pVTbl;
} IEcoPKCS7SignedData;

typedef struct IEcoPKCS7SignerInfo* IEcoPKCS7SignerInfoPtr_t;

typedef struct IEcoPKCS7SignerInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7SignerInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7SignerInfoPtr_t me);

    /* IEcoPKCS7SignerInfo */
    IEcoPKCS7Version* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
	IEcoPKCS7IssuerAndSerialNumber* (ECOCALLMETHOD *issuerAndSerialNumber)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
	IEcoPKCS7DigestAlgorithmIdentifier* (ECOCALLMETHOD *digestAlgorithm)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
	IEcoASNOneCHOICE* (ECOCALLMETHOD *authenticatedAttributes)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
    IEcoPKCS7DigestEncryptionAlgorithmIdentifier* (ECOCALLMETHOD *digestEncryptionAlgorithm)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
	IEcoPKCS7DigestEncryptedDigest* (ECOCALLMETHOD *encryptedDigest)(/* in */ IEcoPKCS7SignerInfoPtr_t me);
	IEcoASNOneCHOICE* (ECOCALLMETHOD *unauthenticatedAttributes)(/* in */ IEcoPKCS7SignerInfoPtr_t me);

} IEcoPKCS7SignerInfoVTbl, *IEcoPKCS7SignerInfoPtr_t;

interface IEcoPKCS7SignerInfo {
    struct IEcoPKCS7SignerInfoVTbl *pVTbl;
} IEcoPKCS7SignerInfo;

typedef struct IEcoPKCS7EnvelopedData* IEcoPKCS7EnvelopedDataPtr_t;

typedef struct IEcoPKCS7EnvelopedDataVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);

    /* IEcoPKCS7EnvelopedData */
    IEcoPKCS7Version* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);
	IEcoPKCS7RecipientInfos* (ECOCALLMETHOD *recipientInfos)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);
	IEcoPKCS7EncryptedContentInfo* (ECOCALLMETHOD *encryptedContentInfo)(/* in */ IEcoPKCS7EnvelopedDataPtr_t me);

} IEcoPKCS7EnvelopedDataVTbl, *IEcoPKCS7EnvelopedDataPtr_t;

interface IEcoPKCS7EnvelopedData {
    struct IEcoPKCS7EnvelopedDataVTbl *pVTbl;
} IEcoPKCS7EnvelopedData;

typedef struct IEcoPKCS7EncryptedContentInfo* IEcoPKCS7EncryptedContentInfoPtr_t;

typedef struct IEcoPKCS7EncryptedContentInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me);

    /* IEcoPKCS7EnvelopedData */
    IEcoPKCS7ContentType* (ECOCALLMETHOD *contentType)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me);
	IEcoPKCS7ContentEncryptionAlgorithmIdentifier* (ECOCALLMETHOD *contentEncryptionAlgorithm)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me);
	IEcoPKCS7EncryptedContent* (ECOCALLMETHOD *encryptedContent)(/* in */ IEcoPKCS7EncryptedContentInfoPtr_t me); // EncryptedContent ::= OCTET STRING

} IEcoPKCS7EncryptedContentInfoVTbl, *IEcoPKCS7EncryptedContentInfoPtr_t;

interface IEcoPKCS7EncryptedContentInfo {
    struct IEcoPKCS7EncryptedContentInfoVTbl *pVTbl;
} IEcoPKCS7EncryptedContentInfo;

typedef struct IEcoPKCS7DigestInfo* IEcoPKCS7DigestInfoPtr_t;

typedef struct IEcoPKCS7DigestInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7DigestInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7DigestInfoPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7DigestInfoPtr_t me);

    /* IEcoPKCS7DigestInfo */
	IEcoPKCS7DigestAlgorithmIdentifier* (ECOCALLMETHOD *digestAlgorithm)(/* in */ IEcoPKCS7DigestInfoPtr_t me);
	IEcoPKCS7Digest* (ECOCALLMETHOD *digest)(/* in */ IEcoPKCS7DigestInfoPtr_t me); Digest ::= OCTET STRING

} IEcoPKCS7DigestInfoVTbl, *IEcoPKCS7DigestInfoPtr_t;

interface IEcoPKCS7DigestInfo {
    struct IEcoPKCS7DigestInfoVTbl *pVTbl;
} IEcoPKCS7DigestInfo;

typedef struct IEcoPKCS7SignedAndEnvelopedData* IEcoPKCS7SignedAndEnvelopedDataPtr_t;

typedef struct IEcoPKCS7SignedAndEnvelopedDataVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);

    /* IEcoPKCS7SignedAndEnvelopedData */
    IEcoPKCS7Version* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
	IEcoPKCS7RecipientInfos* (ECOCALLMETHOD *recipientInfos)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
	IEcoPKCS7DigestAlgorithmIdentifiers* (ECOCALLMETHOD *digestAlgorithms)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
	IEcoPKCS7EncryptedContentInfo* (ECOCALLMETHOD *encryptedContentInfo)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
	IEcoASNOneCHOICE* (ECOCALLMETHOD *certificates)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
	IEcoASNOneCHOICE* (ECOCALLMETHOD *crls)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);
    IEcoPKCS7SignerInfos* (ECOCALLMETHOD *signerInfos)(/* in */ IEcoPKCS7SignedAndEnvelopedDataPtr_t me);

} IEcoPKCS7SignedAndEnvelopedDataVTbl, *IEcoPKCS7SignedAndEnvelopedDataPtr_t;

interface IEcoPKCS7SignedAndEnvelopedData {
    struct IEcoPKCS7SignedAndEnvelopedDataVTbl *pVTbl;
} IEcoPKCS7SignedAndEnvelopedData;

typedef struct IEcoPKCS7DigestedData* IEcoPKCS7DigestedDataPtr_t;

typedef struct IEcoPKCS7DigestedDataVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7DigestedDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7DigestedDataPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7DigestedDataPtr_t me);

    /* IEcoPKCS7DigestedData */
    IEcoPKCS7Version* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS7DigestedDataPtr_t me);
	IEcoPKCS7DigestAlgorithmIdentifier* (ECOCALLMETHOD *digestAlgorithm)(/* in */ IEcoPKCS7DigestedDataPtr_t me);
	IEcoPKCS7ContentInfo* (ECOCALLMETHOD *contentInfo)(/* in */ IEcoPKCS7DigestedDataPtr_t me);
    IEcoPKCS7Digest* (ECOCALLMETHOD *digest)(/* in */ IEcoPKCS7DigestedDataPtr_t me);

} IEcoPKCS7DigestedDataVTbl, *IEcoPKCS7DigestedDataPtr_t;

interface IEcoPKCS7DigestedData {
    struct IEcoPKCS7DigestedDataVTbl *pVTbl;
} IEcoPKCS7DigestedData;

typedef struct IEcoPKCS7EncryptedData* IEcoPKCS7EncryptedDataPtr_t;

typedef struct IEcoPKCS7EncryptedDataVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS7EncryptedDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS7EncryptedDataPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS7EncryptedDataPtr_t me);

    /* IEcoPKCS7EncryptedData */
    IEcoPKCS7Version* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS7EncryptedDataPtr_t me);
    IEcoPKCS7EncryptedContentInfo* (ECOCALLMETHOD *encryptedContentInfo)(/* in */ IEcoPKCS7EncryptedDataPtr_t me);

} IEcoPKCS7EncryptedDataVTbl *IEcoPKCS7EncryptedDataPtr_t;

interface IEcoPKCS7EncryptedData {
    struct IEcoPKCS7EncryptedDataVTbl *pVTbl;
} IEcoPKCS7EncryptedData;


#endif /* __I_ECOPKCS7_H__ */
