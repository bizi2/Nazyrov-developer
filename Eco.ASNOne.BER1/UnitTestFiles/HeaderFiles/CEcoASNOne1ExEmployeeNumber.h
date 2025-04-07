/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1ExEmployeeNumber
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoASNOne1ExEmployeeNumber
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_ASN_ONE_1_EXAMPLE_EMPLOYEE_NUMBER_H__
#define __C_ECO_ASN_ONE_1_EXAMPLE_EMPLOYEE_NUMBER_H__

#include "IEcoASNOne1Example.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoASNOne1ExEmployeeNumber_247D52F9 {

    /* Таблица функций интерфейса IEcoASNOne1ExEmployeeNumber */
    IEcoASNOne1ExEmployeeNumberVTbl* m_pVTblIEmployeeNumber;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейс для работы с нотацией ASN.1 */
    IEcoASNOne1* m_pIASNOne;

    /* Данные экземпляра */
    IEcoASNOne1Value* m_INTEGER;

} CEcoASNOne1ExEmployeeNumber_247D52F9, *CEcoASNOne1ExEmployeeNumber_247D52F9Ptr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoASNOne1ExEmployeeNumber_247D52F9(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoASNOne1ExEmployeeNumberPtr_t* ppIEmployeeNumber);
/* Удаление */
void ECOCALLMETHOD deleteCEcoASNOne1ExEmployeeNumber_247D52F9(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t pIEmployeeNumber);

#endif /* __C_ECO_ASN_ONE_1_EXAMPLE_EMPLOYEE_NUMBER_H__ */
