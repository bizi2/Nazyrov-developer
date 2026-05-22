/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoVFB1BCM283x
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoVFB1BCM283x
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

#ifndef __I_ECO_VIRTUAL_FRAME_BUFFER_1_BCM283X_H__
#define __I_ECO_VIRTUAL_FRAME_BUFFER_1_BCM283X_H__

#include "IEcoBase1.h"

/* IEcoVFB1BCM283x IID = {A354CA89-D1AE-4E73-B1B4-0CC3AE0A51A3} */
#ifndef __IID_IEcoVFB1BCM283x
static const UGUID IID_IEcoVFB1BCM283x = {0x01, 0x10, {0xA3, 0x54, 0xCA, 0x89, 0xD1, 0xAE, 0x4E, 0x73, 0xB1, 0xB4, 0x0C, 0xC3, 0xAE, 0x0A, 0x51, 0xA3}};
#endif /* __IID_IEcoVFB1BCM283x */

typedef struct IEcoVFB1BCM283x* IEcoVFB1BCM283xPtr_t;

typedef struct IEcoVFB1BCM283xVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoVFB1BCM283xPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoVFB1BCM283xPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoVFB1BCM283xPtr_t me);

    /* IEcoVFB1BCM283x */


} IEcoVFB1BCM283xVTbl, *IEcoVFB1BCM283xVTblPtr;

interface IEcoVFB1BCM283x {
    struct IEcoVFB1BCM283xVTbl *pVTbl;
} IEcoVFB1BCM283x;


#endif /* __I_ECO_VIRTUAL_FRAME_BUFFER_1_BCM283X_H__ */
