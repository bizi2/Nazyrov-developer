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
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoBaseEncoding1Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoBaseEncoding1VTbl, *IEcoBaseEncoding1VTblPtr_t;

interface IEcoBaseEncoding1 {
    struct IEcoBaseEncoding1VTbl *pVTbl;
} IEcoBaseEncoding1;


#endif /* __I_ECOBASEENCODING1_H__ */
