/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoEventPoll1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoEventPoll1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "CEcoEventPoll1.h"

/* Подключение заголовочных файлов для Эко ОС */
#ifdef ECO_OS

/* Подключение заголовочных файлов для ОС Windows */
#elif ECO_WINDOWS
#include "Windows.h"
#ifdef ECO_WINDOWS
#elif ECO_WIN64
#endif

/* Подключение заголовочных файлов для ОС Linux */
#elif ECO_LINUX
#include <sys/epoll.h>

/* Подключение заголовочных файлов для ОС Mac OS X, iOS, tvOS */
#elif ECO_APPLE

/* Подключение заголовочных файлов для ОС Android */
#elif ECO_ANDROID
#endif

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoEventPoll1
 * </описание>
 *
 */
int16_t CEcoEventPoll1_QueryInterface(/* in */ struct IEcoEventPoll1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return result;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoEventPoll1) ) {
        *ppv = &pCMe->m_pVTblIEcoEventPoll1;
        pCMe->m_pVTblIEcoEventPoll1->AddRef((IEcoEventPoll1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoEventPoll1;
        pCMe->m_pVTblIEcoEventPoll1->AddRef((IEcoEventPoll1*)pCMe);
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
 *   Функция AddRef для интерфейса IEcoEventPoll1
 * </описание>
 *
 */
uint32_t CEcoEventPoll1_AddRef(/* in */ struct IEcoEventPoll1* me) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;

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
 *   Функция Release для интерфейса IEcoEventPoll1
 * </описание>
 *
 */
uint32_t CEcoEventPoll1_Release(/* in */ struct IEcoEventPoll1* me) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoEventPoll1((IEcoEventPoll1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Add
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CEcoEventPoll1_Add(/* in */ struct IEcoEventPoll1* me, /* in */ descriptor_t fd) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;
#ifdef ECO_OS
#elif ECO_WINDOWS
    HANDLE hIO = 0;
#elif ECO_LINUX
    int ret = 0;
    struct epoll_event epoll_event = {0};
#elif ECO_APPLE
#elif ECO_ANDROID
#endif

    /* Проверка указателей */
    if (me == 0) {
        return -1;
    }
#ifdef ECO_OS
#elif ECO_WINDOWS
    if ((hIO = CreateIoCompletionPort(fd, NULL, 1, NULL)) == INVALID_HANDLE_VALUE) {
        return -1;
    }
#elif ECO_LINUX
    if ((ret = epoll_ctl(pCMe->m_fd, EPOLL_CTL_ADD, *(int*)&fd, &epoll_event)) < 0) {
        return -1;
    }
#elif ECO_APPLE
#elif ECO_ANDROID
#endif

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Mod
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CEcoEventPoll1_Mod(/* in */ struct IEcoEventPoll1* me, /* in */ descriptor_t fd) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;
#ifdef ECO_OS
#elif ECO_WINDOWS
#elif ECO_LINUX
    int ret = 0;
    struct epoll_event epoll_event = {0};
#elif ECO_APPLE
#elif ECO_ANDROID
#endif

    /* Проверка указателей */
    if (me == 0) {
        return -1;
    }
#ifdef ECO_OS
#elif ECO_WINDOWS
#elif ECO_LINUX
    if ((ret = epoll_ctl(pCMe->m_fd, EPOLL_CTL_MOD, *(int*)&fd, &epoll_event)) < 0) {
        return -1;
    }
#elif ECO_APPLE
#elif ECO_ANDROID
#endif

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Del
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CEcoEventPoll1_Del(/* in */ struct IEcoEventPoll1* me, /* in */ descriptor_t fd) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;
#ifdef ECO_OS
#elif ECO_WINDOWS
#elif ECO_LINUX
    int ret = 0;
#elif ECO_APPLE
#elif ECO_ANDROID
#endif

    /* Проверка указателей */
    if (me == 0) {
        return -1;
    }
#ifdef ECO_OS
#elif ECO_WINDOWS
#elif ECO_LINUX
    if ((ret = epoll_ctl(pCMe->m_fd, EPOLL_CTL_DEL, *(int*)&fd, 0)) < 0) {
        return -1;
    }
#elif ECO_APPLE
#elif ECO_ANDROID
#endif

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Wait
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int32_t CEcoEventPoll1_Wait(/* in */ struct IEcoEventPoll1* me, /* in */ int32_t maxevents, /* in */ int32_t timeout) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;
#ifdef ECO_OS
#elif ECO_WINDOWS
#elif ECO_LINUX
    int ret = 0;
#elif ECO_APPLE
#elif ECO_ANDROID
#endif

    /* Проверка указателей */
    if (me == 0) {
        return -1;
    }
#ifdef ECO_OS
#elif ECO_WINDOWS
#elif ECO_LINUX
    if ((ret =  epoll_wait(pCMe->m_fd, epoll_events, maxevents, timeout)) < 0) {
        return -1;
    }
#elif ECO_APPLE
#elif ECO_ANDROID
#endif

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Enum
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CEcoEventPoll1_Enum(/* in */ struct IEcoEventPoll1* me, /* in */ int32_t number, /* out */ descriptor_t* fd) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;

    /* Проверка указателей */
    if (me == 0) {
        return -1;
    }

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
int16_t initCEcoEventPoll1(/*in*/ struct IEcoEventPoll1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;


    return result;
}

/* Create Virtual Table */
IEcoEventPoll1VTbl g_xCDD422700B2B470CADDAD8C752020BE4VTbl = {
    CEcoEventPoll1_QueryInterface,
    CEcoEventPoll1_AddRef,
    CEcoEventPoll1_Release,
    CEcoEventPoll1_Add,
    CEcoEventPoll1_Mod,
    CEcoEventPoll1_Del,
    CEcoEventPoll1_Wait,
    CEcoEventPoll1_Enum
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
int16_t createCEcoEventPoll1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoEventPoll1** ppIEcoEventPoll1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoEventPoll1* pCMe = 0;

    /* Проверка указателей */
    if (ppIEcoEventPoll1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoEventPoll1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoEventPoll1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoEventPoll1 */
    pCMe->m_pVTblIEcoEventPoll1 = &g_xCDD422700B2B470CADDAD8C752020BE4VTbl;

    /* Инициализация данных */
#ifdef ECO_OS
#elif ECO_WINDOWS
#elif ECO_LINUX
    pCMe->m_fd = epoll_create1(0);
    if (pCMe->m_fd < 0) {
        deleteCEcoEventPoll1((IEcoEventPoll1*)pCMe);
        return -1;
    }
#elif ECO_APPLE
#elif ECO_ANDROID
#endif

    /* Возврат указателя на интерфейс */
    *ppIEcoEventPoll1 = (IEcoEventPoll1*)pCMe;


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
void deleteCEcoEventPoll1(/* in */ IEcoEventPoll1* pIEcoEventPoll1) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)pIEcoEventPoll1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoEventPoll1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
#ifdef ECO_OS
#elif ECO_WINDOWS
#elif ECO_LINUX
        if (pCMe->m_fd != -1) {
            close(pCMe->m_fd);
        }
#elif ECO_APPLE
#elif ECO_ANDROID
#endif
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
