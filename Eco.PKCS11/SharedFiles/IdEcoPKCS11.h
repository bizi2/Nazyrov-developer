/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoPKCS11
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoPKCS11
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

#ifndef __ID_ECOPKCS11_H__
#define __ID_ECOPKCS11_H__

#include "IEcoBase1.h"
#include "IEcoPKCS11.h"

/* EcoPKCS11 CID = {D6D7F52D-FCB6-43F9-BA1E-56293EB0FA6E} */
#ifndef __CID_EcoPKCS11
static const UGUID CID_EcoPKCS11 = {0x01, 0x10, {0xD6, 0xD7, 0xF5, 0x2D, 0xFC, 0xB6, 0x43, 0xF9, 0xBA, 0x1E, 0x56, 0x29, 0x3E, 0xB0, 0xFA, 0x6E}};
#endif /* __CID_EcoPKCS11 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_D6D7F52DFCB643F9BA1E56293EB0FA6E;
#endif

#endif /* __ID_ECOPKCS11_H__ */
