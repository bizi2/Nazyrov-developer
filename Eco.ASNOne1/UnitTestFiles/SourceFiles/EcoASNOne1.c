/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoASNOne1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoASNOne1.h"
#include "IdEcoASNOneBER1.h"

bool_t TestBER_01(IEcoASNOne1* pIASNOne, IEcoASNOneBER1* pIBER);
bool_t TestBER_02(IEcoASNOne1* pIASNOne, IEcoASNOneBER1* pIBER);
bool_t TestBER_10(IEcoASNOne1* pIASNOne, IEcoASNOneBER1* pIBER);

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    char_t* name = 0;
    char_t* copyName = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoASNOne1* pIASNOne = 0;
    IEcoASNOneBER1* pIBER = 0;
    IEcoASNOne1EncodingRules* pIEncodingRules = 0;
    IEcoUnknown* pIDecoded = 0;
    IEcoASNOne1Value* pIINTEGER = 0;

   // IEcoASNOne1ValueSet* pIChildInformation = 0;
    byte_t* pBuffer = 0;
    uint32_t cbBuffer = 0;
    uint8_t i8 = 240;
    int32_t cbSize = 0;


    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoASNOne1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_E0EA41D156824A40877EB6A011B2F7AB);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы с ASN.1 BER */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoASNOneBER1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_2C2F66F449864F509444C0F7CBE9F1CB);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoASNOne1, 0, &IID_IEcoASNOne1, (void**) &pIASNOne);
    if (result != 0 || pIASNOne == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoASNOneBER1, 0, &IID_IEcoASNOneBER1, (void**) &pIBER);
    if (result != 0 || pIBER == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Пример */
    TestBER_01(pIASNOne, pIBER);

    TestBER_10(pIASNOne, pIBER);


Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIASNOne != 0) {
        pIASNOne->pVTbl->Release(pIASNOne);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

bool_t TestBER_01(IEcoASNOne1* pIASNOne, IEcoASNOneBER1* pIBER) {
    int16_t result = -1;
    IEcoUnknown* pIUnk = 0;
    IEcoASNOne1ValueSet* pIValueSet = 0;
    IEcoASNOne1Value* pIValue = 0;

    IEcoASNOne1ValueSet* pIPersonnelRecord = 0;
    IEcoASNOne1ValueSet* pIName = 0;
    IEcoASNOne1Value* pIVisibleString = 0;
    IEcoASNOne1Value* pIINTEGER = 0;
    byte_t* pBuffer = 0;
    uint32_t cbBuffer = 0;
    int32_t iSize = 0;
    int32_t iCount = 0;
    int32_t iIndex = 0;
    uint8_t i8 = 0;

    /* Создадин новый набор PersonnelRecord ::= [APPLICATION 0] IMPLICIT SET */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_APPLICATION | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_SET_TYPE, &pIPersonnelRecord);

    /* EmployeeNumber ::= [APPLICATION 2] IMPLICIT INTEGER */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_CLASS_APPLICATION | 2, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_INTEGER_TYPE, &pIINTEGER);
    /* Добавим number в набор */
    pIPersonnelRecord->pVTbl->Add(pIPersonnelRecord, pIINTEGER, 0);
    /* Заполним number 51 */
    i8 = 51;
    pIINTEGER->pVTbl->set_Value(pIINTEGER, &i8, sizeof(uint8_t));

    result = pIBER->pVTbl->Encode(pIBER, pIPersonnelRecord, &pBuffer, &cbBuffer);

    pIINTEGER->pVTbl->Release(pIINTEGER);
    pIINTEGER = 0;
    pIPersonnelRecord->pVTbl->Release(pIPersonnelRecord);
    pIPersonnelRecord = 0;

    result = pIBER->pVTbl->Decode(pIBER, pBuffer, &cbBuffer, (voidptr_t*)&pIPersonnelRecord);
    pIPersonnelRecord->pVTbl->Count(pIPersonnelRecord, &iCount);
    for (iIndex = 0; iIndex < iCount; iIndex++) {
        pIPersonnelRecord->pVTbl->Item(pIPersonnelRecord, iIndex, (voidptr_t*)&pIUnk);
        pIUnk->pVTbl->QueryInterface(pIUnk, &IID_IEcoASNOne1ValueSet, (voidptr_t*)&pIValueSet);
        if (pIValueSet != 0) {
            pIValueSet->pVTbl->Release(pIValueSet);
        }
        pIUnk->pVTbl->QueryInterface(pIUnk, &IID_IEcoASNOne1Value, (voidptr_t*)&pIValue);
        if (pIValue != 0) {
            pIINTEGER = pIValue;
            pIValue->pVTbl->Release(pIValue);
            i8 = 0;
            iSize = 1;
            pIINTEGER->pVTbl->get_Value(pIINTEGER, &i8, &iSize);
        }

    }
    //i8 = 0;
    //iSize = 1;
    //pIINTEGER->pVTbl->get_Value(pIINTEGER, &i8, &iSize);

    pIINTEGER->pVTbl->Release(pIINTEGER);
    pIINTEGER = 0;

    return 1;
}

bool_t TestBER_02(IEcoASNOne1* pIASNOne, IEcoASNOneBER1* pIBER) {

    return 1;
}

bool_t TestBER_10(IEcoASNOne1* pIASNOne, IEcoASNOneBER1* pIBER) {
    int16_t result = -1;
    IEcoASNOne1ValueSet* pIDate = 0;
    IEcoASNOne1ValueSet* pINameOfSpouse = 0;
    IEcoASNOne1ValueSet* pIChildren = 0;
    IEcoASNOne1ValueSet* pIChildInformation = 0;
    IEcoASNOne1ValueSet* pIPersonnelRecord = 0;
    IEcoASNOne1ValueSet* pIName = 0;
    IEcoASNOne1Value* pIVisibleString = 0;
    IEcoASNOne1Value* pIINTEGER = 0;
    byte_t* pBuffer = 0;
    uint32_t cbBuffer = 0;
    uint8_t i8 = 0;

    /* Создадин новый набор PersonnelRecord ::= [APPLICATION 0] IMPLICIT SET */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_APPLICATION | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_SET_TYPE, &pIPersonnelRecord);

    /* Создадин новую последовательность Name ::= [APPLICATION 1] IMPLICIT SEQUENCE */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_APPLICATION | ECO_ASN1_PC_CONSTRUCTED | 1, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_SEQUENCE_TYPE, &pIName);

    /* Добавим name в набор */
    pIPersonnelRecord->pVTbl->Add(pIPersonnelRecord, pIName, 0);

    /* Заполним name {givenName "John",initial "P",familyName "Smith"} */

    /* Создадин новую строку типа "VisibleString" */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "John", 4);
    /* Добавим в последовательность */
    pIName->pVTbl->Add(pIName, pIVisibleString, 0);
    /* Добавим еще несколько ASN.1 компонентов */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "P", 1);
    pIName->pVTbl->Add(pIName, pIVisibleString, 0);
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "Smith", 5);
    pIName->pVTbl->Add(pIName, pIVisibleString, 0);

    /* Создадим компонент title [0] VisibleString */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    /* Добавим title в набор */
    pIPersonnelRecord->pVTbl->Add(pIPersonnelRecord, pIVisibleString, 0);
    /* Заполним title "Director" */
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "Director", 8);


    /* EmployeeNumber ::= [APPLICATION 2] IMPLICIT INTEGER */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_CLASS_APPLICATION | 2, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_INTEGER_TYPE, &pIINTEGER);
    /* Добавим number в набор */
    pIPersonnelRecord->pVTbl->Add(pIPersonnelRecord, pIINTEGER, 0);
    /* Заполним number 51 */
    i8 = 51;
    pIINTEGER->pVTbl->set_Value(pIINTEGER, &i8, sizeof(uint8_t));

    /* Создадим компонент dateOfHire [1] Date */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne,  ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 1, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIDate);
    /* Добавим date в набор */
    pIPersonnelRecord->pVTbl->Add(pIPersonnelRecord, pIDate, 0);

    /* Date ::= [APPLICATION 3] IMPLICIT VisibleString -- YYYYMMDD */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_CLASS_APPLICATION | 3, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);

    pIDate->pVTbl->Add(pIDate, pIVisibleString, 0);
    /* Заполним dateOfHire "19710917" */
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "19710917", 8);


    /* Создадим компонент nameOfSpouse [2] Name */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne,  ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 2, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pINameOfSpouse);
    /* Добавим nameOfSpouse в набор PersonnelRecord */
    pIPersonnelRecord->pVTbl->Add(pIPersonnelRecord, pINameOfSpouse, 0);

    /* Создадин новую последовательность Name ::= [APPLICATION 1] IMPLICIT SEQUENCE */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_APPLICATION | ECO_ASN1_PC_CONSTRUCTED | 1, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_SEQUENCE_TYPE, &pIName);

    /* Добавим name в компонент nameOfSpouse */
    pINameOfSpouse->pVTbl->Add(pINameOfSpouse, pIName, 0);

    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "Mary", 4);
    /* Добавим в последовательность */
    pIName->pVTbl->Add(pIName, pIVisibleString, 0);
    /* Добавим еще несколько ASN.1 компонентов */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "T", 1);
    pIName->pVTbl->Add(pIName, pIVisibleString, 0);
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "Smith", 5);
    pIName->pVTbl->Add(pIName, pIVisibleString, 0);


    /* Создадин новую последовательность children [3] IMPLICIT SEQUENCE OF ChildInformation DEFAULT {} */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 3, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_SEQUENCE_OF_TYPE, &pIChildren);
    /* Добавим children в набор PersonnelRecord */
    pIPersonnelRecord->pVTbl->Add(pIPersonnelRecord, pIChildren, 0);

    /* Создадин новый набор ChildInformation ::= SET */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_PC_CONSTRUCTED | ECO_ASN1_SET_TYPE, &pIChildInformation);
    /* Добавим ChildInformation в набор children */
    pIChildren->pVTbl->Add(pIChildren, pIChildInformation, 0);

    /* Создадин новую последовательность Name ::= [APPLICATION 1] IMPLICIT SEQUENCE */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_APPLICATION | ECO_ASN1_PC_CONSTRUCTED | 1, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_SEQUENCE_TYPE, &pIName);

    /* Добавим name в компонент childInformation */
    pIChildInformation->pVTbl->Add(pIChildInformation, pIName, 0);

    /* name {givenName "Ralph",initial "T",familyName "Smith"} */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "Ralph", 5);
    /* Добавим в последовательность */
    pIName->pVTbl->Add(pIName, pIVisibleString, 0);
    /* Добавим еще несколько ASN.1 компонентов */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "T", 1);
    pIName->pVTbl->Add(pIName, pIVisibleString, 0);
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "Smith", 5);
    pIName->pVTbl->Add(pIName, pIVisibleString, 0);

    /* Создадим компонент dateOfBirth [0] Date */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne,  ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIDate);
    /* Добавим dateOfBirth в набор childInformation */
    pIChildInformation->pVTbl->Add(pIChildInformation, pIDate, 0);

    /* Date ::= [APPLICATION 3] IMPLICIT VisibleString -- YYYYMMDD */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_CLASS_APPLICATION | 3, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);

    pIDate->pVTbl->Add(pIDate, pIVisibleString, 0);
    /* dateOfBirth "19571111" */
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "19571111", 8);

    /* Создадин новый набор ChildInformation ::= SET */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_PC_CONSTRUCTED | ECO_ASN1_SET_TYPE, &pIChildInformation);
    /* Добавим ChildInformation в набор children */
    pIChildren->pVTbl->Add(pIChildren, pIChildInformation, 0);

    /* Создадин новую последовательность Name ::= [APPLICATION 1] IMPLICIT SEQUENCE */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_APPLICATION | ECO_ASN1_PC_CONSTRUCTED | 1, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_SEQUENCE_TYPE, &pIName);

    /* Добавим name в компонент childInformation */
    pIChildInformation->pVTbl->Add(pIChildInformation, pIName, 0);

    /* name {givenName "Susan",initial "B",familyName "Jones"} */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "Susan", 5);
    /* Добавим в последовательность */
    pIName->pVTbl->Add(pIName, pIVisibleString, 0);
    /* Добавим еще несколько ASN.1 компонентов */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "B", 1);
    pIName->pVTbl->Add(pIName, pIVisibleString, 0);
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "Jones", 5);
    pIName->pVTbl->Add(pIName, pIVisibleString, 0);

    /* Создадим компонент dateOfBirth [0] Date */
    pIASNOne->pVTbl->new_ValueSet(pIASNOne,  ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIDate);
    /* Добавим dateOfBirth в набор childInformation */
    pIChildInformation->pVTbl->Add(pIChildInformation, pIDate, 0);

    /* Date ::= [APPLICATION 3] IMPLICIT VisibleString -- YYYYMMDD */
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_CLASS_APPLICATION | 3, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_VISIBLE_STRING_TYPE, &pIVisibleString);

    pIDate->pVTbl->Add(pIDate, pIVisibleString, 0);
    /* dateOfBirth "19590717" */
    pIVisibleString->pVTbl->set_Value(pIVisibleString, "19590717", 8);

    result = pIBER->pVTbl->Encode(pIBER, pIPersonnelRecord, &pBuffer, &cbBuffer);


    return 1;

}
