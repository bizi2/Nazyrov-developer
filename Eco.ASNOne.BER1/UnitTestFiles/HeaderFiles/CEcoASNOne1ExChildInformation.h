/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1ExChildInformation
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoASNOne1ExChildInformation
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_ASN_ONE_1_EXAMPLE_CHILD_INFORMATION_H__
#define __C_ECO_ASN_ONE_1_EXAMPLE_CHILD_INFORMATION_H__

#include "IEcoASNOne1Example.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoASNOne1ExChildInformation_247D52F9 {

    /* Таблица функций интерфейса IEcoASNOne1ExChildInformation */
    IEcoASNOne1ExChildInformationVTbl* m_pVTblIChildInformation;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейс для работы с нотацией ASN.1 */
    IEcoASNOne1* m_pIASNOne;

    /* Данные экземпляра */
    IEcoASNOne1ValueSet* m_SET;
    IEcoASNOne1ExName* m_name;
    IEcoASNOne1ExDate* m_dateOfBirth;

} CEcoASNOne1ExChildInformation_247D52F9, *CEcoASNOne1ExChildInformation_247D52F9Ptr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoASNOne1ExChildInformation_247D52F9(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoASNOne1ExChildInformationPtr_t* ppIChildInformation);
/* Удаление */
void ECOCALLMETHOD deleteCEcoASNOne1ExChildInformation_247D52F9(/* in */ IEcoASNOne1ExChildInformationPtr_t pIChildInformation);

#endif /* __C_ECO_ASN_ONE_1_EXAMPLE_CHILD_INFORMATION_H__ */
