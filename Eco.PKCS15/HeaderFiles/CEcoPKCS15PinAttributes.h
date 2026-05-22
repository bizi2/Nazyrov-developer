/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS15
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoPKCS15
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOPKCS15_H__
#define __C_ECOPKCS15_H__

#include "IEcoPKCS15.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS15PinAttributes {

    /* Таблица функций интерфейса IEcoPKCS15 */
    IEcoPKCS15VTbl* m_pVTblIEcoPKCS15;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    IEcoPKCS15PinFlags* m_pinFlags;
	IEcoPKCS15PinType* m_pinType;
	IEcoASNOne1Value* m_minLength;
	IEcoASNOne1Value* m_storedLength;
	IEcoASNOne1Value* m_maxLength;
	IEcoPKCS15Reference* m_pinReference;
	IEcoASNOne1Value* m_padChar;
	IEcoPKCS15GeneralizedTime* m_lastPinChange;
	IEcoPKCS15Path* m_path;

} CEcoPKCS15PinAttributes, *CEcoPKCS15PinAttributesPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS15PinAttributes(/*in*/ IEcoPKCS15Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS15PinAttributes(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS15Ptr_t* ppIEcoPKCS15);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS15PinAttributes(/* in */ IEcoPKCS15Ptr_t pIEcoPKCS15);

#endif /* __C_ECOPKCS15_H__ */
