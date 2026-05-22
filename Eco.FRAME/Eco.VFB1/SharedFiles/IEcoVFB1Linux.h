/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoVFB1Linux
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoVFB1Linux
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

#ifndef __I_ECO_VIRTUAL_FRAME_BUFFER_1_LINUX_H__
#define __I_ECO_VIRTUAL_FRAME_BUFFER_1_LINUX_H__

#include "IEcoBase1.h"

/* IEcoVFB1Linux IID = {AEF1531A-DA41-4F95-8786-60E0464032E7} */
#ifndef __IID_IEcoVFB1Linux
static const UGUID IID_IEcoVFB1Linux = {0x01, 0x10, {0xAE, 0xF1, 0x53, 0x1A, 0xDA, 0x41, 0x4F, 0x95, 0x87, 0x86, 0x60, 0xE0, 0x46, 0x40, 0x32, 0xE7}};
#endif /* __IID_IEcoVFB1Linux */

typedef struct IEcoVFB1Linux* IEcoVFB1LinuxPtr_t;

typedef struct IEcoVFB1LinuxVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoVFB1LinuxPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoVFB1LinuxPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoVFB1LinuxPtr_t me);

    /* IEcoVFB1Linux */


} IEcoVFB1LinuxVTbl, *IEcoVFB1LinuxVTblPtr;

interface IEcoVFB1Linux {
    struct IEcoVFB1LinuxVTbl *pVTbl;
} IEcoVFB1Linux;


#endif /* __I_ECO_VIRTUAL_FRAME_BUFFER_1_LINUX_H__ */
