/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS15
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoPKCS15
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOPKCS15_H__
#define __C_ECOPKCS15_H__

#include "IEcoPKCS15.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS15DigestInfoWithDefault {

    /* Таблица функций интерфейса IEcoPKCS15 */
    IEcoPKCS15VTbl* m_pVTblIEcoPKCS15;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    IEcoPKCS15AlgorithmIdentifier* m_digestAlg;
	IEcoASNOneDataValue* m_digest;

} CEcoPKCS15DigestInfoWithDefault, *CEcoPKCS15DigestInfoWithDefaultPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS15DigestInfoWithDefault(/*in*/ IEcoPKCS15Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS15DigestInfoWithDefault(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS15Ptr_t* ppIEcoPKCS15);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS15DigestInfoWithDefault(/* in */ IEcoPKCS15Ptr_t pIEcoPKCS15);

#endif /* __C_ECOPKCS15_H__ */
