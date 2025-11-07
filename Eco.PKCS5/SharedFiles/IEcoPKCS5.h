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
#include "IEcoASNOne1.h"

typedef struct IEcoPKCS5PBKDF2* IEcoPKCS5PBKDF2Ptr_t;

typedef struct IEcoPKCS5PBKDF2VTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS5PBKDF2Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS5PBKDF2Ptr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS5PBKDF2Ptr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS5PBKDF2Ptr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS5PBKDF2Ptr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS5PBKDF2Ptr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS5PBKDF2Ptr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS5PBKDF2Ptr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS5PBKDF2Ptr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS5PBKDF2 */
    IEcoASNOne1ValueSet*(ECOCALLMETHOD* salt) (/* in */ IEcoPKCS5PBKDF2Ptr_t me);
    IEcoASNOne1Value*(ECOCALLMETHOD* iterationCount) (/* in */ IEcoPKCS5PBKDF2Ptr_t me);
    IEcoASNOne1Value*(ECOCALLMETHOD* keyLength) (/* in */ IEcoPKCS5PBKDF2Ptr_t me);

} IEcoPKCS5PBKDF2VTbl, * IEcoPKCS5PBKDF2VtblPtr_t;

interface IEcoPKCS5PBKDF2 {
    struct IEcoPKCS5PBKDF2VTbl* pVTbl;
} IEcoPKCS5PBKDF2;

typedef struct IEcoPKCS5PBEParameter* IEcoPKCS5PBEParameterPtr_t;

typedef struct IEcoPKCS5PBEParameterVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS5PBEParameterPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS5PBEParameterPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS5PBEParameterPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS5PBEParameterPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS5PBEParameterPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS5PBEParameterPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS5PBEParameterPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS5PBEParameterPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS5PBEParameterPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS5PBEParameter */
    IEcoASNOne1Value* (ECOCALLMETHOD* salt) (/* in */ IEcoPKCS5PBEParameterPtr_t me);
    IEcoASNOne1Value* (ECOCALLMETHOD* iterationCount) (/* in */ IEcoPKCS5PBEParameterPtr_t me);

} IEcoPKCS5PBEParameterVTbl, * IEcoPKCS5PBEParameterVtblPtr_t;

interface IEcoPKCS5PBEParameter {
    struct IEcoPKCS5PBEParameterVTbl* pVTbl;
} IEcoPKCS5PBEParameter;

typedef struct IEcoPKCS5RC2CBCParameter* IEcoPKCS5RC2CBCParameterPtr_t;

typedef struct IEcoPKCS5RC2CBCParameterVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS5RC2CBCParameterPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS5RC2CBCParameterPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS5RC2CBCParameterPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS5RC2CBCParameterPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS5RC2CBCParameterPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS5RC2CBCParameterPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS5RC2CBCParameterPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS5RC2CBCParameterPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS5RC2CBCParameterPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS5RC2CBCParameterVTbl */
    IEcoASNOne1Value*(ECOCALLMETHOD* iv) (/* in */ IEcoPKCS5RC2CBCParameterPtr_t me);
    IEcoASNOne1Value*(ECOCALLMETHOD* rc2ParameterVision) (/* in */ IEcoPKCS5RC2CBCParameterPtr_t me);

} IEcoPKCS5RC2CBCParameterVTbl, * IEcoPKCS5RC2CBCParameterVtblPtr_t;

interface IEcoPKCS5RC2CBCParameter {
    struct IEcoPKCS5RC2CBCParameterVTbl* pVTbl;
} IEcoPKCS5RC2CBCParameter;


typedef struct IEcoPKCS5RC5CBCParameter* IEcoPKCS5RC5CBCParameterPtr_t;

typedef struct IEcoPKCS5RC5CBCParameterVTbl {

    /* IEcoUnknown */
    int16_t(ECOCALLMETHOD* QueryInterface)(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t(ECOCALLMETHOD* AddRef)(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me);
    uint32_t(ECOCALLMETHOD* Release)(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me);

    /* IEcoASNOneSEQUENCE */
    uint8_t(ECOCALLMETHOD* get_Tag)(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me);
    uint8_t(ECOCALLMETHOD* get_TaggedType)(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me);
    uint8_t(ECOCALLMETHOD* get_Type)(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me);

    /* IEcoASNOne1ValueSet */
    int16_t(ECOCALLMETHOD* Count)(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me, /* in */ int32_t* Count);
    int16_t(ECOCALLMETHOD* Item)(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component);
    int16_t(ECOCALLMETHOD* Add)(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index);

    /* IEcoPKCS5RC5CBCParameter */
    IEcoASNOne1Value*(ECOCALLMETHOD* version) (/* in */ IEcoPKCS5RC5CBCParameterPtr_t me);
    IEcoASNOne1Value*(ECOCALLMETHOD* rounds) (/* in */ IEcoPKCS5RC5CBCParameterPtr_t me);
    IEcoASNOne1Value*(ECOCALLMETHOD* blockSizeInBits) (/* in */ IEcoPKCS5RC5CBCParameterPtr_t me);
    IEcoASNOne1Value*(ECOCALLMETHOD* iv) (/* in */ IEcoPKCS5RC2CBCParameterPtr_t me);

} IEcoPKCS5RC5CBCParameterVTbl, * IEcoPKCS5RC5CBCParameterVtblPtr_t;

interface IEcoPKCS5RC5CBCParameter {
    struct IEcoPKCS5RC5CBCParameterVTbl* pVTbl;
} IEcoPKCS5RC5CBCParameter;

/* IEcoPKCS5 IID = {B7200A1C-E4B1-463D-AAC6-A4C5B4CDCDBC} */
#ifndef __IID_IEcoPKCS5PBEParameter
static const UGUID IID_IEcoPKCS5PBEParameter = {0x01, 0x10, {0xB7, 0x20, 0x0A, 0x1C, 0xE4, 0xB1, 0x46, 0x3D, 0xAA, 0xC6, 0xA4, 0xC5, 0xB4, 0xCD, 0xCD, 0xB1}};
#endif /* __IID_IEcoPKCS5 */

#ifndef __IID_IEcoPKCS5RC2CBCParameter
static const UGUID IID_IEcoPKCS5RC2CBCParameter = { 0x01, 0x10, {0xB7, 0x20, 0x0A, 0x1C, 0xE4, 0xB1, 0x46, 0x3D, 0xAA, 0xC6, 0xA4, 0xC5, 0xB4, 0xCD, 0xCD, 0xB2} };
#endif /* __IID_IEcoPKCS5 */

#ifndef __IID_IEcoPKCS5RC5CBCParameter
static const UGUID IID_IEcoPKCS5RC5CBCParameter = { 0x01, 0x10, {0xB7, 0x20, 0x0A, 0x1C, 0xE4, 0xB1, 0x46, 0x3D, 0xAA, 0xC6, 0xA4, 0xC5, 0xB4, 0xCD, 0xCD, 0xB3} };
#endif /* __IID_IEcoPKCS5 */

#ifndef __IID_IEcoPKCS5PBKDF2
static const UGUID IID_IEcoPKCS5PBKDF2 = { 0x01, 0x10, {0xB7, 0x20, 0x0A, 0x1C, 0xE4, 0xB1, 0x46, 0x3D, 0xAA, 0xC6, 0xA4, 0xC5, 0xB4, 0xCD, 0xCD, 0xB4} };
#endif /* __IID_IEcoPKCS5 */

#ifndef __IID_IEcoPKCS5
static const UGUID IID_IEcoPKCS5 = { 0x01, 0x10, {0xB7, 0x20, 0x0A, 0x1C, 0xE4, 0xB1, 0x46, 0x3D, 0xAA, 0xC6, 0xA4, 0xC5, 0xB4, 0xCD, 0xCD, 0xBC} };
#endif /* __IID_IEcoPKCS5 */

typedef struct IEcoPKCS5* IEcoPKCS5Ptr_t;

typedef struct IEcoPKCS5VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS5Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS5Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS5Ptr_t me);

    /* IEcoPKCS5 */
    int16_t(ECOCALLMETHOD* new_PBEParameter)(/* in */ IEcoPKCS5Ptr_t me, /* out */ IEcoPKCS5PBEParameter* ppIPKCS5PBEParameter);
    int16_t(ECOCALLMETHOD* new_PBKDF2)(/* in */ IEcoPKCS5Ptr_t me, /* out */ IEcoPKCS5PBKDF2* ppIPKCS5PBKDF2);
    int16_t(ECOCALLMETHOD* new_RC2CBCParameter)(/* in */ IEcoPKCS5Ptr_t me, /* out */ IEcoPKCS5RC2CBCParameter* ppIPKCS5RC2CBCParameter);
    int16_t(ECOCALLMETHOD* new_RC5CBCParameter)(/* in */ IEcoPKCS5Ptr_t me, /* out */ IEcoPKCS5RC5CBCParameter* ppIPKCS5RC5CBCParameter);

} IEcoPKCS5VTbl, *IEcoPKCS5VTblPtr_t;

interface IEcoPKCS5 {
    struct IEcoPKCS5VTbl *pVTbl;
} IEcoPKCS5;


#endif /* __I_ECOPKCS5_H__ */
