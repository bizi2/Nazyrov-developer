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

typedef struct CEcoPKCS11TokenInfo {

    /* Таблица функций интерфейса IEcoPKCS11 */
    IEcoPKCS11VTbl* m_pVTblIEcoPKCS11;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
	IEcoPKCS11UTF8CHAR* m_label;
	IEcoPKCS11UTF8CHAR* m_manufacturerID;
	IEcoPKCS11UTF8CHAR* m_model;
	IEcoPKCS11CHAR* m_serialNumber;
	IEcoPKCS11FLAGS* m_flags;
	IEcoPKCS11ULONG* m_ulMaxSessionCount;
	IEcoPKCS11ULONG* m_ulSessionCount;
	IEcoPKCS11ULONG* m_ulMaxRwSessionCount;
	IEcoPKCS11ULONG* m_ulRwSessionCount;
	IEcoPKCS11ULONG* m_ulMaxPinLen;
	IEcoPKCS11ULONG* m_ulMinPinLen;
	IEcoPKCS11ULONG* m_ulTotalPublicMemory;
	IEcoPKCS11ULONG* m_ulFreePublicMemory;
	IEcoPKCS11ULONG* m_ulTotalPrivateMemory;
	IEcoPKCS11ULONG* m_ulFreePrivateMemory;
	IEcoPKCS11Version* m_hardwareVersion;
	IEcoPKCS11Version* m_firmwareVersion;
	IEcoPKCS11CHAR* m_utcTime;

} CEcoPKCS11TokenInfo, *CEcoPKCS11TokenInfoPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS11TokenInfo(/*in*/ IEcoPKCS11Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS11TokenInfo(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS11Ptr_t* ppIEcoPKCS11);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS11TokenInfo(/* in */ IEcoPKCS11Ptr_t pIEcoPKCS11);

#endif /* __C_ECOPKCS11_H__ */
