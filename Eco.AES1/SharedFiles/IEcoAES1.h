/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoAES1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoAES1
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

#ifndef __I_ECOAES1_H__
#define __I_ECOAES1_H__

#include "IEcoBase1.h"

/* IEcoAES1 IID = {84F33CD4-6FEC-4788-B062-F86A7D65BC4B} */
#ifndef __IID_IEcoAES1
static const UGUID IID_IEcoAES1 = {0x01, 0x10, {0x84, 0xF3, 0x3C, 0xD4, 0x6F, 0xEC, 0x47, 0x88, 0xB0, 0x62, 0xF8, 0x6A, 0x7D, 0x65, 0xBC, 0x4B}};
#endif /* __IID_IEcoAES1 */

typedef struct IEcoAES1* IEcoAES1Ptr_t;
typedef uint8_t state_t[4][4];

typedef struct IEcoAES1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoAES1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoAES1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoAES1Ptr_t me);

    /* IEcoAES1 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoAES1Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);
    void (ECOCALLMETHOD *fnAESEncrypt)(IEcoAES1Ptr_t me, uint8_t* _roundKey, uint8_t* _buf);
    void (ECOCALLMETHOD *fnAESDecrypt)(IEcoAES1Ptr_t me, uint8_t* _roundKey, uint8_t* _buf);
    void (ECOCALLMETHOD *fnAESInitCtx)(IEcoAES1Ptr_t me, uint8_t* _roundKey, uint8_t* _key);

} IEcoAES1VTbl, *IEcoAES1VTblPtr_t;

interface IEcoAES1 {
    struct IEcoAES1VTbl *pVTbl;
} IEcoAES1;


#endif /* __I_ECOAES1_H__ */
