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


#endif /* __I_ECOPKCS7_H__ */
