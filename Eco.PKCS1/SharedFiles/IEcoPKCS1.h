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

#ifndef __I_ECOPKCS1_H__
#define __I_ECOPKCS1_H__

#include "IEcoBase1.h"

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
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoPKCS1Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoPKCS1VTbl, *IEcoPKCS1VTblPtr_t;

interface IEcoPKCS1 {
    struct IEcoPKCS1VTbl *pVTbl;
} IEcoPKCS1;


#endif /* __I_ECOPKCS1_H__ */
