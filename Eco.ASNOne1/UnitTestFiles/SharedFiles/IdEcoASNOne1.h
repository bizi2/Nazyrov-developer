/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoASNOne1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoASNOne1
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

#ifndef __ID_ECO_ABSTRACT_SYNTAX_NOTATION_ONE_1_H__
#define __ID_ECO_ABSTRACT_SYNTAX_NOTATION_ONE_1_H__

#include "IEcoBase1.h"
#include "IEcoASNOne1.h"

/* EcoASNOne1 CID = {E0EA41D1-5682-4A40-877E-B6A011B2F7AB} */
#ifndef __CID_EcoASNOne1
static const UGUID CID_EcoASNOne1 = {0x01, 0x10, {0xE0, 0xEA, 0x41, 0xD1, 0x56, 0x82, 0x4A, 0x40, 0x87, 0x7E, 0xB6, 0xA0, 0x11, 0xB2, 0xF7, 0xAB}};
#endif /* __CID_EcoASNOne1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_E0EA41D156824A40877EB6A011B2F7AB;
#endif

#endif /* __ID_ECO_ABSTRACT_SYNTAX_NOTATION_ONE_1_H__ */
