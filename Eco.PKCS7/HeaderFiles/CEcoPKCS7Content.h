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
#include "IEcoASNOne1.h"
#include "CEcoPKCS7ContentType.h"
#include "CEcoPKCS7Content.h"

typedef struct CEcoPKCS7ContentInfo {

    /* Таблица функций интерфейса IEcoPKCS7 */
    IEcoPKCS7ContentInfoVTbl* m_pVTblIEcoPKCS7ContentInfo;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
	IEcoASNOne1ValueSet* m_SET;
    IEcoPKCS7ContentType* m_contentType;
	IEcoPKCS7Content* m_content;

} CEcoPKCS7ContentInfo, *CEcoPKCS7ContentInfoPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS7ContentInfo(/*in*/ IEcoPKCS7Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS7ContentInfo(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS7Ptr_t* ppIEcoPKCS7);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS7ContentInfo(/* in */ IEcoPKCS7Ptr_t pIEcoPKCS7);

#endif /* __C_ECOPKCS7_H__ */
