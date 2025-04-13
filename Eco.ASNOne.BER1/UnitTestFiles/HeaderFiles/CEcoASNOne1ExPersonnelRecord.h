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

#ifndef __C_ECO_ASN_ONE_1_PERSONNEL_RECORD_H__
#define __C_ECO_ASN_ONE_1_PERSONNEL_RECORD_H__

#include "IEcoASNOne1.h"
#include "IEcoASNOne1Example.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoASNOne1ExPersonnelRecord_247D52F9 {

    /* Таблица функций интерфейса IEcoASNOne1ExPersonnelRecord */
    IEcoASNOne1ExPersonnelRecordVTbl* m_pVTblIPersonnelRecord;

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
    IEcoASNOne1Value* m_title;
    IEcoASNOne1ExEmployeeNumber* m_number;
    IEcoASNOne1ExDate* m_dateOfHire;
    IEcoASNOne1ExName* m_nameOfSpouse;
    IEcoASNOne1ValueSet* m_children;

} CEcoASNOne1ExPersonnelRecord_247D52F9, *CEcoASNOne1ExPersonnelRecord_247D52F9Ptr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoASNOne1ExPersonnelRecord_247D52F9(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoASNOne1ExPersonnelRecordPtr_t* ppIPersonnelRecord);
/* Удаление */
void ECOCALLMETHOD deleteCEcoASNOne1ExPersonnelRecord_247D52F9(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t pIPersonnelRecord);

#endif /* __C_ECO_ASN_ONE_1_PERSONNEL_RECORD_H__ */
