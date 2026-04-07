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

#ifdef ECO_OS

#elif ECO_WINDOWS
#include <WinSock2.h>
#include <MSWSock.h>
#include <Windows.h>

#elif ECO_LINUX
#include <sys/epoll.h>

#elif ECO_APPLE

#elif ECO_ANDROID
#endif

static int16_t CEcoEventPoll1_QueryInterface(/* in */ struct IEcoEventPoll1* me, /* in */ const UGUID* riid, /* out */ void** ppv);
static uint32_t CEcoEventPoll1_AddRef(/* in */ struct IEcoEventPoll1* me);
static uint32_t CEcoEventPoll1_Release(/* in */ struct IEcoEventPoll1* me);
static int16_t CEcoEventPoll1_Add(/* in */ struct IEcoEventPoll1* me, /* in */ descriptor_t fd);
static int16_t CEcoEventPoll1_Mod(/* in */ struct IEcoEventPoll1* me, /* in */ descriptor_t fd);
static int16_t CEcoEventPoll1_Del(/* in */ struct IEcoEventPoll1* me, /* in */ descriptor_t fd);
static int32_t CEcoEventPoll1_Wait(/* in */ struct IEcoEventPoll1* me, /* in */ int32_t maxevents, /* in */ int32_t timeout);
static int16_t CEcoEventPoll1_Enum(/* in */ struct IEcoEventPoll1* me, /* in */ int32_t number, /* out */ descriptor_t fd);

#ifdef ECO_WINDOWS
typedef struct CEcoEventPoll1SocketContext {
    OVERLAPPED m_overlapped;
    int m_socket;
    uint8_t m_pending;
    uint8_t m_deleted;
    uint8_t m_ready;
    uint8_t m_reserved;
} CEcoEventPoll1SocketContext;

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_ReadSocket
 * </сводка>
 *
 * <описание>
 *   Функция извлекает сокет Windows из универсального дескриптора descriptor_t
 * </описание>
 *
 * <параметры>
 *   fd - универсальный дескриптор сокета
 * </параметры>
 *
 * <возврат>
 *   дескриптор сокета Windows или INVALID_SOCKET в случае ошибки
 * </возврат>
 *
 */
static SOCKET CEcoEventPoll1_ReadSocket(descriptor_t fd) {
    if (fd == 0) {
        return INVALID_SOCKET;
    }
    return (SOCKET)(uintptr_t)(*(int*)fd);
}

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_ResetOverlapped
 * </сводка>
 *
 * <описание>
 *   Функция очищает структуру OVERLAPPED перед повторной постановкой асинхронной операции
 * </описание>
 *
 * <параметры>
 *   overlapped - указатель на структуру OVERLAPPED
 * </параметры>
 *
 * <возврат>
 *   отсутствует
 * </возврат>
 *
 */
static void CEcoEventPoll1_ResetOverlapped(OVERLAPPED* overlapped) {
    uint8_t* bytes = (uint8_t*)overlapped;
    uint32_t i = 0;
    for (i = 0; i < sizeof(OVERLAPPED); ++i) {
        bytes[i] = 0;
    }
}

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_FindContext
 * </сводка>
 *
 * <описание>
 *   Функция ищет внутренний контекст зарегистрированного сокета
 * </описание>
 *
 * <параметры>
 *   pCMe - указатель на экземпляр компонента
 *   socket - дескриптор сокета Windows
 * </параметры>
 *
 * <возврат>
 *   указатель на контекст сокета или 0, если контекст не найден
 * </возврат>
 *
 */
static CEcoEventPoll1SocketContext* CEcoEventPoll1_FindContext(CEcoEventPoll1* pCMe, SOCKET socket) {
    int32_t i = 0;
    for (i = 0; i < pCMe->m_registered_count; ++i) {
        CEcoEventPoll1SocketContext* context = (CEcoEventPoll1SocketContext*)pCMe->m_registered[i];
        if (context != 0 && context->m_socket == socket) {
            return context;
        }
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_EnsureRegisteredCapacity
 * </сводка>
 *
 * <описание>
 *   Функция увеличивает емкость массива зарегистрированных сокетов при необходимости
 * </описание>
 *
 * <параметры>
 *   pCMe - указатель на экземпляр компонента
 *   required - требуемое количество элементов
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
static int16_t CEcoEventPoll1_EnsureRegisteredCapacity(CEcoEventPoll1* pCMe, int32_t required) {
    voidptr_t* updated = 0;
    int32_t newCapacity = 0;

    if (required <= pCMe->m_registered_capacity) {
        return 0;
    }

    newCapacity = pCMe->m_registered_capacity == 0 ? 8 : pCMe->m_registered_capacity * 2;
    while (newCapacity < required) {
        newCapacity *= 2;
    }

    updated = (voidptr_t*)pCMe->m_pIMem->pVTbl->Alloc(
        pCMe->m_pIMem,
        sizeof(voidptr_t) * newCapacity
    );
    if (updated == 0) {
        return -1;
    }

    pCMe->m_pIMem->pVTbl->Fill(
        pCMe->m_pIMem,
        updated,
        0,
        sizeof(voidptr_t) * newCapacity
    );

    if (pCMe->m_registered != 0 && pCMe->m_registered_count > 0) {
        pCMe->m_pIMem->pVTbl->Copy(
            pCMe->m_pIMem,
            updated,
            pCMe->m_registered,
            sizeof(voidptr_t) * pCMe->m_registered_count
        );
        pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, pCMe->m_registered);
    }

    pCMe->m_registered = updated;
    pCMe->m_registered_capacity = newCapacity;
    return 0;
}

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_EnsureReadyCapacity
 * </сводка>
 *
 * <описание>
 *   Функция увеличивает емкость массива готовых событий при необходимости
 * </описание>
 *
 * <параметры>
 *   pCMe - указатель на экземпляр компонента
 *   required - требуемое количество элементов
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
static int16_t CEcoEventPoll1_EnsureReadyCapacity(CEcoEventPoll1* pCMe, int32_t required) {
    voidptr_t* updated = 0;

    if (required <= pCMe->m_maxevents) {
        return 0;
    }

    if (pCMe->m_ready_contexts != 0) {
        pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, pCMe->m_ready_contexts);
        pCMe->m_ready_contexts = 0;
    }

    updated = (voidptr_t*)pCMe->m_pIMem->pVTbl->Alloc(
        pCMe->m_pIMem,
        sizeof(voidptr_t) * required
    );
    if (updated == 0) {
        return -1;
    }

    pCMe->m_pIMem->pVTbl->Fill(
        pCMe->m_pIMem,
        updated,
        0,
        sizeof(voidptr_t) * required
    );

    pCMe->m_ready_contexts = updated;
    pCMe->m_maxevents = required;
    return 0;
}

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_PostZeroByteRecv
 * </сводка>
 *
 * <описание>
 *   Функция ставит на сокет асинхронную zero-byte операцию WSARecv для ожидания события чтения через IOCP
 * </описание>
 *
 * <параметры>
 *   context - указатель на внутренний контекст сокета
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
static int16_t CEcoEventPoll1_PostZeroByteRecv(CEcoEventPoll1SocketContext* context) {
    WSABUF buffer;
    DWORD flags = 0;
    DWORD received = 0;
    int ret = 0;

    if (context == 0 || context->m_deleted || context->m_pending) {
        return 0;
    }

    CEcoEventPoll1_ResetOverlapped(&context->m_overlapped);
    buffer.buf = 0;
    buffer.len = 0;

    ret = WSARecv(context->m_socket, &buffer, 1, &received, &flags, &context->m_overlapped, 0);
    if (ret == 0) {
        context->m_pending = 1;
        return 0;
    }

    if (WSAGetLastError() == WSA_IO_PENDING) {
        context->m_pending = 1;
        return 0;
    }

    return -1;
}
#endif

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция возвращает указатель на запрошенный интерфейс компонента
 * </описание>
 *
 * <параметры>
 *   me - указатель на экземпляр интерфейса IEcoEventPoll1
 *   riid - идентификатор запрашиваемого интерфейса
 *   ppv - указатель на переменную для результата
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
int16_t CEcoEventPoll1_QueryInterface(/* in */ struct IEcoEventPoll1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;
    int16_t result = -1;

    if (me == 0 || ppv == 0) {
        return result;
    }

    if (IsEqualUGUID(riid, &IID_IEcoEventPoll1)) {
        *ppv = &pCMe->m_pVTblIEcoEventPoll1;
        pCMe->m_pVTblIEcoEventPoll1->AddRef((IEcoEventPoll1*)pCMe);
    }
    else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
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
 *   Функция CEcoEventPoll1_AddRef
 * </сводка>
 *
 * <описание>
 *   Функция увеличивает счетчик ссылок экземпляра компонента
 * </описание>
 *
 * <параметры>
 *   me - указатель на экземпляр интерфейса IEcoEventPoll1
 * </параметры>
 *
 * <возврат>
 *   текущее значение счетчика ссылок или -1 в случае ошибки
 * </возврат>
 *
 */
uint32_t CEcoEventPoll1_AddRef(/* in */ struct IEcoEventPoll1* me) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;

    if (me == 0) {
        return (uint32_t)-1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_Release
 * </сводка>
 *
 * <описание>
 *   Функция уменьшает счетчик ссылок экземпляра компонента и удаляет его при достижении нуля
 * </описание>
 *
 * <параметры>
 *   me - указатель на экземпляр интерфейса IEcoEventPoll1
 * </параметры>
 *
 * <возврат>
 *   текущее значение счетчика ссылок или 0 после удаления экземпляра
 * </возврат>
 *
 */
uint32_t CEcoEventPoll1_Release(/* in */ struct IEcoEventPoll1* me) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;

    if (me == 0) {
        return (uint32_t)-1;
    }

    --pCMe->m_cRef;

    if (pCMe->m_cRef == 0) {
        deleteCEcoEventPoll1((IEcoEventPoll1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_Add
 * </сводка>
 *
 * <описание>
 *   Функция регистрирует дескриптор в механизме ожидания событий текущей платформы
 * </описание>
 *
 * <параметры>
 *   me - указатель на экземпляр интерфейса IEcoEventPoll1
 *   fd - универсальный дескриптор сокета
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
int16_t CEcoEventPoll1_Add(/* in */ struct IEcoEventPoll1* me, /* in */ descriptor_t fd) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;
#ifdef ECO_WINDOWS
    SOCKET socketValue = INVALID_SOCKET;
    CEcoEventPoll1SocketContext* context = 0;
#endif

    if (me == 0) {
        return -1;
    }

#ifdef ECO_OS
    (void)fd;
    return -1;
#elif ECO_WINDOWS
    socketValue = CEcoEventPoll1_ReadSocket(fd);
    if (socketValue == INVALID_SOCKET) {
        return -1;
    }

    context = CEcoEventPoll1_FindContext(pCMe, socketValue);
    if (context != 0) {
        context->m_deleted = 0;
        return CEcoEventPoll1_PostZeroByteRecv(context);
    }

    if (CEcoEventPoll1_EnsureRegisteredCapacity(pCMe, pCMe->m_registered_count + 1) != 0) {
        return -1;
    }

    context = (CEcoEventPoll1SocketContext*)pCMe->m_pIMem->pVTbl->Alloc(
        pCMe->m_pIMem,
        sizeof(CEcoEventPoll1SocketContext)
    );
    if (context == 0) {
        return -1;
    }

    pCMe->m_pIMem->pVTbl->Fill(pCMe->m_pIMem, context, 0, sizeof(CEcoEventPoll1SocketContext));
    context->m_socket = socketValue;

    if (CreateIoCompletionPort((HANDLE)socketValue, (HANDLE)pCMe->m_hio, (ULONG_PTR)context, 0) == NULL) {
        pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, context);
        return -1;
    }

    pCMe->m_registered[pCMe->m_registered_count++] = context;
    return CEcoEventPoll1_PostZeroByteRecv(context);
#elif ECO_LINUX
    {
        int ret = 0;
        struct epoll_event epollEvent;

        epollEvent.events = EPOLLIN | EPOLLERR | EPOLLHUP;
        epollEvent.data.u32 = *(int*)fd;

        ret = epoll_ctl(pCMe->m_fd, EPOLL_CTL_ADD, *(int*)fd, &epollEvent);
        if (ret < 0) {
            return -1;
        }
    }
    return 0;
#elif ECO_APPLE
    (void)fd;
    return -1;
#elif ECO_ANDROID
    (void)fd;
    return -1;
#endif
}

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_Mod
 * </сводка>
 *
 * <описание>
 *   Функция обновляет параметры отслеживания зарегистрированного дескриптора
 * </описание>
 *
 * <параметры>
 *   me - указатель на экземпляр интерфейса IEcoEventPoll1
 *   fd - универсальный дескриптор сокета
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
int16_t CEcoEventPoll1_Mod(/* in */ struct IEcoEventPoll1* me, /* in */ descriptor_t fd) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;
#ifdef ECO_WINDOWS
    SOCKET socketValue = INVALID_SOCKET;
    CEcoEventPoll1SocketContext* context = 0;
#endif

    if (me == 0) {
        return -1;
    }

#ifdef ECO_OS
    (void)fd;
    return -1;
#elif ECO_WINDOWS
    socketValue = CEcoEventPoll1_ReadSocket(fd);
    context = CEcoEventPoll1_FindContext(pCMe, socketValue);

    if (context == 0) {
        return CEcoEventPoll1_Add(me, fd);
    }

    context->m_deleted = 0;
    context->m_ready = 0;
    return CEcoEventPoll1_PostZeroByteRecv(context);
#elif ECO_LINUX
    {
        int ret = 0;
        struct epoll_event epollEvent;

        epollEvent.events = EPOLLIN | EPOLLERR | EPOLLHUP;
        epollEvent.data.u32 = *(int*)fd;

        ret = epoll_ctl(pCMe->m_fd, EPOLL_CTL_MOD, *(int*)fd, &epollEvent);
        if (ret < 0) {
            return -1;
        }
    }
    return 0;
#elif ECO_APPLE
    (void)fd;
    return -1;
#elif ECO_ANDROID
    (void)fd;
    return -1;
#endif
}

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_Del
 * </сводка>
 *
 * <описание>
 *   Функция удаляет дескриптор из механизма ожидания событий
 * </описание>
 *
 * <параметры>
 *   me - указатель на экземпляр интерфейса IEcoEventPoll1
 *   fd - универсальный дескриптор сокета
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
int16_t CEcoEventPoll1_Del(/* in */ struct IEcoEventPoll1* me, /* in */ descriptor_t fd) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;
#ifdef ECO_WINDOWS
    SOCKET socketValue = INVALID_SOCKET;
    CEcoEventPoll1SocketContext* context = 0;
#endif

    if (me == 0) {
        return -1;
    }

#ifdef ECO_OS
    (void)fd;
    return -1;
#elif ECO_WINDOWS
    socketValue = CEcoEventPoll1_ReadSocket(fd);
    context = CEcoEventPoll1_FindContext(pCMe, socketValue);

    if (context == 0) {
        return -1;
    }

    context->m_deleted = 1;
    context->m_ready = 0;
    return 0;
#elif ECO_LINUX
    {
        int ret = epoll_ctl(pCMe->m_fd, EPOLL_CTL_DEL, *(int*)fd, 0);
        if (ret < 0) {
            return -1;
        }
    }
    return 0;
#elif ECO_APPLE
    (void)fd;
    return -1;
#elif ECO_ANDROID
    (void)fd;
    return -1;
#endif
}

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_Wait
 * </сводка>
 *
 * <описание>
 *   Функция ожидает наступления событий для зарегистрированных дескрипторов
 * </описание>
 *
 * <параметры>
 *   me - указатель на экземпляр интерфейса IEcoEventPoll1
 *   maxevents - максимальное количество возвращаемых событий
 *   timeout - время ожидания в миллисекундах
 * </параметры>
 *
 * <возврат>
 *   количество готовых событий, 0 при таймауте, -1 при ошибке
 * </возврат>
 *
 */
int32_t CEcoEventPoll1_Wait(/* in */ struct IEcoEventPoll1* me, /* in */ int32_t maxevents, /* in */ int32_t timeout) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;
    IEcoMemoryAllocator1* pIMem = 0;
#ifdef ECO_WINDOWS
    DWORD bytesTransferred = 0;
    ULONG_PTR completionKey = 0;
    LPOVERLAPPED overlapped = 0;
    BOOL ret = FALSE;
    DWORD waitMilliseconds = 0;
    CEcoEventPoll1SocketContext* context = 0;
#endif

    if (me == 0 || maxevents <= 0) {
        return -1;
    }

    pIMem = pCMe->m_pIMem;
    (void)pIMem;

#ifdef ECO_OS
    (void)timeout;
    return -1;
#elif ECO_WINDOWS
    waitMilliseconds = timeout < 0 ? INFINITE : (DWORD)timeout;

    if (CEcoEventPoll1_EnsureReadyCapacity(pCMe, maxevents) != 0) {
        return -1;
    }

    pCMe->m_ready_events = 0;
    ret = GetQueuedCompletionStatus(
        (HANDLE)pCMe->m_hio,
        &bytesTransferred,
        &completionKey,
        &overlapped,
        waitMilliseconds
    );

    if (!ret) {
        if (GetLastError() == WAIT_TIMEOUT) {
            return 0;
        }
        return -1;
    }

    while (1) {
        context = (CEcoEventPoll1SocketContext*)completionKey;
        (void)bytesTransferred;
        (void)overlapped;

        if (context != 0 && !context->m_deleted) {
            context->m_pending = 0;
            if (!context->m_ready) {
                context->m_ready = 1;
            pCMe->m_ready_contexts[pCMe->m_ready_events++] = (voidptr_t)context;
            }
        }

        if (pCMe->m_ready_events >= maxevents) {
            break;
        }

        ret = GetQueuedCompletionStatus(
            (HANDLE)pCMe->m_hio,
            &bytesTransferred,
            &completionKey,
            &overlapped,
            0
        );
        if (!ret) {
            break;
        }
    }

    return pCMe->m_ready_events;
#elif ECO_LINUX
    {
        int ret = 0;

        if (pCMe->m_epoll_events != 0) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_epoll_events);
            pCMe->m_epoll_events = 0;
        }

        pCMe->m_maxevents = maxevents;
        pCMe->m_epoll_events = (struct epoll_event*)pIMem->pVTbl->Alloc(
            pIMem,
            sizeof(struct epoll_event) * pCMe->m_maxevents
        );
        if (pCMe->m_epoll_events == 0) {
            return -1;
        }

        ret = epoll_wait(pCMe->m_fd, pCMe->m_epoll_events, maxevents, timeout);
        if (ret < 0) {
            return -1;
        }

        pCMe->m_ready_events = ret;
        return ret;
    }
#elif ECO_APPLE
    (void)timeout;
    return -1;
#elif ECO_ANDROID
    (void)timeout;
    return -1;
#endif
}

/*
 *
 * <сводка>
 *   Функция CEcoEventPoll1_Enum
 * </сводка>
 *
 * <описание>
 *   Функция возвращает дескриптор готового события по его индексу
 * </описание>
 *
 * <параметры>
 *   me - указатель на экземпляр интерфейса IEcoEventPoll1
 *   number - индекс готового события
 *   fd - указатель на переменную для возвращаемого дескриптора
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
int16_t CEcoEventPoll1_Enum(/* in */ struct IEcoEventPoll1* me, /* in */ int32_t number, /* out */ descriptor_t fd) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;
#ifdef ECO_WINDOWS
    CEcoEventPoll1SocketContext* context = 0;
#endif

    if (me == 0 || fd == 0) {
        return -1;
    }

#ifdef ECO_OS
    (void)number;
    return -1;
#elif ECO_WINDOWS
    if (number < 0 || number >= pCMe->m_ready_events) {
        return -1;
    }

    context = (CEcoEventPoll1SocketContext*)pCMe->m_ready_contexts[number];
    if (context == 0 || context->m_deleted) {
        return -1;
    }

    *(int*)fd = (int)context->m_socket;
    context->m_ready = 0;

    if (CEcoEventPoll1_PostZeroByteRecv(context) != 0) {
        return -1;
    }
    return 0;
#elif ECO_LINUX
    if (number < 0 || number >= pCMe->m_ready_events) {
        return -1;
    }

    *(int*)fd = (int)pCMe->m_epoll_events[number].data.u32;
    return 0;
#elif ECO_APPLE
    (void)number;
    return -1;
#elif ECO_ANDROID
    (void)number;
    return -1;
#endif
}

/*
 *
 * <сводка>
 *   Функция initCEcoEventPoll1
 * </сводка>
 *
 * <описание>
 *   Функция инициализирует экземпляр компонента
 * </описание>
 *
 * <параметры>
 *   me - указатель на экземпляр интерфейса IEcoEventPoll1
 *   pIUnkSystem - указатель на системный интерфейс
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
int16_t initCEcoEventPoll1(/*in*/ struct IEcoEventPoll1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)me;

    if (me == 0) {
        return -1;
    }

    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;
    return 0;
}

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
 *   Функция createCEcoEventPoll1
 * </сводка>
 *
 * <описание>
 *   Функция создает и инициализирует экземпляр компонента CEcoEventPoll1
 * </описание>
 *
 * <параметры>
 *   pIUnkSystem - указатель на системный интерфейс
 *   pIUnkOuter - указатель на внешний агрегирующий интерфейс
 *   ppIEcoEventPoll1 - указатель на переменную для результата
 * </параметры>
 *
 * <возврат>
 *   0 - успешное выполнение, -1 - ошибка
 * </возврат>
 *
 */
int16_t createCEcoEventPoll1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoEventPoll1** ppIEcoEventPoll1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoEventPoll1* pCMe = 0;

    (void)pIUnkOuter;

    if (ppIEcoEventPoll1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void**)&pISys);
    if (result != 0 || pISys == 0) {
        return result;
    }

    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);
    if (result != 0 || pIBus == 0) {
        pISys->pVTbl->Release(pISys);
        return result;
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**)&pIMem);
    if (result != 0 || pIMem == 0) {
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return result;
    }

    pCMe = (CEcoEventPoll1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoEventPoll1));
    if (pCMe == 0) {
        pIBus->pVTbl->Release(pIBus);
        pIMem->pVTbl->Release(pIMem);
        pISys->pVTbl->Release(pISys);
        return -1;
    }

    pIMem->pVTbl->Fill(pIMem, pCMe, 0, sizeof(CEcoEventPoll1));
    pCMe->m_pISys = pISys;
    pCMe->m_pIMem = pIMem;
    pCMe->m_cRef = 1;
    pCMe->m_pVTblIEcoEventPoll1 = &g_xCDD422700B2B470CADDAD8C752020BE4VTbl;

#ifdef ECO_OS
    deleteCEcoEventPoll1((IEcoEventPoll1*)pCMe);
    pIBus->pVTbl->Release(pIBus);
    return -1;
#elif ECO_WINDOWS
    pCMe->m_hio = (voidptr_t)CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    if (pCMe->m_hio == NULL) {
        deleteCEcoEventPoll1((IEcoEventPoll1*)pCMe);
        pIBus->pVTbl->Release(pIBus);
        return -1;
    }
#elif ECO_LINUX
    pCMe->m_fd = epoll_create1(0);
    if (pCMe->m_fd < 0) {
        deleteCEcoEventPoll1((IEcoEventPoll1*)pCMe);
        pIBus->pVTbl->Release(pIBus);
        return -1;
    }
#elif ECO_APPLE
    deleteCEcoEventPoll1((IEcoEventPoll1*)pCMe);
    pIBus->pVTbl->Release(pIBus);
    return -1;
#elif ECO_ANDROID
    deleteCEcoEventPoll1((IEcoEventPoll1*)pCMe);
    pIBus->pVTbl->Release(pIBus);
    return -1;
#endif

    *ppIEcoEventPoll1 = (IEcoEventPoll1*)pCMe;
    pIBus->pVTbl->Release(pIBus);
    return 0;
}

/*
 *
 * <сводка>
 *   Функция deleteCEcoEventPoll1
 * </сводка>
 *
 * <описание>
 *   Функция освобождает ресурсы и удаляет экземпляр компонента CEcoEventPoll1
 * </описание>
 *
 * <параметры>
 *   pIEcoEventPoll1 - указатель на экземпляр интерфейса IEcoEventPoll1
 * </параметры>
 *
 * <возврат>
 *   отсутствует
 * </возврат>
 *
 */
void deleteCEcoEventPoll1(/* in */ IEcoEventPoll1* pIEcoEventPoll1) {
    CEcoEventPoll1* pCMe = (CEcoEventPoll1*)pIEcoEventPoll1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoEventPoll1 == 0) {
        return;
    }

    pIMem = pCMe->m_pIMem;

#ifdef ECO_OS
#elif ECO_WINDOWS
    if (pCMe->m_ready_contexts != 0) {
        pIMem->pVTbl->Free(pIMem, pCMe->m_ready_contexts);
    }

    if (pCMe->m_registered != 0) {
        int32_t i = 0;
        for (i = 0; i < pCMe->m_registered_count; ++i) {
            if (pCMe->m_registered[i] != 0) {
                pIMem->pVTbl->Free(pIMem, pCMe->m_registered[i]);
            }
        }
        pIMem->pVTbl->Free(pIMem, pCMe->m_registered);
    }

    if (pCMe->m_hio != NULL) {
        CloseHandle((HANDLE)pCMe->m_hio);
    }
#elif ECO_LINUX
    if (pCMe->m_epoll_events != 0) {
        pIMem->pVTbl->Free(pIMem, pCMe->m_epoll_events);
    }

    if (pCMe->m_fd != -1) {
        close(pCMe->m_fd);
    }
#elif ECO_APPLE
#elif ECO_ANDROID
#endif

    if (pCMe->m_pISys != 0) {
        pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
    }

    pIMem->pVTbl->Free(pIMem, pCMe);
    pIMem->pVTbl->Release(pIMem);
}
