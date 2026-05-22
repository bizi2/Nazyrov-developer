/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoVFB1MacOSX
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoVFB1MacOSX
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

#ifndef __I_ECO_VIRTUAL_FRAME_BUFFER_1_MAC_OS_X_H__
#define __I_ECO_VIRTUAL_FRAME_BUFFER_1_MAC_OS_X_H__

#include "IEcoBase1.h"

/* IEcoVFB1MacOSX IID = {767E3EB6-30C2-45EE-B1FC-AEE16073F8B6} */
#ifndef __IID_IEcoVFB1MacOSX
static const UGUID IID_IEcoVFB1MacOSX = {0x01, 0x10, {0x76, 0x7E, 0x3E, 0xB6, 0x30, 0xC2, 0x45, 0xEE, 0xB1, 0xFC, 0xAE, 0xE1, 0x60, 0x73, 0xF8, 0xB6}};
#endif /* __IID_IEcoVFB1MacOSX */

typedef struct IEcoVFB1MacOSX* IEcoVFB1MacOSXPtr_t;

typedef struct IEcoVFB1MacOSXVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoVFB1MacOSXPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoVFB1MacOSXPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoVFB1MacOSXPtr_t me);

    /* IEcoVFB1MacOSX */


} IEcoVFB1MacOSXVTbl, *IEcoVFB1MacOSXVTblPtr;

interface IEcoVFB1MacOSX {
    struct IEcoVFB1MacOSXVTbl *pVTbl;
} IEcoVFB1MacOSX;


#endif /* __I_ECO_VIRTUAL_FRAME_BUFFER_1_MAC_OS_X_H__ */
