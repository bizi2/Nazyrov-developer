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

typedef struct CEcoPKCS15TokenInfo {

    /* Таблица функций интерфейса IEcoPKCS15 */
    IEcoPKCS15VTbl* m_pVTblIEcoPKCS15;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    IEcoASNOne1Value* m_version;
	IEcoASNOne1Value* m_serialNumber;
	IEcoPKCS15Label* m_manufacturerID;
	IEcoPKCS15Label* m_label;
	IEcoPKCS15TokenFlags* m_tokenflags;
	IEcoPKCS15SecurityEnvironmentInfo* m_seInfo;
	IEcoPKCS15RecordInfo* m_recordInfo;
	IEcoPKCS15AlgorithmInfo* m_supportedAlgorithms;
	IEcoPKCS15Label* m_issuerId;
	IEcoPKCS15Label* m_holderId;
	IEcoPKCS15LastUpdate* m_lastUpdate;
	IEcoPKCS15PrintableString* m_preferredLanguage;

} CEcoPKCS15TokenInfo, *CEcoPKCS15TokenInfoPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS15TokenInfo(/*in*/ IEcoPKCS15Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS15TokenInfo(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS15Ptr_t* ppIEcoPKCS15);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS15TokenInfo(/* in */ IEcoPKCS15Ptr_t pIEcoPKCS15);

#endif /* __C_ECOPKCS15_H__ */
