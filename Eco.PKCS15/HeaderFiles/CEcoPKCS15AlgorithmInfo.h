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

typedef struct CEcoPKCS15AlgorithmInfo {

    /* Таблица функций интерфейса IEcoPKCS15 */
    IEcoPKCS15VTbl* m_pVTblIEcoPKCS15;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    IEcoPKCS15Reference* m_reference;
	IEcoPKCS15Reference* m_algRef;
	//reference  	Reference,
    //algorithm  	PKCS15-ALGORITHM.&id({AlgorithmSet}),
    //parameters 	PKCS15-ALGORITHM.&Parameters({AlgorithmSet}{@algorithm}),
    //supportedOperations
    //    	PKCS15-ALGORITHM.&Operations({AlgorithmSet}{@algorithm}),
    //algId       PKCS15-ALGORITHM.&objectIdentifier({AlgorithmSet}{@algorithm})
    //                OPTIONAL, 
    //algRef	Reference OPTIONAL

} CEcoPKCS15AlgorithmInfo, *CEcoPKCS15AlgorithmInfoPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS15AlgorithmInfo(/*in*/ IEcoPKCS15Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS15AlgorithmInfo(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS15Ptr_t* ppIEcoPKCS15);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS15AlgorithmInfo(/* in */ IEcoPKCS15Ptr_t pIEcoPKCS15);

#endif /* __C_ECOPKCS15_H__ */
