/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSHA3
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSHA3
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

#ifndef __I_ECOSHA3_H__
#define __I_ECOSHA3_H__

#include "IEcoBase1.h"

/* IEcoSHA3 IID = {2EBABB98-EA18-49C2-8782-0C3DE6226359} */
#ifndef __IID_IEcoSHA3
static const UGUID IID_IEcoSHA3 = {0x01, 0x10, {0x2E, 0xBA, 0xBB, 0x98, 0xEA, 0x18, 0x49, 0xC2, 0x87, 0x82, 0x0C, 0x3D, 0xE6, 0x22, 0x63, 0x59}};
#endif /* __IID_IEcoSHA3 */

typedef struct IEcoSHA3* IEcoSHA3Ptr_t;

typedef struct IEcoSHA3VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoSHA3Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoSHA3Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoSHA3Ptr_t me);

    /* IEcoSHA3 */
    void (ECOCALLMETHOD *fnEncryptSHA3)(/*in*/ IEcoSHA3Ptr_t me, uint8_t* message, uint8_t* output);

} IEcoSHA3VTbl, *IEcoSHA3VTblPtr_t;

interface IEcoSHA3 {
    struct IEcoSHA3VTbl *pVTbl;
} IEcoSHA3;


#endif /* __I_ECOSHA3_H__ */
