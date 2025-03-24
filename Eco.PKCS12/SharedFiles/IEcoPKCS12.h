/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoPKCS12
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoPKCS12
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

#ifndef __I_ECO_PKCS_12_H__
#define __I_ECO_PKCS_12_H__

#include "IEcoBase1.h"



/*
 *  -- KeyBag
 *
 *  KeyBag ::= PrivateKeyInfo
 */

typedef struct IEcoPKCS8PrivateKeyInfo IEcoPKCS12KeyBag;


/*
 *  -- Shrouded KeyBag
 *
 *  PKCS8ShroudedKeyBag ::= EncryptedPrivateKeyInfo
 */

typedef struct IEcoPKCS8EncryptedPrivateKeyInfo IEcoPKCS12PKCS8ShroudedKeyBag;


/*
 *  SafeBag ::= SEQUENCE {
 *      bagId           BAG-TYPE.&id ({PKCS12BagSet}),
 *      bagValue        [0] EXPLICIT BAG-TYPE.&Type({PKCS12BagSet}{@bagId}),
 *      bagAttributes   SET OF PKCS12Attribute OPTIONAL
 *  }
 */

/* IEcoPKCS12SafeBag IID = {54716B62-3C31-48EA-A8D5-CF3F8A31C94E} */
#ifndef __IID_IEcoPKCS12SafeBag
static const UGUID IID_IEcoPKCS12SafeBag = {0x01, 0x10, {0x54, 0x71, 0x6B, 0x62, 0x3C, 0x31, 0x48, 0xEA, 0xA8, 0xD5, 0xCF, 0x3F, 0x8A, 0x31, 0xC9, 0x4E}};
#endif /* __IID_IEcoPKCS12SafeBag */

typedef struct IEcoPKCS12SafeBag* IEcoPKCS12SafeBagPtr_t;

typedef struct IEcoPKCS12SafeBagVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS12SafeBagPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS12SafeBagPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS12SafeBagPtr_t me);

    /* IEcoASNOneSetOf */

    /* IEcoPKCS12SafeBag */
    int16_t (ECOCALLMETHOD *bagId)(/* in */ IEcoPKCS12SafeBagPtr_t me, /* in | out */ ???IEcoPKCS7DigestInfo** bagId);
    int16_t (ECOCALLMETHOD *bagValue)(/* in */ IEcoPKCS12SafeBagPtr_t me, /* in | out */ ???IEcoASNOneOctetString** bagValue);
    int16_t (ECOCALLMETHOD *bagAttributes)(/* in */ IEcoPKCS12SafeBagPtr_t me, /* in | out */ IEcoASNOneSetOf** bagAttributes);

} IEcoPKCS12SafeBagVTbl, *IEcoPKCS12SafeBagVTblPtr_t;

interface IEcoPKCS12SafeBag {
    struct IEcoPKCS12SafeBagVTbl *pVTbl;
} IEcoPKCS12SafeBag;

/*
 *  SafeContents ::= SEQUENCE OF SafeBag
 */

/* IEcoPKCS12SafeContents IID = {47E07AF4-7A08-45A6-B5BA-717545A0C8E8} */
#ifndef __IID_IEcoPKCS12SafeContents
static const UGUID IID_IEcoPKCS12SafeContents = {0x01, 0x10, {0x47, 0xE0, 0x7A, 0xF4, 0x7A, 0x08, 0x45, 0xA6, 0xB5, 0xBA, 0x71, 0x75, 0x45, 0xA0, 0xC8, 0xE8}};
#endif /* __IID_IEcoPKCS12SafeContents */

typedef struct IEcoPKCS12SafeContents* IEcoPKCS12SafeContentsPtr_t;

typedef struct IEcoPKCS12SafeContentsVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS12SafeContentsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS12SafeContentsPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS12SafeContentsPtr_t me);

    /* IEcoList1 */

    /* IEcoASNOneSequenceOf */

    /* IEcoPKCS12SafeContents */

} IEcoPKCS12SafeContentsVTbl, *IEcoPKCS12SafeContentsVTblPtr_t;

interface IEcoPKCS12SafeContents {
    struct IEcoPKCS12SafeContentsVTbl *pVTbl;
} IEcoPKCS12SafeContents;

/*
 *  AuthenticatedSafe ::= SEQUENCE OF ContentInfo
 *  -- Data if unencrypted
 *  -- EncryptedData if password-encrypted
 *  -- EnvelopedData if public key-encrypted
 */

/* IEcoPKCS12AuthenticatedSafe IID = {4E7824A9-A22C-4FC1-AB99-59C0BD55347A} */
#ifndef __IID_IEcoPKCS12AuthenticatedSafe
static const UGUID IID_IEcoPKCS12AuthenticatedSafe = {0x01, 0x10, {0x4E, 0x78, 0x24, 0xA9, 0xA2, 0x2C, 0x4F, 0xC1, 0xAB, 0x99, 0x59, 0xC0, 0xBD, 0x55, 0x34, 0x7A}};
#endif /* __IID_IEcoPKCS12AuthenticatedSafe */

typedef struct IEcoPKCS12AuthenticatedSafe* IEcoPKCS12AuthenticatedSafePtr_t;

typedef struct IEcoPKCS12AuthenticatedSafeVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS12AuthenticatedSafePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS12AuthenticatedSafePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS12AuthenticatedSafePtr_t me);

    /* IEcoList1 */

    /* IEcoASNOneSequenceOf */

    /* IEcoPKCS12AuthenticatedSafe */

} IEcoPKCS12AuthenticatedSafeVTbl, *IEcoPKCS12AuthenticatedSafeVTblPtr_t;

interface IEcoPKCS12AuthenticatedSafe {
    struct IEcoPKCS12AuthenticatedSafeVTbl *pVTbl;
} IEcoPKCS12AuthenticatedSafe;


/*
 *  MacData ::= SEQUENCE {
 *      mac         DigestInfo,
 *      macSalt     OCTET STRING,
 *      iterations  INTEGER DEFAULT 1
 *  -- Note: The default is for historical reasons and its use is
 *  -- deprecated. A higher value, like 1024 is recommended.
 *  }
 */

/* IEcoPKCS12MacData IID = {B0AB70B9-2855-4195-BF59-87709342A33C} */
#ifndef __IID_IEcoPKCS12MacData
static const UGUID IID_IEcoPKCS12MacData = {0x01, 0x10, {0xB0, 0xAB, 0x70, 0xB9, 0x28, 0x55, 0x41, 0x95, 0xBF, 0x59, 0x87, 0x70, 0x93, 0x42, 0xA3, 0x3C}};
#endif /* __IID_IEcoPKCS12MacData */

typedef struct IEcoPKCS12MacData* IEcoPKCS12MacDataPtr_t;

typedef struct IEcoPKCS12MacDataVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS12MacDataPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS12MacDataPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS12MacDataPtr_t me);

    /* IEcoASNOneSequence */

    /* IEcoPKCS12MacData */
    int16_t (ECOCALLMETHOD *mac)(/* in */ IEcoPKCS12MacDataPtr_t me, /* in | out */ IEcoPKCS7DigestInfo** mac);
    int16_t (ECOCALLMETHOD *macSalt)(/* in */ IEcoPKCS12MacDataPtr_t me, /* in | out */ IEcoASNOneOctetString** macSalt);
    int16_t (ECOCALLMETHOD *iterations)(/* in */ IEcoPKCS12MacDataPtr_t me, /* in | out */ IEcoASNOneInteger** iterations);

} IEcoPKCS12MacDataVTbl, *IEcoPKCS12MacDataVTblPtr_t;

interface IEcoPKCS12MacData {
    struct IEcoPKCS12MacDataVTbl *pVTbl;
} IEcoPKCS12MacData;

/*
 *  -- The PFX PDU
 *
 *  PFX ::= SEQUENCE {
 *          version     INTEGER {v3(3)}(v3,...),
 *          authSafe    ContentInfo,
 *          macData     MacData OPTIONAL
 *  }
 */

/* IEcoPKCS12PFX IID = {5C7EB861-A12F-4FC3-8406-CCA59B8EDB00} */
#ifndef __IID_IEcoPKCS12PFX
static const UGUID IID_IEcoPKCS12PFX = {0x01, 0x10, {0x5C, 0x7E, 0xB8, 0x61, 0xA1, 0x2F, 0x4F, 0xC3, 0x84, 0x06, 0xCC, 0xA5, 0x9B, 0x8E, 0xDB, 0x00}};
#endif /* __IID_IEcoPKCS12PFX */

typedef struct IEcoPKCS12PFX* IEcoPKCS12PFXPtr_t;

typedef struct IEcoPKCS12PFXVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS12PFXPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS12PFXPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS12PFXPtr_t me);

    /* IEcoASNOneSequence */

    /* IEcoPKCS12PFX */
    int16_t (ECOCALLMETHOD *version)(/* in */ IEcoPKCS12PFXPtr_t me, /* in | out */ IEcoASNOneInteger** version);
    int16_t (ECOCALLMETHOD *authSafe)(/* in */ IEcoPKCS12PFXPtr_t me, /* in | out */ IEcoPKCS7ContentInfo** authSafe);
    int16_t (ECOCALLMETHOD *macData)(/* in */ IEcoPKCS12PFXPtr_t me, /* in | out */ IEcoPKCS12MacData** macData);

} IEcoPKCS12PFXVTbl, *IEcoPKCS12PFXVTblPtr_t;

interface IEcoPKCS12PFX {
    struct IEcoPKCS12PFXVTbl *pVTbl;
} IEcoPKCS12PFX;

/*
keyBag BAG-TYPE ::=
    {KeyBag              IDENTIFIED BY {bagtypes 1}}
pkcs8ShroudedKeyBag BAG-TYPE ::=
    {PKCS8ShroudedKeyBag IDENTIFIED BY {bagtypes 2}}
certBag BAG-TYPE ::=
    {CertBag             IDENTIFIED BY {bagtypes 3}}
crlBag BAG-TYPE ::=
    {CRLBag              IDENTIFIED BY {bagtypes 4}}
secretBag BAG-TYPE ::=
    {SecretBag           IDENTIFIED BY {bagtypes 5}}
safeContentsBag BAG-TYPE ::=
    {SafeContents        IDENTIFIED BY {bagtypes 6}}

PKCS12BagSet BAG-TYPE ::= {
    keyBag | 
    pkcs8ShroudedKeyBag |
    certBag |
    crlBag | 
    secretBag | 
    safeContentsBag,
    ... -- For future extensions
}

BAG-TYPE ::= TYPE-IDENTIFIER

-- KeyBag
KeyBag ::= PrivateKeyInfo

-- Shrouded KeyBag
PKCS8ShroudedKeyBag ::= EncryptedPrivateKeyInfo

x509Certificate BAG-TYPE ::=
    {OCTET STRING IDENTIFIED BY {certTypes 1}}
    -- DER-encoded X.509 certificate stored in OCTET STRING
sdsiCertificate BAG-TYPE ::=
    {IA5String IDENTIFIED BY {certTypes 2}}
    -- Base64-encoded SDSI certificate stored in IA5String

CertTypes BAG-TYPE ::= {
    x509Certificate |
    sdsiCertificate,
    ... -- For future extensions
	
	x509CRL BAG-TYPE ::=
    {OCTET STRING IDENTIFIED BY {crlTypes 1}}
    -- DER-encoded X.509 CRL stored in OCTET STRING

CRLTypes BAG-TYPE ::= {
    x509CRL,
    ... -- For future extensions
}

SecretTypes BAG-TYPE ::= {
    ... -- For future extensions
}

PKCS12AttrSet ATTRIBUTE ::= {
    friendlyName |
    localKeyId,
    ... -- Other attributes are allowed
}


*/

typedef struct IEcoPKCS12CertBag* IEcoPKCS12CertBagPtr_t;

typedef struct IEcoPKCS12CertBagVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS12CertBagPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS12CertBagPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS12CertBagPtr_t me);

    /* IEcoPKCS12CertBag */
	
	//     certId    BAG-TYPE.&id   ({CertTypes}),
	//     certValue [0] EXPLICIT BAG-TYPE.&Type ({CertTypes}{@certId})
	//



} IEcoPKCS12CertBagVTbl, *IEcoPKCS12CertBagVTblPtr_t;

interface IEcoPKCS12CertBag {
    struct IEcoPKCS12CertBagVTbl *pVTbl;
} IEcoPKCS12CertBag;

typedef struct IEcoPKCS12CRLBag* IEcoPKCS12CRLBagPtr_t;

typedef struct IEcoPKCS12CRLBagVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS12CRLBagPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS12CRLBagPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS12CRLBagPtr_t me);

    /* IEcoPKCS12CRLBag */
	
	//     crlId     BAG-TYPE.&id ({CRLTypes}),
	//     crltValue [0] EXPLICIT BAG-TYPE.&Type ({CRLTypes}{@crlId})
	//



} IEcoPKCS12CRLBagVTbl, *IEcoPKCS12CRLBagVTblPtr_t;

interface IEcoPKCS12CRLBag {
    struct IEcoPKCS12CRLBagVTbl *pVTbl;
} IEcoPKCS12CRLBag;

typedef struct IEcoPKCS12SecretBag* IEcoPKCS12SecretBagPtr_t;

typedef struct IEcoPKCS12SecretBagVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS12SecretBagPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS12SecretBagPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS12SecretBagPtr_t me);

    /* IEcoPKCS12SecretBag */
	
	//     secretTypeId  BAG-TYPE.&id ({SecretTypes}),
	//     secretValue   [0] EXPLICIT BAG-TYPE.&Type ({SecretTypes}{@secretTypeId})
	//



} IEcoPKCS12SecretBagVTbl, *IEcoPKCS12SecretBagVTblPtr_t;

interface IEcoPKCS12SecretBag {
    struct IEcoPKCS12SecretBagVTbl *pVTbl;
} IEcoPKCS12SecretBag;

typedef struct IEcoPKCS12PKCS12Attribute* IEcoPKCS12PKCS12AttributePtr_t;

typedef struct IEcoPKCS12PKCS12AttributeVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS12PKCS12AttributePtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS12PKCS12AttributePtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS12PKCS12AttributePtr_t me);

    /* IEcoPKCS12PKCS12Attribute */
	
	//     attrId      ATTRIBUTE.&id ({PKCS12AttrSet}),
	//     attrValues  SET OF ATTRIBUTE.&Type ({PKCS12AttrSet}{@attrId})
	//



} IEcoPKCS12PKCS12AttributeVTbl, *IEcoPKCS12PKCS12AttributeVTblPtr_t;

interface IEcoPKCS12PKCS12Attribute {
    struct IEcoPKCS12PKCS12AttributeVTbl *pVTbl;
} IEcoPKCS12PKCS12Attribute;


#endif /* __I_ECO_PKCS_12_H__ */
