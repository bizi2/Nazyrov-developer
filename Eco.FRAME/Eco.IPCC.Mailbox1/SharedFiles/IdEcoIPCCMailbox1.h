/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoIPCCMailbox1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoIPCCMailbox1
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

#ifndef __ID_ECO_IPCC_MAILBOX_1_H__
#define __ID_ECO_IPCC_MAILBOX_1_H__

#include "IEcoBase1.h"
#include "IEcoIPCCMailbox1.h"

/* EcoIPCCMailbox1 CID = {F10BC39A-4F21-43CF-8A1E-104650A2C302} */
#ifndef __CID_EcoIPCCMailbox1
static const UGUID CID_EcoIPCCMailbox1 = {0x01, 0x10, {0xF1, 0x0B, 0xC3, 0x9A, 0x4F, 0x21, 0x43, 0xCF, 0x8A, 0x1E, 0x10, 0x46, 0x50, 0xA2, 0xC3, 0x02}};
#endif /* __CID_EcoIPCCMailbox1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_F10BC39A4F2143CF8A1E104650A2C302;
#endif

#endif /* __ID_ECO_IPCC_MAILBOX_1_H__ */

