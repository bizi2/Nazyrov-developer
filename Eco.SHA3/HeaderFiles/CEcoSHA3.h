/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSHA3
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoSHA3
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOSHA3_H__
#define __C_ECOSHA3_H__

#include "IEcoSHA3.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoSHA3_6EFC7840 {

    /* Таблица функций интерфейса IEcoSHA3 */
    IEcoSHA3VTbl* m_pVTblIEcoSHA3;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoSHA3_6EFC7840, *CEcoSHA3_6EFC7840Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoSHA3_6EFC7840(/*in*/ IEcoSHA3Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoSHA3_6EFC7840(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoSHA3Ptr_t* ppIEcoSHA3);
/* Удаление */
void ECOCALLMETHOD deleteCEcoSHA3_6EFC7840(/* in */ IEcoSHA3Ptr_t pIEcoSHA3);

#endif /* __C_ECOSHA3_H__ */
