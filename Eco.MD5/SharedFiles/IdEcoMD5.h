/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoMD5
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoMD5
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

#ifndef __ID_ECOMD5_H__
#define __ID_ECOMD5_H__

#include "IEcoBase1.h"
#include "IEcoMD5.h"

/* EcoMD5 CID = {26DAFD57-A2AA-4C3B-838C-CC965D90ACD0} */
#ifndef __CID_EcoMD5
static const UGUID CID_EcoMD5 = {0x01, 0x10, {0x26, 0xDA, 0xFD, 0x57, 0xA2, 0xAA, 0x4C, 0x3B, 0x83, 0x8C, 0xCC, 0x96, 0x5D, 0x90, 0xAC, 0xD0}};
#endif /* __CID_EcoMD5 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_26DAFD57A2AA4C3B838CCC965D90ACD0;
#endif

#endif /* __ID_ECOMD5_H__ */
