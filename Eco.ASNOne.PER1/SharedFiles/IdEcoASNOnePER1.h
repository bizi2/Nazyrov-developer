/*
 * <character encoding>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </character encoding>
 *
 * <summary>
 *   IdEcoASNOnePER1
 * </summary>
 *
 * <description>
 *   This header describes the interface IdEcoASNOnePER1
 * </description>
 *
 * <reference>
 *
 * </reference>
 *
 * <author>
 *   Copyright (c) 2026 Vladimir Bashev. All rights reserved.
 * </author>
 *
 */

#ifndef __ID_ECOASNONEPER1_H__
#define __ID_ECOASNONEPER1_H__

#include "IEcoBase1.h"
#include "IEcoASNOnePER1.h"

/* EcoASNOnePER1 CID = {4E050E5A-92C6-453F-8146-6375F509D9E8} */
#ifndef __CID_EcoASNOnePER1
static const UGUID CID_EcoASNOnePER1 = {0x01, 0x10, {0x4E, 0x05, 0x0E, 0x5A, 0x92, 0xC6, 0x45, 0x3F, 0x81, 0x46, 0x63, 0x75, 0xF5, 0x09, 0xD9, 0xE8}};
#endif /* __CID_EcoASNOnePER1 */

/* Component factory for dynamic and static layout */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_4E050E5A92C6453F81466375F509D9E8;
#endif

#endif /* __ID_ECOASNONEPER1_H__ */

