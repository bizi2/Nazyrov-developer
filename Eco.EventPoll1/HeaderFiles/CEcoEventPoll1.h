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
 *   Данный заголовок описывает реализацию компонента CEcoEventPoll1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_EVENT_POLL_1_H__
#define __C_ECO_EVENT_POLL_1_H__

#include "IEcoEventPoll1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoEventPoll1 {

    /* Таблица функций интерфейса IEcoEventPoll1 */
    IEcoEventPoll1VTbl* m_pVTblIEcoEventPoll1;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
#ifdef ECO_OS
#elif ECO_WINDOWS
    voidptr_t m_hio;
    int32_t m_maxevents;
    int32_t m_ready_events;
    voidptr_t* m_registered;
    int32_t m_registered_count;
    int32_t m_registered_capacity;
    voidptr_t* m_ready_contexts;
#elif ECO_LINUX
    int m_fd;
    int m_maxevents;
    int m_ready_events;
    struct epoll_event* m_epoll_events;
#elif ECO_APPLE
#elif ECO_ANDROID
#endif

} CEcoEventPoll1, *CEcoEventPoll1Ptr;

/* Инициализация экземпляра */
int16_t initCEcoEventPoll1(/*in*/ struct IEcoEventPoll1* me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t createCEcoEventPoll1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoEventPoll1** ppIEcoEventPoll1);
/* Удаление */
void deleteCEcoEventPoll1(/* in */ IEcoEventPoll1* pIEcoEventPoll1);

#endif /* __C_ECO_EVENT_POLL_1_H__ */
