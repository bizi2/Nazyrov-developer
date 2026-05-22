/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1ValueSet
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoASNOne1ValueSet
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_ASN_ONE_1_VALUE_SET_H__
#define __C_ECO_ASN_ONE_1_VALUE_SET_H__

#include "IEcoASNOne1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoASNOne1ValueSetComponent_11B2F7AB {
    void* data;
    struct CEcoASNOne1ValueSetComponent_11B2F7AB* next;
} CEcoASNOne1ValueSetComponent_11B2F7AB;

typedef struct CEcoASNOne1ValueSet_11B2F7AB {

    /* Таблица функций интерфейса IEcoASNOne1ValueSet */
    IEcoASNOne1ValueSetVTbl* m_pVTblIValueSet;

    /* Таблица функций интерфейса IEcoASNOne1EncodingRules */
    IEcoASNOne1EncodingRulesVTbl* m_pVTblIEncoding;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    int8_t m_Tag;
    int8_t m_TaggetType;
    int8_t m_Type;
    CEcoASNOne1ValueSetComponent_11B2F7AB* m_Components;
    uint32_t m_Count;

} CEcoASNOne1ValueSet_11B2F7AB, *CEcoASNOne1ValueSet_11B2F7ABPtr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoASNOne1ValueSet_11B2F7AB(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ uint8_t Tag, /* in */ uint8_t TaggetType, /* in */ uint8_t Type, /* out */ IEcoASNOne1ValueSetPtr_t* ppIValueSet);
/* Удаление */
void ECOCALLMETHOD deleteCEcoASNOne1ValueSet_11B2F7AB(/* in */ IEcoASNOne1ValueSetPtr_t pIValueSet);

#endif /* __C_ECO_ASN_ONE_1_VALUE_SET_H__ */
