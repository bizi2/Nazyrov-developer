/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSystemTimer1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSystemTimer1
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

#ifndef __I_ECO_SYSTEM_TIMER_1_H__
#define __I_ECO_SYSTEM_TIMER_1_H__

#include "IEcoBase1.h"

/* IEcoSystemTimer1 IID = {A5ED60AE-D584-4AB5-AAF4-0694FC75FE94} */
#ifndef __IID_IEcoSystemTimer1
static const UGUID IID_IEcoSystemTimer1 = {0x01, 0x10, {0xa5, 0xed, 0x60, 0xae, 0xd5, 0x84, 0x4a, 0xb5, 0xaa, 0xf4, 0x6, 0x94, 0xfc, 0x75, 0xfe, 0x94}};
#endif /* __IID_IEcoSystemTimer1 */

#ifndef ECO_I_ECO_SYSTEM_TIMER_1_PTR_T_DEFINED
typedef struct IEcoSystemTimer1* IEcoSystemTimer1Ptr_t;
#define ECO_I_ECO_SYSTEM_TIMER_1_PTR_T_DEFINED
#endif

typedef struct IEcoSystemTimer1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoSystemTimer1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoSystemTimer1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoSystemTimer1Ptr_t me);

    /* IEcoSystemTimer1 */
    int8_t (ECOCALLMETHOD *set_TimeCounter)(/* in */ IEcoSystemTimer1Ptr_t me, /* in */ uint32_t high, /* in */ uint32_t low);
    int8_t (ECOCALLMETHOD *get_TimeCounter)(/* in */ IEcoSystemTimer1Ptr_t me, /* out */ uint32_t* high, /* out */ uint32_t* low);
    uint64_t (ECOCALLMETHOD *get_SingleTimerCounter)(/* in */ IEcoSystemTimer1Ptr_t me);

} IEcoSystemTimer1VTbl, *IEcoSystemTimer1VTblPtr;

interface IEcoSystemTimer1 {
    struct IEcoSystemTimer1VTbl *pVTbl;
} IEcoSystemTimer1;

#endif /* __I_ECO_SYSTEM_TIMER_1_H__ */
