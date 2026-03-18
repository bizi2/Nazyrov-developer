/*
 * <character encoding>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </character encoding>
 *
 * <summary>
 *   CEcoASNOnePER1_F509D9E8Factory
 * </summary>
 *
 * <description>
 *   This header describes the implementation of the factory for the component
 * </description>
 *
 * <author>
 *   Copyright (c) 2026 Vladimir Bashev. All rights reserved.
 * </author>
 *
 */

#ifndef __C_ECOASNONEPER1_FACTORY_H__
#define __C_ECOASNONEPER1_FACTORY_H__

#include "IEcoSystem1.h"

typedef struct CEcoASNOnePER1_F509D9E8Factory {

    /* IEcoComponentFactory interface function table */
    IEcoComponentFactoryVTbl* m_pVTblICF;

    /* Reference counter */
    uint32_t m_cRef;

    /* Component data for the factory */
    char_t m_Name[64];
    char_t m_Version[16];
    char_t m_Manufacturer[64];

} CEcoASNOnePER1_F509D9E8Factory;

#endif /* __C_ECOASNONEPER1_FACTORY_H__ */
