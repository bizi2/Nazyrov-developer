/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS12
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoPKCS12
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOPKCS12_H__
#define __C_ECOPKCS12_H__

#include "IEcoPKCS12.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS12_2BFE6209 {

    /* Таблица функций интерфейса IEcoPKCS12 */
    IEcoPKCS12VTbl* m_pVTblIEcoPKCS12;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    int16_t* m_mac;
	int16_t* m_macSalt;
	int16_t* m_iterations;

} CEcoPKCS12_2BFE6209, *CEcoPKCS12_2BFE6209Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS12_2BFE6209(/*in*/ IEcoPKCS12Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS12_2BFE6209(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS12Ptr_t* ppIEcoPKCS12);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS12_2BFE6209(/* in */ IEcoPKCS12Ptr_t pIEcoPKCS12);

#endif /* __C_ECOPKCS12_H__ */
