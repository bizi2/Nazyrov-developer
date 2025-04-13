/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoSSH1CP
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoSSH1CP
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

#ifndef __ID_ECOSSH1CP_HPP__
#define __ID_ECOSSH1CP_HPP__

#include "IEcoBase1.hpp"
#include "IEcoSSH1CP.hpp"

/* EcoSSH1CP CID = {C6AFCAA4-1667-4FCE-89F3-0674A203EFE6} */
#ifndef __CID_EcoSSH1CP
static const UGUID CID_EcoSSH1CP = {0x01, 0x10, {0xC6, 0xAF, 0xCA, 0xA4, 0x16, 0x67, 0x4F, 0xCE, 0x89, 0xF3, 0x06, 0x74, 0xA2, 0x03, 0xEF, 0xE6}};
#endif /* __CID_EcoSSH1CP */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern "C" IEcoComponentFactory* GetIEcoComponentFactoryPtr_C6AFCAA416674FCE89F30674A203EFE6;
#endif

#endif /* __ID_ECOSSH1CP_HPP__ */
