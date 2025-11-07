/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS5_1CF80E6C
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoPKCS5_1CF80E6C
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
#include "CEcoPKCS5.h"
#include "CEcoPKCS5PBEParameter.h"
#include "CEcoPKCS5PBKDF2.h"
#include "CEcoPKCS5RC2CBCParameter.h"
#include "CEcoPKCS5RC5CBCParameter.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoPKCS5
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoPKCS5_1CF80E6C_QueryInterface(/* in */ IEcoPKCS5Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS5_1CF80E6C* pCMe = (CEcoPKCS5_1CF80E6C*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoPKCS5) ) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5;
        pCMe->m_pVTblIEcoPKCS5->AddRef((IEcoPKCS5*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoPKCS5;
        pCMe->m_pVTblIEcoPKCS5->AddRef((IEcoPKCS5*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoPKCS5
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoPKCS5_1CF80E6C_AddRef(/* in */ IEcoPKCS5Ptr_t me) {
    CEcoPKCS5_1CF80E6C* pCMe = (CEcoPKCS5_1CF80E6C*)me;

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
 *   Функция Release для интерфейса IEcoPKCS5
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoPKCS5_1CF80E6C_Release(/* in */ IEcoPKCS5Ptr_t me) {
    CEcoPKCS5_1CF80E6C* pCMe = (CEcoPKCS5_1CF80E6C*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoPKCS5_1CF80E6C((IEcoPKCS5*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
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
int16_t ECOCALLMETHOD initCEcoPKCS5_1CF80E6C(/*in*/ IEcoPKCS5Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoPKCS5_1CF80E6C* pCMe = (CEcoPKCS5_1CF80E6C*)me;
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

/*
 *
 * <сводка>
 *   Функция CEcoPKCS5_1CF80E6C_new_PBEParameter
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS5_1CF80E6C_new_PBEParameter(/* in */ IEcoPKCS5Ptr_t me, /* out */ IEcoPKCS5PBEParameter* ppIPKCS5PBEParameter) {
    CEcoPKCS5_1CF80E6C* pCMe = (CEcoPKCS5_1CF80E6C*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS5PBEParameter((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS5PBEParameter);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS5_1CF80E6C_new_RSAPublicKey
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS5_1CF80E6C_new_PBKDF2(/* in */ IEcoPKCS5Ptr_t me, /* out */ IEcoPKCS5PBKDF2* ppIPKCS5PBKDF2) {
    CEcoPKCS5_1CF80E6C* pCMe = (CEcoPKCS5_1CF80E6C*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS5PBKDF2((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS5PBKDF2);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS5_1CF80E6C_new_RSAPublicKey
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS5_1CF80E6C_new_RC2CBCParameter(/* in */ IEcoPKCS5Ptr_t me, /* out */ IEcoPKCS5RC2CBCParameter* ppIPKCS5RC2CBCParameter) {
    CEcoPKCS5_1CF80E6C* pCMe = (CEcoPKCS5_1CF80E6C*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS5RC2CBCParameter((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS5RC2CBCParameter);


    return result;
}

/*
 *
 * <сводка>
 *   Функция CEcoPKCS5_1CF80E6C_new_RSAPublicKey
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoPKCS5_1CF80E6C_new_RC5CBCParameter(/* in */ IEcoPKCS5Ptr_t me, /* out */ IEcoPKCS5RC5CBCParameter* ppIPKCS5RC5CBCParameter) {
    CEcoPKCS5_1CF80E6C* pCMe = (CEcoPKCS5_1CF80E6C*)me;
    int16_t result;

    /* Проверка указателей */
    if (me == 0) {
        return ERR_ECO_POINTER;
    }

    result = createCEcoPKCS5RC5CBCParameter((IEcoUnknownPtr_t)pCMe->m_pISys, 0, pCMe->m_pIASNOne, ppIPKCS5RC5CBCParameter);


    return result;
}

/* Create Virtual Table IEcoPKCS5 */
IEcoPKCS5VTbl g_xB7200A1CE4B1463DAAC6A4C5B4CDCDBCVTbl_1CF80E6C = {
    CEcoPKCS5_1CF80E6C_QueryInterface,
    CEcoPKCS5_1CF80E6C_AddRef,
    CEcoPKCS5_1CF80E6C_Release,
    CEcoPKCS5_1CF80E6C_new_RC5CBCParameter,
    CEcoPKCS5_1CF80E6C_new_RC2CBCParameter,
    CEcoPKCS5_1CF80E6C_new_PBKDF2,
    CEcoPKCS5_1CF80E6C_new_PBEParameter
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
int16_t ECOCALLMETHOD createCEcoPKCS5_1CF80E6C(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS5Ptr_t* ppIEcoPKCS5) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoPKCS5_1CF80E6C* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoPKCS5 == 0 || pIUnkSystem == 0) {
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
    pCMe = (CEcoPKCS5_1CF80E6C*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoPKCS5_1CF80E6C));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoPKCS5 */
    pCMe->m_pVTblIEcoPKCS5 = &g_xB7200A1CE4B1463DAAC6A4C5B4CDCDBCVTbl_1CF80E6C;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoPKCS5 = (IEcoPKCS5*)pCMe;

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
void ECOCALLMETHOD deleteCEcoPKCS5_1CF80E6C(/* in */ IEcoPKCS5Ptr_t pIEcoPKCS5) {
    CEcoPKCS5_1CF80E6C* pCMe = (CEcoPKCS5_1CF80E6C*)pIEcoPKCS5;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoPKCS5 != 0 ) {
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
