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


#endif /* __I_ECOPKCS15_H__ */
