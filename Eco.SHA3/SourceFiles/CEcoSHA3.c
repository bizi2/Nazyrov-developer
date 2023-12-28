/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSHA3_6EFC7840
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoSHA3_6EFC7840
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
#include "CEcoSHA3.h"
#include "SHA3Func.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoSHA3
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoSHA3_6EFC7840_QueryInterface(/* in */ IEcoSHA3Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoSHA3_6EFC7840* pCMe = (CEcoSHA3_6EFC7840*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoSHA3) ) {
        *ppv = &pCMe->m_pVTblIEcoSHA3;
        pCMe->m_pVTblIEcoSHA3->AddRef((IEcoSHA3*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoSHA3;
        pCMe->m_pVTblIEcoSHA3->AddRef((IEcoSHA3*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoSHA3
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoSHA3_6EFC7840_AddRef(/* in */ IEcoSHA3Ptr_t me) {
    CEcoSHA3_6EFC7840* pCMe = (CEcoSHA3_6EFC7840*)me;

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
 *   Функция Release для интерфейса IEcoSHA3
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoSHA3_6EFC7840_Release(/* in */ IEcoSHA3Ptr_t me) {
    CEcoSHA3_6EFC7840* pCMe = (CEcoSHA3_6EFC7840*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoSHA3_6EFC7840((IEcoSHA3*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

void ECOCALLMETHOD fnEncryptSHA3(IEcoSHA3Ptr_t me, uint8_t* message, uint8_t* output) {
    CEcoSHA3_6EFC7840* pCMe = (CEcoSHA3_6EFC7840*)me;
    KeccakState l_state;

    fnKeccakInitialize(&l_state);
    fnKeccakAbsorb(&l_state, message, strlen((const char*)message));
    fnKeccakSqueeze(&l_state, output, sizeof(output));

    return output;
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
int16_t ECOCALLMETHOD initCEcoSHA3_6EFC7840(/*in*/ IEcoSHA3Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoSHA3_6EFC7840* pCMe = (CEcoSHA3_6EFC7840*)me;
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

/* Create Virtual Table IEcoSHA3 */
IEcoSHA3VTbl g_x2EBABB98EA1849C287820C3DE6226359VTbl_6EFC7840 = {
    CEcoSHA3_6EFC7840_QueryInterface,
    CEcoSHA3_6EFC7840_AddRef,
    CEcoSHA3_6EFC7840_Release,
    fnEncryptSHA3
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
int16_t ECOCALLMETHOD createCEcoSHA3_6EFC7840(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoSHA3Ptr_t* ppIEcoSHA3) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoSHA3_6EFC7840* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoSHA3 == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoSHA3_6EFC7840*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoSHA3_6EFC7840));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoSHA3 */
    pCMe->m_pVTblIEcoSHA3 = &g_x2EBABB98EA1849C287820C3DE6226359VTbl_6EFC7840;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoSHA3 = (IEcoSHA3*)pCMe;

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
void ECOCALLMETHOD deleteCEcoSHA3_6EFC7840(/* in */ IEcoSHA3Ptr_t pIEcoSHA3) {
    CEcoSHA3_6EFC7840* pCMe = (CEcoSHA3_6EFC7840*)pIEcoSHA3;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoSHA3 != 0 ) {
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