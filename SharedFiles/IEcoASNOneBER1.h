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

typedef union ECO_ASN1_IDENTIFIER_OCTET {
    struct {
        uint8_t TagNumber   : 5;    /* Tag number */
        uint8_t PC          : 1;    /* P/C enc. rules */
        uint8_t Class       : 2;    /* Class */
    } bits;
    uint8_t byte;
} ECO_ASN1_IDENTIFIER_OCTET;


/* IEcoASNOneBER1 IID = {0CE27186-6EA7-4C04-9528-2B0A4C427BBF} */
#ifndef __IID_IEcoASNOneBER1
static const UGUID IID_IEcoASNOneBER1 = {0x01, 0x10, {0x0C, 0xE2, 0x71, 0x86, 0x6E, 0xA7, 0x4C, 0x04, 0x95, 0x28, 0x2B, 0x0A, 0x4C, 0x42, 0x7B, 0xBF}};
#endif /* __IID_IEcoASNOneBER1 */

typedef struct IEcoASNOneBER1* IEcoASNOneBER1Ptr_t;

typedef struct IEcoASNOneBER1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoASNOneBER1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoASNOneBER1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoASNOneBER1Ptr_t me);

    /* IEcoASNOneEncodingRules */
    int16_t (ECOCALLMETHOD *Encode)(/* in */ IEcoASNOneBER1Ptr_t me, /* in */ voidptr_t pv, /* out */ byte_t** buffer, /* out */ uint32_t* length);
    int16_t (ECOCALLMETHOD *Decode)(/* in */ IEcoASNOneBER1Ptr_t me, /* in */ byte_t* buffer, /* in | out */ uint32_t* length, /* out */ voidptr_t* ppv);

} IEcoASNOneBER1VTbl, *IEcoASNOneBER1VTblPtr;

interface IEcoASNOneBER1 {
    struct IEcoASNOneBER1VTbl *pVTbl;
} IEcoASNOneBER1;

#endif /* __I_ECO_ASN_ONE_BER_1_H__ */
