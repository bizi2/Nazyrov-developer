/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoDiffieHellman1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoDiffieHellman1
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

#ifndef __ID_ECODIFFIEHELLMAN1_HPP__
#define __ID_ECODIFFIEHELLMAN1_HPP__

#include "IEcoBase1.hpp"
#include "IEcoDiffieHellman1.hpp"

/* EcoDiffieHellman1 CID = {E28A3709-C7C6-4253-9BE1-5A46BFB8A295} */
#ifndef __CID_EcoDiffieHellman1
static const UGUID CID_EcoDiffieHellman1 = {0x01, 0x10, {0xE2, 0x8A, 0x37, 0x09, 0xC7, 0xC6, 0x42, 0x53, 0x9B, 0xE1, 0x5A, 0x46, 0xBF, 0xB8, 0xA2, 0x95}};
#endif /* __CID_EcoDiffieHellman1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern "C" IEcoComponentFactory* GetIEcoComponentFactoryPtr_E28A3709C7C642539BE15A46BFB8A295;
#endif

#endif /* __ID_ECODIFFIEHELLMAN1_HPP__ */
