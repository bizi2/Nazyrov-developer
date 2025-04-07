/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1Value_11B2F7AB
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoASNOne1Value_11B2F7AB
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
#include "CEcoASNOne1Value.h"
#include "ErrEcoASNOne1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoASNOne1Value
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_QueryInterface(/* in */ IEcoASNOne1ValuePtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoASNOne1Value) ) {
        *ppv = &pCMe->m_pVTblIValue;
        pCMe->m_pVTblIValue->AddRef((IEcoASNOne1Value*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIValue;
        pCMe->m_pVTblIValue->AddRef((IEcoASNOne1Value*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoASNOne1Type) ) {
        *ppv = &pCMe->m_pVTblIValue;
        pCMe->m_pVTblIValue->AddRef((IEcoASNOne1Value*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoASNOne1EncodingRules) ) {
        *ppv = &pCMe->m_pVTblIEncoding;
        pCMe->m_pVTblIValue->AddRef((IEcoASNOne1Value*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoASNOne1Value
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_AddRef(/* in */ IEcoASNOne1ValuePtr_t me) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)me;

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
 *   Функция Release для интерфейса IEcoASNOne1Value
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_Release(/* in */ IEcoASNOne1ValuePtr_t me) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoASNOne1Value_11B2F7AB((IEcoASNOne1Value*)pCMe);
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
static uint8_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_get_Tag(/* in */ IEcoASNOne1ValuePtr_t me) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_Tag;
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
static uint8_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_get_TaggetType(/* in */ IEcoASNOne1ValuePtr_t me) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_TaggetType;
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
static uint8_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_get_Type(/* in */ IEcoASNOne1ValuePtr_t me) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_Type;
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
static int16_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_set_Value(/* in */ IEcoASNOne1ValuePtr_t me, /* in */ voidptr_t Value, /* in */ int32_t Size) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)me;

    /* Проверка указателей */
    if (me == 0 || Value == 0) {
        return ERR_ECO_POINTER;
    }

    if (Size > 0 && Size <= 64) {
        if (pCMe->m_Value == 0 || pCMe->m_Size != Size) {
            if (pCMe->m_Value != 0) {
                pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, pCMe->m_Value);
                pCMe->m_Value = 0;
                pCMe->m_Size = 0;
            }
            pCMe->m_Value = pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, Size);
            if (pCMe->m_Value == 0) {
                return ERR_ECO_OUTOFMEMORY;
            }
            pCMe->m_pIMem->pVTbl->Copy(pCMe->m_pIMem, pCMe->m_Value, Value, Size);
            pCMe->m_Size = Size;
        }
    }
    else {
        return ERR_ECO_ASN1_INVALID_SIZE;
    }

    return ERR_ECO_SUCCESES;
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
static int16_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_get_Value(/* in */ IEcoASNOne1ValuePtr_t me, /* out */ voidptr_t Value, /* out */ int32_t* Size) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)me;

    /* Проверка указателей */
    if (me == 0 || Size == 0) {
        return ERR_ECO_POINTER;
    }

    if (pCMe->m_Value == 0 || pCMe->m_Size == 0) {
        return ERR_ECO_ASN1_INVALID_VALUE;
    }

    if (*Size == 0 || *Size != pCMe->m_Size) {
        *Size = pCMe->m_Size;
        return ERR_ECO_ASN1_INVALID_SIZE;
    }

    if (Value == 0) {
        return ERR_ECO_POINTER;
    }

    pCMe->m_pIMem->pVTbl->Copy(pCMe->m_pIMem, Value, pCMe->m_Value, pCMe->m_Size);

    return ERR_ECO_SUCCESES;
}


/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoASNOne1EncodingRules
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_17B39B28_QueryInterface(/* in */ IEcoASNOne1EncodingRulesPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)((byte_t*)me - sizeof(IEcoUnknownPtr_t));

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoASNOne1Value) ) {
        *ppv = &pCMe->m_pVTblIValue;
        pCMe->m_pVTblIValue->AddRef((IEcoASNOne1Value*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIValue;
        pCMe->m_pVTblIValue->AddRef((IEcoASNOne1Value*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoASNOne1Type) ) {
        *ppv = &pCMe->m_pVTblIValue;
        pCMe->m_pVTblIValue->AddRef((IEcoASNOne1Value*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoASNOne1EncodingRules) ) {
        *ppv = &pCMe->m_pVTblIEncoding;
        pCMe->m_pVTblIValue->AddRef((IEcoASNOne1Value*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoASNOne1EncodingRules
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_17B39B28_AddRef(/* in */ IEcoASNOne1EncodingRulesPtr_t me) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)((byte_t*)me - sizeof(IEcoUnknownPtr_t));

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
 *   Функция Release для интерфейса IEcoASNOne1EncodingRules
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_17B39B28_Release(/* in */ IEcoASNOne1EncodingRulesPtr_t me) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)((byte_t*)me - sizeof(IEcoUnknownPtr_t));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoASNOne1Value_11B2F7AB((IEcoASNOne1Value*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Encode
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_17B39B28_Encode(/* in */ IEcoASNOne1EncodingRulesPtr_t me, /* in */ voidptr_t pv, /* out */ byte_t* buffer, /* out */ uint32_t* length) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)((byte_t*)me - sizeof(IEcoUnknownPtr_t));
    IEcoASNOne1EncodingRules* pIEncodingRules = 0;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    //if (pCMe->m_VisibleString != 0) {
    //    pCMe->m_VisibleString->pVTbl->QueryInterface(pCMe->m_VisibleString, &IID_IEcoASNOne1EncodingRules, (voidptr_t*)&pIEncodingRules);
    //    pIEncodingRules->pVTbl->Encode(pIEncodingRules, pv, buffer, length);
    //    pCMe->m_VisibleString->pVTbl->Release(pCMe->m_VisibleString);
    //}

    // Encode me

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Decode
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1Value_11B2F7AB_17B39B28_Decode(/* in */ IEcoASNOne1EncodingRulesPtr_t me, /* in */ byte_t* buffer, /* in */ uint32_t length, /* out */ voidptr_t* ppv) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)((byte_t*)me - sizeof(IEcoUnknownPtr_t));
    IEcoASNOne1EncodingRules* pIEncodingRules = 0;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /*ERR_ECO_POINTER*/
    }

    pIEncodingRules->pVTbl->Decode(pIEncodingRules, buffer, length, ppv);
    // Decode me

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoASNOne1Value_11B2F7AB(/*in*/ IEcoASNOne1ValuePtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return result;
}

/* Create Virtual Table IEcoASNOne1Value */
IEcoASNOne1ValueVTbl g_x188D761E316F43488274BE142A9EA308VTbl_11B2F7AB = {
    CEcoASNOne1Value_11B2F7AB_QueryInterface,
    CEcoASNOne1Value_11B2F7AB_AddRef,
    CEcoASNOne1Value_11B2F7AB_Release,
    CEcoASNOne1Value_11B2F7AB_get_Tag,
    CEcoASNOne1Value_11B2F7AB_get_TaggetType,
    CEcoASNOne1Value_11B2F7AB_get_Type,
    CEcoASNOne1Value_11B2F7AB_set_Value,
    CEcoASNOne1Value_11B2F7AB_get_Value
};

/* Create Virtual Table IEcoASNOne1EncodingRules */
IEcoASNOne1EncodingRulesVTbl g_x347BFCFBCFE3418F8EE5DADF17B39B28VTblValue_11B2F7AB = {
    CEcoASNOne1Value_11B2F7AB_17B39B28_QueryInterface,
    CEcoASNOne1Value_11B2F7AB_17B39B28_AddRef,
    CEcoASNOne1Value_11B2F7AB_17B39B28_Release,
    CEcoASNOne1Value_11B2F7AB_17B39B28_Encode,
    CEcoASNOne1Value_11B2F7AB_17B39B28_Decode
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
int16_t ECOCALLMETHOD createCEcoASNOne1Value_11B2F7AB(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ uint8_t Tag, /* in */ uint8_t TaggetType, /* in */ uint8_t Type, /* out */ IEcoASNOne1ValuePtr_t* ppIValue) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoASNOne1Value_11B2F7AB* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppIValue == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoASNOne1Value_11B2F7AB*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoASNOne1Value_11B2F7AB));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoASNOne1Value */
    pCMe->m_pVTblIValue = &g_x188D761E316F43488274BE142A9EA308VTbl_11B2F7AB;
    /* Создание таблицы функций интерфейса IEcoASNOneEncodingRules */
    pCMe->m_pVTblIEncoding = &g_x347BFCFBCFE3418F8EE5DADF17B39B28VTblValue_11B2F7AB;

    /* Инициализация данных */
    pCMe->m_Tag = Tag;
    pCMe->m_TaggetType = TaggetType;
    pCMe->m_Type = Type;
    pCMe->m_Value = 0;

    /* Возврат указателя на интерфейс */
    *ppIValue = (IEcoASNOne1Value*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
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
void ECOCALLMETHOD deleteCEcoASNOne1Value_11B2F7AB(/* in */ IEcoASNOne1ValuePtr_t pIValue) {
    CEcoASNOne1Value_11B2F7AB* pCMe = (CEcoASNOne1Value_11B2F7AB*)pIValue;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIValue != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Value != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Value);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
