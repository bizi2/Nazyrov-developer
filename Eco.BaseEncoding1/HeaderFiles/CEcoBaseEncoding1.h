/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoBaseEncoding1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoBaseEncoding1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOBASEENCODING1_H__
#define __C_ECOBASEENCODING1_H__

#include "IEcoBaseEncoding1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoBaseEncoding1_343447F8 {

    /* Таблица функций интерфейса IEcoBaseEncoding1 */
    IEcoBaseEncoding1VTbl* m_pVTblIEcoBaseEncoding1;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoBaseEncoding1_343447F8, *CEcoBaseEncoding1_343447F8Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoBaseEncoding1_343447F8(/*in*/ IEcoBaseEncoding1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoBaseEncoding1_343447F8(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoBaseEncoding1Ptr_t* ppIEcoBaseEncoding1);
/* Удаление */
void ECOCALLMETHOD deleteCEcoBaseEncoding1_343447F8(/* in */ IEcoBaseEncoding1Ptr_t pIEcoBaseEncoding1);

#endif /* __C_ECOBASEENCODING1_H__ */
