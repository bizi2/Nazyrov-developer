/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoASNOne1Factory
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

#include "CEcoASNOne1.h"
#include "CEcoASNOne1Factory.h"

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
int16_t ECOCALLMETHOD CEcoASNOne1_11B2F7ABFactory_QueryInterface(IEcoComponentFactory* me, const UGUID* riid, void** ppv) {
    if ( IsEqualUGUID(riid, &IID_IEcoUnknown) || IsEqualUGUID(riid, &IID_IEcoComponentFactory) ) {
        *ppv = me;
    }
    else {
        *ppv = 0;
        return -1;
    }
    ((IEcoUnknown*)(*ppv))->pVTbl->AddRef((IEcoUnknown*)*ppv);

    return 0;
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
uint32_t ECOCALLMETHOD CEcoASNOne1_11B2F7ABFactory_AddRef(/* in */ IEcoComponentFactory* me) {
    CEcoASNOne1_11B2F7ABFactory* pCMe = (CEcoASNOne1_11B2F7ABFactory*)me;

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
 *   Функция уменьшает количество ссылок на интерфейс
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoASNOne1_11B2F7ABFactory_Release(/* in */ IEcoComponentFactory* me) {
    CEcoASNOne1_11B2F7ABFactory* pCMe = (CEcoASNOne1_11B2F7ABFactory*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        //deleteCEcoASNOne1_11B2F7ABFactory(&pCMe->m_VtblICF);
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
int16_t ECOCALLMETHOD CEcoASNOne1_11B2F7ABFactory_Init(/* in */ struct IEcoComponentFactory* me, /* in */ struct IEcoUnknown *pIUnkSystem, /* in */ void* pv) {
    CEcoASNOne1_11B2F7ABFactory* pCMe = (CEcoASNOne1_11B2F7ABFactory*)me;
    int16_t result = -1;

    if (me == 0 ) {
        return -1;
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
int16_t ECOCALLMETHOD CEcoASNOne1_11B2F7ABFactory_Alloc(/* in */ struct IEcoComponentFactory* me, /* in */ struct IEcoUnknown *pISystem, /* in */ struct IEcoUnknown *pIUnknownOuter, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoASNOne1_11B2F7ABFactory* pCMe = (CEcoASNOne1_11B2F7ABFactory*)me;
    IEcoUnknown* pIUnk = 0;
    int16_t result = -1;

    if (me == 0 ) {
        return -1;
    }

    /* Агрегирование при условии если IID это IID_IEcoUnknown */
    if ( ( pIUnknownOuter != 0 ) && !IsEqualUGUID(riid, &IID_IEcoUnknown ) ) {
        /* не поддерживает агрегирование */
        return -1;
    }

    /* Создание компонента */
    result = pCMe->m_pInstance(pISystem, pIUnknownOuter, (void**)&pIUnk);
    if ( result != 0 || pIUnk == 0) {
        return -1;
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
char_t* ECOCALLMETHOD CEcoASNOne1_11B2F7ABFactory_get_Name(/* in */ struct IEcoComponentFactory* me) {
    CEcoASNOne1_11B2F7ABFactory* pCMe = (CEcoASNOne1_11B2F7ABFactory*)me;

    if (me == 0 ) {
        return 0;
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
char_t* ECOCALLMETHOD CEcoASNOne1_11B2F7ABFactory_get_Version(/* in */ struct IEcoComponentFactory* me) {
    CEcoASNOne1_11B2F7ABFactory* pCMe = (CEcoASNOne1_11B2F7ABFactory*)me;

    if (me == 0 ) {
        return 0;
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
char_t* ECOCALLMETHOD CEcoASNOne1_11B2F7ABFactory_get_Manufacturer(/* in */ struct IEcoComponentFactory* me) {
    CEcoASNOne1_11B2F7ABFactory* pCMe = (CEcoASNOne1_11B2F7ABFactory*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Manufacturer;
}

/* Create Virtual Table */
IEcoComponentFactoryVTbl g_xE0EA41D156824A40877EB6A011B2F7ABFactoryVTbl = {
    CEcoASNOne1_11B2F7ABFactory_QueryInterface,
    CEcoASNOne1_11B2F7ABFactory_AddRef,
    CEcoASNOne1_11B2F7ABFactory_Release,
    CEcoASNOne1_11B2F7ABFactory_Alloc,
    CEcoASNOne1_11B2F7ABFactory_Init,
    CEcoASNOne1_11B2F7ABFactory_get_Name,
    CEcoASNOne1_11B2F7ABFactory_get_Version,
    CEcoASNOne1_11B2F7ABFactory_get_Manufacturer
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
CEcoASNOne1_11B2F7ABFactory g_xE0EA41D156824A40877EB6A011B2F7ABFactory = {
    &g_xE0EA41D156824A40877EB6A011B2F7ABFactoryVTbl,
    0,
    (CreateInstance)createCEcoASNOne1_11B2F7AB,
    (InitInstance)initCEcoASNOne1_11B2F7AB,
    "EcoASNOne1\0",
    "1.0.0.0\0",
    "CompanyName\0"
};

#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr() {
    return (IEcoComponentFactory*)&g_xE0EA41D156824A40877EB6A011B2F7ABFactory;
};
#elif ECO_LIB
IEcoComponentFactory* GetIEcoComponentFactoryPtr_E0EA41D156824A40877EB6A011B2F7AB = (IEcoComponentFactory*)&g_xE0EA41D156824A40877EB6A011B2F7ABFactory;
#endif