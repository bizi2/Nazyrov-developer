/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoVFB1Windows
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoVFB1Windows
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

#ifndef __I_ECO_VIRTUAL_FRAME_BUFFER_1_WINDOWS_H__
#define __I_ECO_VIRTUAL_FRAME_BUFFER_1_WINDOWS_H__

#include "IEcoBase1.h"

/* IEcoVFB1Windows IID = {8B744A65-43D6-4D0E-8906-A1CB33714233} */
#ifndef __IID_IEcoVFB1Windows
static const UGUID IID_IEcoVFB1Windows = {0x01, 0x10, {0x8B, 0x74, 0x4A, 0x65, 0x43, 0xD6, 0x4D, 0x0E, 0x89, 0x06, 0xA1, 0xCB, 0x33, 0x71, 0x42, 0x33}};
#endif /* __IID_IEcoVFB1Windows */

typedef struct IEcoVFB1Windows* IEcoVFB1WindowsPtr_t;

typedef struct IEcoVFB1WindowsVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoVFB1WindowsPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoVFB1WindowsPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoVFB1WindowsPtr_t me);

    /* IEcoVFB1Windows */
    //HWND (ECOCALLMETHOD *get_WindowHandle)(/* in */ IEcoVFB1WindowsPtr_t me);
    //HDC (ECOCALLMETHOD *get_DeviceContex)(/* in */ IEcoVFB1WindowsPtr_t me);

} IEcoVFB1WindowsVTbl, *IEcoVFB1WindowsVTblPtr;

interface IEcoVFB1Windows {
    struct IEcoVFB1WindowsVTbl *pVTbl;
} IEcoVFB1Windows;


#endif /* __I_ECO_VIRTUAL_FRAME_BUFFER_1_WINDOWS_H__ */
