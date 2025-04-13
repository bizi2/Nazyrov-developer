/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSSH1CPFactory
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию фабрики для компонента
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "CEcoSSH1CP.h"
#include "CEcoSSH1CPFactory.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция возвращает указатель на интерфейс
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoSSH1CP_A203EFE6Factory_QueryInterface(IEcoComponentFactory* me, const UGUID* riid, void** ppv) {
    if ( IsEqualUGUID(riid, &IID_IEcoUnknown) || IsEqualUGUID(riid, &IID_IEcoComponentFactory) ) {
        *ppv = me;
    }
    else {
        *ppv = 0;
        return ERR_ECO_NOINTERFACE;
    }
    ((IEcoUnknown*)(*ppv))->pVTbl->AddRef((IEcoUnknown*)*ppv);

    return ERR_ECO_SUCCESES;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция увеличивает количество ссылок на интерфейс
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoSSH1CP_A203EFE6Factory_AddRef(/* in */ IEcoComponentFactory* me) {
    CEcoSSH1CP_A203EFE6Factory* pCMe = (CEcoSSH1CP_A203EFE6Factory*)me;

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
 *   Функция уменьшает количество ссылок на интерфейс
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoSSH1CP_A203EFE6Factory_Release(/* in */ IEcoComponentFactory* me) {
    CEcoSSH1CP_A203EFE6Factory* pCMe = (CEcoSSH1CP_A203EFE6Factory*)me;

    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        //deleteCEcoSSH1CP_A203EFE6Factory(&pCMe->m_VtblICF);
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
 *   Функция инициализирует компонент с параметрами
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoSSH1CP_A203EFE6Factory_Init(/* in */ struct IEcoComponentFactory* me, /* in */ struct IEcoUnknown *pIUnkSystem, /* in */ void* pv) {
    CEcoSSH1CP_A203EFE6Factory* pCMe = (CEcoSSH1CP_A203EFE6Factory*)me;
    int16_t result = ERR_ECO_POINTER;

    if (me == 0 ) {
        return result;
    }

    /* Инициализация компонента */
    result = pCMe->m_pInitInstance(pv, pIUnkSystem);

    return result;
}

/*
 *
 * <сводка>
 *   Функция Alloc
 * </сводка>
 *
 * <описание>
 *   Функция создает компонент
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoSSH1CP_A203EFE6Factory_Alloc(/* in */ struct IEcoComponentFactory* me, /* in */ struct IEcoUnknown *pISystem, /* in */ struct IEcoUnknown *pIUnknownOuter, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoSSH1CP_A203EFE6Factory* pCMe = (CEcoSSH1CP_A203EFE6Factory*)me;
    IEcoUnknown* pIUnk = 0;
    int16_t result = ERR_ECO_POINTER;

    if (me == 0 ) {
        return result;
    }

    /* Агрегирование при условии если IID это IID_IEcoUnknown */
    if ( ( pIUnknownOuter != 0 ) && !IsEqualUGUID(riid, &IID_IEcoUnknown ) ) {
        /* не поддерживает агрегирование */
        return ERR_ECO_NOAGGREGATION;
    }

    /* Создание компонента */
    result = pCMe->m_pInstance(pISystem, pIUnknownOuter, (void**)&pIUnk);
    if ( result != 0 || pIUnk == 0) {
        return result;
    }

    /* Инициализация компонента */
    result = me->pVTbl->Init(me, pISystem, pIUnk);
	
    /* Получение указателя на интерфейс */
    result = pIUnk->pVTbl->QueryInterface(pIUnk, riid, ppv);

    /* Уменьшение ссылки запрошенной Фабрикой компонентов */
    pIUnk->pVTbl->Release(pIUnk);

    return result;
}

/*
 *
 * <сводка>
 *   Функция get_Name
 * </сводка>
 *
 * <описание>
 *   Функция возвращает наименование компонента
 * </описание>
 *
 */
static char_t* ECOCALLMETHOD CEcoSSH1CP_A203EFE6Factory_get_Name(/* in */ struct IEcoComponentFactory* me) {
    CEcoSSH1CP_A203EFE6Factory* pCMe = (CEcoSSH1CP_A203EFE6Factory*)me;

    if (me == 0 ) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_Name;
}

/*
 *
 * <сводка>
 *   Функция get_Version
 * </сводка>
 *
 * <описание>
 *   Функция возвращает версию компонента
 * </описание>
 *
 */
static char_t* ECOCALLMETHOD CEcoSSH1CP_A203EFE6Factory_get_Version(/* in */ struct IEcoComponentFactory* me) {
    CEcoSSH1CP_A203EFE6Factory* pCMe = (CEcoSSH1CP_A203EFE6Factory*)me;

    if (me == 0 ) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_Version;
}

/*
 *
 * <сводка>
 *   Функция get_Manufacturer
 * </сводка>
 *
 * <описание>
 *   Функция возвращает наименование производителя компонента
 * </описание>
 *
 */
static char_t* ECOCALLMETHOD CEcoSSH1CP_A203EFE6Factory_get_Manufacturer(/* in */ struct IEcoComponentFactory* me) {
    CEcoSSH1CP_A203EFE6Factory* pCMe = (CEcoSSH1CP_A203EFE6Factory*)me;

    if (me == 0 ) {
        return 0; /* ERR_ECO_POINTER */
    }

    return pCMe->m_Manufacturer;
}

/* Create Virtual Table */
IEcoComponentFactoryVTbl g_xC6AFCAA416674FCE89F30674A203EFE6FactoryVTbl = {
    CEcoSSH1CP_A203EFE6Factory_QueryInterface,
    CEcoSSH1CP_A203EFE6Factory_AddRef,
    CEcoSSH1CP_A203EFE6Factory_Release,
    CEcoSSH1CP_A203EFE6Factory_Alloc,
    CEcoSSH1CP_A203EFE6Factory_Init,
    CEcoSSH1CP_A203EFE6Factory_get_Name,
    CEcoSSH1CP_A203EFE6Factory_get_Version,
    CEcoSSH1CP_A203EFE6Factory_get_Manufacturer
};

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция 
 * </описание>
 *
 */
CEcoSSH1CP_A203EFE6Factory g_xC6AFCAA416674FCE89F30674A203EFE6Factory = {
    &g_xC6AFCAA416674FCE89F30674A203EFE6FactoryVTbl,
    0,
    (CreateInstance)createCEcoSSH1CP_A203EFE6,
    (InitInstance)initCEcoSSH1CP_A203EFE6,
    "EcoSSH1CP\0",
    "1.0.0.0\0",
    "CompanyName\0"
};

#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr() {
    return (IEcoComponentFactory*)&g_xC6AFCAA416674FCE89F30674A203EFE6Factory;
};
#elif ECO_LIB
IEcoComponentFactory* GetIEcoComponentFactoryPtr_C6AFCAA416674FCE89F30674A203EFE6 = (IEcoComponentFactory*)&g_xC6AFCAA416674FCE89F30674A203EFE6Factory;
#endif