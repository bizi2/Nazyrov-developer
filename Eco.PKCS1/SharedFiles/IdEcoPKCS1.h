/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoPKCS1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoPKCS1
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

#ifndef __ID_ECOPKCS1_H__
#define __ID_ECOPKCS1_H__

#include "IEcoBase1.h"
#include "IEcoPKCS1.h"

/* EcoPKCS1 CID = {F48EB916-4869-4237-9670-2F3AA50FB39D} */
#ifndef __CID_EcoPKCS1
static const UGUID CID_EcoPKCS1 = {0x01, 0x10, {0xF4, 0x8E, 0xB9, 0x16, 0x48, 0x69, 0x42, 0x37, 0x96, 0x70, 0x2F, 0x3A, 0xA5, 0x0F, 0xB3, 0x9D}};
#endif /* __CID_EcoPKCS1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_F48EB9164869423796702F3AA50FB39D;
#endif

#endif /* __ID_ECOPKCS1_H__ */
