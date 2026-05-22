/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoVFB1DRM
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoVFB1DRM
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

#ifndef __ID_ECO_VIRTUAL_FRAME_BUFFER_1_DRM_H__
#define __ID_ECO_VIRTUAL_FRAME_BUFFER_1_DRM_H__

#include "IEcoBase1.h"
#include "IEcoVFB1.h"

/* EcoVFB1DRM CID = {450F7464-A011-4459-A972-51544D208F5D} */
#ifndef __CID_EcoVFB1DRM
static const UGUID CID_EcoVFB1DRM = {0x01, 0x10, {0x45, 0x0F, 0x74, 0x64, 0xA0, 0x11, 0x44, 0x59, 0xA9, 0x72, 0x51, 0x54, 0x4D, 0x20, 0x8F, 0x5D} };
#endif /* __CID_EcoVFB1DRM */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_450F7464A0114459A97251544D208F5D;
#endif

#endif /* __ID_ECO_VIRTUAL_FRAME_BUFFER_1_DRM_H__ */
