/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1ExPersonnelRecord_247D52F9
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoASNOne1ExPersonnelRecord_247D52F9
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "IdEcoASNOne1.h"
#include "CEcoASNOne1ExPersonnelRecord.h"
#include "CEcoASNOne1ExName.h"
#include "CEcoASNOne1ExEmployeeNumber.h"
#include "CEcoASNOne1ExDate.h"
#include "CEcoASNOne1ExChildInformation.h"
#include "ErrEcoASNOne1Example.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoASNOne1ExPersonnelRecord
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_QueryInterface(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoASNOne1ExPersonnelRecord) ) {
        *ppv = &pCMe->m_pVTblIPersonnelRecord;
        pCMe->m_pVTblIPersonnelRecord->AddRef((IEcoASNOne1ExPersonnelRecord*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIPersonnelRecord;
        pCMe->m_pVTblIPersonnelRecord->AddRef((IEcoASNOne1ExPersonnelRecord*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoASNOne1Type) ) {
        *ppv = &pCMe->m_pVTblIPersonnelRecord;
        pCMe->m_pVTblIPersonnelRecord->AddRef((IEcoASNOne1ExPersonnelRecord*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoASNOne1ValueSet) ) {
        *ppv = &pCMe->m_pVTblIPersonnelRecord;
        pCMe->m_pVTblIPersonnelRecord->AddRef((IEcoASNOne1ExPersonnelRecord*)pCMe);
    }
    else {
        *ppv = 0;
        return ERR_ECO_NOINTERFACE;
    }
    return ERR_ECO_SUCCESES;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoASNOne1ExPersonnelRecord
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_AddRef(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoASNOne1ExPersonnelRecord
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_Release(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoASNOne1ExPersonnelRecord_247D52F9((IEcoASNOne1ExPersonnelRecord*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция get_Tag
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static uint8_t ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_get_Tag(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_SET->pVTbl->get_Tag(pCMe->m_SET);
}

/*
 *
 * <сводка>
 *   Функция get_TaggetType
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static uint8_t ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_get_TaggetType(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_SET->pVTbl->get_TaggedType(pCMe->m_SET);
}

/*
 *
 * <сводка>
 *   Функция get_Type
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static uint8_t ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_get_Type(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_SET->pVTbl->get_Type(pCMe->m_SET);
}

/*
 *
 * <сводка>
 *   Функция Count
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_Count(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me, /* in */ int32_t* Count) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_SET->pVTbl->Count(pCMe->m_SET, Count);

    return result;
}

/*
 *
 * <сводка>
 *   Функция Item
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_Item(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_SET->pVTbl->Item(pCMe->m_SET, Index, Component);

    return result;
}

/*
 *
 * <сводка>
 *   Функция Add
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_Add(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_SET->pVTbl->Add(pCMe->m_SET, Component, Index);

    return result;
}

/*
 *
 * <сводка>
 *   Функция name
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoASNOne1ExName* ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_name(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_name;
}

/*
 *
 * <сводка>
 *   Функция title
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoASNOne1Value* ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_title(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_title;
}

/*
 *
 * <сводка>
 *   Функция number
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoASNOne1ExEmployeeNumber* ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_number(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_number;
}

/*
 *
 * <сводка>
 *   Функция dateOfHire
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoASNOne1ExDate* ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_dateOfHire(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_dateOfHire;
}

/*
 *
 * <сводка>
 *   Функция nameOfSpouse
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoASNOne1ExName* ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_nameOfSpouse(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_nameOfSpouse;
}


/*
 *
 * <сводка>
 *   Функция children
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoASNOne1ValueSet* ECOCALLMETHOD CEcoASNOne1ExPersonnelRecord_247D52F9_children(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t me) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_children;
}

/* Create Virtual Table IEcoASNOne1ExPersonnelRecord */
IEcoASNOne1ExPersonnelRecordVTbl g_x774C3101CD8248E2A267524D127B9D6AVTbl_247D52F9 = {
    CEcoASNOne1ExPersonnelRecord_247D52F9_QueryInterface,
    CEcoASNOne1ExPersonnelRecord_247D52F9_AddRef,
    CEcoASNOne1ExPersonnelRecord_247D52F9_Release,
    CEcoASNOne1ExPersonnelRecord_247D52F9_get_Tag,
    CEcoASNOne1ExPersonnelRecord_247D52F9_get_TaggetType,
    CEcoASNOne1ExPersonnelRecord_247D52F9_get_Type,
    CEcoASNOne1ExPersonnelRecord_247D52F9_Count,
    CEcoASNOne1ExPersonnelRecord_247D52F9_Item,
    CEcoASNOne1ExPersonnelRecord_247D52F9_Add,
    CEcoASNOne1ExPersonnelRecord_247D52F9_name,
    CEcoASNOne1ExPersonnelRecord_247D52F9_title,
    CEcoASNOne1ExPersonnelRecord_247D52F9_number,
    CEcoASNOne1ExPersonnelRecord_247D52F9_dateOfHire,
    CEcoASNOne1ExPersonnelRecord_247D52F9_nameOfSpouse,
    CEcoASNOne1ExPersonnelRecord_247D52F9_children
};

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoASNOne1ExPersonnelRecord_247D52F9(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoASNOne1ExPersonnelRecordPtr_t* ppIPersonnelRecord) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
    IEcoASNOne1ValueSet* pIValueSet = 0;

    /* Проверка указателей */
    if (ppIPersonnelRecord == 0 || pIUnkSystem == 0) {
        return result; /* ERR_ECO_POINTER */
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void **)&pISys);
    /* Проверка */
    if (result != 0 || pISys == 0) {
        return ERR_ECO_NOSYSTEM;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    /* Проверка */
    if (result != 0 || pIBus == 0) {
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_NOBUS;
    }

    /* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    result = pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);
    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_GET_MEMORY_ALLOCATOR;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoASNOne1ExPersonnelRecord_247D52F9));
    if (pCMe == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_OUTOFMEMORY;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoASNOne1ExPersonnelRecord */
    pCMe->m_pVTblIPersonnelRecord = &g_x774C3101CD8248E2A267524D127B9D6AVTbl_247D52F9;

    /* Сохранение указателя на интерфейс для работы с нотацией ASN.1 */
    pCMe->m_pIASNOne = pIASNOne;
    pCMe->m_pIASNOne->pVTbl->AddRef(pCMe->m_pIASNOne);

    /* Инициализация данных */
    pCMe->m_SET = 0;
    pCMe->m_pIASNOne->pVTbl->new_ValueSet(pCMe->m_pIASNOne, ECO_ASN1_CLASS_APPLICATION | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_SET_TYPE, &pCMe->m_SET);
    pCMe->m_name = 0;
    createCEcoASNOne1ExName_247D52F9((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_name);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pCMe->m_name, 0);
    pCMe->m_title = 0;
    pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 0, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_VISIBLE_STRING_TYPE, &pCMe->m_title);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pCMe->m_title, 0);
    pCMe->m_number = 0;
    createCEcoASNOne1ExEmployeeNumber_247D52F9((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_number);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pCMe->m_number, 0);
    pCMe->m_dateOfHire = 0;
    createCEcoASNOne1ExDate_247D52F9((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_dateOfHire);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne,  ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 1, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_dateOfHire, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);
    pCMe->m_nameOfSpouse = 0;
    createCEcoASNOne1ExName_247D52F9((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_nameOfSpouse);
    pIASNOne->pVTbl->new_ValueSet(pIASNOne,  ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 2, ECO_ASN1_TAG_DEFAULT, ECO_ASN1_EMPTY, &pIValueSet);
    pIValueSet->pVTbl->Add(pIValueSet, pCMe->m_nameOfSpouse, 0);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pIValueSet, 0);
    pCMe->m_children = 0;
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_CONTEXT_SPECIFIC | ECO_ASN1_PC_CONSTRUCTED | 3, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_SEQUENCE_OF_TYPE, &pCMe->m_children);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pCMe->m_children, 0);

    /* Возврат указателя на интерфейс */
    *ppIPersonnelRecord = (IEcoASNOne1ExPersonnelRecord*)pCMe;

    /* Освобождение */
    //pIBus->pVTbl->Release(pIBus);

    return ERR_ECO_SUCCESES;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoASNOne1ExPersonnelRecord_247D52F9(/* in */ IEcoASNOne1ExPersonnelRecordPtr_t pIPersonnelRecord) {
    CEcoASNOne1ExPersonnelRecord_247D52F9* pCMe = (CEcoASNOne1ExPersonnelRecord_247D52F9*)pIPersonnelRecord;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIPersonnelRecord != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
