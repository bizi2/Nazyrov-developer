/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS5
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoPKCS5
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOPKCS5_H__
#define __C_ECOPKCS5_H__

#include "IEcoPKCS5.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS5PBES1 {

    /* Таблица функций интерфейса IEcoPKCS5 */
    IEcoPKCS5VTbl* m_pVTblIEcoPKCS5;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    IEcoASNOneDataValue* m_salt;
	IEcoASNOneINTEGER* m_iterationCount;

} CEcoPKCS5PBES1, *CEcoPKCS5PBES1Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS5PBES1(/*in*/ IEcoPKCS5Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS5PBES1(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS5Ptr_t* ppIEcoPKCS5);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS5PBES1(/* in */ IEcoPKCS5Ptr_t pIEcoPKCS5);

#endif /* __C_ECOPKCS5_H__ */
