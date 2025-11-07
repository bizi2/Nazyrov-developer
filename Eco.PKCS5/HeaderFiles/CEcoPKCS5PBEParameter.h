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

#ifndef __C_ECOPKCS5PBEParameter_H__
#define __C_ECOPKCS5PBEParameter_H__

#include "IEcoPKCS5.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS5PBEParameter {

    /* Таблица функций интерфейса IEcoPKCS5 */
    IEcoPKCS5PBEParameterVTbl* m_pVTblIEcoPKCS5PBEParameter;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы с нотацией ASN.1 */
    IEcoASNOne1* m_pIASNOne;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    IEcoASNOne1ValueSet* m_SEQUENCE;
    IEcoASNOne1Value* m_salt;
	IEcoASNOne1Value* m_iterationCount;

} CEcoPKCS5PBEParameter, *CEcoPKCS5PBEParameterPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS5PBEParameter(/*in*/ IEcoPKCS5Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS5PBEParameter(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS5Ptr_t* ppIEcoPKCS5);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS5PBEParameter(/* in */ IEcoPKCS5Ptr_t pIEcoPKCS5);

#endif /* __C_ECOPKCS5PBEParameter_H__ */
