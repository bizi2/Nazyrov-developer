/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS7
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoPKCS7
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOPKCS7DIGESTINFO_H__
#define __C_ECOPKCS7DIGESTINFO_H__

#include "IEcoPKCS7.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IEcoASNOne1.h"

typedef struct CEcoPKCS7DigestInfo {

    /* Таблица функций интерфейса IEcoPKCS7 */
    IEcoPKCS7DigestInfoVTbl* m_pVTblIEcoPKCS7DigestInfo;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
	IEcoASNOne1ValueSet* m_SET;
    IEcoPKCS7DigestAlgorithmIdentifier* m_digestAlgorithm;
	IEcoPKCS7Digest* m_digest;

} CEcoPKCS7DigestInfo, *CEcoPKCS7DigestInfoPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS7DigestInfo(/*in*/ IEcoPKCS7Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS7DigestInfo(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS7Ptr_t* ppIEcoPKCS7);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS7DigestInfo(/* in */ IEcoPKCS7Ptr_t pIEcoPKCS7);

#endif /* __C_ECOPKCS7DIGESTINFO_H__ */
