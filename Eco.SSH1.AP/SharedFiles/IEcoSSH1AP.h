/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSSH1AP
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSSH1AP
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

#ifndef __I_ECO_SSH_1_AUTHENTICATION_PROTOCOL_H__
#define __I_ECO_SSH_1_AUTHENTICATION_PROTOCOL_H__

#include "IEcoBase1.h"

/* IEcoSSH1AP IID = {85CA4410-DBD3-4788-979B-78D0D7DD18CC} */
#ifndef __IID_IEcoSSH1AP
static const UGUID IID_IEcoSSH1AP = {0x01, 0x10, {0x85, 0xCA, 0x44, 0x10, 0xDB, 0xD3, 0x47, 0x88, 0x97, 0x9B, 0x78, 0xD0, 0xD7, 0xDD, 0x18, 0xCC}};
#endif /* __IID_IEcoSSH1AP */

typedef struct IEcoSSH1AP* IEcoSSH1APPtr_t;

typedef struct IEcoSSH1APVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoSSH1APPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoSSH1APPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoSSH1APPtr_t me);

    /* IEcoSSH1AP */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoSSH1APPtr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoSSH1APVTbl, *IEcoSSH1APVTblPtr_t;

interface IEcoSSH1AP {
    struct IEcoSSH1APVTbl *pVTbl;
} IEcoSSH1AP;


#endif /* __I_ECO_SSH_1_AUTHENTICATION_PROTOCOL_H__ */
