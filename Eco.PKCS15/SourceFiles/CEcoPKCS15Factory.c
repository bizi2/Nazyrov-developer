/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS15Factory
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

#include "CEcoPKCS15.h"
#include "CEcoPKCS15Factory.h"

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
int16_t ECOCALLMETHOD CEcoPKCS15_4AEAEFDBFactory_QueryInterface(IEcoComponentFactory* me, const UGUID* riid, void** ppv) {
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
uint32_t ECOCALLMETHOD CEcoPKCS15_4AEAEFDBFactory_AddRef(/* in */ IEcoComponentFactory* me) {
    CEcoPKCS15_4AEAEFDBFactory* pCMe = (CEcoPKCS15_4AEAEFDBFactory*)me;

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
uint32_t ECOCALLMETHOD CEcoPKCS15_4AEAEFDBFactory_Release(/* in */ IEcoComponentFactory* me) {
    CEcoPKCS15_4AEAEFDBFactory* pCMe = (CEcoPKCS15_4AEAEFDBFactory*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        //deleteCEcoPKCS15_4AEAEFDBFactory(&pCMe->m_VtblICF);
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
int16_t ECOCALLMETHOD CEcoPKCS15_4AEAEFDBFactory_Init(/* in */ struct IEcoComponentFactory* me, /* in */ struct IEcoUnknown *pIUnkSystem, /* in */ void* pv) {
    CEcoPKCS15_4AEAEFDBFactory* pCMe = (CEcoPKCS15_4AEAEFDBFactory*)me;
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
int16_t ECOCALLMETHOD CEcoPKCS15_4AEAEFDBFactory_Alloc(/* in */ struct IEcoComponentFactory* me, /* in */ struct IEcoUnknown *pISystem, /* in */ struct IEcoUnknown *pIUnknownOuter, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS15_4AEAEFDBFactory* pCMe = (CEcoPKCS15_4AEAEFDBFactory*)me;
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
char_t* ECOCALLMETHOD CEcoPKCS15_4AEAEFDBFactory_get_Name(/* in */ struct IEcoComponentFactory* me) {
    CEcoPKCS15_4AEAEFDBFactory* pCMe = (CEcoPKCS15_4AEAEFDBFactory*)me;

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
char_t* ECOCALLMETHOD CEcoPKCS15_4AEAEFDBFactory_get_Version(/* in */ struct IEcoComponentFactory* me) {
    CEcoPKCS15_4AEAEFDBFactory* pCMe = (CEcoPKCS15_4AEAEFDBFactory*)me;

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
char_t* ECOCALLMETHOD CEcoPKCS15_4AEAEFDBFactory_get_Manufacturer(/* in */ struct IEcoComponentFactory* me) {
    CEcoPKCS15_4AEAEFDBFactory* pCMe = (CEcoPKCS15_4AEAEFDBFactory*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Manufacturer;
}

/* Create Virtual Table */
IEcoComponentFactoryVTbl g_x8C42FB15E1034E7B871573464AEAEFDBFactoryVTbl = {
    CEcoPKCS15_4AEAEFDBFactory_QueryInterface,
    CEcoPKCS15_4AEAEFDBFactory_AddRef,
    CEcoPKCS15_4AEAEFDBFactory_Release,
    CEcoPKCS15_4AEAEFDBFactory_Alloc,
    CEcoPKCS15_4AEAEFDBFactory_Init,
    CEcoPKCS15_4AEAEFDBFactory_get_Name,
    CEcoPKCS15_4AEAEFDBFactory_get_Version,
    CEcoPKCS15_4AEAEFDBFactory_get_Manufacturer
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
CEcoPKCS15_4AEAEFDBFactory g_x8C42FB15E1034E7B871573464AEAEFDBFactory = {
    &g_x8C42FB15E1034E7B871573464AEAEFDBFactoryVTbl,
    0,
    (CreateInstance)createCEcoPKCS15_4AEAEFDB,
    (InitInstance)initCEcoPKCS15_4AEAEFDB,
    "EcoPKCS15\0",
    "1.0.0.0\0",
    "CompanyName\0"
};

#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr() {
    return (IEcoComponentFactory*)&g_x8C42FB15E1034E7B871573464AEAEFDBFactory;
};
#elif ECO_LIB
IEcoComponentFactory* GetIEcoComponentFactoryPtr_8C42FB15E1034E7B871573464AEAEFDB = (IEcoComponentFactory*)&g_x8C42FB15E1034E7B871573464AEAEFDBFactory;
#endif