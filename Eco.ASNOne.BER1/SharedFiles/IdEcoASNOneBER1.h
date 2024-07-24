/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoASNOneBER1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoASNOneBER1
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

#ifndef __ID_ECO_ASN_ONE_BER_1_H__
#define __ID_ECO_ASN_ONE_BER_1_H__

#include "IEcoBase1.h"
#include "IEcoASNOneBER1.h"

/* EcoASNOneBER1 CID = {2C2F66F4-4986-4F50-9444-C0F7CBE9F1CB} */
#ifndef __CID_EcoASNOneBER1
static const UGUID CID_EcoASNOneBER1 = {0x01, 0x10, 0x2C, 0x2F, 0x66, 0xF4, 0x49, 0x86, 0x4F, 0x50, 0x94, 0x44, 0xC0, 0xF7, 0xCB, 0xE9, 0xF1, 0xCB};
#endif /* __CID_EcoASNOneBER1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_2C2F66F449864F509444C0F7CBE9F1CB;
#endif

#endif /* __ID_ECO_ASN_ONE_BER_1_H__ */
