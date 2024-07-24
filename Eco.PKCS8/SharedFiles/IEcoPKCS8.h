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


#endif /* __I_ECOPKCS8_H__ */
