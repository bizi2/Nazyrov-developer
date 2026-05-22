/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoVFB1ScreenInfo
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoVFB1ScreenInfo
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

#ifndef __I_ECO_VIRTUAL_FRAME_BUFFER_1_SCREEN_INFO__H__
#define __I_ECO_VIRTUAL_FRAME_BUFFER_1_SCREEN_INFO__H__

#include "IEcoBase1.h"

typedef struct ECO_VFB_1_SCREEN_MODE {

    uint32_t Width;
    uint32_t Height;
    uint32_t Bits;
    uint32_t Frequency;
    uint32_t Orientation;
} ECO_VFB_1_SCREEN_MODE;

/* IEcoVFB1ScreenInfo IID = {E6EF4A87-348D-493F-819D-F38FECCC8719} */
#ifndef __IID_IEcoVFB1ScreenInfo
static const UGUID IID_IEcoVFB1ScreenInfo = {0x01, 0x10, {0xE6, 0xEF, 0x4A, 0x87, 0x34, 0x8D, 0x49, 0x3F, 0x81, 0x9D, 0xF3, 0x8F, 0xEC, 0xCC, 0x87, 0x19}};
#endif /* __IID_IEcoVFB1ScreenInfo */

typedef struct IEcoVFB1ScreenInfo* IEcoVFB1ScreenInfoPtr_t;

typedef struct IEcoVFB1ScreenInfoVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoVFB1ScreenInfoPtr_t me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoVFB1ScreenInfoPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoVFB1ScreenInfoPtr_t me);

    /* IEcoVFB1ScreenInfo */
    int16_t (ECOCALLMETHOD *EnumSettings)(/* in */ IEcoVFB1ScreenInfoPtr_t me, /* in */ uint16_t uiModeNumber, /* out */ ECO_VFB_1_SCREEN_MODE* pxScreenMode);
    int16_t (ECOCALLMETHOD *get_Mode)(/* in */ IEcoVFB1ScreenInfoPtr_t me, /* out */ ECO_VFB_1_SCREEN_MODE* pxScreenMode, /* out */ bool_t* pbFullScreen);
    int16_t (ECOCALLMETHOD *set_Mode)(/* in */ IEcoVFB1ScreenInfoPtr_t me, /* in */ ECO_VFB_1_SCREEN_MODE* pxScreenMode, /* in */ bool_t bFullScreen);

} IEcoVFB1ScreenInfoVTbl, *IEcoVFB1ScreenInfoVTblPtr;

interface IEcoVFB1ScreenInfo {
    struct IEcoVFB1ScreenInfoVTbl *pVTbl;
} IEcoVFB1ScreenInfo;


#endif /* __I_ECO_VIRTUAL_FRAME_BUFFER_1_SCREEN_INFO__H__ */
