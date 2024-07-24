/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoPKCS8
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoPKCS8
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

#ifndef __ID_ECOPKCS8_H__
#define __ID_ECOPKCS8_H__

#include "IEcoBase1.h"
#include "IEcoPKCS8.h"

/* EcoPKCS8 CID = {C59F9A8D-F5F5-4003-8C40-5629A0A4CE6B} */
#ifndef __CID_EcoPKCS8
static const UGUID CID_EcoPKCS8 = {0x01, 0x10, {0xC5, 0x9F, 0x9A, 0x8D, 0xF5, 0xF5, 0x40, 0x03, 0x8C, 0x40, 0x56, 0x29, 0xA0, 0xA4, 0xCE, 0x6B}};
#endif /* __CID_EcoPKCS8 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_C59F9A8DF5F540038C405629A0A4CE6B;
#endif

#endif /* __ID_ECOPKCS8_H__ */
