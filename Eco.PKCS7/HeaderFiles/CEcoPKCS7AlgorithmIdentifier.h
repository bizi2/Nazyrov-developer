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

#ifndef __C_ECOPKCS7ALGORITHMIDENTIFIER_H__
#define __C_ECOPKCS7ALGORITHMIDENTIFIER_H__

#include "IEcoPKCS7.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS7AlgorithmIdentifier {

	/* Таблица функций интерфейса IEcoPKCS7 */
	IEcoPKCS7AlgorithmIdentifierVTbl* m_pVTblIEcoPKCS7AlgorithmIdentifier;
	/* Счетчик ссылок */
	uint32_t m_cRef;

	/* Интерфейс для работы с памятью */
	IEcoMemoryAllocator1* m_pIMem;

	/* Системный интерфейс */
	IEcoSystem1* m_pISys;

	/* Интерфейс для работы с нотацией ASN.1 */
	IEcoASNOne1* m_pIASNOne;

	/* Данные экземпляра */
	IEcoASNOne1Value* m_value;

} CEcoPKCS7AlgorithmIdentifier, * CEcoPKCS7AlgorithmIdentifierPtr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS7AlgorithmIdentifier(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoPKCS7AlgorithmIdentifierPtr_t* pAlgorithmIdentifier);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS7AlgorithmIdentifier(/* in */ IEcoPKCS7AlgorithmIdentifierPtr_t pIEcoPKCS7);

#endif /* __C_ECOPKCS7ALGORITHMIDENTIFIER_H__ */
