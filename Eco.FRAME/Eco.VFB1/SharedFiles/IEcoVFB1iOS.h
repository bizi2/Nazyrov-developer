/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoVFB1iOS
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoVFB1iOS
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

#ifndef __I_ECO_VIRTUAL_FRAME_BUFFER_1_I_OS_H__
#define __I_ECO_VIRTUAL_FRAME_BUFFER_1_I_OS_H__

#include "IEcoBase1.h"

/* IEcoVFB1iOS IID = {0BB6D1D1-ECCC-46B6-8752-63C73AF53807} */
#ifndef __IID_IEcoVFB1iOS
static const UGUID IID_IEcoVFB1iOS = {0x01, 0x10, {0x0B, 0xB6, 0xD1, 0xD1, 0xEC, 0xCC, 0x46, 0xB6, 0x87, 0x52, 0x63, 0xC7, 0x3A, 0xF5, 0x38, 0x07}};
#endif /* __IID_IEcoVFB1iOS */

typedef struct IEcoVFB1iOS* IEcoVFB1iOSPtr_t;

typedef struct IEcoVFB1iOSVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoVFB1iOSPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoVFB1iOSPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoVFB1iOSPtr_t me);

    /* IEcoVFB1iOS */


} IEcoVFB1iOSVTbl, *IEcoVFB1iOSVTblPtr;

interface IEcoVFB1iOS {
    struct IEcoVFB1iOSVTbl *pVTbl;
} IEcoVFB1iOS;


#endif /* __I_ECO_VIRTUAL_FRAME_BUFFER_1_I_OS_H__ */
