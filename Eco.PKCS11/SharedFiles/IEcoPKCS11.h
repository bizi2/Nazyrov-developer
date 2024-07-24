/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoPKCS11
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoPKCS11
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

#ifndef __I_ECOPKCS11_H__
#define __I_ECOPKCS11_H__

#include "IEcoBase1.h"

/* IEcoPKCS11 IID = {3A6A72F1-D57C-4813-896C-87DB92B252FF} */
#ifndef __IID_IEcoPKCS11
static const UGUID IID_IEcoPKCS11 = {0x01, 0x10, {0x3A, 0x6A, 0x72, 0xF1, 0xD5, 0x7C, 0x48, 0x13, 0x89, 0x6C, 0x87, 0xDB, 0x92, 0xB2, 0x52, 0xFF}};
#endif /* __IID_IEcoPKCS11 */

typedef struct IEcoPKCS11* IEcoPKCS11Ptr_t;

typedef struct IEcoPKCS11VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS11Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS11Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS11Ptr_t me);

    /* IEcoPKCS11 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoPKCS11Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoPKCS11VTbl, *IEcoPKCS11VTblPtr_t;

interface IEcoPKCS11 {
    struct IEcoPKCS11VTbl *pVTbl;
} IEcoPKCS11;


#endif /* __I_ECOPKCS11_H__ */
