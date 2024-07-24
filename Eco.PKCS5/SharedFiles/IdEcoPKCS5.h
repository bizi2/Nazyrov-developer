/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoPKCS5
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoPKCS5
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

#ifndef __ID_ECOPKCS5_H__
#define __ID_ECOPKCS5_H__

#include "IEcoBase1.h"
#include "IEcoPKCS5.h"

/* EcoPKCS5 CID = {D5D671F9-2770-4268-9D64-A8F71CF80E6C} */
#ifndef __CID_EcoPKCS5
static const UGUID CID_EcoPKCS5 = {0x01, 0x10, {0xD5, 0xD6, 0x71, 0xF9, 0x27, 0x70, 0x42, 0x68, 0x9D, 0x64, 0xA8, 0xF7, 0x1C, 0xF8, 0x0E, 0x6C}};
#endif /* __CID_EcoPKCS5 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_D5D671F9277042689D64A8F71CF80E6C;
#endif

#endif /* __ID_ECOPKCS5_H__ */
