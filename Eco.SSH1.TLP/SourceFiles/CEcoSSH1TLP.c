/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSSH1TLP_AE11B435
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoSSH1TLP_AE11B435
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
#include "CEcoSSH1TLP.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoSSH1TLP
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoSSH1TLP_AE11B435_QueryInterface(/* in */ IEcoSSH1TLPPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoSSH1TLP_AE11B435* pCMe = (CEcoSSH1TLP_AE11B435*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoSSH1TLP) ) {
        *ppv = &pCMe->m_pVTblIEcoSSH1TLP;
        pCMe->m_pVTblIEcoSSH1TLP->AddRef((IEcoSSH1TLP*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoSSH1TLP;
        pCMe->m_pVTblIEcoSSH1TLP->AddRef((IEcoSSH1TLP*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoSSH1TLP
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoSSH1TLP_AE11B435_AddRef(/* in */ IEcoSSH1TLPPtr_t me) {
    CEcoSSH1TLP_AE11B435* pCMe = (CEcoSSH1TLP_AE11B435*)me;

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
 *   Функция Release для интерфейса IEcoSSH1TLP
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoSSH1TLP_AE11B435_Release(/* in */ IEcoSSH1TLPPtr_t me) {
    CEcoSSH1TLP_AE11B435* pCMe = (CEcoSSH1TLP_AE11B435*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoSSH1TLP_AE11B435((IEcoSSH1TLP*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция MyFunction
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoSSH1TLP_AE11B435_MyFunction(/* in */ IEcoSSH1TLPPtr_t me, /* in */ char_t* Name, /* out */ char_t** copyName) {
    CEcoSSH1TLP_AE11B435* pCMe = (CEcoSSH1TLP_AE11B435*)me;
    int16_t index = 0;

    /* Проверка указателей */
    if (me == 0 || Name == 0 || copyName == 0) {
        return ERR_ECO_POINTER;
    }

    /* Копирование строки */
    while(Name[index] != 0) {
        index++;
    }
    pCMe->m_Name = (char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, index + 1);
    index = 0;
    while(Name[index] != 0) {
        pCMe->m_Name[index] = Name[index];
        index++;
    }
    *copyName = pCMe->m_Name;

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
int16_t ECOCALLMETHOD initCEcoSSH1TLP_AE11B435(/*in*/ IEcoSSH1TLPPtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoSSH1TLP_AE11B435* pCMe = (CEcoSSH1TLP_AE11B435*)me;
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

/* Create Virtual Table IEcoSSH1TLP */
IEcoSSH1TLPVTbl g_x9D5A03CCCDF44BF0BE7BA3216C695842VTbl_AE11B435 = {
    CEcoSSH1TLP_AE11B435_QueryInterface,
    CEcoSSH1TLP_AE11B435_AddRef,
    CEcoSSH1TLP_AE11B435_Release,
    CEcoSSH1TLP_AE11B435_MyFunction
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
int16_t ECOCALLMETHOD createCEcoSSH1TLP_AE11B435(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoSSH1TLPPtr_t* ppIEcoSSH1TLP) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoSSH1TLP_AE11B435* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoSSH1TLP == 0 || pIUnkSystem == 0) {
        return result; /* ERR_ECO_POINTER */
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);
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
    pCMe = (CEcoSSH1TLP_AE11B435*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoSSH1TLP_AE11B435));
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

    /* Создание таблицы функций интерфейса IEcoSSH1TLP */
    pCMe->m_pVTblIEcoSSH1TLP = &g_x9D5A03CCCDF44BF0BE7BA3216C695842VTbl_AE11B435;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoSSH1TLP = (IEcoSSH1TLP*)pCMe;

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
void ECOCALLMETHOD deleteCEcoSSH1TLP_AE11B435(/* in */ IEcoSSH1TLPPtr_t pIEcoSSH1TLP) {
    CEcoSSH1TLP_AE11B435* pCMe = (CEcoSSH1TLP_AE11B435*)pIEcoSSH1TLP;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoSSH1TLP != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
