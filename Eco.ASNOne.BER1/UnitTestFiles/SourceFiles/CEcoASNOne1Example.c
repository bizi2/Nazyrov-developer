/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1Example_247D52F9
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoASNOne1Example_247D52F9
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
#include "CEcoASNOne1Example.h"
#include "CEcoASNOne1ExName.h"
#include "CEcoASNOne1ExEmployeeNumber.h"
#include "CEcoASNOne1ExDate.h"
#include "CEcoASNOne1ExPersonnelRecord.h"
#include "CEcoASNOne1ExChildInformation.h"
#include "ErrEcoASNOne1Example.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoASNOne1Example
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1Example_247D52F9_QueryInterface(/* in */ IEcoASNOne1ExamplePtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoASNOne1Example_247D52F9* pCMe = (CEcoASNOne1Example_247D52F9*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoASNOne1Example) ) {
        *ppv = &pCMe->m_pVTblIExample;
        pCMe->m_pVTblIExample->AddRef((IEcoASNOne1Example*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIExample;
        pCMe->m_pVTblIExample->AddRef((IEcoASNOne1Example*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoASNOne1Example
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1Example_247D52F9_AddRef(/* in */ IEcoASNOne1ExamplePtr_t me) {
    CEcoASNOne1Example_247D52F9* pCMe = (CEcoASNOne1Example_247D52F9*)me;

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
 *   Функция Release для интерфейса IEcoASNOne1Example
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoASNOne1Example_247D52F9_Release(/* in */ IEcoASNOne1ExamplePtr_t me) {
    CEcoASNOne1Example_247D52F9* pCMe = (CEcoASNOne1Example_247D52F9*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoASNOne1Example_247D52F9((IEcoASNOne1Example*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция new_PersonnelRecord
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1Example_247D52F9_new_PersonnelRecord(/* in */ IEcoASNOne1ExamplePtr_t me, /* out */ IEcoASNOne1ExPersonnelRecord** ppIPersonnelRecord) {
    CEcoASNOne1Example_247D52F9* pCMe = (CEcoASNOne1Example_247D52F9*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoASNOne1ExPersonnelRecord_247D52F9((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPersonnelRecord);


    return result;
}

/*
 *
 * <сводка>
 *   Функция new_ChildInformation
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoASNOne1Example_247D52F9_new_ChildInformation(/* in */ IEcoASNOne1ExamplePtr_t me, /* out */ IEcoASNOne1ExChildInformation** ppIChildInformation) {
    CEcoASNOne1Example_247D52F9* pCMe = (CEcoASNOne1Example_247D52F9*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoASNOne1ExChildInformation_247D52F9((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIChildInformation);


    return result;
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
int16_t ECOCALLMETHOD initCEcoASNOne1Example_247D52F9(/*in*/ IEcoASNOne1ExamplePtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoASNOne1Example_247D52F9* pCMe = (CEcoASNOne1Example_247D52F9*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = ERR_ECO_POINTER;

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

/* Create Virtual Table IEcoASNOne1Example */
IEcoASNOne1ExampleVTbl g_xC4996BED1E104842BE055D0270A58595VTbl_247D52F9 = {
    CEcoASNOne1Example_247D52F9_QueryInterface,
    CEcoASNOne1Example_247D52F9_AddRef,
    CEcoASNOne1Example_247D52F9_Release,
    CEcoASNOne1Example_247D52F9_new_PersonnelRecord,
    CEcoASNOne1Example_247D52F9_new_ChildInformation

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
int16_t ECOCALLMETHOD createCEcoASNOne1Example_247D52F9(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoASNOne1ExamplePtr_t* ppIExample) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoASNOne1Example_247D52F9* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppIExample == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoASNOne1Example_247D52F9*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoASNOne1Example_247D52F9));
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

    /* Создание таблицы функций интерфейса IEcoASNOne1Example */
    pCMe->m_pVTblIExample = &g_xC4996BED1E104842BE055D0270A58595VTbl_247D52F9;

    /* Получение интерфейса по работе с нотацией ASN.1 */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoASNOne1, 0, &IID_IEcoASNOne1, (void**) &pCMe->m_pIASNOne);
    /* Проверка */
    if (result != 0 || pCMe->m_pIASNOne == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ASNONE1EXAMPLE_REQ_COMP_ASN1;
    }

    /* Инициализация данных */

    /* Возврат указателя на интерфейс */
    *ppIExample = (IEcoASNOne1Example*)pCMe;

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
void ECOCALLMETHOD deleteCEcoASNOne1Example_247D52F9(/* in */ IEcoASNOne1ExamplePtr_t pIExample) {
    CEcoASNOne1Example_247D52F9* pCMe = (CEcoASNOne1Example_247D52F9*)pIExample;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIExample != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
