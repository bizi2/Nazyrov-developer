/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoASNOne1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOASNONE1_H__
#define __C_ECOASNONE1_H__

#include "IEcoASNOne1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoASNOne1_11B2F7AB {

    /* Таблица функций интерфейса IEcoASNOne1 */
    IEcoASNOne1VTbl* m_pVTblIEcoASNOne1;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoASNOne1_11B2F7AB, *CEcoASNOne1_11B2F7ABPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoASNOne1_11B2F7AB(/*in*/ IEcoASNOne1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoASNOne1_11B2F7AB(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoASNOne1Ptr_t* ppIEcoASNOne1);
/* Удаление */
void ECOCALLMETHOD deleteCEcoASNOne1_11B2F7AB(/* in */ IEcoASNOne1Ptr_t pIEcoASNOne1);

#endif /* __C_ECOASNONE1_H__ */
