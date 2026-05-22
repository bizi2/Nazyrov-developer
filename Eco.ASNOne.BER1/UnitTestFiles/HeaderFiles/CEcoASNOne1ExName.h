/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1ExName
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoASNOne1ExName
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_ASN_ONE_1_EXAMPLE_NAME_H__
#define __C_ECO_ASN_ONE_1_EXAMPLE_NAME_H__

#include "IEcoASNOne1Example.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoASNOne1ExName_247D52F9 {

    /* Таблица функций интерфейса IEcoASNOne1ExName */
    IEcoASNOne1ExNameVTbl* m_pVTblIName;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейс для работы с нотацией ASN.1 */
    IEcoASNOne1* m_pIASNOne;

    /* Данные экземпляра */
    IEcoASNOne1ValueSet* m_SEQUENCE;
    IEcoASNOne1Value* m_givenName;
    IEcoASNOne1Value* m_initial;
    IEcoASNOne1Value* m_familyName;

} CEcoASNOne1ExName_247D52F9, *CEcoASNOne1ExName_247D52F9Ptr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoASNOne1ExName_247D52F9(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoASNOne1ExNamePtr_t* ppIName);
/* Удаление */
void ECOCALLMETHOD deleteCEcoASNOne1ExName_247D52F9(/* in */ IEcoASNOne1ExNamePtr_t pIName);

#endif /* __C_ECO_ASN_ONE_1_EXAMPLE_NAME_H__ */
