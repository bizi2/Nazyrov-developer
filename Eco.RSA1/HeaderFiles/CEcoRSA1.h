/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoRSA1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoRSA1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECORSA1_H__
#define __C_ECORSA1_H__

#include "IEcoRSA1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoRSA1_3C4F4509 {

    /* Таблица функций интерфейса IEcoRSA1 */
    IEcoRSA1VTbl* m_pVTblIEcoRSA1;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoRSA1_3C4F4509, *CEcoRSA1_3C4F4509Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoRSA1_3C4F4509(/*in*/ IEcoRSA1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoRSA1_3C4F4509(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoRSA1Ptr_t* ppIEcoRSA1);
/* Удаление */
void ECOCALLMETHOD deleteCEcoRSA1_3C4F4509(/* in */ IEcoRSA1Ptr_t pIEcoRSA1);

#endif /* __C_ECORSA1_H__ */
