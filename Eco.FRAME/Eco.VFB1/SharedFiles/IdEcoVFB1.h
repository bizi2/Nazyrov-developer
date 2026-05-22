/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoVFB1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoVFB1
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

#ifndef __ID_ECO_VIRTUAL_FRAME_BUFFER_1_H__
#define __ID_ECO_VIRTUAL_FRAME_BUFFER_1_H__

#include "IEcoBase1.h"
#include "IEcoVFB1.h"

/* EcoVFB1 CID = {939B1DCD-B640-4F7D-9C07-2291AF252188} */
#ifndef __CID_EcoVFB1
static const UGUID CID_EcoVFB1 = {0x01, 0x10, {0x93, 0x9B, 0x1D, 0xCD, 0xB6, 0x40, 0x4F, 0x7D, 0x9C, 0x07, 0x22, 0x91, 0xAF, 0x25, 0x21, 0x88 } };
#endif /* __CID_EcoVFB1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_939B1DCDB6404F7D9C072291AF252188;
#endif

#endif /* __ID_ECO_VIRTUAL_FRAME_BUFFER_1_H__ */
