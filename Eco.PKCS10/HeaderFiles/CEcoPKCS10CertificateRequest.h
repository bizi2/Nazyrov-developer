/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS10
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoPKCS10
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOPKCS10_H__
#define __C_ECOPKCS10_H__

#include "IEcoPKCS10.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS10CertificateRequest {

    /* Таблица функций интерфейса IEcoPKCS10 */
    IEcoPKCS10VTbl* m_pVTblIEcoPKCS10;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    IEcoPKCS10CertificationRequestInfo* m_certificationRequestInfo;
	IEcoPKCS10AlgorithmIdentifier* m_signatureAlgorithm;
	IEcoASNOneBITSTRING* m_signature;

} CEcoPKCS10CertificateRequest, *CEcoPKCS10CertificateRequestPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS10CertificateRequest(/*in*/ IEcoPKCS10Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS10CertificateRequest(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS10Ptr_t* ppIEcoPKCS10);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS10CertificateRequest(/* in */ IEcoPKCS10Ptr_t pIEcoPKCS10);

#endif /* __C_ECOPKCS10_H__ */
