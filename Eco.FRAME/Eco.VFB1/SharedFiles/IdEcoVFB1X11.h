/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoVFB1X11
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoVFB1X11
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

#ifndef __ID_ECO_VIRTUAL_FRAME_BUFFER_1_X11_H__
#define __ID_ECO_VIRTUAL_FRAME_BUFFER_1_X11_H__

#include "IEcoBase1.h"
#include "IEcoVFB1.h"

/* EcoVFB1X11 CID = {34B0088A-7929-44CE-9386-EBFD0F8070EC} */
#ifndef __CID_EcoVFB1X11
static const UGUID CID_EcoVFB1X11 = {0x01, 0x10, {0x34, 0xB0, 0x08, 0x8A, 0x79, 0x29, 0x44, 0xCE, 0x93, 0x86, 0xEB, 0xFD, 0x0F, 0x80, 0x70, 0xEC} };
#endif /* __CID_EcoVFB1X11 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_34B0088A792944CE9386EBFD0F8070EC;
#endif

#endif /* __ID_ECO_VIRTUAL_FRAME_BUFFER_1_X11_H__ */
