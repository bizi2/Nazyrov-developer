/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoMD5_5D90ACD0
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoMD5_5D90ACD0
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
#include "CEcoMD5.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoMD5
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoMD5_5D90ACD0_QueryInterface(/* in */ IEcoMD5Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoMD5_5D90ACD0* pCMe = (CEcoMD5_5D90ACD0*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoMD5) ) {
        *ppv = &pCMe->m_pVTblIEcoMD5;
        pCMe->m_pVTblIEcoMD5->AddRef((IEcoMD5*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoMD5;
        pCMe->m_pVTblIEcoMD5->AddRef((IEcoMD5*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoMD5
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoMD5_5D90ACD0_AddRef(/* in */ IEcoMD5Ptr_t me) {
    CEcoMD5_5D90ACD0* pCMe = (CEcoMD5_5D90ACD0*)me;

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
 *   Функция Release для интерфейса IEcoMD5
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoMD5_5D90ACD0_Release(/* in */ IEcoMD5Ptr_t me) {
    CEcoMD5_5D90ACD0* pCMe = (CEcoMD5_5D90ACD0*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoMD5_5D90ACD0((IEcoMD5*)pCMe);
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
int16_t ECOCALLMETHOD CEcoMD5_5D90ACD0_MyFunction(/* in */ IEcoMD5Ptr_t me, /* in */ char_t* Name, /* out */ char_t** copyName) {
    CEcoMD5_5D90ACD0* pCMe = (CEcoMD5_5D90ACD0*)me;
    int16_t index = 0;

    /* Проверка указателей */
    if (me == 0 || Name == 0 || copyName == 0) {
        return -1;
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
int16_t ECOCALLMETHOD initCEcoMD5_5D90ACD0(/*in*/ IEcoMD5Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoMD5_5D90ACD0* pCMe = (CEcoMD5_5D90ACD0*)me;
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

/* Create Virtual Table IEcoMD5 */
IEcoMD5VTbl g_x3B1DB870DD5A46A2B716848B45F6D148VTbl_5D90ACD0 = {
    CEcoMD5_5D90ACD0_QueryInterface,
    CEcoMD5_5D90ACD0_AddRef,
    CEcoMD5_5D90ACD0_Release,
    CEcoMD5_5D90ACD0_MyFunction
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
int16_t ECOCALLMETHOD createCEcoMD5_5D90ACD0(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoMD5Ptr_t* ppIEcoMD5) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoMD5_5D90ACD0* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoMD5 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

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
    pCMe = (CEcoMD5_5D90ACD0*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoMD5_5D90ACD0));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoMD5 */
    pCMe->m_pVTblIEcoMD5 = &g_x3B1DB870DD5A46A2B716848B45F6D148VTbl_5D90ACD0;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoMD5 = (IEcoMD5*)pCMe;

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
void ECOCALLMETHOD deleteCEcoMD5_5D90ACD0(/* in */ IEcoMD5Ptr_t pIEcoMD5) {
    CEcoMD5_5D90ACD0* pCMe = (CEcoMD5_5D90ACD0*)pIEcoMD5;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoMD5 != 0 ) {
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
