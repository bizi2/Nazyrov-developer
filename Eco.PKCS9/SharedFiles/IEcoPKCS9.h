/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoPKCS9
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoPKCS9
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

#ifndef __I_ECOPKCS9_H__
#define __I_ECOPKCS9_H__

#include "IEcoBase1.h"

/* IEcoPKCS9 IID = {5F47D7D0-96A1-49B1-A59D-4EAC20FDE88E} */
#ifndef __IID_IEcoPKCS9
static const UGUID IID_IEcoPKCS9 = {0x01, 0x10, {0x5F, 0x47, 0xD7, 0xD0, 0x96, 0xA1, 0x49, 0xB1, 0xA5, 0x9D, 0x4E, 0xAC, 0x20, 0xFD, 0xE8, 0x8E}};
#endif /* __IID_IEcoPKCS9 */

typedef struct IEcoPKCS9* IEcoPKCS9Ptr_t;

typedef struct IEcoPKCS9VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS9Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS9Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS9Ptr_t me);

    /* IEcoPKCS9 */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoPKCS9Ptr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoPKCS9VTbl, *IEcoPKCS9VTblPtr_t;

interface IEcoPKCS9 {
    struct IEcoPKCS9VTbl *pVTbl;
} IEcoPKCS9;

typedef struct IEcoPKCS9SMIMECapability* IEcoPKCS9SMIMECapabilityPtr_t;

typedef struct IEcoPKCS9SMIMECapabilityVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoPKCS9SMIMECapabilityPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoPKCS9SMIMECapabilityPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoPKCS9SMIMECapabilityPtr_t me);

    /* IEcoPKCS9SMIMECapability */
	
	//         algorithm  ALGORITHM.&id ({SMIMEv3Algorithms}),
    //         parameters ALGORITHM.&Type ({SMIMEv3Algorithms}{@algorithm})

} IEcoPKCS9SMIMECapabilityVTbl, *IEcoPKCS9SMIMECapabilityVTblPtr_t;

interface IEcoPKCS9SMIMECapability {
    struct IEcoPKCS9SMIMECapabilityVTbl *pVTbl;
} IEcoPKCS9SMIMECapability;




#endif /* __I_ECOPKCS9_H__ */
