/*
 * <character encoding>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </character encoding>
 *
 * <summary>
 *   CEcoASNOnePER1_F509D9E8
 * </summary>
 *
 * <description>
 *   This header describes the implementation of the CEcoASNOnePER1_F509D9E8 component
 * </description>
 *
 * <author>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </author>
 *
 */

#ifndef __C_ECOASNONEPER1_H__
#define __C_ECOASNONEPER1_H__

#include "IEcoASNOnePER1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoASNOnePER1_F509D9E8* CEcoASNOnePER1_F509D9E8Ptr_t;

typedef struct CEcoASNOnePER1_F509D9E8 {

    /* IEcoASNOnePER1 interface function table */
    IEcoASNOnePER1VTbl* m_pVTblIEcoASNOnePER1;


    /* Instance initialization */
    int16_t (ECOCALLMETHOD *Init)(/*in*/ CEcoASNOnePER1_F509D9E8Ptr_t pCMe, /* in */ IEcoUnknownPtr_t pIUnkSystem);
    /* Instance creation */
    int16_t (ECOCALLMETHOD *Create)(/*in*/ CEcoASNOnePER1_F509D9E8Ptr_t pCMe, /* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter);
    /* Deletion */
    void (ECOCALLMETHOD *Delete)(/*in*/ CEcoASNOnePER1_F509D9E8Ptr_t pCMe);


    /* Reference counter */
    uint32_t m_cRef;

    /* Interface for memory operations */
    IEcoMemoryAllocator1* m_pIMem;

    /* System interface */
    IEcoSystem1* m_pISys;

    /* Instance data */
    char_t* m_Name;

} CEcoASNOnePER1_F509D9E8;

#endif /* __C_ECOASNONEPER1_H__ */
