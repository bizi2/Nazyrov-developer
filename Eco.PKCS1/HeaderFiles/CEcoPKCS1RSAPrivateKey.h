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

#ifndef __C_ECOPKCS1RSAPRIVATEKEY_H__
#define __C_ECOPKCS1RSAPRIVATEKEY_H__

#include "IEcoPKCS1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS1RSAPrivateKey {

    /* Таблица функций интерфейса IEcoPKCS1 */
    IEcoPKCS1RSAPrivateKeyVTbl* m_pVTblIEcoPKCS1RSAPrivateKey;

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
	IEcoPKCS1Version* m_version;
	IEcoASNOne1Value* m_modulus;
	IEcoASNOne1Value* m_publicExponent;
	IEcoASNOne1Value* m_privateExponent;
	IEcoASNOne1Value* m_prime1;
	IEcoASNOne1Value* m_prime2;
	IEcoASNOne1Value* m_exponent1;
	IEcoASNOne1Value* m_exponent2;
	IEcoASNOne1Value* m_coefficient;
	IEcoPKCS1OtherPrimeInfos* m_otherPrimeInfos;

} CEcoPKCS1RSAPrivateKey, *CEcoPKCS1RSAPrivateKeyPtr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS1RSAPrivateKey(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoPKCS1RSAPrivateKeyPtr_t* ppIChildInformation);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS1RSAPrivateKey(/* in */ IEcoPKCS1RSAPrivateKeyPtr_t pIEcoPKCS1);

#endif /* __C_ECOPKCS1RSAPRIVATEKEY_H__ */
