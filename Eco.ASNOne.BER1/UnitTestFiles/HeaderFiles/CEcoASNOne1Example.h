/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1Example
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoASNOne1Example
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_ASN_ONE_1_EXAMPLE_H__
#define __C_ECO_ASN_ONE_1_EXAMPLE_H__

#include "IEcoASNOne1.h"
#include "IEcoASNOne1Example.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoASNOne1Example_247D52F9 {

    /* Таблица функций интерфейса IEcoASNOne1Example */
    IEcoASNOne1ExampleVTbl* m_pVTblIExample;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейс для работы с нотацией ASN.1 */
    IEcoASNOne1* m_pIASNOne;

    /* Данные экземпляра */

} CEcoASNOne1Example_247D52F9, *CEcoASNOne1Example_247D52F9Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoASNOne1Example_247D52F9(/*in*/ IEcoASNOne1ExamplePtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoASNOne1Example_247D52F9(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoASNOne1ExamplePtr_t* ppIExample);
/* Удаление */
void ECOCALLMETHOD deleteCEcoASNOne1Example_247D52F9(/* in */ IEcoASNOne1ExamplePtr_t pIExample);

#endif /* __C_ECO_ASN_ONE_1_EXAMPLE_H__ */
