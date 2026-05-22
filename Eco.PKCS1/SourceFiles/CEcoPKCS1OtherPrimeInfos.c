/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS1OtherPrimeInfos
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoPKCS1OtherPrimeInfos
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
#include "CEcoPKCS1OtherPrimeInfos.h"

 /*
  *
  * <сводка>
  *   Функция QueryInterface
  * </сводка>
  *
  * <описание>
  *   Функция QueryInterface для интерфейса IEcoPKCS1OtherPrimeInfos
  * </описание>
  *
  */
static int16_t ECOCALLMETHOD CEcoPKCS1OtherPrimeInfos_QueryInterface(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS1OtherPrimeInfos* pCMe = (CEcoPKCS1OtherPrimeInfos*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if (IsEqualUGUID(riid, &IID_IEcoPKCS1OtherPrimeInfos)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS1OtherPrimeInfos;
        pCMe->m_pVTblIEcoPKCS1OtherPrimeInfos->AddRef((IEcoPKCS1OtherPrimeInfos*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS1OtherPrimeInfos;
        pCMe->m_pVTblIEcoPKCS1OtherPrimeInfos->AddRef((IEcoPKCS1OtherPrimeInfos*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1Type)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS1OtherPrimeInfos;
        pCMe->m_pVTblIEcoPKCS1OtherPrimeInfos->AddRef((IEcoPKCS1OtherPrimeInfos*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1Value)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS1OtherPrimeInfos;
        pCMe->m_pVTblIEcoPKCS1OtherPrimeInfos->AddRef((IEcoPKCS1OtherPrimeInfos*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoPKCS1OtherPrimeInfos
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS1OtherPrimeInfos_AddRef(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me) {
    CEcoPKCS1OtherPrimeInfos* pCMe = (CEcoPKCS1OtherPrimeInfos*)me;

    /* Проверка указателя */
    if (me == 0) {
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
 *   Функция Release для интерфейса IEcoPKCS1OtherPrimeInfos
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS1OtherPrimeInfos_Release(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me) {
    CEcoPKCS1OtherPrimeInfos* pCMe = (CEcoPKCS1OtherPrimeInfos*)me;

    /* Проверка указателя */
    if (me == 0) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if (pCMe->m_cRef == 0) {
        deleteCEcoPKCS1OtherPrimeInfos((IEcoPKCS1OtherPrimeInfos*)pCMe);
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
static uint8_t ECOCALLMETHOD CEcoPKCS1OtherPrimeInfos_get_Tag(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me) {
    CEcoPKCS1OtherPrimeInfos* pCMe = (CEcoPKCS1OtherPrimeInfos*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_value->pVTbl->get_Tag(pCMe->m_value);
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
static uint8_t ECOCALLMETHOD CEcoPKCS1OtherPrimeInfos_get_TaggetType(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me) {
    CEcoPKCS1OtherPrimeInfos* pCMe = (CEcoPKCS1OtherPrimeInfos*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_value->pVTbl->get_TaggedType(pCMe->m_value);
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
static uint8_t ECOCALLMETHOD CEcoPKCS1OtherPrimeInfos_get_Type(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me) {
    CEcoPKCS1OtherPrimeInfos* pCMe = (CEcoPKCS1OtherPrimeInfos*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_value->pVTbl->get_Type(pCMe->m_value);
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
static int16_t ECOCALLMETHOD CEcoPKCS1OtherPrimeInfos_set_Value(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me, /* in */ voidptr_t Value, /* in */ int32_t Size) {
    CEcoPKCS1OtherPrimeInfos* pCMe = (CEcoPKCS1OtherPrimeInfos*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_value->pVTbl->set_Value(pCMe->m_value, Value, Size);

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
static int16_t ECOCALLMETHOD CEcoPKCS1OtherPrimeInfos_get_Value(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t me, /* out */ voidptr_t Value, /* out */ int32_t* Size) {
    CEcoPKCS1OtherPrimeInfos* pCMe = (CEcoPKCS1OtherPrimeInfos*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = pCMe->m_value->pVTbl->get_Value(pCMe->m_value, Value, Size);

    return result;
}

/* Create Virtual Table IEcoPKCS1OtherPrimeInfos */
IEcoPKCS1OtherPrimeInfosVTbl g_x440D2626FE3349A08266393C3E7987C2 = {
    CEcoPKCS1OtherPrimeInfos_QueryInterface,
    CEcoPKCS1OtherPrimeInfos_AddRef,
    CEcoPKCS1OtherPrimeInfos_Release,
    CEcoPKCS1OtherPrimeInfos_get_Tag,
    CEcoPKCS1OtherPrimeInfos_get_TaggetType,
    CEcoPKCS1OtherPrimeInfos_get_Type,
    CEcoPKCS1OtherPrimeInfos_set_Value,
    CEcoPKCS1OtherPrimeInfos_get_Value
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
int16_t ECOCALLMETHOD createCEcoPKCS1OtherPrimeInfos(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoPKCS1OtherPrimeInfosPtr_t* pInfo) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoPKCS1OtherPrimeInfos* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (pInfo == 0 || pIUnkSystem == 0) {
        return result; /* ERR_ECO_POINTER */
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void**)&pISys);
    /* Проверка */
    if (result != 0 || pISys == 0) {
        return ERR_ECO_NOSYSTEM;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);
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
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**)&pIMem);
    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_GET_MEMORY_ALLOCATOR;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoPKCS1OtherPrimeInfos*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoPKCS1OtherPrimeInfos));
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
    pCMe->m_pVTblIEcoPKCS1OtherPrimeInfos = &g_x440D2626FE3349A08266393C3E7987C2;

    /* Сохранение указателя на интерфейс для работы с нотацией ASN.1 */
    pCMe->m_pIASNOne = pIASNOne;
    pCMe->m_pIASNOne->pVTbl->AddRef(pCMe->m_pIASNOne);

    /* Инициализация данных */
    pCMe->m_value = 0;
    pIASNOne->pVTbl->new_Value(pIASNOne, ECO_ASN1_CLASS_APPLICATION | 2, ECO_ASN1_TAG_IMPLICIT, ECO_ASN1_INTEGER_TYPE, &pCMe->m_value);

    /* Возврат указателя на интерфейс */
    *pInfo = (IEcoPKCS1OtherPrimeInfos*)pCMe;

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
void ECOCALLMETHOD deleteCEcoPKCS1OtherPrimeInfos(/* in */ IEcoPKCS1OtherPrimeInfosPtr_t pIEmployeeNumber) {
    CEcoPKCS1OtherPrimeInfos* pCMe = (CEcoPKCS1OtherPrimeInfos*)pIEmployeeNumber;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEmployeeNumber != 0) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}