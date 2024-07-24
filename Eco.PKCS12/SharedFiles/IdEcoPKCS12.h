/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoPKCS12
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoPKCS12
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

#ifndef __ID_ECOPKCS12_H__
#define __ID_ECOPKCS12_H__

#include "IEcoBase1.h"
#include "IEcoPKCS12.h"

/* EcoPKCS12 CID = {E1A079DC-8EBD-4B92-9697-C9B82BFE6209} */
#ifndef __CID_EcoPKCS12
static const UGUID CID_EcoPKCS12 = {0x01, 0x10, {0xE1, 0xA0, 0x79, 0xDC, 0x8E, 0xBD, 0x4B, 0x92, 0x96, 0x97, 0xC9, 0xB8, 0x2B, 0xFE, 0x62, 0x09}};
#endif /* __CID_EcoPKCS12 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_E1A079DC8EBD4B929697C9B82BFE6209;
#endif

#endif /* __ID_ECOPKCS12_H__ */
