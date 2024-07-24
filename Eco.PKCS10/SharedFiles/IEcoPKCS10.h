/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoPKCS10
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoPKCS10
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

#ifndef __I_ECOPKCS10_H__
#define __I_ECOPKCS10_H__

#include "IEcoBase1.h"

/* IEcoPKCS10 IID = {9EC14D9F-101A-4454-A002-B33957BD6F50} */
#ifndef __IID_IEcoPKCS10
static const UGUID IID_IEcoPKCS10 = {0x01, 0x10, {0x9E, 0xC1, 0x4D, 0x9F, 0x10, 0x1A, 0x44, 0x54, 0xA0, 0x02, 0xB3, 0x39, 0x57, 0xBD, 0x6F, 0x50}};
#endif /* __IID_IEcoPKCS10 */

typedef struct IEcoPKCS10* IEcoPKCS10Ptr_t;

typedef struct IEcoPKCS10VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS10Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS10Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS10Ptr_t me);

    /* IEcoPKCS10 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoPKCS10Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoPKCS10VTbl, *IEcoPKCS10VTblPtr_t;

interface IEcoPKCS10 {
    struct IEcoPKCS10VTbl *pVTbl;
} IEcoPKCS10;


#endif /* __I_ECOPKCS10_H__ */
