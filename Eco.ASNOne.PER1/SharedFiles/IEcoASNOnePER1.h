/*
 * <character encoding>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </character encoding>
 *
 * <summary>
 *   IEcoASNOnePER1
 * </summary>
 *
 * <description>
 *   This header describes the interface IEcoASNOnePER1
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

#ifndef __I_ECOASNONEPER1_H__
#define __I_ECOASNONEPER1_H__

#include "IEcoBase1.h"

/* IEcoASNOnePER1 IID = {9750A886-3A34-47F7-B27F-DA947F903361} */
#ifndef __IID_IEcoASNOnePER1
static const UGUID IID_IEcoASNOnePER1 = {0x01, 0x10, {0x97, 0x50, 0xA8, 0x86, 0x3A, 0x34, 0x47, 0xF7, 0xB2, 0x7F, 0xDA, 0x94, 0x7F, 0x90, 0x33, 0x61}};
#endif /* __IID_IEcoASNOnePER1 */

typedef struct IEcoASNOnePER1* IEcoASNOnePER1Ptr_t;

typedef struct IEcoASNOnePER1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOnePER1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOnePER1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOnePER1Ptr_t me);

    /* IEcoASNOnePER1 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoASNOnePER1Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoASNOnePER1VTbl, *IEcoASNOnePER1VTblPtr_t;

interface IEcoASNOnePER1 {
    struct IEcoASNOnePER1VTbl *pVTbl;
} IEcoASNOnePER1;


#endif /* __I_ECOASNONEPER1_H__ */

