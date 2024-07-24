/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoPKCS10
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoPKCS10
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

#ifndef __ID_ECOPKCS10_H__
#define __ID_ECOPKCS10_H__

#include "IEcoBase1.h"
#include "IEcoPKCS10.h"

/* EcoPKCS10 CID = {90CED7F8-304E-4E23-9883-6815768F3B93} */
#ifndef __CID_EcoPKCS10
static const UGUID CID_EcoPKCS10 = {0x01, 0x10, {0x90, 0xCE, 0xD7, 0xF8, 0x30, 0x4E, 0x4E, 0x23, 0x98, 0x83, 0x68, 0x15, 0x76, 0x8F, 0x3B, 0x93}};
#endif /* __CID_EcoPKCS10 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_90CED7F8304E4E2398836815768F3B93;
#endif

#endif /* __ID_ECOPKCS10_H__ */
