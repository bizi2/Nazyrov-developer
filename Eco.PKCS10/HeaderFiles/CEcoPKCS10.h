/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS10
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoPKCS10
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOPKCS10_H__
#define __C_ECOPKCS10_H__

#include "IEcoPKCS10.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS10_768F3B93 {

    /* Таблица функций интерфейса IEcoPKCS10 */
    IEcoPKCS10VTbl* m_pVTblIEcoPKCS10;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoPKCS10_768F3B93, *CEcoPKCS10_768F3B93Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS10_768F3B93(/*in*/ IEcoPKCS10Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS10_768F3B93(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS10Ptr_t* ppIEcoPKCS10);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS10_768F3B93(/* in */ IEcoPKCS10Ptr_t pIEcoPKCS10);

#endif /* __C_ECOPKCS10_H__ */
