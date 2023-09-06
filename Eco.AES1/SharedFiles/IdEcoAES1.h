/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoAES1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoAES1
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

#ifndef __ID_ECOAES1_H__
#define __ID_ECOAES1_H__

#include "IEcoBase1.h"
#include "IEcoAES1.h"

/* EcoAES1 CID = {7C6C9BBB-7772-4C6C-9117-540BE0872BD7} */
#ifndef __CID_EcoAES1
static const UGUID CID_EcoAES1 = {0x01, 0x10, {0x7C, 0x6C, 0x9B, 0xBB, 0x77, 0x72, 0x4C, 0x6C, 0x91, 0x17, 0x54, 0x0B, 0xE0, 0x87, 0x2B, 0xD7}};
#endif /* __CID_EcoAES1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_7C6C9BBB77724C6C9117540BE0872BD7;
#endif

#endif /* __ID_ECOAES1_H__ */
