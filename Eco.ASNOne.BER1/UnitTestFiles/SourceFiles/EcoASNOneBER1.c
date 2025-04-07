/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   EcoASNOneBER1
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
#include "IEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoASNOne1.h"
#include "IdEcoASNOneBER1.h"
#include "IdEcoASNOne1Example.h"

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
    /* Указатель на тестируемый интерфейс */
    IEcoASNOneBER1* pIBER = 0;
    IEcoASNOne1Example* pIExample = 0;
    IEcoASNOne1ExPersonnelRecord* pIPersonnelRecordIn = 0;
    IEcoASNOne1ExPersonnelRecord* pIPersonnelRecordOut = 0;
    IEcoASNOne1ExName* pIName = 0;
    IEcoASNOne1ExEmployeeNumber* pIEmployeeNumber = 0;
    IEcoASNOne1ExDate* pIDate = 0;
    IEcoASNOne1ExChildInformation* pIChildInformation = 0;
    IEcoASNOne1Value* pIValue = 0;
    IEcoASNOne1ValueSet* pIValueSet = 0;

    byte_t* pBuffer = 0;
    uint32_t cbBuffer = 0;
    uint8_t i8;
    char_t* szValue = 0;
    int32_t cbValue = 0;

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
    /* Регистрация статического компонента для работы с ASN.1 BER */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoASNOneBER1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_2C2F66F449864F509444C0F7CBE9F1CB);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoASNOne1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_E0EA41D156824A40877EB6A011B2F7AB);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Регистрация статического компонента для демонстрации работы с ASN.1 BER */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoASNOne1Example, (IEcoUnknown*)GetIEcoComponentFactoryPtr_CC01E1FC921E4B1C93C6AA45247D52F9);
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
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoASNOneBER1, 0, &IID_IEcoASNOneBER1, (void**) &pIBER);
    if (result != 0 || pIBER == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoASNOne1Example, 0, &IID_IEcoASNOne1Example, (void**) &pIExample);
    if (result != 0 || pIExample == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /*  A.2 ASN.1 description of a record value
        The value of John Smith's personnel record is formally described below using ASN.1.
        { name {givenName "John",initial "P",familyName "Smith"},
            title           "Director",
            number          51,
            dateOfHire      "19710917",
            nameOfSpouse    {givenName "Mary",initial "T",familyName "Smith"},
            children
                {
                    {name {givenName "Ralph",initial "T",familyName "Smith"},
                        dateOfBirth "19571111"
                    },
                    {name {givenName "Susan",initial "B",familyName "Jones"},
                        dateOfBirth "19590717"
                    }
                }
            }
    */

    pIExample->pVTbl->new_PersonnelRecord(pIExample, &pIPersonnelRecordIn);

    pIName = pIPersonnelRecordIn->pVTbl->name(pIPersonnelRecordIn);
    pIValue = pIName->pVTbl->givenName(pIName);
    pIValue->pVTbl->set_Value(pIValue, "John", 4);
    pIValue = pIName->pVTbl->initial(pIName);
    pIValue->pVTbl->set_Value(pIValue, "P", 1);
    pIValue = pIName->pVTbl->familyName(pIName);
    pIValue->pVTbl->set_Value(pIValue, "Smith", 5);
    pIValue = pIPersonnelRecordIn->pVTbl->title(pIPersonnelRecordIn);
    pIValue->pVTbl->set_Value(pIValue, "Director", 8);
    pIEmployeeNumber = pIPersonnelRecordIn->pVTbl->number(pIPersonnelRecordIn);
    i8 = 51;
    pIEmployeeNumber->pVTbl->set_Value(pIEmployeeNumber, &i8, sizeof(uint8_t));
    pIDate = pIPersonnelRecordIn->pVTbl->dateOfHire(pIPersonnelRecordIn);
    pIDate->pVTbl->set_Value(pIDate, "19710917", 8);
    pIName = pIPersonnelRecordIn->pVTbl->nameOfSpouse(pIPersonnelRecordIn);
    pIValue = pIName->pVTbl->givenName(pIName);
    pIValue->pVTbl->set_Value(pIValue, "Mary", 4);
    pIValue = pIName->pVTbl->initial(pIName);
    pIValue->pVTbl->set_Value(pIValue, "T", 1);
    pIValue = pIName->pVTbl->familyName(pIName);
    pIValue->pVTbl->set_Value(pIValue, "Smith", 5);
    pIValueSet = pIPersonnelRecordIn->pVTbl->children(pIPersonnelRecordIn);
    pIExample->pVTbl->new_ChildInformation(pIExample, &pIChildInformation);
    pIName = pIChildInformation->pVTbl->name(pIChildInformation);
    pIValue = pIName->pVTbl->givenName(pIName);
    pIValue->pVTbl->set_Value(pIValue, "Ralph", 5);
    pIValue = pIName->pVTbl->initial(pIName);
    pIValue->pVTbl->set_Value(pIValue, "T", 1);
    pIValue = pIName->pVTbl->familyName(pIName);
    pIValue->pVTbl->set_Value(pIValue, "Smith", 5);
    pIDate = pIChildInformation->pVTbl->dateOfBirth(pIChildInformation);
    pIDate->pVTbl->set_Value(pIDate, "19571111", 8);
    pIValueSet->pVTbl->Add(pIValueSet, pIChildInformation, 0);
    pIExample->pVTbl->new_ChildInformation(pIExample, &pIChildInformation);
    pIName = pIChildInformation->pVTbl->name(pIChildInformation);
    pIValue = pIName->pVTbl->givenName(pIName);
    pIValue->pVTbl->set_Value(pIValue, "Susan", 5);
    pIValue = pIName->pVTbl->initial(pIName);
    pIValue->pVTbl->set_Value(pIValue, "B", 1);
    pIValue = pIName->pVTbl->familyName(pIName);
    pIValue->pVTbl->set_Value(pIValue, "Jones", 5);
    pIDate = pIChildInformation->pVTbl->dateOfBirth(pIChildInformation);
    pIDate->pVTbl->set_Value(pIDate, "19590717", 8);
    pIValueSet->pVTbl->Add(pIValueSet, pIChildInformation, 0);

    result = pIBER->pVTbl->Encode(pIBER, pIPersonnelRecordIn, &pBuffer, &cbBuffer);

    result = pIBER->pVTbl->Decode(pIBER, pBuffer, cbBuffer, (void**)&pIPersonnelRecordOut);

    pIName = pIPersonnelRecordOut->pVTbl->name(pIPersonnelRecordOut);
    pIValue = pIName->pVTbl->givenName(pIName);
    pIValue->pVTbl->get_Value(pIValue, szValue, &cbValue);

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
    if (pIBER != 0) {
        pIBER->pVTbl->Release(pIBER);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

