/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoPKCS7
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoPKCS7
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

#ifndef __ID_ECOPKCS7_H__
#define __ID_ECOPKCS7_H__

#include "IEcoBase1.h"
#include "IEcoPKCS7.h"

/* EcoPKCS7 CID = {7BC48E42-7BF5-43D8-B5FB-2DEE6EA80DA5} */
#ifndef __CID_EcoPKCS7
static const UGUID CID_EcoPKCS7 = {0x01, 0x10, {0x7B, 0xC4, 0x8E, 0x42, 0x7B, 0xF5, 0x43, 0xD8, 0xB5, 0xFB, 0x2D, 0xEE, 0x6E, 0xA8, 0x0D, 0xA5}};
#endif /* __CID_EcoPKCS7 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_7BC48E427BF543D8B5FB2DEE6EA80DA5;
#endif

#endif /* __ID_ECOPKCS7_H__ */
