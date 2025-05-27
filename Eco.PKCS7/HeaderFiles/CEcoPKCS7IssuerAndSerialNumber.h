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

#ifndef __C_ECOPKCS7ISSUERANDSERIALNUMBER_H__
#define __C_ECOPKCS7ISSUERANDSERIALNUMBER_H__

#include "IEcoPKCS7.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS7IssuerAndSerialNumber {

    /* Таблица функций интерфейса IEcoPKCS7 */
    IEcoPKCS7IssuerAndSerialNumberVTbl* m_pVTblIEcoPKCS7IssuerAndSerialNumber;

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
	IEcoASNOne1Value* m_issuer;
	IEcoASNOne1Value* m_serialNumber;

} CEcoPKCS7IssuerAndSerialNumber, *CEcoPKCS7IssuerAndSerialNumberPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS7IssuerAndSerialNumber(/*in*/ IEcoPKCS7Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS7IssuerAndSerialNumber(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS7Ptr_t* ppIEcoPKCS7);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS7IssuerAndSerialNumber(/* in */ IEcoPKCS7Ptr_t pIEcoPKCS7);

#endif /* __C_ECOPKCS7ISSUERANDSERIALNUMBER_H__ */
