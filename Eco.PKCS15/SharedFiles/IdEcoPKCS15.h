/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoPKCS15
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoPKCS15
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

#ifndef __ID_ECOPKCS15_H__
#define __ID_ECOPKCS15_H__

#include "IEcoBase1.h"
#include "IEcoPKCS15.h"

/* EcoPKCS15 CID = {8C42FB15-E103-4E7B-8715-73464AEAEFDB} */
#ifndef __CID_EcoPKCS15
static const UGUID CID_EcoPKCS15 = {0x01, 0x10, {0x8C, 0x42, 0xFB, 0x15, 0xE1, 0x03, 0x4E, 0x7B, 0x87, 0x15, 0x73, 0x46, 0x4A, 0xEA, 0xEF, 0xDB}};
#endif /* __CID_EcoPKCS15 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_8C42FB15E1034E7B871573464AEAEFDB;
#endif

#endif /* __ID_ECOPKCS15_H__ */
