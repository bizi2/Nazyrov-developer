/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoVFB1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoVFB1
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

#ifndef __I_ECO_VIRTUAL_FRAME_BUFFER_1_H__
#define __I_ECO_VIRTUAL_FRAME_BUFFER_1_H__

#include "IEcoBase1.h"
#include "IEcoVFB1ScreenInfo.h"


/* IEcoVFB1 IID = {8A4E6AAC-872D-4DA6-ACFC-FDAA253F2DA1} */
#ifndef __IID_IEcoVFB1
static const UGUID IID_IEcoVFB1 = {0x01, 0x10, {0x8A, 0x4E, 0x6A, 0xAC, 0x87, 0x2D, 0x4D, 0xA6, 0xAC, 0xFC, 0xFD, 0xAA, 0x25, 0x3F, 0x2D, 0xA1} };
#endif /* __IID_IEcoVFB1 */

typedef struct IEcoVFB1* IEcoVFB1Ptr_t;

typedef struct IEcoVFB1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoVFB1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoVFB1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoVFB1Ptr_t me);

    /* IEcoVFB1 */
    int16_t (ECOCALLMETHOD *Create)(/* in */ IEcoVFB1Ptr_t me, /* in */ uint32_t x, /* in */ uint32_t y,  /* in */ uint32_t width, /* in */ uint32_t height);
    int16_t (ECOCALLMETHOD *Read)(/* in */ IEcoVFB1Ptr_t me, /* out */ byte_t** buffer, /* in | out */ uint32_t* length);
    int16_t (ECOCALLMETHOD *Update)(/* in */ IEcoVFB1Ptr_t me, /* in */ byte_t* buffer, /* in */ uint32_t length);
    int16_t (ECOCALLMETHOD *Delete)(/* in */ IEcoVFB1Ptr_t me);
    int16_t (ECOCALLMETHOD *get_Mode)(/* in */ IEcoVFB1Ptr_t me, /* out */ ECO_VFB_1_SCREEN_MODE* pxScreenMode);

} IEcoVFB1VTbl, *IEcoVFB1VTblPtr;

interface IEcoVFB1 {
    struct IEcoVFB1VTbl *pVTbl;
} IEcoVFB1;


#endif /* __I_ECO_VIRTUAL_FRAME_BUFFER_1_H__ */
