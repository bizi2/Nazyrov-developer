/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1ExEmployeeNumber_247D52F9
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoASNOne1ExEmployeeNumber_247D52F9
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
#include "CEcoASNOne1ExEmployeeNumber.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoASNOne1ExEmployeeNumber
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1ExEmployeeNumber_247D52F9_QueryInterface(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoASNOne1ExEmployeeNumber_247D52F9* pCMe = (CEcoASNOne1ExEmployeeNumber_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoASNOne1ExEmployeeNumber) ) {
        *ppv = &pCMe->m_pVTblIEmployeeNumber;
        pCMe->m_pVTblIEmployeeNumber->AddRef((IEcoASNOne1ExEmployeeNumber*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEmployeeNumber;
        pCMe->m_pVTblIEmployeeNumber->AddRef((IEcoASNOne1ExEmployeeNumber*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoASNOne1Type) ) {
        *ppv = &pCMe->m_pVTblIEmployeeNumber;
        pCMe->m_pVTblIEmployeeNumber->AddRef((IEcoASNOne1ExEmployeeNumber*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoASNOne1Value) ) {
        *ppv = &pCMe->m_pVTblIEmployeeNumber;
        pCMe->m_pVTblIEmployeeNumber->AddRef((IEcoASNOne1ExEmployeeNumber*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoASNOne1ExEmployeeNumber
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1ExEmployeeNumber_247D52F9_AddRef(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me) {
    CEcoASNOne1ExEmployeeNumber_247D52F9* pCMe = (CEcoASNOne1ExEmployeeNumber_247D52F9*)me;

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
 *   Функция Release для интерфейса IEcoASNOne1ExEmployeeNumber
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1ExEmployeeNumber_247D52F9_Release(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me) {
    CEcoASNOne1ExEmployeeNumber_247D52F9* pCMe = (CEcoASNOne1ExEmployeeNumber_247D52F9*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoASNOne1ExEmployeeNumber_247D52F9((IEcoASNOne1ExEmployeeNumber*)pCMe);
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
static uint8_t ECOCALLMETHOD CEcoASNOne1ExEmployeeNumber_247D52F9_get_Tag(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me) {
    CEcoASNOne1ExEmployeeNumber_247D52F9* pCMe = (CEcoASNOne1ExEmployeeNumber_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_INTEGER->pVTbl->get_Tag(pCMe->m_INTEGER);
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
static uint8_t ECOCALLMETHOD CEcoASNOne1ExEmployeeNumber_247D52F9_get_TaggetType(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me) {
    CEcoASNOne1ExEmployeeNumber_247D52F9* pCMe = (CEcoASNOne1ExEmployeeNumber_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_INTEGER->pVTbl->get_TaggedType(pCMe->m_INTEGER);
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
static uint8_t ECOCALLMETHOD CEcoASNOne1ExEmployeeNumber_247D52F9_get_Type(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me) {
    CEcoASNOne1ExEmployeeNumber_247D52F9* pCMe = (CEcoASNOne1ExEmployeeNumber_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_INTEGER->pVTbl->get_Type(pCMe->m_INTEGER);
}

/*
 *
 * <сводка>
 *   Функция set_Value
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1ExEmployeeNumber_247D52F9_set_Value(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me, /* in */ voidptr_t Value, /* in */ int32_t Size) {
    CEcoASNOne1ExEmployeeNumber_247D52F9* pCMe = (CEcoASNOne1ExEmployeeNumber_247D52F9*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_INTEGER->pVTbl->set_Value(pCMe->m_INTEGER, Value, Size);

    return result;
}

/*
 *
 * <сводка>
 *   Функция get_Value
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1ExEmployeeNumber_247D52F9_get_Value(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t me, /* out */ voidptr_t Value, /* out */ int32_t* Size) {
    CEcoASNOne1ExEmployeeNumber_247D52F9* pCMe = (CEcoASNOne1ExEmployeeNumber_247D52F9*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_INTEGER->pVTbl->get_Value(pCMe->m_INTEGER, Value, Size);

    return result;
}

/* Create Virtual Table IEcoASNOne1ExEmployeeNumber */
IEcoASNOne1ExEmployeeNumberVTbl g_x440D2626FE3349A08266393C3E7987CCVTbl_247D52F9 = {
    CEcoASNOne1ExEmployeeNumber_247D52F9_QueryInterface,
    CEcoASNOne1ExEmployeeNumber_247D52F9_AddRef,
    CEcoASNOne1ExEmployeeNumber_247D52F9_Release,
    CEcoASNOne1ExEmployeeNumber_247D52F9_get_Tag,
    CEcoASNOne1ExEmployeeNumber_247D52F9_get_TaggetType,
    CEcoASNOne1ExEmployeeNumber_247D52F9_get_Type,
    CEcoASNOne1ExEmployeeNumber_247D52F9_set_Value,
    CEcoASNOne1ExEmployeeNumber_247D52F9_get_Value
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
int16_t ECOCALLMETHOD createCEcoASNOne1ExEmployeeNumber_247D52F9(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoASNOne1ExEmployeeNumberPtr_t* ppIEmployeeNumber) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoASNOne1ExEmployeeNumber_247D52F9* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppIEmployeeNumber == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoASNOne1ExEmployeeNumber_247D52F9*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoASNOne1ExEmployeeNumber_247D52F9));
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

    /* Создание таблицы функций интерфейса IEcoASNOne1EmployeeNumber */
    pCMe->m_pVTblIEmployeeNumber = &g_x440D2626FE3349A08266393C3E7987CCVTbl_247D52F9;

    /* Сохранение указателя на интерфейс для работы с нотацией ASN.1 */
    pCMe->m_pIASNOne = pIASNOne;
    pCMe->m_pIASNOne->pVTbl->AddRef(pCMe->m_pIASNOne);

    /* Инициализация данных */
    pCMe->m_INTEGER = 0;
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_CLASS_APPLICATION | 2, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_INTEGER_TYPE, &pCMe->m_INTEGER);

    /* Возврат указателя на интерфейс */
    *ppIEmployeeNumber = (IEcoASNOne1ExEmployeeNumber*)pCMe;

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
void ECOCALLMETHOD deleteCEcoASNOne1ExEmployeeNumber_247D52F9(/* in */ IEcoASNOne1ExEmployeeNumberPtr_t pIEmployeeNumber) {
    CEcoASNOne1ExEmployeeNumber_247D52F9* pCMe = (CEcoASNOne1ExEmployeeNumber_247D52F9*)pIEmployeeNumber;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEmployeeNumber != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
