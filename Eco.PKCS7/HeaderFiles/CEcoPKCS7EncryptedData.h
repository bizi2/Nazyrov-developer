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

#ifndef __C_ECOPKCS7ENCRYPTEDDATA_H__
#define __C_ECOPKCS7ENCRYPTEDDATA_H__

#include "IEcoPKCS7.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS7EncryptedData {

    /* Таблица функций интерфейса IEcoPKCS7 */
    IEcoPKCS7EncryptedDataVTbl* m_pVTblIEcoPKCS7EncryptedData;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейс для работы с нотацией ASN.1 */
    IEcoASNOne1* m_pIASNOne;

    /* Данные экземпляра */
	IEcoASNOne1ValueSet* m_SET;
    IEcoPKCS7Version* m_version;
	IEcoPKCS7EncryptedContentInfo* m_encryptedContentInfo;

} CEcoPKCS7EncryptedData, *CEcoPKCS7EncryptedDataPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS7EncryptedData(/*in*/ IEcoPKCS7Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS7EncryptedData(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS7Ptr_t* ppIEcoPKCS7);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS7EncryptedData(/* in */ IEcoPKCS7Ptr_t pIEcoPKCS7);

#endif /* __C_ECOPKCS7ENCRYPTEDDATA_H__ */
