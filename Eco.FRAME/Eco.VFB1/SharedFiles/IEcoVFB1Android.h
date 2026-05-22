/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoVFB1Android
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoVFB1Android
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

#ifndef __I_ECO_VIRTUAL_FRAME_BUFFER_1_ANDROID_H__
#define __I_ECO_VIRTUAL_FRAME_BUFFER_1_ANDROID_H__

#include "IEcoBase1.h"

/* IEcoVFB1Android IID = {0ABEC382-E6B8-48C2-A4C8-55058D82D727} */
#ifndef __IID_IEcoVFB1Android
static const UGUID IID_IEcoVFB1Android = {0x01, 0x10, {0x0A, 0xBE, 0xC3, 0x82, 0xE6, 0xB8, 0x48, 0xC2, 0xA4, 0xC8, 0x55, 0x05, 0x8D, 0x82, 0xD7, 0x27}};
#endif /* __IID_IEcoVFB1Android */

typedef struct IEcoVFB1Android* IEcoVFB1AndroidPtr_t;

typedef struct IEcoVFB1AndroidVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoVFB1AndroidPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoVFB1AndroidPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoVFB1AndroidPtr_t me);

    /* IEcoVFB1Android */


} IEcoVFB1AndroidVTbl, *IEcoVFB1AndroidVTblPtr;

interface IEcoVFB1Android {
    struct IEcoVFB1AndroidVTbl *pVTbl;
} IEcoVFB1Android;


#endif /* __I_ECO_VIRTUAL_FRAME_BUFFER_1_ANDROID_H__ */
