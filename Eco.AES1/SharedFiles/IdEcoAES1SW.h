/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoAES1SW
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoAES1SW
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2023 Ivan Vinokurov. All rights reserved.
 * </автор>
 *
 */

#ifndef __ID_ECO_AES_1_SOFTWARE_H__
#define __ID_ECO_AES_1_SOFTWARE_H__

#include "IEcoBase1.h"
#include "IEcoAES1.h"

/* EcoAES1SW CID = {7C6C9BBB-7772-4C6C-9117-540BE0872BD7} */
#ifndef __CID_EcoAES1SW
static const UGUID CID_EcoAES1SW = {0x01, 0x10, {0x7C, 0x6C, 0x9B, 0xBB, 0x77, 0x72, 0x4C, 0x6C, 0x91, 0x17, 0x54, 0x0B, 0xE0, 0x87, 0x2B, 0xD7}};
#endif /* __CID_EcoAES1SW */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_7C6C9BBB77724C6C9117540BE0872BD7;
#endif

#endif /* __ID_ECO_AES_1_SOFTWARE_H__ */
