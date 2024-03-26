/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoMD5
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoMD5
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

#ifndef __I_ECOMD5_H__
#define __I_ECOMD5_H__

#include "IEcoBase1.h"

/* IEcoMD5 IID = {3B1DB870-DD5A-46A2-B716-848B45F6D148} */
#ifndef __IID_IEcoMD5
static const UGUID IID_IEcoMD5 = {0x01, 0x10, {0x3B, 0x1D, 0xB8, 0x70, 0xDD, 0x5A, 0x46, 0xA2, 0xB7, 0x16, 0x84, 0x8B, 0x45, 0xF6, 0xD1, 0x48}};
#endif /* __IID_IEcoMD5 */

typedef struct IEcoMD5* IEcoMD5Ptr_t;

typedef struct IEcoMD5VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoMD5Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoMD5Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoMD5Ptr_t me);

    /* IEcoMD5 */
    void (ECOCALLMETHOD *fnEncryptMD5)(/*in*/ IEcoMD5Ptr_t me, uint8_t* input, uint8_t* output);

} IEcoMD5VTbl, *IEcoMD5VTblPtr_t;

interface IEcoMD5 {
    struct IEcoMD5VTbl *pVTbl;
} IEcoMD5;


#endif /* __I_ECOMD5_H__ */
