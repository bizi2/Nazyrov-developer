/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS7SignerInfos
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoPKCS7SignerInfos
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
#include "CEcoPKCS7SignerInfos.h"
#include "CEcoPKCS7SignerInfo.h"

 /*
  *
  * <сводка>
  *   Функция QueryInterface
  * </сводка>
  *
  * <описание>
  *   Функция QueryInterface для интерфейса IEcoPKCS7SignerInfos
  * </описание>
  *
  */
static int16_t ECOCALLMETHOD CEcoPKCS7SignerInfos_QueryInterface(/* in */ IEcoPKCS7SignerInfosPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS7SignerInfos* pCMe = (CEcoPKCS7SignerInfos*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if (IsEqualUGUID(riid, &IID_IEcoPKCS7SignerInfos)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7SignerInfos;
        pCMe->m_pVTblIEcoPKCS7SignerInfos->AddRef((IEcoPKCS7SignerInfos*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7SignerInfos;
        pCMe->m_pVTblIEcoPKCS7SignerInfos->AddRef((IEcoPKCS7SignerInfos*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1Type)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7SignerInfos;
        pCMe->m_pVTblIEcoPKCS7SignerInfos->AddRef((IEcoPKCS7SignerInfos*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1ValueSet)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS7SignerInfos;
        pCMe->m_pVTblIEcoPKCS7SignerInfos->AddRef((IEcoPKCS7SignerInfos*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoPKCS7SignerInfos
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS7SignerInfos_AddRef(/* in */ IEcoPKCS7SignerInfosPtr_t me) {
    CEcoPKCS7SignerInfos* pCMe = (CEcoPKCS7SignerInfos*)me;

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
 *   Функция Release для интерфейса IEcoPKCS7SignerInfos
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS7SignerInfos_Release(/* in */ IEcoPKCS7SignerInfosPtr_t me) {
    CEcoPKCS7SignerInfos* pCMe = (CEcoPKCS7SignerInfos*)me;

    /* Проверка указателя */
    if (me == 0) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if (pCMe->m_cRef == 0) {
        deleteCEcoPKCS7SignerInfos((IEcoPKCS7SignerInfos*)pCMe);
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
static uint8_t ECOCALLMETHOD CEcoPKCS7SignerInfos_get_Tag(/* in */ IEcoPKCS7SignerInfosPtr_t me) {
    CEcoPKCS7SignerInfos* pCMe = (CEcoPKCS7SignerInfos*)me;

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
static uint8_t ECOCALLMETHOD CEcoPKCS7SignerInfos_get_TaggetType(/* in */ IEcoPKCS7SignerInfosPtr_t me) {
    CEcoPKCS7SignerInfos* pCMe = (CEcoPKCS7SignerInfos*)me;

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
static uint8_t ECOCALLMETHOD CEcoPKCS7SignerInfos_get_Type(/* in */ IEcoPKCS7SignerInfosPtr_t me) {
    CEcoPKCS7SignerInfos* pCMe = (CEcoPKCS7SignerInfos*)me;

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
static int16_t ECOCALLMETHOD CEcoPKCS7SignerInfos_Count(/* in */ IEcoPKCS7SignerInfosPtr_t me, /* in */ int32_t* Count) {
    CEcoPKCS7SignerInfos* pCMe = (CEcoPKCS7SignerInfos*)me;
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
static int16_t ECOCALLMETHOD CEcoPKCS7SignerInfos_Item(/* in */ IEcoPKCS7SignerInfosPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component) {
    CEcoPKCS7SignerInfos* pCMe = (CEcoPKCS7SignerInfos*)me;
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
static int16_t ECOCALLMETHOD CEcoPKCS7SignerInfos_Add(/* in */ IEcoPKCS7SignerInfosPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index) {
    CEcoPKCS7SignerInfos* pCMe = (CEcoPKCS7SignerInfos*)me;
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
static IEcoPKCS7RecipientInfo* ECOCALLMETHOD CEcoPKCS7SignerInfos_siSet(/* in */ IEcoPKCS7SignerInfosPtr_t me) {
    CEcoPKCS7SignerInfos* pCMe = (CEcoPKCS7SignerInfos*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_siSet;
}

/*
 *
 * <сводка>
 *   Функция dateOfBirth
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static IEcoPKCS7RecipientInfo* ECOCALLMETHOD CEcoPKCS7SignerInfos_siSequence(/* in */ IEcoPKCS7SignerInfosPtr_t me) {
    CEcoPKCS7SignerInfos* pCMe = (CEcoPKCS7SignerInfos*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_siSequence;
}

/* Create Virtual Table IEcoPKCS7SignerInfos */
IEcoPKCS7SignerInfosVTbl g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F9 = {
    CEcoPKCS7SignerInfos_QueryInterface,
    CEcoPKCS7SignerInfos_AddRef,
    CEcoPKCS7SignerInfos_Release,
    CEcoPKCS7SignerInfos_get_Tag,
    CEcoPKCS7SignerInfos_get_TaggetType,
    CEcoPKCS7SignerInfos_get_Type,
    CEcoPKCS7SignerInfos_Count,
    CEcoPKCS7SignerInfos_Item,
    CEcoPKCS7SignerInfos_Add,
    CEcoPKCS7SignerInfos_siSet,
    CEcoPKCS7SignerInfos_siSequence,
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
int16_t ECOCALLMETHOD createCEcoPKCS7SignerInfos(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoPKCS7SignerInfosPtr_t* ppIChildInformation) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoPKCS7SignerInfos* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
    IEcoASNOne1ValueSet* pIValueSet = 0;

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
    pCMe = (CEcoPKCS7SignerInfos*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoPKCS7SignerInfos));
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
    pCMe->m_pVTblIEcoPKCS7SignerInfos = &g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F9;

    /* Сохранение указателя на интерфейс для работы с нотацией ASN.1 */
    pCMe->m_pIASNOne = pIASNOne;
    pCMe->m_pIASNOne->pVTbl->AddRef(pCMe->m_pIASNOne);

    /* Инициализация данных */
    pCMe->m_SET = 0;
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_PC_CONSTRUCTED | ECO_ASN1_SET_TYPE, &pCMe->m_SET);
    pCMe->m_siSet = 0;
    createCEcoPKCS7RecipientInfo((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_siSet);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pCMe->m_siSet, 0);

    pCMe->m_siSequence = 0;
    createCEcoPKCS7RecipientInfo((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, &pCMe->m_siSequence);
    pCMe->m_SET->pVTbl->Add(pCMe->m_SET, pCMe->m_siSequence, 0);

    /* Возврат указателя на интерфейс */
    *ppIChildInformation = (IEcoPKCS7SignerInfos*)pCMe;

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
void ECOCALLMETHOD deleteCEcoPKCS7SignerInfos(/* in */ IEcoPKCS7SignerInfosPtr_t pIChildInformation) {
    CEcoPKCS7SignerInfos* pCMe = (CEcoPKCS7SignerInfos*)pIChildInformation;
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

