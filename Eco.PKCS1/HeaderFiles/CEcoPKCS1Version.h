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

#ifndef __C_ECOPKCS1VERSION_H__
#define __C_ECOPKCS1VERSION_H__

#include "IEcoPKCS1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS1Version {

	/* Таблица функций интерфейса IEcoPKCS1 */
	IEcoPKCS1VersionVTbl* m_pVTblIEcoPKCS1Version;
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

} CEcoPKCS1Version, * CEcoPKCS1VersionPtr;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS1Version(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* in */ IEcoASNOne1* pIASNOne, /* out */ IEcoPKCS1VersionPtr_t* pVersion);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS1Version(/* in */ IEcoPKCS1VersionPtr_t pIEcoPKCS1);

#endif /* __C_ECOPKCS1VERSION_H__ */
