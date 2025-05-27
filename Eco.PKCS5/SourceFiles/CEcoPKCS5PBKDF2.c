/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS5PBKDF2
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoPKCS5PBKDF2
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
#include "CEcoPKCS5PBKDF2.h"

 /*
  *
  * <сводка>
  *   Функция QueryInterface
  * </сводка>
  *
  * <описание>
  *   Функция QueryInterface для интерфейса IEcoPKCS5PBKDF2
  * </описание>
  *
  */
static int16_t ECOCALLMETHOD CEcoPKCS5PBKDF2_QueryInterface(/* in */ IEcoPKCS5PBKDF2Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if (IsEqualUGUID(riid, &IID_IEcoPKCS5PBKDF2)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5PBKDF2;
        pCMe->m_pVTblIEcoPKCS5PBKDF2->AddRef((IEcoPKCS5PBKDF2*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5PBKDF2;
        pCMe->m_pVTblIEcoPKCS5PBKDF2->AddRef((IEcoPKCS5PBKDF2*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1Type)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5PBKDF2;
        pCMe->m_pVTblIEcoPKCS5PBKDF2->AddRef((IEcoPKCS5PBKDF2*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1ValueSet)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5PBKDF2;
        pCMe->m_pVTblIEcoPKCS5PBKDF2->AddRef((IEcoPKCS5PBKDF2*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoPKCS5PBKDF2
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS5PBKDF2_AddRef(/* in */ IEcoPKCS5PBKDF2Ptr_t me) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)me;

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
 *   Функция Release для интерфейса IEcoPKCS5PBKDF2
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS5PBKDF2_Release(/* in */ IEcoPKCS5PBKDF2Ptr_t me) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)me;

    /* Проверка указателя */
    if (me == 0) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if (pCMe->m_cRef == 0) {
        deleteCEcoPKCS5PBKDF2((IEcoPKCS5PBKDF2*)pCMe);
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
static uint8_t ECOCALLMETHOD CEcoPKCS5PBKDF2_get_Tag(/* in */ IEcoPKCS5PBKDF2Ptr_t me) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)me;

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
static uint8_t ECOCALLMETHOD CEcoPKCS5PBKDF2_get_TaggetType(/* in */ IEcoPKCS5PBKDF2Ptr_t me) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)me;

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
static uint8_t ECOCALLMETHOD CEcoPKCS5PBKDF2_get_Type(/* in */ IEcoPKCS5PBKDF2Ptr_t me) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)me;

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
static int16_t ECOCALLMETHOD CEcoPKCS5PBKDF2_Count(/* in */ IEcoPKCS5PBKDF2Ptr_t me, /* in */ int32_t* Count) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)me;
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
static int16_t ECOCALLMETHOD CEcoPKCS5PBKDF2_Item(/* in */ IEcoPKCS5PBKDF2Ptr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)me;
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
static int16_t ECOCALLMETHOD CEcoPKCS5PBKDF2_Add(/* in */ IEcoPKCS5PBKDF2Ptr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)me;
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
static IEcoASNOne1Value* ECOCALLMETHOD CEcoPKCS5PBKDF2_salt(/* in */ IEcoPKCS5PBKDF2Ptr_t me) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_salt;
}

static IEcoASNOne1Value* ECOCALLMETHOD CEcoPKCS5PBKDF2_iterationCount(/* in */ IEcoPKCS5PBKDF2Ptr_t me) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_iterationCount;
}

static IEcoASNOne1Value* ECOCALLMETHOD CEcoPKCS5PBKDF2_keyLength(/* in */ IEcoPKCS5PBKDF2Ptr_t me) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_keyLength;
}

/* Create Virtual Table IEcoPKCS5PBKDF2 */
IEcoPKCS5PBKDF2VTbl g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F7 = {
    CEcoPKCS5PBKDF2_QueryInterface,
    CEcoPKCS5PBKDF2_AddRef,
    CEcoPKCS5PBKDF2_Release,
    CEcoPKCS5PBKDF2_get_Tag,
    CEcoPKCS5PBKDF2_get_TaggetType,
    CEcoPKCS5PBKDF2_get_Type,
    CEcoPKCS5PBKDF2_Count,
    CEcoPKCS5PBKDF2_Item,
    CEcoPKCS5PBKDF2_Add,
    CEcoPKCS5PBKDF2_salt,
    CEcoPKCS5PBKDF2_iterationCount,
    CEcoPKCS5PBKDF2_keyLength,
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
int16_t ECOCALLMETHOD createCEcoPKCS5PBKDF2(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoPKCS5PBKDF2Ptr_t* ppIChildInformation) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoPKCS5PBKDF2* pCMe = 0;
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
    pCMe = (CEcoPKCS5PBKDF2*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoPKCS5PBKDF2));
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
    pCMe->m_pVTblIEcoPKCS5PBKDF2 = &g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F7;

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

    pCMe->m_keyLength = 0;
    pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pCMe->m_keyLength);
    pCMe->m_SEQUENCE->pVTbl->Add(pCMe->m_SEQUENCE, pCMe->m_keyLength, 0);

    /* Возврат указателя на интерфейс */
    *ppIChildInformation = (IEcoPKCS5PBKDF2*)pCMe;

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
void ECOCALLMETHOD deleteCEcoPKCS5PBKDF2(/* in */ IEcoPKCS5PBKDF2Ptr_t pIChildInformation) {
    CEcoPKCS5PBKDF2* pCMe = (CEcoPKCS5PBKDF2*)pIChildInformation;
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
