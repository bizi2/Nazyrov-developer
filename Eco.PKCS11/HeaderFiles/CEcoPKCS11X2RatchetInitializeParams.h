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

typedef struct CEcoPKCS11X2RatchetInitializeParams {

    /* Таблица функций интерфейса IEcoPKCS11 */
    IEcoPKCS11VTbl* m_pVTblIEcoPKCS11;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
	IEcoPKCS11BYTE_PTR* m_sk;
	IEcoPKCS11OBJECT_HANDLE* m_peer_public_prekey;
	IEcoPKCS11OBJECT_HANDLE* m_peer_public_identity;
	IEcoPKCS11OBJECT_HANDLE* m_own_public_identity;
	IEcoPKCS11BOOL* m_bEncryptedHeader;
	IEcoPKCS11ULONG* m_eCurve;
	IEcoPKCS11Mechanism_TYPE* m_aeadMechanism;
	IEcoPKCS11X2RATCHET_KDF_TYPE* m_kdfMechanism;

} CEcoPKCS11X2RatchetInitializeParams, *CEcoPKCS11X2RatchetInitializeParamsPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS11X2RatchetInitializeParams(/*in*/ IEcoPKCS11Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS11X2RatchetInitializeParams(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS11Ptr_t* ppIEcoPKCS11);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS11X2RatchetInitializeParams(/* in */ IEcoPKCS11Ptr_t pIEcoPKCS11);

#endif /* __C_ECOPKCS11_H__ */
