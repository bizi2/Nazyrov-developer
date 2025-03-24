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

typedef struct CEcoPKCS11X3DHInitiateParams {

    /* Таблица функций интерфейса IEcoPKCS11 */
    IEcoPKCS11VTbl* m_pVTblIEcoPKCS11;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
	IEcoPKCS11X3DH_KDF_TYPE* m_kdf;
	IEcoPKCS11OBJECT_HANDLE* m_pPeer_identity;
	IEcoPKCS11OBJECT_HANDLE* m_pPeer_prekey;
	IEcoPKCS11BYTE_PTR* m_pPrekey_signature;
	IEcoPKCS11BYTE_PTR* m_pOnetime_key;
	IEcoPKCS11OBJECT_HANDLE* m_pOwn_identity;
	IEcoPKCS11OBJECT_HANDLE* m_pOwn_ephemeral;

} CEcoPKCS11X3DHInitiateParams, *CEcoPKCS11X3DHInitiateParamsPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoPKCS11X3DHInitiateParams(/*in*/ IEcoPKCS11Ptr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoPKCS11X3DHInitiateParams(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoPKCS11Ptr_t* ppIEcoPKCS11);
/* Удаление */
void ECOCALLMETHOD deleteCEcoPKCS11X3DHInitiateParams(/* in */ IEcoPKCS11Ptr_t pIEcoPKCS11);

#endif /* __C_ECOPKCS11_H__ */
