/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoPKCS9
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoPKCS9
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

#ifndef __ID_ECOPKCS9_H__
#define __ID_ECOPKCS9_H__

#include "IEcoBase1.h"
#include "IEcoPKCS9.h"

/* EcoPKCS9 CID = {469ACC53-F45E-4ACA-B004-17E1F5201646} */
#ifndef __CID_EcoPKCS9
static const UGUID CID_EcoPKCS9 = {0x01, 0x10, {0x46, 0x9A, 0xCC, 0x53, 0xF4, 0x5E, 0x4A, 0xCA, 0xB0, 0x04, 0x17, 0xE1, 0xF5, 0x20, 0x16, 0x46}};
#endif /* __CID_EcoPKCS9 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_469ACC53F45E4ACAB00417E1F5201646;
#endif

#endif /* __ID_ECOPKCS9_H__ */
