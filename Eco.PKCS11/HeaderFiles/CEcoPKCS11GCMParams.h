/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoPKCS11
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoPKCS11
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOPKCS11_H__
#define __C_ECOPKCS11_H__

#include "IEcoPKCS11.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoPKCS11GCMParams {

    /* Таблица функций интерфейса IEcoPKCS11 */
    IEcoPKCS11VTbl* m_pVTblIEcoPKCS11;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
 	IEcoPKCS11BYTE_PTR* m_pIv;
	IEcoPKCS11ULONG* m_ulIvLen;
	IEcoPKCS11ULONG* m_ulIvBits;
	IEcoPKCS11BYTE_PTR* m_pAAD;
	IEcoPKCS11ULONG* m_ulAADLen;
	IEcoPKCS11ULONG* m_ulTagBits;

} CEcoPKCS11GCMParams, *CEcoPKCS11GCMParamsPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS11GCMParams(/*in*/ IEcoPKCS11Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS11GCMParams(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS11Ptr_t* ppIEcoPKCS11);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS11GCMParams(/* in */ IEcoPKCS11Ptr_t pIEcoPKCS11);

#endif /* __C_ECOPKCS11_H__ */
