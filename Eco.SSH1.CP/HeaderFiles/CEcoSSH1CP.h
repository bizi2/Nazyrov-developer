/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSSH1CP
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoSSH1CP
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_SSH_1_CONNECTION_PROTOCOL_H__
#define __C_ECO_SSH_1_CONNECTION_PROTOCOL_H__

#include "IEcoSSH1CP.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoSSH1CP_A203EFE6 {

    /* Таблица функций интерфейса IEcoSSH1CP */
    IEcoSSH1CPVTbl* m_pVTblIEcoSSH1CP;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoSSH1CP_A203EFE6, *CEcoSSH1CP_A203EFE6Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoSSH1CP_A203EFE6(/*in*/ IEcoSSH1CPPtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoSSH1CP_A203EFE6(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoSSH1CPPtr_t* ppIEcoSSH1CP);
/* Удаление */
void ECOCALLMETHOD deleteCEcoSSH1CP_A203EFE6(/* in */ IEcoSSH1CPPtr_t pIEcoSSH1CP);

#endif /* __C_ECO_SSH_1_CONNECTION_PROTOCOL_H__ */
