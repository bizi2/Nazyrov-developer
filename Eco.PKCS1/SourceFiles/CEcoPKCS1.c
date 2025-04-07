/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS1_A50FB39D
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoPKCS1_A50FB39D
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
#include "CEcoPKCS1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoPKCS1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoPKCS1_A50FB39D_QueryInterface(/* in */ IEcoPKCS1Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS1_A50FB39D* pCMe = (CEcoPKCS1_A50FB39D*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoPKCS1) ) {
        *ppv = &pCMe->m_pVTblIEcoPKCS1;
        pCMe->m_pVTblIEcoPKCS1->AddRef((IEcoPKCS1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoPKCS1;
        pCMe->m_pVTblIEcoPKCS1->AddRef((IEcoPKCS1*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoPKCS1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoPKCS1_A50FB39D_AddRef(/* in */ IEcoPKCS1Ptr_t me) {
    CEcoPKCS1_A50FB39D* pCMe = (CEcoPKCS1_A50FB39D*)me;

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
 *   Функция Release для интерфейса IEcoPKCS1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoPKCS1_A50FB39D_Release(/* in */ IEcoPKCS1Ptr_t me) {
    CEcoPKCS1_A50FB39D* pCMe = (CEcoPKCS1_A50FB39D*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoPKCS1_A50FB39D((IEcoPKCS1*)pCMe);
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
int16_t ECOCALLMETHOD CEcoPKCS1_A50FB39D_Encode(/* in */ IEcoPKCS1Ptr_t me, /* in */ char_t* Name, /* out */ char_t** copyName) {
    CEcoPKCS1_A50FB39D* pCMe = (CEcoPKCS1_A50FB39D*)me;
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
int16_t ECOCALLMETHOD initCEcoPKCS1_A50FB39D(/*in*/ IEcoPKCS1Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoPKCS1_A50FB39D* pCMe = (CEcoPKCS1_A50FB39D*)me;
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

/* Create Virtual Table IEcoPKCS1 */
IEcoPKCS1VTbl g_x0873B45E04504CCFA2C92CDEAD2A7855VTbl_A50FB39D = {
    CEcoPKCS1_A50FB39D_QueryInterface,
    CEcoPKCS1_A50FB39D_AddRef,
    CEcoPKCS1_A50FB39D_Release,
    CEcoPKCS1_A50FB39D_MyFunction
};

IEcoPKCS1EncoderVTbl g_x0873B45E04504CCFA2C92CDEAD2A7851VTbl_A50FB39D = {
    CEcoPKCS1_A50FB39D_QueryInterface,
    CEcoPKCS1_A50FB39D_AddRef,
    CEcoPKCS1_A50FB39D_Release,
    CEcoPKCS1_A50FB39D_Encode,
    CEcoPKCS1_A50FB39D_Decode
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
int16_t ECOCALLMETHOD createCEcoPKCS1_A50FB39D(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS1Ptr_t* ppIEcoPKCS1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoPKCS1_A50FB39D* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoPKCS1 == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoPKCS1_A50FB39D*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoPKCS1_A50FB39D));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoPKCS1 */
    pCMe->m_pVTblIEcoPKCS1 = &g_x0873B45E04504CCFA2C92CDEAD2A7855VTbl_A50FB39D;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoPKCS1 = (IEcoPKCS1*)pCMe;

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
void ECOCALLMETHOD deleteCEcoPKCS1_A50FB39D(/* in */ IEcoPKCS1Ptr_t pIEcoPKCS1) {
    CEcoPKCS1_A50FB39D* pCMe = (CEcoPKCS1_A50FB39D*)pIEcoPKCS1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoPKCS1 != 0 ) {
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
