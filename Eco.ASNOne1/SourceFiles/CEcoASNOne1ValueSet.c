/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1ValueSet_11B2F7AB
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoASNOne1ValueSet_11B2F7AB
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
#include "CEcoASNOne1ValueSet.h"
#include "ErrEcoASNOne1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoASNOne1ValueSet
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1ValueSet_11B2F7AB_QueryInterface(/* in */ IEcoASNOne1ValueSetPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoASNOne1ValueSet_11B2F7AB* pCMe = (CEcoASNOne1ValueSet_11B2F7AB*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoASNOne1ValueSet) ) {
        *ppv = &pCMe->m_pVTblIValueSet;
        pCMe->m_pVTblIValueSet->AddRef((IEcoASNOne1ValueSet*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoASNOne1Type) ) {
        *ppv = &pCMe->m_pVTblIValueSet;
        pCMe->m_pVTblIValueSet->AddRef((IEcoASNOne1ValueSet*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIValueSet;
        pCMe->m_pVTblIValueSet->AddRef((IEcoASNOne1ValueSet*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoASNOne1ValueSet
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1ValueSet_11B2F7AB_AddRef(/* in */ IEcoASNOne1ValueSetPtr_t me) {
    CEcoASNOne1ValueSet_11B2F7AB* pCMe = (CEcoASNOne1ValueSet_11B2F7AB*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
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
 *   Функция Release для интерфейса IEcoASNOne1ValueSet
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1ValueSet_11B2F7AB_Release(/* in */ IEcoASNOne1ValueSetPtr_t me) {
    CEcoASNOne1ValueSet_11B2F7AB* pCMe = (CEcoASNOne1ValueSet_11B2F7AB*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoASNOne1ValueSet_11B2F7AB((IEcoASNOne1ValueSet*)pCMe);
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
static uint8_t ECOCALLMETHOD CEcoASNOne1ValueSet_11B2F7AB_get_Tag(/* in */ IEcoASNOne1ValueSetPtr_t me) {
    CEcoASNOne1ValueSet_11B2F7AB* pCMe = (CEcoASNOne1ValueSet_11B2F7AB*)me;

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
static uint8_t ECOCALLMETHOD CEcoASNOne1ValueSet_11B2F7AB_get_TaggetType(/* in */ IEcoASNOne1ValueSetPtr_t me) {
    CEcoASNOne1ValueSet_11B2F7AB* pCMe = (CEcoASNOne1ValueSet_11B2F7AB*)me;

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
static uint8_t ECOCALLMETHOD CEcoASNOne1ValueSet_11B2F7AB_get_Type(/* in */ IEcoASNOne1ValueSetPtr_t me) {
    CEcoASNOne1ValueSet_11B2F7AB* pCMe = (CEcoASNOne1ValueSet_11B2F7AB*)me;

    /* Проверка указателей */
    if (me == 0) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_Type;
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
static int16_t ECOCALLMETHOD CEcoASNOne1ValueSet_11B2F7AB_Count(/* in */ IEcoASNOne1ValueSetPtr_t me, /* in */ int32_t* Count) {
    CEcoASNOne1ValueSet_11B2F7AB* pCMe = (CEcoASNOne1ValueSet_11B2F7AB*)me;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    if (Count != 0) {
        *Count = pCMe->m_Count;
    }

    return ERR_ECO_SUCCESES;
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
static int16_t ECOCALLMETHOD CEcoASNOne1ValueSet_11B2F7AB_Item(/* in */ IEcoASNOne1ValueSetPtr_t me, /* in */ uint32_t Index, /* out */ voidptr_t* Component) {
    CEcoASNOne1ValueSet_11B2F7AB* pCMe = (CEcoASNOne1ValueSet_11B2F7AB*)me;
    CEcoASNOne1ValueSetComponent_11B2F7AB* pPrev = 0;
    voidptr_t pComponent = 0;

    /* Проверка указателей */
    if (me == 0 || Component == 0) {
        return ERR_ECO_POINTER;
    }

    if (pCMe->m_Count > 0 && Index < pCMe->m_Count) {
        pPrev = pCMe->m_Components;
        do {
            if (Index == 0) {
                pComponent = pPrev->data;
                break;
            }
            Index--;
            pPrev = pPrev->next;

        } while (pPrev != 0);
    }

    *Component =  pComponent;

    return ERR_ECO_SUCCESES;
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
static int16_t ECOCALLMETHOD CEcoASNOne1ValueSet_11B2F7AB_Add(/* in */ IEcoASNOne1ValueSetPtr_t me, /* in */ voidptr_t Component, /* in */ int32_t* Index) {
    CEcoASNOne1ValueSet_11B2F7AB* pCMe = (CEcoASNOne1ValueSet_11B2F7AB*)me;
    CEcoASNOne1ValueSetComponent_11B2F7AB* pTemp = 0;
    int32_t index = -1;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    if (pCMe != 0) {
        if (pCMe->m_Components == 0) {
            pCMe->m_Components = (CEcoASNOne1ValueSetComponent_11B2F7AB*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, sizeof(CEcoASNOne1ValueSetComponent_11B2F7AB));
            if (pCMe->m_Components == 0) {
                return index;
            }
            pCMe->m_Components->data = Component;
            pCMe->m_Components->next = 0;
            index = 0;
            pCMe->m_Count = 1;
        }
        else {
            pTemp =  pCMe->m_Components;
            while ( pTemp->next != 0) {
                pTemp = pTemp->next;
            }
            pTemp->next = (CEcoASNOne1ValueSetComponent_11B2F7AB*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, sizeof(CEcoASNOne1ValueSetComponent_11B2F7AB));
            pTemp = pTemp->next;
            pTemp->data = Component;
            pTemp->next = 0;
            index = pCMe->m_Count;
            pCMe->m_Count++;
        }
    }
    if (Index != 0) {
        *Index = index;
    }

    return ERR_ECO_SUCCESES;
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
int16_t ECOCALLMETHOD initCEcoASNOne1ValueSet_11B2F7AB(/*in*/ IEcoASNOne1ValueSetPtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoASNOne1ValueSet_11B2F7AB* pCMe = (CEcoASNOne1ValueSet_11B2F7AB*)me;
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

/* Create Virtual Table IEcoASNOne1ValueSet */
IEcoASNOne1ValueSetVTbl g_x8312A9335DE74B47A9C014B2FE4B83C7VTbl_11B2F7AB = {
    CEcoASNOne1ValueSet_11B2F7AB_QueryInterface,
    CEcoASNOne1ValueSet_11B2F7AB_AddRef,
    CEcoASNOne1ValueSet_11B2F7AB_Release,
    CEcoASNOne1ValueSet_11B2F7AB_get_Tag,
    CEcoASNOne1ValueSet_11B2F7AB_get_TaggetType,
    CEcoASNOne1ValueSet_11B2F7AB_get_Type,
    CEcoASNOne1ValueSet_11B2F7AB_Count,
    CEcoASNOne1ValueSet_11B2F7AB_Item,
    CEcoASNOne1ValueSet_11B2F7AB_Add
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
int16_t ECOCALLMETHOD createCEcoASNOne1ValueSet_11B2F7AB(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ uint8_t Tag, /* in */ uint8_t TaggetType, /* in */ uint8_t Type, /* out */ IEcoASNOne1ValueSetPtr_t* ppIValueSet) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoASNOne1ValueSet_11B2F7AB* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppIValueSet == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoASNOne1ValueSet_11B2F7AB*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoASNOne1ValueSet_11B2F7AB));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoASNOne1ValueSet */
    pCMe->m_pVTblIValueSet = &g_x8312A9335DE74B47A9C014B2FE4B83C7VTbl_11B2F7AB;

    /* Инициализация данных экземпляра */
    pCMe->m_Tag = Tag;
    pCMe->m_TaggetType = TaggetType;
    pCMe->m_Type = Type;

    pCMe->m_Components = 0;
    pCMe->m_Count = 0;

    /* Возврат указателя на интерфейс */
    *ppIValueSet = (IEcoASNOne1ValueSet*)pCMe;

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
void ECOCALLMETHOD deleteCEcoASNOne1ValueSet_11B2F7AB(/* in */ IEcoASNOne1ValueSetPtr_t pIValueSet) {
    CEcoASNOne1ValueSet_11B2F7AB* pCMe = (CEcoASNOne1ValueSet_11B2F7AB*)pIValueSet;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIValueSet != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
