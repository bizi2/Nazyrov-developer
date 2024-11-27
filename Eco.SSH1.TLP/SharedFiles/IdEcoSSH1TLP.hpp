/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoSSH1TLP
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoSSH1TLP
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

#ifndef __ID_ECOSSH1TLP_HPP__
#define __ID_ECOSSH1TLP_HPP__

#include "IEcoBase1.hpp"
#include "IEcoSSH1TLP.hpp"

/* EcoSSH1TLP CID = {2B5F2AB4-2EDB-456B-90C4-9F4CAE11B435} */
#ifndef __CID_EcoSSH1TLP
static const UGUID CID_EcoSSH1TLP = {0x01, 0x10, {0x2B, 0x5F, 0x2A, 0xB4, 0x2E, 0xDB, 0x45, 0x6B, 0x90, 0xC4, 0x9F, 0x4C, 0xAE, 0x11, 0xB4, 0x35}};
#endif /* __CID_EcoSSH1TLP */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern "C" IEcoComponentFactory* GetIEcoComponentFactoryPtr_2B5F2AB42EDB456B90C49F4CAE11B435;
#endif

#endif /* __ID_ECOSSH1TLP_HPP__ */
