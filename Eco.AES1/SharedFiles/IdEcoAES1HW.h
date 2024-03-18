/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoAES1HW
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoAES1HW
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2023 Ivan Vinokurov. All rights reserved.
 * </автор>
 *
 */

#ifndef __ID_ECO_AES_1_HARDWARE_H__
#define __ID_ECO_AES_1_HARDWARE_H__

#include "IEcoBase1.h"
#include "IEcoAES1.h"

/* EcoAES1HW CID = {460D3A1D-3DD9-4949-95B3-CD799B716552} */
#ifndef __CID_EcoAES1HW
static const UGUID CID_EcoAES1HW = {0x01, 0x10, {0x46, 0x0D, 0x3A, 0x1D, 0x3D, 0xD9, 0x49, 0x49, 0x95, 0xB3, 0xCD, 0x79, 0x9B, 0x71, 0x65, 0x52}};
#endif /* __CID_EcoAES1HW */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_7C6C9BBB77724C6C9117540BE0872BD7;
#endif

#endif /* __ID_ECO_AES_1_HARDWARE_H__ */
