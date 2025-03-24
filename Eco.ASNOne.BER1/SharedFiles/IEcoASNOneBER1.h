/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoASNOneBER1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoASNOneBER1
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

#ifndef __I_ECO_ASN_ONE_BER_1_H__
#define __I_ECO_ASN_ONE_BER_1_H__

#include "IEcoBase1.h"

/* IEcoASNOneBER1 IID = {0CE27186-6EA7-4C04-9528-2B0A4C427BBF} */
#ifndef __IID_IEcoASNOneBER1
static const UGUID IID_IEcoASNOneBER1 = {0x01, 0x10, 0x0C, 0xE2, 0x71, 0x86, 0x6E, 0xA7, 0x4C, 0x04, 0x95, 0x28, 0x2B, 0x0A, 0x4C, 0x42, 0x7B, 0xBF};
#endif /* __IID_IEcoASNOneBER1 */

typedef struct IEcoASNOneBER1VTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface)(/* in */ struct IEcoASNOneBER1* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef)(/* in */ struct IEcoASNOneBER1* me);
    uint32_t (*Release)(/* in */ struct IEcoASNOneBER1* me);

    /* IEcoASNOneBER1 */
    int16_t (*MyFunction)(/* in */ struct IEcoASNOneBER1* me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoASNOneBER1VTbl, *IEcoASNOneBER1VTblPtr;

interface IEcoASNOneBER1 {
    struct IEcoASNOneBER1VTbl *pVTbl;
} IEcoASNOneBER1;

#endif /* __I_ECO_ASN_ONE_BER_1_H__ */
