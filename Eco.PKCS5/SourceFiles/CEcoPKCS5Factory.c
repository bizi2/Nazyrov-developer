/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS5Factory
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

#include "CEcoPKCS5.h"
#include "CEcoPKCS5Factory.h"

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
int16_t ECOCALLMETHOD CEcoPKCS5_1CF80E6CFactory_QueryInterface(IEcoComponentFactory* me, const UGUID* riid, void** ppv) {
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
uint32_t ECOCALLMETHOD CEcoPKCS5_1CF80E6CFactory_AddRef(/* in */ IEcoComponentFactory* me) {
    CEcoPKCS5_1CF80E6CFactory* pCMe = (CEcoPKCS5_1CF80E6CFactory*)me;

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
uint32_t ECOCALLMETHOD CEcoPKCS5_1CF80E6CFactory_Release(/* in */ IEcoComponentFactory* me) {
    CEcoPKCS5_1CF80E6CFactory* pCMe = (CEcoPKCS5_1CF80E6CFactory*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        //deleteCEcoPKCS5_1CF80E6CFactory(&pCMe->m_VtblICF);
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
int16_t ECOCALLMETHOD CEcoPKCS5_1CF80E6CFactory_Init(/* in */ struct IEcoComponentFactory* me, /* in */ struct IEcoUnknown *pIUnkSystem, /* in */ void* pv) {
    CEcoPKCS5_1CF80E6CFactory* pCMe = (CEcoPKCS5_1CF80E6CFactory*)me;
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
int16_t ECOCALLMETHOD CEcoPKCS5_1CF80E6CFactory_Alloc(/* in */ struct IEcoComponentFactory* me, /* in */ struct IEcoUnknown *pISystem, /* in */ struct IEcoUnknown *pIUnknownOuter, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoPKCS5_1CF80E6CFactory* pCMe = (CEcoPKCS5_1CF80E6CFactory*)me;
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
char_t* ECOCALLMETHOD CEcoPKCS5_1CF80E6CFactory_get_Name(/* in */ struct IEcoComponentFactory* me) {
    CEcoPKCS5_1CF80E6CFactory* pCMe = (CEcoPKCS5_1CF80E6CFactory*)me;

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
char_t* ECOCALLMETHOD CEcoPKCS5_1CF80E6CFactory_get_Version(/* in */ struct IEcoComponentFactory* me) {
    CEcoPKCS5_1CF80E6CFactory* pCMe = (CEcoPKCS5_1CF80E6CFactory*)me;

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
char_t* ECOCALLMETHOD CEcoPKCS5_1CF80E6CFactory_get_Manufacturer(/* in */ struct IEcoComponentFactory* me) {
    CEcoPKCS5_1CF80E6CFactory* pCMe = (CEcoPKCS5_1CF80E6CFactory*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Manufacturer;
}

/* Create Virtual Table */
IEcoComponentFactoryVTbl g_xD5D671F9277042689D64A8F71CF80E6CFactoryVTbl = {
    CEcoPKCS5_1CF80E6CFactory_QueryInterface,
    CEcoPKCS5_1CF80E6CFactory_AddRef,
    CEcoPKCS5_1CF80E6CFactory_Release,
    CEcoPKCS5_1CF80E6CFactory_Alloc,
    CEcoPKCS5_1CF80E6CFactory_Init,
    CEcoPKCS5_1CF80E6CFactory_get_Name,
    CEcoPKCS5_1CF80E6CFactory_get_Version,
    CEcoPKCS5_1CF80E6CFactory_get_Manufacturer
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
CEcoPKCS5_1CF80E6CFactory g_xD5D671F9277042689D64A8F71CF80E6CFactory = {
    &g_xD5D671F9277042689D64A8F71CF80E6CFactoryVTbl,
    0,
    (CreateInstance)createCEcoPKCS5_1CF80E6C,
    (InitInstance)initCEcoPKCS5_1CF80E6C,
    "EcoPKCS5\0",
    "1.0.0.0\0",
    "CompanyName\0"
};

#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr() {
    return (IEcoComponentFactory*)&g_xD5D671F9277042689D64A8F71CF80E6CFactory;
};
#elif ECO_LIB
IEcoComponentFactory* GetIEcoComponentFactoryPtr_D5D671F9277042689D64A8F71CF80E6C = (IEcoComponentFactory*)&g_xD5D671F9277042689D64A8F71CF80E6CFactory;
#endif