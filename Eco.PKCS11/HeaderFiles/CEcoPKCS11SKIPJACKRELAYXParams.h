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

typedef struct CEcoPKCS11_3EB0FA6E {

    /* Таблица функций интерфейса IEcoPKCS11 */
    IEcoPKCS11VTbl* m_pVTblIEcoPKCS11;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
	IEcoPKCS11ULONG* m_ulOldWrappedXLen;
	IEcoPKCS11BYTE_PTR* m_pOldWrappedX;
	IEcoPKCS11ULONG* m_ulOldPasswordLen;
	IEcoPKCS11BYTE_PTR* m_pOldPassword;
	IEcoPKCS11ULONG* m_ulOldPublicDataLen;
	IEcoPKCS11BYTE_PTR* m_pOldPublicData;
	IEcoPKCS11ULONG* m_ulOldRandomLen;
	IEcoPKCS11BYTE_PTR* m_pOldRandomA;
	IEcoPKCS11ULONG* m_ulNewPasswordLen;
	IEcoPKCS11BYTE_PTR* m_pNewPassword;
	IEcoPKCS11ULONG* m_ulNewPublicDataLen;
	IEcoPKCS11BYTE_PTR* m_pNewPublicDataD;
	IEcoPKCS11ULONG* m_ulNewRandomLen;
	IEcoPKCS11BYTE_PTR* m_pNewRandomA;

} CEcoPKCS11_3EB0FA6E, *CEcoPKCS11_3EB0FA6EPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS11_3EB0FA6E(/*in*/ IEcoPKCS11Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS11_3EB0FA6E(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS11Ptr_t* ppIEcoPKCS11);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS11_3EB0FA6E(/* in */ IEcoPKCS11Ptr_t pIEcoPKCS11);

#endif /* __C_ECOPKCS11_H__ */
