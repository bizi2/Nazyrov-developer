/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS5RC5CBCParameter
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoPKCS5RC5CBCParameter
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
#include "CEcoPKCS5RC5CBCParameter.h"

 /*
  *
  * <сводка>
  *   Функция QueryInterface
  * </сводка>
  *
  * <описание>
  *   Функция QueryInterface для интерфейса IEcoPKCS5RC5CBCParameter
  * </описание>
  *
  */
static int16_t ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_QueryInterface(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if (IsEqualUGUID(riid, &IID_IEcoPKCS5RC5CBCParameter)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5RC5CBCParameter;
        pCMe->m_pVTblIEcoPKCS5RC5CBCParameter->AddRef((IEcoPKCS5RC5CBCParameter*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5RC5CBCParameter;
        pCMe->m_pVTblIEcoPKCS5RC5CBCParameter->AddRef((IEcoPKCS5RC5CBCParameter*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1Type)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5RC5CBCParameter;
        pCMe->m_pVTblIEcoPKCS5RC5CBCParameter->AddRef((IEcoPKCS5RC5CBCParameter*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoASNOne1ValueSet)) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5RC5CBCParameter;
        pCMe->m_pVTblIEcoPKCS5RC5CBCParameter->AddRef((IEcoPKCS5RC5CBCParameter*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoPKCS5RC5CBCParameter
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_AddRef(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;

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
 *   Функция Release для интерфейса IEcoPKCS5RC5CBCParameter
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_Release(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;

    /* Проверка указателя */
    if (me == 0) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if (pCMe->m_cRef == 0) {
        deleteCEcoPKCS5RC5CBCParameter((IEcoPKCS5RC5CBCParameter*)pCMe);
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
static uint8_t ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_get_Tag(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;

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
static uint8_t ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_get_TaggetType(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;

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
static uint8_t ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_get_Type(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;

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
static int16_t ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_Count(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me, /* in */ int32_t* Count) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;
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
static int16_t ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_Item(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;
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
static int16_t ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_Add(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;
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
static IEcoASNOne1Value* ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_version(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_version;
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
static IEcoASNOne1Value* ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_rounds(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_rounds;
}

static IEcoASNOne1Value* ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_blockSizeInBits(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_blockSizeInBits;
}

static IEcoASNOne1Value* ECOCALLMETHOD CEcoPKCS5RC5CBCParameter_iv(/* in */ IEcoPKCS5RC5CBCParameterPtr_t me) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    return pCMe->m_iv;
}

/* Create Virtual Table IEcoPKCS5RC5CBCParameter */
IEcoPKCS5RC5CBCParameterVTbl g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F9 = {
    CEcoPKCS5RC5CBCParameter_QueryInterface,
    CEcoPKCS5RC5CBCParameter_AddRef,
    CEcoPKCS5RC5CBCParameter_Release,
    CEcoPKCS5RC5CBCParameter_get_Tag,
    CEcoPKCS5RC5CBCParameter_get_TaggetType,
    CEcoPKCS5RC5CBCParameter_get_Type,
    CEcoPKCS5RC5CBCParameter_Count,
    CEcoPKCS5RC5CBCParameter_Item,
    CEcoPKCS5RC5CBCParameter_Add,
    CEcoPKCS5RC5CBCParameter_version,
    CEcoPKCS5RC5CBCParameter_rounds,
    CEcoPKCS5RC5CBCParameter_blockSizeInBits,
    CEcoPKCS5RC5CBCParameter_iv,
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
int16_t ECOCALLMETHOD createCEcoPKCS5RC5CBCParameter(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoPKCS5RC5CBCParameterPtr_t* ppIChildInformation) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoPKCS5RC5CBCParameter* pCMe = 0;
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
    pCMe = (CEcoPKCS5RC5CBCParameter*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoPKCS5RC5CBCParameter));
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
    pCMe->m_pVTblIEcoPKCS5RC5CBCParameter = &g_xD739CAFE1BE24191A824788A1439E7A1VTbl_247D52F9;

    /* Сохранение указателя на интерфейс для работы с нотацией ASN.1 */
    pCMe->m_pIASNOne = pIASNOne;
    pCMe->m_pIASNOne->pVTbl->AddRef(pCMe->m_pIASNOne);

    /* Инициализация данных */
    pCMe->m_SEQUENCE = 0;
    pIASNOne->pVTbl->new_ValueSet(pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_PC_CONSTRUCTED | ECO_ASN1_SET_TYPE, &pCMe->m_SEQUENCE);
    pCMe->m_version = 0;
    pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pCMe->m_version);
    pCMe->m_SEQUENCE->pVTbl->Add(pCMe->m_SEQUENCE, pCMe->m_version, 0);

    pCMe->m_blockSizeInBits = 0;
    pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pCMe->m_blockSizeInBits);
    pCMe->m_SEQUENCE->pVTbl->Add(pCMe->m_SEQUENCE, pCMe->m_blockSizeInBits, 0);

    pCMe->m_iv = 0;
    pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pCMe->m_iv);
    pCMe->m_SEQUENCE->pVTbl->Add(pCMe->m_SEQUENCE, pCMe->m_iv, 0);

    pCMe->m_rounds = 0;
    pCMe->m_pIASNOne->pVTbl->new_Value(pCMe->m_pIASNOne, ECO_ASN1_EMPTY, ECO_ASN1_TAG_EMPTY, ECO_ASN1_VISIBLE_STRING_TYPE, &pCMe->m_rounds);
    pCMe->m_SEQUENCE->pVTbl->Add(pCMe->m_SEQUENCE, pCMe->m_rounds, 0);

    /* Возврат указателя на интерфейс */
    *ppIChildInformation = (IEcoPKCS5RC5CBCParameter*)pCMe;

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
void ECOCALLMETHOD deleteCEcoPKCS5RC5CBCParameter(/* in */ IEcoPKCS5RC5CBCParameterPtr_t pIChildInformation) {
    CEcoPKCS5RC5CBCParameter* pCMe = (CEcoPKCS5RC5CBCParameter*)pIChildInformation;
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
