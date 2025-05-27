/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS5PBEParameter
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoPKCS5PBEParameter
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2025 Vinokurov Ivan. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoPKCS5PBEParameter.h"

 /*
  *
  * <сводка>
  *   Функция QueryInterface
  * </сводка>
  *
  * <описание>
  *   Функция QueryInterface для интерфейса IEcoPKCS5PBEParameter
  * </описание>
  *
  */
static int16_t ECOCALLMETHOD CEcoPKCS5PBEParameter_QueryInterface(/* in */ IEcoPKCS5PBEParameterPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS5PBEParameter* pCMe = (CEcoPKCS5PBEParameter*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if (IsEqualUGUID(riid, &IID_IEcoPKCS5PBEParameter)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5PBEParameter;
        pCMe->m_pVTblIEcoPKCS5PBEParameter->AddRef((IEcoPKCS5PBEParameter*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5PBEParameter;
        pCMe->m_pVTblIEcoPKCS5PBEParameter->AddRef((IEcoPKCS5PBEParameter*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1Type)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5PBEParameter;
        pCMe->m_pVTblIEcoPKCS5PBEParameter->AddRef((IEcoPKCS5PBEParameter*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1ValueSet)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5PBEParameter;
        pCMe->m_pVTblIEcoPKCS5PBEParameter->AddRef((IEcoPKCS5PBEParameter*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoPKCS5PBEParameter
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS5PBEParameter_AddRef(/* in */ IEcoPKCS5PBEParameterPtr_t me) {
    CEcoPKCS5PBEParameter* pCMe = (CEcoPKCS5PBEParameter*)me;

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
 *   Функция Release для интерфейса IEcoPKCS5PBEParameter
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS5PBEParameter_Release(/* in */ IEcoPKCS5PBEParameterPtr_t me) {
    CEcoPKCS5PBEParameter* pCMe = (CEcoPKCS5PBEParameter*)me;

    /* Проверка указателя */
    if (me == 0) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if (pCMe->m_cRef == 0) {
        deleteCEcoPKCS5PBEParameter((IEcoPKCS5PBEParameter*)pCMe);
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
static uint8_t ECOCALLMETHOD CEcoPKCS5PBEParameter_get_Tag(/* in */ IEcoPKCS5PBEParameterPtr_t me) {
    CEcoPKCS5PBEParameter* pCMe = (CEcoPKCS5PBEParameter*)me;

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
static uint8_t ECOCALLMETHOD CEcoPKCS5PBEParameter_get_TaggetType(/* in */ IEcoPKCS5PBEParameterPtr_t me) {
    CEcoPKCS5PBEParameter* pCMe = (CEcoPKCS5PBEParameter*)me;

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
static uint8_t ECOCALLMETHOD CEcoPKCS5PBEParameter_get_Type(/* in */ IEcoPKCS5PBEParameterPtr_t me) {
    CEcoPKCS5PBEParameter* pCMe = (CEcoPKCS5PBEParameter*)me;

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
static int16_t ECOCALLMETHOD CEcoPKCS5PBEParameter_Count(/* in */ IEcoPKCS5PBEParameterPtr_t me, /* in */ int32_t* Count) {
    CEcoPKCS5PBEParameter* pCMe = (CEcoPKCS5PBEParameter*)me;
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
static int16_t ECOCALLMETHOD CEcoPKCS5PBEParameter_Item(/* in */ IEcoPKCS5PBEParameterPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component) {
    CEcoPKCS5PBEParameter* pCMe = (CEcoPKCS5PBEParameter*)me;
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
static int16_t ECOCALLMETHOD CEcoPKCS5PBEParameter_Add(/* in */ IEcoPKCS5PBEParameterPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index) {
    CEcoPKCS5PBEParameter* pCMe = (CEcoPKCS5PBEParameter*)me;
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
 *   Функция name
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoASNOne1Value* ECOCALLMETHOD CEcoPKCS5PBEParameter_salt(/* in */ IEcoPKCS5PBEParameterPtr_t me) {
    CEcoPKCS5PBEParameter* pCMe = (CEcoPKCS5PBEParameter*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_salt;
}

static IEcoASNOne1Value* ECOCALLMETHOD CEcoPKCS5PBEParameter_iterationCount(/* in */ IEcoPKCS5PBEParameterPtr_t me) {
    CEcoPKCS5PBEParameter* pCMe = (CEcoPKCS5PBEParameter*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_iterationCount;
}

/* Create Virtual Table IEcoPKCS5PBEParameter */
IEcoPKCS5PBEParameterVTbl g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F1 = {
    CEcoPKCS5PBEParameter_QueryInterface,
    CEcoPKCS5PBEParameter_AddRef,
    CEcoPKCS5PBEParameter_Release,
    CEcoPKCS5PBEParameter_get_Tag,
    CEcoPKCS5PBEParameter_get_TaggetType,
    CEcoPKCS5PBEParameter_get_Type,
    CEcoPKCS5PBEParameter_Count,
    CEcoPKCS5PBEParameter_Item,
    CEcoPKCS5PBEParameter_Add,
    CEcoPKCS5PBEParameter_salt,
    CEcoPKCS5PBEParameter_iterationCount,
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
int16_t ECOCALLMETHOD createCEcoPKCS5PBEParameter(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoPKCS5PBEParameterPtr_t* ppIChildInformation) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoPKCS5PBEParameter* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
    IEcoASNOne1ValueSet* piterationCountalueSet = 0;

    /* Проверка указателей */
    if (ppIChildInformation == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoPKCS5PBEParameter*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoPKCS5PBEParameter));
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

    /* Создание таблицы функций интерфейса IEcoASNOne1ChildInformation */
    pCMe->m_pVTblIEcoPKCS5PBEParameter = &g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F1;

    /* Сохранение указателя на интерфейс для работы с нотацией ASN.1 */
    pCMe->m_pIASNOne = pIASNOne;
    pCMe->m_pIASNOne->pVTbl->AddRef(pCMe->m_pIASNOne);

    /* Инициализация данных */
    pCMe->m_SEQUENCE = 0;
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_PC_CONSTRUCTED | ECO_ASN1_SET_TYPE, &pCMe->m_SEQUENCE);
    pCMe->m_salt = 0;
    pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pCMe->m_salt);
    pCMe->m_SEQUENCE->pVTbl->Add(pCMe->m_SEQUENCE, pCMe->m_salt, 0);

    pCMe->m_iterationCount = 0;
    pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pCMe->m_iterationCount);
    pCMe->m_SEQUENCE->pVTbl->Add(pCMe->m_SEQUENCE, pCMe->m_iterationCount, 0);

    /* Возврат указателя на интерфейс */
    *ppIChildInformation = (IEcoPKCS5PBEParameter*)pCMe;

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
void ECOCALLMETHOD deleteCEcoPKCS5PBEParameter(/* in */ IEcoPKCS5PBEParameterPtr_t pIChildInformation) {
    CEcoPKCS5PBEParameter* pCMe = (CEcoPKCS5PBEParameter*)pIChildInformation;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIChildInformation != 0) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
