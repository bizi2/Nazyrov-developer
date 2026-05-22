/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1ExName_247D52F9
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoASNOne1ExName_247D52F9
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
#include "CEcoASNOne1ExName.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoASNOne1ExName
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1ExName_247D52F9_QueryInterface(/* in */ IEcoASNOne1ExNamePtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoASNOne1ExName) ) {
        *ppv = &pCMe->m_pVTblIName;
        pCMe->m_pVTblIName->AddRef((IEcoASNOne1ExName*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIName;
        pCMe->m_pVTblIName->AddRef((IEcoASNOne1ExName*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoASNOne1Type) ) {
        *ppv = &pCMe->m_pVTblIName;
        pCMe->m_pVTblIName->AddRef((IEcoASNOne1ExName*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoASNOne1ValueSet) ) {
        *ppv = &pCMe->m_pVTblIName;
        pCMe->m_pVTblIName->AddRef((IEcoASNOne1ExName*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoASNOne1ExName
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1ExName_247D52F9_AddRef(/* in */ IEcoASNOne1ExNamePtr_t me) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)me;

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
 *   Функция Release для интерфейса IEcoASNOne1ExName
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1ExName_247D52F9_Release(/* in */ IEcoASNOne1ExNamePtr_t me) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoASNOne1ExName_247D52F9((IEcoASNOne1ExName*)pCMe);
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
static uint8_t ECOCALLMETHOD CEcoASNOne1ExName_247D52F9_get_Tag(/* in */ IEcoASNOne1ExNamePtr_t me) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_SEQUENCE->pVTbl->get_Tag(pCMe->m_SEQUENCE);
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
static uint8_t ECOCALLMETHOD CEcoASNOne1ExName_247D52F9_get_TaggetType(/* in */ IEcoASNOne1ExNamePtr_t me) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_SEQUENCE->pVTbl->get_TaggedType(pCMe->m_SEQUENCE);
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
static uint8_t ECOCALLMETHOD CEcoASNOne1ExName_247D52F9_get_Type(/* in */ IEcoASNOne1ExNamePtr_t me) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_SEQUENCE->pVTbl->get_Type(pCMe->m_SEQUENCE);
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
static int16_t ECOCALLMETHOD CEcoASNOne1ExName_247D52F9_Count(/* in */ IEcoASNOne1ExNamePtr_t me, /* in */ int32_t* Count) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_SEQUENCE->pVTbl->Count(pCMe->m_SEQUENCE, Count);

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
static int16_t ECOCALLMETHOD CEcoASNOne1ExName_247D52F9_Item(/* in */ IEcoASNOne1ExNamePtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_SEQUENCE->pVTbl->Item(pCMe->m_SEQUENCE, Index, Component);

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
static int16_t ECOCALLMETHOD CEcoASNOne1ExName_247D52F9_Add(/* in */ IEcoASNOne1ExNamePtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_SEQUENCE->pVTbl->Add(pCMe->m_SEQUENCE, Component, Index);

    return result;
}

/*
 *
 * <сводка>
 *   Функция givenName
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoASNOne1Value* ECOCALLMETHOD CEcoASNOne1ExName_247D52F9_givenName(/* in */ IEcoASNOne1ExNamePtr_t me) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_givenName;
}

/*
 *
 * <сводка>
 *   Функция initial
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoASNOne1Value* ECOCALLMETHOD CEcoASNOne1ExName_247D52F9_initial(/* in */ IEcoASNOne1ExNamePtr_t me) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_initial;
}

/*
 *
 * <сводка>
 *   Функция familyName
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoASNOne1Value* ECOCALLMETHOD CEcoASNOne1ExName_247D52F9_familyName(/* in */ IEcoASNOne1ExNamePtr_t me) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_familyName;
}

/* Create Virtual Table IEcoASNOne1ExName */
IEcoASNOne1ExNameVTbl g_x8C1B98CCE78648B0BAA411968FBDDB9CVTbl_247D52F9 = {
    CEcoASNOne1ExName_247D52F9_QueryInterface,
    CEcoASNOne1ExName_247D52F9_AddRef,
    CEcoASNOne1ExName_247D52F9_Release,
    CEcoASNOne1ExName_247D52F9_get_Tag,
    CEcoASNOne1ExName_247D52F9_get_TaggetType,
    CEcoASNOne1ExName_247D52F9_get_Type,
    CEcoASNOne1ExName_247D52F9_Count,
    CEcoASNOne1ExName_247D52F9_Item,
    CEcoASNOne1ExName_247D52F9_Add,
    CEcoASNOne1ExName_247D52F9_givenName,
    CEcoASNOne1ExName_247D52F9_initial,
    CEcoASNOne1ExName_247D52F9_familyName
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
int16_t ECOCALLMETHOD createCEcoASNOne1ExName_247D52F9(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoASNOne1ExNamePtr_t* ppIName) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoASNOne1ExName_247D52F9* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppIName == 0 || pIUnkSystem == 0) {
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
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);
    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_GET_MEMORY_ALLOCATOR;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoASNOne1ExName_247D52F9*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoASNOne1ExName_247D52F9));
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

    /* Создание таблицы функций интерфейса IEcoASNOne1Name */
    pCMe->m_pVTblIName = &g_x8C1B98CCE78648B0BAA411968FBDDB9CVTbl_247D52F9;

    /* Сохранение указателя на интерфейс для работы с нотацией ASN.1 */
    pCMe->m_pIASNOne = pIASNOne;
    pCMe->m_pIASNOne->pVTbl->AddRef(pCMe->m_pIASNOne);

    /* Инициализация данных */
    pCMe->m_SEQUENCE = 0;
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_CLASS_APPLICATION | ECO_ASN1_PC_CONSTRUCTED | 1, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_SEQUENCE_TYPE, &pCMe->m_SEQUENCE);
    pCMe->m_givenName = 0;
    pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pCMe->m_givenName);
    pCMe->m_SEQUENCE->pVTbl->Add(pCMe->m_SEQUENCE, pCMe->m_givenName, 0);
    pCMe->m_initial = 0;
    pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pCMe->m_initial);
    pCMe->m_SEQUENCE->pVTbl->Add(pCMe->m_SEQUENCE, pCMe->m_initial, 0);
    pCMe->m_familyName = 0;
    pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pCMe->m_familyName);
    pCMe->m_SEQUENCE->pVTbl->Add(pCMe->m_SEQUENCE, pCMe->m_familyName, 0);

    /* Возврат указателя на интерфейс */
    *ppIName = (IEcoASNOne1ExName*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

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
void ECOCALLMETHOD deleteCEcoASNOne1ExName_247D52F9(/* in */ IEcoASNOne1ExNamePtr_t pIName) {
    CEcoASNOne1ExName_247D52F9* pCMe = (CEcoASNOne1ExName_247D52F9*)pIName;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIName != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
