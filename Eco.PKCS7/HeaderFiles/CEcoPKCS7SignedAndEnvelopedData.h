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

#ifndef __C_ECOPKCS7_H__
#define __C_ECOPKCS7_H__

#include "IEcoPKCS7.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS7SignedAndEnvelopedData {

    /* Таблица функций интерфейса IEcoPKCS7 */
    IEcoPKCS7VTbl* m_pVTblIEcoPKCS7;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    IEcoPKCS7Version* m_version;
	IEcoPKCS7RecipientInfos* m_recipientInfos;
	IEcoPKCS7DigestAlgorithmIdentifiers* m_digestAlgorithms;
	IEcoPKCS7EncryptedContentInfo* m_encryptedContentInfo;
	IEcoASNOneCHOICE* m_certificates;
	IEcoASNOneCHOICE* m_crls;
	IEcoPKCS7SignerInfos* m_signerInfos;

} CEcoPKCS7SignedAndEnvelopedData, *CEcoPKCS7SignedAndEnvelopedDataPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS7SignedAndEnvelopedData(/*in*/ IEcoPKCS7Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS7SignedAndEnvelopedData(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS7Ptr_t* ppIEcoPKCS7);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS7SignedAndEnvelopedData(/* in */ IEcoPKCS7Ptr_t pIEcoPKCS7);

#endif /* __C_ECOPKCS7_H__ */
