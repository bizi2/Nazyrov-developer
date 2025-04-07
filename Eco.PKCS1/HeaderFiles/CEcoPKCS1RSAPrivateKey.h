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

#ifndef __C_ECOPKCS1_H__
#define __C_ECOPKCS1_H__

#include "IEcoPKCS1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS1RSAPrivateKey {

    /* Таблица функций интерфейса IEcoPKCS1 */
    IEcoPKCS1VTbl* m_pVTblIEcoPKCS1;

    /* Таблица функций интерфейса IEcoPKCS1 */
    IEcoPKCS1EncoderVTbl* m_pVTblIEcoPKCS1Encoder;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
	IEcoPKCS1Version* m_version;
	IEcoASNOneINTEGER* m_modulus;
	IEcoASNOneINTEGER* m_publicExponent;
	IEcoASNOneINTEGER* m_privateExponent;
	IEcoASNOneINTEGER* m_prime1;
	IEcoASNOneINTEGER* m_prime2;
	IEcoASNOneINTEGER* m_exponent1;
	IEcoASNOneINTEGER* m_exponent2;
	IEcoASNOneINTEGER* m_coefficient;
	IEcoPKCS1OtherPrimeInfos* m_otherPrimeInfos;

} CEcoPKCS1RSAPrivateKey, *CEcoPKCS1RSAPrivateKeyPtr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS1RSAPrivateKey(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS1Ptr_t* ppIEcoPKCS1);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS1RSAPrivateKey(/* in */ IEcoPKCS1Ptr_t pIEcoPKCS1);

#endif /* __C_ECOPKCS1_H__ */
