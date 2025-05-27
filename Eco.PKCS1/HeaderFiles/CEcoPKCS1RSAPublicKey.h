/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoPKCS1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOPKCS1RSAPUBLICKEY_H__
#define __C_ECOPKCS1RSAPUBLICKEY_H__

#include "IEcoPKCS1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS1RSAPublicKey {

    /* Таблица функций интерфейса IEcoPKCS1 */
    IEcoPKCS1RSAPublicKeyVTbl* m_pVTblIEcoPKCS1RSAPublicKey;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Интерфейс для работы с нотацией ASN.1 */
    IEcoASNOne1* m_pIASNOne;

    /* Данные экземпляра */
    IEcoASNOne1ValueSet* m_SEQUENCE;
	IEcoASNOne1Value* m_modulus;
	IEcoASNOne1Value* m_publicExponent;

} CEcoPKCS1RSAPublicKey, *CEcoPKCS1RSAPublicKeyDPtr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS1RSAPublicKey(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoPKCS1RSAPublicKeyPtr_t* ppIChildInformation);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS1RSAPublicKey(/* in */ IEcoPKCS1Ptr_t pIEcoPKCS1);

#endif /* __C_ECOPKCS1RSAPUBLICKEY_H__ */
