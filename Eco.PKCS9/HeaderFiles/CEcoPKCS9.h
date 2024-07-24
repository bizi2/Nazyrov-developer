/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS9
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoPKCS9
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOPKCS9_H__
#define __C_ECOPKCS9_H__

#include "IEcoPKCS9.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS9_F5201646 {

    /* Таблица функций интерфейса IEcoPKCS9 */
    IEcoPKCS9VTbl* m_pVTblIEcoPKCS9;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CEcoPKCS9_F5201646, *CEcoPKCS9_F5201646Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS9_F5201646(/*in*/ IEcoPKCS9Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS9_F5201646(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS9Ptr_t* ppIEcoPKCS9);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS9_F5201646(/* in */ IEcoPKCS9Ptr_t pIEcoPKCS9);

#endif /* __C_ECOPKCS9_H__ */
