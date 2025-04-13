/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSSH1CP
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSSH1CP
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

#ifndef __I_ECO_SSH_1_CONNECTION_PROTOCOL_H__
#define __I_ECO_SSH_1_CONNECTION_PROTOCOL_H__

#include "IEcoBase1.h"

/* IEcoSSH1CP IID = {58182FFD-6184-45A0-B72D-DF702C45F1EC} */
#ifndef __IID_IEcoSSH1CP
static const UGUID IID_IEcoSSH1CP = {0x01, 0x10, {0x58, 0x18, 0x2F, 0xFD, 0x61, 0x84, 0x45, 0xA0, 0xB7, 0x2D, 0xDF, 0x70, 0x2C, 0x45, 0xF1, 0xEC}};
#endif /* __IID_IEcoSSH1CP */

typedef struct IEcoSSH1CP* IEcoSSH1CPPtr_t;

typedef struct IEcoSSH1CPVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoSSH1CPPtr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoSSH1CPPtr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoSSH1CPPtr_t me);

    /* IEcoSSH1CP */
    int16_t (ECOCALLMETHOD *MyFunction)(/* in */ IEcoSSH1CPPtr_t me, /* in */ char_t* Name, /* out */ char_t** CopyName);

} IEcoSSH1CPVTbl, *IEcoSSH1CPVTblPtr_t;

interface IEcoSSH1CP {
    struct IEcoSSH1CPVTbl *pVTbl;
} IEcoSSH1CP;


#endif /* __I_ECO_SSH_1_CONNECTION_PROTOCOL_H__ */
