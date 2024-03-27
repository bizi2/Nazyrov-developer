/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoBaseEncoding1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoBaseEncoding1
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

#ifndef __ID_ECOBASEENCODING1_H__
#define __ID_ECOBASEENCODING1_H__

#include "IEcoBase1.h"
#include "IEcoBaseEncoding1.h"

/* EcoBaseEncoding1 CID = {31BC4FAD-67EF-41DB-9568-7999343447F8} */
#ifndef __CID_EcoBaseEncoding1
static const UGUID CID_EcoBaseEncoding1 = {0x01, 0x10, {0x31, 0xBC, 0x4F, 0xAD, 0x67, 0xEF, 0x41, 0xDB, 0x95, 0x68, 0x79, 0x99, 0x34, 0x34, 0x47, 0xF8}};
#endif /* __CID_EcoBaseEncoding1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_31BC4FAD67EF41DB95687999343447F8;
#endif

#endif /* __ID_ECOBASEENCODING1_H__ */
