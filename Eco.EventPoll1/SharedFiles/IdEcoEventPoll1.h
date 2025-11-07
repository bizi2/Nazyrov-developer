/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoEventPoll1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoEventPoll1
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

#ifndef __ID_ECO_EVENT_POLL_1_H__
#define __ID_ECO_EVENT_POLL_1_H__

#include "IEcoBase1.h"
#include "IEcoEventPoll1.h"

/* EcoEventPoll1 CID = {777B4B25-8FDC-44C9-A54F-78A98339851F} */
#ifndef __CID_EcoEventPoll1
static const UGUID CID_EcoEventPoll1 = {0x01, 0x10, 0x77, 0x7B, 0x4B, 0x25, 0x8F, 0xDC, 0x44, 0xC9, 0xA5, 0x4F, 0x78, 0xA9, 0x83, 0x39, 0x85, 0x1F};
#endif /* __CID_EcoEventPoll1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_777B4B258FDC44C9A54F78A98339851F;
#endif

#endif /* __ID_ECO_EVENT_POLL_1_H__ */
