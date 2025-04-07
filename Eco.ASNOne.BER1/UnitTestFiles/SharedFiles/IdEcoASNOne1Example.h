/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoASNOne1Example
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoASNOne1Example
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

#ifndef __ID_ECO_ASN_ONE_1_EXAMPLE_H__
#define __ID_ECO_ASN_ONE_1_EXAMPLE_H__

#include "IEcoBase1.h"
#include "IEcoASNOne1Example.h"

/* EcoASNOne1Example CID = {CC01E1FC-921E-4B1C-93C6-AA45247D52F9} */
#ifndef __CID_EcoASNOne1Example
static const UGUID CID_EcoASNOne1Example = {0x01, 0x10, {0xCC, 0x01, 0xE1, 0xFC, 0x92, 0x1E, 0x4B, 0x1C, 0x93, 0xC6, 0xAA, 0x45, 0x24, 0x7D, 0x52, 0xF9}};
#endif /* __CID_EcoASNOne1Example */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_CC01E1FC921E4B1C93C6AA45247D52F9;
#endif

#endif /* __ID_ECO_ASN_ONE_1_EXAMPLE_H__ */
