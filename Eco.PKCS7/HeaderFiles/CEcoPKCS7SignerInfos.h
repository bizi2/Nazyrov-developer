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
 *   Данный заголовок описывает реализацию компонента CEcoPKCS7CEcoPKCS7SignerInfos
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOPKCS7SIGNERINFOS_H__
#define __C_ECOPKCS7SIGNERINFOS_H__

#include "IEcoPKCS7.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS7SignerInfos {

    /* Таблица функций интерфейса IEcoPKCS7 */
    IEcoPKCS7SignerInfosVTbl* m_pVTblIEcoPKCS7SignerInfos;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы с нотацией ASN.1 */
    IEcoASNOne1* m_pIASNOne;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
	IEcoASNOne1ValueSet* m_SET;
    IEcoPKCS7RecipientInfo* m_siSet;
    IEcoPKCS7RecipientInfo* m_siSequence;

} CEcoPKCS7SignerInfos, *CEcoPKCS7SignerInfosPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS7SignerInfos(/*in*/ IEcoPKCS7Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS7SignerInfos(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS7Ptr_t* ppIEcoPKCS7);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS7SignerInfos(/* in */ IEcoPKCS7Ptr_t pIEcoPKCS7);

#endif /* __C_ECOPKCS7SIGNERINFOS_H__ */
