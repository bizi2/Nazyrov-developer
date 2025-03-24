/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoPKCS15
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoPKCS15
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

#ifndef __I_ECOPKCS15_H__
#define __I_ECOPKCS15_H__

#include "IEcoBase1.h"

/* IEcoPKCS15 IID = {40A8B04B-2651-4556-96F8-A97BA9F139C2} */
#ifndef __IID_IEcoPKCS15
static const UGUID IID_IEcoPKCS15 = {0x01, 0x10, {0x40, 0xA8, 0xB0, 0x4B, 0x26, 0x51, 0x45, 0x56, 0x96, 0xF8, 0xA9, 0x7B, 0xA9, 0xF1, 0x39, 0xC2}};
#endif /* __IID_IEcoPKCS15 */

typedef struct IEcoPKCS15* IEcoPKCS15Ptr_t;

typedef struct IEcoPKCS15VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15Ptr_t me);

    /* IEcoPKCS15 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoPKCS15Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoPKCS15VTbl, *IEcoPKCS15VTblPtr_t;

interface IEcoPKCS15 {
    struct IEcoPKCS15VTbl *pVTbl;
} IEcoPKCS15;

typedef struct IEcoPKCS15DigestInfoWithDefault* IEcoPKCS15DigestInfoWithDefaultPtr_t;

typedef struct IEcoPKCS15DigestInfoWithDefaultVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15DigestInfoWithDefaultPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15DigestInfoWithDefaultPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15DigestInfoWithDefaultPtr_t me);

    /* IEcoPKCS15DigestInfoWithDefault */
    IEcoPKCS15AlgorithmIdentifier* (ECOCALLMETHOD *digestAlg)(/* in */ IEcoPKCS15DigestInfoWithDefaultPtr_t me);
	IEcoASNOneDataValue* (ECOCALLMETHOD *digest)(/* in */ IEcoPKCS15DigestInfoWithDefaultPtr_t me);


} IEcoPKCS15DigestInfoWithDefaultVTbl, *IEcoPKCS15DigestInfoWithDefaultVTblPtr_t;

interface IEcoPKCS15DigestInfoWithDefault {
    struct IEcoPKCS15DigestInfoWithDefaultVTbl *pVTbl;
} IEcoPKCS15DigestInfoWithDefault;

typedef struct IEcoPKCS15Path* IEcoPKCS15PathPtr_t;

typedef struct IEcoPKCS15PathVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15PathPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15PathPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15PathPtr_t me);

    /* IEcoPKCS15Path */
	IEcoASNOneDataValue* (ECOCALLMETHOD *path)(/* in */ IEcoPKCS15PathPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *index)(/* in */ IEcoPKCS15PathPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *length)(/* in */ IEcoPKCS15PathPtr_t me);


} IEcoPKCS15PathVTbl, *IEcoPKCS15PathVTblPtr_t;

interface IEcoPKCS15Path {
    struct IEcoPKCS15PathVTbl *pVTbl;
} IEcoPKCS15Path;

typedef struct IEcoPKCS15CommonObjectAttributes* IEcoPKCS15CommonObjectAttributesPtr_t;

typedef struct IEcoPKCS15CommonObjectAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15CommonObjectAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15CommonObjectAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15CommonObjectAttributesPtr_t me);

    /* IEcoPKCS15CommonObjectAttributes */
	IEcoPKCS15Label* (ECOCALLMETHOD *label)(/* in */ IEcoPKCS15CommonObjectAttributesPtr_t me);
	IEcoPKCS15CommonObjectFlags* (ECOCALLMETHOD *flags)(/* in */ IEcoPKCS15CommonObjectAttributesPtr_t me);
	IEcoPKCS15Identifier* (ECOCALLMETHOD *authId)(/* in */ IEcoPKCS15CommonObjectAttributesPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *userConsent)(/* in */ IEcoPKCS15CommonObjectAttributesPtr_t me);
	IEcoPKCS15AccessControlRule* (ECOCALLMETHOD *accessControlRules)(/* in */ IEcoPKCS15CommonObjectAttributesPtr_t me);


} IEcoPKCS15CommonObjectAttributesVTbl, *IEcoPKCS15CommonObjectAttributesVTblPtr_t;

interface IEcoPKCS15CommonObjectAttributes {
    struct IEcoPKCS15CommonObjectAttributesVTbl *pVTbl;
} IEcoPKCS15CommonObjectAttributes;

typedef struct IEcoPKCS15AccessControlRule* IEcoPKCS15AccessControlRulePtr_t;

typedef struct IEcoPKCS15AccessControlRuleVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15AccessControlRulePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15AccessControlRulePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15AccessControlRulePtr_t me);

    /* IEcoPKCS15AccessControlRule */
	IEcoPKCS15AccessMode* (ECOCALLMETHOD *accessMode)(/* in */ IEcoPKCS15AccessControlRulePtr_t me);
	IEcoPKCS15SecurityCondition* (ECOCALLMETHOD *securityCondition)(/* in */ IEcoPKCS15AccessControlRulePtr_t me);


} IEcoPKCS15AccessControlRuleVTbl, *IEcoPKCS15AccessControlRuleVTblPtr_t;

interface IEcoPKCS15AccessControlRule {
    struct IEcoPKCS15AccessControlRuleVTbl *pVTbl;
} IEcoPKCS15AccessControlRule;

typedef struct IEcoPKCS15CommonKeyAttributes* IEcoPKCS15CommonKeyAttributesPtr_t;

typedef struct IEcoPKCS15CommonKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15CommonKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15CommonKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15CommonKeyAttributesPtr_t me);

    /* IEcoPKCS15CommonKeyAttributes */
	IEcoPKCS15Identifier* (ECOCALLMETHOD *id)(/* in */ IEcoPKCS15CommonKeyAttributesPtr_t me);
	IEcoPKCS15KeyUsageFlags* (ECOCALLMETHOD *usage)(/* in */ IEcoPKCS15CommonKeyAttributesPtr_t me);
	IEcoASNOneBOOLEAN* (ECOCALLMETHOD *native)(/* in */ IEcoPKCS15CommonKeyAttributesPtr_t me);
	IEcoPKCS15KeyAccessFlags* (ECOCALLMETHOD *accessFlags)(/* in */ IEcoPKCS15CommonKeyAttributesPtr_t me);
	IEcoPKCS15Reference* (ECOCALLMETHOD *keyReference)(/* in */ IEcoPKCS15CommonKeyAttributesPtr_t me);
	IEcoPKCS15GeneralizedTime* (ECOCALLMETHOD *startDate)(/* in */ IEcoPKCS15CommonKeyAttributesPtr_t me);
	IEcoPKCS15GeneralizedTime* (ECOCALLMETHOD *endDate)(/* in */ IEcoPKCS15CommonKeyAttributesPtr_t me);


} IEcoPKCS15CommonKeyAttributesVTbl, *IEcoPKCS15CommonKeyAttributesVTblPtr_t;

interface IEcoPKCS15CommonKeyAttributes {
    struct IEcoPKCS15CommonKeyAttributesVTbl *pVTbl;
} IEcoPKCS15CommonKeyAttributes;

typedef struct IEcoPKCS15CommonPrivateKeyAttributes* IEcoPKCS15CommonPrivateKeyAttributesPtr_t;

typedef struct IEcoPKCS15CommonPrivateKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15CommonPrivateKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15CommonPrivateKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15CommonPrivateKeyAttributesPtr_t me);

    /* IEcoPKCS15CommonPrivateKeyAttributes */
	IEcoPKCS15Name* (ECOCALLMETHOD *subjectName)(/* in */ IEcoPKCS15CommonPrivateKeyAttributesPtr_t me);
	IEcoPKCS15CredentialIdentifier* (ECOCALLMETHOD *keyIdentifiers)(/* in */ IEcoPKCS15CommonPrivateKeyAttributesPtr_t me);


} IEcoPKCS15CommonPrivateKeyAttributesVTbl, *IEcoPKCS15CommonPrivateKeyAttributesVTblPtr_t;

interface IEcoPKCS15CommonPrivateKeyAttributes {
    struct IEcoPKCS15CommonPrivateKeyAttributesVTbl *pVTbl;
} IEcoPKCS15CommonPrivateKeyAttributes;

typedef struct IEcoPKCS15CommonPublicKeyAttributes* IEcoPKCS15CommonPublicKeyAttributesPtr_t;

typedef struct IEcoPKCS15CommonPublicKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15CommonPublicKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15CommonPublicKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15CommonPublicKeyAttributesPtr_t me);

    /* IEcoPKCS15CommonPublicKeyAttributes */
	IEcoPKCS15Name* (ECOCALLMETHOD *subjectName)(/* in */ IEcoPKCS15CommonPublicKeyAttributesPtr_t me);


} IEcoPKCS15CommonPublicKeyAttributesVTbl, *IEcoPKCS15CommonPublicKeyAttributesVTblPtr_t;

interface IEcoPKCS15CommonPublicKeyAttributes {
    struct IEcoPKCS15CommonPublicKeyAttributesVTbl *pVTbl;
} IEcoPKCS15CommonPublicKeyAttributes;

typedef struct IEcoPKCS15SecretPublicKeyAttributes* IEcoPKCS15SecretPublicKeyAttributesPtr_t;

typedef struct IEcoPKCS15SecretPublicKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15SecretPublicKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15SecretPublicKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15SecretPublicKeyAttributesPtr_t me);

    /* IEcoPKCS15SecretPublicKeyAttributes */
	IEcoASNOneINTEGER** (ECOCALLMETHOD *keyLen)(/* in */ IEcoPKCS15SecretPublicKeyAttributesPtr_t me);


} IEcoPKCS15SecretPublicKeyAttributesVTbl, *IEcoPKCS15SecretPublicKeyAttributesVTblPtr_t;

interface IEcoPKCS15SecretPublicKeyAttributes {
    struct IEcoPKCS15SecretPublicKeyAttributesVTbl *pVTbl;
} IEcoPKCS15SecretPublicKeyAttributes;

typedef struct IEcoPKCS15CommonCertificateAttributes* IEcoPKCS15CommonCertificateAttributesPtr_t;

typedef struct IEcoPKCS15CommonCertificateAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15CommonCertificateAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15CommonCertificateAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15CommonCertificateAttributesPtr_t me);

    /* IEcoPKCS15CommonCertificateAttributes */
	IEcoPKCS15Identifier* (ECOCALLMETHOD *id)(/* in */ IEcoPKCS15CommonCertificateAttributesPtr_t me);
	IEcoASNOneBOOLEAN* (ECOCALLMETHOD *authority)(/* in */ IEcoPKCS15CommonCertificateAttributesPtr_t me);
	IEcoPKCS15CredentialIdentifier* (ECOCALLMETHOD *identifier)(/* in */ IEcoPKCS15CommonCertificateAttributesPtr_t me);
	IEcoPKCS15OOBCertHash* (ECOCALLMETHOD *certHash)(/* in */ IEcoPKCS15CommonCertificateAttributesPtr_t me);
	IEcoPKCS15Usage* (ECOCALLMETHOD *trustedUsage)(/* in */ IEcoPKCS15CommonCertificateAttributesPtr_t me);
	IEcoPKCS15GeneralizedTime* (ECOCALLMETHOD *endDate)(/* in */ IEcoPKCS15CommonCertificateAttributesPtr_t me);
	IEcoPKCS15CredentialIdentifier** (ECOCALLMETHOD *identifier)(/* in */ IEcoPKCS15CommonCertificateAttributesPtr_t me);
	IEcoASNOneBOOLEAN* (ECOCALLMETHOD *implicitTrust)(/* in */ IEcoPKCS15CommonCertificateAttributesPtr_t me);


} IEcoPKCS15CommonCertificateAttributesVTbl, *IEcoPKCS15CommonCertificateAttributesVTblPtr_t;

interface IEcoPKCS15CommonCertificateAttributes {
    struct IEcoPKCS15CommonCertificateAttributesVTbl *pVTbl;
} IEcoPKCS15CommonCertificateAttributes;


typedef struct IEcoPKCS15Usage* IEcoPKCS15UsagePtr_t;

typedef struct IEcoPKCS15UsageVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15UsagePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15UsagePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15UsagePtr_t me);

    /* IEcoPKCS15Usage */
	IEcoPKCS15KeyUsage* (ECOCALLMETHOD *keyUsage)(/* in */ IEcoPKCS15UsagePtr_t me);



} IEcoPKCS15UsageVTbl, *IEcoPKCS15UsageVTblPtr_t;

interface IEcoPKCS15Usage {
    struct IEcoPKCS15UsageVTbl *pVTbl;
} IEcoPKCS15Usage;

typedef struct IEcoPKCS15CommonDataObjectAttributes* IEcoPKCS15CommonDataObjectAttributesPtr_t;

typedef struct IEcoPKCS15CommonDataObjectAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15CommonDataObjectAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15CommonDataObjectAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15CommonDataObjectAttributesPtr_t me);

    /* IEcoPKCS15CommonDataObjectAttributes */
	IEcoPKCS15Label* (ECOCALLMETHOD *applicationName)(/* in */ IEcoPKCS15CommonDataObjectAttributesPtr_t me);



} IEcoPKCS15CommonDataObjectAttributesVTbl, *IEcoPKCS15CommonDataObjectAttributesVTblPtr_t;

interface IEcoPKCS15CommonDataObjectAttributes {
    struct IEcoPKCS15CommonDataObjectAttributesVTbl *pVTbl;
} IEcoPKCS15CommonDataObjectAttributes;

typedef struct IEcoPKCS15CommonAuthenticationObjectAttributes* IEcoPKCS15CommonAuthenticationObjectAttributesPtr_t;

typedef struct IEcoPKCS15CommonAuthenticationObjectAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15CommonAuthenticationObjectAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15CommonAuthenticationObjectAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15CommonAuthenticationObjectAttributesPtr_t me);

    /* IEcoPKCS15CommonAuthenticationObjectAttributes */
	IEcoPKCS15Identifier* (ECOCALLMETHOD *authId)(/* in */ IEcoPKCS15CommonAuthenticationObjectAttributesPtr_t me);



} IIEcoPKCS15CommonAuthenticationObjectAttributesVTbl, *IEcoPKCS15CommonAuthenticationObjectAttributesVTblPtr_t;

interface IEcoPKCS15CommonAuthenticationObjectAttributes {
    struct IIEcoPKCS15CommonAuthenticationObjectAttributesVTbl *pVTbl;
} IEcoPKCS15CommonAuthenticationObjectAttributes;

typedef struct IEcoPKCS15RSAPrivateKeyObject* IEcoPKCS15RSAPrivateKeyObjectPtr_t;

typedef struct IEcoPKCS15RSAPrivateKeyObjectVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15RSAPrivateKeyObjectPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15CRSAPrivateKeyObjectPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15RSAPrivateKeyObjectPtr_t me);

    /* IEcoPKCS15RSAPrivateKeyObject */
	IEcoASNOneINTEGER* (ECOCALLMETHOD *modulus)(/* in */ IEcoPKCS15RSAPrivateKeyObjectPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *publicExponent)(/* in */ IEcoPKCS15RSAPrivateKeyObjectPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *privateExponent)(/* in */ IEcoPKCS15RSAPrivateKeyObjectPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *prime1)(/* in */ IEcoPKCS15RSAPrivateKeyObjectPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *prime2)(/* in */ IEcoPKCS15RSAPrivateKeyObjectPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *exponent1)(/* in */ IEcoPKCS15RSAPrivateKeyObjectPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *exponent2)(/* in */ IEcoPKCS15RSAPrivateKeyObjectPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *coefficient)(/* in */ IEcoPKCS15RSAPrivateKeyObjectPtr_t me);

} IEcoPKCS15RSAPrivateKeyObjectVTbl, *IEcoPKCS15RSAPrivateKeyObjectVTblPtr_t;

interface IEcoPKCS15RSAPrivateKeyObject {
    struct IEcoPKCS15RSAPrivateKeyObjectVTbl *pVTbl;
} IEcoPKCS15RSAPrivateKeyObject;

typedef struct IEcoPKCS15PrivateECKeyAttributes* IEcoPKCS15PrivateECKeyAttributesPtr_t;

typedef struct IEcoPKCS15PrivateECKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15PrivateECKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15PrivateECKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15PrivateECKeyAttributesPtr_t me);

    /* IEcoPKCS15PrivateECKeyAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15PrivateECKeyAttributesPtr_t me);
	IEcoPKCS15KeyInfo* (ECOCALLMETHOD *keyInfo)(/* in */ IEcoPKCS15PrivateECKeyAttributesPtr_t me);


} IEcoPKCS15PrivateECKeyAttributesVTbl, *IEcoPKCS15PrivateECKeyAttributesVTblPtr_t;

interface IEcoPKCS15PrivateECKeyAttributes {
    struct IEcoPKCS15PrivateECKeyAttributesVTbl *pVTbl;
} IEcoPKCS15PrivateECKeyAttributes;

typedef struct IEcoPKCS15PrivateDSAKeyAttributes* IEcoPKCS15PrivateDSAKeyAttributesPtr_t;

typedef struct IEcoPKCS15PrivateDSAKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15PrivateDSAKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15PrivateDSAKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15PrivateDSAKeyAttributesPtr_t me);

    /* IEcoPKCS15PrivateDSAKeyAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15PrivateDSAKeyAttributesPtr_t me);
	IEcoPKCS15KeyInfo* (ECOCALLMETHOD *keyInfo)(/* in */ IEcoPKCS15PrivateDSAKeyAttributesPtr_t me);


} IEcoPKCS15PrivateDSAKeyAttributesVTbl, *IEcoPKCS15PrivateDSAKeyAttributesVTblPtr_t;

interface IEcoPKCS15PrivateDSAKeyAttributes {
    struct IEcoPKCS15PrivateDSAKeyAttributesVTbl *pVTbl;
} IEcoPKCS15PrivateDSAKeyAttributes;

typedef struct IEcoPKCS15PrivateKEAKeyAttributes* IEcoPKCS15PrivateKEAKeyAttributesPtr_t;

typedef struct IEcoPKCS15PrivateKEAKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15PrivateKEAKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15PrivateKEAKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15PrivateKEAKeyAttributesPtr_t me);

    /* IEcoPKCS15PrivateKEAKeyAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15PrivateKEAKeyAttributesPtr_t me);
	IEcoPKCS15KeyInfo* (ECOCALLMETHOD *keyInfo)(/* in */ IEcoPKCS15PrivateKEAKeyAttributesPtr_t me);


} IEcoPKCS15PrivateKEAKeyAttributesVTbl, *IEcoPKCS15PrivateKEAKeyAttributesVTblPtr_t;

interface IEcoPKCS15PrivateKEAKeyAttributes {
    struct IEcoPKCS15PrivateKEAKeyAttributesVTbl *pVTbl;
} IEcoPKCS15PrivateKEAKeyAttributes;

typedef struct IEcoPKCS15PublicRSAKeyAttributes* IEcoPKCS15PublicRSAKeyAttributesPtr_t;

typedef struct IEcoPKCS15PublicRSAKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15PublicRSAKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15PublicRSAKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15PublicRSAKeyAttributesPtr_t me);

    /* IEcoPKCS15PublicRSAKeyAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15PublicRSAKeyAttributesPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *modulusLength)(/* in */ IEcoPKCS15PublicRSAKeyAttributesPtr_t me);
	IEcoPKCS15KeyInfo* (ECOCALLMETHOD *keyInfo)(/* in */ IEcoPKCS15PublicRSAKeyAttributesPtr_t me);


} IEcoPKCS15PublicRSAKeyAttributesVTbl, *IEcoPKCS15PublicRSAKeyAttributesVTblPtr_t;

interface IEcoPKCS15PublicRSAKeyAttributesPtr_t {
    struct IEcoPKCS15PublicRSAKeyAttributesVTbl *pVTbl;
} IEcoPKCS15PublicRSAKeyAttributesPtr_t;

typedef struct IEcoPKCS15PublicECKeyAttributes* IEcoPKCS15PublicECKeyAttributesPtr_t;

typedef struct IEcoPKCS15PublicECKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15PublicECKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15PublicECKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15PublicECKeyAttributesPtr_t me);

    /* IEcoPKCS15PublicECKeyAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15PublicECKeyAttributesPtr_t me);
	IEcoPKCS15KeyInfo* (ECOCALLMETHOD *keyInfo)(/* in */ IEcoPKCS15PublicECKeyAttributesPtr_t me);


} IEcoPKCS15PublicECKeyAttributesVTbl, *IEcoPKCS15PublicECKeyAttributesVTblPtr_t;

interface IEcoPKCS15PublicECKeyAttributes {
    struct IEcoPKCS15PublicECKeyAttributesVTbl *pVTbl;
} IEcoPKCS15PublicECKeyAttributes;

typedef struct IEcoPKCS15PublicDHKeyAttributes* IEcoPKCS15PublicDHKeyAttributesPtr_t;

typedef struct IEcoPKCS15PublicDHKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15PublicDHKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15PublicDHKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15PublicDHKeyAttributesPtr_t me);

    /* IEcoPKCS15PublicECKeyAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15PublicDHKeyAttributesPtr_t me);
	IEcoPKCS15KeyInfo* (ECOCALLMETHOD *keyInfo)(/* in */ IEcoPKCS15PublicDHKeyAttributesPtr_t me);


} IEcoPKCS15PublicDHKeyAttributesVTbl, *IEcoPKCS15PublicDHKeyAttributesVTblPtr_t;

interface IEcoPKCS15PublicDHKeyAttributes {
    struct IEcoPKCS15PublicDHKeyAttributesVTbl *pVTbl;
} IEcoPKCS15PublicDHKeyAttributes;

typedef struct IEcoPKCS15PublicDSAKeyAttributes* IEcoPKCS15PublicDSAKeyAttributesPtr_t;

typedef struct IEcoPKCS15PublicDSAKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15PublicDSAKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15PublicDSAKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15PublicDSAKeyAttributesPtr_t me);

    /* IEcoPKCS15PublicDSAKeyAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15PublicDSAKeyAttributesPtr_t me);
	IEcoPKCS15KeyInfo* (ECOCALLMETHOD *keyInfo)(/* in */ IEcoPKCS15PublicDSAKeyAttributesPtr_t me);


} IEcoPKCS15PublicDSAKeyAttributesVTbl, *IEcoPKCS15PublicDSAKeyAttributesVTblPtr_t;

interface IEcoPKCS15PublicDSAKeyAttributes {
    struct IEcoPKCS15PublicDSAKeyAttributesVTbl *pVTbl;
} IEcoPKCS15PublicDSAKeyAttributes;

typedef struct IEcoPKCS15PublicKEAKeyAttributes* IEcoPKCS15PublicKEAKeyAttributesPtr_t;

typedef struct IEcoPKCS15PublicKEAKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15PublicKEAKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15PublicKEAKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15PublicKEAKeyAttributesPtr_t me);

    /* IEcoPKCS15PublicKEAKeyAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15PublicKEAKeyAttributesPtr_t me);
	IEcoPKCS15KeyInfo* (ECOCALLMETHOD *keyInfo)(/* in */ IEcoPKCS15PublicKEAKeyAttributesPtr_t me);


} IEcoPKCS15PublicKEAKeyAttributesVTbl, *IEcoPKCS15PublicKEAKeyAttributesVTblPtr_t;

interface IEcoPKCS15PublicKEAKeyAttributes {
    struct IEcoPKCS15PublicKEAKeyAttributesVTbl *pVTbl;
} IEcoPKCS15PublicKEAKeyAttributes;

typedef struct IEcoPKCS15OtherKey* IEcoPKCS15OtherKeyPtr_t;

typedef struct IEcoPKCS15OtherKeyVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15OtherKeyPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15OtherKeyPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15OtherKeyPtr_t me);

    /* IEcoPKCS15OtherKey */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15OtherKeyPtr_t me);
	IEcoPKCS15KeyInfo* (ECOCALLMETHOD *keyInfo)(/* in */ IEcoPKCS15OtherKeyPtr_t me);


} IEcoPKCS15OtherKeyVTbl, *IEcoPKCS15OtherKeyVTblPtr_t;

interface IEcoPKCS15OtherKey {
    struct IEcoPKCS15OtherKeyVTbl *pVTbl;
} IEcoPKCS15OtherKey;

typedef struct IEcoPKCS15GenericSecretKeyAttributes* IEcoPKCS15GenericSecretKeyAttributesPtr_t;

typedef struct IEcoPKCS15GenericSecretKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15GenericSecretKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15GenericSecretKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15GenericSecretKeyAttributesPtr_t me);

    /* IEcoPKCS15GenericSecretKeyAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15GenericSecretKeyAttributesPtr_t me);
	IEcoPKCS15KeyInfo* (ECOCALLMETHOD *keyInfo)(/* in */ IEcoPKCS15GenericSecretKeyAttributesPtr_t me);


} IEcoPKCS15GenericSecretKeyAttributesVTbl, *IEcoPKCS15GenericSecretKeyAttributesVTblPtr_t;

interface IEcoPKCS15GenericSecretKeyAttributes {
    struct IEcoPKCS15GenericSecretKeyAttributesVTbl *pVTbl;
} IEcoPKCS15GenericSecretKeyAttributes;

typedef struct IEcoPKCS15X509CertificateAttributes* IEcoPKCS15X509CertificateAttributesPtr_t;

typedef struct IEcoPKCS15X509CertificateAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15X509CertificateAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15X509CertificateAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15X509CertificateAttributesPtr_t me);

    /* IEcoPKCS15X509CertificateAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15X509CertificateAttributesPtr_t me);
	IEcoPKCS15Name* (ECOCALLMETHOD *subject)(/* in */ IEcoPKCS15X509CertificateAttributesPtr_t me);
	IEcoPKCS15Name* (ECOCALLMETHOD *issuer)(/* in */ IEcoPKCS15X509CertificateAttributesPtr_t me);
	IEcoPKCS15CertificateSerialNumber* (ECOCALLMETHOD *serialNumber)(/* in */ IEcoPKCS15X509CertificateAttributesPtr_t me);


} IEcoPKCS15X509CertificateAttributesVTbl, *IEcoPKCS15X509CertificateAttributesVTblPtr_t;

interface IEcoPKCS15X509CertificateAttributes {
    struct IEcoPKCS15X509CertificateAttributesVTbl *pVTbl;
} IEcoPKCS15X509CertificateAttributes;

typedef struct IEcoPKCS15X509AttributeCertificateAttributes* IEcoPKCS15X509AttributeCertificateAttributesPtr_t;

typedef struct IEcoPKCS15X509AttributeCertificateAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15X509AttributeCertificateAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15X509AttributeCertificateAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15X509AttributeCertificateAttributesPtr_t me);

    /* IEcoPKCS15X509AttributeCertificateAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15X509AttributeCertificateAttributesPtr_t me);
	IEcoPKCS15GeneralNames* (ECOCALLMETHOD *subject)(/* in */ IEcoPKCS15X509AttributeCertificateAttributesPtr_t me);
	IEcoASNOneObjectIdentifier* (ECOCALLMETHOD *attrTypes)(/* in */ IEcoPKCS15X509AttributeCertificateAttributesPtr_t me);
	IEcoPKCS15CertificateSerialNumber* (ECOCALLMETHOD *serialNumber)(/* in */ IEcoPKCS15X509AttributeCertificateAttributesPtr_t me);


} IEcoPKCS15X509AttributeCertificateAttributesVTbl, *IEcoPKCS15X509AttributeCertificateAttributesVTblPtr_t;

interface IEcoPKCS15X509AttributeCertificateAttributes {
    struct IEcoPKCS15X509AttributeCertificateAttributesVTbl *pVTbl;
} IEcoPKCS15X509AttributeCertificateAttributes;

typedef struct IEcoPKCS15SPKICertificateAttributes* IEcoPKCS15SPKICertificateAttributesPtr_t;

typedef struct IEcoPKCS15SPKICertificateAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15SPKICertificateAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15SPKICertificateAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15SPKICertificateAttributesPtr_t me);

    /* IEcoPKCS15SPKICertificateAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15SPKICertificateAttributesPtr_t me);


} IEcoPKCS15SPKICertificateAttributesVTbl, *IEcoPKCS15SPKICertificateAttributesVTblPtr_t;

interface IEcoPKCS15SPKICertificateAttributes {
    struct IEcoPKCS15SPKICertificateAttributesVTbl *pVTbl;
} IEcoPKCS15SPKICertificateAttributes;

typedef struct IEcoPKCS15PGPCertificateAttributes* IEcoPKCS15PGPCertificateAttributesPtr_t;

typedef struct IEcoPKCS15PGPCertificateAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15PGPCertificateAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15PGPCertificateAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15PGPCertificateAttributesPtr_t me);

    /* IEcoPKCS15PGPCertificateAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15PGPCertificateAttributesPtr_t me);


} IEcoPKCS15PGPCertificateAttributesVTbl, *IEcoPKCS15PGPCertificateAttributesVTblPtr_t;

interface IEcoPKCS15PGPCertificateAttributes {
    struct IEcoPKCS15PGPCertificateAttributesVTbl *pVTbl;
} IEcoPKCS15PGPCertificateAttributes;

typedef struct IEcoPKCS15WTLSCertificateAttributes* IEcoPKCS15WTLSCertificateAttributesPtr_t;

typedef struct IEcoPKCS15WTLSCertificateAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15WTLSCertificateAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15WTLSCertificateAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15WTLSCertificateAttributesPtr_t me);

    /* IEcoPKCS15WTLSCertificateAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15WTLSCertificateAttributesPtr_t me);


} IEcoPKCS15WTLSCertificateAttributesVTbl, *IEcoPKCS15WTLSCertificateAttributesVTblPtr_t;

interface IEcoPKCS15WTLSCertificateAttributes {
    struct IEcoPKCS15WTLSCertificateAttributesVTbl *pVTbl;
} IEcoPKCS15WTLSCertificateAttributes;

typedef struct IEcoPKCS15X9_68CertificateAttributes* IEcoPKCS15X9_68CertificateAttributesPtr_t;

typedef struct IEcoPKCS15X9_68CertificateAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15X9_68CertificateAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15X9_68CertificateAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15X9_68CertificateAttributesPtr_t me);

    /* IEcoPKCS15X9_68CertificateAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15X9_68CertificateAttributesPtr_t me);


} IEcoPKCS15X9_68CertificateAttributesVTbl, *IEcoPKCS15X9_68CertificateAttributesVTblPtr_t;

interface IEcoPKCS15X9_68CertificateAttributes {
    struct IEcoPKCS15X9_68CertificateAttributesVTbl *pVTbl;
} IEcoPKCS15X9_68CertificateAttributes;

typedef struct IEcoPKCS15CVCertificateAttributes* IEcoPKCS15CVCertificateAttributesPtr_t;

typedef struct IEcoPKCS15CVCertificateAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15CVCertificateAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15CVCertificateAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15CVCertificateAttributesPtr_t me);

    /* IEcoPKCS15CVCertificateAttributes */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15CVCertificateAttributesPtr_t me);


} IEcoPKCS15CVCertificateAttributesVTbl, *IEcoPKCS15CVCertificateAttributesVTblPtr_t;

interface IEcoPKCS15CVCertificateAttributes {
    struct IEcoPKCS15CVCertificateAttributesVTbl *pVTbl;
} IEcoPKCS15CVCertificateAttributes;

typedef struct IEcoPKCS15OidDO* IEcoPKCS15OidDOPtr_t;

typedef struct IEcoPKCS15OidDOVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15OidDOPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15OidDOPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15OidDOPtr_t me);

    /* IEcoPKCS15OidDO */
	IEcoPKCS15ObjectValue* (ECOCALLMETHOD *value)(/* in */ IEcoPKCS15OidDOPtr_t me);


} IEcoPKCS15OidDOVTbl, *IEcoPKCS15OidDOVTblPtr_t;

interface IEcoPKCS15OidDO {
    struct IEcoPKCS15OidDOVTbl *pVTbl;
} IEcoPKCS15OidDO;

typedef struct IEcoPKCS15PinAttributes* IEcoPKCS15PinAttributesPtr_t;

typedef struct IEcoPKCS15PinAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15PinAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15PinAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15PinAttributesPtr_t me);

    /* IEcoPKCS15PinAttributes */
	IEcoPKCS15PinFlags* (ECOCALLMETHOD *pinFlags)(/* in */ IEcoPKCS15PinAttributesPtr_t me);
	IEcoPKCS15PinType* (ECOCALLMETHOD *pinType)(/* in */ IEcoPKCS15PinAttributesPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *minLength)(/* in */ IEcoPKCS15PinAttributesPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *storedLength)(/* in */ IEcoPKCS15PinAttributesPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *maxLength)(/* in */ IEcoPKCS15PinAttributesPtr_t me);
	IEcoPKCS15Reference* (ECOCALLMETHOD *pinReference)(/* in */ IEcoPKCS15PinAttributesPtr_t me);
	IEcoASNOneDataValue* (ECOCALLMETHOD *padChar)(/* in */ IEcoPKCS15PinAttributesPtr_t me);
	IEcoPKCS15GeneralizedTime* (ECOCALLMETHOD *lastPinChange)(/* in */ IEcoPKCS15PinAttributesPtr_t me);
	IEcoPKCS15Path* (ECOCALLMETHOD *path)(/* in */ IEcoPKCS15PinAttributesPtr_t me);


} IEcoPKCS15PinAttributesVTbl, *IEcoPKCS15PinAttributesVTblPtr_t;

interface IEcoPKCS15PinAttributes {
    struct IEcoPKCS15PinAttributesVTbl *pVTbl;
} IEcoPKCS15PinAttributes;

typedef struct IEcoPKCS15BiometricAttributes* IEcoPKCS15BiometricAttributesPtr_t;

typedef struct IEcoPKCS15BiometricAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15BiometricAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15BiometricAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15BiometricAttributesPtr_t me);

    /* IEcoPKCS15BiometricAttributes */
	IEcoPKCS15BiometricFlags* (ECOCALLMETHOD *bioFlags)(/* in */ IEcoPKCS15BiometricAttributesPtr_t me);
	IEcoPKCS15BiometricType* (ECOCALLMETHOD *bioType)(/* in */ IEcoPKCS15BiometricAttributesPtr_t me);
	IEcoASNOneObjectIdentifier* (ECOCALLMETHOD *templateId)(/* in */ IEcoPKCS15BiometricAttributesPtr_t me);
	IEcoPKCS15Reference* (ECOCALLMETHOD *bioReference)(/* in */ IEcoPKCS15BiometricAttributesPtr_t me);
	IEcoPKCS15GeneralizedTime* (ECOCALLMETHOD *lastChange)(/* in */ IEcoPKCS15BiometricAttributesPtr_t me);
	IEcoPKCS15Path* (ECOCALLMETHOD *path)(/* in */ IEcoPKCS15BiometricAttributesPtr_t me);


} IEcoPKCS15BiometricAttributesVTbl, *IEcoPKCS15BiometricAttributesVTblPtr_t;

interface IEcoPKCS15BiometricAttributes {
    struct IEcoPKCS15BiometricAttributesVTbl *pVTbl;
} IEcoPKCS15BiometricAttributes;

typedef struct IEcoPKCS15FingerPrint* IEcoPKCS15FingerPrintPtr_t;

typedef struct IEcoPKCS15FingerPrintVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15FingerPrintPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15FingerPrintPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15FingerPrintPtr_t me);

    /* IEcoPKCS15FingerPrint */
	// enum hand {left, right};
	// enum finger {thumb, pointerFinger, middleFinger,
    //                ringFinger, littleFinger};


} IEcoPKCS15FingerPrintVTbl, *IEcoPKCS15FingerPrintVTblPtr_t;

interface IEcoPKCS15FingerPrint {
    struct IEcoPKCS15FingerPrintVTbl *pVTbl;
} IEcoPKCS15FingerPrint;

typedef struct IEcoPKCS15IrisScan* IEcoPKCS15IrisScanPtr_t;

typedef struct IEcoPKCS15IrisScanVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15FingerPrintPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15FingerPrintPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15FingerPrintPtr_t me);

    /* IEcoPKCS15IrisScan */
	// enum eye {left, right};


} IEcoPKCS15IrisScanVTbl, *IEcoPKCS15IrisScanVTblPtr_t;

interface IEcoPKCS15IrisScan {
    struct IEcoPKCS15IrisScanVTbl *pVTbl;
} IEcoPKCS15IrisScan;

typedef struct IEcoPKCS15AuthKeyAttributes* IEcoPKCS15AuthKeyAttributesPtr_t;

typedef struct IEcoPKCS15AuthKeyAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me);

    /* IEcoPKCS15AuthKeyAttributes */
	IEcoASNOneBOOLEAN* (ECOCALLMETHOD *derivedKey)(/* in */ IEcoPKCS15BiometricAttributesPtr_t me);
	IEcoPKCS15Identifier* (ECOCALLMETHOD *authKeyId)(/* in */ IEcoPKCS15BiometricAttributesPtr_t me);


} IEcoPKCS15AuthKeyAttributesVTbl, *IEcoPKCS15AuthKeyAttributesVTblPtr_t;

interface IEcoPKCS15AuthKeyAttributes {
    struct IEcoPKCS15AuthKeyAttributesVTbl *pVTbl;
} IEcoPKCS15AuthKeyAttributes;

typedef struct IEcoPKCS15CertBasedAuthenticationAttributes* IEcoPKCS15CertBasedAuthenticationAttributesPtr_t;

typedef struct IEcoPKCS15CertBasedAuthenticationAttributesVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me);

    /* IEcoPKCS15CertBasedAuthenticationAttributes */
	IEcoASNOneDataValue* (ECOCALLMETHOD *cha)(/* in */ IEcoPKCS15CertBasedAuthenticationAttributesPtr_t me);


} IEcoPKCS15CertBasedAuthenticationAttributesVTbl, *IEcoPKCS15CertBasedAuthenticationAttributesVTblPtr_t;

interface IEcoPKCS15CertBasedAuthenticationAttributes {
    struct IEcoPKCS15CertBasedAuthenticationAttributesVTbl *pVTbl;
} IEcoPKCS15CertBasedAuthenticationAttributes;

typedef struct IEcoPKCS15TokenInfo* IEcoPKCS15TokenInfoPtr_t;

typedef struct IEcoPKCS15TokenInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me);

    /* IEcoPKCS15TokenInfo */
	IEcoASNOneINTEGER* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS15TokenInfoPtr_t me);
	IEcoASNOneDataValue* (ECOCALLMETHOD *serialNumber)(/* in */ IEcoPKCS15TokenInfoPtr_t me);
	IEcoPKCS15Label* (ECOCALLMETHOD *manufacturerID)(/* in */ IEcoPKCS15TokenInfoPtr_t me);
	IEcoPKCS15Label* (ECOCALLMETHOD *label)(/* in */ IEcoPKCS15TokenInfoPtr_t me);
	IEcoPKCS15TokenFlags* (ECOCALLMETHOD *tokenflags)(/* in */ IEcoPKCS15TokenInfoPtr_t me);
	IEcoPKCS15SecurityEnvironmentInfo* (ECOCALLMETHOD *seInfo)(/* in */ IEcoPKCS15TokenInfoPtr_t me);
	IEcoPKCS15RecordInfo* (ECOCALLMETHOD *recordInfo)(/* in */ IEcoPKCS15TokenInfoPtr_t me);
	IEcoPKCS15AlgorithmInfo* (ECOCALLMETHOD *supportedAlgorithms)(/* in */ IEcoPKCS15TokenInfoPtr_t me);
	IEcoPKCS15Label* (ECOCALLMETHOD *issuerId)(/* in */ IEcoPKCS15TokenInfoPtr_t me);
	IEcoPKCS15Label* (ECOCALLMETHOD *holderId)(/* in */ IEcoPKCS15TokenInfoPtr_t me);
	IEcoPKCS15LastUpdate* (ECOCALLMETHOD *lastUpdate)(/* in */ IEcoPKCS15TokenInfoPtr_t me);
	IEcoPKCS15PrintableString* (ECOCALLMETHOD *preferredLanguage)(/* in */ IEcoPKCS15TokenInfoPtr_t me);



} IEcoPKCS15TokenInfoVTbl, *IEcoPKCS15TokenInfoVTblPtr_t;

interface IEcoPKCS15TokenInfo {
    struct IEcoPKCS15TokenInfoVTbl *pVTbl;
} IEcoPKCS15TokenInfo;

typedef struct IEcoPKCS15RecordInfo* IEcoPKCS15RecordInfoPtr_t;

typedef struct IEcoPKCS15RecordInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me);

    /* IEcoPKCS15RecordInfo */
	IEcoASNOneINTEGER* (ECOCALLMETHOD *oDFRecordLength)(/* in */ IEcoPKCS15RecordInfoPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *prKDFRecordLength)(/* in */ IEcoPKCS15RecordInfoPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *puKDFRecordLength)(/* in */ IEcoPKCS15RecordInfoPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *sKDFRecordLength)(/* in */ IEcoPKCS15RecordInfoPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *cDFRecordLength)(/* in */ IEcoPKCS15RecordInfoPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *dODFRecordLength)(/* in */ IEcoPKCS15RecordInfoPtr_t me);
	IEcoASNOneINTEGER* (ECOCALLMETHOD *aODFRecordLength)(/* in */ IEcoPKCS15RecordInfoPtr_t me);



} IEcoPKCS15RecordInfoVTbl, *IEcoPKCS15RecordInfoVTblPtr_t;

interface IEcoPKCS15RecordInfo {
    struct IEcoPKCS15RecordInfoVTbl *pVTbl;
} IEcoPKCS15RecordInfo;

typedef struct IEcoPKCS15AlgorithmInfo* IEcoPKCS15AlgorithmInfoPtr_t;

typedef struct IEcoPKCS15AlgorithmInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15AuthKeyAttributesPtr_t me);

    /* IEcoPKCS15AlgorithmInfo */
	IEcoPKCS15Reference* (ECOCALLMETHOD *reference)(/* in */ IEcoPKCS15AlgorithmInfoPtr_t me);
	IEcoPKCS15Reference* (ECOCALLMETHOD *algRef)(/* in */ IEcoPKCS15AlgorithmInfoPtr_t me);
    //reference  	Reference,
    //algorithm  	PKCS15-ALGORITHM.&id({AlgorithmSet}),
    //parameters 	PKCS15-ALGORITHM.&Parameters({AlgorithmSet}{@algorithm}),
    //supportedOperations
    //    	PKCS15-ALGORITHM.&Operations({AlgorithmSet}{@algorithm}),
    //algId       PKCS15-ALGORITHM.&objectIdentifier({AlgorithmSet}{@algorithm})
    //                OPTIONAL, 
    //algRef	Reference OPTIONAL



} IEcoPKCS15AlgorithmInfoVTbl, *IEcoPKCS15AlgorithmInfoVTblPtr_t;

interface IEcoPKCS15AlgorithmInfo {
    struct IEcoPKCS15AlgorithmInfoVTbl *pVTbl;
} IEcoPKCS15AlgorithmInfo;

//PKCS15-ALGORITHM ::= CLASS {
//       &id INTEGER UNIQUE,
//        &Parameters,
//        &Operations Operations,
//	&objectIdentifier OBJECT IDENTIFIER OPTIONAL
//} WITH SYNTAX {
//  PARAMETERS &Parameters OPERATIONS &Operations ID &id [OID &objectIdentifier]}

typedef struct IEcoPKCS15EnvelopedData* IEcoPKCS15EnvelopedDataPtr_t;

typedef struct IEcoPKCS15EnvelopedDataVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15EnvelopedDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15EnvelopedDataPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15EnvelopedDataPtr_t me);

    /* IEcoPKCS15EnvelopedData */
	IEcoASNOneINTEGER* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS15AlgorithmInfoPtr_t me);
	IEcoPKCS15OriginatorInfo* (ECOCALLMETHOD *originatorInfo)(/* in */ IEcoPKCS15AlgorithmInfoPtr_t me);
	IEcoPKCS15RecipientInfos* (ECOCALLMETHOD *recipientInfos)(/* in */ IEcoPKCS15AlgorithmInfoPtr_t me);
	IEcoPKCS15EncryptedContentInfo* (ECOCALLMETHOD *encryptedContentInfo)(/* in */ IEcoPKCS15AlgorithmInfoPtr_t me);
	IEcoASNOneSET* (ECOCALLMETHOD *unprotectedAttrs)(/* in */ IEcoPKCS15AlgorithmInfoPtr_t me);



} IEcoPKCS15EnvelopedDataVTbl, *IEcoPKCS15EnvelopedDataVTblPtr_t;

interface IEcoPKCS15EnvelopedData {
    struct IEcoPKCS15EnvelopedDataVTbl *pVTbl;
} IEcoPKCS15EnvelopedData;

typedef struct IEcoPKCS15EncryptedContentInfo* IEcoPKCS15EncryptedContentInfoPtr_t;

typedef struct IEcoPKCS15EncryptedContentInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15EncryptedContentInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15EncryptedContentInfoPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15EncryptedContentInfoPtr_t me);

    /* IEcoPKCS15EncryptedContentInfo */
	IEcoASNOneObjectIdentifier* (ECOCALLMETHOD *contentType)(/* in */ IEcoPKCS15EncryptedContentInfoPtr_t me);
	IEcoPKCS15AlgorithmIdentifier** (ECOCALLMETHOD *contentEncryptionAlgorithm)(/* in */ IEcoPKCS15EncryptedContentInfoPtr_t me);
	IEcoASNOneDataValue* (ECOCALLMETHOD *encryptedContent)(/* in */ IEcoPKCS15EncryptedContentInfoPtr_t me);



} IEcoPKCS15EncryptedContentInfoVTbl, *IEcoPKCS15EncryptedContentInfoVTblPtr_t;

interface IEcoPKCS15EncryptedContentInfo {
    struct IEcoPKCS15EncryptedContentInfoVTbl *pVTbl;
} IEcoPKCS15EncryptedContentInfo;

typedef struct IEcoPKCS15Token* IEcoPKCS15TokenPtr_t;

typedef struct IEcoPKCS15TokenVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15TokenPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15TokenPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15TokenPtr_t me);

    /* IEcoPKCS15Token */
	IEcoASNOneINTEGER* (ECOCALLMETHOD *version)(/* in */ IEcoPKCS15TokenPtr_t me);
	IEcoPKCS15KeyManagementInfo* (ECOCALLMETHOD *keyManagementInfo)(/* in */ IEcoPKCS15TokenPtr_t me);
	IEcoPKCS15Objects* (ECOCALLMETHOD *pkcs15Objects)(/* in */ IEcoPKCS15TokenPtr_t me);



} IEcoPKCS15TokenVTbl, *IEcoPKCS15TokenVTblPtr_t;

interface IEcoPKCS15Token {
    struct IEcoPKCS15TokenVTbl *pVTbl;
} IEcoPKCS15Token;

typedef struct IEcoPKCS15KeyManagementInfo* IEcoPKCS15KeyManagementInfoPtr_t;

typedef struct IEcoPKCS15KeyManagementInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15KeyManagementInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15KeyManagementInfoPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15KeyManagementInfoPtr_t me);

    /* IEcoPKCS15KeyManagementInfo */
	IEcoPKCS15Identifier* (ECOCALLMETHOD *keyId)(/* in */ IEcoPKCS15KeyManagementInfoPtr_t me);
	IEcoASNOneCHOICE* (ECOCALLMETHOD *keyInfo)(/* in */ IEcoPKCS15KeyManagementInfoPtr_t me);



} IEcoPKCS15KeyManagementInfoVTbl, *IEcoPKCS15KeyManagementInfoVTblPtr_t;

interface IEcoPKCS15KeyManagementInfo {
    struct IEcoPKCS15KeyManagementInfoVTbl *pVTbl;
} IEcoPKCS15KeyManagementInfo;

typedef struct IEcoPKCS15PasswordInfo* IEcoPKCS15PasswordInfoPtr_t;

typedef struct IEcoPKCS15PasswordInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15PasswordInfoPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15PasswordInfoPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15PasswordInfoPtr_t me);

    /* IEcoPKCS15PasswordInfo */
	IEcoPKCS15Label* (ECOCALLMETHOD *hint)(/* in */ IEcoPKCS15PasswordInfoPtr_t me);
	IEcoPKCS15AlgorithmIdentifier* (ECOCALLMETHOD *algId)(/* in */ IEcoPKCS15PasswordInfoPtr_t me);



} IEcoPKCS15PasswordInfoVTbl, *IEcoPKCS15PasswordInfoVTblPtr_t;

interface IEcoPKCS15PasswordInfo {
    struct IEcoPKCS15PasswordInfoVTbl *pVTbl;
} IEcoPKCS15PasswordInfo;

typedef struct IEcoPKCS15DDO* IEcoPKCS15DDOPtr_t;

typedef struct IEcoPKCS15DDOVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15DDOPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15DDOPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15DDOPtr_t me);

    /* IEcoPKCS15DDO */
	IEcoASNOneObjectIdentifier* (ECOCALLMETHOD *oid)(/* in */ IEcoPKCS15DDOPtr_t me);
	IEcoPKCS15Path* (ECOCALLMETHOD *odfPath)(/* in */ IEcoPKCS15DDOPtr_t me);
	IEcoPKCS15Path* (ECOCALLMETHOD *tokenInfoPath)(/* in */ IEcoPKCS15DDOPtr_t me);
	IEcoPKCS15Path* (ECOCALLMETHOD *unusedPath)(/* in */ IEcoPKCS15DDOPtr_t me);



} IEcoPKCS15DDOVTbl, *IEcoPKCS15DDOVTblPtr_t;

interface IEcoPKCS15DDO {
    struct IEcoPKCS15DDOVTbl *pVTbl;
} IEcoPKCS15DDO;

typedef struct IEcoPKCS15DIRRecord* IEcoPKCS15DIRRecordPtr_t;

typedef struct IEcoPKCS15DIRRecordVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15DIRRecordPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15DIRRecordPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15DIRRecordPtr_t me);

    /* IEcoPKCS15DIRRecord */
	IEcoASNOneDataValue* (ECOCALLMETHOD *aid)(/* in */ IEcoPKCS15DIRRecordPtr_t me);
	IEcoPKCS15UTF8String* (ECOCALLMETHOD *label)(/* in */ IEcoPKCS15DIRRecordPtr_t me);
	IEcoASNOneDataValue* (ECOCALLMETHOD *path)(/* in */ IEcoPKCS15DIRRecordPtr_t me);
	IEcoPKCS15DDO* (ECOCALLMETHOD *ddo)(/* in */ IEcoPKCS15DIRRecordPtr_t me);



} IEcoPKCS15DIRRecordVTbl, *IEcoPKCS15DIRRecordVTblPtr_t;

interface IEcoPKCS15DIRRecord {
    struct IEcoPKCS15DIRRecordVTbl *pVTbl;
} IEcoPKCS15DIRRecord;

typedef struct IEcoPKCS15UnusedSpace* IEcoPKCS15UnusedSpacePtr_t;

typedef struct IEcoPKCS15UnusedSpaceVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS15UnusedSpacePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS15UnusedSpacePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS15UnusedSpacePtr_t me);

    /* IEcoPKCS15UnusedSpace */
	IEcoPKCS15Path* (ECOCALLMETHOD *path)(/* in */ IEcoPKCS15UnusedSpacePtr_t me);
	IEcoPKCS15Identifier* (ECOCALLMETHOD *authId)(/* in */ IEcoPKCS15UnusedSpacePtr_t me);
	IEcoPKCS15AccessControlRule** (ECOCALLMETHOD *accessControlRules)(/* in */ IEcoPKCS15UnusedSpacePtr_t me);



} IEcoPKCS15UnusedSpaceVTbl, *IEcoPKCS15UnusedSpaceVTblPtr_t;

interface IEcoPKCS15UnusedSpace {
    struct IEcoPKCS15UnusedSpaceVTbl *pVTbl;
} IEcoPKCS15UnusedSpace;


#endif /* __I_ECOPKCS15_H__ */
