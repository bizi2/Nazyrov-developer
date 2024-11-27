/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSSH1AP
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoSSH1AP
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_SSH_1_AUTHENTICATION_PROTOCOL_H__
#define __C_ECO_SSH_1_AUTHENTICATION_PROTOCOL_H__

#include "IEcoSSH1AP.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoSSH1AP_DBDD7F7A {

    /* Таблица функций интерфейса IEcoSSH1AP */
    IEcoSSH1APVTbl* m_pVTblIEcoSSH1AP;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoSSH1AP_DBDD7F7A, *CEcoSSH1AP_DBDD7F7APtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoSSH1AP_DBDD7F7A(/*in*/ IEcoSSH1APPtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoSSH1AP_DBDD7F7A(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoSSH1APPtr_t* ppIEcoSSH1AP);
/* Удаление */
void ECOCALLMETHOD deleteCEcoSSH1AP_DBDD7F7A(/* in */ IEcoSSH1APPtr_t pIEcoSSH1AP);

#endif /* __C_ECO_SSH_1_AUTHENTICATION_PROTOCOL_H__ */
