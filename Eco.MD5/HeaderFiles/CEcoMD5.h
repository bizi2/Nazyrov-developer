/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoMD5
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoMD5
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOMD5_H__
#define __C_ECOMD5_H__

#include "IEcoMD5.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoMD5_5D90ACD0 {

    /* Таблица функций интерфейса IEcoMD5 */
    IEcoMD5VTbl* m_pVTblIEcoMD5;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoMD5_5D90ACD0, *CEcoMD5_5D90ACD0Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoMD5_5D90ACD0(/*in*/ IEcoMD5Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoMD5_5D90ACD0(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoMD5Ptr_t* ppIEcoMD5);
/* Удаление */
void ECOCALLMETHOD deleteCEcoMD5_5D90ACD0(/* in */ IEcoMD5Ptr_t pIEcoMD5);

#endif /* __C_ECOMD5_H__ */
