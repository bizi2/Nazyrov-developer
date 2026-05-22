/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoTimer1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoTimer1
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

#ifndef __ID_ECO_TIMER_1_H__
#define __ID_ECO_TIMER_1_H__

#include "IEcoBase1.h"
#include "IEcoTimer1.h"

/* EcoTimer1 CID = {8DB93F3D-F5B9-47D4-A67F-7C100B569723} */
#ifndef __CID_EcoTimer1
static const UGUID CID_EcoTimer1 = {0x01, 0x10, {0x8D, 0xB9, 0x3F, 0x3D, 0xF5, 0xB9, 0x47, 0xD4, 0xA6, 0x7F, 0x7C, 0x10, 0x0B, 0x56, 0x97, 0x23}};
#endif /* __CID_EcoTimer1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_8DB93F3DF5B947D4A67F7C100B569723;
#endif

#endif /* __ID_ECO_TIMER_1_H__ */
