/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoRSA1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoRSA1
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

#ifndef __I_ECORSA1_H__
#define __I_ECORSA1_H__

#include "IEcoBase1.h"

/* IEcoRSA1 IID = {4275D59A-3C34-47E8-A29A-7400F4E9ED62} */
#ifndef __IID_IEcoRSA1
static const UGUID IID_IEcoRSA1 = {0x01, 0x10, {0x42, 0x75, 0xD5, 0x9A, 0x3C, 0x34, 0x47, 0xE8, 0xA2, 0x9A, 0x74, 0x00, 0xF4, 0xE9, 0xED, 0x62}};
#endif /* __IID_IEcoRSA1 */

typedef struct IEcoRSA1* IEcoRSA1Ptr_t;

typedef struct IEcoRSA1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoRSA1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoRSA1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoRSA1Ptr_t me);

    /* IEcoRSA1 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoRSA1Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoRSA1VTbl, *IEcoRSA1VTblPtr_t;

interface IEcoRSA1 {
    struct IEcoRSA1VTbl *pVTbl;
} IEcoRSA1;


#endif /* __I_ECORSA1_H__ */
