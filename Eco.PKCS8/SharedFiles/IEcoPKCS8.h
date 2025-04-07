/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoPKCS8
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoPKCS8
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

#ifndef __I_ECOPKCS8_H__
#define __I_ECOPKCS8_H__

#include "IEcoBase1.h"

/* IEcoPKCS8 IID = {F1057008-CED9-4C97-B4F7-79C6E9CDB8CA} */
#ifndef __IID_IEcoPKCS8
static const UGUID IID_IEcoPKCS8 = {0x01, 0x10, {0xF1, 0x05, 0x70, 0x08, 0xCE, 0xD9, 0x4C, 0x97, 0xB4, 0xF7, 0x79, 0xC6, 0xE9, 0xCD, 0xB8, 0xCA}};
#endif /* __IID_IEcoPKCS8 */

typedef struct IEcoPKCS8* IEcoPKCS8Ptr_t;

typedef struct IEcoPKCS8VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS8Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS8Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS8Ptr_t me);

    /* IEcoPKCS8 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoPKCS8Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoPKCS8VTbl, *IEcoPKCS8VTblPtr_t;

interface IEcoPKCS8 {
    struct IEcoPKCS8VTbl *pVTbl;
} IEcoPKCS8;

typedef struct IEcoPKCS8PrivateKey* IEcoPKCS8PrivateKeyPtr_t;

typedef struct IEcoPKCS8PrivateKeyVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS8PrivateKeyPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS8PrivateKeyPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS8PrivateKeyPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS8PrivateKeyPtr_t me);

    /* IEcoPKCS8PrivateKey */
    IEcoPKCS8Version* (ECOCALLMETHOD* version)(/* in */ IEcoPKCS8PrivateKeyPtr_t me);
    IEcoPKCS8AlgorithmIdentifier* (ECOCALLMETHOD* privateKeyAlgorithm) (/* in */ IEcoPKCS8PrivateKeyPtr_t me);
	IEcoPKCS8PrivateKey* (ECOCALLMETHOD* privateKey) (/* in */ IEcoPKCS8PrivateKeyPtr_t me);
    IEcoPKCS8Attributes* (ECOCALLMETHOD* attributes) (/* in */ IEcoPKCS8PrivateKeyPtr_t me);

} IEcoPKCS8PrivateKeyVTbl, * IEcoPKCS8PrivateKeyPtr_t;

interface IEcoPKCS8PrivateKey {
    struct IEcoPKCS8PrivateKeyVTbl *pVTbl;
} IEcoPKCS8PrivateKey;

typedef struct IEcoPKCS8EncryptedPrivateKey* IEcoPKCS8EncryptedPrivateKeyPtr_t;

typedef struct IEcoPKCS8EncryptedPrivateKeyVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS8EncryptedPrivateKeyPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS8EncryptedPrivateKeyPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS8EncryptedPrivateKeyPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS8EncryptedPrivateKeyPtr_t me);

    /* IEcoPKCS8EncryptedPrivateKey */
    IEcoPKCS8AlgorithmIdentifier* (ECOCALLMETHOD* encryptionAlgorithm) (/* in */ IEcoPKCS8EncryptedPrivateKeyPtr_t me);
	IEcoPKCS8EncryptedData* (ECOCALLMETHOD* encryptedData) (/* in */ IEcoPKCS8EncryptedPrivateKeyPtr_t me);

} IEcoPKCS8EncryptedPrivateKey, * IEcoPKCS8EncryptedPrivateKeyPtr_t;

interface IEcoPKCS8EncryptedPrivateKey {
    struct IEcoPKCS8EncryptedPrivateKeyVTbl *pVTbl;
} IEcoPKCS8EncryptedPrivateKey;


#endif /* __I_ECOPKCS8_H__ */
