/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoAES1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoAES1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOAES1_H__
#define __C_ECOAES1_H__

#include "IEcoAES1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoAES1 {

    /* Таблица функций интерфейса IEcoAES1 */
    IEcoAES1VTbl* m_pVTblIEcoAES1;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoAES1, *CEcoAES1Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoAES1(/*in*/ IEcoAES1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoAES1(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoAES1Ptr_t* ppIEcoAES1);
/* Удаление */
void ECOCALLMETHOD deleteCEcoAES1(/* in */ IEcoAES1Ptr_t pIEcoAES1);

#endif /* __C_ECOAES1_H__ */
