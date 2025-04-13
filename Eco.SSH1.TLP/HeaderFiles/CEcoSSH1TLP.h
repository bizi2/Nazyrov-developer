/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSSH1TLP
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoSSH1TLP
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_SSH_1_TRANSPORT_LAYER_PROTOCOL_H__
#define __C_ECO_SSH_1_TRANSPORT_LAYER_PROTOCOL_H__

#include "IEcoSSH1TLP.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoSSH1TLP_AE11B435 {

    /* Таблица функций интерфейса IEcoSSH1TLP */
    IEcoSSH1TLPVTbl* m_pVTblIEcoSSH1TLP;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoSSH1TLP_AE11B435, *CEcoSSH1TLP_AE11B435Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoSSH1TLP_AE11B435(/*in*/ IEcoSSH1TLPPtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoSSH1TLP_AE11B435(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoSSH1TLPPtr_t* ppIEcoSSH1TLP);
/* Удаление */
void ECOCALLMETHOD deleteCEcoSSH1TLP_AE11B435(/* in */ IEcoSSH1TLPPtr_t pIEcoSSH1TLP);

#endif /* __C_ECO_SSH_1_TRANSPORT_LAYER_PROTOCOL_H__ */
