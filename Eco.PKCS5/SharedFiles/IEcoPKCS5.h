/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoPKCS5
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoPKCS5
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

#ifndef __I_ECOPKCS5_H__
#define __I_ECOPKCS5_H__

#include "IEcoBase1.h"

typedef struct IEcoPKCS5PBKDF2* IEcoPKCS5PBKDF2Ptr_t;

typedef struct IEcoPKCS5PBKDF2VTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS5PBKDF2Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS5PBKDF2Ptr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS5PBKDF2Ptr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS5PBKDF2Ptr_t me);

    /* IEcoPKCS5PBKDF2 */
    IEcoASNOne1ValueSet*(ECOCALLMETHOD* salt) (/* in */ IEcoPKCS5PBKDF2Ptr_t me);
    IEcoASNOne1Value*(ECOCALLMETHOD* iterationCount) (/* in */ IEcoPKCS5PBKDF2Ptr_t me);
    IEcoASNOne1Value*(ECOCALLMETHOD* keyLength) (/* in */ IEcoPKCS5PBKDF2Ptr_t me);

} IEcoPKCS5PBKDF2VTbl, * IEcoPKCS5PBKDF2Ptr_t;

typedef struct IEcoPKCS5PBES1* IEcoPKCS5PBES1Ptr_t;

typedef struct IEcoPKCS5PBES1VTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS5PBES1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS5PBES1Ptr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS5PBES1Ptr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoPKCS5PBES1Ptr_t me);

    /* IEcoPKCS5PBES1 */
    IEcoASNOne1Value* (ECOCALLMETHOD* salt) (/* in */ IEcoPKCS5PBES1Ptr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD* iterationCount) (/* in */ IEcoPKCS5PBES1Ptr_t me);

} IEcoPKCS5PBES1VTbl, * IEcoPKCS5PBES1Ptr_t;

typedef struct IEcoRC2CBCParameter* IEcoRC2CBCParameterPtr_t;

typedef struct IEcoRC2CBCParameterVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoRC2CBCParameterPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoRC2CBCParameterPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoRC2CBCParameterPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoRC2CBCParameterPtr_t me);

    /* IEcoRC2CBCParameterVTbl */
    IEcoASNOne1Value*(ECOCALLMETHOD* iv) (/* in */ IEcoRC2CBCParameterPtr_t me);
    IEcoASNOne1Value*(ECOCALLMETHOD* rc2ParameterVision) (/* in */ IEcoRC2CBCParameterPtr_t me);

} IEcoRC2CBCParameterVTbl, * IEcoRC2CBCParameterPtr_t;

typedef struct IEcoRC5CBCParameter* IEcoRC5CBCParameterPtr_t;

typedef struct IEcoRC5CBCParameterVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoRC5CBCParameterPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoRC5CBCParameterPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoRC5CBCParameterPtr_t me);

    /* IEcoASNOneSEQUENCE */
    int16_t(ECOCALLMETHOD* ToDo)(/* in */ IEcoRC5CBCParameterPtr_t me);

    /* IEcoRC5CBCParameter */
    IEcoASNOne1Value*(ECOCALLMETHOD* version) (/* in */ IEcoRC5CBCParameterPtr_t me);
    IEcoASNOne1Value*(ECOCALLMETHOD* rounds) (/* in */ IEcoRC5CBCParameterPtr_t me);
    IEcoASNOne1Value*(ECOCALLMETHOD* blockSizeInBits) (/* in */ IEcoRC5CBCParameterPtr_t me);
    IEcoASNOne1Value*(ECOCALLMETHOD* iv) (/* in */ IEcoRC2CBCParameterPtr_t me);

} IEcoRC5CBCParameterVTbl, * IEcoRC5CBCParameterPtr_t;

/* IEcoPKCS5 IID = {B7200A1C-E4B1-463D-AAC6-A4C5B4CDCDBC} */
#ifndef __IID_IEcoPKCS5
static const UGUID IID_IEcoPKCS5 = {0x01, 0x10, {0xB7, 0x20, 0x0A, 0x1C, 0xE4, 0xB1, 0x46, 0x3D, 0xAA, 0xC6, 0xA4, 0xC5, 0xB4, 0xCD, 0xCD, 0xBC}};
#endif /* __IID_IEcoPKCS5 */

typedef struct IEcoPKCS5* IEcoPKCS5Ptr_t;

typedef struct IEcoPKCS5VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS5Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS5Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS5Ptr_t me);

    /* IEcoPKCS5 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoPKCS5Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoPKCS5VTbl, *IEcoPKCS5VTblPtr_t;

interface IEcoPKCS5 {
    struct IEcoPKCS5VTbl *pVTbl;
} IEcoPKCS5;


#endif /* __I_ECOPKCS5_H__ */
