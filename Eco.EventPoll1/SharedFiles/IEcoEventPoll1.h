/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoEventPoll1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoEventPoll1
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

#ifndef __I_ECO_EVENT_POLL_1_H__
#define __I_ECO_EVENT_POLL_1_H__

#include "IEcoBase1.h"

/* IEcoEventPoll1 IID = {CDD42270-0B2B-470C-ADDA-D8C752020BE4} */
#ifndef __IID_IEcoEventPoll1
static const UGUID IID_IEcoEventPoll1 = {0x01, 0x10, 0xCD, 0xD4, 0x22, 0x70, 0x0B, 0x2B, 0x47, 0x0C, 0xAD, 0xDA, 0xD8, 0xC7, 0x52, 0x02, 0x0B, 0xE4};
#endif /* __IID_IEcoEventPoll1 */

typedef struct IEcoEventPoll1VTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface)(/* in */ struct IEcoEventPoll1* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef)(/* in */ struct IEcoEventPoll1* me);
    uint32_t (*Release)(/* in */ struct IEcoEventPoll1* me);

    /* IEcoEventPoll1 */
    int16_t (*Add)(/* in */ struct IEcoEventPoll1* me, /* in */ descriptor_t fd);
    int16_t (*Mod)(/* in */ struct IEcoEventPoll1* me, /* in */ descriptor_t fd);
    int16_t (*Del)(/* in */ struct IEcoEventPoll1* me, /* in */ descriptor_t fd);
    int32_t (*Wait)(/* in */ struct IEcoEventPoll1* me, /* in */ int32_t maxevents, /* in */ int32_t timeout);
    int16_t (*Enum)(/* in */ struct IEcoEventPoll1* me, /* in */ int32_t number, /* out */ descriptor_t fd);

} IEcoEventPoll1VTbl, *IEcoEventPoll1VTblPtr;

interface IEcoEventPoll1 {
    struct IEcoEventPoll1VTbl *pVTbl;
} IEcoEventPoll1;


#endif /* __I_ECO_EVENT_POLL_1_H__ */
