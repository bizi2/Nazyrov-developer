/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoSHA3
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoSHA3
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

#ifndef __ID_ECOSHA3_H__
#define __ID_ECOSHA3_H__

#include "IEcoBase1.h"
#include "IEcoSHA3.h"

/* EcoSHA3 CID = {DACA298B-55FA-450D-8B38-C9B16EFC7840} */
#ifndef __CID_EcoSHA3
static const UGUID CID_EcoSHA3 = {0x01, 0x10, {0xDA, 0xCA, 0x29, 0x8B, 0x55, 0xFA, 0x45, 0x0D, 0x8B, 0x38, 0xC9, 0xB1, 0x6E, 0xFC, 0x78, 0x40}};
#endif /* __CID_EcoSHA3 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_DACA298B55FA450D8B38C9B16EFC7840;
#endif

#endif /* __ID_ECOSHA3_H__ */
