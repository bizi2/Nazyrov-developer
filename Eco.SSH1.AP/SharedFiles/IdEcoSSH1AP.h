/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoSSH1AP
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoSSH1AP
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

#ifndef __ID_ECO_SSH_1_AUTHENTICATION_PROTOCOL_H__
#define __ID_ECO_SSH_1_AUTHENTICATION_PROTOCOL_H__

#include "IEcoBase1.h"
#include "IEcoSSH1AP.h"

/* EcoSSH1AP CID = {D8D5E0FE-0EC6-4CF9-8F5F-E31BDBDD7F7A} */
#ifndef __CID_EcoSSH1AP
static const UGUID CID_EcoSSH1AP = {0x01, 0x10, {0xD8, 0xD5, 0xE0, 0xFE, 0x0E, 0xC6, 0x4C, 0xF9, 0x8F, 0x5F, 0xE3, 0x1B, 0xDB, 0xDD, 0x7F, 0x7A}};
#endif /* __CID_EcoSSH1AP */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_D8D5E0FE0EC64CF98F5FE31BDBDD7F7A;
#endif

#endif /* __ID_ECO_SSH_1_AUTHENTICATION_PROTOCOL_H__ */
