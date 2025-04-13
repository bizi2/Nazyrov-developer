/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSSH1TLP
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSSH1TLP
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

#ifndef __I_ECO_SSH_1_TRANSPORT_LAYER_PROTOCOL_H__
#define __I_ECO_SSH_1_TRANSPORT_LAYER_PROTOCOL_H__

#include "IEcoBase1.h"

/* IEcoSSH1TLP IID = {9D5A03CC-CDF4-4BF0-BE7B-A3216C695842} */
#ifndef __IID_IEcoSSH1TLP
static const UGUID IID_IEcoSSH1TLP = {0x01, 0x10, {0x9D, 0x5A, 0x03, 0xCC, 0xCD, 0xF4, 0x4B, 0xF0, 0xBE, 0x7B, 0xA3, 0x21, 0x6C, 0x69, 0x58, 0x42}};
#endif /* __IID_IEcoSSH1TLP */

typedef struct IEcoSSH1TLP* IEcoSSH1TLPPtr_t;

typedef struct IEcoSSH1TLPVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoSSH1TLPPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoSSH1TLPPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoSSH1TLPPtr_t me);

    /* IEcoSSH1TLP */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoSSH1TLPPtr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoSSH1TLPVTbl, *IEcoSSH1TLPVTblPtr_t;

interface IEcoSSH1TLP {
    struct IEcoSSH1TLPVTbl *pVTbl;
} IEcoSSH1TLP;


#endif /* __I_ECO_SSH_1_TRANSPORT_LAYER_PROTOCOL_H__ */
