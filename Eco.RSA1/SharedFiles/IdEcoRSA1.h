/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoRSA1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoRSA1
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

#ifndef __ID_ECORSA1_H__
#define __ID_ECORSA1_H__

#include "IEcoBase1.h"
#include "IEcoRSA1.h"

/* EcoRSA1 CID = {79FA67D3-DEBD-44D6-9F59-262E3C4F4509} */
#ifndef __CID_EcoRSA1
static const UGUID CID_EcoRSA1 = {0x01, 0x10, {0x79, 0xFA, 0x67, 0xD3, 0xDE, 0xBD, 0x44, 0xD6, 0x9F, 0x59, 0x26, 0x2E, 0x3C, 0x4F, 0x45, 0x09}};
#endif /* __CID_EcoRSA1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_79FA67D3DEBD44D69F59262E3C4F4509;
#endif

#endif /* __ID_ECORSA1_H__ */
