/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoTimer1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoTimer1
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

#ifndef __I_ECO_TIMER_1_H__
#define __I_ECO_TIMER_1_H__

#include "IEcoBase1.h"

typedef voidptr_t IEcoInterruptVector1;

/* IEcoTimer1 IID = {0731D74E-4B02-4E87-BD2E-4E9CD94445BC} */
#ifndef __IID_IEcoTimer1
static const UGUID IID_IEcoTimer1 = {0x01, 0x10, {0x07, 0x31, 0xD7, 0x4E, 0x4B, 0x02, 0x4E, 0x87, 0xBD, 0x2E, 0x4E, 0x9C, 0xD9, 0x44, 0x45, 0xBC} };
#endif /* __IID_IEcoTimer1 */

#ifndef ECO_I_ECO_TIMER_1_PTR_T_DEFINED
typedef struct IEcoTimer1* IEcoTimer1Ptr_t;
#define ECO_I_ECO_TIMER_1_PTR_T_DEFINED
#endif

typedef struct IEcoTimer1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoTimer1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoTimer1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoTimer1Ptr_t me);

    /* IEcoTimer1 */
    void (ECOCALLMETHOD *set_Interval)(/* in */ IEcoTimer1Ptr_t me, /* in */ uint32_t usec);
    uint32_t (ECOCALLMETHOD *get_Interval)(/* in */ IEcoTimer1Ptr_t me);
    IEcoInterruptVector1* (ECOCALLMETHOD *set_IrqHandler)(/* in */ IEcoTimer1Ptr_t me, /* in */ void (*handler)(void));
    void (ECOCALLMETHOD *Reset)(/* in */ IEcoTimer1Ptr_t me);
    uint16_t (ECOCALLMETHOD *Start)(/* in */ IEcoTimer1Ptr_t me);
    uint16_t (ECOCALLMETHOD *Stop)(/* in */ IEcoTimer1Ptr_t me);

} IEcoTimer1VTbl, *IEcoTimer1VTblPtr;

interface IEcoTimer1 {
    struct IEcoTimer1VTbl *pVTbl;
} IEcoTimer1;


#endif /* __I_ECO_TIMER_1_H__ */
